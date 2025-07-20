# **Unit 6: Device Management**

## **6.1 I/O Devices and Hardware Interfaces**

### **1. Classification of I/O Devices**
| **Category**       | **Characteristics**                          | **Examples**                     |
|--------------------|---------------------------------------------|----------------------------------|
| **Block Devices**  | Fixed-size data transfers (blocks/sectors)  | Hard disks, SSDs, USB drives     |
| **Character Devices** | Stream-based byte transfers              | Keyboards, mice, serial ports    |
| **Network Devices**  | Packet-based communication               | Ethernet cards, Wi-Fi adapters   |
| **Special Devices**  | Non-standard interfaces                  | `/dev/null`, `/dev/random`      |

**Key Concept:**  
- Block devices support random access; character devices are sequential.

---

### **2. Device Controllers**
**Function:** Bridge between hardware and OS, translating high-level commands to device-specific operations.  
**Components:**  
- **Registers:** Store commands/data (e.g., status, control).  
- **Local Buffer:** Temporary data storage.  

**Example (Disk Controller):**  
1. OS sends "read sector 42" command.  
2. Controller moves disk arm, reads data into buffer.  
3. Generates interrupt upon completion.  

**Advantages:**  
- Standardizes interface.  
- Offloads low-level control from CPU.  

---

### **3. Memory-Mapped I/O**

It is a hardware/software architecture paradigm where:
- I/O devices are accessed by reading/writing to specific memory addresses
- The CPU uses standard memory access instructions (load/store) to interact with devices
- Eliminates the need for special I/O instructions (like x86's IN/OUT)

**Pros:**  
- No special I/O instructions needed.  
**Cons:**  
- Memory space consumption.  

---

### **4. Direct Memory Access (DMA)**
**Operation:**  
1. CPU sets up DMA controller (source, destination, length).  
2. DMA transfers data directly between device and RAM.  
3. Interrupt upon completion.  

**Example:**  
- Disk reads 4KB to RAM without CPU byte-by-byte involvement.  

**Advantages:**  
- Frees CPU for other tasks.  
- Faster bulk transfers.  
**Disadvantages:**  
- Complexity (cache coherency issues).  

```
+----------------+       +-------------------+       +---------------+
|                |       |                   |       |               |
|    CPU         |       |  DMA Controller   |       |  I/O Device   |
|                |       |                   |       |  (e.g., Disk) |
+-------+--------+       +---------+---------+       +-------+-------+
        |                          |                         |
        | [1] INITIATE             |                         |
        | Program DMA:             |                         |
        | - Source (Device)        |                         |
        | - Dest (RAM 0x1000)      |                         |
        | - Size (4KB)             |                         |
        |------------------------->|                         |
        |                          |                         |
        |                          | [2] REQUEST BUS         |
        |                          | (CPU pauses if needed)  |
        |                          |------------------------>|
        |                          |                         |
        |                          | [3] TRANSFER DATA       |
        |                          | (Device → RAM)          |
        |                          |                         |
        |                          |    +---------------+    |
        |                          |    |    BUS        |    |
        |                          |    +-------+-------+    |
        |                          |            |            |
        |                          |    +-------v-------+    |
        |                          |    |     RAM       |    |
        |                          |    |  [0x1000]     |    |
        |                          |    +---------------+    |
        |                          |                         |
        |                          | [4] COMPLETE            |
        |<-------------------------| (Interrupt to CPU)      |
        |                          |                         |
+-------+--------+       +---------+---------+       +-------+-------+
|                |       |                   |       |               |
|    RAM         |<======|======= BUS =======|======>|               |
|                |       |                   |       |               |
+----------------+       +-------------------+       +---------------+
```


### DMA Data Transfer Process Steps:

1. **CPU Initiates DMA Transfer**

   * CPU programs the DMA controller with:

     * **Source:** The I/O device (e.g., disk)
     * **Destination:** RAM address (e.g., 0x1000)
     * **Size:** Amount of data to transfer (e.g., 4 KB)
   * CPU then signals the DMA controller to start the transfer.

2. **DMA Controller Requests Bus Control**

   * DMA controller requests control of the system bus to perform the transfer.
   * If CPU is currently using the bus, it **pauses** (bus arbitration) to allow DMA controller access.

3. **DMA Transfers Data**

   * DMA controller directly transfers data from the I/O device to RAM over the system bus without CPU intervention.
   * Data flows: **Device → DMA controller → RAM**

4. **DMA Transfer Complete - Interrupt CPU**

   * Once the transfer finishes, the DMA controller sends an **interrupt** signal to the CPU.
   * CPU resumes control and processes the data as needed.


---

### **5. Interrupts**
**Types:**  
| **Type**          | **Trigger**                     | **Use Case**               |
|-------------------|---------------------------------|----------------------------|
| Hardware Interrupt | Device signals (e.g., keypress) | I/O completion             |
| Software Interrupt | `int 0x80` (system calls)      | Kernel service requests    |
| Exception         | CPU faults (e.g., divide by 0)  | Error handling             |

**Interrupt Handling Steps:**  
1. CPU finishes current instruction.  
2. Saves context (registers, PC).  
3. Jumps to Interrupt Service Routine (ISR).  
4. Restores context and resumes.  


---


# 6.2 I/O Software

### Overview

I/O Software is a collection of programs and routines that control and manage input/output devices, acting as an intermediary between the hardware and user or application programs. It hides the complicated details of device hardware, allowing programs to perform I/O tasks easily and consistently.

For example, when a program wants to read data from a keyboard or print text on the screen, it uses I/O software like device drivers and operating system routines to communicate with the actual hardware without dealing directly with the device specifics.

### Functions of I/O Software

1. **Device Independence**

   * Programs use generic I/O calls without needing to know hardware specifics.
   * I/O software translates these calls to device-specific commands.

2. **Buffering**

   * Temporarily stores data between the device and the program.
   * Helps match the speed differences between devices and CPU/memory.

3. **Error Handling**

   * Detects and recovers from device errors.
   * Reports errors to the system or user.

4. **Device Scheduling**

   * Manages multiple I/O requests.
   * Schedules device access efficiently, often optimizing throughput and response time.

5. **Device Initialization and Control**

   * Initializes device registers and configures device modes.
   * Controls device operations by sending commands.


### Layers of I/O Software

Typically, I/O software is organized into layers that progressively abstract complexity:

1. **User-level I/O software (Application Programs)**

   * High-level interfaces and APIs for performing I/O.
   * Example: Reading a file, printing to screen.

2. **Device-independent I/O software**

   * Provides generic I/O operations regardless of device type.
   * Manages buffering, error handling, and device scheduling.
   * Examples: File system routines, buffering modules.

3. **Device Drivers (Device-dependent I/O software)**

   * Specific to each hardware device.
   * Translates generic requests into hardware-specific commands.
   * Manages device registers, interrupts, and data transfer.

4. **Interrupt Handlers and Device Controllers**

   * Lowest-level software interacting directly with hardware.
   * Handles interrupts and manages immediate hardware status.


### Types of I/O Software Interfaces

* **System Calls**: OS provides system calls for I/O operations like `read()`, `write()`, `open()`, `close()`.
* **I/O Libraries**: Provide higher-level routines using system calls.
* **Device Drivers**: Offer device-specific routines to control hardware.


### Example: Reading a File Using I/O Software

1. Application calls `read()` system call.
2. Device-independent I/O software checks buffers or schedules device access.
3. Device driver sends commands to hardware device.
4. Device performs data transfer using programmed I/O or DMA.
5. Interrupt signals completion; device driver and OS update status.
6. Data returns to application.


### Summary Table

| **Function**        | **Description**                             |
| ------------------- | ------------------------------------------- |
| Device Independence | Hides device details from user programs     |
| Buffering           | Temporarily stores data to smooth transfers |
| Error Handling      | Detects and manages device errors           |
| Device Scheduling   | Orders device access for efficiency         |
| Device Control      | Sends commands and configures devices       |

---

## **6.3 Disk Management**

### **1. Disk Structure**
- **Platters, Tracks, Sectors:**  
  - 512B–4KB/sector (modern disks use 4K sectors).  
- **Cylinder:** Same track across platters.  

![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/CSIT/4th%20Sem/OS/images/Unit%206/disk%20%20structure.jpg)

![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/CSIT/4th%20Sem/OS/images/Unit%206/platter.png)


### **2. Disk Scheduling Algorithms**
| **Algorithm** | **Description**                  | 
|---------------|----------------------------------|
| **FCFS**      | First-Come-First-Served          | 
| **SSTF**      | Shortest Seek Time First         | 
| **SCAN**      | Elevator algorithm (full sweep)  | 
| **LOOK**      | SCAN but reverses at last request| 
| **C-SCAN**    | Circular SCAN (resets to start)  |

**Numericals**

![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/CSIT/4th%20Sem/OS/images/Unit%206/disk%20scheduling%20algorithm%201.png)

![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/CSIT/4th%20Sem/OS/images/Unit%206/disk%20scheduling%20algorithm%202.png)

![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/CSIT/4th%20Sem/OS/images/Unit%206/disk%20scheduling%20algorithm%203.png)

![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/CSIT/4th%20Sem/OS/images/Unit%206/disk%20scheduling%20algorithm%204.png)

![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/CSIT/4th%20Sem/OS/images/Unit%206/disk%20scheduling%20algorithm%205.png)

![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/CSIT/4th%20Sem/OS/images/Unit%206/disk%20scheduling%20algorithm%206.png)

![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/CSIT/4th%20Sem/OS/images/Unit%206/disk%20scheduling%20algorithm%207.png)


---

### **3. Disk Formatting Techniques**
- **Low-Level Formatting:**  
  - Divides platters into sectors (factory done).  
- **Cylinder Skew:**  
  - Offsets sector numbering to reduce rotation delay.  
- **Interleaving:**  
  - Physical/logical sector staggering (obsolete in modern disks).  

**Error Handling:**  
- **ECC (Error-Correcting Codes):** Detects/corrects bit flips.  
- **Bad Sector Remapping:** Spare sectors replace defective ones.  

---

### **4. RAID Levels**

RAID is a storage virtualization technology that combines multiple physical disk drives into a single logical unit for:
- Improved performance (via parallel I/O operations)
- Increased reliability (via redundancy)
- Enhanced capacity (via aggregation)

| **Level** | **Description**          | **Redundancy?** | **Performance** | **Use Case**       |
|-----------|--------------------------|-----------------|-----------------|--------------------|
| RAID 0    | Striping                 | No              | High            | Video editing      |
| RAID 1    | Mirroring                | Yes             | Moderate        | Critical databases |
| RAID 5    | Striping + Parity        | Yes             | High read       | File servers       |
| RAID 6    | Dual parity              | Yes             | High read       | Archival storage   |


---

