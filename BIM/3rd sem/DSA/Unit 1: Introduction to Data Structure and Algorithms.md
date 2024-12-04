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

#### **Summary**
1. **Data Types**: Foundation of variables and values in Java, classified as primitive (e.g., `int`, `float`) and non-primitive (e.g., Strings, Arrays).  
2. **Data Structures**: Efficient organization of data into **Linear** (e.g., Arrays, Stacks) or **Non-Linear** (e.g., Trees, Graphs) forms.  
3. **Abstract Data Types (ADTs)**: Logical representations like Stack, Queue, and List, focusing on operations rather than implementation details.

These concepts are essential to understand algorithms and solve computational problems effectively.
