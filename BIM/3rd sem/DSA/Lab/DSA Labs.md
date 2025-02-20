## Unit 2: Linked Lists
### Lab 1: Singly LinkedList Implementation
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

**Sample Output**
```java
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

### Lab 2: Doubly LinkedList Implementation

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

**Sample Output**
```java
Doubly Linked List after adding nodes at the beginning:
1 <-> 2 <-> 3 <-> null

Doubly Linked List after adding nodes at the end:
1 <-> 2 <-> 3 <-> 4 <-> 5 <-> null

Doubly Linked List after adding a node at position 2:
1 <-> 2 <-> 10 <-> 3 <-> 4 <-> 5 <-> null

Doubly Linked List after removing a node from the beginning:
2 <-> 10 <-> 3 <-> 4 <-> 5 <-> null

Doubly Linked List after removing a node from the end:
2 <-> 10 <-> 3 <-> 4 <-> null

Doubly Linked List after removing a node at position 2:
2 <-> 10 <-> 4 <-> null

Is 10 in the list? true
Is 3 in the list? false
```

---
## Unit 3: Stack

### Lab 3: Java implementation for a stack using an array.

```java
// Stack implementation using an array
class ArrayStack {
    private int[] stack; // Array to store stack elements
    private int top;     // Points to the top of the stack
    private int size; // Maximum capacity/size of the stack

    // Constructor to initialize the stack
    ArrayStack(int size) {
        stack = new int[size];
        this.size = size;
        top = -1; // Indicates an empty stack, if the capacity/size of the stack is 4, the maximum value of top will indeed be 3 from 0 to 3
    }

    // Push operation: Add an element to the top of the stack
    public void push(int x) {
      //if(top==size-1)
        if (isFull()) {
            System.out.println("Stack Overflow! Cannot push " + x);
            return;
        }
        stack[++top] = x; // Increment top and add the element
        System.out.println(x + " pushed into stack");
    }

    // Pop operation: Remove and return the top element from the stack
    public int pop() {
      //if(top==-1)
        if (isEmpty()) {
            System.out.println("Stack Underflow! Cannot pop");
            return -1; // Return -1 to indicate underflow
        }
        return stack[top--]; // Return the top element and decrement top
    }

    // Peek operation: Return the top element without removing it
    public int peek() {
        if (isEmpty()) {
            System.out.println("Stack is Empty");
            return -1; // Return -1 to indicate empty stack
        }
        return stack[top];
    }

    // Check if the stack is empty
    public boolean isEmpty() {
        return top == -1;
    }

    // Check if the stack is full
    public boolean isFull() {
        return top == size - 1;
    }

    // Display the stack elements
    public void display() {
        if (isEmpty()) {
            System.out.println("Stack is Empty");
            return;
        }
        System.out.print("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            System.out.print(stack[i] + " ");
        }
        System.out.println();
    }
}

// Main class to test the array-based stack implementation
public class Main {
    public static void main(String[] args) {
        ArrayStack stack = new ArrayStack(5); // Create a stack with capacity 5

        // Push elements into the stack
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);

        // Display stack elements
        stack.display();

        // Peek the top element
        System.out.println("Top element is: " + stack.peek());

        // Pop elements from the stack
        System.out.println("Popped element: " + stack.pop());
        System.out.println("Popped element: " + stack.pop());

        // Display stack elements after pops
        stack.display();

        // Push more elements
        stack.push(50);
        stack.push(60);
        stack.push(70);
        stack.push(80);   // This will cause a stack overflow

        // Display final stack elements
        stack.display();

        // Peek the top element after pushes
        System.out.println("Top element is: " + stack.peek());
    }
}
```

**Sample Output**

```java
10 pushed into stack
20 pushed into stack
30 pushed into stack
40 pushed into stack
Stack elements: 10 20 30 40 
Top element is: 40
Popped element: 40
Popped element: 30
Stack elements: 10 20 
50 pushed into stack
60 pushed into stack
Stack Overflow! Cannot push 70
Stack elements: 10 20 50 60 
Top element is: 60
```

---

## Unit 4: Queues

### Lab 4: Java implementation for a queue using array.

```java
public class ArrayQueue {
    private int maxSize;
    private int front;
    private int rear;
    private int[] queueArray;

    // Constructor to initialize the queue with a given size
    public ArrayQueue(int size) {
        maxSize = size;
        queueArray = new int[maxSize];
        front = 0;
        rear = 0;
    }

    // Check if the queue is empty
    public boolean isEmpty() {
        return front == rear;
    }

    // Check if the queue is full
    public boolean isFull() {
        return rear == maxSize;
    }

    // Enqueue (insert) an element into the queue
    public void enqueue(int value) {
        if (isFull()) {
            System.out.println("Queue is full. Cannot enqueue " + value);
            return;
        }
        queueArray[rear++] = value; // Increment rear after inserting
        System.out.println("Enqueued " + value + " into the queue");
    }

    // Dequeue (remove) an element from the queue
    public int dequeue() {
        if (isEmpty()) {
            System.out.println("Queue is empty. Cannot dequeue");
            return -1; // Return a sentinel value indicating failure
        }
        int dequeuedValue = queueArray[front++]; // Increment front after removing
        System.out.println("Dequeued " + dequeuedValue + " from the queue");
        return dequeuedValue;
    }

    // Peek at the front element of the queue without removing it
    public int peek() {
        if (isEmpty()) {
            System.out.println("Queue is empty. Nothing to peek");
            return -1; // Return a sentinel value indicating failure
        }
        return queueArray[front];
    }

    // Display the elements of the queue
    public void display() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return;
        }
        System.out.print("Queue: ");
        for (int i = front; i < rear; i++) {
            System.out.print(queueArray[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        ArrayQueue queue = new ArrayQueue(3); // Queue size of 3

        // Test enqueue operation
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3); // Should indicate full
        queue.display();

        // Test peek operation
        System.out.println("Peek: " + queue.peek());

        // Test dequeue operation
        queue.dequeue();
        queue.display();

        // Test enqueue after dequeue
        queue.enqueue(4); // Should indicate full since linear queue does not reuse space
        queue.display();

        // Check empty and full states
        System.out.println("Is queue empty? " + queue.isEmpty());
        System.out.println("Is queue full? " + queue.isFull());
    }
}
```

**Sample Output**
```java
Enqueued 1 into the queue
Enqueued 2 into the queue
Enqueued 3 into the queue
Queue: 1 2 3
Peek: 1
Dequeued 1 from the queue
Queue: 2 3
Queue is full. Cannot enqueue 4
Queue: 2 3
Is queue empty? false
Is queue full? true

```

---

## Unit 5: Recursion

### Lab 5: Write a java program to find factorial of a number using recursion.

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

**Sample Output**
```java
Factorial of 5 is: 120
```

---

### Lab 6: Wrtie a java program to find fibonacci sequence using recursion.

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
**Sample Output**
```java
Fibonacci Sequence up to 10th term:
0 1 1 2 3 5 8 13 21 34 
```
---

### Lab 7: Write a java program to find Greatest Common Divisor (GCD) of two numbers using recursion.

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

**Sample Output**

```java
The GCD of 12 and 8 is: 4
```

---

### Lab 8: Write a java program to implement Tower of Hanoi using recursion.

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

**Sample Output**
```java
Solution for Tower of Hanoi with 3 disks:
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
```


