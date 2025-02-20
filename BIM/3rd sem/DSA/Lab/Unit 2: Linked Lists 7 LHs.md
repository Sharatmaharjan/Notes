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




