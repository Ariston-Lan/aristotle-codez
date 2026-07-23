# What is JavaScript, and How Does it Work with HTML and CSS?

## JavaScript
Javascript is a powerful programming language that brings interactivity and dynamic behavior to websites.

# What Is a Data Type, and What Are the Different Data Types in JavaScript?

## Data Type
A data type is the kind of value you store, like a number of piece of text.

Javascript has several basic data types

### Number
This one...get this, is a number!

No but seriously, a number represent both integers (1) and floating-point values (3.14)

```javascript
console.log(3);
console.log(5.4);
console.log(-67);
```

- console.log() is a function that prints information to the console. Anyways, here you can see that its just printing numbers and floating point numbers

### String
The second type of data type is a string. 

A string is a sequence of characters, or text, enclosed in quotes.

```js
console.log("I love to code");
```
- Here javascript is printing the string "I love to code"

### Boolean
A boolean represents one of two values, true or false

True and False are both values in their own right, and certain things can be true, like if a user's input is correct, or False, like a wrong password.

### Undefined
This means the variable has been declared but hasn't been given a value yet

### null
Null means the variable has been intenitonally set to "Nothing" and does not hold any value. Similar to None in Python.

### Object
Object is a collection of key-value pairs (similar to a dictionary in Python.)

```js
{
    name: "alice",
    age: 30
};
```

### Symbol
A symbol is a special type of value in JavaScript that is always unique and cannot be changed. 
```js
Symbol('mySymbol');
```

### BigInt
BigInt is used for very large numbers that exceed the limit of the Number Type:
```js
3274106413860436473216041326478163216021762n;
```
- The n is what makes it a BigInteger if that wasn't clear.

# What Are Variables, and What Are Guidelines for Naming JavaScript Variables?



