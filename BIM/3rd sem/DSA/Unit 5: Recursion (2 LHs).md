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

#### **5. Tail Recursion**
**Tail recursion** is a special form of recursion where the recursive call is the last operation in the function. This allows the compiler or interpreter to optimize the recursion by reusing the current function’s stack frame instead of creating a new one. This is called **tail call optimization** (TCO).

- **Advantage:** Tail recursion can reduce the space complexity, as there is no need to maintain the call stack for each recursive call.
- **Example:**

```c
int tailRecursion(int n, int result) {
    if (n == 0) {
        return result; // Base case
    } else {
        return tailRecursion(n - 1, n * result); // Tail recursion
    }
}
```

In this case, `tailRecursion` returns its result directly from the recursive call, making it tail-recursive.

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
