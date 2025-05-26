# **Unit 3: Process Deadlocks (6 Hrs.)**  
**Professor of Operating Systems**  

## **3.1 Introduction to Deadlocks**  
### **Definition**  
A **deadlock** occurs when a set of processes are blocked because each process is holding a resource and waiting for another resource acquired by some other process, leading to a circular wait.  

### **Deadlock Characterization (Coffman Conditions)**  
Four necessary conditions for deadlock (all must hold simultaneously):  
1. **Mutual Exclusion** – Only one process can use a resource at a time.  
2. **Hold and Wait** – A process holds at least one resource while waiting for additional resources.  
3. **No Preemption** – Resources cannot be forcibly taken from a process; they must be released voluntarily.  
4. **Circular Wait** – A circular chain of processes exists where each process waits for a resource held by the next process in the chain.  

### **Preemptable vs. Non-preemptable Resources**  
- **Preemptable Resources** – Can be taken away from a process without causing failure (e.g., CPU, memory).  
- **Non-preemptable Resources** – Cannot be taken away without causing the process to fail (e.g., printer, file locks).  

### **Resource-Allocation Graph (RAG)**  
- **Nodes**:  
  - **Process Nodes (P₁, P₂, ...)**  
  - **Resource Nodes (R₁, R₂, ...)**  
- **Edges**:  
  - **Request Edge (Pᵢ → Rⱼ)** – Process Pᵢ is waiting for resource Rⱼ.  
  - **Assignment Edge (Rⱼ → Pᵢ)** – Resource Rⱼ is held by process Pᵢ.  
- **Deadlock Detection**:  
  - If the graph contains a **cycle**, a deadlock may exist.  
  - If all resource types have a single instance → Cycle ⇒ Deadlock.  
  - If multiple instances exist → Cycle does not necessarily mean deadlock (additional checks needed).  

---  

## **3.2 Handling Deadlocks**  
### **1. Ostrich Algorithm (Ignoring Deadlock)**  
- Pretend deadlocks never occur (like an ostrich burying its head in the sand).  
- Used when deadlocks are rare, and recovery costs outweigh prevention costs.  

### **2. Deadlock Prevention**  
Ensure at least **one** of the four Coffman conditions is **never satisfied**:  
1. **Mutual Exclusion** – Allow some resources to be shareable (not always possible).  
2. **Hold and Wait** – Require processes to request all resources at once (may lead to resource starvation).  
3. **No Preemption** – If a process can’t get a resource, it releases all held resources (may cause repeated preemptions).  
4. **Circular Wait** – Impose a **total ordering** of resource types and require processes to request resources in increasing order.  

### **3. Deadlock Avoidance**  
- **Banker’s Algorithm** (for multiple resource instances):  
  - Each process declares **maximum need**.  
  - System checks if granting a request leads to a **safe state** (a state where processes can complete without deadlock).  
- **Safe State**: A sequence of processes exists where each can obtain needed resources without waiting indefinitely.  
- **Resource-Request Algorithm**:  
  1. If request ≤ available, proceed.  
  2. Pretend to allocate, then check if the system remains in a safe state.  
  3. If safe, grant the request; else, block the process.  

### **4. Deadlock Detection**  
#### **For Single Resource Instances**  
- Use **Resource-Allocation Graph (RAG)** and detect cycles.  
#### **For Multiple Resource Instances**  
- Use a **Wait-for Graph** (derived from RAG) or a matrix-based algorithm.  
- **Detection Algorithm**:  
  1. Compare available resources with process requests.  
  2. If a process can be executed, mark it as finished and release its resources.  
  3. Repeat until no more processes can be executed.  
  4. Remaining processes are deadlocked.  

### **5. Recovery from Deadlock**  
#### **Process Termination**  
- **Abort all deadlocked processes** (simple but drastic).  
- **Abort one process at a time** until deadlock is resolved (costly but safer).  
#### **Resource Preemption**  
- Select a **victim process** and preempt its resources (may require rollback).  
- **Starvation Risk**: A process may be repeatedly chosen as a victim → Use a cost factor to avoid this.  
#### **Rollback**  
- Restore the system to a previous **safe state** (requires checkpointing).  

---  

## **Summary of Key Points**  
| **Approach**          | **Mechanism** | **Pros** | **Cons** |  
|----------------------|--------------|---------|---------|  
| **Ostrich Algorithm** | Ignore deadlock | Simple | System may freeze |  
| **Prevention**       | Break Coffman conditions | Guaranteed no deadlock | Low resource utilization |  
| **Avoidance**        | Banker’s Algorithm | Safe resource allocation | Requires prior knowledge of max needs |  
| **Detection**        | Cycle detection in RAG | No prevention overhead | Recovery is costly |  
| **Recovery**         | Preemption/Rollback | Resolves deadlock | May lead to starvation or data loss |  

---  
**Next Steps**:  
- Practice **Banker’s Algorithm** problems.  
- Analyze **Resource-Allocation Graphs** for cycles.  
- Discuss real-world examples (e.g., database deadlocks).  

**End of Unit 3 Notes**
