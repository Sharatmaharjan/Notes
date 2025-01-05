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

### **Array Implementation of Lists**  

The **Array Implementation of Lists** uses a fixed-size or dynamic array to store list elements. The list operations are performed using array indices. 

---

### **1. Array Representation**  
- **Index-based**: Each element in the list is stored at a specific index in the array.  
- **Sequential Memory Allocation**: Elements are stored contiguously in memory.

---

### **2. Operations in Array Implementation**  

#### **a. Insertion**  
1. **At the end**:  
   - Add the element to the next available index.  
   **Time Complexity**: \(O(1)\).  

2. **At a specific position**:  
   - Shift elements to the right to make space.  
   **Time Complexity**: \(O(n)\).  

   **Example**:  
   ```java
   void insertAt(int[] arr, int size, int pos, int value) {
       for (int i = size; i > pos; i--) {
           arr[i] = arr[i - 1];
       }
       arr[pos] = value;
   }
   ```

#### **b. Deletion**  
1. **From the end**:  
   - Decrease the size.  
   **Time Complexity**: \(O(1)\).  

2. **From a specific position**:  
   - Shift elements to the left to fill the gap.  
   **Time Complexity**: \(O(n)\).  

   **Example**:  
   ```java
   void deleteAt(int[] arr, int size, int pos) {
       for (int i = pos; i < size - 1; i++) {
           arr[i] = arr[i + 1];
       }
   }
   ```

#### **c. Access**  
1. Direct access using index:  
   **Time Complexity**: \(O(1)\).  

---

### **Advantages**  
1. **Fast Access**: Direct indexing allows constant time access.  
2. **Simple Implementation**: Easy to implement and understand.  

---

### **Disadvantages**  
1. **Fixed Size**: Static arrays cannot grow dynamically without reallocation.  
2. **Costly Insertions/Deletions**: Requires shifting elements.  
3. **Wastage of Memory**: Allocating extra space for future growth may lead to unused memory.  

---

### **Linked List Implementation of Lists**  

A **Linked List** implements lists dynamically using nodes. Each node contains:  
1. **Data**: Stores the value.  
2. **Pointer**: Points to the next node (or previous node for doubly linked lists).

---

Here’s a detailed explanation of basic operations in a **Singly Linked List** using both **head** and **tail** concepts:

### 1. **Linked List Representation**  

In a **Singly Linked List**, each node contains two fields:
- **data**: Stores the value of the node.
- **next**: Points to the next node in the list.

Additionally, the list maintains:
- **head**: Points to the first node in the list.
- **tail**: Points to the last node in the list.

### 2. **Node Structure**
```java
class Node {
    int data;
    Node next;

    // Constructor to initialize a node with data
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}
```

### 3. **Linked List Class**
```java
class LinkedList {
    Node head; // Points to the first node
    Node tail; // Points to the last node
}
```

### 4. **Basic Operations in Linked List**  

#### a. **Insertion**

1. **At the Beginning**  
   To insert a node at the beginning, create a new node, link it to the current head, and update the head. If the list is empty, update the tail to point to the new node as well.

   **Time Complexity**: \(O(1)\).

   ```java
   public void addNodeAtBeginning(int newData) {
       Node newNode = new Node(newData);
       newNode.next = head;  // Link the new node to the current head
       head = newNode;       // Update head to point to the new node

       // If the list was empty, update tail as well
       if (tail == null) {
           tail = newNode;
       }
   }
   ```

2. **At the End**  
   To insert a node at the end, create a new node, check if the list is empty (in which case both head and tail will point to it), or traverse to the last node and link it to the new node.

   **Time Complexity**: \(O(1)\) (when using tail reference), otherwise \(O(n)\).

   ```java
   public void addNodeAtEnd(int newData) {
       Node newNode = new Node(newData);
       if (tail == null) {
           // List is empty, new node becomes both head and tail
           head = newNode;
           tail = newNode;
       } else {
           // Link the current tail to the new node
           tail.next = newNode;
           tail = newNode; // Update the tail to the new node
       }
   }
   ```

3. **At a Specific Position**  
   To insert a node at a specific position, traverse to the desired position and insert the new node.

   **Time Complexity**: \(O(n)\).

   ```java
   public void addNodeAtPosition(int newData, int position) {
       if (position == 0) {
           addNodeAtBeginning(newData);  // Insert at the beginning
           return;
       }

       Node newNode = new Node(newData);
       Node temp = head;
       for (int i = 0; i < position - 1 && temp != null; i++) {
           temp = temp.next;
       }

       if (temp != null) {
           newNode.next = temp.next;
           temp.next = newNode;

           // If inserting at the end, update tail
           if (temp == tail) {
               tail = newNode;
           }
       }
   }
   ```

---

#### b. **Deletion**

1. **From the Beginning**  
   To remove the first node, update the head to point to the next node. If the list becomes empty, update tail to `null`.

   **Time Complexity**: \(O(1)\).

   ```java
   public void removeNodeFromBeginning() {
       if (head != null) {
           head = head.next;  // Move head to the next node
           if (head == null) { // If the list is empty, reset tail
               tail = null;
           }
       }
   }
   ```

2. **From the End**  
   To remove the last node, traverse to the second-last node and update its next pointer to `null`. Update tail to point to the second-last node.

   **Time Complexity**: \(O(n)\).

   ```java
   public void removeNodeFromEnd() {
       if (head == null) {
           return; // List is empty
       }
       if (head.next == null) {
           head = null;  // List has only one node
           tail = null;
           return;
       }

       Node temp = head;
       while (temp.next != tail) {
           temp = temp.next;
       }
       temp.next = null;  // Remove the last node
       tail = temp;  // Update the tail to the second-last node
   }
   ```

3. **From a Specific Position**  
   To remove a node at a specific position, traverse to the node before the target node, and update its next pointer.

   **Time Complexity**: \(O(n)\).

   ```java
   public void removeNodeFromPosition(int position) {
       if (position == 0) {
           removeNodeFromBeginning();  // Remove from the beginning
           return;
       }

       Node temp = head;
       for (int i = 0; i < position - 1 && temp != null; i++) {
           temp = temp.next;
       }

       if (temp != null && temp.next != null) {
           temp.next = temp.next.next;  // Remove the target node

           // If the node removed was the tail, update the tail
           if (temp.next == null) {
               tail = temp;
           }
       }
   }
   ```

---

#### c. **Traversal**

To traverse the list, start from the head and visit each node until reaching the end (where `next` is `null`).

**Time Complexity**: \(O(n)\).

```java
public void printList() {
    Node temp = head;
    while (temp != null) {
        System.out.print(temp.data + " -> ");
        temp = temp.next;
    }
    System.out.println("null");
}
```

---

### **Comparison: Array vs. Linked List**

| **Aspect**             | **Array**                              | **Linked List**                       |
|-------------------------|-----------------------------------------|---------------------------------------|
| **Memory Allocation**   | Static or dynamic                      | Fully dynamic                         |
| **Insertion/Deletion**  | Costly (requires shifting)             | Efficient at beginning/middle         |
| **Access**              | Direct access via index \(O(1)\)       | Sequential access \(O(n)\)            |
| **Memory Usage**        | Contiguous memory blocks               | Extra memory for pointers             |
| **Size Flexibility**    | Fixed size (unless resized dynamically)| Grows and shrinks dynamically         |

---

### **Summary**  
- **Array** is better suited for scenarios requiring frequent random access due to its constant time complexity for indexing.  
- **Linked List** is ideal for applications requiring frequent insertions and deletions, particularly when the size of the list is unpredictable.

---

### **Types of Linked Lists**

Linked lists are data structures consisting of nodes where each node contains data and a reference (or pointer) to the next (or previous) node. Based on how nodes are linked, linked lists are classified into the following types:

---

### **1. Singly Linked List**

#### **Description**  
- Each node has two parts:  
  1. **Data**: Stores the value.  
  2. **Next**: A pointer to the next node in the list.  
- Traversal is unidirectional, i.e., from the head node to the last node.  
- The last node points to `null`.

#### **Structure**  
```
[Data | Next] -> [Data | Next] -> [Data | Null]
```

#### **Operations**  
- **Insertion**: At the beginning, end, or specific position.  
- **Deletion**: From the beginning, end, or specific position.  
- **Traversal**: Starts from the head and visits each node sequentially.

#### **Advantages**  
- Uses less memory compared to other linked lists.  
- Simple implementation.  

#### **Disadvantages**  
- Cannot traverse backward.  
- Searching is \(O(n)\).

#### **Example Code**  
```java
class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class SinglyLinkedList {
    Node head;

    void insertAtEnd(int value) {
        Node newNode = new Node(value);
        if (head == null) {
            head = newNode;
            return;
        }
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
    }

    void traverse() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("null");
    }
}
```

---

### **2. Doubly Linked List**

#### **Description**  
- Each node has three parts:  
  1. **Data**: Stores the value.  
  2. **Next**: Pointer to the next node.  
  3. **Prev**: Pointer to the previous node.  
- Traversal is bidirectional (forward and backward).  
- The first node's `Prev` is `null`, and the last node's `Next` is `null`.

#### **Structure**  
```
Null <- [Prev | Data | Next] <-> [Prev | Data | Next] -> Null
```

#### **Operations**  
- **Insertion**: At the beginning, end, or specific position.  
- **Deletion**: From the beginning, end, or specific position.  
- **Traversal**: Can traverse forward or backward.

#### **Advantages**  
- Can traverse in both directions.  
- Easier to delete nodes compared to a singly linked list.  

#### **Disadvantages**  
- Requires more memory due to the additional pointer.  
- More complex to implement.

#### **Example Code**  
```java
class DoublyNode {
    int data;
    DoublyNode next;
    DoublyNode prev;

    DoublyNode(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLinkedList {
    DoublyNode head;

    void insertAtEnd(int value) {
        DoublyNode newNode = new DoublyNode(value);
        if (head == null) {
            head = newNode;
            return;
        }
        DoublyNode temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
        newNode.prev = temp;
    }

    void traverseForward() {
        DoublyNode temp = head;
        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("null");
    }

    void traverseBackward() {
        DoublyNode temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.prev;
        }
        System.out.println("null");
    }
}
```

---

### **3. Circular Linked List**

#### **Description**  
- A variation of singly or doubly linked lists where the last node points back to the first node, forming a circle.  
- In a **singly circular linked list**, only the `Next` pointer exists.  
- In a **doubly circular linked list**, both `Next` and `Prev` pointers exist.  

#### **Structure**  
1. **Singly Circular Linked List**:  
   ```
   [Data | Next] -> [Data | Next] -> [Data | Next] -+
      ^--------------------------------------------+
   ```
2. **Doubly Circular Linked List**:  
   ```
   Null <- [Prev | Data | Next] <-> [Prev | Data | Next] <->
            ^------------------------------------------+
   ```

#### **Operations**  
- Similar to singly or doubly linked lists, but traversal is cyclic.  

#### **Advantages**  
- Can traverse the entire list starting from any node.  
- Efficient for applications requiring cyclic iterations (e.g., round-robin scheduling).

#### **Disadvantages**  
- Risk of infinite loops during traversal.  
- Slightly complex to implement.  

#### **Example Code (Singly Circular)**  
```java
class CircularNode {
    int data;
    CircularNode next;

    CircularNode(int data) {
        this.data = data;
        this.next = null;
    }
}

class CircularLinkedList {
    CircularNode head;

    void insertAtEnd(int value) {
        CircularNode newNode = new CircularNode(value);
        if (head == null) {
            head = newNode;
            newNode.next = head;
            return;
        }
        CircularNode temp = head;
        while (temp.next != head) {
            temp = temp.next;
        }
        temp.next = newNode;
        newNode.next = head;
    }

    void traverse() {
        if (head == null) return;
        CircularNode temp = head;
        do {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        } while (temp != head);
        System.out.println("(back to head)");
    }
}
```

---

### **Comparison of Linked List Types**

| **Feature**                | **Singly Linked List**     | **Doubly Linked List**         | **Circular Linked List**              |
|-----------------------------|----------------------------|---------------------------------|----------------------------------------|
| **Traversal**               | Forward only              | Forward and backward           | Cyclic (from any node)                |
| **Memory Requirement**      | Less                      | More (extra `Prev` pointer)    | Same as singly/doubly (cyclic nature) |
| **Insertion/Deletion**      | Less efficient in middle  | More efficient in middle       | Efficient for cyclic operations       |
| **Complexity**              | Simple                    | Moderate                       | Moderate                              |

---

### **Summary**  
Each type of linked list has unique advantages suited to specific use cases:  
- **Singly Linked List**: Efficient and memory-saving for unidirectional traversal.  
- **Doubly Linked List**: Ideal for bidirectional traversal and easier node deletions.  
- **Circular Linked List**: Best for cyclic tasks like round-robin scheduling.


---

### **Basic Operations in Linked List**

Linked lists support a variety of operations, including creating nodes, inserting nodes at various positions, and deleting nodes. Below are the details:

---

### **1. Node Creation**

#### **Description**  
A node is the basic unit of a linked list, consisting of:  
- **Data**: Stores the value.  
- **Next**: Points to the next node in the list (or `null` if it is the last node).

#### **Code Example (Java)**  
```java
class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}
```

---

### **2. Node Insertion**

Insertion can be performed at three main positions:  
- At the **beginning**.  
- At the **end**.  
- At a **specific position**.

#### **a. Insertion at the Beginning**  
- Create a new node.  
- Point its `next` to the current head.  
- Update the head to the new node.

**Code Example**:  
```java
class LinkedList {
    Node head;

    void insertAtBeginning(int value) {
        Node newNode = new Node(value);
        newNode.next = head;
        head = newNode;
    }
}
```

---

#### **b. Insertion at the End**  
- Create a new node.  
- Traverse the list to the last node.  
- Update the last node's `next` pointer to the new node.

**Code Example**:  
```java
void insertAtEnd(int value) {
    Node newNode = new Node(value);
    if (head == null) {
        head = newNode;
        return;
    }
    Node temp = head;
    while (temp.next != null) {
        temp = temp.next;
    }
    temp.next = newNode;
}
```

---

#### **c. Insertion at a Specific Position**  
- Traverse the list to the desired position.  
- Update the `next` pointers to include the new node at the specified position.

**Code Example**:  
```java
void insertAtPosition(int value, int position) {
    Node newNode = new Node(value);
    if (position == 0) {
        newNode.next = head;
        head = newNode;
        return;
    }
    Node temp = head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == null) throw new IndexOutOfBoundsException("Invalid Position");
        temp = temp.next;
    }
    newNode.next = temp.next;
    temp.next = newNode;
}
```

---

### **3. Node Deletion**

Deletion can be performed at:  
- The **beginning**.  
- The **end**.  
- A **specific position**.

#### **a. Deletion from the Beginning**  
- Update the head pointer to the next node.  
- The old head node is removed.

**Code Example**:  
```java
void deleteFromBeginning() {
    if (head == null) {
        System.out.println("List is empty.");
        return;
    }
    head = head.next;
}
```

---

#### **b. Deletion from the End**  
- Traverse the list to find the second last node.  
- Update the second last node's `next` pointer to `null`.

**Code Example**:  
```java
void deleteFromEnd() {
    if (head == null) {
        System.out.println("List is empty.");
        return;
    }
    if (head.next == null) {
        head = null;
        return;
    }
    Node temp = head;
    while (temp.next.next != null) {
        temp = temp.next;
    }
    temp.next = null;
}
```

---

#### **c. Deletion from a Specific Position**  
- Traverse the list to the node before the specified position.  
- Update its `next` pointer to skip the node at the specified position.

**Code Example**:  
```java
void deleteFromPosition(int position) {
    if (head == null) {
        System.out.println("List is empty.");
        return;
    }
    if (position == 0) {
        head = head.next;
        return;
    }
    Node temp = head;
    for (int i = 0; i < position - 1; i++) {
        if (temp.next == null) throw new IndexOutOfBoundsException("Invalid Position");
        temp = temp.next;
    }
    if (temp.next == null) throw new IndexOutOfBoundsException("Invalid Position");
    temp.next = temp.next.next;
}
```

---

### **Complete Example with Basic Operations**  

```java
package SinglyLinkedList;

// Node class to represent a node in the linked list
class Node {
    int data;
    Node next;

    // Constructor to initialize a node with data
    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

package SinglyLinkedList;

// LinkedList class to manage operations on the linked list
class LinkedList {
    Node head; // Head of the linked list
    Node tail; // Tail of the linked list

    // Constructor to initialize an empty linked list
    public LinkedList() {
        this.head = null;
        this.tail = null;
    }

    // Method to add a node at the beginning of the linked list
    public void addNodeAtBeginning(int newData) {
        Node newNode = new Node(newData); // Create a new node with the given data
        newNode.next = head; // Link the new node to the rest of the list
        head = newNode; // Update the head to point to the new node
        if (tail == null) { // Update tail if the list was empty
            tail = newNode;
        }
    }

    // Method to add a node at the end of the linked list
    public void addNodeAtEnd(int newData) {
        Node newNode = new Node(newData); // Create a new node with the given data
        if (head == null) { // Check if the list is empty
            head = newNode;
            tail = newNode;
            return;
        }
        tail.next = newNode; // Link the last node to the new node
        tail = newNode; // Update the tail to be the new node
    }

    // Method to add a node at a specified position in the linked list
    public void addNodeAtPosition(int newData, int position) {
        if (head == null) { // Check for an empty list
            System.out.println("List is empty. Adding node at the beginning.");
            addNodeAtBeginning(newData);
            return;
        }
        if (position == 0) { // If position is 0, add node at the beginning
            addNodeAtBeginning(newData);
            return;
        }
        Node newNode = new Node(newData); // Create a new node with the given data
        Node current = head;

        // Traverse the list to find the node at position-1
        for (int i = 1; i < position && current != null; i++) {
            current = current.next;
        }

        if (current == null) { // If position exceeds the length of the list
            System.out.println("Position exceeds the length of the list. Adding at the end.");
            addNodeAtEnd(newData);
            return;
        }
        newNode.next = current.next; // Link the new node to the rest of the list
        current.next = newNode;

        if (newNode.next == null) { // Update tail if the new node is added at the end
            tail = newNode;
        }
    }

    // Method to remove a node from the beginning of the linked list
    public void removeNodeFromBeginning() {
        if (head == null) { // Check if the list is empty
            System.out.println("List is empty. Cannot remove from the beginning.");
            return;
        }
        if (head.next == null) { // If there is only one node
            head = null;
            tail = null;
            return;
        }
        head = head.next; // Update the head to the next node
    }

    // Method to remove a node from the end of the linked list
    public void removeNodeFromEnd() {
        if (head == null) { // Check if the list is empty
            System.out.println("List is empty. Cannot remove from the end.");
            return;
        }
        if (head.next == null) { // If there is only one node
            head = null;
            tail = null;
            return;
        }
        Node current = head;
        while (current.next.next != null) { // Traverse the list to find the second-to-last node
            current = current.next;
        }
        current.next = null; // Remove the last node
        tail = current; // Update tail
    }

    // Method to remove a node from a specified position in the linked list
    public void removeNodeFromPosition(int position) {
        if (head == null) { // Check for an empty list
            System.out.println("List is empty. Cannot remove from a specified position.");
            return;
        }
        if (position == 0) { // If position is 0, remove node from the beginning
            removeNodeFromBeginning();
            return;
        }
        Node current = head;
        Node previous = null;

        for (int i = 0; i < position && current != null; i++) { // Traverse the list to find the node at position-1
            previous = current;
            current = current.next;
        }

        if (current == null) { // If position exceeds the length of the list
            System.out.println("Position exceeds the length of the list. Cannot remove.");
            return;
        }
        previous.next = current.next; // Remove the node at the specified position

        if (current.next == null) { // Update tail if the last node is removed
            tail = previous;
        }
    }

    // Method to search for a given data
    public boolean isInList(int data) {
        Node current = head;
        while (current != null) {
            if (current.data == data) {
                return true;
            }
            current = current.next;
        }
        return false;
    }

    // Method to print the linked list
    public void printList() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " -> ");
            current = current.next;
        }
        System.out.println("null");
    }
}

package SinglyLinkedList;
// Main class to demonstrate linked list operations
public class Main {
    public static void main(String[] args) {
        // Create a linked list
        LinkedList linkedList = new LinkedList();

        // Add nodes at the beginning of the linked list
        linkedList.addNodeAtBeginning(3);
        linkedList.addNodeAtBeginning(2);
        linkedList.addNodeAtBeginning(1);

        // Print the linked list
        System.out.println("Linked List after adding nodes at the beginning:");
        linkedList.printList();

        // Add a node at the end of the linked list
        linkedList.addNodeAtEnd(4);
        linkedList.addNodeAtEnd(5);

        // Print the linked list
        System.out.println("\nLinked List after adding nodes at the end:");
        linkedList.printList();

        // Add a node at a specified position in the linked list
        linkedList.addNodeAtPosition(10, 2);

        // Print the linked list
        System.out.println("\nLinked List after adding a node at position 2:");
        linkedList.printList();

        // Remove a node from the beginning of the linked list
        linkedList.removeNodeFromBeginning();
        System.out.println("\nLinked List after removing a node from the beginning:");
        linkedList.printList();

        // Remove a node from the end of the linked list
        linkedList.removeNodeFromEnd();
        System.out.println("\nLinked List after removing a node from the end:");
        linkedList.printList();

        // Remove a node from a specified position in the linked list
        linkedList.removeNodeFromPosition(2);
        System.out.println("\nLinked List after removing a node at position 2:");
        linkedList.printList();

        // Check if a value exists in the list
        System.out.println("\nIs 10 in the list? " + linkedList.isInList(10));
        System.out.println("Is 3 in the list? " + linkedList.isInList(3));
    }
}
```

---

### Sample Output:

```
Linked List after adding nodes at the beginning:
1 -> 2 -> 3 -> null

Linked List after adding nodes at the end:
1 -> 2 -> 3 -> 4 -> 5 -> null

Linked List after adding a node at position 2:
1 -> 2 -> 10 -> 3 -> 4 -> 5 -> null

Linked List after removing a node from the beginning:
2 -> 10 -> 3 -> 4 -> 5 -> null

Linked List after removing a node from the end:
2 -> 10 -> 3 -> 4 -> null

Linked List after removing a node at position 2:
2 -> 10 -> 4 -> null

Is 10 in the list? true
Is 3 in the list? false
```

---

### Doubly Linked List Code Complete Code

```java
package DoublyLinkedList;

// Node class to represent a node in the doubly linked list
class Node {
    int data;
    Node next;
    Node prev;

    // Constructor to initialize a node with data
    public Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

package DoublyLinkedList;

// LinkedList class to manage operations on the doubly linked list
class LinkedList {
    Node head; // Head of the linked list
    Node tail; // Tail of the linked list

    // Constructor to initialize an empty linked list
    public LinkedList() {
        this.head = null;
        this.tail = null;
    }


// Method to add a node at the beginning of the doubly linked list
public void addNodeAtBeginning(int newData) {
    Node newNode = new Node(newData); // Create a new node with the given data

    if (head == null) { // Check if the list is empty
        head = newNode;
        tail = newNode;
        return;
    }

    newNode.next = head; // Link the new node to the current head
    head.prev = newNode; // Update the current head's previous link to the new node
    head = newNode; // Update the head to the new node
}

    // Method to add a node at the end of the doubly linked list
    public void addNodeAtEnd(int newData) {
        Node newNode = new Node(newData);

        if (head == null) { // If the list is empty
            head = newNode;
            tail = newNode;
            return;
        }

        tail.next = newNode;
        newNode.prev = tail;
        tail = newNode;
    }

    // Method to add a node at a specified position in the doubly linked list
    public void addNodeAtPosition(int newData, int position) {
        if (position == 0) {
            addNodeAtBeginning(newData);
            return;
        }

        Node newNode = new Node(newData);
        Node current = head;

        for (int i = 0; i < position - 1 && current != null; i++) {
            current = current.next;
        }

        if (current == null) {
            System.out.println("Position exceeds the length of the list. Adding at the end.");
            addNodeAtEnd(newData);
            return;
        }

        newNode.next = current.next;
        if (current.next != null) {
            current.next.prev = newNode;
        } else {
            tail = newNode; // If added at the end, update tail
        }

        current.next = newNode;
        newNode.prev = current;
    }

    // Method to remove a node from the beginning of the doubly linked list
    public void removeNodeFromBeginning() {
        if (head == null) {
            System.out.println("List is empty. Cannot remove from the beginning.");
            return;
        }

        head = head.next;

        if (head != null) {
            head.prev = null;
        } else {
            tail = null; // If the list becomes empty, update tail
        }
    }

    // Method to remove a node from the end of the doubly linked list
    public void removeNodeFromEnd() {
        if (head == null) {
            System.out.println("List is empty. Cannot remove from the end.");
            return;
        }

        if (head.next == null) {
            head = null;
            tail = null;
            return;
        }

        tail = tail.prev;
        tail.next = null;
    }

    // Method to remove a node from a specified position in the doubly linked list
    public void removeNodeFromPosition(int position) {
        if (head == null) {
            System.out.println("List is empty. Cannot remove from a specified position.");
            return;
        }

        if (position == 0) {
            removeNodeFromBeginning();
            return;
        }

        Node current = head;

        for (int i = 0; i < position && current != null; i++) {
            current = current.next;
        }

        if (current == null) {
            System.out.println("Position exceeds the length of the list. Cannot remove.");
            return;
        }

        if (current.next != null) {
            current.next.prev = current.prev;
        } else {
            tail = current.prev; // Update tail if the last node is removed
        }

        if (current.prev != null) {
            current.prev.next = current.next;
        }
    }

    // Method to search for a given data
    public boolean isInList(int data) {
        Node current = head;
        while (current != null) {
            if (current.data == data) {
                return true;
            }
            current = current.next;
        }
        return false;
    }

    // Method to print the doubly linked list
    public void printList() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " <-> ");
            current = current.next;
        }
        System.out.println("null");
    }
}

package DoublyLinkedList;
// Main class to demonstrate doubly linked list operations
public class Main {
    public static void main(String[] args) {
        // Create a doubly linked list
        LinkedList linkedList = new LinkedList();

        // Add nodes at the beginning of the linked list
        linkedList.addNodeAtBeginning(3);
        linkedList.addNodeAtBeginning(2);
        linkedList.addNodeAtBeginning(1);

        // Print the linked list
        System.out.println("Doubly Linked List after adding nodes at the beginning:");
        linkedList.printList();

        // Add a node at the end of the linked list
        linkedList.addNodeAtEnd(4);
        linkedList.addNodeAtEnd(5);

        // Print the linked list
        System.out.println("\nDoubly Linked List after adding nodes at the end:");
        linkedList.printList();

        // Add a node at a specified position in the linked list
        linkedList.addNodeAtPosition(10, 2);

        // Print the linked list
        System.out.println("\nDoubly Linked List after adding a node at position 2:");
        linkedList.printList();

        // Remove a node from the beginning of the linked list
        linkedList.removeNodeFromBeginning();
        System.out.println("\nDoubly Linked List after removing a node from the beginning:");
        linkedList.printList();

        // Remove a node from the end of the linked list
        linkedList.removeNodeFromEnd();
        System.out.println("\nDoubly Linked List after removing a node from the end:");
        linkedList.printList();

        // Remove a node from a specified position in the linked list
        linkedList.removeNodeFromPosition(2);
        System.out.println("\nDoubly Linked List after removing a node at position 2:");
        linkedList.printList();

        // Check if a value exists in the list
        System.out.println("\nIs 10 in the list? " + linkedList.isInList(10));
        System.out.println("Is 3 in the list? " + linkedList.isInList(3));
    }
}
```

--- 


### **Skip List**  

#### **Definition**  
A **Skip List** is a data structure that allows fast search, insertion, and deletion operations. It builds multiple levels of linked lists where:  
- The bottom level contains all elements in a simple sorted linked list.  
- Higher levels provide shortcuts to jump over multiple elements.

#### **Structure**  
- Each node contains:  
  - A key (data).  
  - Multiple pointers, one for each level.  
- Skip lists use probabilistic balancing, unlike balanced trees that require rotations.  

#### **Operations**  
1. **Search**  
   - Start at the highest level.  
   - Move forward until the target key is greater than the current node's key.  
   - Drop down a level and repeat until the key is found or the search reaches the bottom level.  

2. **Insertion**  
   - Determine the level for the new node based on random probability.  
   - Insert the node into all applicable levels.

3. **Deletion**  
   - Remove the node from all levels where it exists.

#### **Advantages**  
- Easier to implement than balanced trees.  
- Supports logarithmic time complexity for search, insertion, and deletion.  

#### **Code Example (Java)**  
```java
import java.util.Random;

class SkipListNode {
    int key;
    SkipListNode[] next;

    public SkipListNode(int key, int level) {
        this.key = key;
        this.next = new SkipListNode[level + 1];
    }
}

class SkipList {
    private static final int MAX_LEVEL = 4;
    private final SkipListNode head;
    private final Random random;

    public SkipList() {
        head = new SkipListNode(Integer.MIN_VALUE, MAX_LEVEL);
        random = new Random();
    }

    private int randomLevel() {
        int level = 0;
        while (level < MAX_LEVEL && random.nextInt(2) == 0) {
            level++;
        }
        return level;
    }

    public void insert(int key) {
        SkipListNode current = head;
        SkipListNode[] update = new SkipListNode[MAX_LEVEL + 1];
        for (int i = MAX_LEVEL; i >= 0; i--) {
            while (current.next[i] != null && current.next[i].key < key) {
                current = current.next[i];
            }
            update[i] = current;
        }

        int level = randomLevel();
        SkipListNode newNode = new SkipListNode(key, level);
        for (int i = 0; i <= level; i++) {
            newNode.next[i] = update[i].next[i];
            update[i].next[i] = newNode;
        }
    }

    public boolean search(int key) {
        SkipListNode current = head;
        for (int i = MAX_LEVEL; i >= 0; i--) {
            while (current.next[i] != null && current.next[i].key < key) {
                current = current.next[i];
            }
        }
        current = current.next[0];
        return current != null && current.key == key;
    }

    public void delete(int key) {
        SkipListNode current = head;
        SkipListNode[] update = new SkipListNode[MAX_LEVEL + 1];
        for (int i = MAX_LEVEL; i >= 0; i--) {
            while (current.next[i] != null && current.next[i].key < key) {
                current = current.next[i];
            }
            update[i] = current;
        }

        current = current.next[0];
        if (current != null && current.key == key) {
            for (int i = 0; i <= MAX_LEVEL; i++) {
                if (update[i].next[i] != current) break;
                update[i].next[i] = current.next[i];
            }
        }
    }
}
```

---

### **Lists in `java.util`**

Java provides built-in implementations of lists in the `java.util` package, including **`LinkedList`** and **`ArrayList`**.

---

#### **1. ArrayList**

##### **Features**  
- A resizable array implementation.  
- Allows random access using an index.  
- Not synchronized.  

##### **Usage**  
```java
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        ArrayList<Integer> arrayList = new ArrayList<>();
        arrayList.add(10); // Add element
        arrayList.add(20);
        arrayList.add(30);

        System.out.println("ArrayList: " + arrayList);
        arrayList.remove(1); // Remove element at index 1
        System.out.println("After removal: " + arrayList);
    }
}
```

##### **Advantages**  
- Fast for random access and updates.  
- Automatically resizes when full.  

##### **Disadvantages**  
- Inefficient for insertion/deletion (except at the end) due to shifting elements.

---

#### **2. LinkedList**

##### **Features**  
- A doubly linked list implementation.  
- Efficient for insertion and deletion.  
- Not synchronized.  

##### **Usage**  
```java
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {
        LinkedList<Integer> linkedList = new LinkedList<>();
        linkedList.add(10); // Add element
        linkedList.addFirst(5); // Add at the beginning
        linkedList.addLast(15); // Add at the end

        System.out.println("LinkedList: " + linkedList);
        linkedList.remove(1); // Remove element at index 1
        System.out.println("After removal: " + linkedList);
    }
}
```

##### **Advantages**  
- Fast for insertion/deletion at the beginning or middle.  
- No need to resize as in `ArrayList`.  

##### **Disadvantages**  
- Slow for random access due to sequential traversal.  

---

#### **Comparison: `ArrayList` vs. `LinkedList`**

| Feature              | ArrayList                      | LinkedList                     |
|----------------------|--------------------------------|--------------------------------|
| **Data Structure**   | Resizable array               | Doubly linked list            |
| **Access**           | Fast random access (`O(1)`)   | Sequential access (`O(n)`)    |
| **Insertion/Deletion**| Slow (`O(n)` for middle)      | Fast for middle (`O(1)`)      |
| **Memory Usage**     | Less memory overhead          | More memory due to pointers   |
| **Use Case**         | Best for read-heavy tasks     | Best for write-heavy tasks    |  

---

### **Conclusion**  
- Use **`ArrayList`** when frequent access is required.  
- Use **`LinkedList`** when frequent insertion or deletion is required.  
- For advanced use cases like logarithmic search/insertion, consider data structures like **`Skip List`**.
