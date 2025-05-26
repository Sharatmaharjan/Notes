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

