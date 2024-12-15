

### **1. Basic Right-Angle Triangle of Stars**

This is one of the simplest patterns where stars are printed in a right-angle triangle shape.

#### Code:

```c
#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
```

#### Explanation:
- The outer loop runs from 1 to `n` (the number of rows).
- The inner loop prints the stars (`*`) starting from 1 in the first row, 2 in the second row, and so on.

#### Sample Output:

```
Enter the number of rows: 5
*
**
***
****
*****
```

---

### **2. Inverted Right-Angle Triangle of Stars**

This is the reverse of the previous pattern, where stars are printed in a descending order from the largest to the smallest.

#### Code:

```c
#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for(i = n; i >= 1; i--) {
        for(j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
```

#### Explanation:
- The outer loop runs from `n` to 1, printing stars in each row.
- The inner loop prints the stars accordingly.

#### Sample Output:

```
Enter the number of rows: 5
*****
****
***
**
*
```

---

### **3. Square Pattern of Stars**

This pattern prints a square with stars.

#### Code:

```c
#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter the number of rows and columns: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
```

#### Explanation:
- Both the outer and inner loops run from 1 to `n`, printing `n` stars in each row, thus forming a square.

#### Sample Output:

```
Enter the number of rows and columns: 5
*****
*****
*****
*****
*****
```

---

### **4. Star Pyramid (Centered)**

This pattern forms a pyramid shape, with stars printed in a centered format.

#### Code:

```c
#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for(j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
```

#### Explanation:
- The outer loop runs from 1 to `n` to print each row.
- The first inner loop prints spaces to center the stars.
- The second inner loop prints stars in an increasing pattern (1, 3, 5, ...).

#### Sample Output:

```
Enter the number of rows: 5
    *
   ***
  *****
 *******
*********
```

---

### **5. Inverted Pyramid of Stars**

This pattern prints an inverted pyramid with stars.

#### Code:

```c
#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for(i = n; i >= 1; i--) {
        for(j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for(j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
```

#### Explanation:
- The outer loop runs from `n` to 1 to print each row.
- The first inner loop prints spaces.
- The second inner loop prints stars in a decreasing pattern (9, 7, 5, ...).

#### Sample Output:

```
Enter the number of rows: 5
*********
 *******
  *****
   ***
    *
```

---

### **6. Diamond Pattern**

The diamond pattern combines both the pyramid and inverted pyramid to form a diamond shape.

#### Code:

```c
#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    // Upper part of diamond
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for(j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Lower part of diamond
    for(i = n - 1; i >= 1; i--) {
        for(j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for(j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
```

#### Explanation:
- The first part of the code prints the upper pyramid (increasing stars).
- The second part prints the inverted pyramid (decreasing stars).

#### Sample Output:

```
Enter the number of rows: 5
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

### **7. Hollow Square Pattern**

In this pattern, we print a square with hollow spaces inside.

#### Code:

```c
#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter the size of the square: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if(i == 1 || i == n || j == 1 || j == n) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
```

#### Explanation:
- If the current row or column is on the boundary of the square, a star is printed. Otherwise, a space is printed.

#### Sample Output:

```
Enter the size of the square: 5
*****
*   *
*   *
*   *
*****
```

---

### **8. Number Pyramid Pattern**

This pattern prints numbers in a pyramid shape.

#### Code:

```c
#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for(j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}
```

#### Explanation:
- The outer loop handles the rows.
- The inner loop prints numbers in each row starting from 1.

#### Sample Output:

```
Enter the number of rows: 5
    1
   12
  123
 1234
12345
```

---
