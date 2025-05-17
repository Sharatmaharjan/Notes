# **Unit 1: Operating System Overview**  
**Lecture Duration:** 4 Hours   

## **1.1 Definition, Two Views of OS, Evolution, Types of OS**  

### **1.1.1 Definition of an Operating System (OS)**  
An Operating System is a **resource manager** and **control program** that:  
- Acts as an intermediary between users/applications and computer hardware.  
- Provides an environment for program execution.  
- Manages hardware resources efficiently (CPU, memory, I/O devices).  

The OS performs four fundamental functions:  
1. **Process Management** - Creation, scheduling, synchronization of processes.  
2. **Memory Management** - Allocation/deallocation, virtual memory handling.  
3. **File System Management** - Organizes data storage hierarchically.  
4. **Device Management** - Handles device drivers and I/O operations.  

**Real-world Analogy:**  
*"The OS is like a government that manages resources (hardware) and provides services (APIs) to citizens (applications)."*  

---

### **1.1.2 Two Views of an Operating System**  

#### **1. User View**  
**Perspective:** How end-users interact with the OS.  
- **Personal Computers:** Focus on **GUI**, responsiveness (Windows/macOS).  
- **Mobile Devices:** Touch interfaces, battery optimization (Android/iOS).  
- **Servers:** Stability and uptime prioritized over UI (Linux servers).  

**Key Point:**  
*"User experience varies by device type – a smartphone OS ≠ a supercomputer OS."*  

#### **2. System View**  
**Perspective:** How developers/system administrators see the OS.  
- **Resource Allocator:**  
  - Manages CPU time (scheduling).  
  - Memory allocation (paging/segmentation).  
  - I/O device arbitration.  
- **Control Program:**  
  - Prevents errors via process isolation.  
  - Enforces security policies.  
 
---

### **1.1.3 Evolution of Operating Systems**  
**Detailed Timeline with Technical Milestones:**  

| **Era**          | **Key Innovation**                     | **Example OS**       | **Impact**                          |  
|-------------------|----------------------------------------|----------------------|-------------------------------------|  
| **1940s-50s**     | No OS – Machine language programming  | –                    | Manual execution via punch cards.   |  
| **1950s-60s**     | Batch Processing                       | IBM OS/360           | Automated job sequencing.           |  
| **1960s-70s**     | Multiprogramming & Time-Sharing        | UNIX                 | Concurrent user access.             |  
| **1980s-90s**     | Personal Computers & GUI               | Windows 95, Mac OS   | Made computers user-friendly.       |  
| **2000s-Present** | Mobile/Distributed Systems             | Android, Linux       | Cloud computing, IoT integration.   |  

**Critical Discussion Points:**  
- **Batch Systems:** Introduced the concept of job queues.  
- **UNIX Revolution:** Modular design influenced modern OS architectures.  
- **GUI Era:** Enabled mass adoption of PCs.  

**Visual Aid Suggestion:**  
```mermaid
graph LR
  A[No OS] --> B[Batch Systems]
  B --> C[Multiprogramming]
  C --> D[Time-Sharing]
  D --> E[Personal Computing]
  E --> F[Mobile/Distributed OS]
```

---

### **1.1.4 Types of Operating Systems**

## **1. Batch Processing OS**
- Processes jobs in groups without user interaction
- **Use Case:** Payroll systems, bank transactions
- **Pros:** Efficient for large repetitive tasks
- **Cons:** No real-time feedback

## **2. Time-Sharing/Multitasking OS**
- Shares CPU time between multiple users/tasks
- **Key Feature:** Quick task switching (10-100ms slices)
- **Examples:** Linux, Windows, macOS
- **Advantage:** Enables interactive computing

## **3. Real-Time OS (RTOS)**
- Designed for time-critical applications where delay is unacceptable.
- **Hard RTOS:** Strict deadlines (medical devices)
- **Soft RTOS:** Tolerable delays (streaming apps)
- **Examples:** VxWorks, FreeRTOS

## **4. Distributed OS**
- Manages networked computers as single system
- **Features:** Resource sharing, fault tolerance
- **Examples:** Google Borg, Hadoop

## **5. Network OS**
- Manages shared resources in client-server model
- **Examples:** Windows Server, Linux servers

## **6. Mobile OS**
- Optimized for touch, battery life
- **Examples:** Android, iOS
- **Key Features:** App sandboxing, power management

### **Comparison Summary**

| Type           | User Interaction Level | Response Latency | Primary Applications          | Representative System |
|----------------|-----------------------|------------------|-------------------------------|-----------------------|
| Batch          | None                  | High             | Large-scale data processing   | IBM OS/360            |
| Time-Sharing   | High                  | Medium           | Multi-user environments       | Linux                 |
| Real-Time (RTOS)| Variable             | Ultra-Low        | Mission-critical systems      | VxWorks               |
| Distributed    | Moderate              | Low              | Cloud infrastructure          | Google Borg           |
| Mobile         | High (Touch)          | Low              | Smart devices                 | Android               |

---

### **1.2 Operating System Core Components**  


## **1.2.1 System Calls**  
**Definition:**  
Programmatic requests from applications to the OS kernel for privileged operations.  

### **Key System Call Categories**  
| **Category**       | **Examples**          | **Purpose**                          |  
|--------------------|-----------------------|--------------------------------------|  
| Process Control    | `fork()`, `exit()`    | Create/terminate processes           |  
| File Management    | `open()`, `read()`    | File operations                      |  
| Device Management  | `ioctl()`, `write()`  | Hardware control                     |  
| Communication      | `pipe()`, `shmget()`  | Inter-process communication (IPC)    |  

**Example (C Code):**  
```c
#include <unistd.h>  
int main() {  
    write(1, "Hello OS!", 9);  // System call to print  
    return 0;  
}
```

### **1.2.2 System Call Handling**  
1. **User Mode → Kernel Mode Transition**  
   - Triggered via software interrupt (e.g., `int 0x80` on x86).  
2. **Kernel Executes** the requested service.  
3. **Return to User Mode** with results.  

**Diagram:**  
```
User Process → Syscall Interface → Kernel → Hardware  
               (Mode Switch: User → Kernel)
```

---

## **1.2.3 System Programs**  
**Purpose:** Provide user-friendly utilities to manage system resources.  

### **Types & Examples**  
| **Type**           | **Linux Examples** | **Windows Equivalent** |  
|--------------------|--------------------|------------------------|  
| File Management    | `ls`, `cp`         | File Explorer          |  
| Process Management | `top`, `kill`      | Task Manager           |  
| Networking         | `ping`, `ssh`      | `ipconfig`             |  

**Teaching Tip:**  
- Demo: Run `strace ls` to show system calls behind the `ls` command.  

---

## **1.2.4 Operating System Structures**  

### **A. Monolithic Kernel**  
- **All OS services run in kernel space.**  
- **Example:** Traditional Linux  
- **Pros:** High performance  
- **Cons:** Single bug can crash system  

**Diagram:**  
```
+---------------------+
|      User Apps      |
+---------------------+
| File Sys | Network  | ← All in kernel
| Device Drivers      |
+---------------------+
|        HW           |
+---------------------+
```

### **B. Microkernel**  
- **Minimal kernel (IPC, memory). Services run in user space.**  
- **Example:** MINIX  
- **Pros:** More stable/secure  
- **Cons:** Slower (frequent mode switches)  

### **C. Hybrid (Linux Modules)**  
- **Compromise:** Core kernel + loadable modules  
- **Example:** Modern Linux  

---

## **1.2.5 The Shell**  
**Definition:** Command-line interpreter bridging users and OS.  

### **Shell Types**  
| **Shell** | **Features**                     | **Example Command**       |  
|-----------|----------------------------------|---------------------------|  
| Bash      | Default on Linux                 | `ls -l`                   |  
| Zsh       | Auto-completion                  | `cd /usr/local/<TAB>`     |  
| PowerShell| Object-oriented (Windows)        | `Get-Process`             |  

**Demo Idea:**  
- Compare `bash` vs `zsh` tab-completion.  

---

## **1.2.6 Open Source Operating Systems**  

### **Key Examples**  
| **OS**      | **Use Case**          | **Key Feature**               |  
|-------------|-----------------------|-------------------------------|  
| Linux       | Servers, Desktops     | Customizable kernel           |  
| FreeBSD     | Networking            | ZFS file system               |  
| Android     | Mobile                | Linux-based, open-core        |  

### **Open-Source Advantages**  
1. **Transparency:** Auditable code (e.g., Heartbleed bug fix).  
2. **Community-Driven:** Rapid updates (Linux patches in hours).  
3. **No Vendor Lock-in:** Avoid proprietary constraints.    

## **Summary Table: OS Architectures**  
| **Type**       | **Performance** | **Security** | **Example** |  
|----------------|----------------|--------------|-------------|  
| Monolithic     | High           | Medium       | Linux       |  
| Microkernel    | Low            | High         | MINIX       |  
| Hybrid         | High           | High         | Windows NT  |  

---

### **Short Question Answers(5 marks)**
1. Explain microkernels and exokernels.
2. Define the terms shell and system call. How it is handled? Illustrate with suitable example.

1-> ans
### **Microkernels vs. Exokernels**  
*(Advanced Operating System Architectures)*  

---

## **1. Microkernels**  
**Definition:**  
A minimal OS kernel that provides only essential services:  
- **Process scheduling**  
- **Inter-process communication (IPC)**  
- **Basic memory management**  

All other services (file systems, device drivers) run as **user-space processes**.  

### **Key Principles**  
1. **Minimal Privilege:** Kernel runs with minimum permissions.  
2. **Modularity:** Services can be added/removed without kernel changes.  
3. **Fault Isolation:** Crash in a service (e.g., driver) doesn’t crash the entire OS.  

### **Examples**  
- **MINIX 3**: Used for teaching OS concepts.  
- **QNX**: Powers critical systems (e.g., medical devices, car infotainment).  
- **L4 Microkernel**: Focuses on high-performance IPC.  

### **Advantages**  
✔ **High Security/Stability** (Isolated components).  
✔ **Easier Debugging** (User-space services can be restarted).  
✔ **Flexibility** (Customizable for embedded systems).  

### **Disadvantages**  
✖ **Performance Overhead** (Frequent user/kernel mode switches).  
✖ **Complex IPC** (Communication between services is slower).  

**Diagram:**  
```
+---------------------+
|  User Applications  |
+---------------------+
| File System | Driver |  ← Runs as user processes  
+---------------------+
|       IPC Layer      |  ← Microkernel (only handles IPC/scheduling)
+---------------------+
|        Hardware      |
+---------------------+
```

---

## **2. Exokernels**  
**Definition:**  
An extreme minimalist kernel that **only manages hardware resources** (CPU, memory, disk).  
- **No abstractions** (e.g., no file systems, virtual memory).  
- Applications request **raw hardware access** and build their own abstractions.  

### **Key Principles**  
1. **Library OS:** Applications link to libraries that provide abstractions.  
2. **Secure Binding:** Kernel ensures fair/resource-safe access.  
3. **Customization:** Each app can optimize its OS layer.  

### **Examples**  
- **ExOS** (MIT’s prototype exokernel).  
- **XOK** (Harvard’s exokernel for networking research).  

### **Advantages**  
✔ **Ultra-High Performance** (No unnecessary layers).  
✔ **Custom Abstractions** (Database apps can optimize file access).  
✔ **Security** (Kernel only enforces resource allocation).  

### **Disadvantages**  
✖ **Complex Development** (Apps must handle low-level details).  
✖ **Limited Adoption** (Mostly used in research).  

**Diagram:**  
```
+---------------------+
|  App 1   |  App 2   |  ← Each app has its own OS library  
+---------------------+
| Lib OS   | Lib OS   |  ← Custom file system, memory mgmt.  
+---------------------+
|       Exokernel      |  ← Only manages CPU/memory/disk  
+---------------------+
|        Hardware      |
+---------------------+
```

---

## **Comparison: Microkernel vs. Exokernel**  
| **Feature**       | **Microkernel**            | **Exokernel**               |  
|-------------------|----------------------------|-----------------------------|  
| **Abstractions**  | Provides some (IPC, tasks) | None (apps build their own) |  
| **Performance**   | Moderate (IPC overhead)    | Maximum (no layers)         |  
| **Use Cases**     | Embedded systems, safety   | Research, high-perf apps    |  
| **Complexity**    | Medium (services in user)  | High (apps manage HW)       |  


2-> ans
### **Definitions and Handling of Shell & System Calls**  


### **1. Shell**  
**Definition:**  
A **shell** is a **command-line interpreter** that acts as an interface between users and the operating system. It:  
- Accepts user commands (e.g., `ls`, `mkdir`).  
- Translates them into system calls.  
- Manages processes (e.g., foreground/background jobs).  

**Example Shells:**  
- **Bash** (Linux/macOS)  
- **PowerShell** (Windows)  

### **2. System Call**  
**Definition:**  
A **system call** is a programmatic request made by an application to the OS kernel for **privileged operations** (e.g., file access, process creation).  

**Key Features:**  
- Bridges user programs and kernel.  
- Requires a **mode switch** (user → kernel mode).  

**Common System Calls:**  
| **Category**       | **Example**   | **Purpose**                     |  
|--------------------|---------------|---------------------------------|  
| File Operations    | `open()`, `read()` | Access files                 |  
| Process Control    | `fork()`, `exec()` | Create/manage processes      |  


## **Example**  

### **Scenario:**  
A user runs `cat file.txt` in the shell.  

### **Step 1: Shell Parses Command**  
- The shell (e.g., Bash) splits `cat file.txt` into:  
  - **Program:** `cat` (concatenate files)  
  - **Argument:** `file.txt`  

### **Step 2: Shell Invokes System Calls**  
1. **`fork()`**: Creates a child process to run `cat`.  
2. **`exec()`**: Replaces the child process with `cat`.  
3. **`open()`**: Opens `file.txt`.  
4. **`read()`**: Reads file contents.  
5. **`write()`**: Prints to terminal (stdout).  

### **Step 3: System Call Execution**  
1. **User → Kernel Transition**:  
   - CPU switches to **kernel mode** via software interrupt (e.g., `int 0x80` on x86).  
2. **Kernel Performs Operation**:  
   - Validates the request (e.g., checks file permissions).  
   - Accesses hardware (disk) if needed.  
3. **Kernel → User Transition**:  
   - Returns results to the user program.  

**Diagram:**  
```
User Program (cat) → System Call Interface → Kernel → Hardware
                      (Mode Switch)
```





