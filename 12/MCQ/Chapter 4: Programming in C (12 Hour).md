
### 4.1 Review of C Programming Concepts

1. **Which of the following is not a valid data type in C?**  
   a) int  
   b) char  
   c) float  
   **d) string**  

### 4.2 Functions

#### 4.2.1 Concept of Library and User-Defined Functions and Advantages

2. **What is the main advantage of using library functions in C programming?**  
   **a) Reusability**  
   b) Optimization  
   c) Simplicity  
   d) Customization  

3. **Which function is user-defined in C?**  
   a) `printf()`  
   **b) `myFunction()`**  
   c) `scanf()`  
   d) `sqrt()`  

#### 4.2.2 Function Definition, Prototype, Call, and Return Statements

4. **Which of the following correctly defines a function prototype in C?**  
   **a) int add(int, int);**  
   b) add(int, int);  
   c) void add();  
   d) function add();  

5. **Which statement is used to call a function in C?**  
   **a) functionName();**  
   b) call functionName;  
   c) define functionName();  
   d) void functionName();  

#### 4.2.3 Accessing a Function by Passing Values

6. **Which method is used to pass values to a function in C?**  
   a) Call by value  
   b) Call by reference  
   **c) Both a and b**  
   d) Call by pointer  

#### 4.2.4 Concept of Storage: Automatic and External

7. **Which keyword is used to define an external variable in C?**  
   **a) extern**  
   b) auto  
   c) static  
   d) global  

8. **By default, variables in a function are stored as...**  
   a) external  
   **b) automatic**  
   c) global  
   d) static  

#### 4.2.5 Concept of Recursion: Factorial and Fibonacci Problems

9. **What is recursion in C programming?**  
   a) A function that calls multiple other functions  
   b) A function that is never called  
   **c) A function that calls itself**  
   d) A function that does not return a value  

10. **The base case in a recursive function is used to...**  
    a) Initialize the function  
    b) Call the function  
    **c) Terminate the recursion**  
    d) Declare variables  

### 4.3 Structures and Unions

#### 4.3.1 Structure: Definition, Declaration, Initialization, and Size of Structure

11. **Which of the following is the correct way to define a structure in C?**  
    **a) struct person { char name[20]; int age; };**  
    b) structure person { char name[20]; int age; };  
    c) person { char name[20]; int age; };  
    d) typedef struct { char name[20]; int age; } person;  

#### 4.3.2 Accessing Members of Structure

12. **Which operator is used to access a member of a structure in C?**  
    **a) . (dot)**  
    b) -> (arrow)  
    c) & (ampersand)  
    d) * (asterisk)  

#### 4.3.3 Array of Structures

13. **How do you define an array of structures in C?**  
    a) struct array { int a[10]; };  
    **b) struct student arr[5];**  
    c) student struct arr[5];  
    d) typedef struct { int a[10]; } array;  

#### 4.3.4 Union: Definition, Declaration

14. **What is the key characteristic of a union in C?**  
    **a) All members share the same memory location**  
    b) All members have different memory locations  
    c) Only one member can be defined at a time  
    d) The size of the union is the sum of all members  

#### 4.3.5 Difference Between Union and Structure

15. **What is the key difference between a union and a structure in C?**  
    a) A union can have more members than a structure  
    **b) A union shares memory for all members, while a structure allocates separate memory for each member**  
    c) A structure can only have integers, while a union can have any data type  
    d) A structure is faster to access than a union  

### 4.4 Pointers

#### 4.4.1 Definition of Pointer

16. **What is a pointer in C?**  
    **a) A variable that stores the address of another variable**  
    b) A function that points to a variable  
    c) A function pointer  
    d) A type of loop  

#### 4.4.2 Address (&) and Indirection (*) Operator

17. **Which operator is used to get the address of a variable in C?**  
    a) *  
    **b) &**  
    c) ->  
    d) . (dot)  

18. **What does the indirection operator (*) do in C?**  
    **a) It dereferences a pointer to access the value stored in the memory location**  
    b) It gets the address of a variable  
    c) It assigns a new value to a variable  
    d) It multiplies two variables  

#### 4.4.3 Pointer Expression and Assignment

19. **Which of the following correctly assigns the address of a variable to a pointer?**  
    a) p = *var;  
    **b) p = &var;**  
    c) &p = var;  
    d) p = var;  

#### 4.4.4 Call by Value and Call by Reference

20. **In which method does the called function receive a copy of the argument’s value?**  
    **a) Call by value**  
    b) Call by reference  
    c) Call by pointer  
    d) Call by function  

21. **In which method does the called function receive the address of the argument?**  
    a) Call by value  
    **b) Call by reference**  
    c) Call by copy  
    d) Call by function  

### 4.5 Working with Files

#### 4.5.1 Concept of Data File

22. **Which of the following is used to store data permanently in C programming?**  
    a) Variables  
    b) Arrays  
    **c) Files**  
    d) Functions  

#### 4.5.2 Sequential and Random File

23. **Which type of file access reads data in order, from start to finish?**  
    **a) Sequential access**  
    b) Random access  
    c) Indexed access  
    d) Ordered access  

24. **In random file access, data can be...**  
    **a) Accessed in any order**  
    b) Only accessed sequentially  
    c) Accessed with indices only  
    d) Stored but not read  

#### 4.5.3 File Manipulation Functions

25. **Which function is used to write an integer to a file in C?**  
    **a) putw()**  
    b) getw()  
    c) putc()  
    d) getc()  

26. **Which function is used to read a single character from a file in C?**  
    a) putw()  
    b) fprintf()  
    c) fscanf()  
    **d) getc()**  

#### 4.5.4 Opening, Reading, Writing, and Appending Data File

27. **Which mode is used to open a file for both reading and writing in C?**  
    a) r  
    **b) r+**  
    c) w  
    d) w+  

28. **Which function is used to write formatted output to a file in C?**  
    a) putw()  
    b) getw()  
    **c) fprintf()**  
    d) getc()  

---
