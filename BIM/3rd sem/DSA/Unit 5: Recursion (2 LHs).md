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
![Alt text]([https://www.example.com/image.jpg](https://github.com/Sharatmaharjan/Notes/blob/main/BIM/3rd%20sem/DSA/images/tailrecursion.png))

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
