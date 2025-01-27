# **Unit 6: Trees (9 LHs)**

## **1. Introduction to Trees**

A **tree** is a non-linear data structure that represents a hierarchical relationship between elements. It consists of **nodes** connected by **edges** and is widely used in applications such as databases, AI, and computer graphics.

### **Basic Terminology**
- **Root**: The topmost node in a tree.
- **Parent**: A node that has child nodes.
- **Child**: A node derived from another node.
- **Sibling**: Nodes that share the same parent.
- **Leaf**: A node with no children.
- **Degree**: Number of children a node has.
- **Depth**: Number of edges from the root to a node.
- **Height**: Number of edges on the longest path from a node to a leaf.

### **Example of a Tree Structure**
```
        A
       / \
      B   C
     / \   \
    D   E   F
```
- Root: A
- Parent of B, C: A
- Children of B: D, E
- Leaf Nodes: D, E, F

---

## **2. Applications of Trees**
- **Hierarchical Data Representation**: File systems, XML/HTML parsing.
- **Databases**: B-Trees used in indexing.
- **Artificial Intelligence**: Decision trees in machine learning.
- **Compiler Design**: Syntax trees for parsing expressions.
- **Network Routing**: Spanning trees in network topology.

---

## **3. Tree as an ADT (Abstract Data Type)**

A tree ADT defines the basic operations performed on trees, including:

1. **Create** – Create an empty tree.
2. **Insert** – Add a node.
3. **Delete** – Remove a node.
4. **Traverse** – Visit all nodes.
5. **Search** – Find a specific node.

---

## **4. Binary Trees and Types**

A **binary tree** is a tree data structure where each node has at most two children (left and right).

### **Types of Binary Trees**
1. **Full Binary Tree**: Every node has either 0 or 2 children.
2. **Complete Binary Tree**: All levels are fully filled except possibly the last.
3. **Perfect Binary Tree**: All internal nodes have 2 children, and all leaf nodes are at the same level.
4. **Skewed Binary Tree**: All nodes have only one child (left or right).
5. **Balanced Binary Tree**: Difference in height of left and right subtrees is at most 1.

---

## **5. Implementing Binary Trees**

### **Example (C Program for Binary Tree Creation and Traversal)**
```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    
    printf("Inorder traversal: ");
    inorder(root);
    return 0;
}
```
**Sample Output:**
```
Inorder traversal: 4 2 1 3
```

---

## **6. Tree Traversal Methods**

Tree traversal refers to visiting all nodes of a tree in a specific order.

1. **In-order (Left, Root, Right)**
2. **Pre-order (Root, Left, Right)**
3. **Post-order (Left, Right, Root)**

---

## **7. Binary Search Tree (BST) Operations**

A **BST** is a binary tree where:
- The left subtree contains values smaller than the root.
- The right subtree contains values greater than the root.

### **Operations**
1. **Insertion**
2. **Deletion**
3. **Searching**

### **Example: Insertion in BST**
```c
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) return createNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}
```

---

## **8. AVL Trees**

An **AVL tree** is a self-balancing BST where the height difference of left and right subtrees is at most 1. It uses rotations to maintain balance.

### **Rotations in AVL Tree**
1. Left Rotation (LL)
2. Right Rotation (RR)
3. Left-Right Rotation (LR)
4. Right-Left Rotation (RL)

---

## **9. Expression Trees**

Expression trees represent mathematical expressions. The internal nodes contain operators, and the leaf nodes contain operands.

### **Example:**
Expression: `(3 + 5) * 2`

```
        *
       / \
      +   2
     / \
    3   5
```

### **Operations on Expression Trees**
1. Evaluation
2. Infix, Prefix, Postfix conversion

---

## **10. Heap**

A **heap** is a special tree-based structure that satisfies the heap property:
- **Max-Heap**: Parent is greater than or equal to children.
- **Min-Heap**: Parent is smaller than or equal to children.

### **Heap Operations**
1. Insert
2. Delete
3. Heapify (restructuring)

---

## **11. Huffman Algorithm**

The Huffman algorithm is used for lossless data compression. It builds a binary tree based on character frequencies, assigning shorter codes to more frequent characters.

**Steps:**
1. Create a frequency table.
2. Build a priority queue.
3. Construct the Huffman tree.
4. Generate codes.

---

## **12. Self-Adjusting Trees**

Self-adjusting trees reorganize themselves to optimize frequently accessed elements. Examples include:

- **Splay Trees**: Bring accessed nodes to the root.
- **Treaps**: Combine BST and heap properties.

---

## **13. Multiway Search Trees (B-Trees)**

A **B-Tree** is a self-balancing search tree that generalizes the BST by allowing more than two children per node.

**Characteristics:**
- Nodes can contain multiple keys.
- All leaves are at the same level.
- Used in databases and filesystems.

**Operations:**
1. Insertion
2. Deletion
3. Searching

---

### **Conclusion**

Trees are fundamental data structures widely used for efficient searching, sorting, and hierarchical data representation. Understanding different tree types and their operations is crucial for algorithm optimization and system design.
