from flask import render_template
from app import app
from app.forms import LoginForm

@app.route('/')
@app.route('/index')
def index():
    user = {'username': 'Maddi'}
    posts = [
        {
            'author': {'username':'Ariston'},
            'body': 'I love gay people'
        },
        {
            'author': {'username':'Hect0r'},
            'body': 'I love USCD'
        }
    ]

    return render_template('index.html', title='Home', user=user, posts=posts)

@app.route('/login')
def login():
    form = LoginForm()
    return render_template('login.html', title='Sign In', form=form)