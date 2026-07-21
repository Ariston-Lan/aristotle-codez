# Installing Flask

## Python packages/Virtual Environments
Before stalling flask, we're going to talk about python packages.

In python, packages such as Flask are avaliable in a public repository known as PyPI. Installing a package from PyPI is very simple, because python comes with a tool called pip that does this work. 

```bash
pip install <package-name>
```

Interestingly though, this method of installing packages will not work in most cases of your computer, since the changes are your regular access account is not going to have permission to make modifications to it, so the only way to make the above command work is through running it from an administrator account.

However when you download a file this way, the pip tool is going to download the package from PyPI and then add it to your python installation. From that point on, EVERY pythons script that you have on your system will have access to this package. Which means that old scripts may stop working once your package gets updated.

A solution to this is virtual environments. A virtual environment is a complete copy of the Python interpreter. When you install packages in a virtual environment, the system0wide Python interpreter is not affected, only the copy is. 

The command for creating virtual environments is:
```bash
python3 -m venv venv
```

With this command, you're asking pyhton to run the venv package, which creates a virtual environment named venv. The first venv in the command is an argument to the -m option which is the name of the Python virtual environment package, and the second is the virtual environment name that I'm going to use for this particular enviroment. 
- If this is confusing, you can replace the second venv with a different name that you want to assign to your virtual environment. 
- - In some operating systems you may need to use python instead of python3.

After the command completes, you'll have a directory named venv where all the virtual environment files are stored. Now you have to tell the system that you want to use this virtual environment, and you do that by activating it.

To activate your brand new virtual environment, use the following command:

```bash
venv/bin/activate
(venv)
```
- Note that the command is slightly different based on the interface you're using (like powershell or microsoft windows command prompt)

When you activate a virtual environment, the configuration of your terminal session is modified so that the Python interpreter stored inside it is the one that is invoked when you type python. Also the terminal prompt is modified to include the name of the activated virtual envrionment. 

- The changes made to your terminal session are all temporary and private to that session, so theyw ill not persist when you close the terminal window. It is perfectly fine to have different virtual enviroments activated in multiple terminals at once

## Actually installing Flask
After you have the virtual environment created and activated you can FINALLY install flask in it

```bash
pip install flask
```

- If you want to confirm that your virtual environment now has Flask installed, you can use the start Python interpreter and import Flask into it. 
```python
import flask
```
- If this gives you no errors, congrats! Glask is installed and ready to be used!

- Note that when the specific version of Flask isnt specified, the latest version of Flask will be downloaded

# Flask Introduction
