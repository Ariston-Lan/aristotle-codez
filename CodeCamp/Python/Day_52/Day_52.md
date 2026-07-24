# How Do Singly Linked Lists Work and How Do They Differ From Doubly Linked List?

## Linked List
A linked list is a linear data structure in which each node is connected to the next node in a sequence. These connections create a data structure htat looks like a chain of nodes, where each node stores data and a reference to the next node in the linked lis.

We use these references to go from the first node to the next and so on.

Linked lists are commonly used for implementing other data structures, such as stackes, queues, and deques. They can also be used to implemenet essential graph algorithms, such as depth-first search and breadth-first search.

### Singly Linked Lists
A singly linked list is a type of linked list in which each node is connected to the next node in the sequence. Each node is connected to the next one by storing a reference to it. This single reference per node allows you to traverse the linked list in one direction, from start to end.

The serach can ONLY move foward, not backwards. T

The head node is the first node in the linked list (Lets refer to thise node as Node A, and the following node, Node B, and so on.)

The process will start with Node A, then it will continue to node B, then node C, and finally node D, the tail node. It amy also stop before that if you implement specific logic in your code. 

The tail node is the last node, its used to determine when the process has reached the end of the linked list.

#### Inserting Nodes
One of the great things about linked lists is that they do not have a fixed size. They can be expanded or shrunk as needed by simply updating the connections between the nodes. 

You can insert a node at the start, middle, and end of a linked list. 

Linked lists don't really need to store the nodes in a specific order. THe order will be determines by the connections between the nodes.

However, if you do need to keep the nodes in a specific order for particular use cases, you can do so by implementing that logic in your code and the criteria you implement will determine if the node is inserted at the start, middle, or end.

To insert a node at the start of the linked list, you just need to create a connection between the new node and the node that USED to be the head node. If our new node is Node E, then we would insert node E at the start and make this new node the head node of the linked list.
- Inserting a node at the beginning of the linked list has a constant time complexity of 0(1) because it only requires updating the reference to the head node and the connection between the new head node and the next node in the sequence. 

To insert a node at the END of a linked list, first you need to reach the end and then add a connection to the new node, making it the new tail node. 
- This operation has a linear time complexity 0(n), as it grows with the number of nodes stored in the linked list.

If the node has to be inserted somewher ein the middle of the linked list, the connections between the nodes will have to be updated too. The previous node in the sequence should be connected to the new node and the new node should be connected to hte next node. 
- The insertion operation has a constant space complexity 0(1), since inserting a new node only requires creating it and updating the connections between the nodes. This operation dosen't depend on the size of the linked list itself.

#### Removing Nodes
Just as you can insert nodes, you can also remove them from the start, middle, and end of the linked list.

To remove a node from the start, you need to update the reference to the head node, which should be the next node in the sequence. 
- This operation has constant time complexity 0(1), because it only requires updating the linked list's reference to the head node.

To remove a node from the middle of the linked list, you need to update the reference to the previous node to connect it to the next node in the sequence.

To remove a node from the end of the linked list, you need to remove the connection of the previous node and make this node the new tail node. Now the linked list will end at the new tail mode.
- This operation has a linear time complexity 0(n) bc you have to reach the end of the list

### Doubly Linked Lists
In a doubly linked list, each node stores 2 references: a reference to the next node and a reference to the previous node in the sequence.

In this type of linked list, it's also common to keep a reference to the tail node in the linked list itself to start the traversal from the end if necessary.

This means they are more flexible than singly linked lists, however, they require more memory, since each node stores two references instead of one.

The insertion and deletion operations work exactly the same however, the only difference is you will need to update two references per node and keep track of the reference to the tail node to insert elements at the end of the doubly linked list very efficiently and start the traversal process from the back, if necessary.

# How Do Maps, Hash Maps and Sets Work?

## Abstract Data Types
An Abstract Data Type (ADT) is a conceptual representation of a data type, including what operations can be performed on the data and the properties of that data. 

Abstract Data Types are like blueprints that describe WHAT operations can be performed, not HOW they are performed. They seperate interface from implementation.

### Maps
A map is an ADT that mangaes a collection of key-value pairs and their operations in a very specific and efficient way (cough cough DICTIONARIES)

One of the key characteristic of maps is that every key MUST be unique. This uniqueness allows for direct lookups, which makes the process of retrieving information much more efficient. Only keys must be unique, values can be repeated.

The map ADT also defines important operations, such as inserting key-value pairs, getting the value associated with a key, updating the value, removing a key-value pair, and checking if a key exists in the map.

#### Hash map
A has map also known as a has table is a concrete implementation of the map Abstract Data Type

Has maps use a technique called "hashing" to perform common operations very efficiently.

Hashing essentially works by generating a has value for each element using a has function.

The has value is generated based on the key of the key-value pair and its used to calcuate an index in an underlying array, the actual data structure is where the key-value pairs are stored.

If two keys result in the same index due to his, has map has several collision strategies.
- Chaining, which is where each array index points to a linked list (another data structure), where all elements with the same index are stored.

- Open addressing, which involves searching the next available index in the array bast on a predefined search sequence

- Other ones prolly idek

The average case time complexity of hash maps is contasnt time 0(1) for inserting, retrieving, and deleting key-value pairs.

The worst case time complexity of hash maps is Linear time 0(n) for inserting, retrieving and deleting key-value pairs.

The space complexity of inserting into a has map is constant 0(1) on the average case, however in the worst case it can have linear space complexity 0(n).

This turns the hash table into something similar to a linear data structure where n elements have to be scanned to find the target key. However, this is relatively rare if the has map is implemented properly. 

##### Dictionaries
Python's dictionaries are implemented as hash maps behind the scenes. I am not gonna write how to make them and what you can do with them because I already know but just to be brief you can add keys assign keys different values, check if a key is in a dictionary and remove key value pairs. You can also call methods to see all the keys, values, or key-value pairs.

### Sets
Sets are unordered collections of unique elements. 
- Sets are unordered. The elemnts are never stored in a specific order, so you cannot access them through indices.
- Sets only contain unique elements. If you try to add the same value twice, only one copy of the value will be kept.

One of the main advantages of sets is that they guarantee that the elements will be unique (no duplicates). This is why they are often used to remove duplicates from lists and other data structures.

They are also dynamic. So they can adjust to the number of elements that are currently stored. 

The average case of time complexity of adding, removing, getting the length of set, and checking if an element is in the set is Constant time 0(1), which is very efficient.

Since sets are implemeneted as hash tables, the worst case time complexity of adding, removing, checking membership is Linear time 0(n). This may occur when there are multiple has collisions, transforming the has table into a linear data structure essentially.

In terms of space complexity, the average case of inserting an element is 0(1), with a new unique element requiring a constant amount of memory. The worst case could be linear space complexity 0(1).

- Python has a built in data structure, sets. I wont list everything they do but yea. 