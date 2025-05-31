# **Unit 4: Memory Management**

## **4.1 Memory Management Fundamentals**

### **a. Introduction to Memory Management**
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

### **b. Monoprogramming vs. Multiprogramming**

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

### **c. Modelling Multiprogramming**

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

### **d. Fixed vs. Variable Partitions**

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

### **e. Relocation and Protection**

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

### **a. Bitmaps vs. Linked Lists**

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

### **b. Memory Allocation Strategies**

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


## **4.3 Virtual Memory: Paging**

### **a. Introduction to Paging**
Virtual memory enables execution of processes larger than physical memory by dividing them into fixed-size blocks called **pages** (typically 4KB).

**Key Components:**
- **Page Table:** Maps virtual page numbers (VPN) to physical frame numbers (PFN)
- **Page Fault Handler:** Loads pages from disk when needed
- **TLB (Translation Lookaside Buffer):** Caches frequent translations

**Example:** 
32-bit system with 4KB pages → 2²⁰ pages (1M entries in page table)

---

### **b. Page Table Structures**

#### **1. Linear Page Table**
- Simple array indexed by VPN
- **Problem:** Large memory overhead (4MB for 32-bit systems)

#### **2. Hierarchical Page Tables**
- Multi-level tree structure
- **x86 Example:**  
  - Page Directory (10 bits)  
  - Page Table (10 bits)  
  - Offset (12 bits)  
- **Advantage:** Sparse memory representation

#### **3. Hashed Page Tables**
- Hash function reduces search space
- **Use Case:** Large address spaces (64-bit systems)

#### **4. Inverted Page Tables**
- One entry per physical frame
- **Advantage:** Constant space overhead
- **Disadvantage:** Complex lookup

**Diagram Suggestion:**  
Comparative diagrams of all four page table structures.

---

### **c. Handling Page Faults**
**Page Fault Sequence:**
1. MMU detects invalid page table entry
2. CPU traps to OS page fault handler
3. OS:
   - Checks access validity
   - Locates page on disk
   - Selects victim frame (if needed)
   - Writes dirty page to disk
   - Loads requested page
   - Updates page table
4. Restarts faulting instruction

**Performance Impact:**  
Typical page fault service time: 5-20ms (vs 100ns for RAM access)

**Diagram Suggestion:**  
Flowchart of page fault handling steps.

---

### **d. Translation Lookaside Buffer (TLB)**
**Purpose:** Cache frequent VPN→PFN translations

**Characteristics:**
- Typically 64-512 entries
- Hit ratio >98% in practice
- Parallel search (associative memory)

**TLB Miss Handling:**
1. Hardware walks page table (x86)
2. Software handler (MIPS)

**Example:**  
Intel Skylake: 1536-entry L2 TLB

**Diagram Suggestion:**  
CPU pipeline diagram showing TLB lookup.

---

## **4.4 Page Replacement Algorithms**

### **Evaluation Metrics**
- **Page Fault Rate:** Primary optimization target
- **Overhead:** Bookkeeping complexity
- **Implementation Cost:** Hardware support needed

---

### **a. Algorithm Details**

#### **1. FIFO (First-In First-Out)**
- Evicts oldest page
- **Advantage:** Simple implementation
- **Disadvantage:** Poor for cyclic access patterns
- **Belady's Anomaly:** Fault rate may increase with more frames

#### **2. Second Chance**
- FIFO with reference bit check
- **Implementation:**  
  ```c
  while (page->referenced) {
      page->referenced = 0;
      move_to_tail(page);
  }
  evict(page);
  ```

#### **3. LRU (Least Recently Used)**
- Evicts unused-for-longest page
- **Perfect but impractical:** Needs exact timestamp tracking
- **Approximations:**  
  - Clock algorithm  
  - Reference bits + aging registers

#### **4. Optimal (OPT)**
- Clairvoyant algorithm (future knowledge)
- **Academic use only:** Serves as benchmark

#### **5. LFU (Least Frequently Used)**
- Evicts least-often-used page
- **Problem:** Old heavily-used pages may stay

#### **6. Clock Variants**
- **Basic Clock:** Circular buffer with reference bit
- **WS-Clock:** Combins working set and clock

**Diagram Suggestion:**  
Animation showing each algorithm's page selection.

---

### **b. Locality of Reference**
**Principle:** Programs access memory in predictable patterns:
- **Temporal:** Recently used items likely reused
- **Spatial:** Nearby addresses likely accessed

**Impact on Replacement:**  
Good algorithms exploit locality (e.g., LRU)

**Example:**  
Loop processing array elements exhibits strong spatial locality.

---

## **4.5 Segmentation**

### **a. Need for Segmentation**
**Problems with Pure Paging:**
- No logical grouping of memory
- Difficult shared library implementation

**Segmentation Benefits:**
- Logical units (code, data, stack)
- Variable-sized segments
- Easier sharing/protection

**Example:**  
ELF binaries use segments:
- .text (code)
- .data (initialized variables)
- .bss (uninitialized data)

**Diagram Suggestion:**  
ELF segment viewer output.

---

### **b. Segmentation Drawbacks**
1. **External Fragmentation:**  
   - Variable sizes cause memory holes
   - Requires compaction

2. **Complex Allocation:**  
   - Best-fit often needed
   - Slower than paging

3. **Swapping Overhead:**  
   - Entire segments must be swapped

---

### **c. Segmentation with Paging (MULTICS)**
**Hybrid Approach:**
1. Segment table points to page tables
2. Each segment contains multiple pages
3. Two-level address translation:
   - Segment # → Page # → Offset

**Advantages:**
- Combines benefits of both
- Fine-grained protection possible

**Disadvantages:**
- Double lookup overhead
- Complex memory management

**Modern Equivalent:**  
x86-64 uses segmentation remnants:
- FS/GS registers for thread-local storage

**Diagram Suggestion:**  
MULTICS address translation flowchart.

---
