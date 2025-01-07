

### Unit 3: Stack 4LHs

#### 3.1. **Basic Concept of Stack**
A stack is a linear data structure that follows the **LIFO (Last In, First Out)** principle, where the last element added to the stack is the first one to be removed.

**Key Features of a Stack:**
- **Insertion (Push):** Adds an element to the top of the stack.
- **Deletion (Pop):** Removes the top element from the stack.
- **Peek (Top):** Retrieves the top element without removing it.
- **Empty Check:** Determines whether the stack is empty.

**Example:**
A stack of books:
1. Add a book (Push)
2. Remove the top book (Pop)
3. Check the title of the top book (Peek)

---

#### 3.2. **Stack as an Abstract Data Type (ADT)**
A stack can be implemented using:
- **Arrays**
- **Linked Lists**

**Stack Operations as ADT:**
1. **Push(x):**
   - Adds the element `x` to the top of the stack.
   - If the stack is full, it returns an "overflow" error.
   - Time Complexity: \( O(1) \).
   
2. **Pop():**
   - Removes the top element of the stack and returns it.
   - If the stack is empty, it returns an "underflow" error.
   - Time Complexity: \( O(1) \).

3. **Peek():**
   - Returns the top element of the stack without removing it.
   - If the stack is empty, it returns an error.
   - Time Complexity: \( O(1) \).

4. **isEmpty():**
   - Returns `true` if the stack has no elements, otherwise `false`.
   - Time Complexity: \( O(1) \).

5. **isFull():** (only for array-based implementation)
   - Returns `true` if the stack is full, otherwise `false`.
   - Time Complexity: \( O(1) \).

---


#### **3.3 Stack Implementation**
Stacks can be implemented using:
1. **Array**
2. **Linked List**

---

**2.1 Array-Based Implementation**
- Uses a fixed-size array to store stack elements.
- The top of the stack is tracked using an index (`top`).

**Algorithm for Array-Based Stack:**
```plaintext
Initialize an array `stack` of size `N` and set `top = -1`.

Push(x):
  if top == N-1:
    print "Stack Overflow"
  else:
    top = top + 1
    stack[top] = x

Pop():
  if top == -1:
    print "Stack Underflow"
  else:
    x = stack[top]
    top = top - 1
    return x

Peek():
  if top == -1:
    print "Stack is Empty"
  else:
    return stack[top]
```

**Advantages:**
- Easy to implement.
- Faster access since elements are stored contiguously in memory.

**Disadvantages:**
- Fixed size, leading to overflow if the array is full.
- Wastage of memory if the stack is underutilized.

Java implementation for a **stack using an array**.

```java
// Stack implementation using an array
class ArrayStack {
    private int[] stack; // Array to store stack elements
    private int top;     // Points to the top of the stack
    private int capacity; // Maximum capacity of the stack

    // Constructor to initialize the stack
    ArrayStack(int size) {
        stack = new int[size];
        capacity = size;
        top = -1; // Indicates an empty stack, if the capacity of the stack is 4, the maximum value of top will indeed be 3 from 0 to 3
    }

    // Push operation: Add an element to the top of the stack
    public void push(int x) {
        if (isFull()) {
            System.out.println("Stack Overflow! Cannot push " + x);
            return;
        }
        stack[++top] = x; // Increment top and add the element
        System.out.println(x + " pushed into stack");
    }

    // Pop operation: Remove and return the top element from the stack
    public int pop() {
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
        return top == capacity - 1;
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
        stack.push(70); // This will cause a stack overflow

        // Display final stack elements
        stack.display();

        // Peek the top element after pushes
        System.out.println("Top element is: " + stack.peek());
    }
}
```

---

### Step-by-Step Explanation

1. **ArrayStack Class:**
   - Manages stack operations (`push`, `pop`, `peek`) and checks for overflow or underflow conditions.
   - Uses an integer array `stack` to store elements and an integer `top` to track the current position.

2. **Push Operation:**
   - Checks if the stack is full using the `isFull` method.
   - If not full, increments `top` and assigns the new value to `stack[top]`.

3. **Pop Operation:**
   - Checks if the stack is empty using the `isEmpty` method.
   - If not empty, returns `stack[top]` and decrements `top`.

4. **Peek Operation:**
   - Checks if the stack is empty.
   - If not empty, returns the value of `stack[top]`.

5. **Display Method:**
   - Iterates from index `0` to `top` to display all elements in the stack.

6. **Main Class:**
   - Demonstrates various stack operations with sample values, including edge cases like overflow and underflow.

---

### Sample Output
```
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

#### 3.4. **Stack Applications**

1. **Expression Evaluation and Conversion:**
   - Used for converting infix expressions to postfix or prefix.
   - Evaluates postfix and prefix expressions.

2. **Backtracking:**
   - Example: Maze solving or navigating recursive algorithms.

3. **Function Call Management:**
   - The function call stack manages active subroutine calls in programming.

4. **Undo Mechanisms:**
   - Used in text editors and software to reverse actions.

. **Parentheses Matching:**
   - Checks for balanced parentheses in expressions.

6. **Browser Navigation:**
   - Maintains a stack for backtracking through visited web pages.

7. **Data Parsing:**
   - Used in compilers for syntax parsing of programming languages.

---
