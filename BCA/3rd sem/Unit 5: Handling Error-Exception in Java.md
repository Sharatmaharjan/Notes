## Unit 5: Handling Error/Exception in Java

### 1. Basic Exceptions
In Java, **exceptions** are events that disrupt the normal flow of a program. They occur during the execution of a program when something unexpected happens, such as dividing by zero, accessing an invalid index in an array, or trying to open a file that doesn't exist. Java provides a robust mechanism to handle exceptions using **try-catch blocks**, **throw**, and **throws** keywords.

#### **Types of Exceptions**

1. **Checked Exceptions**:
   - These are exceptions that are checked at **compile-time**.
   - Examples: `IOException`, `SQLException`, `ClassNotFoundException`.
   - The programmer must handle these exceptions using `try-catch` blocks or declare them using the `throws` keyword.

2. **Unchecked Exceptions**:
   - These are exceptions that are checked at **runtime**.
   - Examples: `ArithmeticException`, `NullPointerException`, `ArrayIndexOutOfBoundsException`.
   - These are not required to be handled explicitly.

3. **Errors**:
   - These are severe issues that are not meant to be handled by the program.
   - Examples: `OutOfMemoryError`, `StackOverflowError`.


#### **Exception Handling Mechanism**

Java provides five keywords for exception handling:
1. **`try`**: A block of code where exceptions might occur.
2. **`catch`**: A block that handles the exception.
3. **`finally`**: A block that executes regardless of whether an exception occurs.
4. **`throw`**: Used to explicitly throw an exception.
5. **`throws`**: Used to declare exceptions that a method might throw.

#### **Common Exceptions in Java**

1. **ArithmeticException**: Occurs when dividing by zero.
2. **NullPointerException**: Occurs when trying to access a null object.
3. **ArrayIndexOutOfBoundsException**: Occurs when accessing an invalid array index.
4. **IOException**: Occurs during input/output operations.
5. **NumberFormatException**: Occurs when converting a string to a numeric type fails.


#### Lab 1: Basic Exception
```java
public class Main {
    public static void main(String[] args) {
        int a = 10;
        int b = 0;
        try {
            int result = a / b; // This will cause an ArithmeticException
            System.out.println("Result is " + result);
        } catch (ArithmeticException e) {
            System.out.println("Cannot divide by zero!");
        }
    }
}
```
**Output:**
```
Cannot divide by zero!
```
**Explanation:**
- The code attempts to divide `a` by `b`, which is zero, leading to an `ArithmeticException`.
- The `try` block contains the code that might throw an exception.
- The `catch` block catches the exception and handles it by printing an error message.

---

### 2. Proper Use of Exceptions
Exceptions should be used for exceptional conditions only, not for regular control flow. They are costly in terms of performance and should not be used to handle predictable conditions that can be checked with simple if-else statements.

#### Lab 2: Proper Use of Exceptions
```java
public class Main {
    public static void main(String[] args) {
        int[] numbers = {1, 2, 3};
        int index = 3;
        if (index >= 0 && index < numbers.length) {
            System.out.println("Number at index " + index + " is " + numbers[index]);
        } else {
            System.out.println("Index out of bounds!");
        }
    }
}
```
**Output:**
```
Index out of bounds!
```
**Explanation:**
- Instead of using a try-catch block to handle an `ArrayIndexOutOfBoundsException`, we use an if-else statement to check the index bounds.
- This is more efficient and clearer for predictable conditions.

### 3. User-Defined Exceptions
Java allows us to create our own exceptions by extending the `Exception` class. This is useful for creating specific exception types for our application.

#### Lab 3: User-Defined Exception
```java
class InvalidAgeException extends Exception {
    public InvalidAgeException(String message) {
        super(message);
    }
}

public class Main {
    static void validateAge(int age) {
        try {
            if (age < 18) {
                throw new InvalidAgeException("Age must be 18 or above.");//set message
            } else {
                System.out.println("Age is valid.");
            }
        } catch (InvalidAgeException e) {
            System.out.println("Caught an exception: " + e.getMessage());//get message
        }
    }

    public static void main(String[] args) {
        validateAge(15); // This will internally handle the exception
    }
}
```
**Output:**
```
Caught an exception: Age must be 18 or above.
```
#### **Explanation**
a. **Custom Exception**:
   - We define `InvalidAgeException` by extending the `Exception` class for handling invalid age errors.

b. **Local Handling in `validateAge`**:
   - The `validateAge` method throws `InvalidAgeException` if the age is less than 18, it catches and handles the exception locally using a `try-catch` block.

3. **`main`**:
   - The `main` method calls `validateAge(15)` without needing to handle the exception, as it is already managed inside the method. 


## 4. Catching Exception: try, catch
The `try` block contains code that might throw an exception. The `catch` block contains code that handles the exception.

### Example: Catching Exception
```java
public class Main {
    public static void main(String[] args) {
        try {
            int[] numbers = {1, 2, 3};
            System.out.println(numbers[5]); // This will cause an ArrayIndexOutOfBoundsException
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Array index is out of bounds!");
        }
    }
}
```
**Output:**
```
Array index is out of bounds!
```
**Explanation:**
- The `try` block attempts to access an index that is out of bounds, causing an `ArrayIndexOutOfBoundsException`.
- The `catch` block catches the exception and prints an error message.

## 5. Throwing and Rethrowing: throw, throws
- `throw`: Used to explicitly throw an exception.
- `throws`: Used in method signatures to declare that a method might throw one or more exceptions.

### Example: Throwing and Rethrowing
```java
public class Main {
    static void checkAge(int age) throws ArithmeticException {
        if (age < 18) {
            throw new ArithmeticException("Access denied - You must be at least 18 years old.");
        } else {
            System.out.println("Access granted - You are old enough!");
        }
    }

    public static void main(String[] args) {
        try {
            checkAge(15); // This will throw an ArithmeticException
        } catch (ArithmeticException e) {
            System.out.println("Caught an exception: " + e.getMessage());
        }
    }
}
```
**Output:**
```
Caught an exception: Access denied - You must be at least 18 years old.
```
**Explanation:**
- The `checkAge` method throws an `ArithmeticException` if the age is less than 18.
- The `throws` keyword in the method signature indicates that this method might throw an `ArithmeticException`.
- In the `main` method, we catch and handle the exception.

## 6. Cleaning Up Using the finally Clause
The `finally` block is used to execute important code such as closing resources, regardless of whether an exception is thrown or not.

### Example: finally Clause
```java
public class Main {
    public static void main(String[] args) {
        try {
            int[] numbers = {1, 2, 3};
            System.out.println(numbers[5]); // This will cause an ArrayIndexOutOfBoundsException
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Array index is out of bounds!");
        } finally {
            System.out.println("This will always be executed.");
        }
    }
}
```
**Output:**
```
Array index is out of bounds!
This will always be executed.
```
**Explanation:**
- The `try` block attempts to access an out-of-bounds index, causing an exception.
- The `catch` block handles the exception.
- The `finally` block is executed regardless of whether an exception was thrown or not, ensuring that cleanup code is always run.

## Summary
- **Basic Exceptions**: Handle unexpected errors using try-catch blocks.
- **Proper Use of Exceptions**: Use exceptions for exceptional conditions, not for regular control flow.
- **User-Defined Exceptions**: Create custom exceptions by extending the `Exception` class.
- **Catching Exceptions**: Use try-catch blocks to handle exceptions.
- **Throwing and Rethrowing**: Use `throw` to throw exceptions and `throws` to declare them in method signatures.
- **finally Clause**: Use the `finally` block to execute cleanup code that must run regardless of whether an exception occurs.

These concepts are fundamental to writing robust and error-resistant Java programs.
