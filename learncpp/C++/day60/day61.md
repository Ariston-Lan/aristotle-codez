# Statements and structure of a program

## Statements

A computer program is a sequence of instructions that tell a computer what to do. A statement is a type of instruction that causes the program to perform some action.

Most(but not all) statements in C++ end in a semicolon (;).

## Functions and the main() function
Statements are typically grouped into units called functions. A function is a collection of statements that get executed sequentially (in order, from top to bottom). 

When the program is run, the statements inside of main are executed in sequential order. 
- Every C++ program must have a special function named main()

## Characters and text
The earliest computers were designed primarily for mathematical calculations and data processing. As hardware improved, computers also became valuable tools for written communication.

In written language, the most basic unit of communiciation is the character. A character is a written symbol or mark, such as a letter, digit, punctuation mark, or mathematical symbol. When we tap an alphabetic or numeric key on our keyboard, a character is produced as a result, which can then be displayed on the screen.

A sequence of characters is called text (or string in programming contexts)

Let's look at an example of a simple program, "Hello world"
```C++
#include <iostream>

int main()
{
    std::cout << "Hello world!";
    return 0;
}
```

Here we are declaring the type of our function, main(), and we are saying that main should return the value of an integer (which it does at the end). Before that occurs however, we want the function to print the statement "Hello world!", which is done by using std::cout, pronounced as C-out, which prints a value to the terminal.

The #include preprocessor directive (which is a special type of line), indicates that we would like to use the contents of iostream library, which is part of the C++ standard library that allows us to read and write text from/to the console. This is necessary to use std::cout.

# Comments

## Single-line comments

The // symbol begins a C++ single-line comment, which tells the compiler to ignore everything from the // symbol to the end of the line. For example:
```C++
std::cout <<"Hello world!"; //Everything from here to the end of the line is ignored, since it is a comment.
```

Having comments to the right of a line can make botht he code and the comment hard to read. 

However if the lines are long, placing comments to the right can make your lines really llong. In that-case, single line comments are often placed right above your code or the line it is commenting.


## Multi-line comments
/* and */ are a pair of symbols used to make multi line comments. Everything between the two symbols are ignored. For example:
```C++
/* 
This is a multi-line comment
This line will be ignored
And so will this one.
*/
```

Muilti line comments cannot be nested. So do not use multi-line comments inside other multi-line comments, wrapping single-line comments inside a multi-line comment is okay however.

## Proper use of comments
Typically comments should be used for three things

- First, for a given library, program, or function, commenst are best used to describe what the library, program, or function, does. These are typically placed at the top of the file or library, immediately preceding the function.

- Second, within a library, program, or function, comments can be used to describ ehow the code is used to accomplish its goal.

- Third, at the statement level, comments should be used to describe why the code is doing something. A bad statement code explains what the code is doing. If you ever write code that is so complex that needs a comment to exaplain what a staement is doing, you probably need to rewrite your statement, not comment it.

# Introduction to objects and variables

## Data and values

### Data

In computing, data is any information that can be moved, processed, or stored by a computer.

A program can acquire data to work with in many ways: from a file or database, over a network, from the user providing input on a keyboard, or from the programmer putting data directly into the source code of the program itself.

In the "Hello world" program from the aforementioned lesson, the text "Hello world!" was insterted directly into the source code of the program, providing data for the program to use. The program then manipulates this data by sending it to the monitor to be displayed.

### values
In programming, a single piece of data is called a value (sometimes called a data value).

Some common examples of values are:
- numbers
- characters
- text

## Random Access Memory

The main memory in a computer is called Random Access Memory (RAM). When we run a program, the operating system loads the program into RAM. Any data that is hardcoded into the program itself (such as text) is loaded at this point.

The operating system also reserves some additional RAM for the program to use while it is running. Commun uses for memory are to store values entered by the user, to store data read in from a file or network, or to store values calculated while the program is running so they can be used again later.

Ram is sort of like a series of numbered boxes that can be used to store data while the program is running.

In some older programming languages, you could directly access these boxes.

## Objects and variables
In C++ direct memory access is discouraged. Instead we access memory indirectly through an object. An object represents a region of storage (typically a RAM or CU regist) that can hold a value. objects have associated properties as well.

How the compiler and operating system work to assign memory to objects is beyond the scope of this lesson and a little too advanced. But essentially, instead of saying "go get the value stored in mailbox number 7532" it says "go get the value stored by this object" and let the compiler figure out where and how to retrive the value.

This means we can focus on using objects to store and retrive values, and not have to worry about where in memory those objects are actually being placed.

## Variable Definition

In order to use  variable, we need to tell the compiler that we want one. The most common way to do this is by use of a special kind of declaration statement called a definition.

An example is defining a variable named x:
```C++
int x; //define a variabled named x (of type int)
```

At commpile-time (when the program is being compiled), when encountering this statement, the compiler makes a note to itself that we want a variable with the name x, and that variable has the data type of int.

The compiler hanles all the other details aboutthis variablle for us, including determining how much memory the object will need, in what kind of storage the object will be placed (e.g. RAM or CPU register), where it will be placed relative to other objects, when it will be created and destroyed, etc.

A variable created via a definition statement is said to be defined at the point where the definition statement is placed. Usually, that's inside of main, but it can be in other functions and files as well.

## Variable creation

At runtime (when the program is loaded into memory and ran), each object is given an actual storage location (such as RAM or a CPU register) that it can use to store values. 

The process of reserving storage for an object's use is called allocation. 

Once allocation has occurred, the object has been created and can be sued.

Let's say that variable x is instantiated (created) at memory locaiton 140. Whenever the program uses variable x, it will access the value in the memory location 140. 

Then when the program is ran, execution starts at the top of main(), and memory for x is allocated. Then the program ends.

## Data types
A data type (more commonly just called a type) determines what kind of value the object will store.

There are plenty of data types in C++, the most common ones being:

- int (integers)
- double (decimals(often referred to as floaters))
- char (singular characters(i.e. "a" or "1"))
- std::string (groups of characters (i.e. "Hello))
- bool (True or False conditions)

## Defining multiple variables

It is possible to define multiple variables of the same type in a single statement by separating the names with a comma:

```C++
int a, b;
```

# Variable assignemnt and initialization

## Variable assignment
After a variable has been defined you can assign a value to it using the = operator.

This process is called assignment.
```C++
int width;
width = 5; //Now the variable width has the value of type integer, 5
```

## Variable initialization

You can combine the two steps of defining and assigning a variable. The process of specifying an initial value for an object is called initialization, and the syntax used to initialize an object is called an initializer. 

For instance:
```C++
#include <iostream>

int main()
{
    int width {5};
    std::count << width //prints 5
    return 0;
}
```

## Different forms of initialization

There are 5 common forms of initialization in C++:

```C++
int a; //default (no initializer)

//Traditional initialization forms:
int b = 5; //copy initialization 
int c (6); // direct-initialization

//Modern initialization forms (preferred):
int d { 7 }; //direct-list-initialization
int e {}; // value-initialization (empty braces)
```

### Default-initialization

When no initializer is provided, this is called default initialization. In many cases default-initialization performs no initialization, and leaves the variable with an inderterminate value (a value that is not predictable, sometimes called a "garbage value")

### Copy-initialization
When an initial value is provided after an equals sign, this is called copy-initialization.

This method copies the value on the right hand sign of the equals into the variable being created on the left hand side. 

Copy initilization had fallen out of favor in modern C++ due to being less efficient than other forms of initilization for some complex types. But some people still use it as C++17 remedied the bulk of these issues.

### Direct-initialization
Direct-initialization was initally introduced to allow for more efficient initialization of complex objects (those with class types). It also sort of fell out with modern C++ but its coming back allegedly

### List-initialization
The modern way to initialize objects in C++ is to use a form of initializtion that makes use of curly braces. This is called list-initialization (or uniform initilaization or brace initialization).

List-initialization comes in two forms:
```C++
int width { 5 }; // direct-list-initialization of initial 5 into variable width (preferred)

int height = { 6 }; //copy-list-initialization of initial value 6 into variable height (rarely used)
```

#### List-initialization disallows narrowing conversions

One of the primary benefits of list-initializations for new C++ progarmmers is that "narrowing conversions" ar disallowed.

This means if you try to list-initialize a variable usign a value that the variable can not safely hold, the compiler is required to produce a diagnostic (compilation error or warning) to notify you.

### Value-initialization and zero-initialization

When a variable is initialized using an empty set of braces, a special form of list-initializationc alled value-initialization takes place. In most cases, value-initialization will implicitly initialize the variable to zero (or whatever value is closest to zero for a given type). 

In cases where zeroing occurs, this is called zero-initialization.

## Overview

### List-initialization is the preferred form of initialization in modern C++

List-initialization (including value initialization) is generally preferred over the other initialization forms because it works in most cases.

### Initialize your variables

Initialize your variables upon creation. You may eventually find cases where youw ant to ignore this advice for a specific reason, and thats okay, as long as the choice is made deliberately.

### Instanation
The term instanation is a fancy word that means a variable has been created (allocated). An instantiated object is sometimes called an instance.

### Initializing multiple variables

You can initialize multiple variables like so:

```C++
int a=5, =6;
int c( 7 ), d ( 8 );
int e { 9 }, f{ 10 }l
int i {}, j{};
```

### Unused initialized variables warnings

Compilers will raise an error if you initialize a variable but never use it (since this is rarely desireable)

There are a few easy ways to fix this

- Remove the definition or comment it out

- Use the variable somehwere

#### The [[maybe_unused]] attribute

In some cases, neither of the above options are desirebale.

To address such cases, C++17 introduced the [[maybe-unused]] attribute, which allows us to tell the compiler that we're okay with a variable being unused.

# Introduction to iostream: cout, cin, and endl

## The input/output library

The input/output library (io library) is part of the C++ standard library that deals with basic input and output. We'll use the functionality in this library to get input from the keyboard and output to the data console. The io part of iostream stands for input/output.

### std::cout

std::cout allows us to send data to the console to be printed as text. 
- cout stands for "character output"

Example:
```C++
#include <iostream> //for std::cout

int main()
{
    std::cout << "Hello world!"; //print Hello world! to console
    
    return 0;
}
```
In the above example, we have included iostream so we have access to std::cout. We use std::cout with its insertion operator (<<), to send the text "Hello world!" (or any value outside of this specific program's context) to the console to be printed.

### Using std::endl to output a newline

Separate output stamenets do not result in separate lines of output on the console. So that means...
```C++
# include <iosteram> //for std::cout

int main()
{
    std::cout"Hello"
    std::cout"My name is arrstone"
    
    /* Together these would print: 
    HelloMy name is arrstone
    */
}
```
If we want to print separate lines of ouptut onto the console we need to tell the console to move the cursor to the next line. We can do that by outputting a newline.

- A newline is an OS-specific character or sequence of characters that moves teh cursor to the start of the next line.

Example:
```C++
#include <iostream> //for std::cout and std::endl

int main()
{
    std::cout << "Hi!" << std::endl, //std::endl causes the cursor to move to the next line

    std::cout <<"My name is Alex." << std::endl

    return 0;

    /* This is what the program prints:
    Hi!
    My name is Alex.

    */
}
```

### std::cout is buffered

std::cout is buffered, meaning that C++ statements that request outputs to the console are typically not sent to the console immediately. Instead the requested output "gets in line", and is stored in a region of memory set aside to collect such requests (called a buffer)
- Periodically, the buffer is flushed, meaning all of that data collected in the buffer is transferred to its destination (in this case the console)

### std::endl vs \n

Instead of using std::endl, you could just use "\n", which represents a newline.

std::endl actually does two things, it flushes the buffer (which is slow), AND it moves the cursor, which makes it inefficient.

Sot o output a newline without flushing the output buffer, we can just use \n

### std::cin

We've talked a lot about outputs, but what about inputs?

std::cin reads input from keyboard, and typically uses the extraction operator >> to put the input data in a variable.

Example:
```C++
#include <iostream>

int main()
{
    int number {};
    std::cout << "Enter Number";

    std::cin >> number;
    std::cout << number;
}
```

#### std::cin is buffered

std::cin is also buffered. Outputting data is a two step process

- The individual characters you enter as input are added to the end of an input buffer. The enter key is also stored as a '\n' character.

- The extraction operator '>>' removes characters from the front of the input buffer and converts them into a value that is assigned (via copy-assignment) to the associated variable. This variable can be used in subsequent statements.

Let's show an example:
```C++
#include <iostream>  // for std::cout and std::cin

int main()
{
    std::cout << "Enter two numbers: ";

    int x{};
    std::cin >> x;

    int y{};
    std::cin >> y;

    std::cout << "You entered " << x << " and " << y << '\n';

    return 0;
}
```
If you were to run this program and type "4" for the first input and then "5" for the second input, then the operation would run properly and would print "You entered 4 and 5"

However, if you type "4 5" in the first input, then by the time the second input runs, it won't wait for your input. Instead the 5 that is still in the input buffer is extracted to variable y. The program then prints "You entered 4 and 5".

# Uninitialized variables and undefined behavior

## Uninitialized variables

A varibale that has not been given a known value is called an uninitalized variable.

Using the values of uninitalized variables can lead to unexpected results.

Most modern compilers will attempt to detect if a variable is being used without being given a value. Usually it will give an error.

## Undefined behavior

Using the value from an unitianlized variable is our first example of undefined behavior

Undefined behaviour (UB) is the result of executing code whose behavior is not well-defined by the C++ language.

## Implentation-defined behavior and unspecified behavior

A specific compiler and the associated standard library it comes witha re called implenetation (as these are what actually implement the C++ langauge).

in some cases, the C++ language standards allow the implentation to determine how some aspects of the language will behave, so that the compiler can choose a behavior that is efficient for a given platform. 

Behavior that is defined by the implentation is called implentation-defined-behavior. Implentation-defined behavior must be documented and consistent for a given implentation.

For instance:
```C++
#include <iostream>

int main()
{
    std::cout << sizeof(int) << '\n' //print how many bytes of memory an intvalue takes

    return 0;
}
```
On most platforms this will produce 4, but on others, it may produce 2.

Generally you want to avoid implentation defined behavior and unspecified behavior.

# Keywords and naming identifiers

## Keywords

C++ reserves a set of 92 words for its own use. These words are called keywords (or reserved words), and each of these keywords has a special meaning within the C++ language.

![table of C++ keywords](keywords.png)

## Identifier naming rules

The name of a variable (or function, type, or other kind of item) is called an identifier. C++ gives you a lot of flexibility to name identifiers as you wish, however there are some rules:

- The identifier cannot be a keyword
- The identifier can only be composed of letters (lower or upper case), numbers, and the underscore character.
- The identifier must begin with a letter or an underscore. It can not start with a number
- C++ is case sensitive

## Identifier naming best practices

Usually its best to just make them all lowercase (though some disagree), and name it things that make sense. Like dont name an important variable (variable_one)

For having variables that are multiple words, separate them via underscore.

# Whitespace and basic formatting

## Some language elements must be whitespace-separated

This topic is fairly straightfoward.

The key thing is, sometimes you have to space code out for the compiler to properly understand whatever you're typing.

For instance:
```C++
intx; // This is not the same as...

int x;
```

Outside of that, whitespace is generally ignored

## Using whitespace to format code

Even though whitespace is generally ignored, its still better to format your code using whitespace.

Example:
```C++
#include <iostream>

//This code works, but it's hard to read
int main(){std::cout<<"Hello world!";return 0;}

```

Instead you use whitespace to separate each line of code.

C++ does not enforce any sort of formatting restrictions, so it is a whitespace-independent langauge.

In professional programming, you'll most likely use a style guide so that all developers on the team program in a consistent manner.

# Introduction to literals and operators

## Literals

A literal is a fixed value that has been inserted directly into the source code.

Literals and variables both have a value (and a type). 

Unlike a variable (whose value can be set and changed through initialization), the value of a literal is fixed and cannot be changed. The literal 5 will always have the value 5. This is why literals are called constants.

## Operators

Operators are processes involving zero or more input values called operands, that produce a new value, called an output value.

For instnace, 1 + 2 = 3. This is '+' is an operator, and the output value is 3. The literals 1 and 2 are the operands.

### Unary operators

Unary operators act on one operand. For instance, given -5, operator - takes literal operand 5 and flips its sign to produce a new output value -5.

### Binary operators

Binary operators act on two operands. An example of a binary operator is '+' since it needs operand1 + operand2

### Ternary

Ternary operators act on 3 operands (conditional operator)

### Nullary

Nullary operators act on zero operands. (the throw operator)

# Introduction to expressions

## Expressions

Expression is a non-empty sequences of literals, variables, operators, and function calls that calculates a value. The process of executing an expression is called na evaluation, and the resulting value produced is called the result.

For instance:
```C++
2 //evaluates to 2
"Hi" //evaluates to hi
x //evaluates to whatever value variable x holds
2 + 3 //evaluates to 5
five() //evaluates to the return value of function five
```

### Useless expression statements

These are expressions that exist but are never used, such as

2 * 3;

this results in 6 but its never used, or stored, so its just discarded.

### Subexpressions, full expressions, and compound expressions

subexpressions is an expression used as an operand. Like the subexpressions of x = 4 + 5 are x and "4 + 5"

A full expression is an expression that is not a subexpression. Like 2 is a full expression, or 2 + 3 (while not being used as an operand)

and a compound expression is an expression that contains two or muse of operators.

# Introduction to functions


## Functions
A function is a reusable sequence of statemens designed to do a particular job.

Every executeable program must have a function named main(), as aforementioned. However, as programs start to get longer and longer, putting all the code inside the main() function becomes increasingly hard to manage. So functions allow a way to separate different code into small, modular chunks that are easier to organize, test, and use.

A funciton you write yourself is called *user-defined functions*

For instance:
```C++
int add()
{
    int num1 {}, num2 {};
    std::cout << "Enter first number";
    std::cin >> num1;

    std::cout <<"Enter second number";
    std::cin >> num2;

    std::cout << num1 << " + " << num2 << " is " << num1 + num2;

}
```

When I call this function, add, it will run this sequence of code.


The first line is informally called the function header, and it tells the compiler about the existence of a function, the function's name, and some other information (such as the return type or possible parameters a.k.a arguments)

## Calling functions more than once
You can call functions more than once. In fact you can call them as much as you like

## Functions call call other functions
Functions cal call OTHER functions. So you can make a function thats designed to only be used WITHIN a function.

However, nested functions are not supported. Meaning you cant create a function within a function.

# Function return values (value-returning functions)

## Return values

When you write a user-defined function, you get to determine whether your function will return a value back to the caller or not. To return a value back, two things are needed.

First your function must indicate the type of value it is meant to return (remember how we always did int in front of main()?)

If your function returns no value, then you can use void (meaning no value will be returned to the caller).

Secondly, inside the function you must add a return statement to indicate the specific value being returned to the caller.

## Status codes

The return value from main() is sometimes called a status code (or an exist code/return code). The status code is used to signal whether your program was successful or not.

A non-zero status code is often used to indicate some kind of failure (and while this works fine on most operating sysems, it's not guaranteed to be portable)

- C++ only defines the emaning of 3 status codes: 0, EXIT_SUCCESS, and EXIT_FAILURE. 0 and EXIT_SUCCESS both mean the program executed successfully. EXIT_FAILURE means the program did not execute successfully.

# Void functions (non-value returning functions)

## Void return values

Functions are not required to return a value back to the caller. To tell the compiler that a function does not return a value, a return type of void is used. For instance:

```C++
#include <iostream>

void printHi()
{
    std::cout << "Hi\n";
}

int main()
{
    printHi();

    return 0;
}
```

Notice how while main() returns an integer, 0 as the status code for EXIT_SUCCESS, printHi() does not need to return anything.

You can use void functions for general printing purposes, but if you try to return something within a void function, it won't work.

Void functions also can't be used in expressions that require a value. You can't print or assign something the value of a void function since there is nothing to execute nor assign.

# Introduction to function parameters and arguments

## Function parameters and arguments

It can be useful to pass information to function beign called, so that the function has data to work with. For instance, if we wanted to write a function to add two numbers, we need some way to tell the function which two numbers to add when we call it. Otherwise, how would the function know what to add? We do that via function parameters and arguments


### Func parameter

A function parameter is a variable used in the header of a function. Function parameters work almost identically to variables defined inside the function, but with one difference, they are initialized with a value provided by the caller of the function.


For instance:
```C++
#include <iostream>

void print(int x)
{
    std::cout << x 
}

int main()
{
    print(4) //this is a function that takes the parameter, x, as any number for it to print. The ARGUMENT is the number 4 itself, since that is value actually being passed.
}

```

### Func argument

An argument is a value that is passed from the caller to the function when a function call is made.

### Argument and Parameter relationship

When a function is called, all of the parameters of the function are created as variables, and the value of each argument is copied into the matching parameter (using copy initialization). This process is called pass by value.

Function parameters that utilize pass by value are called value parameters.


## Using return values as arguments

This is pretty simple. No matter what a function does, if you specify it to have a return value, it will (assuming youve structured it correctly), return a value. What you do with that value can be used as an argument for another funciton.

Imagine this, you have a function used to get a number, and then another function called that function's output to print the number.

```C++
#include <iostream>

int getnum()
{
    int input {};
    std::cout << "Enter number: \n"
    std::cin >> input;
    return input
}

void printnum(number)
{
    std::cout << number << "\n"
}

int main()
{
    printnum(getnum())
    return 0;
}

```
As you can see here, print num uses getnum AS the argument, because getnum will return a number for it to print.

### Parameters and return values relationship

By using both parameters and a return value, we can create functions that take data as input, do some calculation with it, and return the value to the caller.

Here is an instance of that exact thing:
```C++
//add() takes two integers as parameters, and returns the result of their sum

// The values of x and y are determined by the function that calls add

int add(int x, int y)
{
    return x + y
}

//main takes no parameters (duh)
int main()
{
    std::cout << add(4, 5) << '\n' //Arguments 4 and 5 are passed to function add()
    
    return 0;
}
```

## Unreferenced parameters and unnamed parameters

In some cases, you will encounter functions that have parameters that are not used in the body of the function. These are called unreferenced parameters.

For instance:
```C++
void dowhatever(int count) //warning: unreferenced parameter count
{
    //This function used to do something with count but it is not used any longer
}

int main()
{
    doSomething(4);

    return 0;
}
```

Just like with unused local variables, your compiler will probably warn that variable count has been defined but not used.

In a function definition, the name of a funciton parameter is optional. Therefore, in cases where a function parameter needs to exist but is not used in the body of a function, you can simply omit the name. A parameter without a name is called an unnamed parameter.

# Introduction to local scope

## Local variables

Local variables are variables defined inside the body of a function.

For example:
```C++
int (add int x, int y)
{
    int z{ x + y}; //z is a local variable

    return z;
}
```

### Local variable lifetime

Function parameters are created and initialized when the function is entered, and variables within the function body are created and initialized at the point of definition

For example:
```C++
int add(int x, int y) // x and y created and initialized here
{
    int z{ x + y };   // z created and initialized here

    return z;
}
```

Much like a person's lfietime is defined to be the time between their birth and death, an object's lfietime is defined between the time of its creation and destruction.
- Note that variable creation and destruction happen when program is running (called runtime), not at compile time. Therefore, lifetime is a runtime property.

#### What happens when an object is destroyed?
In most cases, nothing. The destroyed object simply becomes invalid


Any use of an object after it has been destroyed will result in undefined behavior. At some point after desctruction, the memory used the object will be deallocated (freed up for reuse.)

## Local scope (block scope)

An identifier's scope determines where the identifier can be seen and used within the source code. When an identifier can be seen and used, we say it is "in scope". When an identifier can not be seen, we can not use it, and we say it is "out of scope". Scope is a compile-time property, and trying to use an identifier when it is not in scope will result in a compile error.

The identifier of a local variable has a local scope. An identifier with local scope (technically called block scope) is usable from the point of its definition to the end of the innermost pair of curly braces containing the identifier (or for function parameters, at the end of the function). 

This ensures local variables cannot be used before the point of definition (even if the compiler opts to create them before then) or after they are destryed. Local variables defined in one function are also not in scope in other functions that are called.

For example
```C++
#include <iostream>

// x is not in scope anywhere in this function
void doSomething()
{
    std::cout << "Hello!\n";
}

int main()
{
    // x can not be used here because it's not in scope yet

    int x{ 0 }; // x enters scope here and can now be used within this function

    doSomething();

    return 0;
} // x goes out of scope here and can no longer be used
```

### "Out of scope" vs "going out of scope"

An identifier is out of scope anywhere it cannot be accessed within the code. Like in the example above, x is in scope from its point of definition to the end of the main function.

"Going out of scope" is typically applied to objects rather than identifiers. We say an object goes out of scope at the end of the scope (the end curly brace) in which the object was instantiated. Like the object named x goes out of scope at the end of the function main

A local variable's lifetime ends at the point where it goes out of scope, so local variables are destroyed at this point. Not all types of variables are destroyed when they go out of scope however.

## Intro to temp objects

A temporary object (also sometimes called an anonymous object) is an unnamed object that is used to hold a value only for a short period of time. Temporary objects are generated by the compiler when they are needed.

For example:
```C++
#include <iostream>

int getValueFromUser()
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input; // return the value of input back to the caller
}

int main()
{
	std::cout << getValueFromUser() << '\n'; // where does the returned value get stored?

	return 0;
}
```

In the above program, the function getValueFromUser() returns the value stored in local variable input back to the caller. Because input will be destroyed at the end of the function, the caller receives a copy of the value so that it has a value it can use even after input is destroyed.

Temp objects have both no scope nor identifier.

# Foward declarations and definitions

## Foward declaration

A foward declaration allows us tot ell the compiler about the existence of an identifier before actually defining the identifier.

In the case of functions, this allows us to tell the compiler about the existence of a function before we define the function's bodyd. This way, then the compiler encounters a call to the function, it'll understand that we're making a function call, and can check to ensure we're calling the function correctly, even if it dosen't yet know how or where the function is defined.

To write a foward declaration for a function, we use a function declaration statement (also called a function protoype). The function declaration consits of the function's return type, name, and parameter types, terminated with a semicolon. The names of the parameters can be optionally included. The function body is not included in this declaration.

For example:
```C++
int add(int x, int y); // function declaration includes return type, function name, parameters, and a semicolon.

```

And in action it would look like this:

```C++
#include <iostream>

int add(int x, int y); // forward declaration of add() (using a function declaration)

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n'; // this works because we forward declared add() above
    return 0;
}

int add(int x, int y) // even though the body of add() isn't defined until here
{
    return x + y;
}
```

## Why foward declarations?

Why use a foward declaration if we could just reorder the functions to make our programs work?

Most often, foward declarations are used to tell the compiler about the existence of some function that has been defined in a different code file. Reordering isn't possible in this scenario because the caller and the callee are in completely different files!

## Errors

If you declare a function but do not define it, there is no one specific error that might happen. 

If a foward declaration is made, but the function is never called, the program will compile and run fine. howveer, if a foward declaration is made and the function is called, but the program never defines the function, the program will compile okay, but the linker will complain that it can't resolve the function call.

For instance:
```C++
#include <iostream>

int add(int x, int y); // forward declaration of add()

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
    return 0;
}

// note: No definition for function add
```

## Other types of foward declarations

Foward declarations can also be used with other identifiers in C++, such as variables and types. Variables and types have a different syntax for declarations.

## Declarations vs. definitions

A declaration tells the *compiler* about the *existence* of an identifier and its associated type infomration.

A definition is a declaration that actually implements (for functions or types) or instantiates (for variables) the identifier.

## The one definition rule (ODR)

The ODR has three parts:

1. Within a file, each function, variable, type, or template in a given scope can only have one definition. Definitions occurring in different scopes do not violate this rule.

2. Within a program, each function or variable in a given space can only have one definition. This rule exists because programs can have more than one file .

3. Types, tempaltes, inline functions, and inline variables are allows to have duplicate definitions in different files, so long as each definition is identical.

Violating part 1 of the ODR will cause the compiler to issue a redefinition error. Violating part 2 will cause the linker to issue a redefinition error. And then violating ODR part 3 will cause undefined behavior.

# Programs with multiple code files

## A multi-file example

Let's take a look at a multi-file program:

add.cpp:
```C++
int add(int x, int y)
{
    return x + y;
}
```

main.cpp:
```C++
#include <iostream>

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n'; // compile error
    return 0;
}
```

Your compile may compile whichever program first, but regardles, main.cpp will fail to compile since the "add" identifier will not be found, since the identifier for said function is within another file.

The compiler compiles each file individually, it dosent know about the content of any other code files, or rememebr anything it has seen from previously compiled code files. So even though the compiler may have seen the definition of functiona dd previously, it dosen't remember.

Our options for a solution are either to place the defintion of the function "add" before function main OR use a foward declaration for "add". Since add is in another file, we are going to do the latter.


main.cpp (updated)
```C++
#include <iostream>

int add(int x, int y); //needed so man.cpp knows that add() is a function defined somewhere else

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3,4) << "\n"
    return 0;
}
```

# Naming collisions and an introduction to namespaces


## Naming collision (or naming conflict)


If two identical identifiers are introduced into the same program in a way that the compiler or linker can't tell them apart, the compiler or linker will produce an error. This error is generally referred to as a naming collision (or naming conflict).

Here's an example:
a.cpp
```C++
#include <iostream>

void myFcn(int x)
{
    std::cout << x;
}

```

main.cpp
```C++
#include <iostream>

void myFcn(int x);
{
    std::cout << 2 * x;
}

int main()
{
    return 0;
}
```

Here we have TWO files, main.cpp and a.cpp. However BOTH files have functions with the same identifiers: "myFcn". There is no distinguishing feature between either. So when the compiler compiles the program, it will function since it compiles them seperately.

However...when the linker executes, it will link all the definitions in a.cpp and main.cpp together, and discover conflicting definitions for function myFcn(). The linker will then abort with an error.
- This error occurs even though myFcn() is never called!
