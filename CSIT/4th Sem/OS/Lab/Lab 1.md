**1. Write a program in C to implement producer-consumer problem using semaphore.**


```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t mutex, empty, full;

void *producer(void *arg) {
    int item;
    for (int i = 0; i < 10; i++) {
        item = rand() % 100;  // Produce random item
        
        sem_wait(&empty);     // Wait if buffer is full
        sem_wait(&mutex);     // Enter critical section
        
        buffer[in] = item;
        printf("Producer produced %d\n", item);
        in = (in + 1) % BUFFER_SIZE;
        
        sem_post(&mutex);     // Leave critical section
        sem_post(&full);      // Signal that buffer has one more item
        
        sleep(rand() % 2);   // Simulate random production time
    }
    return NULL;
}

void *consumer(void *arg) {
    int item;
    for (int i = 0; i < 10; i++) {
        sem_wait(&full);      // Wait if buffer is empty
        sem_wait(&mutex);     // Enter critical section
        
        item = buffer[out];
        printf("Consumer consumed %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        
        sem_post(&mutex);     // Leave critical section
        sem_post(&empty);     // Signal that buffer has one more empty slot
        
        sleep(rand() % 2);    // Simulate random consumption time
    }
    return NULL;
}

int main() {
    pthread_t prod_thread, cons_thread;
    
    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    
    // Create producer and consumer threads
    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);
    
    // Wait for threads to finish
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);
    
    // Destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    
    return 0;
}
```

---

**2. Write a program to implement the concept of the dining philosopher problem.**

```c
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

sem_t mutex;
sem_t chopsticks[NUM_PHILOSOPHERS];
int state[NUM_PHILOSOPHERS];

void *philosopher(void *num);
void take_chopsticks(int);
void put_chopsticks(int);
void test(int);

int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int philosopher_numbers[NUM_PHILOSOPHERS];

    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_init(&chopsticks[i], 0, 1);
        philosopher_numbers[i] = i;
    }

    // Create philosopher threads
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_create(&philosophers[i], NULL, philosopher, &philosopher_numbers[i]);
    }

    // Wait for threads to finish (though they run indefinitely)
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Clean up semaphores
    sem_destroy(&mutex);
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_destroy(&chopsticks[i]);
    }

    return 0;
}

void *philosopher(void *num) {
    int *philosopher_num = (int *)num;
    int i = *philosopher_num;

    while (1) {
        printf("Philosopher %d is thinking\n", i);
        sleep(1); // Thinking time

        take_chopsticks(i);

        printf("Philosopher %d is eating\n", i);
        sleep(1); // Eating time

        put_chopsticks(i);
    }
}

void take_chopsticks(int i) {
    sem_wait(&mutex);
    state[i] = HUNGRY;
    printf("Philosopher %d is hungry\n", i);
    test(i);
    sem_post(&mutex);
    sem_wait(&chopsticks[i]);
}

void test(int i) {
    if (state[i] == HUNGRY && 
        state[(i + NUM_PHILOSOPHERS - 1) % NUM_PHILOSOPHERS] != EATING && 
        state[(i + 1) % NUM_PHILOSOPHERS] != EATING) {
        
        state[i] = EATING;
        sem_post(&chopsticks[i]);
    }
}

void put_chopsticks(int i) {
    sem_wait(&mutex);
    state[i] = THINKING;
    printf("Philosopher %d has finished eating\n", i);
    
    // Notify neighbors
    test((i + NUM_PHILOSOPHERS - 1) % NUM_PHILOSOPHERS);
    test((i + 1) % NUM_PHILOSOPHERS);
    
    sem_post(&mutex);
}
```

---

**3. Write a program to simulate the following scheduling algorithm.**

**FCFS**
**SJF**
**Round Robin**

**For each of the algorithm finds out turnaround time and waiting time.**

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 2 // For Round Robin

// Structure to represent a process
typedef struct {
    int pid;          // Process ID
    int arrival_time; // Arrival time
    int burst_time;   // Burst time
    int remaining_time; // For Round Robin
    int completion_time;
    int turnaround_time;
    int waiting_time;
} Process;

// Function to initialize processes
void initialize_processes(Process p[], int n) {
    // Sample processes: {PID, Arrival Time, Burst Time}
    int sample_data[][3] = {{1, 0, 5}, {2, 1, 3}, {3, 2, 8}, {4, 3, 6}};
    for (int i = 0; i < n; i++) {
        p[i].pid = sample_data[i][0];
        p[i].arrival_time = sample_data[i][1];
        p[i].burst_time = sample_data[i][2];
        p[i].remaining_time = p[i].burst_time;
        p[i].completion_time = 0;
        p[i].turnaround_time = 0;
        p[i].waiting_time = 0;
    }
}

// FCFS Scheduling
void fcfs(Process p[], int n) {
    printf("\nFCFS Scheduling:\n");
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < p[i].arrival_time) {
            current_time = p[i].arrival_time;
        }
        p[i].completion_time = current_time + p[i].burst_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
        current_time = p[i].completion_time;
    }
}

// SJF Scheduling (Non-preemptive)
void sjf(Process p[], int n) {
    printf("\nSJF Scheduling:\n");
    Process temp[MAX_PROCESSES];
    for (int i = 0; i < n; i++) temp[i] = p[i];
    
    int current_time = 0, completed = 0;
    while (completed < n) {
        int min_burst = 9999, min_index = -1;
        for (int i = 0; i < n; i++) {
            if (temp[i].arrival_time <= current_time && temp[i].completion_time == 0) {
                if (temp[i].burst_time < min_burst) {
                    min_burst = temp[i].burst_time;
                    min_index = i;
                }
            }
        }
        if (min_index == -1) {
            current_time++;
            continue;
        }
        temp[min_index].completion_time = current_time + temp[min_index].burst_time;
        temp[min_index].turnaround_time = temp[min_index].completion_time - temp[min_index].arrival_time;
        temp[min_index].waiting_time = temp[min_index].turnaround_time - temp[min_index].burst_time;
        current_time = temp[min_index].completion_time;
        completed++;
        p[min_index] = temp[min_index]; // Update original array
    }
}

// Round Robin Scheduling
void round_robin(Process p[], int n, int quantum) {
    printf("\nRound Robin Scheduling (Quantum = %d):\n", quantum);
    Process temp[MAX_PROCESSES];
    for (int i = 0; i < n; i++) temp[i] = p[i];
    
    int current_time = 0, completed = 0;
    while (completed < n) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (temp[i].remaining_time > 0) {
                done = 0;
                if (temp[i].arrival_time <= current_time) {
                    int time_slice = (temp[i].remaining_time < quantum) ? temp[i].remaining_time : quantum;
                    temp[i].remaining_time -= time_slice;
                    current_time += time_slice;
                    if (temp[i].remaining_time == 0) {
                        temp[i].completion_time = current_time;
                        temp[i].turnaround_time = temp[i].completion_time - temp[i].arrival_time;
                        temp[i].waiting_time = temp[i].turnaround_time - temp[i].burst_time;
                        completed++;
                        p[i] = temp[i]; // Update original array
                    }
                }
            }
        }
        if (done) current_time++;
    }
}

// Function to print results
void print_results(Process p[], int n, const char* algo) {
    printf("\nResults for %s:\n", algo);
    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    float avg_turnaround = 0, avg_waiting = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n",
               p[i].pid, p[i].arrival_time, p[i].burst_time,
               p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
        avg_turnaround += p[i].turnaround_time;
        avg_waiting += p[i].waiting_time;
    }
    printf("Average Turnaround Time: %.2f\n", avg_turnaround / n);
    printf("Average Waiting Time: %.2f\n", avg_waiting / n);
}

int main() {
    int n = 4; // Number of processes
    Process processes[MAX_PROCESSES];
    
    // FCFS
    initialize_processes(processes, n);
    fcfs(processes, n);
    print_results(processes, n, "FCFS");
    
    // SJF
    initialize_processes(processes, n);
    sjf(processes, n);
    print_results(processes, n, "SJF");
    
    // Round Robin
    initialize_processes(processes, n);
    round_robin(processes, n, TIME_QUANTUM);
    print_results(processes, n, "Round Robin");
    
    return 0;
}
```

---

**4. Write a program to simulate Banker's algorithm.**

```c
#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

// Function to check if the system is in a safe state
bool is_safe_state(int processes[], int n, int resources[], int m,
                   int available[], int max[][MAX_RESOURCES], int allocation[][MAX_RESOURCES]) {
    int work[MAX_RESOURCES];
    int finish[MAX_PROCESSES] = {0};
    int safe_sequence[MAX_PROCESSES];
    int count = 0;

    // Initialize work as available
    for (int i = 0; i < m; i++) {
        work[i] = available[i];
    }

    // Find a safe sequence
    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) {
                bool can_allocate = true;
                for (int j = 0; j < m; j++) {
                    int need = max[i][j] - allocation[i][j];
                    if (need > work[j]) {
                        can_allocate = false;
                        break;
                    }
                }
                if (can_allocate) {
                    for (int j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }
                    safe_sequence[count++] = i;
                    finish[i] = 1;
                    found = true;
                }
            }
        }
        if (!found) {
            return false; // No safe sequence found
        }
    }

    // Print safe sequence
    printf("System is in a safe state.\nSafe Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("P%d", safe_sequence[i]);
        if (i < n - 1) printf(" -> ");
    }
    printf("\n");
    return true;
}

// Function to initialize sample data and run Banker's Algorithm
int main() {
    int n = MAX_PROCESSES; // Number of processes
    int m = MAX_RESOURCES; // Number of resource types

    // Sample data
    int allocation[MAX_PROCESSES][MAX_RESOURCES] = {
        {0, 1, 0}, // P0
        {2, 0, 0}, // P1
        {3, 0, 2}, // P2
        {2, 1, 1}, // P3
        {0, 0, 2}  // P4
    };

    int max[MAX_PROCESSES][MAX_RESOURCES] = {
        {7, 5, 3}, // P0
        {3, 2, 2}, // P1
        {9, 0, 2}, // P2
        {2, 2, 2}, // P3
        {4, 3, 3}  // P4
    };

    int available[MAX_RESOURCES] = {3, 3, 2}; // Available resources
    int processes[MAX_PROCESSES] = {0, 1, 2, 3, 4};

    // Calculate need matrix
    int need[MAX_PROCESSES][MAX_RESOURCES];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Print input data
    printf("Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < m; j++) {
            printf("%d ", allocation[i][j]);
        }
        printf("\n");
    }

    printf("\nMax Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < m; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }

    printf("\nNeed Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    printf("\nAvailable Resources: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", available[i]);
    }
    printf("\n");

    // Check for safe state
    if (!is_safe_state(processes, n, available, m, available, max, allocation)) {
        printf("System is in an unsafe state.\n");
    }

    return 0;
}
```

---

**5. Simulate paging technique of memory management.**

```c
#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 4096 // Page size in bytes (4KB)
#define NUM_PAGES 8    // Number of pages in logical memory
#define NUM_FRAMES 4   // Number of frames in physical memory
#define MAX_ADDRESSES 10 // Number of logical addresses to simulate

// Structure to represent the page table entry
typedef struct {
    int frame_number; // Frame number in physical memory (-1 if not mapped)
    int valid;        // Valid bit (1 if page is in memory, 0 otherwise)
} PageTableEntry;

// Function to initialize page table
void initialize_page_table(PageTableEntry page_table[], int n) {
    // Sample mapping: some pages are mapped to frames, others are not
    int sample_mapping[NUM_PAGES] = {2, 0, -1, 3, -1, 1, -1, -1}; // -1 indicates page fault
    for (int i = 0; i < n; i++) {
        page_table[i].frame_number = sample_mapping[i];
        page_table[i].valid = (sample_mapping[i] != -1) ? 1 : 0;
    }
}

// Function to translate logical address to physical address
void translate_address(int logical_address, PageTableEntry page_table[], int page_size) {
    int page_number = logical_address / page_size;
    int offset = logical_address % page_size;

    if (page_number >= NUM_PAGES) {
        printf("Logical Address %d: Invalid page number %d (exceeds max pages %d)\n",
               logical_address, page_number, NUM_PAGES);
        return;
    }

    if (page_table[page_number].valid == 0) {
        printf("Logical Address %d: Page Fault (Page %d not in memory)\n",
               logical_address, page_number);
        return;
    }

    int frame_number = page_table[page_number].frame_number;
    int physical_address = (frame_number * page_size) + offset;

    printf("Logical Address %d: Page %d, Offset %d -> Physical Address %d (Frame %d, Offset %d)\n",
           logical_address, page_number, offset, physical_address, frame_number, offset);
}

// Function to simulate paging
void simulate_paging() {
    PageTableEntry page_table[NUM_PAGES];
    initialize_page_table(page_table, NUM_PAGES);

    // Print page table
    printf("Page Table:\n");
    printf("Page\tFrame\tValid\n");
    for (int i = 0; i < NUM_PAGES; i++) {
        printf("%d\t%d\t%d\n", i, page_table[i].frame_number, page_table[i].valid);
    }

    // Sample logical addresses to translate
    int logical_addresses[MAX_ADDRESSES] = {100, 5000, 8192, 12000, 16384, 20000, 25000, 32768, 40000, 45000};
    
    printf("\nAddress Translation:\n");
    for (int i = 0; i < MAX_ADDRESSES; i++) {
        translate_address(logical_addresses[i], page_table, PAGE_SIZE);
    }
}

int main() {
    printf("Paging Simulation (Page Size = %d bytes, %d Pages, %d Frames)\n\n",
           PAGE_SIZE, NUM_PAGES, NUM_FRAMES);
    simulate_paging();
    return 0;
}
```
