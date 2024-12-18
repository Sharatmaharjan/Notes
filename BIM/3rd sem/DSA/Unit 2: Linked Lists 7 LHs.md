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

