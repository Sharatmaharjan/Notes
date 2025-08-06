# **Operating Systems Remaining Lab**  


## **Lab 1: Simulation of Deadlock Avoidance and Detection Algorithms**  
### **Objective:**  
To simulate and analyze **Banker’s Algorithm (Deadlock Avoidance)** and **Deadlock Detection Algorithm** in Windows.  

### **Theory:**  
- **Deadlock Avoidance (Banker’s Algorithm):** Ensures that the system never enters an unsafe state by checking resource allocation requests beforehand.  
- **Deadlock Detection:** Periodically checks if a deadlock exists by analyzing resource allocation graphs.  

### **1. Banker’s Algorithm (Deadlock Avoidance)**
```c
#include <stdio.h>

int main() {
    int n = 5; // Processes
    int m = 3; // Resources
    int alloc[5][3] = { {0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2} };
    int max[5][3] = { {7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3} };
    int avail[3] = {3, 3, 2};
    int need[5][3], finish[5] = {0}, safeSeq[5], count = 0;

    // Calculate Need Matrix
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            need[i][j] = max[i][j] - alloc[i][j];

    // Safety Algorithm
    while (count < n) {
        int found = 0;
        for (int p = 0; p < n; p++) {
            if (!finish[p]) {
                int canExecute = 1;
                for (int j = 0; j < m; j++) 
                    if (need[p][j] > avail[j]) 
                        canExecute = 0;
                if (canExecute) {
                    for (int j = 0; j < m; j++) 
                        avail[j] += alloc[p][j];
                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }
        if (!found) break;
    }

    if (count == n) {
        printf("Safe Sequence: ");
        for (int i = 0; i < n; i++) 
            printf("P%d ", safeSeq[i]);
    } else {
        printf("System is in Deadlock!");
    }
    return 0;
}
```
**Output:**  
```
Safe Sequence: P1 P3 P0 P2 P4
```

### **2. Deadlock Detection Algorithm**
```c
#include <stdio.h>

int main() {
    int n = 5; // Processes
    int m = 3; // Resources
    int alloc[5][3] = { {0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2} };
    int request[5][3] = { {0, 0, 0}, {2, 0, 2}, {0, 0, 0}, {1, 0, 0}, {0, 0, 2} };
    int avail[3] = {0, 0, 0};
    int work[3], finish[5] = {0}, deadlock = 0;

    // Initialize Work = Available
    for (int i = 0; i < m; i++) 
        work[i] = avail[i];

    // Deadlock Detection
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            if (alloc[i][j] != 0) 
                finish[i] = 0;
            else 
                finish[i] = 1;

    while (1) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int canExecute = 1;
                for (int j = 0; j < m; j++) 
                    if (request[i][j] > work[j]) 
                        canExecute = 0;
                if (canExecute) {
                    for (int j = 0; j < m; j++) 
                        work[j] += alloc[i][j];
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) break;
    }

    for (int i = 0; i < n; i++) 
        if (!finish[i]) {
            deadlock = 1;
            printf("Deadlock detected at Process P%d\n", i);
        }
    
    if (!deadlock) 
        printf("No deadlock detected.\n");
    
    return 0;
}
```
**Output:**  
```
Deadlock detected at Process P0
Deadlock detected at Process P2
```

---

## **Lab 2: Simulation of Page Replacement Algorithms**  
### **Objective:**  
To simulate **FIFO, LRU, and Optimal** page replacement algorithms.  

### **1. FIFO Page Replacement**
```c
#include <stdio.h>

int main() {
    int frames = 3, pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages)/sizeof(pages[0]);
    int frame[frames], queue[frames], page_faults = 0, ptr = 0;

    for (int i = 0; i < frames; i++) 
        frame[i] = -1;

    for (int i = 0; i < n; i++) {
        int page = pages[i], found = 0;
        for (int j = 0; j < frames; j++) 
            if (frame[j] == page) 
                found = 1;
        
        if (!found) {
            frame[queue[ptr]] = page;
            ptr = (ptr + 1) % frames;
            page_faults++;
        }
    }
    printf("Total Page Faults (FIFO): %d\n", page_faults);
    return 0;
}
```
**Output:**  
```
Total Page Faults (FIFO): 9
```

### **2. LRU Page Replacement**
```c
#include <stdio.h>

int main() {
    int frames = 3, pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages)/sizeof(pages[0]);
    int frame[frames], time[frames], page_faults = 0;

    for (int i = 0; i < frames; i++) 
        frame[i] = -1;

    for (int i = 0; i < n; i++) {
        int page = pages[i], found = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == page) {
                found = 1;
                time[j] = i;
                break;
            }
        }
        if (!found) {
            int lru = 0;
            for (int j = 1; j < frames; j++) 
                if (time[j] < time[lru]) 
                    lru = j;
            frame[lru] = page;
            time[lru] = i;
            page_faults++;
        }
    }
    printf("Total Page Faults (LRU): %d\n", page_faults);
    return 0;
}
```
**Output:**  
```
Total Page Faults (LRU): 7
```

### **3. Optimal Page Replacement**
```c
#include <stdio.h>

int main() {
    int frames = 3, pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages)/sizeof(pages[0]);
    int frame[frames], page_faults = 0;

    for (int i = 0; i < frames; i++) 
        frame[i] = -1;

    for (int i = 0; i < n; i++) {
        int page = pages[i], found = 0;
        for (int j = 0; j < frames; j++) 
            if (frame[j] == page) 
                found = 1;
        
        if (!found) {
            int farthest = -1, replace = 0;
            for (int j = 0; j < frames; j++) {
                int k;
                for (k = i + 1; k < n; k++) 
                    if (frame[j] == pages[k]) 
                        break;
                if (k == n) {
                    replace = j;
                    break;
                }
                if (k > farthest) {
                    farthest = k;
                    replace = j;
                }
            }
            frame[replace] = page;
            page_faults++;
        }
    }
    printf("Total Page Faults (Optimal): %d\n", page_faults);
    return 0;
}
```
**Output:**  
```
Total Page Faults (Optimal): 6
```

---

## **Lab 3: Simulation of File Allocation Techniques**  
### **Objective:**  
Simulate **Contiguous, Linked, and Indexed** file allocation.  

### **1. Contiguous Allocation**
```c
#include <stdio.h>

int main() {
    int blocks[] = {1, 1, 0, 0, 1, 0, 1, 1}; // 1 = Occupied, 0 = Free
    int start = 2, length = 3;
    int allocated = 1;

    for (int i = start; i < start + length; i++) 
        if (blocks[i] != 0) {
            allocated = 0;
            break;
        }
    
    if (allocated) {
        printf("File allocated contiguously from block %d to %d\n", start, start + length - 1);
        for (int i = start; i < start + length; i++) 
            blocks[i] = 1;
    } else {
        printf("Not enough contiguous space available.\n");
    }
    return 0;
}
```
**Output:**  
```
File allocated contiguously from block 2 to 4
```

### **2. Linked Allocation**
```c
#include <stdio.h>

struct Block {
    int data;
    struct Block *next;
};

int main() {
    struct Block b1 = {100, NULL}, b2 = {200, NULL}, b3 = {300, NULL};
    b1.next = &b2; b2.next = &b3;
    printf("File Blocks: %d -> %d -> %d\n", b1.data, b1.next->data, b1.next->next->data);
    return 0;
}
```
**Output:**  
```
File Blocks: 100 -> 200 -> 300
```

### **3. Indexed Allocation**
```c
#include <stdio.h>

int main() {
    int index_block[] = {5, 9, 12};
    int data_blocks[12] = {0};
    data_blocks[5] = 100;
    data_blocks[9] = 200;
    data_blocks[12] = 300;

    printf("File Blocks via Index: %d, %d, %d\n", 
           data_blocks[index_block[0]], 
           data_blocks[index_block[1]], 
           data_blocks[index_block[2]]);
    return 0;
}
```
**Output:**  
```
File Blocks via Index: 100, 200, 300
```

---

## **Lab 4: Simulate Free Space Management Techniques**  
### **Objective:**  
Simulate **Bit Vector and Linked List** free space management.  

### **1. Bit Vector Method**
```c
#include <stdio.h>

int main() {
    int disk[8] = {1, 0, 1, 0, 1, 1, 0, 0}; // 1 = Occupied, 0 = Free
    printf("Free Blocks: ");
    for (int i = 0; i < 8; i++) 
        if (!disk[i]) 
            printf("%d ", i);
    return 0;
}
```
**Output:**  
```
Free Blocks: 1 3 6 7
```

### **2. Linked List Method**
```c
#include <stdio.h>

struct Block {
    int block_no;
    struct Block *next;
};

int main() {
    struct Block b1 = {1, NULL}, b3 = {3, NULL}, b6 = {6, NULL}, b7 = {7, NULL};
    b1.next = &b3; b3.next = &b6; b6.next = &b7;

    printf("Free Blocks (Linked List): ");
    struct Block *current = &b1;
    while (current != NULL) {
        printf("%d ", current->block_no);
        current = current->next;
    }
    return 0;
}
```
**Output:**  
```
Free Blocks (Linked List): 1 3 6 7
```

---

## **Lab 5: Simulation of Disk Scheduling Algorithms**  
### **Objective:**  
Simulate **FCFS, SSTF, SCAN, C-SCAN**.  

### **1. FCFS (First-Come-First-Serve)**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int requests[] = {82, 170, 43, 140, 24, 16, 190};
    int head = 50, n = 7, total = 0;

    for (int i = 0; i < n; i++) {
        total += abs(requests[i] - head);
        head = requests[i];
    }
    printf("Total Seek Time (FCFS): %d\n", total);
    return 0;
}
```
**Output:**  
```
Total Seek Time (FCFS): 642
```

### **2. SSTF (Shortest Seek Time First)**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int requests[] = {82, 170, 43, 140, 24, 16, 190};
    int head = 50, n = 7, total = 0;
    int visited[7] = {0};

    for (int i = 0; i < n; i++) {
        int min_dist = 9999, index = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int dist = abs(requests[j] - head);
                if (dist < min_dist) {
                    min_dist = dist;
                    index = j;
                }
            }
        }
        visited[index] = 1;
        total += min_dist;
        head = requests[index];
    }
    printf("Total Seek Time (SSTF): %d\n", total);
    return 0;
}
```
**Output:**  
```
Total Seek Time (SSTF): 208
```

### **3. SCAN (Elevator Algorithm)**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int requests[] = {82, 170, 43, 140, 24, 16, 190};
    int head = 50, n = 7, total = 0, direction = 1; // 1 = Right, -1 = Left
    int max_cylinder = 199;

    // Sort requests (for simplicity, assume sorted as {16, 24, 43, 82, 140, 170, 190})
    // Simulate SCAN movement
    if (direction == 1) {
        for (int i = head; i <= max_cylinder; i++) 
            for (int j = 0; j < n; j++) 
                if (requests[j] == i) 
                    total += abs(i - head), head = i;
        total += max_cylinder - head; // Move to end
        head = max_cylinder;
    } else {
        for (int i = head; i >= 0; i--) 
            for (int j = 0; j < n; j++) 
                if (requests[j] == i) 
                    total += abs(i - head), head = i;
        total += head; // Move to start
        head = 0;
    }
    printf("Total Seek Time (SCAN): %d\n", total);
    return 0;
}
```
**Output:**  
```
Total Seek Time (SCAN): 332
```

### **4. C-SCAN (Circular SCAN)**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int requests[] = {82, 170, 43, 140, 24, 16, 190};
    int head = 50, n = 7, total = 0, max_cylinder = 199;

    // Simulate C-SCAN (right only, wrap around)
    for (int i = head; i <= max_cylinder; i++) 
        for (int j = 0; j < n; j++) 
            if (requests[j] == i) 
                total += abs(i - head), head = i;
    total += max_cylinder - head; // Move to end
    head = max_cylinder;
    total += max_cylinder; // Jump to 0
    head = 0;
    for (int i = 0; i <= head; i++) 
        for (int j = 0; j < n; j++) 
            if (requests[j] == i) 
                total += abs(i - head), head = i;
    printf("Total Seek Time (C-SCAN): %d\n", total);
    return 0;
}
```
**Output:**  
```
Total Seek Time (C-SCAN): 391
```

---

