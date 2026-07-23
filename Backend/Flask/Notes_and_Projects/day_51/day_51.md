# Flask Introduction

## What are packages, modules, and how do you import flask correctly?

Disclaimer:
- Unlike my other notes, these are sort of fragmented notes on my own progress on the flask mega tutorial, so they are notably confusing if you don't know where I am. Sorry in advance!

This application (the microblog), will exist in a package (a folder with a __init__.py file). In Python, a subdirectory (a directory in a directory so a folder in a folder) that incluedes a __init__.py file is considered a package, and can be imported. Let me repeat that cuz its very important, YOU CAN IMPORT PACKAGES. When you import a package, the __init__.py executes and defines what symboles the package exposes to the outside world.

We are now going to create a package called app, that will host the application. (For my context, I am currently IN the microblog directory)
```bash
mkdir app
```
The __init__.py for app is going to contain the following code:
```python
from flask import Flask

app = Flask(__name__)

from app import routes
```
The script above creates the application object as an instance of class Flask imported from the flask package (recall a package is JUST a folder with a __init__.py script inside of it). So within this package we are calling the Flask class, and then using it to construct a Flask object and putting that inside of the variable, app. The __name__ variable passed to Flask is a Python predefined variable, which is set to the name of the module (which is just a python file) in which it is used.

For all practical purposes, passisng __name__ is almost always going to configure Flask in the correct way. The application then imports the routes module, which does NOT exist yet. It does this from the app package we JUST made, so now we are going to CREATE routes.

- Note that there are two entities named app, the Flask object and the package (the folder with the __init__.py in it.)

- Also the route module is imported at the bottom and not the top of the script. This is a workaround that avoids circular imports, a common problem with Flask applications. You are about to see that the routes module needs to import the app variable defined in this script, so putting the reciprocal imports at the bottom avoids the error that results from the mutal references between the two files.

## Routes module

So what goes in the routes module? Well, the routes module handles the different URLs that the application supports. In Flask, handlers for the application routes are written as Python functions, called view functions. View functions are mapped to one or more route URLs so that Flask knows what logic to execute when a client requests a given URL.

### Routes and Handlers
So...what does that mean? Well, Let's start with routes. A route is simply a URL route. This URL route is handled BY a handler.  And as I said before, handlers in Flask are written as Python functions, called view functions!

Now, with that out of the way we are going to create a Home Page route. This will be the first view function for this application, which will be written in a new module, apps/routes.py (in my case this is nested in more folders for reference.)

```python
from app import app

@app.route('/')
@app.route('/index')
def index():
    return "Hello, World!"
```

- In this example, whenever the web browser requests either of these two URLs, Flask is going to invoke this function and pass its return value back to thr browser as a response. 

## Complete Application
To compelte this application, you need to have a Python script at the top-level that defines the Flask application instance. Let's call this script microblog.py, and define it as a single line that imports the application instance:
```python
from app import app
```
This code belongs in tehe MAIN application module, meaning in this case its going in the directory that CONTAINS app not the directory app itself.

The first version of the application is now compelete! Before running it though, Flask needs to be told how to import it, by setting the FLASK_APP environment variable:
```bash
set FLASK_APP=microblog.py
```

### Flask run Debrief
```bash
 * Debug mode: off
WARNING: This is a development server. Do not use it in a production deployment. Use a production WSGI server instead.
 * Running on http://127.0.0.1:5000
```

So I bet you're wondering, what the fuck am I looking at? Well, the flask run command looked for a flask application instance in the moduel reference by the FLASK_APP command. We told it to go to the module microblog.py. The command then sets up a web server that is configured to foward requests to this to this application.

- In short, flask run sets up a web server, which is a seperate program that runs on your computer, and afterwards the terminal CONNECTS you to the web server.

After the server initializes it will wait for client connections. The ouput from flask run indicates that the server is running on the IP address 127.0.0.1, which is always the address of your own computer. This address is SO common that it also has a simpler name: localhost.

Network servers listen for connections on a specific port number. Applications deployed on production web servers typically listen on port 443, or sometimes 80 if they do not implement encryption, but access to these ports requires administration rights.

Since this application is running in a development environment, Flask uses port 5000. Now open up your web browser and enter the following URL in the address field:

- http://localhost:5000/

Or you can use this URL (since recall, we made both URL requests return the same thing)

- http://localhost:5000/index

The first URL maps to / while the second URL maps to /index. Both routes are associated the only view function in the application, so they produce the same output, which is the string that the function returns. If you enter any other URL, you will get an error, since only these two URLs are recognized by the application.

## Closer
Before I end this chapter, I wanna show one more thing. Since environment variables aren't remembered across terminal sessions, you may find it tedious to ALWAYS have to set the FLASK_APP environment variable when you open a new terminal window to work on your flask application. But luckily, Flask allows you to register environment variables that you want to be automatically used when you rin the flask command.

To use this option, you have to install the python-dotenv package:
```bash
pip install python-dotenv
```

Now you can just write the environment variable name and value ina  file named .flaskenv located in the top-level director of the project:

- .flaskenv: Environment variables for flask command
- - FLASK_APP=microblog.py

The flask command will look for the .flaskenv file and import all the variables defined in it exactly as if they were defined in the environment.