### Unit 4: Queues  

**Duration**: 4 Lecture Hours (LHs)  

---

#### **1. Basic Concept of Queue**
A queue is a **linear data structure** that follows the **First-In-First-Out (FIFO)** principle. This means that the element inserted first is the first to be removed. It is analogous to a line or queue in real life, such as people waiting in line for a bus or a ticket counter.

---

##### **1.1 Characteristics of Queue**
1. **FIFO Principle**: Elements are processed in the order in which they arrive.
2. **Two Pointers**: 
   - **Front**: Points to the first element in the queue (next to be removed).
   - **Rear**: Points to the last element in the queue (most recently added).
3. **Operations**:
   - **Enqueue**: Add an element to the rear of the queue.
   - **Dequeue**: Remove an element from the front of the queue.

---

#### **2. Queue as an Abstract Data Type (ADT)**
A queue can be implemented as an **Abstract Data Type (ADT)**, where its operations are defined without specifying the internal implementation.

The queue ADT includes the following methods:
1. **CreateQueue()**: Initializes an empty queue.
2. **Enqueue(element)**: Adds `element` to the rear of the queue.
3. **Dequeue()**: Removes and returns the element from the front of the queue.
4. **IsEmpty()**: Checks if the queue is empty.
5. **IsFull()**: Checks if the queue is full (for fixed-size queues).
6. **Peek()**: Returns the element at the front of the queue without removing it.


---

#### **3. Primitive Operations in Queue**
Primitive operations are the basic functionalities performed on a queue. These include:  
1. **Enqueue**: Insert an element at the rear of the queue.  
2. **Dequeue**: Remove and return the element at the front of the queue.  
3. **Peek/Front**: Retrieve the element at the front without removing it.  
4. **IsEmpty**: Check whether the queue is empty.  
5. **IsFull**: Check whether the queue is full (only applicable for fixed-size queues).  

---

#### **4. Linear Queue**
A **Linear Queue** is the simplest type of queue in which:  
- Elements are added at the rear and removed from the front.  
- The queue follows the **First-In-First-Out (FIFO)** principle.  
- It suffers from the **"unused space problem"**, where the space in the array is not reused after elements are dequeued.  

---

#### **5. Queue Implementation**
Queues can be implemented using two main techniques:  

---

##### **1. Array-Based Implementation**  
- **Concept**: Use a fixed-size array to store elements of the queue.  
- **Key Points**:  
  - Maintain `front` and `rear` pointers to track the queue ends.  
  - Update `rear` during `enqueue` and `front` during `dequeue`.  
  - Inefficient memory usage due to the unused space problem.  

- **Algorithm for Array-Based Implementation**:  
  **Enqueue**:  
  1. Check if the queue is full (`rear == maxsize`).  
  2. If not full, increment `rear` and insert the element at `queue[rear]`.  

  **Dequeue**:  
  1. Check if the queue is empty (`front > rear`).  
  2. If not empty, return the element at `queue[front]` and increment `front`.
``` java
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

---

##### **2. Linked-List-Based Implementation**  
- **Concept**: Use dynamically allocated nodes with `data` and `next` pointers.  
- **Key Points**:  
  - No fixed size; memory is allocated as needed.  
  - Use two pointers, `front` (head) and `rear` (tail), to track the ends of the queue.  
  - Efficient memory usage without the unused space problem.  

- **Algorithm for Linked-List-Based Implementation**:  
  **Enqueue**:  
  1. Create a new node with the given value.  
  2. If the queue is empty (`front == NULL`), set both `front` and `rear` to the new node.  
  3. Else, link the new node to the current `rear` and update `rear`.  

  **Dequeue**:  
  1. Check if the queue is empty (`front == NULL`).  
  2. If not empty, retrieve the `data` from `front`, update `front` to `front->next`, and free the old front node.  

---

#### **6. Circular Queue**
A **Circular Queue** solves the unused space problem of a linear queue by connecting the last position of the queue back to the first position, forming a circular structure.  

- **Key Points**:  
  - The `rear` wraps around to the beginning of the array when it reaches the end.  
  - `front` and `rear` pointers are updated using modulo arithmetic:  
    - `rear = (rear + 1) % size`  
    - `front = (front + 1) % size`  
  - Efficient use of memory.  

- **Conditions**:  
  - **Full Queue**: `(rear + 1) % size == front`  
  - **Empty Queue**: `front == -1` or `front == rear + 1`  

---

#### **7. Priority Queue**
A **Priority Queue** is a special type of queue where elements are dequeued based on their priority rather than their order of arrival.  

- **Key Points**:  
  - Each element has an associated priority.  
  - Elements with higher priority are dequeued before those with lower priority.  
  - If two elements have the same priority, they are dequeued in FIFO order.  

- **Implementation Methods**:  
  1. **Array-Based**: Store elements in an array and reorder them based on priority.  
  2. **Heap-Based**: Use a binary heap for efficient insertion and deletion.  

---

#### **Queue Applications**
1. **Scheduling Tasks**:  
   - CPU scheduling (e.g., round-robin algorithm).  
   - Disk scheduling.  

2. **Data Buffering**:  
   - Print queue management.  
   - Input/output buffering in operating systems.  

3. **Breadth-First Search (BFS)**:  
   - Used in graph traversal and shortest path algorithms.  

4. **Resource Sharing**:  
   - Managing shared resources like printers or network bandwidth.  

5. **Simulation**:  
   - Simulating real-world scenarios like queues in banks or airports.  

6. **Order Processing Systems**:  
   - E-commerce systems for order tracking and dispatch.  

--- 


