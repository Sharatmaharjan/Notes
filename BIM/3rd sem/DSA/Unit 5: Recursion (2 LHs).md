### Unit 5: Recursion (2 LHs)

Recursion is a method in which the solution to a problem depends on solutions to smaller instances of the same problem. A function calls itself directly or indirectly to solve smaller parts of the problem. Recursion plays a significant role in many programming problems, such as searching, sorting, and solving mathematical problems.

---

#### **1. Recursive Definitions**
A **recursive definition** defines an entity in terms of itself. In the context of recursion, this involves defining a function in terms of itself, where the function repeats its execution with smaller or simpler inputs. The key to recursion is breaking a problem into subproblems that are easier to solve.

- **Base Case:** The simplest case that can be solved directly without recursion. This halts the recursion process.
- **Recursive Case:** The part where the function calls itself to solve smaller instances of the problem.

**Example: Factorial Function (n!)**

The factorial of a number \(n\) is defined as:
- \(n! = 1\) if \(n = 0\)
- \(n! = n * (n-1)!\) if \(n > 0\)

This can be recursively defined in a function like this:

```c
int factorial(int n) {
    if (n == 0) {
        return 1; // Base case
    } else {
        return n * factorial(n - 1); // Recursive case
    }
}
```

---

#### **2. Method Calls and Recursion Implementation**
In recursive function calls, the function must "remember" its state each time it calls itself. This is done through the **call stack**, where each call stores the necessary information (parameters, return addresses, etc.).

When a recursive function is called, the function executes the recursive case until it reaches the base case, at which point the recursion unwinds, and the final result is returned.

- **Method Call Stack:** Each recursive call adds a new layer to the stack. Once the base case is hit, the stack begins to unwind, returning values back up to the original function call.

**Example: Fibonacci Series**

```c
int fibonacci(int n) {
    if (n <= 1) {
        return n; // Base case
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
    }
}
```

---

#### **3. Direct Recursion**
**Direct recursion** occurs when a function calls itself within its body. This is the most common form of recursion, where the function works directly on its problem, calling itself repeatedly until it reaches the base case.

- **Example:** The factorial function mentioned earlier is a direct recursion since it calls itself directly within its body.

---

#### **4. Indirect Recursion**
**Indirect recursion** occurs when function A calls function B, and function B calls function A, forming a cycle of function calls. Indirect recursion can make the code more complex and harder to trace but works in similar ways to direct recursion.

- **Example:**
  
```c
void functionA(int n) {
    if (n > 0) {
        functionB(n - 1); // Calls functionB
    }
}

void functionB(int n) {
    if (n > 0) {
        functionA(n - 1); // Calls functionA
    }
}
```

---


### **5. Tail Recursion**

**Definition:**
Tail recursion occurs when a recursive function calls itself as its last operation before returning a result. In other words, the recursive call is the **final action** of the function, meaning there is no additional work to be done after the recursive call returns. This enables certain optimizations, such as **Tail Call Optimization (TCO)**, where the compiler or interpreter reuses the current function's stack frame for the next call, avoiding additional stack space consumption. 

In languages that support TCO, tail recursion can help avoid stack overflow errors even for deep recursion by preventing the accumulation of stack frames.

---

### **Key Features of Tail Recursion:**
1. **Final Recursive Call:** The recursive call must be the last thing executed in the function, so that no additional operations (such as multiplication, addition, etc.) are performed after the call.
2. **No Need for Additional Stack Frames:** If the recursion is tail-recursive, the current stack frame is discarded, and the next recursive call reuses the same stack frame.
3. **Efficiency:** Tail recursion reduces the risk of stack overflow in cases of deep recursion by eliminating the need to maintain multiple stack frames.

---

### **Example of Tail Recursion:**

#### **Factorial Function:**
The factorial of a number \(n\) is defined as:
- \(n! = 1\) if \(n = 0\)
- \(n! = n * (n - 1)!\) if \(n > 0\)

**Non-Tail Recursion:**

```c
// Non-tail recursive factorial function
int factorial(int n) {
    if (n == 0) {
        return 1; // Base case
    } else {
        return n * factorial(n - 1); // Recursive call
    }
}
```

In the above non-tail recursive function, the multiplication operation `n *` is performed after the recursive call. This means the function has to wait for the recursive calls to return before it can perform the multiplication, leading to multiple stack frames being created.

**Tail Recursion:**

```c
// Tail recursive factorial function
int factorialTail(int n, int result) {
    if (n == 0) {
        return result; // Base case: return the result
    } else {
        return factorialTail(n - 1, n * result); // Tail recursive call
    }
}

// Helper function to start the recursion with an initial result of 1
int factorial(int n) {
    return factorialTail(n, 1);
}
```

### **Explanation:**
- In the tail-recursive version, the `result` is passed along with each recursive call, accumulating the product as the recursion progresses.
- The **recursive call** is the last operation, meaning there is no further computation after the recursion.
- The recursion will continue until `n == 0`, at which point the accumulated `result` is returned.


---
![Alt text](https://github.com/Sharatmaharjan/Notes/blob/main/BIM/3rd%20sem/DSA/images/tailrecursion.png)

### **Example Walkthrough:**

Let’s calculate `factorial(5)` using the tail-recursive version.

1. `factorial(5)` calls `factorialTail(5, 1)`
2. `factorialTail(5, 1)` calls `factorialTail(4, 5)`
3. `factorialTail(4, 5)` calls `factorialTail(3, 20)`
4. `factorialTail(3, 20)` calls `factorialTail(2, 60)`
5. `factorialTail(2, 60)` calls `factorialTail(1, 120)`
6. `factorialTail(1, 120)` calls `factorialTail(0, 120)`
7. `factorialTail(0, 120)` returns `120`

In this process, the recursion "builds" the result incrementally through the `result` parameter, and at the end, the value of `120` is returned.

---

### **Advantages of Tail Recursion:**
1. **Memory Efficiency:** Because the stack frame is reused, tail recursion minimizes memory usage compared to non-tail recursion.
2. **Prevention of Stack Overflow:** Tail recursion reduces the risk of stack overflow errors in cases of deep recursion (e.g., recursive depth up to millions), as it uses constant stack space.
3. **Optimized Execution:** Some compilers or interpreters can convert tail recursion into a loop (using tail call optimization), making the recursive call more efficient in terms of execution time.

---

### **Disadvantages of Tail Recursion:**
1. **Limited Support:** Not all programming languages or compilers support tail call optimization (TCO). In languages like C and Python, TCO is not always available, meaning deep tail recursion might still result in stack overflow.
2. **Potential Complexity in Conversion:** Some recursive problems may not be easily convertible to tail recursion, requiring additional logic or helper functions.


---

#### **6. Nested Recursion**
**Nested recursion** occurs when a recursive function calls itself in a nested manner, i.e., the recursive call itself contains further recursive calls.

- **Example:** A function that calculates the Ackermann function is a typical example of nested recursion. The Ackermann function is defined as:
  - \( A(m, n) = n + 1 \) if \( m = 0 \)
  - \( A(m, n) = A(m-1, 1) \) if \( m > 0 \) and \( n = 0 \)
  - \( A(m, n) = A(m-1, A(m, n-1)) \) if \( m > 0 \) and \( n > 0 \)

```c
int ackermann(int m, int n) {
    if (m == 0) {
        return n + 1; // Base case
    } else if (n == 0) {
        return ackermann(m - 1, 1); // Recursive case
    } else {
        return ackermann(m - 1, ackermann(m, n - 1)); // Nested recursion
    }
}
```

---

#### **7. Excessive Recursion**
**Excessive recursion** occurs when the depth of recursion is too large, leading to issues such as stack overflow. This happens when the base case is not defined properly or is reached too late, causing the recursion to continue indefinitely or for an impractically large number of times.

**Preventive Measures:**
- Properly define base cases to ensure recursion halts.
- Avoid recursion in cases where it might lead to unnecessary deep calls (e.g., using loops where applicable).

**Example:**

```c
// Potential excessive recursion
void excessiveRecursion(int n) {
    if (n > 0) {
        excessiveRecursion(n - 1);
    } else {
        excessiveRecursion(n + 1); // Incorrect, leads to infinite recursion
    }
}
```

---

### Programs:

#### 1. Factorial of a number using recursion.

### 

```java
public class Factorial {
    // Recursive function to calculate factorial
    public static int factorial(int n) {
        if (n == 0 || n == 1) { // Base case
            return 1;
        } else {
            return n * factorial(n - 1); // Recursive call
        }
    }

    // Driver method
    public static void main(String[] args) {
        int number = 5; // Example number
        int result = factorial(number);
        
        System.out.println("Factorial of " + number + " is: " + result);
    }
}
```

### How it works:
- The `factorial` function is defined recursively. 
- The base case is when `n` is 0 or 1, and the factorial of 0 and 1 is defined as 1.
- For other values, the function calls itself with `n-1` until the base case is reached, multiplying the values as it returns.

### Visualization:
When `factorial(5)` is called, the function calls will unfold like this:

```
factorial(5) → 5 * factorial(4)
                    factorial(4) → 4 * factorial(3)
                            factorial(3) → 3 * factorial(2)
                                    factorial(2) → 2 * factorial(1)
                                            factorial(1) → 1
```

The recursion will "unwind" as follows:

```
factorial(5) → 5 * (4 * (3 * (2 * 1))) = 120
```

The final result will be `120`.

---

#### 2. Fibonacci sequence using recursion.


```java
public class Fibonacci {

    // Recursive function to find the nth Fibonacci number
    public static int fibonacci(int n) {
        if (n <= 1) {  // Base cases
            return n;
        } else {
            return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive call
        }
    }

    // Driver method
    public static void main(String[] args) {
        int number = 10; // Example for the first 10 Fibonacci numbers
        System.out.println("Fibonacci Sequence up to " + number + "th term:");

        // Printing Fibonacci sequence
        for (int i = 0; i < number; i++) {
            System.out.print(fibonacci(i) + " ");
        }
    }
}
```

### How it works:
- The function `fibonacci(int n)` uses recursion to calculate the nth Fibonacci number.
- The base cases are when `n` is 0 or 1 (both of these return `n`).
- For other values, the function calls itself to get the previous two Fibonacci numbers and adds them together to calculate the current Fibonacci number.

### Fibonacci Sequence Example:
For `number = 10`, the Fibonacci sequence is generated as follows:

```
Fibonacci Sequence up to 10th term:
0 1 1 2 3 5 8 13 21 34
```

### Visualization:
The recursive calls for `fibonacci(5)` will unfold like this:

```
fibonacci(5) → fibonacci(4) + fibonacci(3)
                fibonacci(4) → fibonacci(3) + fibonacci(2)
                    fibonacci(3) → fibonacci(2) + fibonacci(1)
                        fibonacci(2) → fibonacci(1) + fibonacci(0)
```

This will continue recursively until it reaches the base cases (`fibonacci(1)` and `fibonacci(0)`), then the values will start adding up and unwinding back to the original call. The final result will be the Fibonacci value for the nth term.
---

#### 3. **Greatest Common Divisor (GCD)**. 

We can find the GCD using the **Euclidean Algorithm**, which is a recursive method.


```java
public class GCD {

    // Recursive function to find GCD of two numbers
    public static int gcd(int a, int b) {
        if (b == 0) {  // Base case
            return a;
        } else {
            return gcd(b, a % b);  // Recursive call with remainder
        }
    }

    // Driver method
    public static void main(String[] args) {
        int num1 = 12;  // Example number 1
        int num2 = 8;  // Example number 2
        int result = gcd(num1, num2);

        System.out.println("The GCD of " + num1 + " and " + num2 + " is: " + result);
    }
}
```

### How it works:
1. The `gcd(a, b)` function calculates the GCD of `a` and `b` recursively.
2. If `b` is 0, the GCD is `a` (base case).
3. Otherwise, it recursively calls `gcd(b, a % b)` (where `%` is the modulus operator), which ensures that `a` is reduced step-by-step until `b` reaches 0.

### Example:
num1=12 and num2=8

gcd(12, 8) → gcd(8, 12 % 8) = gcd(8, 4)
gcd(8, 4) → gcd(4, 8 % 4) = gcd(4, 0)
gcd(4, 0) → 4 (base case reached)

Thus, the GCD of 12 and 8 is 4.

### Output:

```
The GCD of 12 and 8 is: 4
```
---
#### 4. **Tower of Hanoi**
The objective is to move all the disks from the source peg to the destination peg, with the following rules:

1. You can move only one disk at a time.
2. A disk can only be placed on top of a larger disk or on an empty peg.
3. You must move all the disks from the source peg to the destination peg, using the third peg as an auxiliary storage.

### Tower of Hanoi Algorithm:

The recursive approach to solving the Tower of Hanoi is as follows:

1. Move `n-1` disks from the source peg to the auxiliary peg using the destination peg as auxiliary.
2. Move the nth disk (the largest disk) from the source peg to the destination peg.
3. Move the `n-1` disks from the auxiliary peg to the destination peg using the source peg as auxiliary.

### Java Code for Tower of Hanoi:

```java
public class TowerOfHanoi {

    // Recursive function to solve the Tower of Hanoi problem
    public static void towerOfHanoi(int n, char source, char destination, char auxiliary) {
        if (n == 1) {  // Base case: Only one disk to move
            System.out.println("Move disk 1 from " + source + " to " + destination);
            return;
        }
        
        // Step 1: Move n-1 disks from source to auxiliary peg
        towerOfHanoi(n - 1, source, auxiliary, destination);
        
        // Step 2: Move the nth disk from source to destination peg
        System.out.println("Move disk " + n + " from " + source + " to " + destination);
        
        // Step 3: Move n-1 disks from auxiliary to destination peg
        towerOfHanoi(n - 1, auxiliary, destination, source);
    }

    // Driver method
    public static void main(String[] args) {
        int n = 3;  // Example: Number of disks
        char source = 'A';  // Source peg
        char destination = 'C';  // Destination peg
        char auxiliary = 'B';  // Auxiliary peg
        
        System.out.println("Solution for Tower of Hanoi with " + n + " disks:");
        towerOfHanoi(n, source, destination, auxiliary);
    }
}
```

### Explanation:
- The function `towerOfHanoi(n, source, destination, auxiliary)` moves `n` disks from the source peg to the destination peg using the auxiliary peg.
- If `n` is 1 (base case), it simply moves the disk from the source peg to the destination peg.
- For `n > 1`, it recursively moves `n-1` disks from the source to the auxiliary peg, then moves the nth disk from the source to the destination peg, and finally moves the `n-1` disks from the auxiliary peg to the destination peg.

### Example Output (For `n = 3` disks):

```
Solution for Tower of Hanoi with 3 disks:
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
```

### Visualization:
For `n = 3`, the disks are moved step-by-step from peg `A` (source) to peg `C` (destination) with peg `B` as the auxiliary storage.

1. Move disk 1 from A to C.
2. Move disk 2 from A to B.
3. Move disk 1 from C to B.
4. Move disk 3 from A to C.
5. Move disk 1 from B to A.
6. Move disk 2 from B to C.
7. Move disk 1 from A to C.

This recursive solution ensures that all disks are moved correctly while respecting the rules of the problem.

---

#### Last topic: Recursion Vs Iteration

**Recursion** and **iteration** are two fundamental programming techniques for solving problems, but they have key differences in how they approach problem-solving. Here's a comparison of both:

### 1. **Definition:**

- **Recursion:** 
  - Recursion is a process in which a function calls itself to solve a smaller instance of the problem.
  - A recursive function must have a **base case** to stop the recursion and prevent an infinite loop.
  
- **Iteration:**
  - Iteration is the process of repeating a set of instructions (or a loop) until a certain condition is met.
  - Iterative solutions typically use **loops** such as `for`, `while`, or `do-while`.

### 2. **Control Flow:**

- **Recursion:**
  - In recursion, the function keeps calling itself with modified arguments until it reaches a base case.
  - It uses the **call stack** to maintain function calls, meaning each call is placed on the stack until the base case is reached, then they "unwind" as the recursion returns.

- **Iteration:**
  - Iteration uses explicit loops (`for`, `while`, etc.) and doesn't involve multiple function calls.
  - It maintains a **loop counter** and keeps executing the same block of code until a condition is met.

### 3. **Memory Usage:**

- **Recursion:**
  - Recursion can use a lot of memory due to the **call stack** storing the function calls.
  - If the recursion depth is large, it can lead to a **stack overflow** error.
  
- **Iteration:**
  - Iteration typically uses less memory because it does not involve multiple function calls.
  - Only a fixed amount of memory is used to store the loop counter and other variables.

### 4. **Performance:**

- **Recursion:**
  - Recursive calls can add overhead due to the function calls and memory usage for the call stack.
  - Some recursive algorithms, especially those with **overlapping subproblems**, can be inefficient if not optimized (e.g., **memoization** or **tail recursion**).

- **Iteration:**
  - Iteration tends to be more efficient because it doesn't involve the overhead of multiple function calls or memory allocation for each call.
  - Iterative solutions usually have better performance in terms of time and space for simple repetitive tasks.

### 5. **Simplicity and Readability:**

- **Recursion:**
  - Recursive solutions can be more elegant and concise for problems that naturally fit recursion (e.g., tree traversals, factorial calculation).
  - Recursive functions can be harder to understand, especially for beginners, due to the **self-referencing** nature and tracking the call stack.

- **Iteration:**
  - Iterative solutions are typically easier to understand and follow, especially for simple tasks.
  - They are often more straightforward and familiar, making them suitable for problems that involve simple repetition.

### 6. **Use Cases:**

- **Recursion:**
  - Problems like **Tree Traversals**, **Graph Traversals**, **Factorial**, **Fibonacci series**, **Tower of Hanoi**, **Divide and Conquer algorithms** (e.g., Merge Sort, Quick Sort).
  - Recursion is preferred when the problem can be broken down into smaller subproblems that are similar to the original problem.

- **Iteration:**
  - Problems that involve **simple repetitive tasks** or **linear processing** such as iterating over arrays or lists, or accumulating values.
  - Iteration is ideal when the problem involves a fixed number of steps or operations.

### 7. **Example:**

#### Recursion Example (Factorial of a number):

```java
public class RecursionExample {
    public static int factorial(int n) {
        if (n == 0) {
            return 1;  // Base case
        } else {
            return n * factorial(n - 1);  // Recursive call
        }
    }
}
```

#### Iteration Example (Factorial of a number):

```java
public class IterationExample {
    public static int factorial(int n) {
        int result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        return result;
    }
}
```

### 8. **Summary of Differences:**

| Aspect                | Recursion                              | Iteration                           |
|-----------------------|----------------------------------------|-------------------------------------|
| **Approach**           | Function calls itself                 | Repeats instructions in a loop     |
| **Memory Usage**       | Uses the call stack (can cause stack overflow) | Uses a fixed amount of memory     |
| **Performance**        | Can be less efficient due to overhead | Generally more efficient           |
| **Complexity**         | Can be more elegant but harder to debug | Easier to understand and debug     |
| **Use Cases**          | Tree traversals, Divide & Conquer, etc. | Iterating over arrays, lists, etc. |

### Conclusion:
- Use **recursion** when the problem naturally fits the recursive approach, especially when dealing with hierarchical structures like trees or when breaking down a problem into smaller, similar subproblems.
- Use **iteration** for problems that involve repetitive tasks with a known or fixed number of steps, and when you need more control over memory usage and performance.

