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

Like vectors, the array is a data structure used in C++ to store a squential collection of elements. However unlike vectors, its size cannot be cahgned.
