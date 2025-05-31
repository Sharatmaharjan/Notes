# **Unit 4: Memory Management**

## **4.1 Memory Management Fundamentals**

### **Introduction to Memory Management**
Memory management is the core OS function responsible for:
- **Allocation/Deallocation** of memory to processes  
- **Protection/isolation** between processes  
- **Optimization** of memory utilization  

**Key Challenges:**
- Fragmentation (internal/external)
- Address translation overhead
- Swapping between RAM and disk  

**Diagram Suggestion:**  
Insert a three-layer memory hierarchy diagram showing:  
1. CPU registers  
2. Primary memory (RAM)  
3. Secondary storage (Disk)  

---

### **Monoprogramming vs. Multiprogramming**

#### **Monoprogramming**
**Definition:** Only one process resides in memory at a time.  

**Example:**  
Early DOS systems where a single program (e.g., WordPerfect) occupied all available memory.  

**Advantages:**  
- Simple implementation  
- No process synchronization needed  

**Disadvantages:**  
- Poor resource utilization (CPU idle during I/O)  
- No memory protection  

#### **Multiprogramming**  
**Definition:** Multiple processes concurrently reside in memory.  

**Example:**  
Modern OS like Linux running Firefox, LibreOffice, and terminal simultaneously.  

**Key Requirements:**  
- Memory protection (MMU support)  
- Allocation tracking (bitmaps/linked lists)  
- Context switching capability  

**Advantages:**  
- Higher CPU utilization  
- Better throughput  

**Disadvantages:**  
- Complex memory management  
- Overhead for protection mechanisms  

**Diagram Suggestion:**  
Comparative timeline showing:  
- 1960s: Monoprogramming (batch systems)  
- 1970s: Multiprogramming (UNIX timesharing)  

---

### **Modelling Multiprogramming**

#### **Degree of Multiprogramming**
The number of processes in memory affects:  
- **CPU utilization** (Amdahl's Law)  
- **Throughput** vs. **response time** tradeoff  

**Mathematical Model:**  
```
CPU Utilization ≈ 1 - pⁿ  
Where:  
p = I/O wait probability  
n = # of processes  
```

**Practical Implications:**  
- Too few processes → CPU idle  
- Too many processes → thrashing  

**Example Calculation:**  
If each process spends 80% time waiting (p=0.8):  
- With n=2: Utilization = 1-0.8² = 36%  
- With n=4: Utilization = 1-0.8⁴ = 59%  

**Diagram Suggestion:**  
Graph plotting CPU utilization vs. degree of multiprogramming.  

---

### **Fixed vs. Variable Partitions**

#### **Fixed Partitions**  
**Implementation:**  
- Memory divided into fixed-size blocks  
- Each partition holds one process  

**Example:**  
IBM OS/360 with partitions like:  
- 64KB (small jobs)  
- 256KB (medium jobs)  
- 1MB (large jobs)  

**Advantages:**  
- Simple to implement  
- Fast allocation  

**Disadvantages:**  
- Internal fragmentation  
- Inflexible for varying process sizes  

#### **Variable Partitions**  
**Implementation:**  
- Memory dynamically divided as needed  
- Each process gets exact required space  

**Example:**  
Modern malloc() implementation in Unix/Linux.  

**Advantages:**  
- No internal fragmentation  
- Efficient memory use  

**Disadvantages:**  
- External fragmentation  
- Complex allocation algorithms required  

**Diagram Suggestion:**  
Side-by-side memory maps showing:  
- Fixed partitions with wasted space  
- Variable partitions with external fragmentation  

---

### **Relocation and Protection**

#### **Static Relocation**  
- Addresses bound at compile/load time  
- **Problem:** Cannot move process after loading  

#### **Dynamic Relocation**  
- Uses **base-limit registers**  
- MMU translates logical → physical addresses  

**Protection Mechanism:**  
```
If (logical_addr > limit_register)  
    → Trigger segmentation fault  
Else  
    → physical_addr = base_register + logical_addr  
```

**Example:**  
x86 architecture uses:  
- CS (Code Segment) register as base  
- EFLAGS register for protection  

**Advantages:**  
- Enables virtual memory  
- Supports process isolation  

**Disadvantages:**  
- MMU hardware required  
- Address translation overhead  

**Diagram Suggestion:**  
MMU operation flowchart with base/limit registers.  

---

## **4.2 Memory Management Techniques**

### **Bitmaps vs. Linked Lists**

#### **Bitmaps**  
**Implementation:**  
- Each bit represents fixed-size block status  
  (0=free, 1=allocated)  

**Example:**  
For 1GB memory with 4KB blocks:  
- Requires 32KB bitmap (1GB/4KB/8 bits)  

**Advantages:**  
- Fast to find consecutive free blocks  
- Compact representation  

**Disadvantages:**  
- Search time O(n) for first-fit  
- Wastes space for large memories  

#### **Linked Lists**  
**Implementation:**  
- Nodes track:  
  - Hole/process flag  
  - Start address  
  - Size  
  - Next pointer  

**Variants:**  
- Singly-linked (basic)  
- Doubly-linked (better merging)  

**Advantages:**  
- Efficient merging of freed blocks  
- Flexible for variable sizes  

**Disadvantages:**  
- Fragmentation over time  
- Pointer overhead  

**Diagram Suggestion:**  
Visual comparison of:  
- Bitmap for 16 blocks  
- Linked list with 3 allocated regions  

---

### **Memory Allocation Strategies**

#### **First-Fit**  
- Allocate first sufficient hole found  
- **Advantage:** Fast  
- **Disadvantage:** Creates small fragments  

#### **Best-Fit**  
- Allocate smallest sufficient hole  
- **Advantage:** Reduces wasted space  
- **Disadvantage:** Leaves unusable fragments  

#### **Worst-Fit**  
- Allocate largest available hole  
- **Advantage:** Leaves large remaining blocks  
- **Disadvantage:** Poor for large processes  

**Performance Comparison:**  

| Strategy | Allocation Time | Fragmentation |  
|----------|-----------------|---------------|  
| First-Fit | O(n) | Moderate |  
| Best-Fit | O(n) | High |  
| Worst-Fit | O(n) | Low |  

**Empirical Finding:**  
First-fit generally outperforms others in practice.  

**Diagram Suggestion:**  
Animation showing allocation patterns for 3 strategies.  

---
