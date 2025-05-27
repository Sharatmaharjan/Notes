# **Unit 3: Process Deadlocks**   
**Duration: 6 Hours**  


## **3.1 Introduction to Deadlocks**  
 **Definition**  
A **deadlock** is a situation where a set of processes are blocked because each process is holding a resource and waiting for another resource acquired by some other process.  

 **Example**  
- **Process P1** holds **Resource R1** and requests **Resource R2**.  
- **Process P2** holds **Resource R2** and requests **Resource R1**.  
- Both processes wait indefinitely → **Deadlock**.  

---

## **3.2 Deadlock Characterization (Necessary Conditions)**  
For a deadlock to occur, **all four** conditions must hold simultaneously:  

**1. Mutual Exclusion**  
**Definition:** Only one process can use a resource at a time.  
**Example:**  
- **Printer**: Only one document can print at a time.  
  - *Process A* prints a file → *Process B* must wait.   

**2. Hold and Wait**  
**Definition:** A process holds one resource *while waiting* for another.  
**Example:**  
  - *Process A* holds *Resource 1*, waits for *Resource 2*.  
  - *Process B* holds *Resource 3*, waits for *Resource 4*.

**3. No Preemption**  
**Definition:** Resources can’t be forcibly taken; must be released voluntarily.  
**Example:**  
 **Library Books**  
- **Student 1** borrows *Book A* and won’t return it until they get *Book B*.  
- **Student 2** borrows *Book B* and won’t return it until they get *Book A*.  
- **Librarian can’t force-return books** → Deadlock!  


 **4. Circular Wait**  
**Definition:** A loop of processes waiting for each other’s resources.  
**Example:**  
  - *Process A* holds *Resource 1*, waits for *Resource 2* (held by *Process B*).  
  - *Process B* holds *Resource 2*, waits for *Resource 1* (held by *Process A*). 
- **Result:** Infinite loop → **Deadlock!**  


**Key Takeaways**  
1. **All 4 conditions must hold for deadlock:**  
   - **Mutual Exclusion** → "Only one process can use a resource at a time."  
   - **Hold & Wait** → "I’m keeping this resource but also waiting for another."  
   - **No Preemption** → "Resources can't be forcibly taken away."  
   - **Circular Wait** → "A cycle where each process waits for the next."  

2. **Deadlock cannot occur if even one condition is missing.**  


**Mnemonic** Remember:  
**"Mutual Hold-No-Circle"** → **M**utual exclusion + **H**old & wait + **N**o preemption + **C**ircular wait = **Deadlock!**  

---

## **3.3 Preemptable vs Non-Preemptable Resources**  

| **Preemptable Resources** | **Non-Preemptable Resources** |  
|---------------------------|-------------------------------|  
| Can be taken away without causing issues (e.g., CPU, Memory). | Cannot be taken away without causing failure (e.g., Printer, Scanner). |  
| Deadlocks can be resolved by preemption. | Deadlocks require other solutions. |  

---

## **3.4 Resource-Allocation Graph (RAG)**  
- A directed graph used to detect deadlocks.  
- **Nodes**:  
  - **Processes (P1, P2, ...)**  
  - **Resources (R1, R2, ...)**  
- **Edges**:  
  - **Request Edge (P → R)**: Process **P** is waiting for resource **R**.  
  - **Assignment Edge (R → P)**: Resource **R** is allocated to process **P**.  

 **Example of RAG**  
```
P1 → R2 (Request)  
R2 → P2 (Assignment)  
P2 → R1 (Request)  
R1 → P1 (Assignment)  
```  
- **Cycle exists?** → **Deadlock!**  

 **Deadlock Detection using RAG**  
- If the graph has **no cycles** → **No deadlock**.  
- If the graph has **a cycle** → **Deadlock possible**.  

---

## **3.5 Conditions for Deadlock**  
1. **Mutual Exclusion**  
2. **Hold and Wait**  
3. **No Preemption**  
4. **Circular Wait**  

 **Tip:**  
- If any **one** condition is missing → **No deadlock!**  
- Deadlock prevention strategies aim to **break one of these conditions**. 

---

 **Key Takeaways**  
✔ Deadlock = Circular waiting with all 4 conditions.  
✔ RAG helps visualize deadlocks (cycles = deadlock).  
✔ Preemptable resources can help resolve deadlocks.  

---


## 3.2: Handling Deadlocks

There are five strategies for handling deadlocks:

1. Ostrich Algorithm


2. Deadlock Prevention


3. Deadlock Avoidance


4. Deadlock Detection


5. Recovery from Deadlock




---

1. Ostrich Algorithm

Concept

This strategy ignores deadlocks.

Based on the idea that deadlocks are rare and may not significantly impact system performance.


Used in

Most UNIX and Linux systems.


Example

A desktop application freezes due to deadlock, but the OS doesn't intervene unless the user restarts the process manually.


Diagram

[Process A] --waiting--> [Resource X] <--held-- [Process B]
[Process B] --waiting--> [Resource Y] <--held-- [Process A]

System ignores this circular wait.


---

2. Deadlock Prevention

Concept

Ensures that at least one of the four necessary conditions for deadlock is never allowed.


Techniques

Condition	Prevention Technique

Mutual Exclusion	Make resources sharable (not always possible)
Hold and Wait	Require processes to request all resources at once
No Preemption	Allow OS to preempt resources from processes
Circular Wait	Impose a strict order of resource acquisition


Example

Circular Wait Prevention: Number resources, and processes can request only in increasing order.


Diagram

Resource Order: R1 < R2 < R3

Process A: Requests R1 → then R2
Process B: Requests R2 → then R3

No circular wait possible.


---

3. Deadlock Avoidance

Concept

The system carefully allocates resources only if it leads to a safe state.

Uses information about future resource needs.


Banker’s Algorithm (for multiple instances)

Ensures that the system remains in a safe state by simulating allocations.


Safe State

A system is in a safe state if there is a sequence of all processes such that each process can finish with the available resources.


Example

Suppose 3 processes P1, P2, P3 and 10 total resources.

Allocation: P1(3), P2(2), P3(2)

Maximum: P1(6), P2(4), P3(6)

Available: 3


→ The system checks whether all processes can eventually finish. If yes, safe state.

Diagram

[Banker's Safety Check]
P1 --> finish?
P2 --> finish?
P3 --> finish?
YES → SAFE STATE


---

4. Deadlock Detection

Used when the system does not avoid deadlocks. Periodically, the OS checks if a deadlock has occurred.

(A) For Single Instance of Each Resource:

Use a Wait-For Graph (WFG).

Nodes are processes, and an edge from P1 to P2 implies P1 is waiting for a resource held by P2.

Cycle in the graph = deadlock.


Example Diagram

P1 → P2 → P3 → P1 (Cycle Detected)

(B) For Multiple Instances:

Use detection algorithm similar to Banker's Algorithm.

Keeps track of:

Allocation Matrix

Request Matrix

Available Vector



Steps:

1. Work = Available


2. Finish[i] = false for all i


3. Find i such that Request[i] ≤ Work and Finish[i] = false


4. If found, Work = Work + Allocation[i]; Finish[i] = true


5. Repeat until no such i exists


6. If any Finish[i] = false → deadlock




---

5. Recovery from Deadlock

Once a deadlock is detected, recovery strategies are needed.

(A) Preemption

Temporarily take resources from some processes.

Requires saving the state (context) of preempted processes.


(B) Rollback

Roll back one or more processes to an earlier safe state.

Use checkpoints (snapshots of process states).


(C) Kill Processes

Terminate one or more processes involved in the deadlock.


Example

If P1, P2, P3 are in deadlock:

Kill P2, reclaim its resources

Allow P1 and P3 to proceed



---

Comparison Table

Strategy	Pros	Cons

Ostrich Algorithm	Simple, low overhead	Risk of system freeze
Deadlock Prevention	Avoids deadlocks completely	May reduce resource utilization
Deadlock Avoidance	Allocates resources safely	Needs advance knowledge of max resource need
Deadlock Detection	Detects actual deadlocks	Adds overhead; needs recovery mechanism
Recovery Techniques	Resolves deadlocks after detection	May lead to data loss or inconsistency



---

