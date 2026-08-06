# Vectors

## Introduction to Vectors
A vector is a sequence of elements that you can access by index (similar to a list.)

## Creating a Vector
The std::vector lives in the <vector> header, so before we even make a vector we'll need to include vectors via #include <vector>

- Recall that #include is a preprocessor directive tells the compiler to include whatever library that follows. In our case, that is the standard vector library.

The standard syntax to create a vector is:
```C++
std::vector<type> name;

// So in action it'd look like this:

std::vector<int> calories_today;
//This would be a vector of numbers, with the variable name of calories_today
```

Inside the angle brackets is the data type of the vector, and after the angle brackets is the name of the vector.

## Initializing a Vector
So now we know how to create vector, so we should learn how to initialize it too.

Instead of just naming a vector, similar to variables themselves, you can create and assign a vector's value in the same line.

Here is it in action:
```C++
std::vector<double> location = {4.324, -5.324};
```

Here we are storing a latitude and longitude.

### Presizing
Another way we can initialize our vector is by presizing, or setting the size.

Suppose we want to create and initialize a vector with two elements. However we don't know what values we want to add yet:
```C++
std::vector<double> location(2);
```
This tells us we are creating a double vector and setting the initial size to two using parentheses.

It would look something like this {0.0, 0.0}, since 0.0 is the default value for double.

## Index
Vectors have indices starting from 0

If we have a vector such as this:
```C++
std::vector<char> letters={'a', 'b', 'c', 'd'};
// letters[0] = 'a'
// letters[1] = 'b'
//letters [2] = 'c'
//letters [3] = 'd'
```

## Adding and Removing Elements

Regardless of if you start with a vector that's empty or at a certain length, as you compute the data you want, you can grow the vector as needed.

For instance, .push_back() is used to add a new element to the "back" or the end of the vector (similar to append).

For instance:
```C++
std::vector<std::string> dna = {'ATG', 'ACG'};
dna.push_back('GTG');
std::cout << dna;
//{'ATG', 'ACG', 'GTG'}
```

You can also remove elements from the "back" of the vector using a method called .pop_back().
- I don't know why the course sayd the "back" of the vector, it just removes the last added element.

```C++
dna.pop_back();
std::cout << dna;
//{'ATG', 'ACG'}
```

## Methods

- The .size() function returns the number of elements in the vector

- The .push_back() method adds to the end of the vector

- The .pop_back() removes the last element

- The .empty() returns true or false

- The .front() accesses the first element

- The .back() accesses the last element

- .at() accesses an element at specific index (similar to doing variable[index], except .at() is safer since it checks if it exists first)

- The .clear() clears the vector

## Operations

You can loop through vectors in order to change each of the values within it.

For instance:
```C++
for (int i = 0; i < vector.size(); i++) {
    vector[i] = vector[i] + 10;
}
```

So here we are declaring a variable of type integer called i, this will represent the indices or the index number that we'll use to access the elements in the vector. And then we do our conditional, which says that as long as i is not greater than the current list size, we update i by +1 every time. 

So what does that actually do? Well it allows us to traverse the vector one index at a time.

Then we can do whatever we like to each value at the specifies index.

In this case we are adding 10 to each value in the vector. The program would function similarly to this (assume here the vector has a size of 10):
```C++
vector[0] = vector[0] + 10;
vector[1] = vector[1] + 10;
//...
vector[10] = vector[10] + 10;
// checking conditional, i = 10, i < vector.size() is false, so i no longer increases and loop ends.
```

# Arrays

Like vectors, the array is a data structure used in C++ to store a squential collection of elements. However unlike vectors, its size cannot be chagned.

Being able to store multiple pieces of related information in the same structure is very useful in programming. One way we do that is vectors.

Arrays are similar to vectors in that they allow us to store groups of information. However, arrays are ultimately lower-level constructs and require some more work on the part of the user.

## Arrays vs Vectors

With arrays you cannot add or remove elements, you can only modify EXISITNG elements.

Vectors originated from arrays, so back in the day devs took these basic arrays and enhanced them to make them more flexible and powerful.


## Creating arrays

When creating an array you give its type, the name of it, and its size.

For example:
```C++
int coolarray[4];
```

In the above code we create an array of only integers of size 4. So it can ONLY hold four integers.

## Array indices

Each element in an array is assigned a specific index starting at 0, and they are accessed via indices the same way vectors are.

# Functions

Functions (also known as a method or procedure) is a named group of code statements that accomplish something together, a bit like a factory machine.

## Built in functions

C++ comes with some built in functions that are apart of the standard library.

For instance, if you do #include <cmath> as a preprocessor you gain access to math functions such as sqrt().

rand() is also a simple random number generator that creates a number between whatever range you dictate, given that you seed the random number generator

```C++
//This seeds the random number generator:
srand (time(NULL));

//This is rand, that generates the random number.
rand() % 29
//outputs a random number between 0 and 29
```

## Declare and Define

The structure for functions is you declare the function, what its return type is, and any parameters(if the function will need to accept any arguments)

Then the definition is the function body, which is a group of code statements used to accomplish the task.

## Void

A void funciton, also known as a subroutine, has no return value, making it ideally suited for situations where you just want to print stuff to the terminal.

For instance:
```C++
void gay_chat() {
    std::string name;
    char choice;

    std::cout << "whats your name?\n";
    std::cin >> name;

    std::cout << "Are you gay? y/n \n";
    std::cin >> choice;
    choice = std::tolower(choice)
    if (choice == 'y'){
        std::cout << "cool, have fun being gay"
    }
    else if (choice == 'n'){
        std::cout << "cool, have fun not being gay"
    }
    
}
```

## Return Types

When you want your functions to return something and pass information back to the rest of your program, you can use different return types.

A function can return most data types. The return statement itself is the last line of code that will execute.

