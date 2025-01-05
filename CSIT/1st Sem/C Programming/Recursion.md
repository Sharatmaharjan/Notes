### **1. Factorial Calculation**  
**Problem**: Write a recursive function to compute the factorial of a number \( n \).  

**Source Code**:  
```c
#include <stdio.h>

int factorial(int n) {
    if (n == 0) // Base case
        return 1;
    return n * factorial(n - 1); // Recursive case
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0)
        printf("Factorial of negative number is not defined.\n");
    else
        printf("Factorial of %d is %d\n", n, factorial(n));

    return 0;
}
```

**Explanation**:  
- Base case: \( n = 0 \), return 1.  
- Recursive case: Multiply \( n \) with `factorial(n-1)`.  

**Sample Output**:  
```
Enter a number: 5  
Factorial of 5 is 120  
```

---

### **2. Fibonacci Sequence**  
**Problem**: Generate the first \( n \) Fibonacci numbers using recursion.  

**Source Code**:  
```c
#include <stdio.h>

int fibonacci(int n) {
    if (n == 0)
        return 0; // Base case
    else if (n == 1)
        return 1; // Base case
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci sequence: ");
    for (int i = 0; i < n; i++)
        printf("%d ", fibonacci(i));

    return 0;
}
```

**Explanation**:  
- Base case: Return 0 for \( n = 0 \) and 1 for \( n = 1 \).  
- Recursive case: \( F(n) = F(n-1) + F(n-2) \).  

**Sample Output**:  
```
Enter the number of terms: 6  
Fibonacci sequence: 0 1 1 2 3 5  
```

---

### **3. Sum of Digits**  
**Problem**: Write a recursive function to find the sum of the digits of a number.  

**Source Code**:  
```c
#include <stdio.h>

int sumOfDigits(int n) {
    if (n == 0) // Base case
        return 0;
    return n % 10 + sumOfDigits(n / 10); // Recursive case
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Sum of digits of %d is %d\n", n, sumOfDigits(n));
    return 0;
}
```

**Explanation**:  
- Base case: \( n = 0 \), return 0.  
- Recursive case: Add the last digit (\( n\%10 \)) to the sum of the remaining digits (\( n/10 \)).  

**Sample Output**:  
```
Enter a number: 123  
Sum of digits of 123 is 6  
```

---

### **4. Reverse a String**  
**Problem**: Write a recursive function to reverse a string.  

**Source Code**:  
```c
#include <stdio.h>
#include <string.h>

void reverseString(char str[], int start, int end) {
    if (start >= end) // Base case
        return;
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverseString(str, start + 1, end - 1); // Recursive case
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    reverseString(str, 0, strlen(str) - 1);
    printf("Reversed string: %s\n", str);

    return 0;
}
```

**Explanation**:  
- Base case: Stop when the start index is greater than or equal to the end index.  
- Recursive case: Swap the characters at the `start` and `end` indices, then recursively call for the next indices.  

**Sample Output**:  
```
Enter a string: hello  
Reversed string: olleh  
```

---

### **5. GCD of Two Numbers**  
**Problem**: Implement a recursive function to find the greatest common divisor (GCD) of two numbers.  

**Source Code**:  
```c
#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) // Base case
        return a;
    return gcd(b, a % b); // Recursive case
}

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
    return 0;
}
```

**Explanation**:  
- Base case: If \( b = 0 \), return \( a \).  
- Recursive case: \( \text{GCD}(a, b) = \text{GCD}(b, a \% b) \).  

**Sample Output**:  
```
Enter two numbers: 36 24  
GCD of 36 and 24 is 12  
```

---

### **6. Power of a Number**  
**Problem**: Write a recursive function to calculate \( a^b \).  

**Source Code**:  
```c
#include <stdio.h>

int power(int a, int b) {
    if (b == 0) // Base case
        return 1;
    return a * power(a, b - 1); // Recursive case
}

int main() {
    int a, b;
    printf("Enter base and exponent: ");
    scanf("%d %d", &a, &b);

    printf("%d^%d = %d\n", a, b, power(a, b));
    return 0;
}
```

**Explanation**:  
- Base case: If \( b = 0 \), return 1.  
- Recursive case: Multiply \( a \) with `power(a, b-1)`.  

**Sample Output**:  
```
Enter base and exponent: 2 3  
2^3 = 8  
```

---
