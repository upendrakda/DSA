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

### 🧠 Algorithm: Dynamic Memory Allocation Using malloc() and calloc()

1. Start
2. Display menu
    - 1. Using malloc()
    - 2. Using calloc()
    - 3. Exit
3. Read the user’s choice
4. If choice = 1, execute using_malloc()
    - Else if choice = 2, execute using_calloc()
    - Else if choice = 3, terminate the program
    - Else display “Invalid Input”

    #### Algorithm: using_malloc()
    1. Read the total number of elements n
    2. Allocate memory
        - Allocate memory for n integers using malloc()
    3. Read elements
        - Read n integer elements and store them in allocated memory
    4. Ask user for reallocation
        - Read user choice (y or n)
    5. If reallocation is required
        - Read new size new
        - Reallocate memory using realloc()
    6. If new size > old size
        - Read remaining elements from index n to new - 1
    7. Update size
        - Set n = new
    8. Display all elements
    9. Free allocated memory
        - Deallocate memory using free()
    10. Return to main menu

        #### Algorithm: using_calloc()
    1. Read the total number of elements n
    2. Allocate memory
        - Allocate memory for n integers using calloc()
    3. Read elements
        - Read n integer elements and store them in allocated memory
    4. Ask user for reallocation
        - Read user choice (y or n)
    5. If reallocation is required
        - Read new size new
        - Reallocate memory using realloc()
    6. If new size > old size
        - Read remaining elements from index n to new - 1
    7. Update size
        - Set n = new
    8. Display all elements
    9. Free allocated memory
        - Deallocate memory using free()
    10. Stop

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

#### 2️⃣ Pop Operation
- Removes the **topmost element** from the stack
- Before popping, it checks for **stack underflow**
- Underflow occurs when `top == -1`

**Condition Checked:**
If stack is empty → Underflow
Else → Remove element and decrement top

---

#### 3️⃣ Peek Operation
- Displays the **top element** of the stack without removing it
- Useful to check the current element at the top

---

#### 4️⃣ Display Operation
- Displays all elements of the stack
- Elements are shown from **top to bottom**
- Helps visualize the stack structure

---

### 🧠 Algorithm: Array Implementation of Stack

1. Start
2. Define stack
    - Declare an array stack[MAX]
    - Initialize top = -1
3. Display menu
    - 1. push()
    - 2. pop()
    - 3. display()
    - 4. exit()
4. Read user choice
5. If choice = 1, perform push()
    - Else if choice = 2, perform pop()
    - Else if choice = 3, perform display()
    - Else if choice = 4, terminate the program
    - Else display “Invalid input”
6. Repeat steps 3 to 5 until choice = 4
7. Stop

    #### Algorithm: push() Operation
    1. Check stack overflow
       - If top == MAX − 1, display “Stack is Full” and return
    2. Read element
       - Input the element to be pushed
    3. Insert element
       - Increment top
       - Store element at stack[top]
    4. Return to main menu

    #### Algorithm: pop() Operation
    1. Check stack underflow
       - If top == −1, display “Stack is Empty” and return
    2. Remove element
       - Store stack[top] in a variable
       - Decrement top
    3. Display popped element
    4. Return to main menu

    #### Algorithm: display() Operation

    1. Check if stack is empty
       - If top == −1, display “Stack is Empty” and return
    2. Display stack elements
       - Print elements from index 0 to top
    3. Return to main menu

---

### ⚠️ Stack Conditions

#### 🚫 Stack Overflow
Occurs when trying to push an element into a **full stack**.

#### 🚫 Stack Underflow
Occurs when trying to pop an element from an **empty stack**.

---

### 🏗️ Program Flow
1. Initialize stack and set `top = -1`
2. Display a menu for stack operations
3. Perform operation based on user choice
4. Repeat until the user exits

---

### 📚 Applications of Stack
- Function calls and recursion
- Expression evaluation
- Undo/Redo operations
- Backtracking algorithms
- Reversing data

---

### 🧾 Conclusion
This program helps in understanding how a **stack works internally using an array**. It clearly demonstrates stack operations and highlights important conditions like **overflow and underflow**, making it a good foundation for learning data structures.
Actual code implementation can be done using any programming language such as **C, C++, or Java**.

---

## 🔁 Infix to Postfix Expression Conversion

### 📌 Overview

- **Infix Expression**  
  Operators are written **between operands** 
  A + B

- **Postfix Expression (Reverse Polish Notation)**  
    Operators are written **after operands**  
    AB+

👉 Postfix expressions **do not require parentheses** and are easier to evaluate using stacks.

---

### 🎯 Objective

- Convert a given **infix expression** into its **postfix equivalent**
- Implement the solution using:
    - Stack (array implementation)
    - Operator precedence rules
    - Parenthesis handling

---

### 🧮 Operator Precedence

| Operator | Precedence |
|--------|------------|
| `^`    | Highest |
| `* /`  | Medium |
| `+ -`  | Lowest |

---

### 🔑 Algorithm(General)

1. Initialize an empty stack for operators
2. Scan the infix expression from **left to right**
3. If the scanned character is:
 - **Operand** → add it to postfix expression
 - **`(`** → push onto stack
 - **`)`** → pop from stack until `(` is found
 - **Operator** →  
   - Pop operators from stack with **higher or equal precedence**
   - Push the current operator
4. After scanning the expression, pop all remaining operators from the stack
5. The resulting string is the **postfix expression**

---

### 🧠 Algorithm: Infix to Postfix Conversion Using Stack

1. Start
2. Declare stack
    - Define a character stack with array data[MAX]
    - Initialize top = -1
3. Read infix expression
    - Input the infix expression as a string
4. Initialize postfix index
    - Set j = 0 for postfix expression
5. Scan infix expression from left to right
    - Repeat for each character ch in the infix expression
6. If character is an operand
    - Append ch to postfix expression
    - Increment j
7. If character is ‘(’
    - Push ch onto the stack
8. If character is ‘)’
    - Pop operators from stack and append to postfix until ‘(’ is found
    - Pop and discard ‘(’ from stack
9. If character is an operator
    - While stack is not empty and precedence of stack top ≥ precedence of current operator
        - Pop operator from stack and append to postfix
    - Push current operator onto the stack
10. Repeat steps 6 to 9 until end of infix expression
11. Pop remaining operators
    - While stack is not empty
      - Pop operator and append to postfix
12. Terminate postfix expression
    - Append null character '\0'
13. Display postfix expression
14. Stop

---

### 📌 Example

#### Input
A+B*(C-D)

#### Output
ABCD-*+

---

### 🧪 Sample Dry Run

| Symbol | Stack | Postfix |
|------|-------|---------|
| A | — | A |
| + | + | A |
| B | + | AB |
| * | + * | AB |
| ( | + * ( | AB |
| C | + * ( | ABC |
| - | + * ( - | ABC |
| D | + * ( - | ABCD |
| ) | + * | ABCD- |
| End | — | ABCD-*+ |

---

### 🧠 Applications

- Compiler design
- Expression evaluation
- Syntax parsing
- Calculator programs

---

### ✅ Conclusion

This project clearly demonstrates how **stacks simplify expression conversion** and highlights their importance in real-world applications like compilers and interpreters.

---

## 🔁 Infix to Prefix Expression Conversion

### 📌 Overview

- **Infix Expression**  
  Operators are written **between operands**  
    A + B

- **Prefix Expression (Polish Notation)**  
    Operators are written **before operands**  
    +AB

👉 Prefix expressions **do not require parentheses** and are easier to evaluate using stacks.

---

### 🎯 Objective

- Convert a given **infix expression** into its **prefix equivalent**
- Implement the solution using:
    - Stack (array implementation)
    - Operator precedence rules
    - Parenthesis handling
    - Reverse technique

---

### 🧮 Operator Precedence

| Operator | Precedence |
|--------|------------|
| `^`    | Highest |
| `* /`  | Medium |
| `+ -`  | Lowest |

---

### 🔑 Algorithm (Reverse–Postfix Method) (General)

1. Reverse the given infix expression
2. Replace:
 - `(` with `)`
 - `)` with `(`
3. Convert the modified expression to **postfix** using stack rules
4. Reverse the postfix expression to obtain the **prefix expression**

---

### 🧠 Algorithm: Infix to Prefix Conversion Using Stack

1. Start
2. Declare stack
    - Define a character stack with array data[MAX]
    - Initialize top = -1
3. Read infix expression
    - Input the infix expression as a string
4. Reverse the infix expression
5. Replace parentheses
    - Replace every '(' with ')'
    - Replace every ')' with '('
6. Initialize prefix index
    - Set j = 0
7. Scan the modified infix expression from left to right
8. If character is an operand
    - Append the character to prefix array
    - Increment j
9. If character is ‘(’
    - Push it onto the stack
10. If character is ‘)’
    - Pop operators from stack and append to prefix until ‘(’ is found
    - Pop and discard ‘(’ from stack
11. If character is an operator
    - While stack is not empty and precedence of stack top > precedence of current operator
        - Pop operator from stack and append to prefix
    - Push current operator onto the stack
12. Repeat steps 8 to 11 until end of expression
13. Pop remaining operators
    - Pop all remaining operators from stack and append to prefix
14. Terminate string
    - Append null character '\0'
15. Reverse the obtained expression
    - Reverse the postfix expression to get prefix expression
16. Display prefix expression
17. Stop

---

### 📌 Example

#### Input
A+B*(C-D)

#### Output
A * B - C D

(Without spaces: `+A*B-CD`)

---

### 🧪 Sample Dry Run

#### Step 1: Reverse Infix
)D-C(*B+A

#### Step 2: Replace Brackets
(D-C)*B+A

#### Step 3: Postfix Conversion
DC-*B+A+

#### Step 4: Reverse Postfix (Prefix Result)
+A*B-CD

---

### 🧠 Applications

- Compiler design
- Expression evaluation
- Syntax parsing
- Calculator programs

---

### ✅ Conclusion

This project highlights how **infix expressions can be efficiently converted to prefix form** using stacks and string manipulation, making it a key concept in data structures and compiler design.

---

## Postfix Expression Evaluation

### 📌 Objective

The objective of this program is to evaluate a postfix (Reverse Polish) expression using the stack data structure. The program demonstrates how stacks are effectively used to process expressions where operators follow operands, eliminating the need for parentheses and operator precedence rules.

---

### 📌 Introduction

In computer science, expressions can be represented in three forms:
- Infix (e.g., A + B)
- Prefix (e.g., + A B)
- Postfix (e.g., A B +)

Postfix expressions are especially useful for computation because they can be evaluated from left to right using a stack, making them simple and efficient for machines to process.

---

### 🧠 Core Concepts

1️⃣ Stack Data Structure
- A stack is a linear data structure that follows the LIFO (Last In, First Out) principle.
- Basic stack operations include:
    - Push: Insert an element onto the stack
    - Pop: Remove the top element from the stack
- Stacks are ideal for postfix evaluation because operands can be stored temporarily until an operator is encountered.

2️⃣ Postfix Expression
- A postfix expression places operators after their operands.
- Example:
    - Infix: 3 + 4
    - Postfix: 34+
- Characteristics:
    - No parentheses required
    - No need to consider operator precedence
    - Evaluated strictly from left to right

3️⃣ Operand and Operator Handling
- Operands (numbers) are pushed onto the stack.
- Operators trigger the removal (pop) of the top two operands from the stack.
- The operation is performed and the result is pushed back onto the stack.

---

### 🧠 Working Principle
- Initialize an empty stack.
- Scan the postfix expression from left to right.
- If the scanned symbol is an operand, push it onto the stack.
- If the scanned symbol is an operator:
    - Pop the top two operands from the stack.
    - Apply the operator to these operands.
    - Push the result back onto the stack.
- After the entire expression is processed, the stack contains a single value.
- This value is the final result of the postfix expression.

---

### 🧠 Algorithm: Evaluation of Postfix Expression Using Stack

1. Start
2. Declare stack
    - Define an integer stack with array data[MAX]
    -Initialize top = -1
3. Read postfix expression
    - Input the postfix expression as a string
4. Scan postfix expression from left to right
5. If character is an operand
    - Convert character to integer
    - Push the value onto the stack
6. If character is an operator
    - Pop the top element as op2
    - Pop the next element as op1
    - Perform the operation op1 operator op2
    - Push the result onto the stack
7. Repeat steps 5 and 6 until end of expression
8. Pop final result
    - Pop the remaining value from the stack
9. Display the result
10. Stop

---

### 🎯 Applications
- Expression evaluation in compilers
- Calculator implementations
- Parsing arithmetic expressions
- Stack-based virtual machines

---

### 🎯 Advantages
- Simple and efficient evaluation
- No need for parentheses or precedence rules
- Suitable for stack-based computation
- Faster evaluation compared to infix expressions

---

### 🧾 Conclusion

Postfix expression evaluation is a classic application of the stack data structure. By using LIFO principles, complex arithmetic expressions can be evaluated efficiently and systematically. This approach is widely used in compilers and interpreters, making it an important concept in data structures and algorithms.

---

## Prefix Expression Evaluation

### 📌 Objective

The objective of this program is to evaluate a prefix (Polish) expression using the stack data structure. The program highlights how prefix expressions can be efficiently evaluated by reversing the expression and applying stack-based computation.

---

### ✨ Introduction

Arithmetic expressions can be written in three notations:
- Infix → A + B
- Prefix → + A B
- Postfix → A B +
In prefix notation, the operator appears before its operands. This notation is widely used in expression parsing because it eliminates the need for parentheses and operator precedence rules, making evaluation straightforward for machines.

---

### 🧠 Core Concepts
1️⃣ Stack Data Structure
- A stack is a linear data structure that follows the LIFO (Last In, First Out) principle.
- Key operations:
    - Push – Insert an element into the stack
    - Pop – Remove the top element from the stack
- Stacks play a crucial role in expression evaluation by temporarily storing operands until operators are applied.

2️⃣ Prefix Expression
- In a prefix expression:
    - Operators come before operands
    - Evaluation is naturally performed from right to left
- Example:
    - Infix: 3 + 4
    - Prefix: +34

3️⃣ Reversal Technique
- Direct evaluation of prefix expressions is complex when scanning from left to right.
- To simplify:
    - The prefix expression is reversed
    - The reversed expression is then evaluated similarly to a postfix expression
- This approach allows efficient processing using a stack.

---

### ⚙️ Working Principle
- Read the prefix expression.
- Reverse the given expression.
- Initialize an empty stack.
- Scan the reversed expression from left to right.
- If the symbol is an operand, push it onto the stack.
- If the symbol is an operator:
    - Pop two operands from the stack.
    - Apply the operator in correct order.
    - Push the result back onto the stack.
- After complete evaluation, the stack contains a single value.
- This value represents the final result of the prefix expression.

---

### 🧠 Algorithm: Evaluation of Prefix Expression Using Stack

1. Start
2. Declare stack
    - Define an integer stack with array data[MAX]
    - Initialize top = -1
3. Read prefix expression
    - Input the prefix expression as a string
4. Reverse the prefix expression
5. Scan the reversed expression from left to right
6. If character is an operand
    - Convert character to integer
    - Push the value onto the stack
7. If character is an operator
    - Pop the top element as op1
    - Pop the next element as op2
    - Perform the operation op2 operator op1
    - Push the result onto the stack
8. Repeat steps 6 and 7 until end of expression
9. Pop final result
    - Pop the remaining value from the stack
10. Display the result
11. Stop

---

### 🚀 Applications
- Compiler design and expression parsing
- Calculator implementations
- Stack-based interpreters
- Symbolic computation systems

---

### 🏁 Conclusion

Prefix expression evaluation is a powerful application of stacks in data structures. By reversing the prefix expression and using stack operations, complex expressions can be evaluated efficiently. This method is widely used in compilers and expression evaluators, making it a fundamental concept in computer science.

---

## Linear Queue Implementation Using Array

### 🎯 Objective

The objective of this program is to implement a Linear Queue using an array and demonstrate its fundamental operations such as enqueue, dequeue, and display. The program helps in understanding how queues work internally using array-based storage.

---

### 📘 Introduction

A queue is a linear data structure that follows the FIFO (First In, First Out) principle.
This means the element inserted first is removed first.

In a linear queue, elements are inserted from one end called the rear and deleted from the other end called the front. This implementation uses a fixed-size array to store queue elements.

---

### 🧠 Core Concepts
1️⃣ Queue Data Structure
- A queue maintains two important pointers:
    - Front – points to the first element
    - Rear – points to the last element
- Operations are performed based on these pointers.

2️⃣ FIFO Principle
- FIFO stands for First In, First Out:
    - The first element added to the queue will be the first one removed
    - This principle is commonly used in real-life scenarios like ticket counters and scheduling systems

3️⃣ Array Implementation
- In array-based queues:
    - Memory size is fixed
    - Elements are stored in contiguous memory locations
    - Queue overflow occurs when the array is full
    - Queue underflow occurs when the queue is empty

---

### ⚙️ Queue Operations
#### 🔹 Enqueue (Insertion)
- Adds an element at the rear end of the queue
- Checks for queue overflow
- Updates the rear pointer after insertion

#### 🔹 Dequeue (Deletion)
- Removes an element from the front end of the queue
- Checks for queue underflow
- Updates the front pointer after deletion
- Resets front and rear when the queue becomes empty

#### 🔹 Display
- Displays all elements present in the queue
- Traverses from front to rear
- Shows queue contents in FIFO order

---

### 🚀 Working Principle
- Initialize the queue with front and rear set to -1.
- Perform enqueue operation to insert elements at the rear.
- Perform dequeue operation to remove elements from the front.
- Display operation shows current elements of the queue.
- The program continues until the user chooses to exit.

---

### 🧠 Algorithm: Array Implementation of Linear Queue

1. Start
2. Declare queue
    - Define an integer array queue[MAX]
    - Initialize front = -1 and rear = -1
3. Display menu
    - 1. enqueue()
    - 2. dequeue()
    - 3. display()
    - 4. exit()
4. Read user choice
5. If choice = 1, perform enqueue()
    - Else if choice = 2, perform dequeue()
    - Else if choice = 3, perform display()
    - Else if choice = 4, terminate the program
    - Else display “Invalid choice”
6. Repeat steps 3 to 5 until choice = 4
7. Stop

    #### Algorithm: enqueue() Operation
    1. Check queue overflow
        - If rear == MAX − 1, display “Queue is Full” and return
    2. Check first insertion
        - If front == −1, set front = 0
    3. Insert element
        - Increment rear
        - Read the element
        - Store it at queue[rear]
    4. Return to main menu

    #### Algorithm: dequeue() Operation
    1. Check queue underflow
        - If front == −1 or front > rear, display “Queue is Empty” and return
    2. Delete element
        - Display element at queue[front]
        - Increment front
    3. Reset queue
        - If front > rear, set front = −1 and rear = −1
    4. Return to main menu

    #### Algorithm: display() Operation
    1. Check if queue is empty
        - If front == −1, display “Queue is Empty” and return
    2. Display elements
        - Print elements from index front to rear
    3. Return to main menu

---
### 📌 Applications
- CPU scheduling
- Print spooling
- Process management
- Data buffering
- Breadth First Search (BFS)

---

### 🏁 Conclusion

The array implementation of a linear queue provides a clear understanding of queue fundamentals and FIFO behavior. Although simple and efficient for small datasets, it suffers from memory limitations. This implementation serves as a foundational concept for advanced queue structures like circular queues, dequeues, and priority queues.

---

## Circular Queue Implementation Using Array

### 🎯 Objective
The objective of this program is to implement a Circular Queue using an array and demonstrate its fundamental operations such as enqueue, dequeue, and display.
This program helps in understanding how circular queues overcome the memory limitation problem of linear queues.

---

### 📘 Introduction
A circular queue is a linear data structure that follows the FIFO (First In, First Out) principle.

Unlike a linear queue, a circular queue connects the last position of the array back to the first position, forming a circle. This allows better utilization of memory by reusing empty spaces created after deletion.

In this implementation, a fixed-size array is used along with two pointers:
- Front – points to the first element
- Rear – points to the last element

---

### 🧠 Core Concepts
1️⃣ Circular Queue Structure
- Uses an array of fixed size
- Maintains two pointers: front and rear
- Uses modulo operation % MAX for circular movement

2️⃣ FIFO Principle
- The element inserted first will be removed first
- Insertion happens at rear
- Deletion happens at front

3️⃣ Circular Behavior
- When rear reaches the last index, it moves to index 0
- Overflow condition:
```c
(rear + 1) % MAX == front
```
- Underflow condition:
```c
front == -1
```
---

### ⚙️ Circular Queue Operations
🔹 Enqueue (Insertion)
- Adds an element at the rear
- Checks for queue overflow
- Updates rear using modulo operation

🔹 Dequeue (Deletion)
- Removes an element from the front
- Checks for queue underflow
- Updates front using modulo operation
- Resets front and rear if queue becomes empty

🔹 Display
- Displays all elements in circular order
- Traverses from front to rear using modulo operation

---

### 🚀 Working Principle
- Initialize front and rear to -1
- Perform enqueue to insert elements at rear
- Perform dequeue to remove elements from front
- Display shows elements in circular order
- Continue until user selects exit

---

### 🧠 Algorithm: Array Implementation of Circular Queue
1. Start
2. Declare circular queue
    - Define integer array queue[MAX]
    - Initialize front = -1 and rear = -1
3. Display menu
    1. enqueue()
    2. dequeue()
    3. display()
    4. exit()
4. Read user choice
5. If choice = 1, perform enqueue()
    - Else if choice = 2, perform dequeue()
    - Else if choice = 3, perform display()
    - Else if choice = 4, terminate program
    - Else display “Invalid choice”
6. Repeat steps 3 to 5 until choice = 4
7. Stop

    #### Algorithm: enqueue() Operation
    1. Check queue overflow
        - If (rear + 1) % MAX == front, display “Queue is Full” and return
    2. Check first insertion
        - If front == -1, set front = 0 and rear = 0
        - Else set rear = (rear + 1) % MAX
    3. Insert element
        - Read item
        - Store it at queue[rear]
    4. Return to main menu

    #### Algorithm: dequeue() Operation
    1. Check queue underflow
        - If front == -1, display “Queue is Empty” and return
    2. Delete element
        - Display queue[front]
    3. Check if only one element
        - If front == rear, set front = -1 and rear = -1
        - Else set front = (front + 1) % MAX
    4. Return to main menu

    #### Algorithm: display() Operation
    1. Check if queue is empty
        - If front == -1, display “Queue is Empty” and return
    2. Display elements
        - Set i = front
        - Print queue[i]
        - Repeat i = (i + 1) % MAX until i == rear
    3. Return to main menu

---

### 📌 Applications
- CPU scheduling
- Traffic management systems
- Memory buffering
- Streaming data handling
- Producer-consumer problems

---

### 🏁 Conclusion
The array implementation of a circular queue efficiently utilizes memory by allowing wrap-around movement of pointers. It eliminates the major drawback of linear queues where unused spaces cannot be reused. This concept forms the foundation for more advanced data structures and real-world queue management systems.

---

## Factorial of a Number Using Recursion

### 📘 Introduction
Factorial of a non-negative integer n is defined as:
𝑛!=𝑛×(𝑛−1)×(𝑛−2)×...×1

Special cases:
- 0! = 1
- 1! = 1

In this program, factorial is calculated using recursion, where a function calls itself repeatedly until a base condition is satisfied.

---

### 🧠 Core Concepts
1️⃣ Recursion
- A technique where a function calls itself
- Must have a base condition to stop recursion
- Each recursive call reduces the problem size

2️⃣ Base Condition
- If n == 0 or n == 1, return 1
- Prevents infinite recursion

3️⃣ Recursive Case
- factorial(n) = n × factorial(n − 1)
- Function keeps calling itself until it reaches base condition

---

### ⚙️ Working Principle
- Read a number from the user
- If the number is negative, factorial is not defined
- Otherwise, call recursive function
- Function keeps multiplying numbers until it reaches 1
- Display the final result

---

### 🧠 Algorithm: Factorial Using Recursion
1. Start
2. Declare recursive function factorial(n)
3. In main()
- Read number num
4. If num < 0
- Display “Factorial not defined for negative numbers”
5. Else
- Call factorial(num)
- Display result
6. Stop

    #### Algorithm: factorial(n) Function
    1. If n == 0 or n == 1
    - Return 1
    2. Else
    - Return n × factorial(n − 1)

---

### 📌 Applications
- Mathematical computations
- Permutations and combinations
- Probability calculations
- Algorithm analysis

---

### 🏁 Conclusion
Recursion provides a simple and elegant way to calculate factorial by breaking the problem into smaller subproblems. The base condition ensures termination, and each recursive call reduces the value of n until it reaches 1.

---

## Fibonacci Sequence Using Recursion

### 📘 Introduction
The Fibonacci sequence is a series of numbers where each number is the sum of the two preceding numbers.

The sequence starts as: 0,1,1,2,3,5,8,13,...

Mathematically:
- F(0) = 0
- F(1) = 1
- F(n) = F(n−1) + F(n−2)

In this program, Fibonacci numbers are generated using recursion, where the function calls itself to compute previous values.

---

### 🧠 Core Concepts
1️⃣ Recursion
- A function calls itself
- Problem is divided into smaller subproblems
- Requires base condition to stop recursion

2️⃣ Base Cases
- If n == 0, return 0
- If n == 1, return 1

3️⃣ Recursive Case
- fibonacci(n) = fibonacci(n−1) + fibonacci(n−2)
- Function keeps calling itself until it reaches base cases

---

### ⚙️ Working Principle
- Read number of terms from the user
- If input is less than or equal to 0, display error message
- Otherwise, use a loop to print Fibonacci numbers
- Each term is calculated using recursive function
- Display the complete Fibonacci sequence

---

### 🧠 Algorithm: Fibonacci Sequence Using Recursion
1. Start
2. Declare recursive function fibonacci(n)
3. In main()
- Read number of terms n
4. If n <= 0
- Display “Enter a positive number”
5. Else
- For i = 0 to n − 1
    - Print fibonacci(i)
6. Stop

    #### Algorithm: fibonacci(n) Function
    1. If n == 0
        - Return 0
    2. Else if n == 1
        - Return 1
    3. Else
        - Return fibonacci(n − 1) + fibonacci(n − 2)

---

### 📌 Applications
- Mathematical modeling
- Dynamic programming concepts
- Algorithm analysis
- Population growth modeling

---

### 🏁 Conclusion
Recursion provides a simple way to generate Fibonacci numbers by defining the problem in terms of smaller subproblems. Although easy to understand, recursive Fibonacci is less efficient for large inputs compared to iterative or dynamic programming approaches.

---

## GCD of Two Numbers Using Recursion

### 📘 Introduction
The Greatest Common Divisor (GCD) of two numbers is the largest positive integer that divides both numbers without leaving a remainder.

This program calculates GCD using the Euclidean Algorithm with recursion.

Mathematical rule: GCD(a,b)=GCD(b,amodb)

The process continues until the second number becomes zero.

---

### 🧠 Core Concepts
1️⃣ Euclidean Algorithm
- Based on the principle:
```mathematica
GCD(a, b) = GCD(b, a % b)
```
- If b = 0, then GCD = a

2️⃣ Recursion
- Function calls itself with smaller values
- Each call reduces the problem size

3️⃣ Base Condition
- If b == 0, return a
- Ensures termination of recursion

---

### ⚙️ Working Principle
- Read two numbers from the user
- Check if numbers are positive
- Call recursive gcd() function
- Function repeatedly replaces (a, b) with (b, a % b)
- When b becomes 0, return a
- Display the result

---

### 🧠 Algorithm: GCD Using Recursion
1. Start
2. Declare recursive function gcd(a, b)
3. In main()
- Read two integers num1 and num2
4. If num1 < 0 or num2 < 0
- Display “Enter positive integers only”
5. Else
- Call gcd(num1, num2)
- Display result
6. Stop

    #### Algorithm: gcd(a, b) Function
    1. If b == 0
        - Return a
    2. Else
        - Return gcd(b, a % b)

---

### 📌 Applications
- Simplifying fractions
- Cryptography (RSA algorithm)
- Number theory problems

---

### 🏁 Conclusion

The recursive Euclidean algorithm is an efficient method to compute the GCD of two numbers. It reduces the problem size at each step and terminates when the remainder becomes zero, providing a fast and elegant solution.

---

## Tower of Hanoi Using Recursion

### 📘 Introduction
The Tower of Hanoi is a classic recursive problem that involves moving disks from one rod to another following specific rules.

🔹 Rules:
1. Only one disk can be moved at a time.
2. A larger disk cannot be placed on a smaller disk.
3. Only the top disk of a rod can be moved.

The goal is to move all disks from the source rod to the destination rod using an auxiliary rod.

---

### 🧠 Core Concepts
1️⃣ Recursion
- The problem is solved by breaking it into smaller subproblems.
- To move n disks:
    - Move n−1 disks to auxiliary rod
    - Move the nth disk to destination
    - Move n−1 disks from auxiliary to destination

2️⃣ Base Condition
- If n == 1, move the disk directly from source to destination.

3️⃣ Recursive Strategy
- T(n) = 2T(n−1) + 1
- Minimum moves required = 2ⁿ − 1

---

### ⚙️ Working Principle
- Read number of disks from the user
- If number is less than or equal to zero, display error message
- Otherwise, call recursive function
- Function prints steps required to move all disks
- Each recursive call reduces the number of disks

---

### 🧠 Algorithm: Tower of Hanoi Using Recursion
1. Start
2. Declare recursive function towerOfHanoi(n, source, destination, auxiliary)
3. In main()
- Read number of disks n
4. If n <= 0
- Display “Number of disks must be positive”
5. Else
- Call towerOfHanoi(n, 'A', 'C', 'B')
6. Stop

    #### Algorithm: towerOfHanoi(n, source, destination, auxiliary)
    1. If n == 1
        - Print “Move disk 1 from source to destination”
        - Return
    2. Call towerOfHanoi(n − 1, source, auxiliary, destination)
    3. Print “Move disk n from source to destination”
    4. Call towerOfHanoi(n − 1, auxiliary, destination, source)
    5. Return

---

### 📌 Applications
- Understanding recursion concepts
- Algorithm design and analysis
- Problem-solving using divide-and-conquer
- Used in teaching stack and recursion behavior

---

### 🏁 Conclusion

The Tower of Hanoi problem is a classic example of recursion where a complex problem is solved by dividing it into smaller subproblems. The recursive approach provides a clear and elegant solution, demonstrating the power of divide-and-conquer techniques.

---

## Singly Linked List Implementation

### 📘 Introduction
A Singly Linked List is a linear data structure where each element (node) contains:
- Data – the value stored in the node
- Next pointer – address of the next node
Unlike arrays, linked lists use dynamic memory allocation and do not require contiguous memory locations.

In this program, different operations such as node creation, insertion, deletion, and display are implemented.

---

### 🧠 Core Concepts
1️⃣ Node Structure
- Each node contains:
    - data field
    - next pointer

2️⃣ Head Pointer
- Points to the first node of the list
- If head = NULL, the list is empty

3️⃣ Dynamic Memory Allocation
- Nodes are created using malloc()
- Memory is freed using free() after deletion

4️⃣ Traversal
- Accessing elements requires moving node by node using the next pointer

---

### ⚙️ Operations Performed
- Insert at Beginning
- Insert at End
- Insert at Specific Position
- Delete from Beginning
- Delete from End
- Delete from Specific Position
- Display List

---

### 🧠 Algorithm: Singly Linked List Implementation
1. Start
2. Define structure Node with fields data and next
3. Initialize head = NULL
4. Display menu
    1. Insert at Beginning
    2. Insert at End
    3. Insert at Position
    4. Delete at Beginning
    5. Delete at End
    6. Delete at Position
    7. Display
    8. Exit
5. Read user choice
6. Perform selected operation
7. Repeat steps 4 to 6 until choice = 8
8. Stop

    #### Algorithm: createNode(value)
    1. Allocate memory for new node
    2. Set newNode->data = value
    3. Set newNode->next = NULL
    4. Return new node

    #### Algorithm: Insert at Beginning
    1. Create new node
    2. Set newNode->next = head
    3. Set head = newNode
    4. Return

    #### Algorithm: Insert at End
    1. Create new node
    2. If head == NULL
        - Set head = newNode
        - Return
    3. Traverse list until last node
    4. Set last node’s next = newNode
    5. Return

    #### Algorithm: Insert at Position
    1. If position = 1
        - Call Insert at Beginning
    2. Traverse list up to position − 1
    3. If position invalid
        - Display error
    4. Set newNode->next = temp->next
    5. Set temp->next = newNode
    6. Return

    #### Algorithm: Delete at Beginning
    1. If head == NULL
        - Display “List is empty”
    2. Store head in temp
    3. Set head = head->next
    4. Free temp
    5. Return

    #### Algorithm: Delete at End
    1. If head == NULL
        - Display “List is empty”
    2. If only one node
        - Free head
        - Set head = NULL
    3. Traverse to last node
    4. Set second-last node’s next = NULL
    5. Free last node
    6. Return

    #### Algorithm: Delete at Position
    1. If head == NULL
        - Display “List is empty”
    2. If position = 1
        - Call Delete at Beginning
    3. Traverse to desired position
    4. If position invalid
        - Display error
    5. Set prev->next = temp->next
    6. Free temp
    7. Return

    #### Algorithm: Display
    1. If head == NULL
        - Display “List is empty”
    2. Set temp = head
    3. While temp != NULL
        - Print temp->data
        - Move temp = temp->next
    4. Print NULL
    5. Return

---

### 📌 Applications
- Dynamic memory management
- Implementing stacks and queues
- Polynomial representation
- Graph adjacency list
- Music playlist and browser history

---

### 🏁 Conclusion

The singly linked list provides flexible and dynamic storage compared to arrays. It allows efficient insertion and deletion operations without shifting elements. This implementation helps in understanding pointer manipulation and dynamic memory allocation concepts in data structures.

---

## Doubly Linked List Implementation

### 📘 Introduction
A Doubly Linked List (DLL) is a linear data structure where each node contains:
- Data – the value stored in the node
- Prev pointer – address of the previous node
- Next pointer – address of the next node
Unlike singly linked lists, DLL allows traversal in both directions. This makes insertion and deletion more flexible, especially at the end or in between nodes.

In this program, various operations such as node creation, insertion, deletion, and display are implemented.

---

### 🧠 Core Concepts
1️⃣ Node Structure
- Each node contains: data, prev, and next pointers

2️⃣ Head Pointer
- Points to the first node
- head = NULL indicates an empty list

3️⃣ Bidirectional Traversal
- Nodes can be traversed forward using next and backward using prev

4️⃣ Dynamic Memory Allocation
- Nodes are allocated using malloc()
- Memory is freed using free()

---

### ⚙️ Operations Performed
- Insert at Beginning
- Insert at End
- Insert at Specific Position
- Delete from Beginning
- Delete from End
- Delete from Specific Position
- Display List

---

### 🧠 Algorithm: Doubly Linked List Implementation
1. Start
2. Define structure Node with fields data, prev, and next
3. Initialize head = NULL
4. Display menu:
    1. Insert at Beginning
    2. Insert at End
    3. Insert at Position
    4. Delete at Beginning
    5. Delete at End
    6. Delete at Position
    7. Display
    8. Exit
5. Read user choice
6. Perform the selected operation
7. Repeat steps 4–6 until choice = 8
8. Stop

    #### Algorithm: createNode(value)
    1. Allocate memory for new node
    2. Set newNode->data = value
    3. Set newNode->prev = NULL
    4. Set newNode->next = NULL
    5. Return new node

    #### Algorithm: Insert at Beginning
    1. Create new node
    2. If head != NULL
        - Set head->prev = newNode
        - Set newNode->next = head
    3. Set head = newNode
    4. Return

    #### Algorithm: Insert at End
    1. Create new node
    2. If head == NULL
        - Set head = newNode
        - Return
    3. Traverse to last node
    4. Set last->next = newNode
    5. Set newNode->prev = last
    6. Return

    #### Algorithm: Insert at Position
    1. If position = 1
        - Call Insert at Beginning
    2. Traverse to position − 1
    3. If position invalid
        - Display error
    4. Set newNode->next = temp->next
    5. Set newNode->prev = temp
    6. If temp->next != NULL
        - Set temp->next->prev = newNode
    7. Set temp->next = newNode
    8. Return

    #### Algorithm: Delete at Beginning
    1. If head == NULL
        - Display “List is empty”
    2. Store head in temp
    3. Set head = head->next
    4. If head != NULL
        - Set head->prev = NULL
    5. Free temp
    6. Return

    #### Algorithm: Delete at End
    1. If head == NULL
        - Display “List is empty”
    2. If only one node
        - Free head
        - Set head = NULL
    3. Traverse to last node
    4. Set last->prev->next = NULL
    5. Free last node
    6. Return

    #### Algorithm: Delete at Position
    1. If head == NULL
        - Display “List is empty”
    2. If position = 1
        - Call Delete at Beginning
    3. Traverse to desired position
    4. If position invalid
        - Display error
    5. Set temp->next->prev = temp->prev (if temp->next != NULL)
    6. Set temp->prev->next = temp->next (if temp->prev != NULL)
    7. Free temp
    8. Return

    #### Algorithm: Display
    1. If head == NULL
        - Display “List is empty”
    2. Set temp = head
    3. While temp != NULL
        - Print temp->data
        - Move temp = temp->next
    4. Print NULL
    5. Return

---

### 📌 Applications
- Implementation of deque
- Browser history navigation
- Undo/redo functionality in editors
- Memory-efficient data structures
- Doubly-linked graph adjacency lists

---

### 🏁 Conclusion

Doubly linked lists provide bidirectional traversal, making insertion and deletion more flexible than singly linked lists. This implementation demonstrates dynamic memory management, pointer manipulation, and advanced linked list operations effectively.

---

## Circular Linked List Implementation

### 📘 Introduction
A Circular Linked List (CLL) is a type of linked list where the last node points back to the first node (head), forming a circular structure.

Unlike a singly linked list:
- There is no NULL at the end.
- Traversal continues until we reach the head again.

In this program, the following operations are implemented:
- Node Creation
- Insertion (Beginning, End, Position)
- Deletion (Beginning, End, Position)
- Display

---

### 🧠 Core Concepts
1️⃣ Node Structure
- Each node contains:
    - data
    - next pointer

2️⃣ Head Pointer
- Points to the first node
- If head == NULL, the list is empty

3️⃣ Circular Nature
- Last node’s next pointer points to head
- Traversal uses a do-while loop

4️⃣ Dynamic Memory Allocation
- Nodes are created using malloc()
- Deleted using free()

---

### 🧠 Algorithm: Circular Linked List Implementation
1. Start
2. Define structure Node with fields data and next
3. Initialize head = NULL
4. Display menu:
    1. Insert at Beginning
    2. Insert at End
    3. Insert at Position
    4. Delete at Beginning
    5. Delete at End
    6. Delete at Position
    7. Display
    8. Exit
5. Read user choice
6. Perform selected operation
7. Repeat until choice = 8
8. Stop

    #### Algorithm: createNode(value)
    1. Allocate memory for new node
    2. Set newNode->data = value
    3. Set newNode->next = NULL
    4. Return new node

    #### Algorithm: Insert at Beginning
    1. Create new node
    2. If head == NULL
        - Set head = newNode
        - Set newNode->next = head
    3. Else
        - Traverse to last node (whose next is head)
        - Set newNode->next = head
        - Set last->next = newNode
        - Set head = newNode
    4. Return

    #### Algorithm: Insert at End
    1. Create new node
    2. If head == NULL
        - Set head = newNode
        - Set newNode->next = head
    3. Else
        - Traverse to last node
        - Set last->next = newNode
        - Set newNode->next = head
    4. Return

    #### Algorithm: Insert at Position
    1. If position = 1
        - Call Insert at Beginning
    2. If head == NULL
        - Display “List is empty”
    3. Traverse to position − 1
    4. If position invalid
        - Display error
    5. Create new node
    6. Set newNode->next = temp->next
    7. Set temp->next = newNode
    8. Return

    #### Algorithm: Delete at Beginning
    1. If head == NULL
        - Display “List is empty”
    2. If only one node (head->next == head)
        - Free head
        - Set head = NULL
    3. Else
        - Traverse to last node
        - Store head in temp
        - Set head = head->next
        - Set last->next = head
        - Free temp
    4. Return

    #### Algorithm: Delete at End
    1. If head == NULL
        - Display “List is empty”
    2. If only one node
        - Free head
        - Set head = NULL
    3. Else
        - Traverse to last node (keep track of previous)
        - Set prev->next = head
        - Free last node
    4. Return

    #### Algorithm: Delete at Position
    1. If head == NULL
        - Display “List is empty”
    2. If position = 1
        - Call Delete at Beginning
    3. Traverse to desired position
    4. If position invalid
        - Display error
    5. Set prev->next = temp->next
    6. Free temp
    7. Return

    #### Algorithm: Display
    1. If head == NULL
        - Display “List is empty”
    2. Set temp = head
    3. Repeat
        - Print temp->data
        - Set temp = temp->next  
        Until temp == head
    4. Print “(head)”
    5. Return

---

### 📌 Applications
- Round-robin scheduling
- Circular queue implementation
- Multiplayer turn-based games
- Buffer management systems
- Josephus problem

---

### 🏁 Conclusion

A Circular Linked List connects the last node back to the first node, forming a loop. It eliminates NULL termination and is efficient for cyclic processes like scheduling. This implementation demonstrates insertion, deletion, and traversal operations using proper pointer manipulation.

---

## Stack Implementation Using Linked List

### 📘 Introduction
A Stack is a linear data structure that follows the LIFO (Last In, First Out) principle.
The element inserted last is the first one to be removed.

In this program, the stack is implemented using a linked list, which provides dynamic memory allocation and avoids stack overflow due to fixed size (as in array implementation).

---

### 🧠 Core Concepts
1️⃣ LIFO Principle
- Push → Insert element at the top
- Pop → Remove element from the top

2️⃣ Node Structure
Each node contains:
- data
- next pointer

3️⃣ Top Pointer
- Points to the top element of the stack
- If top == NULL, stack is empty

4️⃣ Dynamic Memory Allocation
- Memory allocated using malloc()
- Memory released using free()

---

### 🧠 Algorithm: Stack Using Linked List
1. Start
2. Define structure Node with fields data and next
3. Initialize top = NULL
4. Display menu:
    1. Push
    2. Pop
    3. Display
    4. Exit
5. Read user choice
6. Perform selected operation
7. Repeat until choice = 4
8. Stop

    #### Algorithm: Push(value)
    1. Allocate memory for new node
    2. If memory allocation fails
        - Display “Stack Overflow”
        - Return
    3. Set newNode->data = value
    4. Set newNode->next = top
    5. Set top = newNode
    6. Display success message
    7. Return

    #### Algorithm: Pop()
    1. If top == NULL
        - Display “Stack Underflow”
        - Return
    2. Store top in temp
    3. Display popped element
    4. Set top = top->next
    5. Free temp
    6. Return

    #### Algorithm: Display()
    1. If top == NULL
        - Display “Stack is empty”
        - Return
    2. Set temp = top
    3. While temp != NULL
        - Print temp->data
        - Set temp = temp->next
    4. Return

---

### 📌 Applications of Stack
- Expression evaluation (infix, postfix, prefix)
- Parenthesis checking
- Undo/Redo operations
- Function calls (Call Stack)
- Backtracking algorithms

---

### 🏁 Conclusion

The stack implemented using a linked list provides dynamic memory allocation and efficient push and pop operations in O(1) time complexity. It eliminates size limitations found in array-based stacks and efficiently demonstrates the LIFO principle using pointer manipulation.

---

## Queue Implementation Using Linked List

### 📘 Introduction
A Queue is a linear data structure that follows the FIFO (First In, First Out) principle.
The element inserted first is the first one to be removed.

In this program, the queue is implemented using a linked list, which allows dynamic memory allocation and avoids fixed size limitations.

---

### 🧠 Core Concepts
1️⃣ FIFO Principle
- Enqueue → Insert element at the rear
- Dequeue → Remove element from the front

2️⃣ Node Structure
Each node contains:
- data
- next pointer

3️⃣ Front and Rear Pointers
- front → Points to the first element
- rear → Points to the last element
- If both are NULL, the queue is empty

4️⃣ Dynamic Memory Allocation
- Memory allocated using malloc()
- Memory released using free()

---

### 🧠 Algorithm: Queue Using Linked List
1. Start
2. Define structure Node with fields data and next
3. Initialize front = NULL and rear = NULL
4. Display menu:
    1. Enqueue
    2. Dequeue
    3. Display
    4. Exit
5. Read user choice
6. Perform selected operation
7. Repeat until choice = 4
8. Stop

    #### Algorithm: Enqueue(value)
    1. Allocate memory for new node
    2. If memory allocation fails
        - Display “Queue Overflow”
        - Return
    3. Set newNode->data = value
    4. Set newNode->next = NULL
    5. If rear == NULL (queue is empty)
        - Set front = rear = newNode
    6. Else
        - Set rear->next = newNode
        - Set rear = newNode
    7. Display success message
    8. Return

    #### Algorithm: Dequeue()
    1. If front == NULL
        - Display “Queue Underflow”
        - Return
    2. Store front in temp
    3. Display dequeued element
    4. Set front = front->next
    5. If front == NULL
        - Set rear = NULL
    6. Free temp
    7. Return

    #### Algorithm: Display()
    1. If front == NULL
        - Display “Queue is empty”
        - Return
    2. Set temp = front
    3. While temp != NULL
        - Print temp->data
        - Set temp = temp->next
    4. Return

---

### 📌 Applications of Queue
- CPU scheduling
- Printer queue management
- Breadth First Search (BFS)
- Call center systems
- Resource sharing systems

---

### 🏁 Conclusion

The queue implemented using a linked list provides efficient enqueue and dequeue operations in O(1) time complexity. It dynamically allocates memory, eliminating fixed-size limitations of array-based queues while maintaining the FIFO principle effectively.

---

## Bubble Sort Implementation

### 📘 Introduction
Bubble Sort is a simple comparison-based sorting algorithm.
It repeatedly compares adjacent elements and swaps them if they are in the wrong order.

With each pass, the largest unsorted element “bubbles up” to its correct position at the end of the array.

---

### 🧠 Core Concepts
1️⃣ Comparison of Adjacent Elements
- Compare arr[j] and arr[j+1]
- Swap if arr[j] > arr[j+1]

2️⃣ Multiple Passes
- After each pass, the largest element is placed at the correct position

3️⃣ Optimization (Swapped Flag)
- If no swapping happens in a pass, the array is already sorted
- The algorithm stops early

4️⃣ In-Place Sorting
- Does not require extra memory

---

### 🧠 Algorithm: Bubble Sort
1. Start
2. Read number of elements n
3. Read array elements
4. Repeat for i = 0 to n-2
    - Set swapped = 0
    - For j = 0 to n-i-2
        - If arr[j] > arr[j+1]
            - Swap elements
            - Set swapped = 1
    - If swapped == 0
        - Break loop (array is sorted)
5. Display sorted array
6. Stop

---

### 🔁 Working Example
For array:  
5 3 8 4 2

Pass 1:  
5 3 → swap → 3 5  
5 8 → no swap  
8 4 → swap → 4 8  
8 2 → swap → 2 8  
Array becomes: 3 5 4 2 8  

Pass 2:  
3 5 → no swap  
5 4 → swap  
5 2 → swap  
Array becomes: 3 4 2 5 8  

And so on, until sorted.

---

### ⏱ Time Complexity
- Best Case: O(n) (Already sorted, due to swapped flag)
- Average Case: O(n²)
- Worst Case: O(n²)

---

### 💾 Space Complexity
- O(1) (In-place sorting)

---

### 📌 Applications
- Educational purposes (easy to understand)
- Small datasets
- When simplicity is more important than performance

---

### 🏁 Conclusion

Bubble Sort is one of the simplest sorting algorithms. Although it is not efficient for large datasets, it is useful for understanding the concept of sorting and algorithm design. The optimized version improves performance by stopping early if the array becomes sorted.

---

## Selection Sort Implementation

### 📘 Introduction
Selection Sort is a simple comparison-based sorting algorithm.
It works by repeatedly selecting the smallest element from the unsorted portion of the array and placing it at the beginning.

Unlike Bubble Sort, it performs minimum swaps — at most one swap per pass.

---

### 🧠 Core Concept
1️⃣ Divide the array into two parts:
-  Sorted portion (left side)
-  Unsorted portion (right side)

2️⃣ In each pass:
-  Find the smallest element from the unsorted portion
-  Swap it with the first unsorted element

3️⃣ Repeat until the entire array is sorted

---

### 🧠 Algorithm: Selection Sort
1. Start
2. Read number of elements n
3. Read array elements
4. For i = 0 to n - 2
    - Set minIndex = i
    - For j = i + 1 to n - 1
        - If arr[j] < arr[minIndex]
            - Set minIndex = j
    - If minIndex != i
        - Swap arr[i] and arr[minIndex]
5. Display sorted array
6. Stop

---

### 🔁 Working Example
For array:  
64 25 12 22 11

Pass 1:  
Smallest = 11  
Swap 64 and 11  
Array → 11 25 12 22 64  

Pass 2:  
Smallest in remaining = 12  
Swap 25 and 12  
Array → 11 12 25 22 64  

Pass 3:  
Smallest = 22  
Swap 25 and 22  
Array → 11 12 22 25 64  

Pass 4:  
Smallest = 25  
Swap 25 and 25 (no change)  
Array → 11 12 22 25 64  

Sorted array obtained.

---

### ⏱ Time Complexity
-  Best Case: O(n²)
-  Average Case: O(n²)
-  Worst Case: O(n²)

👉 Time complexity remains same because comparisons are always performed.

---

### 💾 Space Complexity
-  O(1) (In-place sorting)

---

### 📌 Advantages
-  Simple and easy to implement
-  Performs fewer swaps compared to Bubble Sort
-  Useful when memory writes are costly

---

### ⚠️ Disadvantages
-  Inefficient for large datasets
-  Not stable by default

---

### 🏁 Conclusion

Selection Sort repeatedly selects the minimum element and places it in its correct position. Although not efficient for large arrays, it is simple, requires minimal memory, and performs fewer swaps compared to Bubble Sort.

---

## Shell Sort Implementation

### 📘 Introduction
Shell Sort is an advanced version of Insertion Sort that improves performance by allowing the exchange of far-apart elements.

Instead of comparing only adjacent elements, it compares elements separated by a gap, which gradually reduces to 1.

When the gap becomes 1, the algorithm behaves like a normal insertion sort — but by then, the array is mostly sorted, making it efficient.

---

### 🧠 Core Concepts
1️⃣ Gap Method
- Start with a large gap (n/2)
- Reduce the gap by half each time
- Continue until gap becomes 1

2️⃣ Gapped Insertion Sort
- For each gap, perform insertion sort on elements separated by that gap

3️⃣ Improvement Over Insertion Sort
- Reduces large element movements early
- Improves overall efficiency

---

### 🧠 Algorithm: Shell Sort
1. Start
2. Read number of elements n
3. Read array elements
4. Set gap = n / 2
5. While gap > 0
    - For i = gap to n - 1
        - Store temp = arr[i]
        - Set j = i
        - While j >= gap AND arr[j - gap] > temp
            - Shift arr[j] = arr[j - gap]
            - Set j = j - gap
        - Place temp at position j
    - Reduce gap: gap = gap / 2
6. Display sorted array
7. Stop

---

### 🔁 Working Example
For array:  
12 34 54 2 3

Initial gap = 5/2 = 2

Gap = 2:  
Compare elements at distance 2  
Array becomes partially sorted  

Gap = 1:  
Normal insertion sort applied  
Final sorted array obtained  

Result → 2 3 12 34 54  

---

### ⏱ Time Complexity
- Best Case: O(n log n)
- Average Case: Between O(n log n) and O(n²)
- Worst Case: O(n²) (depends on gap sequence)

---

### 💾 Space Complexity
- O(1) (In-place sorting)

---

### 📌 Advantages
- Faster than Bubble, Selection, and Insertion Sort
- Efficient for medium-sized datasets
- Simple implementation

---

### ⚠️ Disadvantages
- Not stable
- Performance depends on gap sequence

---

### 🏁 Conclusion

Shell Sort improves insertion sort by allowing the exchange of distant elements first. By gradually reducing the gap, it efficiently sorts the array with better performance than basic quadratic sorting algorithms.

---

## Merge Sort Implementation

### 📘 Introduction
Merge Sort is a highly efficient divide-and-conquer sorting algorithm.
It divides the array into smaller subarrays, sorts them recursively, and then merges them back together in sorted order.

Unlike simple sorting algorithms, Merge Sort guarantees good performance even for large datasets.

---

### 🧠 Core Concepts
1️⃣ Divide
- Split the array into two halves

2️⃣ Conquer
- Recursively sort both halves

3️⃣ Combine (Merge)
- Merge the two sorted halves into one sorted array

4️⃣ Recursion
- The process continues until each subarray contains only one element

---

### 🧠 Algorithm: Merge Sort
1. Start
2. Read number of elements n
3. Read array elements
4. Call mergeSort(arr, 0, n-1)
5. Display sorted array
6. Stop

    #### Algorithm: mergeSort(arr, left, right)
    1. If left < right
    2. Find middle index
        - mid = left + (right - left) / 2
    3. Call mergeSort(arr, left, mid)
    4. Call mergeSort(arr, mid + 1, right)
    5. Call merge(arr, left, mid, right)
    6. Return

    #### Algorithm: merge(arr, left, mid, right)
    1. Calculate sizes:
        - n1 = mid - left + 1
        - n2 = right - mid
    2. Create temporary arrays L[n1] and R[n2]
    3. Copy elements into temporary arrays
    4. Compare elements of L and R
    5. Place smaller element into original array
    6. Copy remaining elements (if any)
    7. Return

---

### 🔁 Working Example
For array:  
38 27 43 3 9 82 10

Step 1: Divide into halves  
38 27 43 3 and 9 82 10

Step 2: Continue dividing until single elements  

Step 3: Merge step-by-step in sorted order  

Final result →  
3 9 10 27 38 43 82  

---

### ⏱ Time Complexity
- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n log n)

👉 Time complexity remains same in all cases.

---

### 💾 Space Complexity
- O(n) (Requires extra temporary arrays)

---

### 📌 Advantages
- Efficient for large datasets
- Stable sorting algorithm
- Predictable performance

---

### ⚠️ Disadvantages
- Requires extra memory
- Slightly slower for very small datasets compared to simpler sorts

---

### 🏁 Conclusion

Merge Sort is a powerful and efficient sorting algorithm based on the divide-and-conquer technique. It guarantees O(n log n) time complexity and is widely used in real-world applications where stable and consistent performance is required.

---