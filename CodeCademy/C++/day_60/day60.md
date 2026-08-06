# Classes and Objects

## Class
A C++ class is a user-defined data type.

The class serves as a blueprint for objects, which are instances of the class (just like age is an instance of int). An object gets characteristics and behaviors from its class

You can create a C++ class as follows:
```C++
class City {

}; // <-- Notice the semicolon!
```

Classes are designed to bring together related information and functionality.

Componenets of a class are called class members. Just like you can get a string's length using .length(), you can access class memebrs using the dot operator (object.class_member).

There are two types of class members: attributes and methods.

- Attributes, also known as member data, consists of informations. Like an object's name or some other innate/given value the object has.

- Methods, also known as member functions, are functions that cause the object to execute whatever code is specified within them. 

Unless there is an empty class, it's common to split function declarations from definitions. We declare methods inside the class (in a header), then define the methods outside the class (in a .cpp file of the same name)

You can define methods outside of a class using ClassName:: before the method name to indicate its class like this:

```C++
//(in city.hpp)
class City {
    int population;

public:
    int get_population();
};

//(in city.cpp)
#include city.hpp

int City::get_population() {
    return population;
}
```

In the preceding code sample, we declare .get_population() in the ehader file, city.hpp. Unlike regular functions, we need to include the header file in the .cpp file where we define the methods, which we have done at the top of city.cpp. Then, we provide the definitions for .get_population(), which returns the value of the population attribute.

Notice how you are able to access population within city.cpp even though it was declared within city.hpp? Since it was declared in the City class, it will be accessible to any method that is also declared in the City class.

## Creating Objects

After creating your class, you can create objects.

To create (or instantiate an object), you can do this:
```C++
City accra;
```

Then you can give the object's attributes values like this (not that these must be attributes you defined before within the class)
```C++
accra.population = 20039
```

## Access Control: Public and Private

### Overview
By default, everything in a class is private, meaning class members are limtied to the scope of the calss. This makes it easier to keep data from being mistakenly altered, and abstracts away all the nitty gritty details. If you try to access a private class member, you'll get an error.

Sometimes though, you DO need to access class members, and for that there is public. You can use it to make everything below it accessible outside of the class.

### Public
As aforementioned, using public makes everything below it accessible ouside of the class. For isntance:

```C++
class City{
    int population;

pubic: //stuff below is public, stuff above is private
    void add_resident() {
        population++;
    }
};
```
So in this example, nobody could go New_York.population += 1 since it is a private attribute, you could however still acess it via New_York.add_resident().

### Private
There is also a private access modifier for when you want something below public to still be private.

# Constructors
There is a way to give an object some data right away when it gets created, similar to python's self.whatever process

A constructor is a special kind of method that lets you decide how the objects of a class get created. It has the same name as the class and no return type. Constructors really shine when you want to create an object with specific attribute (such as a name, age, or anything else)

If you wanted to give each city the attribute of a name and population, you would use them as parameters for creating the class as follows:
```C++
//in city.hpp
class City {
    std::string name;
    int population;

public:
    City(std::string new_name, int new_pop)
};

//in city.cpp
City::City(std::string new_name, int new_pop)
    : name(new_name), population(new_pop)
```

You could also write the definitions like this
```C++
City::City(std::string new_name, int new_pop) {
    name=new_name;
    population = new_pop;
}
```

And then to create an object with said attributes you would just do:
```C++
City ankara('Ankara', 5445000)
```

# Destructors
An object destruction is about tidying up and preventing memory leaks. A destructor is a special method that handles object destruction. Like a constructor, it has the same name as the class and no return type, bu is preceded by a ~ operator and takes no parameters.

example:
```C++
// city.hpp
class City {
 
  std::string name;
  int population;
 
public:
  City(std::string new_name, int new_pop);
  ~City();
};
 
// city.cpp
City::~City() {
  
  // any final cleanup
  
}
```
Inside, you add any housekeeping that needs to happen before the object is destroyed. You generally won't need to call a destructor; the destructor will bec alled automatically if the object:
- Moves out of scope
- Is being explicitly deleted
- When the program ends

# References and Pointers

## References

In C++ a reference variable is an alias for something else, that is, another name for an already existing variable.

So suppose we make Sonny a reference to someone named Mark. You can refer to the person as either Sonny or Mark.

Suppose we have an int variable already named mark, we can create an alias to it by using the & sign in the declaration:
```C++
int &sonny = mark
```

So here we made sonny a reference to mark.

### Pass-By-Reference
When we passed parameters to a function, we used normal variables and that's known as pass-by-value. But because the variables passed into the function are out of scope, we can't actually modify the value of the arguments.

Pass-by-reference refers to passing parameters to a function by using references. When called, the function can modify the value of the arguments by using the reference passed in.

This allows us to:
- Modify the value of function arguments.
- Avoid amking copies of a variable/object for performance reasons.

The following code demonstrates an example of pass-by-reference:
```C++
void swap_num(int &i, int &j) {

  int temp = i;
  i = j;
  j = temp;

}

int main() {

  int a = 100;
  int b = 200;

  swap_num(a, b);

  std::cout << "A is " << a << "\n";
  std::cout << "B is " << b << "\n";

  // A is 200
  // B is 100

}
```

#### Using Const in pass by reference

The const keyword tells the compiler that we won't change something (hence it being a constant)

For example:
```C++
double const pi = 3.14
```
This says that the variable pi is a double(floating number, so a decimal) and constant (meaning it will never change from 3.14)

If we try to change pi the compiler will throw an error.

Sometimes, we use const in a function parameter; this is when we know for a fact we want to write a function where the parameter won't change inside the function, here's an example:
```C++
int triple(int const i) {
    return i * 3
}
```

In this example we are saying that, if inside the function triple(), the value of i is changed, there will be a compiler error.

So, to save the computational cost for a function that dosen't modify the parameter value(s) we can actually go a step further and use a const reference.

```C++
int triple(int const &i) {
    
return i * 3

}
```
In this example we arent modifying i. We are just multiplying i by 3 and returning that value after the function completes it.

By making i a reference to the argument, this saves the computational cost of making a copy of the argument.

### Memory Address

The "address of" operator, &, is used to get the memory address, the location memory of an object.

Suppose there is a variable called:
```C++
int count = 3;
```

Where is the variable count actually stored on the computer? We can find out by printing out &count:

```C++
std::cout << &count; << "\n"
```

It will return something like "0x7ffd7caa5b54"

This is a memory address represented in hexadecimal. A memory address is usually denoted in hexadecimal instead of binary for readability and coniseness.

So remember:
- When & is used in a declaration, it is a reference operator
- When & is not used in a declaration, it is an address operator.

## Pointers
In C++ a pointer variable is mostly the same as otehr variables, with one caveat. Normal variables store a data type (such as int, double, char), whereas a pointer stores a memory address/

While references are a new mechanism that originated in C++, pointers are an older mechanism that was inherited from C. We recommend avoiding pointers as possible; usually, a reference will do the trick.

However, you will see pointers a lot in the wild, particularly in older projects, where they are used in a very similar way to references.

Pointers must be declared beefore they can be used, just like a normal variable. They are syntatically distinguished by an asterisk (*).

so int* means "pointer to int" and double* means "pointer to double"

Example:
```C++
int* number;
double* decimal;
char* character;
```

So suppose we have a variable, gum:
```C++ 
int gum = 8;
```

We can create a pointer to it by:
```C++
int* ptr = &gum;
```
In this case, int* makes it "ptr" a pointer rather than a normal variable, and ptr is just the variable name, and then = &gum is the memory address of the other variable, gum.

### Deference

The asterisk sign (*) also known as the deference operator is used to obtain the value pointed to by a variable. This can be done by preceding the name of a pointer variable with the asterisk (*).

```C++
int number = 30;

int* ptr = &30

//number = 30
// ptr = memory address of number

std::cout << *ptr

// This prints 30 bc thats the value at the memory address.

```
### Null Pointer

When we declare a pointer variable, its content is not initialized:

In other words, it contains an address of "somewhere", which is of course not a valid location. This is dangerous! So we need to intitalize a pointer by assigning it a valid address.

```C++
int* ptr;
// Uninitialized pointer

int* ptr = null ptr;
//Initialized pointer
```
