## 1. Programming Language : 10 hrs

1. **Explain the different types of programming languages and provide examples of each. Discuss their respective uses and characteristics.**

2. **What is a language processor? Explain the various types of language processors and their functions in the compilation and execution of programs.**

3. **Discuss the common types of program errors that occur during software development. Explain how these errors can be identified and rectified.**

4. **What are the key features of a good program? Discuss how these features contribute to the maintainability, efficiency, and readability of the code.**

5. **Describe the different programming paradigms (e.g., procedural, object-oriented, functional). Explain how each paradigm influences the way software is designed and implemented.**

---

## 2. Programming Technique : 5 hrs


1. **Explain the difference between the top-down and bottom-up approaches in software development. Discuss the advantages and disadvantages of each approach.**

2. **What are cohesion and coupling in software design? Explain the difference between them and discuss how they influence the maintainability of a system.**

3. **Define structured programming. Discuss its key principles and how it improves the clarity and reliability of software development.**

4. **Differentiate between deterministic and non-deterministic techniques in programming. Provide examples where each technique might be applied.**

5. **Explain the concepts of iterative and recursive logic. How do they differ in terms of their approach and applications in problem-solving?**

---

## 3. Basic concept of C : 5 hrs


1. **Briefly explain the history of the C programming language. Discuss its evolution and the key factors that contributed to its widespread use.**

2. **What are the advantages and disadvantages of using the C programming language? Provide examples where C is particularly useful and situations where it might be less suitable.**

3. **Describe the structure of a C program. Explain the purpose of each part, including the main function, preprocessor directives, and the role of header files.**

4. **What are tokens in C programming? Explain the different types of tokens (keywords, identifiers, constants, operators, and separators) with examples.**

5. **Explain the role of preprocessor directives in C. Discuss common directives like `#include`, `#define`, and `#if`, and how they are used in C programs.**

---

## 4. Input and Output : 3 hrs


1. **Explain the concept of input and output operations in C programming. What are the basic functions used for input and output in C?**

2. **Discuss the difference between formatted and unformatted input/output in C. Provide examples of functions used for each type and explain their usage.**

3. **Describe the `scanf` and `printf` functions in C. How are they used for formatted input and output operations? Provide an example program that demonstrates their usage.**

4. **What are the differences between unformatted input functions like `getch()`, `getche()`, and `getchar()`? Provide examples of when each function would be used.**

5. **Explain the `puts()` and `gets()` functions in C. What are their purposes, and what are the potential risks of using `gets()` in a program?**

---

## 5. Operators and Expressions : 3 hrs


1. **Explain the different types of operators in C. Discuss the functionality and provide examples for arithmetic, relational, and logical operators.**

2. **What are increment/decrement operators in C? Explain their usage and how they differ when used as prefix or postfix in expressions. Provide examples.**

3. **Describe the conditional operator in C. How does it differ from the regular `if-else` statement? Provide an example where the conditional operator is used effectively.**

4. **What is the purpose of bitwise operators in C? Explain how they work with examples for bitwise AND, OR, XOR, and NOT operations.**

5. **What is operator precedence and associativity in C? How do they affect the evaluation of expressions? Explain with an example that demonstrates operator precedence and type casting in expressions.**

---

## 6. Control Structure : 6 hrs


1. **Write a C program to implement a menu-driven calculator using `switch-case` to perform the following operations: addition, subtraction, multiplication, division, and modulus. The program should handle invalid inputs and allow the user to continue performing operations until they choose to exit.**

2. **Write a C program that reads a sequence of integers from the user and uses a `while` loop to find the second largest number in the sequence. The program should handle cases where there are duplicates.**

3. **Write a C program to implement a `for` loop that calculates the factorial of a number recursively and iteratively. Compare the two methods in terms of performance and output.**

4. **Write a C program that uses `nested loops` and `if-else` to print a pyramid pattern with asterisks (`*`). The program should take an integer input from the user to determine the height of the pyramid. Example output for height.**

   ```
      *
     ***
    *****
   *******

   


5. **Write a C program that simulates a simple banking system using `switch-case`. The program should allow the user to create an account, deposit money, withdraw money, check balance, and exit. The program should also handle error checking for invalid amounts and negative balances.**

---

## 7. Array : 6 hrs


1. **Write a C program to declare, initialize, and print the elements of a one-dimensional array. Also, implement a function to find the maximum and minimum values in the array.**

2. **Write a C program to perform bubble sort on a one-dimensional array of integers. The program should sort the array in both ascending and descending order based on user input.**

3. **Write a C program that implements a function to perform a sequential search on a one-dimensional array to find a specific element entered by the user. If the element is found, return its position; otherwise, return a message indicating that the element was not found.**

4. **Write a C program to declare and initialize a two-dimensional array. Implement a function to add two matrices (2D arrays) and display the result.**

5. **Write a C program to reverse a string using a one-dimensional character array. Implement a function to print the string before and after reversal. Use string handling functions like `strlen` and `strcpy` in your solution.**

---

## 8. User Defined Function : 5 hrs


1. **Write a C program to demonstrate the difference between "Call By Value" and "Call By Reference" by using a function to modify the value of a variable. Show the results for both types of parameter passing.**

2. **Write a C program that uses recursion to find the factorial of a number. Then, modify the program to compute the factorial iteratively and compare both implementations.**

3. **Write a C program to define and use a user-defined function that accepts an array as an argument, computes the sum of all its elements, and returns the sum to the main function. Demonstrate both passing by value and by reference.**

4. **Write a C program to implement a function that reverses a string. Use pointers and pass the string to the function. Demonstrate the difference between passing a string to a function using a character pointer vs. an array.**

5. **Write a C program that uses macros to calculate the area of a circle and a rectangle. The program should accept the dimensions as inputs and display the results using the macro definition. Include error handling for invalid inputs.**

---

## 9. Pointer : 6 hrs

1. **Write a C program to demonstrate the use of the address (`&`) and indirection (`*`) operators by creating a pointer to an integer. Show how to modify the value of the integer using the pointer and print both the original value and the modified value.**

2. **Write a C program to implement a function that accepts a pointer to a pointer as an argument. The function should modify the value of the original variable via the pointer-to-pointer and display the updated value.**

3. **Write a C program to demonstrate pointer arithmetic by creating an array of integers and using a pointer to traverse the array. Perform operations like incrementing, decrementing, and accessing elements using pointer arithmetic.**

4. **Write a C program that accepts an array of integers and uses pointers to pass the array to a function. The function should calculate the sum of the array elements and return the result. Demonstrate how pointer arithmetic is used in this process.**

5. **Write a C program to dynamically allocate memory for an array of integers using `malloc()` and `free()`. The program should take input from the user, store the values in the dynamically allocated memory, and then display the values before freeing the memory.**

---

## 10. Structure : 5 hrs



1. **Write a C program to define a structure that represents a "Student" with fields for name, roll number, and marks. Then, initialize an array of structures with data for multiple students and display their details.**

2. **Write a C program to demonstrate the use of a nested structure. Define a structure for "Employee" that contains another structure "Address" with fields like street, city, and zip code. Initialize and display the details of an employee and their address.**

3. **Write a C program to define a structure "Book" with fields for title, author, and price. Create an array of structures to hold details of 5 books. Then, write a function to pass this array of structures and display the information of all books.**

4. **Write a C program to demonstrate the use of structure pointers. Define a structure for a "Rectangle" with fields for length and breadth, and use a pointer to access and modify these values in the main function.**

5. **Write a C program to explain the difference between structure and union by defining a structure and a union both representing a "Shape" with fields for area and type. Demonstrate how memory is allocated differently for a structure and a union and display the size of both.**

---

## 11. Data File Handling : 4 hrs


1. **Write a C program to demonstrate the process of opening and closing a file. The program should create a file, write some text to it, and then close the file. Additionally, show how to check if the file was successfully opened.**

2. **Write a C program that reads a list of integers from a file, sums them, and displays the result. Implement error handling for file opening and reading errors.**

3. **Write a C program to write a list of names and corresponding phone numbers into a text file. The program should allow the user to update the phone number for a given name by opening the file, reading its contents, modifying the record, and writing the updated information back to the file.**

4. **Write a C program to implement random access file handling. Create a structure to store a record of a student (name, roll number, and marks), then read and write student records at random positions in a binary file using `fseek()` and `ftell()`.**

5. **Write a C program to read a file containing student information and print the contents to the screen. Each student’s record should include their name, roll number, and marks, which should be read from the file and printed in a formatted manner.**

---

## 12. Introduction to Graphics : 2 hrs


1. **Write a C program to initialize the graphics mode and draw a simple geometric shape (such as a rectangle or circle) on the screen using the `graphics.h` library. Show the process of initializing the graphics mode and closing it after the shape is drawn.**

2. **Write a C program that initializes the graphical mode and draws a line from one point to another on the screen using the `line()` function from the `graphics.h` library. Include error handling for initializing the graphics mode.**

3. **Write a C program to display a filled circle and a filled rectangle on the screen. Use appropriate graphical functions to set colors and fill the shapes, and ensure proper initialization and de-initialization of the graphical mode.**

4. **Write a C program that initializes graphical mode, then draws multiple shapes (circle, rectangle, and line) on the screen with different colors. Afterward, display the shapes in sequence with delays using the `delay()` function.**

5. **Write a C program to create a simple graphical user interface (GUI) element, such as a button or a clickable shape. When the shape is clicked, change its color or position. Use mouse events and graphical functions from the `graphics.h` library.**

---
