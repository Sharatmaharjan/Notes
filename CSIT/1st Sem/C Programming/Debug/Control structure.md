### **1. Missing Braces in `if` Statement**
```c
#include <stdio.h>
int main() {
    int num = 10;
    if (num > 5)
        printf("The number is greater than 5\n");
        printf("This line should not execute if num <= 5\n");
    return 0;
}
```
**Question**: Why is the second `printf` executing even when `num <= 5`? Fix the issue.

---

### **2. Incorrect Use of `else if`**
```c
#include <stdio.h>
int main() {
    int x = 15;
    if (x > 10)
        printf("x is greater than 10\n");
    else if (x > 20)
        printf("x is greater than 20\n");
    else
        printf("x is 10 or less\n");
    return 0;
}
```
**Question**: The program never checks if `x > 20`. Why? How would you fix it?

---

### **3. Infinite Loop in `while`**
```c
#include <stdio.h>
int main() {
    int count = 0;
    while (count < 5) {
        printf("%d\n", count);
    }
    return 0;
}
```
**Question**: Why does this program result in an infinite loop? Fix the issue.

---

### **4. Logical Error in `for` Loop**
```c
#include <stdio.h>
int main() {
    for (int i = 1; i <= 10; i++);
        printf("i = %d\n", i);
    return 0;
}
```
**Question**: Why does this program give a compilation error? Fix the issue.

---

### **5. Misuse of `switch` Statement**
```c
#include <stdio.h>
int main() {
    int num = 2;
    switch (num) {
        case 1:
            printf("One\n");
        case 2:
            printf("Two\n");
        case 3:
            printf("Three\n");
        default:
            printf("Default\n");
    }
    return 0;
}
```
**Question**: Why does this program print multiple outputs? Modify the program to print only the correct case.

---

### **6. Incorrect Condition in `do-while` Loop**
```c
#include <stdio.h>
int main() {
    int n = 5;
    do {
        printf("Value of n: %d\n", n);
    } while (n > 10);
    return 0;
}
```
**Question**: Why does the loop execute even though `n > 10` is false? Fix the issue.

---

### **7. Logical Error in Nested `if-else`**
```c
#include <stdio.h>
int main() {
    int a = 5, b = 10, c = 15;
    if (a > b)
        if (b > c)
            printf("a is the largest\n");
        else
            printf("c is the largest\n");
    else
        printf("b is the largest\n");
    return 0;
}
```
**Question**: Why is the program's output incorrect? Fix the logic.

---

### **8. Use of Break in Loops**
```c
#include <stdio.h>
int main() {
    for (int i = 0; i < 5; i++) {
        if (i == 3)
            break;
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
```
**Question**: What will the output be? Modify the code so the loop skips `3` but continues to print other numbers.

---

### **9. Wrong Condition in `if`**
```c
#include <stdio.h>
int main() {
    int x = 0;
    if (x = 1) {
        printf("x is 1\n");
    } else {
        printf("x is not 1\n");
    }
    return 0;
}
```
**Question**: Why does the program always print "x is 1"? Fix the issue.

---

### **10. Skipping Iterations in `for` Loop**
```c
#include <stdio.h>
int main() {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0)
            continue;
        printf("%d ", i);
    }
    return 0;
}
```

---

These questions are designed to help students identify common bugs and improve debugging skills in control structures.
