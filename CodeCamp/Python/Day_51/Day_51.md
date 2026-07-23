# What Is an Algorithm and How Does Big O Notation Work?

## Algorithm
Every computer program that runs on your device has a specific set of instructions, which are executed in a specific order to complete a task.

An algorithm is a set of unambiguous intrusctions for solving a problem or carrying out a task. They have two characteristics:
- They cannot continue indefinitely. They must finish in a finite number of steps.
- Each step must be precice and unambiguous.

They may have zero, one, or more inputs, and generate one or more outputs.

The steps of an algorithm are independent from any programming language, but to actually make them run on a computer, you need to implement them in a programming language, like Python or JavaScript.

If an algorithm is correct, the output for any valid input should match the expected output.

In addition to being correct, algorithms should also be efficient. Algorithm efficiency can be measured in terms of how long they take to run and how much space they require in memoryto complete the task. Knowing an algorithm's efficiency is very important because it gives you an idea of how well it will perform as the input size grows. 

## Big O Notation
Sorting 15 integers is obviously not the same as sorting 1 million integers. As the process grows in size and complexity, if the algorithm is not efficient enough to handle it, you might end up with a very slow computer program that may even crash the system.

This is where Big O notation becomes very important. 

Big O notation describes the worst-case-performance, or growth rate, of an algoirithm as the input size increases. The growth rate of an algorithm refers to how the resources it requires increase as the input size grows.

Big O notation focuses on the worst-case performance because this case is very important to understand how efficient the algorithm can be, even in the worst case scenario, regardless of the input.

Going back to our sorting example, sorting 1 million integers should intuitively take more time and resources than sorting 15 integers. But how much more? This really depends on the algoirthm that you choose to sort them.

### Big O Notation Formula
Big O notation will not give you an exact number to describe the algorithm's efficiency, but it will give you an idea of how it scales as the input size grows, based on the number of operations performed by the algorithm. 

In Big O notation, we usually denote the input size with the letter n. For example, if the input is a list, n would denote the number of elements in that lsit.

Constant factors and lower-order terms are not taken into account to find the time complexity of an algorithm based on the number of operations. That's because as the size of n grows, the impact of these smaller terms in the total number of operations performed will become smaller and smaller.

The term that will dominate the overall behavior of the algorithm will be the highest order term with n, the input size.

For instance, if an algorithm performs 7n + 20 operations to be completed, the impact of the constant 20 on the final result will be smaller and smaller as n grows. The term 7n will tend to dominate and this will define the overall behavior and efficiency of the algorithm.

Another example would be an algorithm that takes 20n^2 + 15n + 7 operations to be completed. The term 20n^2 will tend to dominate as n grows, so this algorithm would have a quadratic time compleity because the dominant term has n^2.

Quadratic time complexity is one of many different types of time complexities that you can find in the world of algorithms.

### Time complexities


#### Constant Time Complexity 0(1)
0(1) is known as the "Constant Time Complexity". When an algorithm has constant time complexity, it takes the same amount of time to run, regardless of input size. 

For instance, checking if a number is even or odd will always take the same amount of time regardless of the number itself.

```python
def check_even_or_odd(number):
    if number % 2 == 0:
        return "Even"
    else:
        return "Odd"
```

#### Logarithmic Time Complexity 0(log n)
0(log n) is known as "Logarithmic Time Complexity". This means the time required by the algorithm increases slowly as the input size grows. This is common in problems in which the size of the problem is repeatedly reduced by a constant fraction.

For instance, a popular search algorithm called Binary Search has 0(log n) worst-case time complexity. This is because it eliminates half of the remeaining elements in each comparison, which makes it more efficient overall.

#### Linear Time Complexity 0(n)
0(n) is known as liner time complexity. The running time of algorithms with this time complexity increases proportionally to the input size.

For instance, a for loop that iterates over all the elements of a list will perform more iterations as the number of list elements increases. If the list is doubled in size, the number of operations will approximately double as well.

#### Log-Linear Time Complexity 0(n log n)
0(n log n) is known as "Log-Linear Time Complexity". This is a common time complexity of efficient sorting algorithms, like Merge Sort and Quick Sort.

#### Quadratic Time Complexity 0(n^2)
The running time of these algorithms increases quadratically relative to the input size, which is generally not efficient for real world problems.

Nested loops are a common example of quadratic time complexity. The inner loop will perform n iterations for each one of the n iterations of the outer loop, resulting in n squared iterations.

### Space Requirements
So far, you've learned about Big O notaiton in terms of time requirements, but thisnnotation can also be applied to the context of space requirements.

In this context, it describes how the memory space required by the algorithm grows as the input size grows.

#### Constant Space Complexity 0(1)
Algorithms with "Constant Space Complexity" 0(1) always require a constant amount of memory space, even as the input gets larger.

An example would be an algorithm that only creates and stores a few variables in memory.

#### Linear Space Complexity 0(n)
In contrast, the space required by algorithms with "Linear Space Complexity" 0(n) increases proportionally as the input size grows.

An example of this would be an algorithm that creates and stores a copy of a list of length n.

#### Quadratic Space Complexity 0(n^2)
The space requirements of an algorithm with Quadratic Space Complexiy 0(n^2) obviously increase quadratically as the input size grows.

An example of this would be creating a 2D matrix, where dimensions are determined by input size, storing all possible pairs.

# What Are Good Problem-Solving Techniques and Ways to Approach Algorithmic Challenges?

## Reversing a string in python
There are several problem-solving techniques you should try to develop.

To show you how you should go about practicing them, let's solve the challenge to reverse a Python string.

Ask yourself:
- What is the input?
- What is the expected output
- How can I transform the input into the expected output?

Seems redundant I am aware but its fundamentally what you'll use every time.

In this case, the input is a string, the output is the original string but reversed, so you need to take the original string and reverse it.

### Pseudocode
Pseudocode is a high-level description of the algorithm's logic that is general in nature, and not based on any specific programming language. It is not as formal as actual code, since it's only intended for humans to read. It should be easy to understand at a glance.

For instance,

GET original_string

SET reversed_string = ""

FOR EACH character IN original_string:
    ADD character TO THE BEGINNING OF reveresed_string

DISPLAY reversed_string

### Choosing The Algorithm
This dictates everything the code needs to do. But this problem can be solved in many different ways, and choosing the right algorithm is important. Thinking through different available algorithms is an important problem solving skill that you should practice. 

For example, there are many different algorithms for sorting elements, but some of them are more efficient than others. Bubble sort, for example, is very inefficient for sorting large lists, while Quick Sort is usually more efficient.

For our "Reverse a String" challenge, we could use either one of these approaches, assuming that we are planning to implement our algorithm in python:

- Using extend slice syntax [::-1] to get a new reversed string.
- Looping over the characters from left to right and adding the new character to the beginning of the new string.
- Calling the reversed function to get an iterator with all the characters in reverse order, and then the "".join() method to concatenate them back into string.

Which one should you use? That's your choice.

Making these decisions based on your knowledge and experience can make a huge difference in the final performance of your application.

# How Do Dynamic Arrays Differ From Static Arrays?

## Arrays
Arrays are a fundamental data structure in comptuer science. All arrays store ordered collections of data, but depending on their type, they may work different behind the scenes. 

Their underlying behaviour can have an important effect in the program's efficiency, so let's learn about dynamic and static arrays and their differences, so you can choose the most efficient one for your program.

### Statis Arrays
Statis arrays have a fixed size. They store elements in adjacent memory locations.

The size of a static array is determined when the array is intialized. Once that specific block of memory is allocated, it's fixed and cannot be changed while the program is running. This is a key characteristic of statis arrays.

Storing elements in adjacent memory locations makes the data retrieval process more efficient because the program can store the location of the first element and then use indices to make simple calculations and find other elements in memory.

Thanks to this, accessing the values of a static array takes constant time 0(1), which is very efficient.

You can use a static array when you know the number of elements that will be stored in advance. It's also helpful when the values will be accessed very frequently, since the access operation is very efficient.

However, this data structure cannot grow or shrink, so if the number of elements that will be stored can vary, you should use a dynamic array instead. 

Trying to increase the size of a static array would involve creating a new array and copying all the elements from the old array into a new one, which is inefficient. In that case, a dynamic array would be much better because it handles this process automatically.

- Python does not include traditional static arrays as built in structures. Tuples are technically not defined as static arrays programmatically.

### Dynamic arrays
Dynamic arrays are more flexible because they can grow or shrink automatically while the program is running. They work through automatic resizing mechanism that copies the elements into a new array when the original array is full. The process is done efficiently because the size of the new array is chosen in an efficient way that makes these computationally expensive operations less frequent.

Accessing elements of a dynamic array takes constant time 0(1), so this operation is very efficient.

Inserting an element in the middle of the arrary takes linear time 0(n) because the elemnts after need to be relocated.

Insertaing an element at the end of the arry takes constant time 0(1) if there is space available. But if the array is full and needs resizing, this operation has a 0(n) complexity.

You should use dynamic arrays when you don't know in advance the number of values that you'll need to store in the array. 

Python's built in data structure, list, works as a dynamic array.

# How Do Stacks and Queues Work?

## Stacks
A stack is  last-in, First-out (LIFO) datastructure

This means the last element that was added to the stack is the first one to be removed.

 Stacks have two ends, known as the top and the bottom.

Elements are added and removed from the top of the stack.

Adding an element to a stack is known as a push operation. We say that we push an element onto the stack when we add it on the top of the stack. Removing an element from a stack is known as a pop operation. We say that we pop an element from the stack when we remove it from the top of the stack.

The time complexity of push and pop operations is typically 0(1), a constant time complexity. The space complexity of the push and pop operations is usually constant 0(1). This means the amount of memory required to perform these operations remains constant regardless of the size of the stack.

## Queues
A queue is a first in first out (FIFO) linear data structure. This means the first element added is the first one to be removed.

Queues have two ends, the front and the back. Elements are added to the back of the queue and they are removed from the front of the queue.

Adding an element to the back of a queue is known as an  "enqueue" operation. In an enqueue operation, the new element is added to the end of the queue, becoming the end of the line.

Removing an element from the front of the queue is known as a "dequeue" operation.

In the dequeue operation, the element at thef ront of the queue is removed, and the next in line becomes the front.

The time complexity for enqueue and dequeue operations is 0(1), constant time. The space complexity for both is also 0(1). This means the amount of time and memory required to perform these operations remain constant regardless of the size of the queue.
