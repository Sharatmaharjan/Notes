# **UNIT 3: Input and Output – LAB ASSIGNMENT**

## **A. FORMATTED INPUT/OUTPUT**

### **a. Using `scanf()` – Formatted Input**

---

### **1. Handling Whitespace Characters in `scanf()`**

**Task:**
Write a program to demonstrate how whitespace characters (such as newline) affect character input using `scanf()`, especially when reading a character after a number.

**Hint:**
`%c` does not skip whitespace. Use a space before `%c` to ignore leftover newlines.

**Sample Input:**

```
5
a
```

**Sample Output:**

```
Enter a number:
Enter a character:
Number=5      Character=a
```

**Application:**
Useful in forms or interactive inputs where multiple fields are entered one after another.

---

### **2. Reading Structured Input Using Ordinary Characters**

**Task:**
Write a program to parse a date input such as `dd/mm/yyyy` using ordinary characters (like `/`) inside the `scanf()` control string.

**Sample Input:**

```
15/06/1995
```

**Sample Output:**

```
Enter your date of birth separated by / :
Your date of birth is: 15 day  6 month  1995 year.
```

**Application:**
Used in systems that accept structured inputs such as dates, timestamps, or IDs.

---

### **3. Restricting Input Using Field Width in `scanf()`**

**Task:**
Write a program to read marks limited to two digits using `%2d`.

**Sample Input 1:**

```
85
```

**Sample Output 1:**

```
Enter your marks in C:
Your entered marks=85
```

**Sample Input 2:**

```
123
```

**Sample Output 2:**

```
Enter your marks in C:
Your entered marks=12
```

**Application:**
Useful when data ranges must be controlled, such as student marks or inventory counts.

---

### **4. Skipping an Input Field Using `*` in `scanf()`**

**Task:**
Write a program to skip the second input value using `%*d`.

**Sample Input:**

```
10 20 30
```

**Sample Output:**
(c may vary depending on compiler)

```
Enter three numbers:
a=10      b=30      c=0
```

**Application:**
Used for ignoring unnecessary fields when importing or processing semi-structured data.

---

### **5. Reading and Displaying a Single-Word String**

**Task:**
Write a program to input and display a single-word string using `scanf()` and `printf()`.

**Sample Input:**

```
Sharat
```

**Sample Output:**

```
Enter your name:
Your name is: Sharat
```

**Application:**
Used in login prompts or command inputs.

---

### **6. Reading Uppercase-Only Strings**

**Task:**
Write a program that reads only uppercase letters using `%[A-Z]`.

**Sample Input:**

```
SHARAT123
```

**Sample Output:**

```
Enter your name in uppercase:
Your name is: SHARAT
```

**Application:**
Used in systems that require uppercase codes or identifiers.

---

### **7. Reading Multi-Word Strings Using scanf**

**Task:**
Write a program to input a full name (including spaces) using `%[^\n]`.

**Sample Input:**

```
Sharat Maharjan
```

**Sample Output:**

```
Enter your full name:
Your name is: Sharat Maharjan
```

**Application:**
Used in forms requiring full names, addresses, or descriptions.

---

## **b. Using `printf()` – Formatted Output**

---

### **8. Integer and Float Formatting**

**Task:**
Predict the output of the given `printf()` statements involving width, padding, and precision.

```c
#include <stdio.h>

int main() {
    int n = 1234;
    float m = 12.31456;
    printf("n=%d", n);
    printf("\n n=%6d", n);
    printf("\n n=%2d", n);
    printf("\n n=%-6d", n);
    printf("\n n=%06d", n);
    printf("\n n=%.2f", m);
    return 0;
}
```

**Expected Output:**

```
 n=1234
 n=  1234
 n=1234
 n=1234  
 n=001234
 n=12.31
```

**Application:**
Useful in structured reports such as bills, tables, and financial summaries.

---

### **9. Character Formatting**

**Task:**
Predict the output of character formatting with left- and right-alignment.

```c
#include<stdio.h>
int main(){
    char ch='A';
    printf("ch=%2c",ch);
    printf("\nch=%5c",ch);
    printf("\nch=%-5c",ch);
    return 0;
}
```

**Expected Output:**

```
ch= A
ch=    A
ch=A    
```

**Application:**
Used in menu displays and aligned text outputs.

---

### **10. String Formatting**

**Task:**
Predict the output for string alignment, width, and precision settings.

```c
#include<stdio.h>
int main(){
    char str[10]="MY NEPAL";
    printf("%s",str);
    printf("\n%10s",str);
    printf("\n%-10s",str);
    printf("\n%.4s",str);
    printf("\n%4s",str);
    printf("\n%10.6s",str);
    printf("\n%-10.6s",str);
    return 0;
}
```
**Expected Output:**

```
MY NEPAL
  MY NEPAL
MY NEPAL  
MY N
MY NEPAL
    MY NEP
MY NEP    
```

**Application:**
Used in table formatting, logs, and structured display panels.

---

### **11. Displaying Multiple Data Types in One `printf()`**

**Task:**
Write a single `printf()` that prints an integer, a float, and a string.

**Sample Output:**

```
integer=10      float=2.500000      string=Sharat
```

**Application:**
Useful for combined debug logs and status displays.

---

## **B. UNFORMATTED INPUT/OUTPUT**

---

### **12. Using `getchar()` and `putchar()`**

**Task:**
Write a program to read a character using `getchar()` and display it using `putchar()`.

**Sample Input:**

```
M
```

**Sample Output:**

```
Enter your gender:
Your gender is:M
```

**Application:**
Used for simple prompts and interactive inputs.

---

### **13. Using `getch()` and `getche()`**

**Task:**
Write a program to read two characters—one hidden and one shown.

**Sample Output:**

```
Enter 1st character:
Enter 2nd character:y
1st character: x
2nd character: y
```

**Application:**
Used for PIN entry or game controls.

---

### **14. Reading a Line Using `gets()` and Displaying with `puts()`**

**Task:**
Write a program to read a full line using `gets()` and print it using `puts()`.

**Sample Input:**

```
Sharat Maharjan
```

**Sample Output:**

```
Enter your name:
Your name is:Sharat Maharjan
```

**Application:**
Used in chat inputs or form fields.

---
