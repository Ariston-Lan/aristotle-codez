# Receiving Form Data
If you try to press the submit button the browser is going to display a "Method Not Allowed" error. This is because the login view function from the previous section does one half of the jobs o far. It can display the form on a web page, but it has no logic to process the data submitted by the user...yet!

This is another area where Flask-WTF makes the job really easy. 

Here is an updated version of the view function that accepts and validates the data submitted by the user.

(in app/routes.py)
```python
from flask import render_template, flash, redirect

@app.route('/login', methods=['GET', 'POST'])
def login():
    form = LoginForm()
    if form.validate_on_submit():
        flash('Login requested for user {}, remember_me={}'.format(
            form.username.data, form.remember_me.data))
        return redirect('/index')
    return render_template('login.html', title='Sign In', form=form)
```
The first new thing in this version is the methods argument in the route decorator. This tells Flask that this view function accepts GET and POST requests, overriding the default, which is to accept only GET requests.

The HTTP protocol states GET requests are those that return information to the client (the web browser in this case). All the requests in the application so far are of this type. POST requests are typically used when the browser submits form data to the server (in reality GET requests can also be used for this purpose, but it is not a recommended practice). The "Method Not Allowed" error that the browser showed you before, appears because the browser tried to send a POST request and the application was not configured to accept it. By providing the methods argument, you are telling Flask which request methods should be accepted.

The form.validate_on_submit() methods does all the form processing work. When the browser sends the GET request to recieve the web page with the form, this method is going to return False, so in that case the function skips the if statement and goes directly to render the template in the last line of the function.

When the browser sends the POST request as a result of the user pressing the submit button, the form.validate_on_submit() is going to gather all thed ata, run all the validators attatched to fields, and if everything is all right it will return True, indicating that the data is valid and can be processed by the applicationn. But if at least one field fails validation, then the fucntion will return False, and that will cause the form to be rendered back to the user, like in the GET request case. 

When form.validate_on_submit() returns True, the login view function calls two new functions, imported from Flask. The flash() function is a useful way to show a message to the user. A lot of applications use this technique to let the user know if some action has been successful or not. In this case, It's being used as a temporary solution, because there is no real log for users yet. 

The second new function used in the login view function is redirect(). This function instructs the client web browser to automatically navigate to a different page, given as an argument. This view function uses it to redirect the user to the index page of the application.

When you call the flash() function, Flask stores the message, but flashed messages will not magically appear in web pages. The templates of the application need to render these flashed messages in a way that works for the site layout. I'm going to add these messages to the base template, so that all the templates inherit this functionality. 

This is the updated base template:
```html
<html>
    <head>
        {% if title %}
        <title>{{ title }} - microblog</title>
        {% else %}
        <title>microblog</title>
        {% endif %}
    </head>
    <body>
        <div>
            Microblog:
            <a href="/index">Home</a>
            <a href="/login">Login</a>
        </div>
        <hr>
        {% with messages = get_flashed_messages() %}
        {% if messages %}
        <ul>
            {% for message in messages %}
            <li>{{ message }}</li>
            {% endfor %}
        </ul>
        {% endif %}
        {% endwith %}
        {% block content %}{% endblock %}
    </body>
</html>
```
As you can see there is a with construct. This with construct is used to assign the result of calling get_flashed_messages() to a messages variable, all in the context of the template. The get_flashed_messages() function comes from Flask, and returns a list of all the messages that have been registered with flash() previously. The conditional that follows checks if messages has some content, if it odoes, a unordered list element is rendered and in each <li> there is the message content.

Once these flashed messages are requested through the get_flashed_messages function they are removed from the message list, so they appear only once after the flash() function is called.

# Improving Field Validation
The validators that are attatched to form fields prevent invalid data from being accepted into the application. The way the application deals with invalid form inputs is by re-displaying the form, to let the user make the necessary corrections.

If you tried to submit invalid data, I'm sure you noticed that while the validation mechanisms work well, there is no indication given to the user that there is something wrong with the form, the user simply gets the form back. The next task is to improve the user experience by adding a meaningful error message next to each field that failed validation

The form validators generate these descriptive error messages already, so all that is missing is adding some additional logic in the template to render them.

```html
{% extends "base.html" %}

{% block content %}
    <h1>Sign In</h1>
    <form action="" method="post" novalidate>
        {{ form.hidden_tag() }}
        <p>
            {{ form.username.label }}<br>
            {{ form.username(size=32) }}<br>
            {% for error in form.username.errors %}
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
        <p>{{ form.remember_me() }} {{ form.remember_me.label }}</p>
        <p>{{ form.submit() }}</p>
    </form>
{% endblock %}
```

The only change here is now there are loops for right after the username and password fields, so that the error messages have a place to go.

As a general rule, any fields that have validators attatched will have any error messages that result from validation added under form.<field_name>>.errors. This is going to be a list, because fields can have multiple validators attatched and more than one may be providing error messages to display to the user.

# Generating Links
The login form is fairly complete now, but we should discuss the proper way to include links in templates and redirects. So far you have seen a few instances in which links are defined. For instance:
```html
<nav>
    Microblog:
    <a href="/index">Home</a>
    <a href="/login">Login</a>
</nav>
```

The login view function also defines a link that is passed to the redirect function
```python
@app.route('/login', methods=['GET', 'POST'])
def login():
    form = LoginForm()
    if form.validate_on_submit():
        # ...
        return redirect('/index')
    # ...
```
One problem with writing links directly in tempaltes and source files is that if one day you decide to reorganize your links, then you rae going to have to search up and replace these links in your entire application

To have better control ove rthese links, Flask provides a function called url_for(), which gnerates URLs using its internal mapping of URLs to view functions. For example, the expression url_for('login') returns /login, and url_for('index') returns '/index. The argument to url_for() is the endpoint name, which is the name of the view function.

So from now on, we are going to use url_for( )every time we need to generate an application URL. The navigation abr in the base template now becomes app/templates/base.html