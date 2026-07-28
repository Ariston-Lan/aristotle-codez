# Profile page and Avatars
This chapter is going to be about adding user profile pages to the application.

That means a page where the user information is presented, often information entered by the user themselves. We will add the profile pages dynamically and then we will add a small profile editors users can use to enter their information.

## User Profile page

First we will need to add a new route. Think about it, when you click on someone's profile, the page loads up a new page with all that info. So before we do anything, we will add that route into our routes module
(in app/routes.py)
```python
@app.route('/user/<username>')
@login_required
def user(username):
    user = db.first_or_404(sa.select(User).where(User.username == username))
    posts = [
        {'author':user, 'body': 'Test post #1'}
        {'author':user, 'body': 'Test post #2'}
    ]
    return render_template('user.html', user=user, posts=posts)
```

Let's go through this line by line. First we have @app.route, which declares this view function as a view function, and inside of it we have the argument ('/user/<username>'). This is a dynamic componenet, which is indicated as the <username> URL component. Flask will accept any text in that portion of hte URL, and will invoke the view function with the actual text as an argument. 

For instance, if the client browser requests URL /user/susan, the view function is going to be called with the argument username set to 'susan'. 

This view function is only going to be accessible to logged-in users, hence the @login_requierd decorator.

The implentation of this view function is fairly simple. The first thing I do is try to load the user from the database using a query by the username. 
- A database query can be executed with db.session.scalars or db.session scalar for reference (not limited to those two but most commonly used)

In this view function, we are using a variant of scalar, one that is provided by Flask-SQLAlchemy called db.first_or_404(), which works like scalar() when there are results, but when there are NO results it sends a 404 error back to the client. BY executing the query in this way, I save myself from having to check if the query returned a user manually, since when username does not exist itll just raise a 404 exception instead.

If the database query does NOT trigger a 404 error, then that means that a user with the given username is found! So after that, we have intialized some fake posts for the user (test post #1 and 2), and then after that we render a new template, the user.html template (which we have not made yet so do not worry!).

The user.html template is going to show all the user info. So it should include things like the user username and the user's posts. Later it'll include things like a bio but...let's not get ahead of ourselves just yet.

(in app/templates/user.html)
```html
{% extends "base.html" %}

{% block content %}
    <h1>User: {{ user.username }}</h1>
    <hr>
    {% for post in posts %}
    <p>
    {{ post.author.username }} says: <b>{{ post.body }}</b>
    </p>
    {% endfor %}
{% endblock %}
```

The profile page is now complete, but a link to it...dosen't exist anywhere in the website. So we should make a way for users to check their own profile. Let's add it onto our nav bar in base.html
(in app/templates/base.html)
```html
        <div>
            Microblog:
            <a href="{{ url_for('index') }}">Home</a>
            {% if current_user.is_anonymous %}
            <a href="{{ url_for('login') }}">Login</a>
            {% else %}
            <a href="{{ url_for('user', username=current_user.username) }}">Profile</a>
            <a href="{{ url_for('logout') }}">Logout</a>
            {% endif %}
        </div>
```

Here the only thing we changed is we added a new link to our conditional, that checks whether the user is logged in. If the user is logged in, (meaning the conditional returns True), there is now a link for a url to the user's page. The profile page url is 'user', in conjuction with username=current_user.username, since if you recall our route uses the user's username as apart of the route link.

## Avatars
Okay so Profile pages are pretty boring without SOME form of expression. So let's add some user avatars. Instead of having to deal with a possibly large collection of uploaded images in the server, we are going to use the Gravatar service to provide images for all users.

The Gravatar service is very cimple to use. To request an image for a given user, a URL with the format
https://www.gravatar.com/avatar/<hash> must be used, where <hash> is the MD5 hash (which is just the output of a hash function) of the user's email address.

Here is an example where I obtain the Gravatar URL for a user with email john@example.com
```bash
from haslib import md5
'https://www.gravatar.com/avatar/' + md5(b'john@example.com').hexdigest()
'https://www.gravatar.com/avatar/d4c74594d841139328695756648b6bd6'
```

Essentially, this URL now contains an image using the hash of this user's email. By default the image size is returned at 80x80 pixels, but a different size can be requested using a s arguemnt to the URL's query string.

Example:
https://www.gravatar.com/avatar/729e26a2a2c7ff24a71958d4aa4e5f35?s=128.

Another argument is the d, which determines what the image Gravatar provides for users that do not have an avatar registered with the service. 
- A nice attribute value for this is identicon, which returns a nice geometric design that is different for every email.

Some privacy web browsers extentions such as Ghostery block Gravatar images, as they consider that Automatic (the owners of the Gravatar service) can determine what sites you visit based on the requests they get for your avatar. If you don't see avatars in your browser, consider that the problem may be due to an extention that you have installed in your browser.

Since avatars are associated with users, it makes sense to add the logic that geenrates the avatar URLs to the user model.
(in app/models.py)
```python
from hashlib import md5

class User(UserMixin, db.Model):
    def avatar(self, size):
        digest = md5(self.email.lower().encode('utf-8')).hexidigest()
        return f'https://www.gravatar.com/avatar/{digest}?d=identicon&s={size}'
```

Okay so here, the new avatar() method of the User class returns the URL of the user's avatar image, scaled to the requested size in pixels. For users that don't have an avatar registered, an identicon image will be generated. 

In order to generate the MD5 hash, we first convert the email to lowercase (as required by the Gravatar service). Then, since the MD5 support in Python works on bytes and not on strings, we encode the strings as bytes before passing it onto the has function (using .encode() ). The argument in encode is just the most commonly used charset for encoding. Then md5 takes all of that and returns a byte object. After that hexidigest takes that and returns a readable MD5 hash.

The next step is to insert the avatar images in the user profile template.
(in app/templates/user.html)
```html
{% extends "base.html" %}

{% block content %}
    <table>
        <tr valign="top">
            <td><img src="{{ user.avatar(128) }}"></td>
            <td><h1>User: {{ user.username }}</h1></td>
        </tr>
    </table>
    <hr>
    {% for post in posts %}
    <p>
    {{ post.author.username }} says: <b>{{ post.body }}</b>
    </p>
    {% endfor %}
```

The nice thing about making the User class responsible for returning avatar URLs is that if some day I decide Gravatar avatars are not what I want, I can just rewrite the avatar() method to return different URLs, and all the templates will start showing the new avatars automatically.

Okay so we have the big avatar at the top of the page, nice, but we don't just have to stop there. How about whenever there are some posts from users, they show their profile picture as well?

For the user profile page of course all posts will have the same avatar, but then I can implement the same functionality on the main page as well, and then each post will be decorated with the author's avatar, and that will look pretty cool!

Luckily, we stored the author as a user object for each post, so all we need to do is edit the jinja inside of our template to also include the user's avatar (since we ALSO included avatar as a function in the user class, this is rather simple!)

(in app/templates/user.html)
```html
{% extends "base.html" %}

{% block content %}
    <table>
        <tr valign="top">
            <td><img src="{{ user.avatar(128) }}"></td>
            <td><h1>User: {{ user.username }}</h1></td>
        </tr>
    </table>
    <hr>
    {% for post in posts %}
        {% include '_post.html' %}
    {% endfor %}
{% endblock %}
```

## Using Jinja-Sub Templates
I designed the user profile page so that it displays the posts written by the user, along with their avatars. Now I want the index page to also display posts with a similar layout.

To do this, we are going to make a sub-template that just renders one post, and then we are going to reference it from both the user.html and index.html templates. Like template-ception (or just inheritance.)

So we're going to name this template with the _ prefix. This is just a naming convention to help me recognize what template files are sub-templates.

(in app/templates/_post.html)
```html
    <table>
        <tr valign="top">
            <td><img src="{{ post.author.avatar(36) }}"></td>
            <td>{{ post.author.username }} says:<br>{{ post.body }}</td>
        </tr>
    </table>
```

Now we are going to include this sub template inside of user.html using the include statement.

## More Interesting Profiles
One problem the new user profile pages have is that they don't really...show much on them. We need to add a bio of course! We're also going to keep track of what was the last time each user accessed the site and also display it on their page.

The first thing I need to do to support all this extra information is to extend the users table in the database with two new fields, their about me and the time they were last online.

(in app/moodels.py)
```python
class User(UserMixin, db.Model):
    # ...
    about_me: so.Mapped[Optional[str]] = so.mapped_column(sa.String(140))
    last_seen: so.Mapped[Optional[datetime]] = so.mapped_column(
        default=lambda: datetime.now(timezone.utc))
```

Remember that every time the database is modified it is necessary to generate a database migration. Since we already set up the application to track database changes through migration scripts, we now have two new fields we need to add to the database. 

So now let's generate the migration script:
```bash
flask db migrate -m "New fields in user model"
```

And if your output command looks good, we can apply this change to the database
```bash
flask db upgrade
```

Now we are going to add these two new fields to the user profile template:
(in app/templates/user.html)
```html
{% extends "base.html" %}

{% block content %}
    <table>
        <tr valign="top">
            <td><img src="{{ user.avatar(128) }}"></td>
            <td>
                <h1>User: {{ user.username }}</h1>
                {% if user.about_me %}<p>{{ user.about_me }}</p>{% endif %}
                {% if user.last_seen %}<p>Last seen on: {{ user.last_seen }}</p>{% endif %}
            </td>
        </tr>
    </table>
    ...
{% endblock %}
```

## Recroding The Last Visit Time For a User
Now we need to record these new data fields somehow. First let's start with the last_seen field.

What I want to do is write the current timeon this field for a given user whenever that user sends a request to the server.

Adding the login to set this field on every possible view function that can be requested from the browser is impractical, but executing a bit of generic logic ahead of a request being dispatched to a view function is a common task in web applications, so much so that Flask offers it as a native feature.

Let's look at the solution.
(in app/routes.py)
```python
from datetime import datetime, timezone

@app.before_request
def before_request():
    if current_user.is_authenticated:
        current_user.last_seen = datetime.now(timezone.utc)
        db.session.commit()
```

Here, the @app.before_request decorator registers the decorated function to be executed right before the view function. Now this is super useful because I can insert the code I want to execut before ANY view function in the application. The implementation does two things.

First it checks it the user is authenticated (logged in), and then if they are, sets the current_user's last_seen field to the current time.

After that we use db.session.commit() to push the database changes to the database.