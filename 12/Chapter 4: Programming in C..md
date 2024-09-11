## CHAPTER 4: PROGRAMMING IN C [12-HRS]
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
____________________________________

## 4.1 Review of C programming concept
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

____________________________________

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

____________________________________

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

____________________________________


### 4.4 Pointers

#### 4.4.1 Definition of Pointer

- **Definition**: 
  - A pointer in C is a variable that stores the memory address of another variable. 
  - Pointers enable direct manipulation of memory and facilitate dynamic memory allocation.

- **Example**:
  ```c
  int *ptr; // Declaration of a pointer variable 'ptr' that can point to an integer
  float *ptr_float; // Declaration of a pointer variable 'ptr_float' that can point to a float
  ```

#### 4.4.2 Address (&) and Indirection (*) Operator

- **Address Operator (`&`)**:
  - The `&` operator is used to obtain the address of a variable.
  - It returns the memory address where the variable is stored.

- **Example**:
  ```c
  int num = 10;
  int *ptr = &num; // Assigning the address of 'num' to 'ptr'
  ```

- **Indirection or Dereference Operator (`*`)**:
  - The `*` operator is used to access the value stored at a pointer's address.
  - It is also used in pointer declarations to declare a pointer variable.

- **Example**:
  ```c
  int num = 10;
  int *ptr = &num; // 'ptr' now holds the address of 'num'
  printf("Value of num: %d\n", *ptr); // Output: Value of num: 10
  ```

#### 4.4.3 Pointer Expression and Assignment

- **Pointer Expression**:
  - A pointer expression combines pointer operators and operands to form valid C expressions.
  - Examples include arithmetic operations on pointers (`ptr++`, `ptr--`) and accessing array elements using pointers (`*(ptr + i)`).

- **Example**:
  ```c
  int arr[5] = {1, 2, 3, 4, 5};
  int *ptr = arr; // 'ptr' points to the first element of 'arr'
  printf("Third element of arr: %d\n", *(ptr + 2)); // Output: Third element of arr: 3
  ```

- **Pointer Assignment**:
  - Pointers can be assigned values of the same type or `NULL`.
  - Pointers can be reassigned to point to different variables or memory locations.

- **Example**:
  ```c
  int num1 = 10, num2 = 20;
  int *ptr = &num1; // 'ptr' points to 'num1'
  ptr = &num2; // Now 'ptr' points to 'num2'
  ```

#### 4.4.4 Call by Value and Call by Reference

#### Call by Value

In call by value, when a function is called, the actual value (data) of the argument is passed to the function. The function works with a copy of the data, and any modifications made to the parameters inside the function do not affect the original data in the calling function.

**Key Points:**

1. **Data Copying**: 
   - When arguments are passed by value, the function parameters receive copies of the actual data passed from the calling function.
   
2. **No Impact on Original Data**: 
   - Changes made to the parameters inside the function are local to that function and do not affect the original variables in the calling function.

3. **Usage**: 
   - Typically used for simple data types and situations where the function does not need to modify the original data but only needs to work with a local copy.

 

```c
#include <stdio.h>

// Function to swap two integers using call by value
void swapByValue(int x, int y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 5, b = 10;

    printf("Before swapping (Call by Value):\n");
    printf("a = %d, b = %d\n", a, b);

    swapByValue(a, b); // Passing a and b by value

    printf("After swapping (Call by Value):\n");
    printf("a = %d, b = %d\n", a, b); // Values of a and b remain unchanged

    return 0;
}
```

**Output**:
```
Before swapping (Call by Value):
a = 5, b = 10
After swapping (Call by Value):
a = 5, b = 10
```

In this example, even though `swapByValue` function swaps `x` and `y` inside, it doesn't affect the original variables `a` and `b` in `main()` because they are passed by value.

#### Call by Reference :

In call by reference, the memory address (reference) of the actual argument is passed to the function. This allows the function to directly access and modify the data stored at that memory address. Changes made inside the function using the references affect the original data in the calling function.

**Key Points:**

1. **Passing Addresses**: 
   - Instead of passing copies of data, call by reference passes the addresses (pointers) of the actual variables.

2. **Direct Modification**: 
   - Functions can modify the original data directly through the pointers, as they have access to the actual memory locations.

3. **Usage**: 
   - Useful when a function needs to modify the original data or when working with large data structures to avoid the overhead of copying.

 

```c
#include <stdio.h>

// Function to swap two integers using call by reference
void swapByReference(int *x, int *y) {
    int temp;
    temp = *x; // Dereference to access the value at address x
    *x = *y;   // Dereference to assign the value at address y to x
    *y = temp; // Dereference to assign temp to the value at address y
}

int main() {
    int a = 5, b = 10;

    printf("Before swapping (Call by Reference):\n");
    printf("a = %d, b = %d\n", a, b);

    swapByReference(&a, &b); // Passing addresses of a and b (call by reference)

    printf("After swapping (Call by Reference):\n");
    printf("a = %d, b = %d\n", a, b); // Values of a and b are swapped

    return 0;
}
```

**Output**:
```
Before swapping (Call by Reference):
a = 5, b = 10
After swapping (Call by Reference):
a = 10, b = 5
```

In this example, `swapByReference` function receives addresses of `a` and `b` (`&a` and `&b`), allowing it to modify the values at those addresses directly. As a result, `a` and `b` are swapped successfully.

 

### Summary:

- **Pointers** in C are variables that store memory addresses.
- **Operators** (`&` and `*`) are used for address-of and indirection operations.
- **Expressions** and **assignment** involving pointers facilitate dynamic memory management and efficient data access.
- **Call by Value** and **Call by Reference** determine how arguments are passed to functions, impacting whether changes made inside the function affect the original variables.

---

### 4.5 Working with Files

### 4.5.1 Concept of Data File and 4.5.4 Opening, Reading, Writing and Appending data file

**1. Introduction to Data Files:**
A data file is a storage unit on a disk that contains data. In programming, files are used to store data permanently, allowing it to be retrieved, updated, or processed later. Files serve as an interface between the program and the underlying storage device.

**2. Types of Data Files:**
There are two main types of data files:
   - **Text Files:** These files contain data in the form of text, which means the data is human-readable. Each line of text ends with a newline character (`\n`). Examples include `.txt` files and source code files like `.c` or `.java`.
   - **Binary Files:** These files contain data in binary form, which is not human-readable. Data in binary files is stored in the same format as it is in memory, making them more efficient for storage and retrieval. Examples include `.exe` files and image files like `.png` or `.jpg`.

**3. File Operations:**
In C programming, several operations can be performed on files:
   - **Creating a File:** A file can be created using the `fopen()` function.
   - **Opening a File:** A file must be opened before it can be read from or written to. The `fopen()` function is used for this purpose.
   - **Reading from a File:** Data can be read from a file using functions like `fscanf()`, `fgets()`, or `fgetc()`.
   - **Writing to a File:** Data can be written to a file using functions like `fprintf()`, `fputs()`, or `fputc()`.
   - **Closing a File:** After all operations are complete, the file should be closed using the `fclose()` function to release resources.

**4. File Modes:**
When opening a file, you specify the mode in which the file will be used. Common file modes include:
   - `"r"`: Read mode (opens an existing file for reading).
   - `"w"`: Write mode (creates a new file for writing, or truncates an existing file).
   - `"a"`: Append mode (opens an existing file for writing and appends new data).
   - `"r+"`: Read and write mode (opens an existing file for both reading and writing).
   - `"w+"`: Write and read mode (creates a new file for writing and reading, or truncates an existing file).
   - `"a+"`: Append and read mode (opens an existing file for writing and appends new data, allows reading as well).

**5. Example: Working with Text Files in C**

Program to create, write to, and read from a text file in C:

```c
#include <stdio.h>

int main() {
    FILE *filePtr;
    char data[100];

    // Creating and writing to a file
    filePtr = fopen("example.txt", "w");
    if (filePtr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(filePtr, "Hello, this is a text file.\n");
    fprintf(filePtr, "This is a new line of text.\n");
    fclose(filePtr);

    // Reading from the file
    filePtr = fopen("example.txt", "r");
    if (filePtr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    while (fgets(data, 100, filePtr) != NULL) {
        printf("%s", data);
    }
    fclose(filePtr);

    return 0;
}
```

**Explanation:**
   - **Creating and Writing:** The file `example.txt` is created using `fopen()` in write mode (`"w"`). If the file already exists, it will be truncated. The `fprintf()` function writes formatted data to the file, and `fclose()` closes the file.
   - **Reading:** The file is then reopened in read mode (`"r"`). The `fgets()` function reads lines from the file, and the content is printed to the console. Finally, the file is closed again.

C program that demonstrates how to append text to an existing file:

```c
#include <stdio.h>

int main() {
    FILE *filePtr;

    // Open the file in append mode
    filePtr = fopen("example.txt", "a");
    if (filePtr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Append text to the file
    fprintf(filePtr, "This text is appended to the file.\n");
    fprintf(filePtr, "Appending another line to the file.\n");

    // Close the file
    fclose(filePtr);

    return 0;
}
```

### Explanation:
1. **Open the File in Append Mode:**
   - `fopen("example.txt", "a")` opens the file for appending. If the file does not exist, it will be created. If it exists, new content will be added to the end without modifying existing content.

2. **Append Text:**
   - `fprintf(filePtr, "This text is appended to the file.\n");` writes a new line of text to the file.
   - `fprintf(filePtr, "Appending another line to the file.\n");` writes another line of text.

3. **Close the File:**
   - `fclose(filePtr);` closes the file to ensure all changes are saved and resources are released.


**6. Importance of Data Files:**
Data files are crucial for programs that require persistent data storage. Without files, all data would be lost once the program terminates. Files allow for long-term storage and management of data, making them essential for most real-world applications, such as databases, word processors, and spreadsheets.

---

### 4.5.2 Sequential and Random File

**1. Introduction:**
Files can be accessed in different ways, depending on how the data is organized and how it needs to be retrieved. The two primary methods of file access in C programming are Sequential Access and Random Access.

---

**2. Sequential File Access:**

- **Definition:** 
  Sequential file access involves reading or writing data in a linear order, from the beginning to the end of the file. In this method, the file pointer automatically moves to the next piece of data after each operation, making it ideal for processing data in a fixed sequence.

- **Usage:**
  Sequential access is commonly used when the data needs to be processed in order, such as reading a text file line by line, processing log files, or writing data that will later be read in the same order.

- **Example:**
  Program that demonstrates sequential access in a text file:

  ```c
  #include <stdio.h>

  int main() {
      FILE *filePtr;
      char line[100];

      // Writing data sequentially to a file
      filePtr = fopen("sequential.txt", "w");
      if (filePtr == NULL) {
          printf("Error opening file!\n");
          return 1;
      }
      fprintf(filePtr, "First Line\n");
      fprintf(filePtr, "Second Line\n");
      fprintf(filePtr, "Third Line\n");
      fclose(filePtr);

      // Reading data sequentially from the file
      filePtr = fopen("sequential.txt", "r");
      if (filePtr == NULL) {
          printf("Error opening file!\n");
          return 1;
      }
      while (fgets(line, sizeof(line), filePtr) != NULL) {
          printf("%s", line);
      }
      fclose(filePtr);

      return 0;
  }
  ```

  **Explanation:**
  - The file `sequential.txt` is opened in write mode, and three lines are written sequentially using `fprintf()`.
  - The file is then reopened in read mode, and each line is read sequentially using `fgets()`.

---

**3. Random File Access:**

- **Definition:**
  Random file access allows data to be read from or written to any location in the file, without the need to process data in a linear sequence. This method uses the file pointer to move directly to any desired location in the file.

- **Usage:**
  Random access is useful when you need to access specific data points quickly, such as in databases, indexed files, or when modifying a particular record in a file without reading the entire file.

- **Key Functions:**
  - `fseek(FILE *stream, long int offset, int whence)`: Moves the file pointer to a specified location.
  - `ftell(FILE *stream)`: Returns the current position of the file pointer.
  - `rewind(FILE *stream)`: Resets the file pointer to the beginning of the file.
 
Program that demonstrates random access in a file:

```c
#include <stdio.h>

int main() {
    FILE *filePtr;
    char buffer[50];

    // Writing data to a text file
    filePtr = fopen("textfile.txt", "w");
    if (filePtr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(filePtr, "Line 1\nLine 2\nLine 3\n");
    fclose(filePtr);

    // Reading a specific line using random access
    filePtr = fopen("textfile.txt", "r");
    if (filePtr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Move the file pointer to the start of "Line 2" by skipping the first 7 characters
    fseek(filePtr, 7, SEEK_SET);
    fgets(buffer, sizeof(buffer), filePtr);
    printf("Line 2: %s", buffer); // Output should be "Line 2"

    fclose(filePtr);

    return 0;
}
```

**Explanation:**
- In the example, `fseek()` is used to skip the first 7 characters, directly jumping to the start of "Line 2" in a text file.

---

**4. Comparison Between Sequential and Random File Access:**

- **Efficiency:** 
  - Sequential access is straightforward and efficient when processing all data in a file.
  - Random access is more flexible and efficient for accessing specific data points, but it requires more careful management of the file pointer.

- **Use Cases:**
  - Use sequential access for tasks like reading log files, processing records in order, or when the data is naturally sequential.
  - Use random access when you need to retrieve, modify, or append specific records in a file, such as in databases or indexed files.

---

### 4.5.3 File Manipulation Functions: `putw`, `getw`, `putc`, `getc`, `fscanf`, `fprintf`

In C programming, various file manipulation functions enable reading and writing data to and from files. These functions are essential for handling files in both text and binary modes. Below are explanations and examples for each of the mentioned functions.

---

**1. `putw`**

- **Description:**
  - `putw` is used to write an integer to a file in binary mode. It writes the integer value in its binary form.
  - This function is suitable for storing integers when the exact binary representation is needed.

- **Syntax:**
  ```c
  int putw(int value, FILE *stream);
  ```

- **Example:**
  ```c
  #include <stdio.h>

  int main() {
      FILE *filePtr;
      int num = 1234;

      // Open a file in binary write mode
      filePtr = fopen("binaryfile.dat", "wb");
      if (filePtr == NULL) {
          printf("Error opening file!\n");
          return 1;
      }

      // Write the integer to the file
      putw(num, filePtr);

      fclose(filePtr);
      return 0;
  }
  ```

**Explanation:** The example writes the integer `1234` to a binary file. The file will contain the binary representation of the integer.

---

**2. `getw`**

- **Description:**
  - `getw` is used to read an integer from a file in binary mode. It reads the binary representation of an integer and converts it back to an integer.
  
- **Syntax:**
  ```c
  int getw(FILE *stream);
  ```

- **Example:**
  ```c
  #include <stdio.h>

  int main() {
      FILE *filePtr;
      int num;

      // Open a file in binary read mode
      filePtr = fopen("binaryfile.dat", "rb");
      if (filePtr == NULL) {
          printf("Error opening file!\n");
          return 1;
      }

      // Read the integer from the file
      num = getw(filePtr);

      printf("Read integer: %d\n", num);

      fclose(filePtr);
      return 0;
  }
  ```

**Explanation:** The example reads the integer stored in `binaryfile.dat` and prints it. The file must contain an integer written in binary mode, as with `putw`.

---

**3. `putc`**

- **Description:**
  - `putc` is used to write a single character to a file in text mode.
  - It writes the character as it appears, making it suitable for text files.

- **Syntax:**
  ```c
  int putc(int char, FILE *stream);
  ```

- **Example:**
  ```c
  #include <stdio.h>

  int main() {
      FILE *filePtr;
      char ch = 'A';

      // Open a file in write mode
      filePtr = fopen("textfile.txt", "w");
      if (filePtr == NULL) {
          printf("Error opening file!\n");
          return 1;
      }

      // Write the character to the file
      putc(ch, filePtr);

      fclose(filePtr);
      return 0;
  }
  ```

**Explanation:** The example writes the character `A` to a text file. The file will contain the character as it appears.

---

**4. `getc`**

- **Description:**
  - `getc` is used to read a single character from a file in text mode.
  - It reads the next character in the file, returning it as an integer.

- **Syntax:**
  ```c
  int getc(FILE *stream);
  ```

- **Example:**
  ```c
  #include <stdio.h>

  int main() {
      FILE *filePtr;
      char ch;

      // Open a file in read mode
      filePtr = fopen("textfile.txt", "r");
      if (filePtr == NULL) {
          printf("Error opening file!\n");
          return 1;
      }

      // Read the character from the file
      ch = getc(filePtr);

      printf("Read character: %c\n", ch);

      fclose(filePtr);
      return 0;
  }
  ```

**Explanation:** The example reads the first character from `textfile.txt` and prints it. The file must contain a character written in text mode, as with `putc`.

---

**5. `fscanf`**

- **Description:**
  - `fscanf` is used to read formatted data from a file in text mode.
  - It works similarly to `scanf`, but reads data from a file instead of standard input.

- **Syntax:**
  ```c
  int fscanf(FILE *stream, const char *format, ...);
  ```

- **Example:**
  ```c
  #include <stdio.h>

  int main() {
      FILE *filePtr;
      int num;
      char str[50];

      // Open a file in read mode
      filePtr = fopen("datafile.txt", "r");
      if (filePtr == NULL) {
          printf("Error opening file!\n");
          return 1;
      }

      // Read an integer and a string from the file
      fscanf(filePtr, "%d %s", &num, str);

      printf("Read integer: %d\n", num);
      printf("Read string: %s\n", str);

      fclose(filePtr);
      return 0;
  }
  ```

**Explanation:** The example reads an integer and a string from `datafile.txt`. The file must contain data in the format specified by `fscanf`.

---

**6. `fprintf`**

- **Description:**
  - `fprintf` is used to write formatted data to a file in text mode.
  - It works similarly to `printf`, but writes data to a file instead of standard output.

- **Syntax:**
  ```c
  int fprintf(FILE *stream, const char *format, ...);
  ```

- **Example:**
  ```c
  #include <stdio.h>

  int main() {
      FILE *filePtr;
      int num = 1234;
      char str[] = "Hello";

      // Open a file in write mode
      filePtr = fopen("datafile.txt", "w");
      if (filePtr == NULL) {
          printf("Error opening file!\n");
          return 1;
      }

      // Write an integer and a string to the file
      fprintf(filePtr, "%d %s", num, str);

      fclose(filePtr);
      return 0;
  }
  ```

**Explanation:** The example writes an integer and a string to `datafile.txt`. The file will contain the data formatted as specified in the `fprintf` statement.

---




