# **UNIT 4 – OPERATORS AND EXPRESSIONS: LAB ASSIGNMENT**

## **A. BASIC OPERATOR APPLICATIONS**

---

### **1. Converting Days into Months and Days**

**Task:**
Write a program to convert a given number of days into months and remaining days using arithmetic operators.

**Sample Input:**

```
75
```

**Sample Output:**

```
Enter number of days:
Months = 2   Days = 15
```

**Application:**
Used in time-tracking systems such as employee attendance summaries.

---

### **2. Summing the Digits of a 5-Digit Positive Integer**

**Task:**
Write a program to extract and sum the digits of a 5-digit number using modulo and division operators.

**Sample Input:**

```
54321
```

**Sample Output:**

```
Sum = 15
```

**Application:**
Used in checksum verifications or basic numeric validations.

---

### **3. Finding the Larger of Two Numbers Using the Conditional (Ternary) Operator**

**Task:**
Use the ternary operator to determine the larger of two integers.

**Sample Input:**

```
Enter two numbers: 20 35
```

**Sample Output:**

```
The larger number is 35
```

**Application:**
Used in decision-making steps in embedded systems or sensor comparisons.

---

### **4. Demonstrating the Use of the `sizeof()` Operator**

**Task:**
Write a program to display the memory size of basic data types.

**Sample Output:**

```
Size of int = 4 bytes
Size of float = 4 bytes
Size of double = 8 bytes
Size of long int = 8 bytes
```

**Application:**
Important in memory-critical applications, such as embedded development.

---

## **B. ARITHMETIC & ASSIGNMENT OPERATORS**

---

### **5. Evaluate a Complex Arithmetic Expression**

**Task:**
Read values of `a`, `b`, and `c` and compute an expression such as:

```
result = (a + b) * c - a / b;
```

**Sample Output:**

```
Enter values of a, b, c:
Computed result = ___
```

**Application:**
Used in calculators, financial computations, and simulation formulas.

---

### **6. Demonstrate Compound Assignment Operators**

**Task:**
Write a program that uses `+=`, `-=`, `*=`, `/=`, and `%=` on a variable and displays the change after each operation.

**Sample Output:**

```
After += : ___
After -= : ___
After *= : ___
After /= : ___
After %= : ___
```

**Application:**
Used in loops, aggregations, and iterative algorithms.

---

## **C. RELATIONAL & LOGICAL OPERATORS**

---

### **7. Checking Eligibility Using Relational Operators**

**Task:**
Write a program that checks if a person is eligible to vote (`age >= 18`).

**Sample Input:**

```
Enter age: 17
```

**Sample Output:**

```
You are not eligible to vote.
```

**Application:**
Used in authentication systems, access control, or form validation.

---

### **8. Demonstrate Logical Operators (AND, OR, NOT)**

**Task:**
Check whether a number is both positive AND even.

**Sample Input:**

```
Enter number: 12
```

**Sample Output:**

```
The number is positive and even.
```

**Application:**
Used in condition checking in computer security and filtering systems.

---

## **D. INCREMENT/DECREMENT & EXPRESSION EVALUATION**

---

### **9. Demonstrate Pre-Increment and Post-Increment**

**Task:**
Write a program to illustrate differences between:

```
++a   a++
--a   a--
```

**Sample Output:**

```
Before increment: 5
After ++a: 6
After a++: 6 (then becomes 7)
```

**Application:**
Used in loops, counters, and iterative logic in compilers.

---

### **10. Evaluate Expression with Mixed Operators**

**Task:**
Predict and display the output of:

```
int a = 5, b = 10, c;
c = a++ + --b * a;
```

**Sample Output:**

```
Value of c = ___
```

**Application:**
Demonstrates operator precedence—important in debugging numeric logic.

---

## **E. BITWISE OPERATORS**

---

### **11. Demonstrate Bitwise AND, OR, XOR, NOT, Left and Right Shifts**

**Task:**
Write a program that takes two integers and displays:

* `a & b`
* `a | b`
* `a ^ b`
* `~a`
* `a << 1`
* `a >> 1`

**Sample Input:**

```
Enter two integers: 5 3
```

**Sample Output:**

```
a & b = 1
a | b = 7
a ^ b = 6
~a = -6
a<<1 = 10
a>>1 = 2
```

**Application:**
Used in cryptography, compression algorithms, and low-level hardware control.

---

## **F. SPECIAL OPERATORS**

---

### **12. Demonstration of the Comma Operator**

**Task:**
Write a program using the comma operator inside an expression:

```
result = (a = 5, b = 10, a + b);
```

**Sample Output:**

```
Value of result = 15
```

**Application:**
Useful in for-loops and compact expressions.

---

### **13. Demonstrate the Use of `sizeof()` with Variables and Expressions**

**Task:**
Input any variable type and display its size using `sizeof(var)`.

**Sample Output:**

```
Enter an integer:
Size of the variable = 4 bytes
```

**Application:**
Used in memory allocation and portability checks.

---

## **G. TERNARY / CONDITIONAL OPERATOR**

---

### **14. Classify a Number as Positive, Negative, or Zero**

**Task:**
Using only the ternary operator, determine whether a number is positive, negative, or zero.

**Sample Input:**

```
0
```

**Sample Output:**

```
The number is zero.
```

**Application:**
Used in input validation and classification routines.

---

## **H. OPERATOR PRECEDENCE & ASSOCIATIVITY**

---

### **15. Evaluate Expressions with Different Precedence**

**Task:**
Predict the result of:

```
a = 10;
b = 20;
c = a + b * 2 - a / 2;
```

**Sample Output:**

```
Value of c = ___
```

**Application:**
Helps understand how compilers interpret expressions.

---
