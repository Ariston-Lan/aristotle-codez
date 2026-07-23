# What Are Templates?

First, let's start with a want. I want to design the microblog website to have a heading that welcomes the user. Since there are no real users yet, we are going to test it out with a mock user, which will be implemented as a python dictionary.

```python
user = {'username':'Miguel'}
```

Before, the view function we used last time returned the string "Hello, World!". Now we are going to return the string to a complete HTML page.

(currently in app/routes.py)
```python
from app import app

@app.route('/')
@app.route('/index')
def index():
    user = {'username': 'Miguel'}
    return '''
<!DOCTYPE hthml>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>Home Page - Microblog</title>
    </head>
    <body>
        <h1>Hello, ''' + user['username'] + '''!</h1>
    </body>
</html>
```

Returning an entire string of an html document is...not a good idea. It just isnt efficient, especially considering some doucments link to different html pages. use certain files, the list goes on. Also code constantly changes, HTML, CSS, so what's the solution?

Well, this is where templates come in. In Flask, templates are written as separate files, stored in a templates folder that is inside the application package. 

# Implementing Templates

Now we are going to make a templates folder inside of the app package.
```bash
mkdir app/templates
```

Now we are going to put the html file INSIDE of templates instead.
```bash
echo > app/templates/index.html
```
(You don't need to do this part, you can just create the file manually but I perfer this)

Okay now we have made the index.html file, and we are going to put some html into it.
```html
<!DOCTYPE html>
<html lang ="en">
    <head>
        <link rel="stylesheet" href="stylesheet.css">

        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">

        <title>{{ title }} - Microblog</title>
    </head>
    <body>
        <h1>Hey {{ user.username }}!</h1>
    </body>
</html>
```

Unlike a typical HTML page, there are some place holders here enclosed in the {{ ... }} sections. These placeholders represent the parts of the page that are variable and will only be known at runtime. 

Now that the presentation of the page was offloaded to the HTML template, the view function can be simplified.
(inside app/routes.py)
```python
from flask import render_template
from app import app

@app.route('/')
@app.route('/index')
def index():
    user = {'username': 'Miguel'}
    return render_template('index.html', title='Home', user=user)
```

As you can see, to render the template I had to import a function taht comes with Flask called render_template(). This function takes a template filename and a variable list of template arguments, but all with placeholders in it replaced with actual values.

- The render template() function invokes the Jinja template engine that comes bundled with the Flask framework. Jinja substitutes {{ ... }} blocks with the corresponding values, given by arguments provided in the render_template() call.  So basically, whatever variables you NEED in your HTML, will be arguments in your render_template function.

- Templates also support control statements, given inside {% ... %} blocks.

## Conditional Statements
The next version of the index.html template adds a conditional statement. (if x then y)

```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <link rel="stylesheet" href="stylesheet.css">

        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        {% if title %}
        <title>{{ title }} - Microblog</title>
        {% else %}
        <title>Welcome to Microblog!</title>
        {% endif %}
    </head>
    <body>
        <h1>Hello, {{ user.username }}</h1>
    </body>
</html>
```

Now the template will provide a default value if the title placeholder variable is missing. 

## Loops
The logged in user will probably want tos ee recent posts from connected users in the home page, so we're going to extend the application to support that. (relying on mock objects).

(in app/routes.py)
```python
from flask import render_template
from app import app

@app.route('/')
@app.route('/index')
def index():
    user = {'username': 'Miguel'}
    posts = [
        {
            'author': {'username': 'John'},
            'body': 'Beautiful day in Portland!'
        },
        {
            'author': {'username': 'Susan'},
            'body': 'The Avengers movie was so cool!'
        }
    ]
    return render_template('index.html', title='Home', user=user, posts=posts)
```

Here we have both the dictionary of one user and some posts from other users.

So now we are going to implement these variables into our HTML
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        {% if title %}
        <title>{{ title }} - Microblog</title>
        {% else %}
        <title>Welcome to Microblog</title>
        {% endif %}
    </head>
    <body>
        <h1>Hi, {{ user.username }}!</h1>
        {% for post in posts %}
        <div><p>{{ post.author.username }} says: <b>{{ post.body }}</b></p></div>
        {% endfor %}
    </body>
</html>
```
This is formatted JUST like a python. Itll loop through the list, and for each object (which is a dictionary), itll add their username value (which is a string, specifically their username) and then it will add their post.body in bold (which is another string, their post.) 

## Template Inheritance
Most web applications these days have a navigation bar at the top of the page with a few frequently used links, such as a link to edit your profile, to login, logout, etc. I can easily add a navigation bar to the index.html, but would you REALLY wanna add a navigation bar to EVERY single page manually? Nope. Insead...why not just MAKE a navigation_bar.html file and add it to each one of your pages? Even better, why not make a base.html that each of your pages use?

Here is an example of what I mean:
(in app/templates/base.html)
```html
<!doctype html>
<html>
    <head>
      {% if title %}
      <title>{{ title }} - Microblog</title>
      {% else %}
      <title>Welcome to Microblog</title>
      {% endif %}
    </head>
    <body>
        <div>Microblog: <a href="/index">Home</a></div>
        <hr>
        {% block content %}{% endblock %}
    </body>
</html>
```
- The {% block content %}{% end block %} Says where the code should go.

After doing that, you can make the index.html inherit from the base.html like so:
(in app/templates/index.html)
```html
{% extends "base.html" %}

{% block content %}
    <h1>Hi, {{ user.username }}!</h1>
    {% for post in posts %}
    <div><p>{{ post.author.username }} says: <b>{{ post.body }}</b></p></div>
    {% endfor %}
{% endblock %}
```
- The extends statement establishes the inheritance link between the two templates, so that Jinja knows when its asked to render index.html it needs to embed it inside base.html. The two templates have matching block statements with the name content, and this is how Jinja knows how to combine the two templates into one.