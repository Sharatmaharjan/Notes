# **Operating System (OS)**

## **1. Need and Role of Operating System**  
### **Need for an OS:**  
- Acts as an intermediary between users and computer hardware.  
- Manages hardware resources efficiently (CPU, memory, disk, I/O devices).  
- Provides a user-friendly interface (GUI/CLI).  
- Ensures security and access control.  
- Facilitates program execution and multitasking.  
- Provides abstraction to hide hardware complexity.  

### **Roles of an OS:**  
1. **Resource Manager:** Allocates CPU time, memory, and I/O devices efficiently.  
2. **Process Manager:** Handles process scheduling, synchronization, and communication.  
3. **Memory Manager:** Manages RAM and virtual memory for running processes.  
4. **File System Manager:** Organizes and controls access to files and directories.  
5. **Device Manager:** Controls hardware devices via device drivers.  
6. **Security & Protection:** Prevents unauthorized access and ensures data integrity.  

---  
## **2. OS Components**  
### **a) Scheduler (CPU Scheduler)**  
- Decides which process runs next on the CPU.  
- Types:  
  - **Long-term Scheduler (Job Scheduler):** Selects processes from disk to RAM.  
  - **Short-term Scheduler (CPU Scheduler):** Selects a process from ready queue to execute.  
  - **Medium-term Scheduler (Swapper):** Handles swapping processes in/out of RAM.  

### **b) Memory Manager**  
- Manages primary memory (RAM) and secondary memory (disk).  
- Functions:  
  - Allocation & deallocation of memory.  
  - Virtual memory management (paging, segmentation).  
  - Protection between processes.  

### **c) File System Handlers**  
- Manages file storage, retrieval, and organization.  
- Functions:  
  - File creation, deletion, and access control.  
  - Directory management (hierarchical structure).  
  - Disk space allocation (contiguous, linked, indexed).  

### **d) I/O Device Managers**  
- Controls input/output operations.  
- Functions:  
  - Device drivers for hardware communication.  
  - Buffering, caching, and spooling for performance.  
  - Interrupt handling for asynchronous I/O.  

---  
## **3. Analysis and Criticism of OS Techniques**  
### **a) Scheduling Algorithms**  
| Algorithm | Advantages | Disadvantages |  
|-----------|------------|--------------|  
| **FCFS** | Simple, no starvation | Poor for short jobs (convoy effect) |  
| **SJF** | Optimal (min avg waiting time) | Hard to predict burst time |  
| **Round Robin** | Fair, good response time | High overhead with small time quantum |  
| **Priority** | Important processes run first | Starvation for low-priority processes |  

### **b) Memory Management Techniques**  
- **Paging:**  
  - Pros: No external fragmentation, flexible memory use.  
  - Cons: Internal fragmentation, overhead due to page tables.  
- **Segmentation:**  
  - Pros: Logical division, easy sharing.  
  - Cons: External fragmentation, complex management.  
- **Virtual Memory:**  
  - Pros: Allows larger programs than RAM.  
  - Cons: Thrashing if excessive paging occurs.  

### **c) File System Techniques**  
- **Contiguous Allocation:** Fast access but suffers from fragmentation.  
- **Linked Allocation:** No fragmentation but slow random access.  
- **Indexed Allocation:** Supports random access but has overhead.  

---  
## **4. Demonstration and Simulation of OS Algorithms**  
### **a) Scheduling Algorithms Simulation**  
- **FCFS Example:**  
  ```
  Processes: P1 (Burst=5), P2 (Burst=3), P3 (Burst=8)  
  Order: P1 → P2 → P3  
  Avg Waiting Time = (0 + 5 + 8)/3 = 4.33  
  ```  
- **Round Robin (Time Quantum=4):**  
  ```
  P1 (5) runs 4 → P2 (3) runs 3 → P1 (1) runs 1 → P3 (8) runs 4 → P3 (4) runs 4  
  ```  

### **b) Memory Management Simulation (Paging)**  
- **Page Table Example:**  
  ```
  Logical Address: 12-bit (4-bit page no, 8-bit offset)  
  Page Table: Page 0 → Frame 3, Page 1 → Frame 7  
  Physical Address = (Frame No × Frame Size) + Offset  
  ```  

---  
## **5. Algorithms & Techniques in Linux OS Components**  
### **a) Linux Scheduler (CFS - Completely Fair Scheduler)**  
- Uses **red-black tree** for O(log n) task selection.  
- Assigns **virtual runtime (vruntime)** to ensure fairness.  

### **b) Linux Memory Management**  
- Uses **Buddy System** for contiguous memory allocation.  
- **Slab Allocator** for kernel object caching.  
- **Swappiness** parameter controls swapping tendency.  

### **c) Linux File System (Ext4)**  
- **Journaling** for crash recovery.  
- **Extents** for large file allocation (reduces fragmentation).  

### **d) Linux I/O Management**  
- **I/O Schedulers:**  
  - **CFQ (Completely Fair Queuing)** – Fair disk access.  
  - **Deadline** – Prioritizes read/write deadlines.  
  - **NOOP** – Simple FIFO for SSDs.  

---  
### **Summary**  
✔ Understand **why OS is needed** and its **key roles**.  
✔ Learn **OS components** (scheduler, memory, file, I/O managers).  
✔ Analyze **pros & cons** of different OS techniques.  
✔ Practice **simulating scheduling & memory algorithms**.  
✔ Study **Linux-specific implementations** (CFS, Ext4, I/O schedulers).  
