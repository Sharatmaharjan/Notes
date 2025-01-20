#### Unit 2: Tokens, Expressions and Control Structures [5 Hrs.]
### 1. **Primitive Data Types**
Java has built-in data types that represent basic values.

#### **Integers**
- **int**: Stores whole numbers (32-bit).
- **long**: Stores large integers (64-bit).

**Explanation:**
- `int` is commonly used to store integer values, while `long` is used for larger numbers.
- Example: `int x = 10;`

**Code Example:**
```java
public class IntegerExample {
    public static void main(String[] args) {
        int num = 10;
        System.out.println("Integer: " + num); // Output: Integer: 10
    }
}
```

**Output:**
```
Integer: 10
```

---

#### **Floating-Point Types**
- **float**: Stores single-precision floating-point numbers (32-bit).
- **double**: Stores double-precision floating-point numbers (64-bit).

**Explanation:**
- `float` is used when lower precision is enough. `double` provides more precision for calculations involving decimals.

**Code Example:**
```java
public class FloatExample {
    public static void main(String[] args) {
        float pi = 3.14f;  // 'f' denotes float
        double e = 2.71828;  // Default is double
        System.out.println("Float: " + pi);  // Output: Float: 3.14
        System.out.println("Double: " + e);  // Output: Double: 2.71828
    }
}
```

**Output:**
```
Float: 3.14
Double: 2.71828
```

---

#### **Characters**
- **char**: Stores single characters in 16-bit Unicode format.

**Explanation:**
- `char` is used to store individual characters enclosed in single quotes.

**Code Example:**
```java
public class CharExample {
    public static void main(String[] args) {
        char grade = 'A';
        System.out.println("Character: " + grade);  // Output: Character: A
    }
}
```

**Output:**
```
Character: A
```

---

#### **Booleans**
- **boolean**: Stores true or false.

**Explanation:**
- `boolean` is used for conditional statements and logical operations.

**Code Example:**
```java
public class BooleanExample {
    public static void main(String[] args) {
        boolean isJavaFun = true;
        System.out.println("Is Java fun? " + isJavaFun);  // Output: Is Java fun? true
    }
}
```

**Output:**
```
Is Java fun? true
```

---

### 2. **Variables, Declarations, and Constants**
- **Variable**: A storage location with a name and type.
- **Constant**: A variable whose value cannot change.

**Explanation:**
- Variables are defined with a specific type, and constants are defined with `final` keyword to prevent reassignment.

**Code Example:**
```java
public class VariableExample {
    public static void main(String[] args) {
        int age = 25;  // Variable declaration and assignment
        final int MAX_AGE = 100;  // Constant declaration
        System.out.println("Age: " + age);  // Output: Age: 25
        System.out.println("Max Age: " + MAX_AGE);  // Output: Max Age: 100
    }
}
```

**Output:**
```
Age: 25
Max Age: 100
```

---

### 3. **Type Conversion and Casting**
- **Implicit Conversion (Widening)**: Automatic conversion from smaller to larger type.
- **Explicit Conversion (Narrowing)**: Manual conversion from larger to smaller type.

**Explanation:**
- **Implicit**: Happens automatically when assigning a smaller type to a larger type.
- **Explicit**: Requires casting (e.g., from `double` to `int`).

**Code Example:**
```java
public class TypeConversionExample {
    public static void main(String[] args) {
        int num = 10;
        double result = num;  // Implicit conversion (int to double)
        System.out.println("Converted to double: " + result);  // Output: Converted to double: 10.0
        
        double pi = 3.14;
        int intPi = (int) pi;  // Explicit conversion (double to int)
        System.out.println("Converted to int: " + intPi);  // Output: Converted to int: 3
    }
}
```

**Output:**
```
Converted to double: 10.0
Converted to int: 3
```

---

### 4. **Arrays of Primitive Data Types**
An array allows you to store multiple values of the same type.

**Explanation:**
- Arrays are fixed in size and store values of a single type.
- Example: `int[] arr = {1, 2, 3, 4, 5};`

**Code Example:**
```java
public class ArrayExample {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};  // Array of integers
        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);  // Output: 1 2 3 4 5
        }
    }
}
```

**Output:**
```
1
2
3
4
5
```

---

### 5. **Control Statements**

#### **Branching: if, switch**
- **if**: Executes code if the condition is true.
- **switch**: Allows checking multiple conditions in a concise manner.

**Explanation:**
- **if** is used for single conditions, while **switch** is used when there are multiple options.

**Code Example (if):**
```java
public class IfExample {
    public static void main(String[] args) {
        int age = 20;
        if (age >= 18) {
            System.out.println("Adult");  // Output: Adult
        }
    }
}
```

**Code Example (switch):**
```java
public class SwitchExample {
    public static void main(String[] args) {
        int day = 3;
        switch (day) {
            case 1: System.out.println("Monday"); break;
            case 2: System.out.println("Tuesday"); break;
            default: System.out.println("Invalid day");
        }
    }
}
```

**Output for if:**
```
Adult
```

**Output for switch:**
```
Invalid day
```

---

#### **Looping: while, do-while, for**

- **while**: Executes code as long as the condition is true.
- **do-while**: Executes code at least once and then checks the condition.
- **for**: Executes code for a specific number of times.

**Explanation:**
- **while** checks the condition before executing the code.
- **do-while** guarantees at least one execution.
- **for** is used when the number of iterations is known in advance.

**Code Example (while):**
```java
public class WhileExample {
    public static void main(String[] args) {
        int i = 0;
        while (i < 5) {
            System.out.println(i);  // Output: 0 1 2 3 4
            i++;
        }
    }
}
```

**Code Example (do-while):**
```java
public class DoWhileExample {
    public static void main(String[] args) {
        int i = 0;
        do {
            System.out.println(i);  // Output: 0 1 2 3 4
            i++;
        } while (i < 5);
    }
}
```

**Code Example (for):**
```java
public class ForExample {
    public static void main(String[] args) {
        for (int i = 0; i < 5; i++) {
            System.out.println(i);  // Output: 0 1 2 3 4
        }
    }
}
```

**Output for while, do-while, and for:**
```
0
1
2
3
4
```

---

#### **Jumping Statements: break, continue, return**

- **break**: Exits from a loop or switch statement.
- **continue**: Skips the current iteration and moves to the next.
- **return**: Exits from a method and optionally returns a value.

**Explanation:**
- **break** stops loop execution.
- **continue** skips the current loop iteration.
- **return** ends method execution and optionally returns a value.

**Code Example (break):**
```java
public class BreakExample {
    public static void main(String[] args) {
        for (int i = 0; i < 10; i++) {
            if (i == 5) break;
            System.out.println(i);  // Output: 0 1 2 3 4
        }
    }
}
```

**Code Example (continue):**
```java
public class ContinueExample {
    public static void main(String[] args) {
        for (int i = 0; i < 5; i++) {
            if (i == 2) continue;
            System.out.println(i);  // Output: 0 1 3 4
        }
    }
}
```

**Code Example (return):**
```java
public class ReturnExample {
    public static void main(String[] args) {
        int result = add(5, 3);
        System.out.println(result);  // Output: 8
    }

    public static int add(int a, int b) {
        return a + b;
    }
}
```

**Output for break, continue, and return:**
```
0
1
2
3
4

0
1
3


4

8
```

---

