## **Unit 7: Graphs**

## **Unit 7: Graphs**
### **1. Introduction to Graphs**
- A **graph** is a non-linear data structure consisting of **vertices (nodes)** and **edges** that connect these vertices.
- Graphs are used to represent relationships between objects, such as networks, social connections, maps, etc.
- **Types of Graphs**:
  - **Directed Graph (Digraph)**: Edges have a direction (e.g., A → B).
  - **Undirected Graph**: Edges have no direction (e.g., A — B).
  - **Weighted Graph**: Edges have weights or costs associated with them.
  - **Unweighted Graph**: Edges have no weights.
  - **Cyclic Graph**: Contains at least one cycle.
  - **Acyclic Graph**: Contains no cycles.

---

### **2. Graph as an Abstract Data Type (ADT)**
- A graph can be represented as an ADT with the following operations:
  - **AddVertex(v)**: Adds a vertex \( v \) to the graph.
  - **AddEdge(u, v)**: Adds an edge between vertices \( u \) and \( v \).
  - **RemoveVertex(v)**: Removes a vertex \( v \) and all its associated edges.
  - **RemoveEdge(u, v)**: Removes the edge between \( u \) and \( v \).
  - **IsAdjacent(u, v)**: Checks if there is an edge between \( u \) and \( v \).
  - **Neighbors(v)**: Returns a list of vertices adjacent to \( v \).

---

### **3. Graph Representation**
Graphs can be represented in two main ways:

#### **a. Adjacency Matrix**
- A 2D array of size \( V \times V \), where \( V \) is the number of vertices.
- **Matrix[i][j] = 1** if there is an edge between vertex \( i \) and \( j \), otherwise **0**.
- For weighted graphs, **Matrix[i][j]** stores the weight of the edge.
- **Pros**:
  - Easy to implement.
  - Efficient for dense graphs.
- **Cons**:
  - Requires \( O(V^2) \) space, which is inefficient for sparse graphs.

#### **b. Adjacency List**
- An array of lists, where each list stores the neighbors of a vertex.
- For weighted graphs, each list stores pairs of (neighbor, weight).
- **Pros**:
  - Space-efficient for sparse graphs (\( O(V + E) \)).
  - Easy to find all neighbors of a vertex.
- **Cons**:
  - Checking if two vertices are adjacent is slower (\( O(V) \) in the worst case).

---

### **4. Graph Traversals**
Graph traversal algorithms visit all vertices in a graph systematically.

#### **a. Breadth-First Traversal (BFT)**
- Explores all neighbors of a vertex before moving to the next level.
- Uses a **queue** for implementation.
- **Applications**:
  - Shortest path in unweighted graphs.
  - Finding connected components.
- **Time Complexity**: \( O(V + E) \).

#### **b. Depth-First Traversal (DFT)**
- Explores as far as possible along each branch before backtracking.
- Uses a **stack** (or recursion) for implementation.
- **Applications**:
  - Detecting cycles.
  - Topological sorting.
- **Time Complexity**: \( O(V + E) \).

---

### **5. Greedy Algorithm**
- A greedy algorithm makes the locally optimal choice at each step to find a global optimum.
- **Characteristics**:
  - Builds a solution piece by piece.
  - Does not reconsider previous choices.
- **Applications**:
  - Dijkstra's algorithm (shortest path).
  - Kruskal's and Prim's algorithms (MST).

---

### **6. Shortest Path Problem: Dijkstra's Algorithm**
- Finds the shortest path from a source vertex to all other vertices in a **weighted graph** with **non-negative weights**.
- **Steps**:
  1. Initialize distances to all vertices as infinity, except the source (distance = 0).
  2. Use a priority queue to select the vertex with the smallest distance.
  3. Relax all edges from the selected vertex.
  4. Repeat until all vertices are processed.
- **Time Complexity**: \( O((V + E) \log V) \) using a priority queue.

---

### **7. All-to-All Shortest Path Problem: Floyd-Warshall Algorithm**
- Finds the shortest paths between all pairs of vertices in a **weighted graph** (can handle negative weights but no negative cycles).
- **Steps**:
  1. Initialize a distance matrix with direct edge weights.
  2. For each intermediate vertex, update the distances between all pairs of vertices.
- **Time Complexity**: \( O(V^3) \).

---

### **8. Spanning Trees and Minimum Spanning Tree (MST)**
- A **spanning tree** is a subgraph of a graph that is a tree and connects all vertices.
- A **Minimum Spanning Tree (MST)** is a spanning tree with the minimum possible total edge weight.

#### **a. Kruskal's Algorithm**
- **Steps**:
  1. Sort all edges in non-decreasing order of weight.
  2. Add edges to the MST one by one, avoiding cycles (using Union-Find).
- **Time Complexity**: \( O(E \log E) \).

#### **b. Prim's Algorithm**
- **Steps**:
  1. Start with an arbitrary vertex.
  2. Add the smallest edge that connects a vertex in the MST to a vertex outside the MST.
  3. Repeat until all vertices are included.
- **Time Complexity**: \( O((V + E) \log V) \) using a priority queue.

---

### **9. Topological Sort**
- A linear ordering of vertices in a **Directed Acyclic Graph (DAG)** such that for every directed edge \( u \rightarrow v \), \( u \) comes before \( v \).
- **Steps**:
  1. Perform a Depth-First Search (DFS).
  2. Add vertices to a stack after visiting all their neighbors.
- **Applications**:
  - Scheduling tasks with dependencies.
  - Course prerequisites.
- **Time Complexity**: \( O(V + E) \).

---

### **Summary of Algorithms**
| **Algorithm**           | **Purpose**                              | **Time Complexity**       |
|--------------------------|------------------------------------------|---------------------------|
| Dijkstra's Algorithm     | Single-source shortest path             | \( O((V + E) \log V) \)   |
| Floyd-Warshall Algorithm | All-pairs shortest paths                | \( O(V^3) \)              |
| Kruskal's Algorithm      | Minimum Spanning Tree (MST)             | \( O(E \log E) \)         |
| Prim's Algorithm         | Minimum Spanning Tree (MST)             | \( O((V + E) \log V) \)   |
| Topological Sort         | Linear ordering in a DAG                | \( O(V + E) \)            |

---
