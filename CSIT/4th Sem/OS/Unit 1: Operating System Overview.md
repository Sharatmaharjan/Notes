# **Unit 1: Operating System Overview**  
**Lecture Duration:** 4 Hours   

## **1.1 Definition, Two Views of OS, Evolution, Types of OS**  

### **1.1.1 Definition of an Operating System (OS)**  
An Operating System is a **resource manager** (hardware and software resources) and **control program**(acts like a traffic controller — deciding which tasks get to use the CPU, how memory is allocated, and how data is read from or written to devices.) that:  
- Acts as an intermediary between users/applications and computer hardware.  
- Provides an environment for program execution.  
- Manages hardware resources efficiently (CPU, memory, I/O devices).  


The OS performs four fundamental functions:  
1. **Process Management** - Creation, scheduling, synchronization of processes.  
2. **Memory Management** - Allocation/deallocation, virtual memory handling.  
3. **File System Management** - Organizes data storage hierarchically.  
4. **Device Management** - Handles device drivers and I/O operations.  


**Real-world Analogy:**  
*"An operating system is like a manager that handles the work of many employees (programs), gives them tools (resources), ensures they follow the rules, and keeps everything running smoothly without conflict."*  

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
  - I/O device arbitration (operating system determines which I/O device gets access to the system bus(Transfers data/signals between CPU, memory, and I/O devices) or CPU when multiple devices request it at the same time).  
- **Control Program:**  
  - Prevents errors via process isolation.  
  - Enforces security policies.

 ```
For Reference Only:
                +----------------------+
                |      CPU (Processor) |
                |  +----------------+  |
                |  |   ALU          |  |
                |  |   Control Unit |  |
                |  |   Registers     | |
                +----------------------+
                          |
         +----------------+----------------+
         |                |                |
   +------------+  +-------------+  +-------------+
   |  Data Bus  |  | Address Bus |  | Control Bus |
   +------------+  +-------------+  +-------------+
         |                |                |
         |                |                |
+----------------+  +----------------+  +----------------+
|     Memory     |  |  I/O Devices   |  |   Storage      |
|   (RAM, ROM)   |  | (Mouse, etc.)  |  | (HDD, SSD, etc.)|
+----------------+  +----------------+  +----------------+
```
 
---

### **1.1.3 Evolution of Operating Systems**   

| **Era**          | **Key Innovation**                     | **Example OS**       | **Impact**                          |  
|-------------------|----------------------------------------|----------------------|-------------------------------------|  
| **1940s-50s**     | No OS – Machine language programming  | –                    | Manual execution via punch cards.   |  
| **1950s-60s**     | Batch Processing                       | IBM OS/360           | Automated job sequencing.           |  
| **1960s-70s**     | Multiprogramming & Time-Sharing        | UNIX                 | Concurrent user access.             |  
| **1980s-90s**     | Personal Computers & GUI               | Windows 95, Mac OS   | Made computers user-friendly.       |  
| **2000s-Present** | Mobile/Distributed Systems             | Android, Linux       | Cloud computing, IoT integration.   |  


**Visualization**  
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
(Windows 10 and kali linux are desktop OS)

#### **1. Batch Processing OS**
- Processes jobs in groups without user interaction -> (The user submits a "job" (program + data) → jobs are grouped into a batch → processed in order → output is received later.)
- **Use Case:** Payroll systems, bank transactions(interest calculation, account updates, statement generation, etc.)
- **Pros:** Efficient for large repetitive tasks
- **Cons:** No real-time feedback

#### **2. Time-Sharing/Multitasking OS**
- Shares CPU time between multiple users/tasks (Personal Computing: Run multiple apps and user programs at the same time, Servers(Web, Database):	Handle many user requests simultaneously)
- **Key Feature:** Quick task switching (10-100ms slices)
- **Examples:** Linux, Windows, macOS
- **Advantage:** Enables interactive computing

#### **3. Real-Time OS (RTOS)**
- Designed for time-critical applications where delay is unacceptable.
  a. **Hard Real-Time Operating System (Hard RTOS):**
    - Meeting deadlines is absolutely critical.
    - If a task doesn’t complete **exactly on time**, it can cause **serious failures or even danger**.
    - These systems are used where timing is **life-critical** or **safety-critical**, such as in **medical devices** (like pacemakers or life-support machines, eg; FreeRTOS) or **airbag control systems** in cars eg; SafeRTOS.
    - The system guarantees that every critical task will finish **within a strict, fixed deadline**, no exceptions.

  b. **Soft Real-Time Operating System (Soft RTOS):**

    - In a **Soft RTOS**, deadlines are important, but missing them occasionally won’t cause catastrophic failure.
    - These are used in applications where timing is important for quality but not safety, such as **video streaming** (VxWorks), **online gaming**, or **multimedia applications**.
    - For example, a slight delay in streaming video might cause a brief hiccup, but it won’t endanger users or damage equipment.

#### **4. Distributed OS**
- Manages networked computers as single system
- **Features:** Resource sharing, fault tolerance
- **Examples:** Google Borg, Hadoop(Facebook for distributed storage and processing)

#### **5. Network OS**
- Manages shared resources in client-server model (manages network resources like files, printers, and users across multiple connected computers (nodes) in a Local Area Network (LAN) or similar setup.Unlike a distributed OS that tries to make multiple computers act like one system, a Network OS keeps them separate but lets them communicate and share resources.)
- **Examples:** Windows Server, Linux servers

#### **6. Mobile OS**
- Optimized for touch, battery life
- **Examples:** Android, iOS
- **Key Features:** App sandboxing, power management

| Organization Type      | Server OS Example     | Description                               |
| ---------------------- | --------------------- | ----------------------------------------- |
| Small/Medium Business  | Windows Server, Linux | Standard server OS for file sharing, apps |
| Tech Giants (Google)   | Google Borg + Linux   | Large-scale, distributed resource control |
| Tech Giants (Facebook) | Tupperware + Linux    | Handles massive web traffic and services  |


| Aspect               | Time-Sharing OS        | Distributed OS                        |
| -------------------- | ---------------------- | ------------------------------------- |
| Users                | Many users on 1 system | Users on many systems (appear as one) |
| Resource location    | Centralized            | Decentralized (networked nodes)       |
| Scalability          | Limited                | High                                  |
| Fault Tolerance      | Low                    | High (failover mechanisms)            |
| Communication Needed | Minimal                | Extensive (over network)              |


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


#### **1.2.1 System Calls**  
**Definition:**  
Programmatic requests from applications to the OS kernel for privileged operations.  (The kernel is the **brain** of the operating system — always running in the background to control the system’s most basic functions->Starts, stops, and schedules processes->Decides how much memory each process gets.->Helps software read/write to files and directories.)

### **Key System Call Categories**  
| **Category**        | **System Calls**     | **Function**                     |
| ------------------- | -------------------- | -------------------------------- |
| Process Control     | `fork()`, `exit()`   | Create and terminate processes   |
| File Management     | `open()`, `read()`   | Open and access file contents    |
| Device Management   | `ioctl()`, `write()` | Control and send data to devices(Input/Output Control) |
| Communication (IPC) | `pipe()`, `shmget()` | Exchange data between processes(Shared Memory GET)  |


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
User Program (User Mode)
          |
          |   1. System Call (e.g., int 0x80)
          V
+-------------------------+
|                         |
|      CPU switches from User Mode   | 
|      to Kernel Mode      |
|                         |
+-------------------------+
          |
          |   2. Kernel handles request (e.g., read file)
          V
+-------------------------+
|                         |
|      OS Kernel runs      |  <-- Executes privileged instructions
|                         |
+-------------------------+
          |
          |   3. Return result and switch back
          V
User Program (User Mode)

```
```mermaid
graph LR
 A[User Program (User Mode)] -->|1. System Call (e.g., int 0x80)| B[CPU switches from User Mode to Kernel Mode]
    B -->|2. Kernel handles request (e.g., read file)| C[OS Kernel runs<br>(executes privileged instructions)]
    C -->|3. Return result and switch back| A

```
---

### **1.2.3 System Programs**  
**Purpose:** Provide user-friendly utilities to manage system resources.  

### **Types & Examples**  
| **Type**           | **Linux Examples**                   | **Windows Equivalent**                         |
| ------------------ | ------------------------------------ | ---------------------------------------------- |
| File Management    | `ls`, `cp`                           | File Explorer, `dir`, `copy`                   |
| Process Management | `top`, `ps`, `kill`                  | Task Manager, `tasklist`, `taskkill`           |
| Networking         | `ping`, `ifconfig`, `netstat`        | `ping`, `ipconfig`, `netstat`                  |

---

### **1.2.4 Operating System Structures**  

### 1. **Monolithic Structure**

* The OS is implemented as a **single large program** running entirely in **kernel mode**.
* All core functions like process management, memory management, device drivers, file system, and system calls are part of this big kernel.
* Communication within the kernel happens via direct procedure calls.

#### Characteristics:

* Fast execution because all services are in the same address space.
* Hard to maintain or extend because all components are tightly coupled.
* A bug in any part of the kernel can crash the entire system.

#### Example:

* Traditional Unix, early Linux kernels.


### 2. **Microkernel Structure**

* The kernel includes only essential services such as low-level memory management, process management, and inter-process communication.
* Other services like device drivers, file systems, and network protocols run in **user mode** as separate processes.
* Communication between services and kernel uses message passing (IPC).

| Mode            | What Runs Here                | Example                     |
| --------------- | ----------------------------- | --------------------------- |
| **User Mode**   | Apps, browsers, editors       | Chrome, VS Code, Calculator |
| **Kernel Mode** | OS core, hardware interaction | Disk I/O, memory management |


#### Characteristics:

* Small kernel size improves security and stability.
* Easier to extend and port to new hardware.
* Potentially lower performance due to IPC overhead.

#### Example:

* MINIX, QNX, Mach (basis for macOS), L4 microkernel.

| In Microkernel                                                                                                                                  |
| ----------------------------------------------------------------------------------------------------------------------------------------------- |
| App → Microkernel (system call) → IPC → File System service (user mode) → IPC → Disk Driver (user mode) → IPC → File System → Microkernel → App |


| **Step** | **Action**                                | **Monolithic Kernel**                                                       | **Microkernel**                                                                                 |
| -------- | ----------------------------------------- | --------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------- |
| 1        | Launching a text editor (e.g., Notepad)  | Runs in **User Mode**                                                       | Runs in **User Mode**                                                                           |
| 2        | App requests to open `myfile.txt`         | Makes a **system call** to the kernel (`open()`)                            | Makes a **system call** to the microkernel                                                      |
| 3        | OS checks permissions, file existence     | **Kernel handles everything internally** (file system, memory, permissions) | Microkernel **forwards** the request to **user-space file system service** via **IPC** (Because this service is outside the kernel, if it crashes or misbehaves, it won’t bring down the whole system, increasing reliability and security.)         |
| 4        | OS reads file from disk                   | **Disk driver** is in kernel space — reads data directly                    | Microkernel sends the request to a disk driver running in user space and returns the data back to the file system service by disk driver after reading, again through IPC                     |
| 5        | File contents returned to the application | Data passed back via kernel to user mode                                    | Data returned from file system server → microkernel → text editor via **message passing** (IPC) |


### 3. **Modular Structure(Modern Linux)** -> (modular monolithic kernel)

- Linux kernel runs most OS services (process management, file system, drivers) in kernel space as one big binary.
- It supports loadable kernel modules (LKMs) — pieces of code (like device drivers or file systems) that can be dynamically loaded/unloaded without rebooting.
- This modularity adds flexibility and easier maintenance without fully sacrificing monolithic speed.
- So, Linux is often called a modular monolithic kernel — combines performance of monolithic kernels with some flexibility of microkernel style.

#### Characteristics:

* Highly flexible and extensible.
* Improves maintainability.
* Reduces memory usage as only needed modules are loaded.

#### Example:

* Modern Linux kernels use modular design with Loadable Kernel Modules (LKMs).

---

### 4. **Layered Structure**
```
+-----------------------+
|       User Apps       |  ← Applications like browsers, editors
+-----------------------+
|   User Interface &    |  ← GUI, Command Line Interface
|      Utilities        |
+-----------------------+
|    File Management    |  ← Handles files, directories
+-----------------------+
|    Process Manager    |  ← Manages processes and scheduling
+-----------------------+
|   Device Management   |  ← Controls hardware devices
+-----------------------+
|      Kernel Layer     |  ← Core OS functions, CPU management
+-----------------------+
|    Hardware Layer     |  ← Physical hardware (CPU, Memory, I/O)
+-----------------------+
```

* The OS is divided into a number of **layers**, each built on top of the lower ones.
* The bottom layer (layer 0) is the hardware; the top layer (layer N) is the user applications.
* Each layer communicates only with its immediate lower and upper layers.
* Provides a clear modular design and easier debugging.

#### Characteristics:

* Modular approach simplifies OS development and maintenance.
* Performance overhead due to the layered calls.
* Layered structure is more conceptual; in practice, strict layering can be inefficient.

#### Example:

* THE OS (Technische Hogeschool Eindhoven OS), Windows NT has some layered aspects,IBM OS/360.


## 5. **Client-Server Structure**

### Description:

* OS functions are divided between **clients** (user applications) and **servers** (OS services).
* Servers provide services like file handling, device management, and communication.
* Clients request these services through message passing.
* Typically used in distributed operating systems and networked environments.

### Characteristics:

* Clear separation of user applications and system services.
* Supports distributed computing and networking.
* Can be slower due to message passing overhead.

### Example:

* Distributed OS, some implementations of microkernels.


### Summary Table

| Structure Type    | Description                               | Advantages                         | Disadvantages                   | Example OS                |
| ----------------- | ----------------------------------------- | ---------------------------------- | ------------------------------- | ------------------------- |
| **Monolithic**    | One big kernel with all OS services       | High performance                   | Less modular, hard to maintain  | Unix, Linux (traditional) |
| **Microkernel**   | Minimal kernel + user-mode servers        | Stability, security, portability   | IPC overhead, slower            | MINIX, QNX, Mach          |
| **Modular**       | Kernel + dynamically loadable modules     | Flexibility, extensibility         | Complexity in module management | Linux (modern)            |
| **Layered**       | OS divided into layers                    | Modular, easier debugging          | Performance overhead            | THE OS, Windows NT        |
| **Client-Server** | Services provided by servers, clients use | Separation of concerns, networking | Performance overhead            | Distributed OS            |

---

### **1.2.5 The Shell**  
**Definition:** Command-line interpreter bridging users and OS.  

#### **Shell Types**  
| **Shell** | **Features**                     | **Example Command**       |  
|-----------|----------------------------------|---------------------------|  
| Bash      | Default on Linux                 | `ls -l`                   |  
| Zsh       | Auto-completion                  | `cd /usr/local/<TAB>`     |  
| PowerShell| Object-oriented (Windows)        | `Get-Process`             |  


---

### **1.2.6 Open Source Operating Systems**  

#### **Key Examples**  
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





