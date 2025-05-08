# **Unit 1: Operating System Overview (4 Hrs.)** 

## **1.1 Definition, Views, Evolution, and Types of OS**  

### **Definition of Operating System (OS)**  
An **Operating System (OS)** is a system software that:  
- Acts as an **intermediary** between users and computer hardware.  
- Manages hardware resources (CPU, memory, disk, I/O devices).  
- Provides a **user-friendly interface** (GUI/CLI).  
- Ensures **efficient execution** of programs.  

### **Two Views of Operating System**  
1. **User View:**  
   - Provides an **easy-to-use interface** (GUI, command line).  
   - Hides hardware complexity (abstraction).  
   - Examples: Windows, macOS, Linux (Ubuntu).  

2. **System View:**  
   - Acts as a **resource manager** (CPU, memory, I/O).  
   - Controls and coordinates hardware usage.  
   - Prevents conflicts between programs.  

### **Evolution of Operating Systems**  
| Era | OS Type | Key Features |  
|------|---------|--------------|  
| **1940s-50s** | No OS | Manual programming via punch cards. |  
| **1950s-60s** | Batch Processing | Jobs collected in batches, executed sequentially. |  
| **1960s-70s** | Multiprogramming | Multiple jobs in memory, CPU switches between them. |  
| **1970s-80s** | Time-Sharing | Interactive computing, multiple users share CPU time. |  
| **1980s-90s** | Personal Computers | Single-user OS (DOS, Windows, Mac). |  
| **1990s-Present** | Modern OS | Multitasking, networking, GUI, mobile (Android, iOS). |  

### **Types of Operating Systems**  
1. **Batch OS**  
   - Jobs executed in batches (no user interaction).  
   - Example: Early mainframe systems.  

2. **Multitasking (Time-Sharing) OS**  
   - Multiple tasks run concurrently (CPU switches rapidly).  
   - Example: Unix, Linux.  

3. **Real-Time OS (RTOS)**  
   - Time-critical tasks (e.g., robotics, flight control).  
   - **Hard RTOS** (strict deadlines) vs. **Soft RTOS** (flexible).  

4. **Distributed OS**  
   - Manages multiple networked computers as a single system.  
   - Example: Cluster computing, cloud OS.  

5. **Embedded OS**  
   - Runs on small devices (IoT, smartwatches).  
   - Example: Android (for mobile), FreeRTOS.  

6. **Network OS**  
   - Manages servers and network resources.  
   - Example: Windows Server, Linux servers.  

---

## **1.2 System Calls, System Programs, OS Structures, Shell, Open Source OS**  

### **System Call**  
- A **programmatic way** for applications to request OS services.  
- Examples:  
  - `fork()` – Create a new process.  
  - `open()` – Access a file.  
  - `read()/write()` – File I/O operations.  

### **Handling System Calls**  
1. User program calls a **library function** (e.g., `printf()`).  
2. Library calls the **kernel via system call interface**.  
3. CPU switches to **kernel mode** (privileged execution).  
4. OS performs the requested task and returns result.  

### **System Programs (Utilities)**  
- Tools provided by OS for system management:  
  - **File management** (`cp`, `mv`, `rm` in Linux).  
  - **Process management** (`ps`, `kill`).  
  - **Disk management** (`fdisk`, `format`).  
  - **Networking** (`ping`, `ifconfig`).  

### **Operating System Structures**  
1. **Monolithic Kernel**  
   - All OS functions in a single kernel (Linux, Unix).  
   - **Pros:** Fast execution.  
   - **Cons:** Less modular, difficult to debug.  

2. **Microkernel**  
   - Minimal kernel (only essential functions).  
   - Other services run in user space (e.g., Mach, QNX).  
   - **Pros:** More stable, modular.  
   - **Cons:** Slower due to message passing.  

3. **Layered OS**  
   - OS divided into layers (each layer uses services of lower layers).  
   - Example: THE OS (Dijkstra’s design).  

4. **Hybrid Kernel**  
   - Combines monolithic and microkernel approaches.  
   - Example: Windows NT, macOS XNU.  

### **The Shell**  
- A **command-line interpreter** that takes user commands and executes them.  
- Types:  
  - **Bourne Shell (sh)** – Early Unix shell.  
  - **Bash (Bourne Again Shell)** – Default in Linux.  
  - **Zsh, Fish** – Modern alternatives.  

### **Open Source Operating Systems**  
- OS with **publicly available source code** (can be modified).  
- Examples:  
  - **Linux** (Ubuntu, Fedora, Debian).  
  - **FreeBSD** (Unix-like).  
  - **Android** (based on Linux kernel).  

---

## **Summary**  
✔ **Definition & Views** – OS as interface vs. resource manager.  
✔ **Evolution** – Batch → Multiprogramming → Time-Sharing → Modern OS.  
✔ **Types of OS** – Batch, RTOS, Distributed, Embedded, etc.  
✔ **System Calls** – Bridge between user programs and OS.  
✔ **OS Structures** – Monolithic, Microkernel, Layered, Hybrid.  
✔ **Shell** – CLI interpreter (Bash, Zsh).  
✔ **Open Source OS** – Linux, FreeBSD, Android.  
