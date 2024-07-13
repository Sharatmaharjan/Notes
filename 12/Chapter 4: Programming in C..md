#### CHAPTER 4: PROGRAMMING IN C
- 4.1 Review of C programming concept
- 4.2 Functions
  - 4.2.1 Concept of library and user-defined functions and advantages
  - 4.2.2 Function definition, prototype, call and return statements
  - 4.2.3 Accessing a Function by passing values
  - 4.2.4 Concept of storage: automatic and external
  - 4.2.5 Concept of Recursion: factorial and Fibonacci problems
- 4.3 Structures and Unions
  - 4.3.1 Structure: Definition, Declaration, Initialization, and Size of Structure.
  - 4.3.2 Accessing Members of the structure
  - 4.3.3 Array of structure
  - 4.3.4 Union: Definition, Declaration
  - 4.3.5 Difference between union and structure.
- 4.4 Pointers
  - 4.4.1 Definition of Pointer
  - 4.4.2 Address (&) and indirection (*) operator
  - 4.4.3 Pointer Expression and Assignment
  - 4.4.4 Call by values and call by reference
- 4.5 Working with Files
  - 4.5.1 Concept of Data File
  - 4.5.2 Sequential and Random File
  - 4.5.3 File manipulation function: putw, getw, putc, getc, fscanf, fprintf
  - 4.5.4 Opening, Reading, Writing, and Appending data file

### 1. Introduction to C Programming
- C is a general-purpose programming language developed in 1972 by Dennis Ritchie at Bell Labs.
- Known for its efficiency, flexibility, and direct access to system hardware, C is widely used in system software, embedded systems, and applications where performance is critical.

### 2. Basic Structure of a C Program
- **Header Files**: Provide essential functions and macros (`#include <stdio.h>` for standard input/output).
- **Main Function**: Every C program must have a `main()` function where execution begins.
  
  ```c
  #include <stdio.h>
  
  int main() {
      // statements
      return 0;
  }
  ```

### 3. Data Types
- **Primitive Data Types**: `int`, `float`, `double`, `char`, etc.
- **Derived Data Types**: Arrays, Structures, Unions, Pointers, etc.

### 4. Variables and Constants
- **Variables**: Named memory locations to store data. Must be declared before use.
  
  ```c
  int age;
  float pi = 3.14;
  ```

- **Constants**: Fixed values that do not change during program execution. Defined using `const` keyword.
  
  ```c
  const int MAX_SIZE = 100;
  ```

### 5. Operators
- **Arithmetic Operators**: `+`, `-`, `*`, `/`, `%`
- **Relational Operators**: `==`, `!=`, `>`, `<`, `>=`, `<=`
- **Logical Operators**: `&&`, `||`, `!`
- **Assignment Operators**: `=`, `+=`, `-=` etc.
- **Bitwise Operators**: `&`, `|`, `^`, `<<`, `>>`

### 6. Control Structures
- **Conditional Statements**: `if`, `else`, `else if`
  
  ```c
  if (condition) {
      // statements
  } else if (another_condition) {
      // statements
  } else {
      // statements
  }
  ```

- **Loops**: `for`, `while`, `do-while`
  
  ```c
  for (initialization; condition; increment/decrement) {
      // statements
  }
  
  while (condition) {
      // statements
  }
  
  do {
      // statements
  } while (condition);
  ```

### 7. Functions
- **Function Declaration and Definition**:
  
  ```c
  // Function Declaration
  int add(int a, int b);
  
  // Function Definition
  int add(int a, int b) {
      return a + b;
  }
  ```

- **Function Prototypes**: Declaring function signatures before main function for visibility.
  
  ```c
  // Function Prototype
  int add(int, int);
  
  int main() {
      // function call
      int result = add(5, 3);
      return 0;
  }
  ```

### 8. Arrays
- **Declaration and Initialization**:
  
  ```c
  int numbers[5] = {1, 2, 3, 4, 5};
  ```

- **Accessing Elements**:
  
  ```c
  printf("%d", numbers[2]);  // Output: 3
  ```

### 9. Pointers
- **Address and Pointer Declaration**:
  
  ```c
  int *ptr;
  int num = 10;
  ptr = &num;  // ptr now holds address of num
  ```

- **Pointer Arithmetic**:
  
  ```c
  ptr++;  // Moves pointer to next memory location
  ```

### 10. Structures and Unions
- **Structures**: User-defined data type to group items of possibly different types under a single name.
  
  ```c
  struct Person {
      char name[50];
      int age;
  };
  ```

- **Unions**: Similar to structures but share memory locations for different variables.
  
  ```c
  union Data {
      int i;
      float f;
      char str[20];
  };
  ```

### 11. File Handling
- **File Operations**: Opening, Reading, Writing, and Closing files using `fopen`, `fclose`, `fprintf`, `fscanf`, etc.

### 12. Dynamic Memory Allocation
- **Functions**: `malloc`, `calloc`, `realloc`, `free` to manage memory dynamically during program execution.

### 13. Preprocessor Directives
- **`#define`**: Defines constants or macros.
- **`#include`**: Includes header files.
- **`#ifdef`, `#ifndef`, `#endif`**: Conditional compilation directives.

### 14. Miscellaneous Concepts
- **Recursion**: Function calling itself.
- **Command-line Arguments**: Arguments passed to `main()`.

Certainly! Here are detailed notes on each sub-topic related to functions in C programming:

### 4.2 Functions

#### 4.2.1 Concept of Library and User-Defined Functions and Advantages

**Functions** in C are modular blocks of code that perform a specific task. They can be categorized into two types:

- **Library Functions**: Pre-defined functions provided by C standard libraries (`stdio.h`, `math.h`, etc.) or user-created libraries. Examples include `printf()`, `scanf()`, `sqrt()`, etc.
  
  ```c
  #include <stdio.h>
  
  int main() {
      printf("Hello, World!\n");
      return 0;
  }
  ```

- **User-Defined Functions**: Functions defined by the programmer to perform specific tasks tailored to their needs. These functions enhance code modularity, readability, and reusability.
  
  ```c
  // Function prototype
  void greet();
  
  int main() {
      greet();  // Function call
      return 0;
  }
  
  // Function definition
  void greet() {
      printf("Hello, User!\n");
  }
  ```

**Advantages**:
- **Modularity**: Functions break down complex tasks into smaller, manageable units.
- **Reusability**: Functions can be reused across different parts of the program or in different programs.
- **Readability**: Enhances code readability by abstracting complex logic into named functions.
- **Easy Debugging**: Isolates errors to specific functions, simplifying the debugging process.

#### 4.2.2 Function Definition, Prototype, Call, and Return Statements

**Function Definition**:
- Specifies the function's name, return type, parameters (if any), and body.

  ```c
  // Function definition
  int add(int a, int b) {
      return a + b;
  }
  ```

**Function Prototype**:
- Declaration of the function before its use in the program. Includes function name, return type, and parameter types.

  ```c
  // Function prototype
  int add(int, int);
  ```

**Function Call**:
- Invoking a function to execute its defined task.

  ```c
  int result = add(5, 3);  // Function call
  ```

**Return Statement**:
- Used to return a value from a function to the calling function.

  ```c
  return a + b;
  ```

#### 4.2.3 Accessing a Function by Passing Values

**Passing Values**:
- Values can be passed to functions through parameters. These parameters act as placeholders to receive data from the calling function.

  ```c
  // Function definition
  void display(int num) {
      printf("Number: %d\n", num);
  }
  
  int main() {
      int x = 10;
      display(x);  // Passing 'x' to function
      return 0;
  }
  ```

#### 4.2.4 Concept of Storage: Automatic and External

**Automatic Storage**:
- Default storage class for local variables declared inside functions.
- Automatically created when the function is called and destroyed when the function exits.

  ```c
  void func() {
      int x = 10;  // Automatic storage duration
  }
  ```

**External Storage**:
- Variables declared outside functions or using `extern` keyword.
- Retain their value between function calls and have a global scope.

  ```c
  // External variable declaration
  int count = 0;
  
  void increment() {
      count++;  // Accessing external variable
  }
  ```
Certainly! Here are detailed notes specifically focusing on the concept of recursion with examples of solving factorial and Fibonacci sequence problems in C programming:

### 4.2.5 Concept of Recursion: Factorial and Fibonacci Problems

#### Recursion Overview

Recursion is a powerful programming technique where a function calls itself directly or indirectly to solve a problem. It breaks down a problem into smaller, similar sub-problems until reaching a base case where the solution can be directly computed.

#### 1. Recursive Function Structure

- **Base Case**: Defines the simplest possible case where the recursion ends without further recursive calls.
- **Recursive Case**: Defines how the function calls itself with smaller or simpler input to solve the problem incrementally.

#### 2. Example: Factorial Calculation

Factorial of a non-negative integer `n`, denoted as `n!`, is the product of all positive integers less than or equal to `n`.

- **Base Case**: `0! = 1` and `1! = 1`.
- **Recursive Formula**: `n! = n * (n-1)!` for `n > 1`.

```c
// Recursive function to calculate factorial
int factorial(int n) {
    // Base case
    if (n == 0 || n == 1)
        return 1;
    // Recursive case
    else
        return n * factorial(n - 1);
}
```

**Explanation**:
- If `n` is `0` or `1`, return `1` (base case).
- Otherwise, compute `n * factorial(n - 1)` (recursive case).

**Example Usage**:
```c
int main() {
    int num = 5;
    int fact = factorial(num);
    printf("Factorial of %d is %d\n", num, fact);
    return 0;
}
```
**Output**:
```
Factorial of 5 is 120
```



#### 3. Example: Fibonacci Sequence

The Fibonacci sequence is a series of numbers where each number is the sum of the two preceding ones, typically starting with `0` and `1`.

- **Base Cases**: `fib(0) = 0` and `fib(1) = 1`.
- **Recursive Formula**: `fib(n) = fib(n-1) + fib(n-2)` for `n > 1`.

```c
// Recursive function to calculate Fibonacci sequence
int fibonacci(int n) {
    // Base case
    if (n <= 1)
        return n;
    // Recursive case
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}
```

**Explanation**:
- If `n` is `0` or `1`, return `n` (base case).
- Otherwise, compute `fibonacci(n - 1) + fibonacci(n - 2)` (recursive case).

**Example Usage**:
```c
int main() {
    int num = 6;
    printf("Fibonacci sequence up to %d:\n", num);
    for (int i = 0; i < num; ++i) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}
```

**Output**:
```
Fibonacci sequence up to 6:
0 1 1 2 3 5
```

#### 4. Considerations for Recursion

- **Base Case Importance**: Ensure the base case(s) are well-defined to prevent infinite recursion.
- **Performance**: Recursive solutions can be less efficient compared to iterative approaches due to function call overhead and stack usage.
- **Stack Limitation**: Recursion depth is limited by the system's stack size, potentially leading to stack overflow errors with excessively deep recursion.

#### 5. Practical Use Cases

- Recursion is useful for problems involving hierarchical structures, such as tree traversal (e.g., binary trees).
- It simplifies solutions for problems inherently defined in terms of smaller instances of the same problem (e.g., factorial, Fibonacci).

Here are detailed notes on structures and unions in C programming:

### 4.3 Structures and Unions

#### 4.3.1 Structure: Definition, Declaration, Initialization, and Size of Structure

**Structure** in C is a user-defined data type that allows you to group together variables of different types under a single name.

**Definition and Declaration**:
- **Definition**: Specifies the blueprint of the structure, including member variables.
  
  ```c
  // Structure definition
  struct Person {
      char name[50];
      int age;
      float salary;
  };
  ```

- **Declaration**: Creates variables of the structure type.
  
  ```c
  // Structure variable declaration
  struct Person employee1, employee2;
  ```

**Initialization**:
- Initializing structure members can be done during declaration or separately using assignment.

  ```c
  // Initialization during declaration
  struct Person employee1 = {"John Doe", 30, 50000.0};
  
  // Initialization after declaration
  employee2.age = 25;
  ```

**Size of Structure**:
- The size of a structure is determined by the sum of the sizes of its members, possibly adjusted for alignment.

  ```c
  printf("Size of struct Person: %lu bytes\n", sizeof(struct Person));
  ```

#### 4.3.2 Accessing Members of the Structure

Members of a structure are accessed using the dot (`.`) operator.

```c
// Accessing structure members
printf("Name: %s, Age: %d, Salary: %.2f\n", employee1.name, employee1.age, employee1.salary);
```

#### 4.3.3 Array of Structure

Arrays of structures allow you to store multiple instances of structures sequentially in memory.

```c
// Array of structures
struct Person employees[10];
employees[0].age = 35;
```
**Example of Structure Usage**:

```c
#include <stdio.h>

// Define a structure
struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

int main() {
    struct Student students[3];  // Array of structures
    
    // Input information for each student
    printf("Enter information for students:\n");
    for (int i = 0; i < 3; ++i) {
        printf("Student %d:\n", i + 1);
        
        printf("Enter name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        
        printf("Enter roll number: ");
        scanf("%d", &students[i].rollNumber);
        
        printf("Enter marks: ");
        scanf("%f", &students[i].marks);
        
        // Consume the newline character left by scanf in the input buffer
        while (getchar() != '\n');
        
        printf("\n");
    }
    
    // Display information of all students
    printf("Student Information:\n");
    for (int i = 0; i < 3; ++i) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
    
    return 0;
}
```

**Example Execution**:
```
Enter information for students:
Student 1:
Enter name: John Doe
Enter roll number: 101
Enter marks: 85.5

Student 2:
Enter name: Jane Smith
Enter roll number: 102
Enter marks: 90.0

Student 3:
Enter name: Alice Johnson
Enter roll number: 103
Enter marks: 95.5

Student Information:
Student 1:
Name: John Doe
Roll Number: 101
Marks: 85.50

Student 2:
Name: Jane Smith
Roll Number: 102
Marks: 90.00

Student 3:
Name: Alice Johnson
Roll Number: 103
Marks: 95.50
```

**Explanation**:
- The program defines a structure `struct Student` with `name`, `rollNumber`, and `marks`.
- An array `students` of size `3` is declared to store instances of `struct Student`.
- Inside the `for` loop, the program prompts the user to input data for each student (`name`, `rollNumber`, `marks`) using `fgets` and `scanf`.
- After inputting data, it displays the information of all students using another `for` loop.

This example demonstrates how to use an array of structures in C to manage and display user-inputted data for multiple students effectively.


#### 4.3.4 Union: Definition, Declaration

**Union** in C is similar to a structure but uses a single memory location to hold multiple variables of different types.

**Definition and Declaration**:

```c
// Union definition
union Data {
    int i;
    float f;
    char str[20];
};

// Union variable declaration
union Data data;
```

**Usage**:
- All members share the same memory location, so modifying one member affects the others.

#### 4.3.5 Difference between Union and Structure

**Key Differences**:

- **Memory Allocation**:
  - **Structure**: Allocates separate memory for each member.
  - **Union**: Shares the same memory for all members.

- **Size**:
  - **Structure**: Size is the sum of sizes of all members.
  - **Union**: Size is the size of the largest member.

- **Usage**:
  - **Structure**: Used when different types of data need to be grouped together.
  - **Union**: Used when only one type of data will be accessed at a time but you want to save memory.

**Example of Union Usage**:

```c
#include <stdio.h>

union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data data;
    
    data.i = 10;
    printf("Data.i: %d\n", data.i);
    
    data.f = 220.5;
    printf("Data.f: %.2f\n", data.f);
    
    strcpy(data.str, "C Programming");
    printf("Data.str: %s\n", data.str);
    
    printf("Size of union Data: %lu bytes\n", sizeof(data));
    
    return 0;
}
```

**Output**:
```
Data.i: 10
Data.f: 220.50
Data.str: C Programming
Size of union Data: 20 bytes
```

**Explanation**:
- In this example, `union Data` is defined with three members (`i`, `f`, `str`) sharing the same memory location.
- Modifying one member (`data.i`, `data.f`, `data.str`) affects the others due to the shared memory.
- The size of `union Data` is determined by the largest member (`str`, which is 20 bytes).
