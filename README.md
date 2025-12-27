# Data Structure & Algorithm

## Dynamic Memory Allocation (DMA) in C

This project demonstrates the implementation of **Dynamic Memory Allocation** in C using the standard library functions: `malloc()`, `calloc()`, `realloc()`, and `free()`.

---

### 📌 Overview

Dynamic Memory Allocation allows programs to request memory **at runtime**, rather than using fixed memory at compile-time. This is useful when the size of data structures (like arrays) is not known beforehand or may change during execution.

---

### 🎯 Key Functions

#### 1. `malloc()`
- **Purpose:** Allocates a specified number of bytes in memory.
- **Syntax:**  
  ```c
  ptr = (datatype*) malloc(size_in_bytes);
  ```
- **Behavior:**
    - Allocates uninitialized memory
    - Garbage values may be present
    - Returns `NULL` if memory allocation fails

#### 2. `calloc()`
- **Purpose:** Allocates memory for multiple elements and initializes all bytes to zero.
- **Syntax:**
```c
ptr = (datatype *)calloc(number_of_elements, sizeof(datatype));
```
- **Behavior:**
    - Allocates memory for an array
    - Initializes all elements to 0
    - Returns `NULL` if memory allocation fails

#### 3. `realloc()`
- **Purpose:** Resizes previously allocated memory.
- **Syntax:**
```c
ptr = (datatype *)realloc(ptr, new_size_in_bytes);
```
- **Behavior:**
    - Preserves existing data
    - May move memory to a new location
    - Newly allocated memory is not initialized
    - Returns NULL if reallocation fails

#### 4. `free()`
- **Purpose:** Releases dynamically allocated memory back to the system.
- **Syntax:**
```c
free(ptr);
```
- **Behavior:**
    - Frees memory allocated using malloc(), calloc(), or realloc()
    - Prevents memory leaks
    - Pointer should not be used after freeing

---

### 🎯 Advantages of Dynamic Memory Allocation
- Efficient use of memory
- Flexible data size management
- Supports dynamic data structures like linked lists and trees

---

### 🧾 Conclusion

Dynamic Memory Allocation provides flexibility and efficient memory management in C programs.
Proper usage of `malloc()`, `calloc()`, `realloc()`, and `free()` is essential to avoid memory leaks and runtime errors.

---

## Stack Implementation Using Array

### 📌 Overview

This section demonstrates the **implementation of a Stack using an Array** and explains the **basic stack operations**.  
A stack is a **linear data structure** that follows the **LIFO (Last In, First Out)** principle, meaning the last element inserted is the first one to be removed.

---

### 🎯 Objectives
- To understand the concept of a **stack data structure**
- To implement a stack using an **array**
- To perform common stack operations such as:
  - Push
  - Pop
  - Display
- To understand **stack overflow** and **stack underflow**

---

### 🧠 Stack Concepts

#### 🔹 Stack
A stack is a linear data structure where:
- Insertion and deletion occur only at **one end**, called the **top**
- It follows the **LIFO** rule

#### 🔹 Array-Based Stack
- Uses an array to store stack elements
- Has a fixed size defined at compile time
- Efficient for simple stack operations

---

### ⁉️ Why Use struct for Stack?
- Groups stack data (array and top) into a single unit
- Improves readability and organization
- Allows creation of multiple stack objects
- Represents stack as an Abstract Data Type (ADT)

---

### ⁉️ Why Use typedef?
- Simplifies structure usage
- Avoids repeated use of struct keyword
- Makes code cleaner and more readable

---

### ⁉️ Why Use Pointer in Stack Functions?

- Stack operations modify the original stack, so functions receive the stack using a pointer.
- Example:
```c
void push(Stack *s);
```
- Prevents creation of copies
- Ensures real-time updates to top and stack data

---

### 📝 Explanation of Important Syntax
1. `push(&s)`
    - Passes the address of stack
    - Required because function expects a pointer

2. `Stack *s`
    - Receives address of stack
    - Allows direct modification of stack data

3. `s->top`
    - Used to access structure members via pointer
    - Equivalent to (*s).top

---

### 🤓 Stack Display Logic
- Only elements from index 0 to top are valid.
- Correct display loop:
```c
for (i = s->top; i >= 0; i--) {
    printf("%d ", s->stack[i]);
}
```
- ❌ Looping till MAX may display garbage values

---

### 🔧 Stack Operations

#### 1️⃣ Push Operation
- Adds an element to the **top of the stack**
- Before pushing, it checks for **stack overflow**
- Overflow occurs when `top == size - 1`

**Condition Checked:**
If stack is full → Overflow
Else → Increment top and insert element

---

### 2️⃣ Pop Operation
- Removes the **topmost element** from the stack
- Before popping, it checks for **stack underflow**
- Underflow occurs when `top == -1`

**Condition Checked:**
If stack is empty → Underflow
Else → Remove element and decrement top

---

### 3️⃣ Peek Operation
- Displays the **top element** of the stack without removing it
- Useful to check the current element at the top

---

### 4️⃣ Display Operation
- Displays all elements of the stack
- Elements are shown from **top to bottom**
- Helps visualize the stack structure

---

## ⚠️ Stack Conditions

### 🚫 Stack Overflow
Occurs when trying to push an element into a **full stack**.

### 🚫 Stack Underflow
Occurs when trying to pop an element from an **empty stack**.

---

## 🏗️ Program Flow
1. Initialize stack and set `top = -1`
2. Display a menu for stack operations
3. Perform operation based on user choice
4. Repeat until the user exits

---

## 📚 Applications of Stack
- Function calls and recursion
- Expression evaluation
- Undo/Redo operations
- Backtracking algorithms
- Reversing data

---

## 🧾 Conclusion
This program helps in understanding how a **stack works internally using an array**. It clearly demonstrates stack operations and highlights important conditions like **overflow and underflow**, making it a good foundation for learning data structures.
Actual code implementation can be done using any programming language such as **C, C++, or Java**.

---


