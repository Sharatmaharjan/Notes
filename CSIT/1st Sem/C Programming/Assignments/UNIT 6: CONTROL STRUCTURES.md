# UNIT 6: CONTROL STRUCTURES


## A. Decision Making Statements

*(if, if–else, nested if, else–if ladder, switch)*

---

### 1. Negative Number Check

**Question:**
Write a program to check whether the entered number is negative.

**Hint:**
Use a simple `if` condition to compare the number with zero.

**Sample Output:**

```
Enter a number: -5  
The number -5 is negative.
```

---

### 2. Even or Odd

**Question:**
Write a program to determine whether a given number is even or odd.

**Hint:**
Use the modulus (`%`) operator.

**Sample Output:**

```
Enter a number: 7  
The number 7 is odd.
```

---

### 3. Profit or Loss

**Question:**
Write a program to input cost price and selling price and determine profit or loss.

**Hint:**
Compare selling price with cost price.

**Sample Output:**

```
Enter CP: 500  
Enter SP: 650  
Profit amount = 150
```

---

### 4. Roots of Quadratic Equation

**Question:**
Write a program to find the roots of a quadratic equation.

**Hint:**
Calculate discriminant `b² − 4ac` and check its nature.

**Sample Output:**

```
Roots are real  
Root1 = 2.00  
Root2 = 3.00
```

---

### 5. Smallest of Three Numbers

**Question:**
Write a program to find the smallest among three numbers.

**Hint:**
Use `&&` operator in conditions.

**Sample Output:**

```
Enter three numbers: 4 2 9  
2 is the smallest number.
```

---

### 6. Percentage and Grade

**Question:**
Write a program to compute percentage and grade of a student based on marks of three subjects.

percentage>=80 grade = A
percentage<80 and per>=60 grade = B
percentage<60 and per>=50 grade = C
percentage<50 and per>=40 grade = D
percentage<40 grade = F

**Hint:**
Use else–if ladder for grading conditions.

**Sample Output:**

```
Percentage = 72.50  
Grade = B
```

---

### 7. Largest Using Logical Operator

**Question:**
Write a program to find the largest of three numbers using logical operators.

**Hint:**
Use `&&` operator in conditions.

**Sample Output:**

```
Largest number is 25
```

---

### 8. Switch Fall-Through Output

**Question:**
Predict the output of a given switch–case program.

**Hint:**
Observe missing `break` statements carefully.


```c
#include<stdio.h>
int main(){
  int n;
  printf("Enter a number:");
  scanf("%d",&n);
  switch(n){
    case 1:
    case 2:
      printf("1 or 2?");
      break;
    case 3:
    case 4:
      printf("3 or 4?");
    case 5:
    case 6:
      printf("5 or 6?");
      printf("or may be 3 or 4?");
      break;
    default:
      printf("Invalid choice.");
    }
  return 0;
}
```

**Sample Output:**

```
5 or 6? or may be 3 or 4?
```

---

### 9. Menu Using Switch

**Question:**
Write a program that demonstrates the use of switch statement with menu options: Select 1 for FACEBOOK, 2 for TWITTER and 3 for INSTAGRAM.

**Hint:**
Use `switch(choice)` and default case.

**Sample Output:**

```
You use FACEBOOK.
```

---

### 10. Arithmetic Operations Using Switch

**Question:**
Write a program to perform arithmetic operations between two numbers using switch statement.
Menu: Select + to add, - to subtract, * to multiply and / to divide.

**Hint:**
Use character input for operator selection.

**Sample Output:**

```
Sum of two numbers = 30
```

---

## B. Iteration Statements

*(for, while, do–while)*

---

### 11. Print Numbers 1 to 10

**Question:**
Write a program to print numbers from 1 to 10 using for loop.

**Hint:**
Initialize loop variable from 1 to 10.

**Sample Output:**

```
1 2 3 4 5 6 7 8 9 10
```

---

### 12. Factorial of a Number

**Question:**
Write a program to calculate factorial of a number using for loop.

**Hint:**
Use multiplication inside loop.

**Sample Output:**

```
Factorial of 5 is 120
```

---

### 13. Sum of 1 to 100

**Question:**
Write a program to calculate sum of integers from 1 to 100.

**Hint:**
Use accumulator variable.

**Sample Output:**

```
Sum = 5050
```

---

### 14. Sum and Average of Marks

**Question:**
Write a program to find sum and average of five subjects using for loop.

**Hint:**
Use loop to read marks.

**Sample Output:**

```
Total = 350  
Average = 70
```

---

### 15. Sum of Digits

**Question:**
Write a program to find the sum of digits of a number using while loop.

**Hint:**
Use modulus and division.

**Sample Output:**

```
Sum of digits = 15
```

---

### 16. Armstrong Number

**Question:**
Write a program to check whether a number is an Armstrong number.

**Hint:**
Cube each digit and compare sum.

**Sample Output:**

```
153 is an Armstrong number.
```

---

### 17. Reverse of a Number

**Question:**
Write a program to reverse a given number.

**Hint:**
Use while loop with remainder logic.

**Sample Output:**

```
Reverse number = 4321
```

---

### 18. Palindrome Number

**Question:**
Write a program to check whether a number is palindrome.

**Hint:**
Compare original and reversed number.

**Sample Output:**

```
121 is a palindrome number.
```

---

### 19. Do-While Printing

**Question:**
Write a program to print numbers 1 to 10 using do-while loop.

**Hint:**
Ensure loop runs at least once.

**Sample Output:**

```
1 2 3 4 5 6 7 8 9 10
```

---


## C. Jump Statements

---

### 20. break Statement

**Question:**
Write a program to demonstrate use of break statement.

**Hint:**
Exit loop when condition is met.

**Sample Output:**

```
1 2 3
```

---

### 21. continue Statement

**Question:**
Write a program to demonstrate continue statement.

**Hint:**
Skip current iteration.

**Sample Output:**

```
1 3 4 5 6 7 8 9 10
```

---

### 22. goto Statement

**Question:**
Write a program to print numbers using goto without loop.

**Hint:**
Use label and conditional goto.

**Sample Output:**

```
1 2 3 4 5 6 7 8 9 10
```

---

## D. Pattern & Practice Programs

---

### 23. Number Triangle

**Question:**
Display a triangle where each row prints the row number.

**Hint:**
Use nested loops.

**Sample Output:**

```
1  
2 2  
3 3 3
```

---

### 24. Multiplication Table Pattern

**Question:**
Display multiplication tables from 1 to 5.

**Hint:**
Outer loop for rows, inner for columns.

**Sample Output:**

```
1 2 3 4 5  
2 4 6 8 10
```

---

### 25. Prime Number

**Question:**
Write a program to check whether a number is prime.

**Hint:**
Check divisibility from 2 to n−1.

**Sample Output:**

```
7 is a prime number.
```

---
