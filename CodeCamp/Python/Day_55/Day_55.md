# What Is Binary Search and How Does It Differ From Linear Search?

## Linear Search
Searching through a list of items is a common occurence in computer science. There are two key algorithms you should know about when it comes to searching: linear search and binary search

Linear search starts at the beginning of a list and iterates through each item until it finds the target value it is looking for. 

If the target value is found, where it's located in the list is returned. If the target value is not found, -1 is returned. We return -1 because it's not a valid index in most programming languages.

A basic example is a for loop:
```python
def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1
```
While this is a relatively straightfoward algorithm, it is not the most efficient. If you have a large number of tiems, linear search can take a long time to find the target value. 

Due to this, the time complexity of a linear search is 0(n) beause the time it takes to search through the list grows linearly with the size of the list. The space complexity of linear search is 0(1) however, because it does not require any additional space to search through the list.

## Binary Search
Binary search is a more efficient algorithm for searching through a large list of items. The condition here is that the list must be sorted in ascending order.

Binary search works by dividing the list in half and checking if the target value is in the middle of the list. If the target value is in the middle of the list, the index of the target value is returned. Otherwise, the algorithm checks if the target value is in the left or right half of the last.

It continues to divide the remaining parts of the list into halves until the target value is found. if the target value is not in the list, it returns -1

Here is an example:
```python
def binary_search(arr, target):
    low = 0
    high = len(arr) -1

    while low <= high:
        mid = (low + high) // 2

        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    
    return -1
```

We start by identifying a low and high index. This represents the range of the list we are searching through.

We can check the condition of low being less than or equal to high. If low is greater than high, we have serached through the entire list and the target is not found.

If the low index is less than or equal to high, we calculate the middle index of the list, mid. We then check if the target value is at the middle index. If it is, we return the middle index.

Otherwise, we check if the value at the midpoint is less than the target. It if it is less than the target, it means that the target value is higher up. So the new low (minimum), should be one above the current midpoint. 

But if the midpoint value is more than the target, it means that the target is farther down the list, and in that case we should set maximum to one before that midpoint.

Then we repeat this process until we find the target or determine that the target is not in the list.

# What Is Divide and Conquer, and How Does Merge Sort Work?

## Divide and Conquer
The Divide and Conquer paradigm in computer science is a technique for recursively breaking down problems into smaller sub-probelms. One of the key aspects of this technique is recursion, which happens when a functionc alls itself repeatedly until a base case is reached. In this lesson, we will have a look at the merge sort algorithm to better understand how the divide and conquer technique works.

Let's say we had this list of numbers:

- 42 37 53 17

The goal is to sort that list from smallest to largets using the merge sort algorithm. The first step is to divide that list in half:

- 42 37 | 53 17

Then we need to look at the left side of the list:

- 42 37

We take that sub list and divide it in half again until each sublist has only one item in it:

- 42 | 37

A list with only one item in it is stored by default. Next we need to merge each one of those one element sub lists into a sorted list:

- 37 42

Then we follow the same process for the right side of the original list

- 17 53

Now that both halves of the original list are sorted, we merge those two halves together and sort the elements.

- 17 37 42 53

Here is what the algorithm looks like in code:
```python
def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])

    sorted_list = []
    i = 0
    j = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            sorted_list.append(left[i])
            i +=1
        else:
            sorted_list.append(right[j])
            j += 1

    sorted_list.extend(left[i:])
    sorted_list.extend(right[j:])

    return sorted_list
```

The time complexity for merge sort would be 0(n log n) because the list is continously divided in half (log n) and then merged together (0(n)). Unlike other sorting algorithms like bubble sort, merge sort is not sorted in place and has a space complexity of 0(n)