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

## **6.2 I/O Software**

### **1. Goals of I/O Software**
- **Device Independence:** Uniform interface (`read()/write()`).  
- **Error Handling:** Retry transient errors (e.g., disk read failures).  
- **Synchronous/Asynchronous:** Support both blocking and non-blocking I/O.  

---

### **2. I/O Handling Techniques**
| **Method**            | **Mechanism**                              | **Pros**               | **Cons**              |
|-----------------------|-------------------------------------------|------------------------|-----------------------|
| **Programmed I/O**    | CPU polls device status                   | Simple                 | Wastes CPU cycles     |
| **Interrupt-Driven**  | Device interrupts CPU when ready          | Efficient for low load | Overhead at high load |
| **DMA**              | Offloads transfer to DMA controller       | Best for bulk data     | Complex setup         |

---

### **3. I/O Software Layers**
**Layered Architecture:**  
1. **Interrupt Handlers:**  
   - Minimal (save state, wake driver).  
   - Example: Mark disk read completion.  
2. **Device Drivers:**  
   - OS-specific code to control hardware.  
   - Example: `nvme.ko` for NVMe SSDs.  
3. **Device-Independent Layer:**  
   - Uniform API, error handling.  
4. **User-Level I/O:**  
   - Libraries (e.g., `stdio.h`).  


---

## **6.3 Disk Management**

### **1. Disk Structure**
- **Platters, Tracks, Sectors:**  
  - 512B–4KB/sector (modern disks use 4K sectors).  
- **Cylinder:** Same track across platters.  



---

### **2. Disk Scheduling Algorithms**
| **Algorithm** | **Description**                  | 
|---------------|----------------------------------|
| **FCFS**      | First-Come-First-Served          | 
| **SSTF**      | Shortest Seek Time First         | 
| **SCAN**      | Elevator algorithm (full sweep)  | 
| **LOOK**      | SCAN but reverses at last request| 
| **C-SCAN**    | Circular SCAN (resets to start)  |

**Numericals**

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

