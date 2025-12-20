# UNIT 5: CONTROL STRUCTURES/STATEMENTS


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

# ADDITIONAL CONTROL STRUCTURE & PATTERN QUESTIONS

## 1. Skipping a Specific Term in a Series

**Question:**
Write a program to display the following series up to **25 terms**, but **do not print the 7th term**:
2 × 3, 3 × 5, 4 × 7, 5 × 9, …

**Hint:**

* Use a loop counter to generate terms
* Use `continue` to skip the 7th term

**Sample Output:**

```
2 x 3
3 x 5
4 x 7
5 x 9
...
(Skips 7th term)
...
```

---

## 2. Power Calculation Without Using pow()

**Question:**
Write a program to calculate the value of ( x^y ) without using the `pow()` function.

**Hint:**

* Use a loop to multiply `x` repeatedly
* Initialize result as 1

**Sample Output:**

```
Enter x: 2
Enter y: 4
Result = 16
```

---

## 3. Menu-Driven Program Using Character Choice

**Question:**
Write a menu-driven program that performs the following operations based on user choice:

A. Find Odd or Even
B. Find Positive or Negative
C. Find Factorial
D. Exit

The menu should repeat until the user selects **D**.

**Hint:**

* Use `do-while` loop
* Use `switch` with character input

**Sample Output:**

```
Enter choice: A
Number is Even

Enter choice: C
Factorial = 120

Enter choice: D
Program terminated.
```

---

## 4. Harmonic Series

**Question:**
Write a program to display the **n terms of harmonic series** and also display their sum.

Series:
1 + 1/2 + 1/3 + 1/4 + … + 1/n

**Hint:**

* Use `float` variables
* Accumulate sum inside loop

**Sample Output:**

```
1 + 1/2 + 1/3 + 1/4
Sum = 2.0833
```

---

## 5. Sum of Repeated Digit Series

**Question:**
Write a program to find the sum of the series:
9 + 99 + 999 + 9999 + …

**Hint:**

* Build the number progressively
* Add each term to sum

**Sample Output:**

```
Enter number of terms: 4
Sum = 11106
```

---

# PATTERN QUESTIONS

---

## 6. Right-Angle Triangle of Stars

**Question:**
Write a program to print a right-angle triangle of stars.

**Hint:**

* Use nested loops
* Inner loop depends on row number

**Sample Output:**

```
*
**
***
****
*****
```

---

## 7. Inverted Right-Angle Triangle

**Question:**
Write a program to print an inverted right-angle triangle using stars.

**Hint:**

* Outer loop decreases
* Inner loop prints stars

**Sample Output:**

```
*****
****
***
**
*
```

---

## 8. Square Pattern of Stars

**Question:**
Write a program to print a square pattern of stars.

**Hint:**

* Use same loop limits for rows and columns

**Sample Output:**

```
*****
*****
*****
*****
*****
```

---

## 9. Centered Star Pyramid

**Question:**
Write a program to display a centered pyramid of stars.

**Hint:**

* Use spaces before stars
* Stars follow odd-number pattern

**Sample Output:**

```
    *
   ***
  *****
 *******
*********
```

---

## 10. Inverted Pyramid of Stars

**Question:**
Write a program to display an inverted pyramid of stars.

**Hint:**

* First print spaces, then stars
* Decrease star count each row

**Sample Output:**

```
*********
 *******
  *****
   ***
    *
```

---

## 11. Diamond Pattern

**Question:**
Write a program to print a diamond pattern using stars.

**Hint:**

* Combine pyramid and inverted pyramid

**Sample Output:**

```
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
```

---

## 12. Hollow Square Pattern

**Question:**
Write a program to display a hollow square of stars.

**Hint:**

* Print stars only on boundary positions

**Sample Output:**

```
*****
*   *
*   *
*   *
*****
```

---

## 13. Number Pyramid

**Question:**
Write a program to display a number pyramid.

**Hint:**

* Numbers start from 1 in each row

**Sample Output:**

```
    1
   12
  123
 1234
12345
```

---

# OUTPUT-BASED

**14. Trace the output**

```c
#include<conio.h>
#include<stdio.h>
void main(){
  int i =0,k;
  for(k=5;k>=0;k–){
    i=i+k;
  }
  printf(“%d\t”,i);
  getch();
}
```

---


## 15. Sales Commission Calculation

**Question:**
Write a C program to input the total sales amount of a salesperson and calculate the commission using a slab-wise commission system according to the following rules:

| Sales Amount        | Commission    |
| ------------------- | ------------- |
| Below 10000         | No commission |
| ≥ 10000 and < 20000 | 20%           |
| ≥ 20000             | 30%           |

**Hint:**

* Use `if–else if` ladder
* Commission = sales × rate

**Sample Output:**

```
Enter sales amount: 15000
Commission = 1000
```

---

## 16. Temperature Condition Message

**Question:**
Write a program to input temperature and print message according to following conditions:

a) Ice – if temperature is less than 0
b) Water – if temperature is between 0 and 100
c) Steam – if temperature is more than 100

**Hint:**

* Use relational operators
* Order of conditions matters

**Sample Output:**

```
Enter temperature: 120
Steam
```

---

## 17. Menu-Driven Program Using Switch Case

**Question:**
Write a program to find the following using switch-case statement:

1. Area of rectangle
2. Simple interest
3. Volume of cube

**Hint:**

* Take user choice
* Perform calculation based on choice

**Sample Output:**

```
Enter choice: 2
Simple Interest = 450
```

---

## 18. Switch Case Operations on Number

**Question:**
Write a program using switch case to perform the following operations:

a. Find greater number between two numbers
b. Check whether a number is odd or even
c. Check whether a number is positive or negative

**Hint:**

* Use switch on user choice
* Use relational and modulus operators

**Sample Output:**

```
Enter choice: b
Enter number: 2
Number is Even
```

---

## 19. Electricity Billing System

**Question:**
Write a program for electricity authority to calculate total electricity charge according to the following conditions:

| Unit Consumed | Charge Rate      |
| ------------- | ---------------- |
| U ≤ 20        | Minimum Rs. 100  |
| 20 < U ≤ 40   | Rs. 6 per unit   |
| 40 < U ≤ 80   | Rs. 6.5 per unit |
| 80 < U ≤ 100  | Rs. 7 per unit   |
| U > 100       | Rs. 7.5 per unit |

**Hint:**

* Use slab-wise and cumulative calculation
* Apply minimum charge if applicable

**Sample Output:**

```
Units consumed: 65
Total Bill = Rs. 317.5
```

---

## 20. BMI Calculation

**Question:**

Write a program in C to calculate the Body Mass Index (BMI) of a person. The program should take the person's height in meters and weight in kilograms, compute BMI using the formula:

BMI = weight / (height * height)

After calculating BMI, use suitable if–else statements to display whether the person is:

Underweight (BMI < 18.5)

Healthy (18.5 ≤ BMI < 24.9)

Overweight (24.9 ≤ BMI < 29.9)

Obese (BMI ≥ 29.9)


Display the calculated BMI value up to two decimal places and the corresponding health result.

Sample Output – 1
```c
Enter height in meters: 1.72
Enter weight in kg: 65

BMI = 21.97
Result: Healthy
```

---

Sample Output – 2
```
Enter height in meters: 1.60
Enter weight in kg: 45

BMI = 17.57
Result: Underweight
```

---

Sample Output – 3
```
Enter height in meters: 1.68
Enter weight in kg: 79

BMI = 27.99
Result: Overweight
```

---

Sample Output – 4
```
Enter height in meters: 1.75
Enter weight in kg: 95

BMI = 31.02
Result: Obese
```

---

## 21. Number Guessing Game (Random Number from 1–100)

Question:

Write a C program to create a number guessing game. The computer should generate a random number between 1 and 100 using srand() and rand(). Then repeatedly ask the user to guess the number until the correct answer is found.

For every wrong guess:

display “Too High!” if the guess is greater than the number

display “Too Low!” if the guess is smaller than the number


The program should stop only when the user guesses the correct number and display the total number of attempts taken.

Hint:

Use srand(time(NULL)) to generate a different number each time

Use a loop (while or do-while) to repeat guessing

Store number of guesses in a counter

Compare user guess with random number using if–else


Sample Output:
```
Guess a number between 1 and 100: 50
Too High! Try again.

Guess a number between 1 and 100: 20
Too Low! Try again.

Guess a number between 1 and 100: 32
Too High! Try again.

Guess a number between 1 and 100: 27
Correct! You guessed the number in 4 attempts.
```

---

