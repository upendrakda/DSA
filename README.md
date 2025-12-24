# Data Structure & Algorithm

### Dynamic Memory Allocation (DMA) in C

This project demonstrates the implementation of **Dynamic Memory Allocation** in C using the standard library functions: `malloc()`, `calloc()`, `realloc()`, and `free()`.

---

### Overview

Dynamic Memory Allocation allows programs to request memory **at runtime**, rather than using fixed memory at compile-time. This is useful when the size of data structures (like arrays) is not known beforehand or may change during execution.

---

### Key Functions

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

### Advantages of Dynamic Memory Allocation
- Efficient use of memory
- Flexible data size management
- Supports dynamic data structures like linked lists and trees

---

### Conclusion

Dynamic Memory Allocation provides flexibility and efficient memory management in C programs.
Proper usage of `malloc()`, `calloc()`, `realloc()`, and `free()` is essential to avoid memory leaks and runtime errors.

---
