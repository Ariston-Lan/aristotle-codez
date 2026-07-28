# User Logins

## Password Hashing

In the previous chatper the user model was given a password_hash field, that so far is unused. The purpose of this field is to hold a hash of the user password, which will be used to verify the password entered by the user during the log in process. Password hashing is a complicated topic that should be left to security experts, but there are several easy to use libraries that implement all that logic in a way that is simple to be invoked from an application.

### Werkzeug
One of the packages that implement password hashing is Werkzeug, which you may have seen referenced in the output of pip when you install Flask, since it is one of its core dependencies. Since it is a dependency, Werkzeug is already installed in your virtual environment.

The following Python shell session demonstrates how to hash a password with this package:

```python
from werkzeug.security import generate_password_hash
hash = generate_password_hash('foobar')
hash
'scrypt:32768:8:1$DdbIPADqKg2nniws$4ab051ebb6767a...'
```

In this example, the password foobar is transformed into a long encoded string through a series of cryptographic operations that have no known reverse operation, which means that a person that obtains the hashed password will be unable to use it to recover the original password. As an additional measure, if you hash the same password multiple times, you will get different results, since all hashed passwords get a different cryptographic salt, so this makes it impossible to identify if two users have the same password by looking at their hashes.

The verification process is done with a second function from Werkzeug, as follows:
```python
from werkzeug.security import check_password_hash
check_password_hash(hash, 'foobar')
True
checj_password_hash(hash, 'barfoo')
False
```

Ther verification function takes a password hash that was previously generated, and a password entered by the user at the time of log in. The function returns True if the password provided by the user matches the has, or False otherwise.

The whole password hashing logic can be implemeneted as two new methods in the user model:
(in app/models.py)
```python
from werkzeug.security import generate_password_hash, check_password_hash

class User(db.model):
    # ...

    def set_password(self, password):
        self.password_hash = generate_password_hash(password)
    
    def check_password(self, password):
        return check_password_hash(self.password_hash, password)
```

With these two methods in place, a user object is now able to do secure password verification, without the need to ever store original passwords.

Here is an example usage of these new methods
```python
>>> u = User(username='susan', email='susan@example.com')
>>> u.set_password('mypassword')
>>> u.check_password('anotherpassword')
False
>>> u.check_password('mypassword')
True
```

## Introduction to Flask-Login
Flask-Login is another flask extention. This extention manages the user logged-in state, so that for exmaple users can log in to the application and then navifate to different pages while the applciation "remembers" that the user is logged in. It also provides the "remember me" functionality that allows users to remain logged in even after closing the browser window.

First, let's install Flask-Login inside the virtual environment
```bash
pip install flask-login
```

Now Flask-Login needs to be created and initialized right after the application instance in app/__init__.py

This is how this extention is initailized:
(in app/__init__.py)
```python
#...
from flask_login import LoginManager

app = Flask(__name__)
#...
login = LoginManager(app)
```

## Preparing The User Model for Flask-Login
The Flask-Login extention works with the application's user model, and expects certain properties and methods to be implented in it. This approach is nice, because as long as these required items are added to the model, Flask-Login does not have any other requirements, so for example, it can work with user models that are based on any database system.

The four required items are listed below:
- is_authenticated: a property that is True if the user has valid credentials or False otherwise
- is_active: a property that is True if the user's account is active or False otherwise
- is_anonymous: a property that is False for regular users, and True only for a special, anonymous user.
- get_id(): a method that returns a unique identifier for the user as a string

I can implement these four easily, but since the implementations are fairly generic, Flask-login provides a mixin class called UserMixin that includes safe implementations that are appropriate for most user model classes. Here is how the mixin class is added to the model:
(in app/models.py)
```python
#...
from flask_login import UserMixin

class User(UserMixin, db.Model):
    #...
    
```

## User Loader Function
Flask-Login keeps track of the logged in user by storing its unique identifier in Flask's user session, a storage space assigned to each user who connects to the application. Each time the logged-in user navigates to a new page, Flask-Login retrives the ID of the user from the session, and then loads that user into memory.

Because Flask-Login knows nothing about databases, it needs the application's help in laoding a user. For that reason, the extention expects that the application will configure a user loader function, that can be called to load a user given the ID. This function can be added in the app/models.py module
(in app/models.py)
```python
from app import login
#..

@login.user_loader
def load_user(id):
    return db.session.get(User, int(id))
```
The user loader is registered with Flask-Login with the @login.user_loader decorataor. The id that Flask-login passes to the function as an argument is going to be a string, so that databases that use the numeric IDs need to conver thte string to integer as you see above.

## Logging Users In
Let's revisit the login view function, which as you recall, implemented a fake login that just issued a flash() message. Now that the application has access to a user database and knows how to generate and verify password hashes, this view function can be completed.
(in app/routes.py)
```python
# ...
from flask_login import current_user, login_user
import sqlalchemy as sa
from app import db
from app.models import User

# ...

@app.route('/login', methods=['GET', 'POST'])
def login():
    if current_user.is_authenticated:
        return redirect(url_for('index'))
    form = LoginForm()
    if form.validate_on_submit():
        user = db.session.scalar(
            sa.select(User).where(User.username == form.username.data))
        if user is None or not user.check_password(form.password.data):
            flash('Invalid username or password')
            return redirect(url_for('login'))
        login_user(user, remember=form.remember_me.data)
        return redirect(url_for('index'))
    return render_template('login.html', title='Sign In', form=form)
```

Okay so let's go over everything happening here line by line.

The top two lines in the login() function deal with a weird situation. Imagine you have a user that is logged in, and the user navigates to the /login URL of your application. Clearly that is a mistake, so i want to not allow that. The current_User variable comes from Flask-Login and can be used at any time during the handling of a request to obtain the user object that represents the client of that request. The value of this variable can be a user object from the database (which Flask-Login reads through the user loader callback I provided above), or a special anonymous user object if the user did not log in yet.

Remember those properties that Flask-Login required in the user object? One of those was is_authenticated, which omes in handy to check if the user is logged in or not. When the user is already logged in, I just redirect to the index page.

In place of the flash() call that was used earlier, now I can log the user in for real. The first step is to load the user from the database. The username came with the form submission, so I can query the database with that to find the user. For this purpose I'm using the where() clause, to find users with the with the given username. 

Since I know there is only going to be one or zero results, I execute thee query by calling db.session.scalar(), which will return the user object if it exists, or None if it does not. In the last chapter you have seen that when you call the all() method the query executes and you get a list of all the results that match that query. The first() method is another commonly used way to execute a query, when you only need to have one result.

If I got a match for the username that was provided I can next check if the password that also came with the form is valid. This is done by invoking the check_password() method I defined above. This will take the password hash stored with the user and determine if the password entered in the form mathces that has or not. So now I have two possible error conditions: if the username can be invalid, or the password can be incorrect for the user. In either of those cases, I flash a message and redirect back to the login prompt so that the user can try again.

If the username and password are both correct, then I call the login_user() function, which comes from Flask-Logim. This function registers the user as logged in, so that means that any future pages the user navigates to will have the current user variable set to that user.

To complete the login process, I just redirect the newly logged-in user to the index page.

## Logging Users Out
I know I will also need to offer users the option to log out if the application. This can be done with Flask-Login's logout_user() function. here is the function:
(in app/routes.py)
```python
@app.route('/logout')
def logout():
    logout_user()
    return redirect(url_for('index'))
```

To expose this link to users, I can make the Login link in the navigation bar automatically switch to a Logout link after the user logs in. this can be done with a conditional in the base.html template
(in app/templates/base.html)
```html
        <div>
            Microblog:
            <a href="{{ url_for('index') }}">Home</a>
            {% if current_user.is_anonymous %}
            <a href="{{ url_for('login') }}">Login</a>
            {% else %}
            <a href="{{ url_for('logout') }}">Logout</a>
            {% endif %}
        </div>
```

The is_anonymous property is one of the attributes that Flask-Login adds to user objects through the UserMixin class. The current_user.is_anonymous expression is going to be True only when the user is not logged in.

## Requiring Users To Login
Flask-Login provides a very useful feature that forces users to log in before they can view ceratin pages of the application. If a user who is not logged in tries to view a protected page, Flask-Login will automatically redirect the user to the login form, and only redirect back to the page the user wanted to view after the login process is complete.

For this feature to be implemeneted, Flask-Login needs to know what is the view function that handles logins. This can be added in app/__init__.py
(in app/__init__.py)
```python
login.login_view = 'login'
```

The 'login' value above is the function (or endpoint) name for the login view. In other words, the name you would use in a url_for() call to get the URL.

The way Flask-Login protects a view functiona gainst anonymous users is witha  decorator called @login_required. When you add this decorator to a view function below the @app.route decorator from Flask, the function becomes protected and will not allow access to users that are not authenticated. Here is how the decorator can be applied to the index view function of this application:
(in app/routes.py)
```python
from flask_login import login_required

@app.route('/')
@app.route('/index')
@login_required
def index():
    #...
```

What reamins is to implement the redirect back from the successful login to the page the user wanted access. When a user that is not logged in accesses a view function protected with the @login_required decorator, the decorator is going ot redirect to the login page, but it is going to include some extra information in this redirect so that the application ccan hen return to the original page. 

If the user navigates to /index, for example, the @login_required decorator will intercept the request and respond with a redirect /login, but it will add a query string argument to this URL, making the complete redirect URL /login?next=/index. 

The next query string argument is set to the original URL, so the application can use that to redirect back after login.

Here is a snippet of code that shows how to read and process the next query string argument. The changes are in the four lines below the login_user() call.

(in app/routes.py)
```python
from flask import request
from urllib.parse import urlsplit

@app.route('login', methods=['GET', 'POST'])
def login():
    #...
    if form.validate_on_submit():
            user = db.session.scalar(sa.select(User).where(User.username == form.username.data))
        if user is None or not user.check_password(form.password.data):
            flash('Incorrest username or password')
            return redirect(url_for('login'))
        login_user(user, remember=form.remember_me.data)
        next_page = request.args.get('next')
        if not next_page or urlsplit(next_page).netloc != '':
            next_page = url_for('index')
        return redirect(next_page)
    #...
```

Right after the user is logged in by calling Flask-Login's login_user() function, the value of the next query string argument is obtained. Flask provides a request variable that contains all the information that the client sent with the request. In particular, the request.args attribute exposes the contents of the query string in a friendly dictionary format. 

There are actually three posisble cases that need to be considered to determine where to redirect after a successful login:
- If the login URl does not have a next argument, then the user is redirected to the index page.
- If the login URl includes a next argument that is set to a relative path (or in other words, a URL without the domain portion), then the user is redirected to that URl.
- If the login URl includes a next argument that is set to a full URL that includes a domain name, then this URL is ignored, and the user is redirected to the index page.

The first and second cases are self-explanatory. The third case is in place to make the application more secure. An attacker could insert a URL to a malicious site in the enxt argument, so the application only redirects when the URl is relative, which ensures the redirect stays within the same site as the application. To determine if the URL is absolute or relative, I parse it with Python's urlsplit() function and then check if the netloc component is set or not.

## Showing The Logged-In User in Templates
The application has real users now, so we can remove the fake user and start working with real users. Instead of the gake user, I can use Flask-Login's current_user in the template index.html/template
(in app/templates/index.html)
```html
{% extends "base.html" %}

{% block content %}
    <h1>Hi, {{ current_user.username }}!</h1>
    {% for post in posts %}
    <div><p>{{ post.author.username }} says: <b>{{ post.body }}</b></p></div>
    {% endfor %}
{% endblock %}
```

And I can remove the user template argument in the view function
(in app/routes.py)
```python
@app.route('/')
@app.route('/index')
@login_required
def index():
    # ...
    return render_template("index.html", title='Home Page', posts=posts)
```

Okay so now we should text how the login and logout works functionally. Since there is still no user registration, the only way to add a user into the database is via the Python shell, so we are going to use that.

```bash
>>> u = User(username='susan', email='susan@example.com')
>>> u.set_password('cat')
>>> db.session.add(u)
>>> db.session.commit()
```

Now if you start the application and go to the application's index or / URLs, you will be immediately redirected to the login page. And after you log in using the credentials of the user you just added into the database, you will be returned to the original page.

If you then click the logout link in the top navigation bar, you will be sent back to the index as an anonymous user, and redirected to hte login page again by Flask-Login.

## User Registration
The LAST piece of functionality that is going to be covered is a registration form, so that users can register themselves through a web form.

First lets make the form in app/forms.py:
```python
from flask_wtf import FlaskForm
from wtforms import StringField, PasswordField, BooleanField, SubmitField
from wtforms.validators import ValidationError, DataRequired, Email, EqualTo
import sqlalchemy as sa
from app import db
from app.models import User

#...

class RegistrationForm(FlaskForm):
    username = StringField('Username', validators=[DataRequired()])
    email = StringField('Email', validators=[DataRequired(), Email()])
    password = PasswordField('Password', validators = [DataRequired()])
    password2 = PasswordField(
        'Repeat Password', validators=[DataRequired(), EqualTo('password')]
    )
    submit = SubmitField('Register')

    def validate_username(self, username):
        user = db.session.scalar(sa.select(User).where(
            User.username == username.data
        ))
        if user is not None:
            raise ValidationError(f'{username.data} is already taken')
        

    def validate_email(self, email):
        user = db.session.scalar(sa.User.where(
            User.email == email.data
        ))
        if user is not None:
            raise ValidationError(f'{email.data} is already taken')
```

There are a couple of interesting things in this new form related to validation. First, from wtform.validators, we import new validaiton techniques that these forms can use, such as Email, and EqualTo. These are necessary for when the user might input invalid information.

The Email() validator from WTForms requires an external dependency to eb installed:
```bash
pip install email-validator
```

Since this is a registration form, we should probably ask the user to type the password two times to reduce the risk of a type. This is why there is a password1 and password2 field. The EqualTo validator will make sure the value is identical for both password fields.

When you add any methods that match the pattern validate_<field_name>, WTForms takes those as custom validators and invokes them in addition to the stock validators (Stock validators are the pre-installed ones like DataRequierd and Email).

I have added two of those methods to this class for the username and email fields. In this case I want to make sure that the username and email address entered by the user are not already in the database, so there are two methods issue database queries expecting there will be no results.

```python
user = db.session.get(sa.select(User).where(
    User.username == username.data
))
if user is not None:
    #...
```
- These are the methods that I am referring to. This makes sure that the username is not currently in the database. Similarly email also has a custom validator that does the same thing.

In the event a result exists, a validation error is triggered by raising an exception of type ValidationError. The message included as the argument in the exception will be the message that will be displayed next to the field for the user to see.

Note how the two validation quereies are issued. These quries will never find more than one result, so instead of running them with db.session.scalars() I am using db.session.scalar() in singular, which returns None if there are no results, or else the first result.

- I assume using the plural would return an empty list which is still "something" even if falsy, idk

To display this form on a web page, I need to have a NEW html template, so we are going to make a new one called register.html, and put it in our app/templates.
(in app/templates/register.html)
```html
{% extends "base.html" %}

{% block content %}
    <h1>Register</h1>
    <form action="" method="post">
        {{ form.hidden_tag() }}
        <p>
            {{ form.username.label }}<br>
            {{ form.username(size=32) }}<br>
            {% for error in form.username.errors %}
            <span style="color: red;">[{{ error }}]</span>
            {% endfor %}
        </p>
        <p>
            {{ form.email.label }}<br>
            {{ form.email(size=64) }}<br>
            {% for error in form.email.errors %}
            <span style="color: red;">[{{ error }}]</span>
            {% endfor %}
        </p>
        <p>
            {{ form.password.label }}<br>
            {{ form.password(size=32) }}<br>
            {% for error in form.password.errors %}
            <span style="color: red;">[{{ error }}]</span>
            {% endfor %}
        </p>
        <p>
            {{ form.password2.label }}<br>
            {{ form.password2(size=32) }}<br>
            {% for error in form.password2.errors %}
            <span style="color: red;">[{{ error }}]</span>
            {% endfor %}
        </p>
        <p>{{ form.submit() }}</p>
    </form>
{% endblock %}
```

After doing that we need to add a link to the register form in the login form

```html
  <p>New User? <a href="{{ url_for('register') }}">Click to Register!</a></p>
```

And finally after all of that, we need to write the view function that is going to handle the user registrations. Recall the view function is what handles the URL routes.

```py
@app.route('/register', methods=['GET', 'POST'])
def register():
    if current_user.is_authenticated:
        return redirect(url_for('index'))
    form = RegistrationForm()
    if form.validate_on_submit():
        user = User(username=form.username.data, email=form.email.data)
        user.set_password(form.password.data)
        db.session.add(user)
        db.session.commit()
        flash('Congratulations, you are now a registered user!')
        return redirect(url_for('login'))
    return render_template('register.html', title='Register',)
    form=form
```
And this view function should also be mostly self-explanatory.

Here you can see we are checking if the user is authenticated (so if the user is logged in), and if they are then we just redirect them to home. If they arent however, then we check if the HTTP request is GET or POST. If its get, we just render the template. If its post then we submit the data (given that its validated) and create a user with the given username, email, and we set a password with the user. Then after that we add the user to the database and commit it.

With these changes we can FINALLY have users in the database, and users can now create accounts on this application and log in and out.