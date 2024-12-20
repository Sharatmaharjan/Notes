### **Unit 2: Linked Lists (7 LHs)**  
#### **Basic Concept**  

Linked lists are a fundamental data structure in computer science, used to store a sequence of elements where each element is a node. Unlike arrays, linked lists are dynamic and can grow or shrink during runtime.  

---

### **1. Definition of a Linked List**  
A linked list is a collection of nodes where:  
- Each node contains two parts:  
  - **Data**: The value or information the node holds.  
  - **Pointer/Link**: A reference to the next node in the sequence.  

---

### **2. Components of a Linked List**  
- **Node**: The basic building block of a linked list containing data and a pointer.  
- **Head**: A reference to the first node in the linked list.  
- **Tail**: The last node in the linked list, whose pointer is `NULL` (indicating the end of the list).  

---

### **3. Characteristics of Linked Lists**  
- **Dynamic Size**: Can easily grow or shrink as needed.  
- **Efficient Insertions/Deletions**: No need for shifting elements like in arrays.  
- **Non-Contiguous Memory Allocation**: Nodes can be stored anywhere in memory, linked through pointers.  

---

### **4. Types of Linked Lists**  
1. **Singly Linked List**:  
   - Each node points to the next node.  
   - The last node points to `NULL`.  
   - Example structure: `A -> B -> C -> NULL`  

2. **Doubly Linked List**:  
   - Each node has two pointers:  
     - One to the next node.  
     - One to the previous node.  
   - Example structure: `NULL <- A <-> B <-> C -> NULL`  

3. **Circular Linked List**:  
   - The last node points back to the first node.  
   - Can be singly or doubly circular.  
   - Example structure: `A -> B -> C -> A`  

---

### **5. Advantages of Linked Lists**  
- **Dynamic Memory Allocation**: Nodes are created as needed, reducing memory wastage.  
- **Efficient Insertions and Deletions**: Insertions and deletions are easier compared to arrays as no shifting is required.  
- **Flexibility**: Size is not fixed, unlike arrays.  

---

### **6. Disadvantages of Linked Lists**  
- **Sequential Access**: Must traverse the list to access elements (no random access like arrays).  
- **Extra Memory**: Requires additional memory for storing pointers.  
- **Complexity**: More complex to implement and debug compared to arrays.  

---

### **7. Operations on Linked Lists**  
1. **Traversal**: Accessing and processing each node in the list sequentially.  
2. **Insertion**: Adding a new node to the list at various positions:  
   - At the beginning.  
   - At the end.  
   - At a specific position.  
3. **Deletion**: Removing a node from the list:  
   - From the beginning.  
   - From the end.  
   - From a specific position.  
4. **Searching**: Finding a node containing specific data.  
5. **Reversing**: Changing the direction of pointers to reverse the list.  

---



### **8. Applications of Linked Lists**  
- Implementing stacks and queues.  
- Dynamic memory allocation (used in operating systems).  
- Representation of sparse matrices.  
- Used in graph representations like adjacency lists.  
- Undo functionality in text editors.  

---

### **List and Abstract Data Type (ADT) in Linked List (Java)**  

Java provides a built-in implementation of **LinkedList** as part of the `java.util` package, which fulfills the **List ADT** operations dynamically.

---

### **1. Linked List in Java**  
A **LinkedList** in Java is a **class** that implements the `List`, `Deque`, and `Queue` interfaces. It can act as:  
- A **Singly Linked List**  
- A **Doubly Linked List**

The **LinkedList** class in Java is part of the **List ADT** family, meaning it supports operations like insertion, deletion, traversal, etc.

---

### **2. Declaration and Initialization**  
```java
import java.util.LinkedList;

LinkedList<Integer> list = new LinkedList<>();
```

---

### **3. Operations in LinkedList as List ADT**  

#### **a. Insertion**  
1. **Add at the end**:  
   ```java
   list.add(10); // Adds 10 to the end of the list
   ```
2. **Add at a specific index**:  
   ```java
   list.add(1, 20); // Adds 20 at index 1
   ```
3. **Add at the beginning**:  
   ```java
   list.addFirst(5); // Adds 5 to the beginning
   ```

#### **b. Deletion**  
1. **Remove by index**:  
   ```java
   list.remove(2); // Removes the element at index 2
   ```
2. **Remove by value**:  
   ```java
   list.remove(Integer.valueOf(10)); // Removes the first occurrence of 10
   ```
3. **Remove the first element**:  
   ```java
   list.removeFirst(); // Removes the first element
   ```
4. **Remove the last element**:  
   ```java
   list.removeLast(); // Removes the last element
   ```

#### **c. Access/Retrieve Elements**  
1. **Access by index**:  
   ```java
   int value = list.get(1); // Retrieves the element at index 1
   ```
2. **Get the first element**:  
   ```java
   int first = list.getFirst();
   ```
3. **Get the last element**:  
   ```java
   int last = list.getLast();
   ```

#### **d. Traverse the LinkedList**  
Using a **for-each loop**:  
```java
for (int element : list) {
    System.out.println(element);
}
```

Using an **iterator**:  
```java
Iterator<Integer> iterator = list.iterator();
while (iterator.hasNext()) {
    System.out.println(iterator.next());
}
```

#### **e. Check Size and Properties**  
1. **Size of the list**:  
   ```java
   int size = list.size();
   ```
2. **Check if empty**:  
   ```java
   boolean isEmpty = list.isEmpty();
   ```

#### **f. Clear the List**  
```java
list.clear(); // Removes all elements
```  
  
  

---

### **Example Code**:  
```java
import java.util.LinkedList;

public class LinkedListExample {
    public static void main(String[] args) {
        // Create a LinkedList
        LinkedList<String> names = new LinkedList<>();

        // Add elements
        names.add("Alice");
        names.add("Bob");
        names.addLast("Charlie");
        names.addFirst("Zara");

        // Print the LinkedList
        System.out.println("LinkedList: " + names);

        // Remove an element
        names.remove("Bob");
        System.out.println("After removing Bob: " + names);

        // Access an element
        System.out.println("First element: " + names.getFirst());

        // Traverse the list
        System.out.println("Elements in the list:");
        for (String name : names) {
            System.out.println(name);
        }
    }
}
```

**Output**:  
```
LinkedList: [Zara, Alice, Bob, Charlie]  
After removing Bob: [Zara, Alice, Charlie]  
First element: Zara  
Elements in the list:  
Zara  
Alice  
Charlie  
```

---

