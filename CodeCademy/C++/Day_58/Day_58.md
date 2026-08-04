
# Basic C++ Structure
Every C++ program follows a similar structure.
```C++
int main()
{
    std:cout << "Hello\n";
}
```
Before I explain what's going on, let's go through the new code vocab we are using.

'int' is a data type representing an integer. In this case, int specifies the return value of the main() function.

main() is a function (we already know what that is from python), a function is a named block of code that performs a task. In this case, main() is the entry point of every C++ program.
- When the operating system starts the program, execution begins inside main()

The curly braces {} define a block of code. Everything between { and } belongs to the function.
```C++
int main()
{
    // Code inside the function
}
```

std::cout is used to display output to the console. It's pronounced "C out"

The << operator sends information to std::cout. Right now it's sending text to the console

Then /n is just a newline character

Lastly, a semicolon ; marks the end of a statement. It's sort of like the period at the end of an english sentence.

- Also, comments can be done in C++ via // followed by whatever you want to comment.

## Pre-Processor Directive
```C++
#include <iostream>
```
This is known as a pre-processor directive. Basically, it instructs the compiler to locate the file that contains code for a library known as iosstream. This library contains code that allows for input and output, such as displaying data in the terminal window or reading input from your keyboard.

## main()
EVERY C++ program must have a function called main. The main function houses all of our instructions for the program.

## Return values
As we already established, int main() is saying the return value of this function will be an integer. 
```C++
int main(){
    std::cout << "Hello World!\n";

    return 0;
}
```
Here, after dispalying "Hello World!" to the console, we return the integer 0. Returning 0 is an indication to the operating system that the code executed successfully (however, this line of code is optional).

### White space
C++ programs permit judicious use of white space to create code that is easier to read. The compiler completely ignores white space, with a small exception for conditionals (if statements). Basically just indent your code so its easier to read.

# Compile and Execute
Let's start with some definitions.

## Compile
Compile: A computer can only understand machine code (a low level programming language in the form of hexadecimal or binary). A compiler can translate C++ programs into that machine code.

You call on the compiler by using the terminal. To compile a file, you need to type g++ followed by the file name in the terminal and press enter.

For instance:
```bash
g++ hello.cpp
```
The compiler will then translate the C++ program hello.cpp and create a machine code file called a.out

## Execute
Execute: To execute the new machine code file, all you need to do is type ./ and the machine code file name in the terminal and press enter. In this case, our compiled name is "a.out" so to execute the file, we run "./a.out"

The executable file will then be loaded to computer memory and the computer's CPU executes the program one instruction at a time.

### Naming Executables

Sometimes when we compile, we want to give the output executable file a specific name. To do so, the compile command is slightly different.

```bash
g++ hello.cpp -o hello
```

In this example, the compiler will then translate the C++ program hello.cpp and create a machine code file named hello.

Execute: To execute the new machine code file, all you need to do is type ./ and the machine code file name in the terminal:

```bash
./hello
```

The executable file will then be loaded to computer memory and the co,puter's CPU will execute the program one instruction at a time.

## Comments
Comments in C++ are done with two slashes "//"

A multi-line comment is done with an slash and then a asterisk /*, and then to close it is an asterisk followed by a slash.
```C++
#include whatever

int main(){
    /* This is a multi
    line
    comment
    */
    std::cout <<"Yo what up";
}
```
## Overview

### The Process
C++ is a compiled language. That means to get a program to run, you must first translate it from human-readable form to something a machine can understand (machine code). That translation is done by a program called a compiler.

What you read and write is called source code, and then what the computer executes is called executable, object code, or machine code.

Typically C++ source code files are given the suffix:
- .cpp
- .h

#### Compile
A compiler translates the C++ program into machine langauge code which it stores on the disk as a file with the extention .o (e.g. hello.o). A linker then links the object code with standard library routines that the program may use and creates an executable image which is also saved on disk, usually a file with the file name without any extention (e.g. hello).

So the process goes like this:
- The source code is written by you (or whoever)
- It then goes to the preprocessor (It processes all lines beginning with #)
- Then it gets compiled into machine code via the compiler
- Then it goes to a linker (Links your code with all the code in the C++ Standard Library)
- And then comes out the executable

#### Execute
The executable is loaded from the disk to memory and the computer's CPU (Central Processing Unit) executes the program one instruction at a time.

# Variables
A variable is simply a name that represents a value.

Before we get into that too much, lets look at some of the basic data types:
- int: integer  numbers
- double: floating-point numbers
- char: individual characters
- string: a sequence of characters
- bool: true/false values

## Declare a Variable

To declare a variable in C++, you must provide the type for the variable and the name of it.

```C++
int score;
```
In this example, int is the type of the variable, score is the name of the variable, and ; is how we end a statement.

## Initialize a Variable

After you declare a variable you can give it a value.

```C++
int score;
score = 0;
```

### Combining Both Steps
You can do both of these at the same time as well

```C++
int score = 0;
```
This defines the variable type as int, and sets the variable name as score with the value of 0

# Arithmetic Operators

Here are some arithmetic operators:
- + addition
- - subtraction
- * multiplication
- / divison
- % module (divides and gives the remainder)

# Chaining

You can use multiple << operators to chain the things you want to output. 

For instance:
```C++
int age = 28;

std::cout << "Hello I am" << age << " years old\n";
```
In this example, we chain the string to the variable another string in the C out object.

# User Input

For input, there is something called cin (C - in).

Here's how its used:
```C++
std::cin >> password;
```
As you can see, it has a similar syntax as cout. Instead though, the arrows point towards where the input goes

# Basic Data Types

As already mentioned, C++ has  data types that are assigned to whatever value you give your variables.

Here are some of them in action:
```C++
int age = 28;

double price = 8.99;

char grade = 'A';

std::string message = "Game Over";

bool late_to_work = true;
```

## Datatype Modifiers:
Datatype modifers are used with built in data types to modify the length of data that a particular data type can hold.

Data type modifers are:
- signed
- unsigned
- short
- long

### Const
const (constant) variables cannot be cahnged by your program during execution
```C++
const double quarter = 0.25;
```
Now in this program once it runs, the variable quarter's value cannot be changed from 0.25

## Type conversion

A type cast is basically a conversion from one type to another.

Here's what it looks like in action
```C++
double weight1;
int weight2;

weight1 = 154.49;
weight2 = (int) weight1;

// weight2 is now 154
```

Going from a double to an int simply removes the decial, there's no rounding involved.

# Conditionals

Logical operators are used to combine two or more conditionals. They allow programs to make more flexible decisions. The result of the operation of a logical operator is a bool value of either true or false.

There are three logical operators that we're gonna cover:
- &&: the and logical operator
- ||: the or logical operator
- !: the not logical operator

The and operator returns true if both conditionals are true.
The or operator returns true of either conditional is ture
and the not operator returns true if the conditional is false

Here are some relational operators as well

- == equal to
- != not equal to
- '>' greater than
- < less than
- '>=' geater than or equal to
- '<=' less than or equal to


You can also add an else to conditionals too, the else runs if the conditional is false.

```C++
if (coin == 1) {
    std::cout << "Heads\n"

}
else {
    std::count << "Tails\n"
}
```
Lastly, you can use else if statements if you want to test for multiple conditionals, given that one is not true. 
- Technically you can do this just by using a lot of if statements, but usually in most situations B can only happen if A is not true, and C can only happen if B is not true, so you wouldn't need to check for B or C if A is already true