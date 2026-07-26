# Database

The topic of this chapter is extremely important. For most applications there is going to be a need to maintain persistent data that can be retrieved efficiently, and this is exactly what databases are made for.

## Databases in Flask
Flask does not support databases natively. This is one of the many areas in which Flask is intentionally not opinonated, which is great, because you have the freedom to choose the database that best fits your application instead of being forced to adopt one.

There are great choices for databases in Python, many of them with Flask extentions that make a better integration with the application. The databses can be separated into two big groups, those that follow the RELATIONAL model and those that do not.

The latter group is often called noSQL, indicating that they do not implement the popular relational query language SQL. 

While there are great database products in both groups, my opinion is that relational databases are a better for applications that have structured data such as lists of users, blog posts, etc., while NoSQL databses tend to be better for data that has less defined structure. 

This application, like most others, can be implemented using either type of database, but for the reasons stated above, we are going to use a relational database.

### Flask-SQLAlchemry
The first extention we are going to install is Flask-SQLAlchemy, an extension that provides a Flask-friendly wrapper to the popular SQLAlchemy package, which is an Object Relational Mapper or ORM.

- ORMs allow applications to manage a database using high-level entities such as classes, objects, and methods instead of tables and SQL. The job of the ORM is to translate the high-level operations into database commands.

The nice thing about SQLAlchemy is that it is an ORM not for one, but for many relational databases. SQLAlchemy supports a long list of database engines, inclduing the popular MySQL, PostgreSQL, and SQLite. This is extremely powerful, because you can do your development using a simple SQLite database that does not require a server, and then when the time comes to deploy the application on a production server you can choose a more robust MySQL or PostgreSQL server, without having to change your application.

To install Flask-SQLAlchemy in your virtual environment, run
```bash
pip install flask-sqlalchemy
```

## Database Migration
Most database tutorials I've seen cover creation and use of a database but do not adequately address the problem of making updates to an existing database as the application needs change or grow. This is hard because relational databases are centered around structured daa, so when the structure changes the data that is already in the database needs to be migrated to the modified structure.

The second extension I am going to present is Flask-Migrate. This extention is a Flask wrapper for Alembic, a database migration framework for SQLAlchemyWorking with database migrations adds a bit of work to get a database started, but this is a small price to pay for a robust way to make changes to your database in the future.

The installation process for Flask-Migrate is similar to other extentions you have seen:
```bash
pip install flask-migrate
```

## Flask-SQLAlchemy Configuration
During development, we are going to use a SQLite database. SQLite databases are the most ocnvient choice for developing small applications, sometimes even not so small onces, as each database is stored in a single file disk on there is no need to run a database server like MySQL and PostgreSQL.

Flask-SQLAlchemy needs a new configuration item added to the config file:
(in config.py)
```python
import os
basedir = os.path.abspath(os.path.dirname(__file__))

class Config:
    SQLALCHEMY_DATABASE_URI = os.environ.get('DATABASE_URL') or \
        'sqlite:///' + os.path.join(basedir, 'app.db')
```

The Flask-SQLAlchemy extension takes the location of the application's database from the SQLALCHEMY_DATABASE_URI configuration variable.

In genearl, it is a good practice to set configuration from environment variables, and provide a fallback value when the environment does not define the variable. In this case, I'm taking the database URL from the DATABASE_URL environment variable, and if that isn't defined, I'm configuring a database named app.db located in the main directory of the application, which is stored in the basedir variable.

The daabase is going to be represented in the application by the database instance. The database migration engine will also have an instance. These are objects that need to be created after the application, in the app/__init__.py file
(in app/__init__.py)
```python
from flask import Flask
from config import Config
from flask_sqlalchemy import SQLAlchemy
from flask_migrate import Migrate

app = Flask(__name__)
app.config.from_object(Config)
db = SQLAlchemy(app)
migrate = Migrate(app, db)

from app import routes, models
```

Three changes have been made to the file here.

The first is that there is now a db object, this represents the database. 

Then I added migrate, to represent the database migration engine.

Hopefully you see a pattern in how to work with Flask extentions. Most extensions are initialized as these two.

The last change is that I imported a new module called models atthe bottom. This module will define the structure of the database.

## Database Models
The data that will be stored in the database will be repsented by a collection of classes, usually called database models. The OR layer within SQLAlchemy will do the translations required to map objects created from these classes into rows in the proper database tables.

Let's start by creating a model that represents users.
(I can't show the image here but the database looks like this)

- id[integer]
- username [varchar]
- email [varchar]
- password_hash [varchar]

The id field is usually in all models, and is used as the primary key. Each user in the database will be assigned a unique id value stored in this field. Primary keys are, in most cases, automatically assigned by the database, so I just need to provide the id field makred as a primary key.

The username,email, and password_hash are defined as strings (or varchar in database jargon), and their maximum lengths are specified so that the database can optomize space usage. While the username and email fields are self-explanatory, the password_hash fields deserves some attention.

essentially, instead of just leaving the user passwords in pure string variations, which could be detrimental for users considering if there is any security breach, instead we are going to hash the password (turns them into numbers), which greatly improves security.

So now that I know what I want from my users table, I can translate that into code in the new app/models.py module.

(in app/models.py)
```python
from typing import Optional
import sqlalchemy as sa
import sqlalchemy.orm as so
from app import db

class User(db.Model):
    id: so.Mapped[int] = so.mapped_column(primary_key=True)
    username: so.Mapped[str] = so.mapped_column(sa.String(64), index=True,
                                                unique=True)
    email: so.Mapped[str] = so.mapped_column(sa.String(120), index=True,
                                             unique=True)
    password_hash: so.Mapped[Optional[str]] = so.mapped_column(sa.String(256))

    def __repr__(self):
        return '<User {}>'.format(self.username)
```
Okay there is quite a few things happening here. Let's go through each thing one by one.

First we start by improting sqlalchemy and sqlalchemy.orm modules from the SQLAlchemy package, which provides most of the elements that are needed to work with a database. 

The sqlalchemy module includes general purpose database functions and classes such as types and query building helpers, while sqlalchemy.orm provides the support for using models. 

Given that these two module names are long and will need to be references often, the sa and so aliases are defined directly in the import statements. 

The db instance from Flask-SQLAlchemy and the Optional typing hint from Python are imported as well.

The User class created above will represent users stored in the daabase. The class inherits from db.Model, a base class for all models from Flask-SQLAlchemy. The User model defines several fields as class variables. These are the columns that will be created in the corresponding database table.

Fields are assigned a type using Python type hints, wrapped with SQLAlchemy's so.Mapped generic type. A type declaration such as so.Mapped[int] or so.Mapped[str] define the type of collumn, and also make values required, or non-nullable in database terms. To define a column that is allowed to be empty or nullable, the Optional helper from Python is also added, as password_hash demonstrates.

In most cases defining a table column requires more than the column type. SQLAlchemy uses a so.mapped_column() function call assigned to each column to provide this additional configuration. In the case of id above, the column is configured as the primary key. For string columns many daabases require a length to be given, so this is also included. I have included other optional arguments that allow me to indicate which fields are unique and indexed, which is important so that database is consistent and searches are efficient.

The __repr__ method tells python how to print objects of this class, which is going to be useful for debugging.

## Creating The Migration Repository
The model class created in the previous section defines the initial database structure (or schema) for this application. But as the application continues to grow, it is likely that I will need to make changes to the structure sucha s adding new things, and sometimes to modify or remove items. Alembic (the migration framework used by Flask-Migrate) will make these schema changes in a way that does not require the database to be crecreated from scratch every time a change is made.

To accomplish this seemingly difficult task, Alembic maintains a amigration repository, which is a directory in which it stores its migration scripts. Each time a change is made to the database chema, a migration script is added to the repository with the details of the change.

To apply the migrations to a database, these migration scripts are executed in the sequence they were created.

Flask-Migrate exposes its commands through flask command. You have already seen flask run. The flask db sub-command is added by Flask-Migrate to manage everything related to database migrations.

So let's create the migaation repository for microblog by running flask db init:
```bash
flask db init
```

After you run flask db init command, you will find a new migrations directory, with a few files and a versions subdirectory inside. All these files should be treated as part of your project from now on, and in particular, should be addedf to source contorl along with your application code.

## The First Database Migration
With the migration repository in place, it is time to create the first database migration, which will include the users table that maps to the User database model. There are two ways to create a database migration: manually or automatically. 

To generate a migration automatically, the Alembic compares the database schema ass defined by the database models, against the actual database schema currently used in the database. It then populates the migration script with the changes necessary to make the database schema match the application models. 

In this case, since there is no previous database, the automatic migration will add the entire User model to the migration script. 

The flask db migrate sub-command generates these automatic migrations
```bash
flask db migrate -m "users table"
INFO  [alembic.runtime.migration] Context impl SQLiteImpl.
INFO  [alembic.runtime.migration] Will assume non-transactional DDL.
INFO  [alembic.autogenerate.compare] Detected added table 'user'
INFO  [alembic.autogenerate.compare] Detected added index 'ix_user_email' on '['email']'
INFO  [alembic.autogenerate.compare] Detected added index 'ix_user_username' on '['username']'
  Generating /home/miguel/microblog/migrations/versions/e517276bb1c2_users_table.py ... done
```

The first two lines are informational and can usually be ignored. It says that it found a user table and two indexes. Then it tells you where it wrote the migration script. The e517276bb1c2 value is an automatically generated and unique code for the migration (different for everyone). he comment given with the m option is optional, it just adds a short descriptive text to the migration.

The generated migration script is now part of your project, and if you are using git or other source control tools, it needs to be incorporated as an additional source file, along with all other files stored in mirgartions directory. 

You are welcome to inspect the script if you are curious to see how it looks. You will find that it has two functions called upgrade() and downgrade(). The upgrade() function applies the migration, and the downgrade() function removes it. This allows Alembic to migrate the database to any point in the history, even to older versions, by using the downgrade path

The flask db migrate command does not make any changes to the database, it just generates the migration script. To apply changes to the database, the flask db upgrade command must be used.

```bash
flask db upgrade
INFO  [alembic.runtime.migration] Context impl SQLiteImpl.
INFO  [alembic.runtime.migration] Will assume non-transactional DDL.
INFO  [alembic.runtime.migration] Running upgrade  -> e517276bb1c2, users table
```

Because this application uses SQLite, the upgrade command will detect that a database does not exist and will create it (you will notice a file named app.db is added after this command finishes, that is the SQLite database). When working with database servers such as MySQL and PostgreSQL, you have to create the database in a database server before running upgarde.

- Note that Flask-SQLAlchemy uses a "snake case" naming convention for database tables by default. For the User model above, the corresponding table in the database will be named user. For a AddressAndPhone model class, the table would be named address_and_phone. If you prefer to choose your own table names, you can add an attribute named __tablename__ to the model class, set to the desired name as a string.

## Database Upgrade and Downgrade Workflow
The application is in its infancy point, but this does not hurt to discuss what is going on to be the database migration strategy going foward. Imagine that you have your application on your development machine, and also have a copy deployed to a production server that is online and in use.

Let's say that for the next release of your application you have to introduce a change to your models, for example a new table needs to be added. Without migrations you would need to figure out how to change the schema of your database, both in your development machine and then again in your server, and this could be a lot of work.

But with database migration support, after you modify the models in your application you generate a new migration script (flask db migrate), you review it to make sure the automatic generation did the right thing, and then apply the changes to your development database (flask db upgrade). Youw ill add the migration script to source control and commit it.

When you are ready to release the new version of the application to your production server, all you need to do is grab the updated version of your application, which will include the new migration script, and run flask db upgrade. Alembic will detect that the productiond atabase is not updated to the latest version of the schema, and run all new migration scripts that were created after the previous release.

As I mentioned earlier, you have a flask db downgrade command, which undoes the last migration. While you will be unlikely to need this option on a production system, you may find it very useful during development. You may have generated a migration script and applied it, only to find that the changes you made are not exactly what you need. In this case, you can downgrade the database, delete your migration script, then generate a new one to replace it.

## Database Relationships
Relational databases are good at storing relations between data items.

Consider the case of a user writing a blog post. The user will have a record in the users table, and the post will have a record in the posts table., The most efficient way to record who wrote a given post is to link the two related records.

Once a link between a user and a post is established, the database can answer queries about this link. The most trivial one if when you have a blog post and need to know what user wrote it. A more complex query is the reverse of this one. If you have a user, you may want to know all the posts this user wrote. SQLAlchemy helps with both types of quieries.

Let's exapnd the database to store blog posts to see relationships in action. Here is the schema for a new posts table:
- id[int] 
- username [varchar]
- email [varchar]
- password_hash [varchar]

This is linked with these data table:

- id[int] 
- body [varchar]
- timestamp [datetime]
- user_id [int] (id from the previous table)

As you can see here, the second table uses the user_id from the first table when creating a new post. So now the database stores the user_id, the body of the post, the date it was posted, and a unique id for the post itself. 

The posts table will have the required id, the body of the post, and a timestamp. But in addition to these expected fields, there is a user_id field, which links the post to its author. You've seen that all users have an id primary key, which is unique. The way to link a blog post to the user that authored it is to add a reference to the user's id, and that is exactly what the user_id field is for. 

This user_id field is called a foreign key, because it references the primary key of another table. 

The database diagram above shows foreign keys as a link between the field and the field and the id field of the table it refers to. This kind of relationship is called a one-to-many, because "one" user writes "many" posts.

Rhw modified app/models.py is shown below:
(in app/models.py)
```python
from datetime import datetime, timezone
from typing import Optional
import sqlalchemy as sa
import sqlalchemy.orm as so
from app import db

class User(db.Model):
    id: so.Mapped[int] = so.mapped_column(primary_key=True)
    username: so.Mapped[str] = so.mapped_column(sa.String(64), index=True,
                                                unique=True)
    email: so.Mapped[str] = so.mapped_column(sa.String(120), index=True,
                                             unique=True)
    password_hash: so.Mapped[Optional[str]] = so.mapped_column(sa.String(256))

    posts: so.WriteOnlyMapped['Post'] = so.relationship(
        back_populates='author')

    def __repr__(self):
        return '<User {}>'.format(self.username)

class Post(db.Model):
    id: so.Mapped[int] = so.mapped_column(primary_key=True)
    body: so.Mapped[str] = so.mapped_column(sa.String(140))
    timestamp: so.Mapped[datetime] = so.mapped_column(
        index=True, default=lambda: datetime.now(timezone.utc))
    user_id: so.Mapped[int] = so.mapped_column(sa.ForeignKey(User.id),
                                               index=True)

    author: so.Mapped[User] = so.relationship(back_populates='posts')

    def __repr__(self):
        return '<Post {}>'.format(self.body)
```

Okay so a lot happened here so let's once again go one by one.

First, there is a new post class. This will represent blog posts written by users. The timestamp field is defined with a datetime type hint and is configured to be indexed, which is useful if you want to retreive posts in a chronological order. There is also a default argument with a lambda function passed into it that returns the current time in the UTC timezonel. When you pass a function as a default, SQLAlchemy will set the field to the value returned by the function. In general, you will want to work with UTC dates and times in a sever application instead of the local time where you are located. This ensures that you are using uniform timestamps regardless of where the users and sever are located. These timestamps will be converted to the user's local time when they are displayed

The user_id field was initialized as a forein key to User.id, which means that it references values from the id column in the users table. Since not all databases create an index for foreign keys, the index=True option is added explicitly, so that searches based on this column are optomized.

The User class has a new posts field, that is initialized with so.relationship(). This is not an actual database field, but a high-level view of the relationship between users and posts, and for that reason isn't in the database diagram. Likewise, the Post class has an author field that is also initialized as a relationship. These two attributes allow the application to access the connected user and post entities.

The first argument to so.relationship() is the model class that represents the other side of the relationship. this arugment can be provided as a string, which is necessary when the class is defined later in the module. The back_populates arguments reference the name of the relationship attribute on the other side, so that SQLAlchemy knows that these attributes refer to the two sides of the same relationship.

The post relationship attribute uses a different typing definition. Instead of so.Mapped, it uses so.WriteOnlyMapped, which defines posts as a collection type with Post objects inside.

Since I have updates to the application models, a new database migration needs to be generated
```bash
flask db migrate -m "posts table"
flask db upgrade
```

## Playing with the Database
Since the application does not have any database logic yet, let's paly with the database in the Python interpreter to familiarize with it.
```bash
python
from app import app, db
from app.models import User, Post
import sqlalchemy as sa
```

For flask and its extensions to have access to the Flask application without having to pass app as an argument into every function, an application context must be created and pushed. 

For now, you can do this through the following code
```bash
app.app_context().push()
```

Next, create a new user:
```python
u = User(username ='john' email='john@example.com')
db.session.add(u)
db.session.commit()
```

Changes to a database are done in the context of a database session, which can be accessed as a db.session. Multiple changes can be accumulated in a session and once all the changes have been registered, you can issue a single db.session.commit(), which writes all the changes atomically. If at any time while working on a session there is an error, a call to db.session.rollback() will abort the session and remove any changes stored in it. 
- The important thing to remember is that changes are ONLY written to a database when a commit is issued with db.session.commit(). Sessions guarantee that the database will never be left in an incosistent state.

Are you wondering how do all these database operations know what database to usE? The application contet that was pushed above allows Flask-SQLAlchemy to access the Flask application instance app without having to receive it as an argument. The extension looks in the app.config dictionary for SQLALCHEMY_DATABASE_URI entry which contains the database URL.

Let's add another user
```python
u = User(username='susan', email'susan@example.com')
db.session.add(u)
db.session.commit()
```

The database can answer a query that returns all the users:
```python
query = sa.select(User)
users = db.session.scalers(query).all()
users
[<User: john>, <User susan>] #Or however else you formatted it in __repr__
```

The query variable in this example is assigned to a basic query that selects all the users. This is achieved by passing the model class to the SQLAlchemy sa.select() query helper function. You will find that most database queries start from a sa.select() call.

The database session, which above was used to define and commit changes, is also used to execute queries. The db.session.scalars() method executes the database query and returns a results iterator. Calling the all() method of the results object converts the results to a plain list.

In many situations it is most efficient to use the results iterator in a for loop instead of converting it to a list:
```python
users = db.sessions.scalars(query)
for u in users:
    print(u.id, us.username)

1 john
2 susan
```

Note that the id fields were automatically set to 1 and 2 when those users were added. This happens because SQLAlchemy configures integer primary key columns to be auto-incrementing.

Here is another way to do queries. If you know the id of a user, you can retrive that user:
```python
u = db.sessions.get(User, 1)
u
<User john>
```

Now let's do a blog post
```python
u = db.session.get(User, 1)
p = Post(body='my first post!', author=u)
db.session.add(p)
db.session.commit()
```

I did not need to set a value for the timestamp field, because this field has a default, which you can see in the model definition. And what about the user_id field? Recall that the so.relationship that I created in the Post class adds an author attribute to posts. I assign an hour to the post using this author field instead of have to deal with user IDs. SQLAlchemy is great in that respect, as it provides a high-level abstraction over relationships and foreign keys.

There are a lot of things you can do but I want to specifically show you one of the ways to get all users with a specific characteristic. Let's look at getting all users starting with the letter "s".

```python
query = sa.select(User).where(User.username.like('s%'))
db.session.scalars(query).all()
[<User susan>]
```

Recall that the User model has a posts relationship attribute that was configured with the WriteOnlyMapped generic type. This is a special type of relationship that adds a select() method that returns a database query for all related items. The u.posts.sleect() expression takes care of generating the query that links the user to its blog posts.

The last query demonstrates how to filter the contents of a table using a condition. The where() clause is used to create filters that select only a subset of the rows from the entity selected. in this example, I'm using the like() operatore to select users based on a pattern.

The SQLAlchemy documentation is the best place to learn about the many options that are avaliable to query the database.

To end, exit the python shell and use the following commands to erase the test users and posts created above, so that the database is clean and ready for the next chapter:
```bash
flask db downgrade base
flask db upgrade
```

The first command tells Flask-Migrate to apply the database migrations in reverse order. When the downgrade command is not given a target, it downgrades one revision. The base target causes all migrations to be downgraded, until the database is left at its initial state, with no tables.

The upgrade command re-applies all the migration in foward order. The default target for upgrade is head, which is a shortcut for the most recent migration. This command effectively restores the tables that were downgraded above. Since database migrations do not preserve the data stored in the database, downgrading and then upgrading has the effect of quickly emptying all the tables.
## Shell Context
Remember what you did at the start of the previous section, right after starting a Python interpreter? At the startyou typed some imports then pushed an application context.
```python
from app import app, db
from app.models import User, Post
import sqlalchemy as sa
app.app_context().push()
```

While you work on your applicaiton, you will need to test things out in a Python shell very often, so having to repeat the above statements every time is annoying. This is a good time to address this problem.

The flask shell sub-command is another very useful tool in the flask umbrella of commands. The shell command is the second "core" command implemented by Flask, after run. The purpose of this command is to start a Pyton interpreter in the context of the application. For example:

```bash
flask shell
# (Now in a python context)
# >>> app
# <Flask 'app'>
```

The nice thing about flask shell is not only that it pre-imports app, but that you can also configure a "shell context", which is a list of other symbols to pre-import.

The following function in microblog.py creates a shell context that adds the database instance and models to the shell session.
(in microblog.py)
```python
import sqlalchemy as sa
import sqlalchemy.orm as so
from app import app, db
from app.models import User, Post

@app.shell_context_processor
def make_shell_context():
    return {'sa': sa, 'so':so, 'db':db, 'User':User, 'Post':Post}
```
The app.shell_context_processor decorator registers the function as a shell context funciton. When the flask shell command runs, it will invoke this function and register the itmes returned by it in the shell session. 

The reason the function returns a dictionary and not a list is that for each item you have to also provide a name under which it will be referenced in the shell, which is given by the dictionary keys.

After you add the shell context processor function you can work with database entities without having to import them.

