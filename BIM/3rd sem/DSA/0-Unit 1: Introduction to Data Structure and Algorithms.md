### **Unit 1: Introduction to Data Structure and Algorithms**

#### **1.1 Data Types**
- **Definition**:  
  A **data type** defines the type of data that can be stored in a variable and the operations that can be performed on it.

- **Types of Data Types in Java**:  

  **1. Primitive Data Types**:  
  These are the built-in data types in Java. Examples include:
  - **byte, short, int, long**: Used to store integer values.
  - **float, double**: Used to store decimal values.
  - **char**: Used to store a single character.
  - **boolean**: Used to store `true` or `false`.

  **Example Code**:  
  ```java
  public class DataTypeExample {
      public static void main(String[] args) {
          int age = 25; // Integer
          float salary = 34500.75f; // Floating-point number
          char grade = 'A'; // Single character
          boolean isActive = true; // Boolean value

          System.out.println("Age: " + age);
          System.out.println("Salary: " + salary);
          System.out.println("Grade: " + grade);
          System.out.println("Is Active: " + isActive);
      }
  }
  ```
  **Sample Output**:  
  ```
  Age: 25  
  Salary: 34500.75  
  Grade: A  
  Is Active: true  
  ```

  **2. Non-Primitive (Reference) Data Types**:  
  These are data types that refer to objects. Examples include Strings, Arrays, and user-defined classes.  

  **Example Code**:  
  ```java
  public class NonPrimitiveExample {
      public static void main(String[] args) {
          String name = "Alice"; // String
          int[] numbers = {1, 2, 3, 4}; // Array

          System.out.println("Name: " + name);
          System.out.print("Numbers: ");
          for (int num : numbers) {
              System.out.print(num + " ");
          }
      }
  }
  ```
  **Sample Output**:  
  ```
  Name: Alice  
  Numbers: 1 2 3 4  
  ```

---

#### **1.2 Data Structure**

- **Definition**:  
  A **data structure** is a way to organize, manage, and store data efficiently to perform operations such as access, insertion, deletion, and search.

---

##### **Linear Data Structures**
- Data is organized in a sequential (linear) order where each element is connected to its previous and next element.  
- **Examples**:  
  Arrays, Linked Lists, Stacks, Queues.  

- **Key Characteristics**:  
  - Elements are stored in a contiguous manner in memory (for arrays).  
  - Traversal is performed one element at a time.

- **Examples in Java**:  

  **Array**:  
  ```java
  public class ArrayExample {
      public static void main(String[] args) {
          int[] numbers = {10, 20, 30, 40};
          for (int i = 0; i < numbers.length; i++) {
              System.out.println("Element at index " + i + ": " + numbers[i]);
          }
      }
  }
  ```
  **Sample Output**:  
  ```
  Element at index 0: 10  
  Element at index 1: 20  
  Element at index 2: 30  
  Element at index 3: 40  
  ```

  **Queue**:  
  ```java
  import java.util.LinkedList;
  import java.util.Queue;

  public class QueueExample {
      public static void main(String[] args) {
          Queue<String> queue = new LinkedList<>();
          queue.add("Alice"); // Enqueue
          queue.add("Bob");
          System.out.println("Front Element: " + queue.peek()); // Peek
          queue.remove(); // Dequeue
          System.out.println("After Dequeue: " + queue);
      }
  }
  ```
  **Sample Output**:  
  ```
  Front Element: Alice  
  After Dequeue: [Bob]  
  ```

---

##### **Non-Linear Data Structures**
- Data is organized hierarchically or in a non-sequential manner.  
- **Examples**: Trees, Graphs.

- **Key Characteristics**:  
  - Elements are connected in multiple ways (not necessarily sequential).  
  - Efficient for hierarchical or network-based relationships.

- **Example in Java** (Tree Structure):  
  ```java
  import java.util.ArrayList;

  class TreeNode {
      int data;
      ArrayList<TreeNode> children;

      public TreeNode(int data) {
          this.data = data;
          children = new ArrayList<>();
      }

      public void addChild(TreeNode child) {
          children.add(child);
      }
  }

  public class TreeExample {
      public static void main(String[] args) {
          TreeNode root = new TreeNode(1);
          TreeNode child1 = new TreeNode(2);
          TreeNode child2 = new TreeNode(3);

          root.addChild(child1);
          root.addChild(child2);

          System.out.println("Root Node: " + root.data);
          System.out.println("Children: " + root.children.get(0).data + ", " + root.children.get(1).data);
      }
  }
  ```
  **Sample Output**:  
  ```
  Root Node: 1  
  Children: 2, 3  
  ```

---

#### **1.3 Abstract Data Type (ADT)**

- **Definition**:  
  An **Abstract Data Type (ADT)** is a logical model that defines how data is organized and the operations supported, without specifying how the data is implemented.

- **Examples of ADTs**:  

  **1. Stack ADT**:  
  - Operations: `push()`, `pop()`, `peek()`.  
  - **Example Code**:  
    ```java
    import java.util.Stack;

    public class StackExample {
        public static void main(String[] args) {
            Stack<Integer> stack = new Stack<>();
            stack.push(10); // Push element
            stack.push(20);
            System.out.println("Top Element: " + stack.peek()); // Peek
            stack.pop(); // Pop element
            System.out.println("After Pop: " + stack);
        }
    }
    ```
    **Sample Output**:  
    ```
    Top Element: 20  
    After Pop: [10]  
    ```

  **2. Queue ADT**:  
  - Operations: `enqueue()`, `dequeue()`, `peek()`.  
  - **Example Code**:  
    ```java
    import java.util.LinkedList;
    import java.util.Queue;

    public class QueueExample {
        public static void main(String[] args) {
            Queue<String> queue = new LinkedList<>();
            queue.add("Alice"); // Enqueue
            queue.add("Bob");
            System.out.println("Front Element: " + queue.peek()); // Peek
            queue.remove(); // Dequeue
            System.out.println("After Dequeue: " + queue);
        }
    }
    ```
    **Sample Output**:  
    ```
    Front Element: Alice  
    After Dequeue: [Bob]  
    ```

---

### **1.4 Operations Performed in Data Structures**
Data structures allow efficient organization, access, and modification of data. Below are the primary operations performed:

#### **1.1 Basic Operations**
1. **Traversal**  
   - Visiting each element in the data structure.  
   - Example: Traversing an array to print its elements.  
     ```java
     int[] arr = {10, 20, 30};
     for (int num : arr) {
         System.out.println(num);
     }
     ```
     **Output**:  
     ```
     10  
     20  
     30  
     ```

2. **Insertion**  
   - Adding an element to the data structure.  
   - Example: Adding elements to a list.  
     ```java
     ArrayList<Integer> list = new ArrayList<>();
     list.add(10);
     list.add(20);
     System.out.println(list);
     ```
     **Output**:  
     ```
     [10, 20]  
     ```

3. **Deletion**  
   - Removing an element from the data structure.  
   - Example: Removing an element from a list.  
     ```java
     list.remove(1); // Removes the element at index 1
     System.out.println(list);
     ```
     **Output**:  
     ```
     [10]  
     ```

4. **Searching**  
   - Finding an element in the data structure.  
   - Example: Searching for an element in a list.  
     ```java
     System.out.println(list.contains(10)); // true
     ```

5. **Sorting**  
   - Arranging elements in a specific order (ascending/descending).  
   - Example: Sorting an array.  
     ```java
     Arrays.sort(arr);
     System.out.println(Arrays.toString(arr));
     ```
     **Output**:  
     ```
     [10, 20, 30]  
     ```

6. **Updation**  
   - Modifying an existing element.  
   - Example: Updating an element in an array.  
     ```java
     arr[1] = 25;
     System.out.println(Arrays.toString(arr));
     ```
     **Output**:  
     ```
     [10, 25, 30]  
     ```

---

### **1.5 Introduction to Algorithms**

#### ** Definition**
An **algorithm** is a step-by-step procedure or formula for solving a problem or performing a task.

#### ** Characteristics of a Good Algorithm**
1. **Finite**: It must have a limited number of steps.  
2. **Definite**: Each step must be clearly defined.  
3. **Input**: Takes input data.  
4. **Output**: Produces one or more outputs.  
5. **Effective**: Should be efficient and achieve the desired outcome.

#### ** Example of an Algorithm**
**Problem**: Find the largest number in an array.  

**Algorithm Steps**:  
1. Start.  
2. Initialize `max = arr[0]`.  
3. Loop through the array:  
   - If `arr[i] > max`, update `max = arr[i]`.  
4. Print `max`.  
5. End.

**Implementation in Java**:  
```java
public class LargestElement {
    public static void main(String[] args) {
        int[] arr = {10, 20, 30, 25};
        int max = arr[0];
        for (int num : arr) {
            if (num > max) {
                max = num;
            }
        }
        System.out.println("Largest Element: " + max);
    }
}
```
**Output**:  
```
Largest Element: 30
```

---

### **1.6 Computational Complexity**

#### **1. Definition**
Computational complexity measures the efficiency of an algorithm in terms of:
1. **Time Complexity**: The amount of time an algorithm takes to complete as a function of the input size.  
2. **Space Complexity**: The amount of memory an algorithm consumes during execution.

---

### **2. Importance**
Understanding computational complexity allows developers to:
- Choose optimal algorithms for different scenarios.
- Predict how an algorithm will perform as the input size grows.
- Optimize code for better performance.

---

### **3. Time Complexity**

#### **3.1 What is Time Complexity?**
Time complexity represents the number of operations an algorithm performs relative to the size of the input (`n`).

#### **3.2 Big-O Notation**
Big-O Notation is used to express the upper bound (worst-case scenario) of an algorithm's time complexity. It ignores constant factors and focuses on the growth rate.

#### **3.3 Common Big-O Complexities**

| **Complexity**    | **Description**                    | **Example**                                   |
|--------------------|------------------------------------|-----------------------------------------------|
| **O(1)**           | Constant time                     | Accessing an element in an array              |
| **O(log n)**       | Logarithmic time                  | Binary search                                 |
| **O(n)**           | Linear time                       | Traversing an array                           |
| **O(n log n)**     | Linearithmic time                 | Merge sort, Quick sort (average case)         |
| **O(n²)**          | Quadratic time                    | Nested loops in Bubble sort                   |
| **O(2ⁿ)**          | Exponential time                  | Recursive Fibonacci calculation               |
| **O(n!)**          | Factorial time                    | Solving the Traveling Salesman Problem        |

#### **3.4 Examples**

1. **O(1): Constant Time**
   ```java
   public int getFirstElement(int[] arr) {
       return arr[0]; // Always takes one step
   }
   ```
   **Explanation**: No matter the size of the array, accessing the first element takes the same amount of time.

2. **O(n): Linear Time**
   ```java
   public int findSum(int[] arr) {
       int sum = 0;
       for (int num : arr) {
           sum += num; // Loop runs for each element
       }
       return sum;
   }
   ```
   **Explanation**: The time taken grows linearly with the size of the array.

3. **O(log n): Logarithmic Time**
   ```java
   public boolean binarySearch(int[] arr, int target) {
       int left = 0, right = arr.length - 1;
       while (left <= right) {
           int mid = (left + right) / 2;
           if (arr[mid] == target) {
               return true;
           } else if (arr[mid] < target) {
               left = mid + 1;
           } else {
               right = mid - 1;
           }
       }
       return false;
   }
   ```
   **Explanation**: With each iteration, the input size is halved, leading to logarithmic growth.

4. **O(n²): Quadratic Time**
   ```java
   public void printPairs(int[] arr) {
       for (int i = 0; i < arr.length; i++) {
           for (int j = i + 1; j < arr.length; j++) {
               System.out.println(arr[i] + ", " + arr[j]);
           }
       }
   }
   ```
   **Explanation**: Two nested loops cause the time complexity to grow quadratically.

---

### **4. Space Complexity**

#### **4.1 What is Space Complexity?**
Space complexity represents the amount of memory an algorithm requires, including:
1. **Fixed Part**: Memory needed for input data and variables.  
2. **Variable Part**: Memory needed for auxiliary data structures like arrays or recursion stacks.

#### **4.2 Examples**

1. **O(1): Constant Space**
   ```java
   public int sum(int[] arr) {
       int sum = 0; // Single variable
       for (int num : arr) {
           sum += num;
       }
       return sum;
   }
   ```
   **Explanation**: The algorithm only uses a fixed amount of memory (`sum`), regardless of input size.

2. **O(n): Linear Space**
   ```java
   public int[] reverseArray(int[] arr) {
       int[] reversed = new int[arr.length]; // Auxiliary array
       for (int i = 0; i < arr.length; i++) {
           reversed[i] = arr[arr.length - 1 - i];
       }
       return reversed;
   }
   ```
   **Explanation**: Memory usage grows linearly with the input size.

3. **O(n): Space for Recursion**
   ```java
   public int factorial(int n) {
       if (n == 0) {
           return 1;
       }
       return n * factorial(n - 1);
   }
   ```
   **Explanation**: Each recursive call adds to the stack, leading to linear space usage.

---

### **5. Best, Worst, and Average Case Complexity**

#### **Best Case**:  
The minimum time required for an algorithm to complete.  
- **Example**: In linear search, the target is the first element (`O(1)`).

#### **Worst Case**:  
The maximum time required for an algorithm to complete.  
- **Example**: In linear search, the target is the last element (`O(n)`).

#### **Average Case**:  
The expected time for an algorithm to complete over multiple inputs.  
- **Example**: In linear search, the target is found halfway through the list on average (`O(n/2)`).

---

### **6. Trade-offs Between Time and Space**
- Some algorithms prioritize time efficiency over memory usage (e.g., quicksort).  
- Others prioritize low memory usage at the cost of slower execution (e.g., bubble sort).

**Example**:  
Quicksort uses more memory (stack space for recursion) but is faster (`O(n log n)`), while bubble sort uses less memory but is slower (`O(n²)`).

---

### **1.7 Asymptotic Notations and Complexity Analysis**

---

### **1. Introduction to Asymptotic Notations**
Asymptotic notations are mathematical tools used to describe the growth of an algorithm's time or space requirements relative to its input size (`n`). These notations help evaluate the efficiency of algorithms, especially for large inputs.

#### **1.1 Purpose of Asymptotic Notations**
1. Provide a **theoretical measure** of performance.
2. Abstract away hardware and implementation-specific details.
3. Compare algorithms based on their growth rates.

---

### **2. Types of Asymptotic Notations**

#### **2.1 Big-O Notation (`O`)**
- **Definition**: Represents the upper bound (worst-case) of an algorithm's complexity.
- **Usage**: Ensures the algorithm will not perform worse than the stated time complexity.

**Mathematical Definition**:  
An algorithm is `O(g(n))` if there exist positive constants `c` and `n₀` such that:  
\[ T(n) \leq c \cdot g(n) \ \forall \ n \geq n₀ \]  

**Example**:  
- For a function `T(n) = 5n² + 3n + 2`,  
  \( T(n) \) is \( O(n²) \) because \( 5n² + 3n + 2 \leq 6n² \) for \( n \geq 1 \).

---

#### **2.2 Big-Omega Notation (`Ω`)**
- **Definition**: Represents the lower bound (best-case) of an algorithm's complexity.
- **Usage**: Guarantees the algorithm will perform at least as well as the stated complexity.

**Mathematical Definition**:  
An algorithm is `Ω(g(n))` if there exist positive constants `c` and `n₀` such that:  
\[ T(n) \geq c \cdot g(n) \ \forall \ n \geq n₀ \]  

**Example**:  
- For `T(n) = 5n² + 3n + 2`,  
  \( T(n) \) is \( Ω(n²) \) because \( 5n² + 3n + 2 \geq 5n² \) for \( n \geq 1 \).

---

#### **2.3 Big-Theta Notation (`Θ`)**
- **Definition**: Represents the tight bound of an algorithm’s complexity.
- **Usage**: Shows both the upper and lower bounds of an algorithm.

**Mathematical Definition**:  
An algorithm is `Θ(g(n))` if there exist positive constants `c₁`, `c₂`, and `n₀` such that:  
\[ c₁ \cdot g(n) \leq T(n) \leq c₂ \cdot g(n) \ \forall \ n \geq n₀ \]  

**Example**:  
- For `T(n) = 5n² + 3n + 2`,  
  \( T(n) \) is \( Θ(n²) \) because it is both \( O(n²) \) and \( Ω(n²) \).

---

### **3. Properties of Asymptotic Notations**

#### **3.1 Properties of Big-O**
1. **Transitivity**: If \( T(n) = O(f(n)) \) and \( f(n) = O(g(n)) \), then \( T(n) = O(g(n)) \).
2. **Additivity**: If \( T₁(n) = O(f(n)) \) and \( T₂(n) = O(f(n)) \), then \( T₁(n) + T₂(n) = O(f(n)) \).
3. **Multiplication by Constants**: If \( T(n) = O(f(n)) \), then \( c \cdot T(n) = O(f(n)) \), where \( c > 0 \).

#### **3.2 Properties of Big-Omega**
1. **Transitivity**: If \( T(n) = Ω(f(n)) \) and \( f(n) = Ω(g(n)) \), then \( T(n) = Ω(g(n)) \).
2. **Additivity**: If \( T₁(n) = Ω(f(n)) \) and \( T₂(n) = Ω(f(n)) \), then \( T₁(n) + T₂(n) = Ω(f(n)) \).

#### **3.3 Properties of Big-Theta**
1. **Equivalence**: \( T(n) = Θ(f(n)) \) if \( T(n) = O(f(n)) \) and \( T(n) = Ω(f(n)) \).
2. **Additivity**: Similar to Big-O and Big-Omega.

---

### **4. Finding Asymptotic Complexity**

#### **Example 1: Linear Function**
**Algorithm**: Traversing an array.  
```java
for (int i = 0; i < n; i++) {
    System.out.println(i);
}
```
- Time Complexity: \( O(n) \)  
- Best Case: \( Ω(n) \)  
- Tight Bound: \( Θ(n) \)

---

#### **Example 2: Nested Loops**
**Algorithm**: Printing all pairs in an array.  
```java
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        System.out.println(i + ", " + j);
    }
}
```
- Time Complexity: \( O(n²) \)  
- Best Case: \( Ω(n²) \)  
- Tight Bound: \( Θ(n²) \)

---

#### **Example 3: Binary Search**
**Algorithm**: Searching in a sorted array.  
```java
while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        low = mid + 1;
    } else {
        high = mid - 1;
    }
}
```
- Time Complexity: \( O(\log n) \)  
- Best Case: \( Ω(1) \) (when the target is found immediately)  
- Tight Bound: \( Θ(\log n) \)

---

### **5. Best, Average, and Worst-Case Analysis**

#### **5.1 Best Case**
- Represents the **minimum time** required for the algorithm to complete.
- Example: In linear search, finding the target at the first position takes \( O(1) \).

#### **5.2 Average Case**
- Represents the **expected time** for an algorithm to complete over all inputs.
- Example: In linear search, the target is likely to be found halfway through the array on average, \( O(n/2) \), simplified to \( O(n) \).

#### **5.3 Worst Case**
- Represents the **maximum time** an algorithm might take.
- Example: In linear search, finding the target at the last position or not at all takes \( O(n) \).

---

### **6. Summary**

| **Notation** | **Definition**                          | **Example**                                   |
|--------------|------------------------------------------|-----------------------------------------------|
| **Big-O**    | Upper bound (worst-case)                | Traversing a list: \( O(n) \)                 |
| **Big-Ω**    | Lower bound (best-case)                 | Binary search: \( Ω(1) \)                     |
| **Big-Θ**    | Tight bound (average-case)              | Bubble sort: \( Θ(n²) \)                      |

- **Best Case**: Minimum operations.  
- **Average Case**: Expected operations.  
- **Worst Case**: Maximum operations.  

---

### Summary

This chapter covers the following concepts:

1. **Data Types**: Fundamental types that define the kind of data that can be stored, such as integers, floats, characters, and more.

2. **Data Structures**: Structures that organize and store data efficiently, including arrays, linked lists, stacks, queues, trees, and graphs.

3. **Abstract Data Types (ADT)**: High-level descriptions of data structures, defining operations without specifying their implementation (e.g., list, stack, queue).

4. **Operations on Data Structures**: Essential actions performed on data structures like insertion, deletion, traversal, and searching.

5. **Introduction to Algorithms**: Algorithms are step-by-step instructions to solve problems, and their design is essential for efficient problem-solving.

6. **Computational Complexity**: The study of the efficiency of algorithms in terms of time and space usage.

7. **Asymptotic Notations**: Big-O, Big-Ω, and Big-Θ notations describe the behavior of algorithms as the input size grows, helping to compare algorithm performance.

8. **Properties of Big-O, Big-Ω, and Big-Θ**: These notations provide bounds for algorithm performance, with Big-O representing upper bounds, Big-Ω representing lower bounds, and Big-Θ representing tight bounds.

9. **Finding Asymptotic Complexity**: Techniques for calculating the time and space complexity of algorithms through examples.

10. **Best, Average, and Worst-Case Analysis**: Methods for analyzing algorithms by considering different input conditions and understanding their behavior under various scenarios.




