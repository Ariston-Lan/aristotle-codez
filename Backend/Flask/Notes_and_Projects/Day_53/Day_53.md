# Introduction to Flask-WTF
To handle web forms in this application I'm going to use Flask-WTF extention, which is a thin wrapper around the WTForms package that nicely integrates it with Flask. 

Extentions are a very important part of the flask ecosystem, as they provide solutions to problems that Flask is intentionally not opinonated about.

Flask extentions are regular Python packages that are instaleld with pip. You can go ahdea and install Flask-WTF in your virtual environment
```bash
pip install flask-wtf
```

## Configuration
So far the application is very simple, and for that reason I did not need to worry about its configuration. But for any applications except the simplest ones, you are going to find that Flask (and possibly also the Flask extentions that you use) offer some amount of freedom in how to do things, and you need to make some decisions, which you pass to the framework as a list of configuration variables.

There are several formats for the application to specify configuration options. The most basic solution is to define your variables as keys in app.config, which uses a dictionary style to work with variables.

For example, you could do something like this
```python
app = Flask(__name__)
app.config['SECRET_KEY'] = 'you-will-never-guess'
#... add more variables here as needed
```

While the above code is sufficient to create configuration options for Flask, its good to enforce the principle of separation of concerns.

So instead of putting my configuration in the same placed where I crate my application, it'd be better to keep the configuration in a separate file.

A good oslution is to use a Python class to store configuration variables. To keep things organized, I'm going to create the configuration class in a separate Python module. Below you can see the new configuration class for this application, stored in a config.py module in the top-level directory.

The configuration settings are defined as class varibales inside the Config class. As the application needs more configuration items, they can be added to this class, and later if I find I need to have more than one configuration set, I can create subclasses of it.

The SECRET_KEY configuration variable that I added as the only configuration item is an important part in most Flask applications. Flask and some of its extentions use the value of the secret key as a cryptographic key, useful to generate signatures or tokens. The Flask-WTF extention uses it to protect web forms against a nasty attack called Cross-Site Request Forgery or CSRF.

As its name implies, the secret key is supposed to be secret, as the strength of the tokens and signatures generated with it depends on no person outside the trusted maintainers of the application knowing it.

The value of the secret key is set as an expression with two terms, joined by the or operator. The first term looks for the value of an envrionment variable, also called SECRET_KEY. The second term, is just a hardcoded string. 

The idea is that a value sourced from an environment varibale is preferred, but if the environment does not define the variable, the hardcoded string is used instead as a default. When you are developing this application, the security requirements are low, so you can just ignore this setting and let the hardcoded string be used. But when this application is deployed on a production server, a unique and difficult to guess value in the environment will be set, so the server has a secure key that nobody else knows.

Now that I have a config file, I need to tell Flask to read it and apply it. That can be done right after the Flask application instance is created using the app.config.from_object() method:
(in app/__init__.py)
```python
from flask import Flask
from config import Config

app = Flask(__name__)
app.config.from_object(Config)

from app import routes
```

## User Login Form
The Flask-WTF extention uses Python classes to represent web forms. A form class simply defines the fields of the form as class variables.

I'm going to use a new app/forms.py module to store my web form classes.

To beign let's define a user login form, which asks the user to enter a username and a password. The form will also include a "remember me" check box and a submit button.

(in app/forms.py)
```python
from flask_wtf import FlaskForm
from wtforms import StringField, PasswordField, BooleanField, SubmitField
from wtforms.validators import DataRequired

class LoginForm(FlaskForm):
    username = StringField('Username', validators=[DataRequired()])
    password = PasswordField('Password', validators=[DataRequired()])
    remember_me = BooleanField('Remember Me')
    submit = SubmitField('Sign In')
```

Most Flask extentions use a flask_<name> naming convention for their top-level import symbol. In this case, Flask-WTF has all its symbols under flask_wtf. this is where the FlaskForm base class is imported from at the top of app/forms.py

The four classes that represent the field types that I'm using for this form are imported directly from WTForms package, since the Flask WTF extention does not provide customized versions. For each field, an object is created as a class variable in the LoginForm class. Each field is given a description or label as a first argument.

Next, the optional validators argument that you see is in some of the fields. This is used to attach validation behaviors to fields. The DataRequired validator simply checks that the field is not submitted empty. There are many types of validators available.

## Form Templates
The next step is to add the form to an HTML template so that it can be rendered ona  web page. The good news is that the fields that are defined in the LoginForm class know how to render themselves as HTML.

I'm going to store the login template in app/templates/login.html
(in app/templates/login.html)
```python
{% extends "base.html" %}

{% block content %}
    <h1>Sign In</h1>
    <form action="" method="post" novalidate>
        {{ form.hidden_tag() }}
        <p>
            {{ form.username.label }}<br>
            {{ form.username(size=32) }}
        </p>
        <p>
            {{ form.password.label }}<br>
            {{ form.password(size=32) }}
        </p>
        <p>{{ form.remember_me() }} {{ form.remember_me.label }}</p>
        <p>{{ form.submit() }}</p>
    </form>
{% endblock %}
```

This template expects a form object instantiated from the LoginForm class to be given as an argument, which you can see referenced as form. This argument will be sent by the login view function, which we are about to write.

The method attribute specifies the HTTP request method that should be used when submitting the form to the server. The default is to send it with a GET requrest, but in almost all cases, using a POST request makes for a better user experience because requests of this type can submit the form data in the body of the request, while GET requests add the form fields to the URL, cluttering the browser address bar.

The novalidate attribute is used to tell the web browser not to apply validation to the fields in this form, which effectively leaves this task to the Flask application running the server. Using novalidate is optional.

The form.hidden_tag() template argument generates a hidden field that includes a token that is used to protect the form against CSRF attacks. All you need to do to have the form protected is include this hidden field and have the SECRET_KEY variable defined in the Flask configuration.

There are no HTML fields in this template since all the fields from the form object know how to render themsleves as HTML. Simply include {{ form.<field_name>() }} where you want the field. For fields that require additional HTML attributes, those can be passed as arguments. The username and password fiels in this template take the size as an argument that will be added to the input HTML element as an attribute. This is how you can attatch CSS classes or IDs to form fields.

## Form Views
The final step before you can see this form in the browser is to code a new view function.

So let's do that.

(in app/routes.py)
```python
from flask import render_template
from app import app
from app.forms import LoginForm

# ...

@app.route('/login')
def login():
    form = LoginForm()
    return render_template('login.html', title='Sign In', form=form)
```

Don't forget to extend the nav in the base.html
```html
<nav>
    Microblog:
    <a href='/index'>Home</a>
    <a href='/login'>Login</a>
</nav>
```
