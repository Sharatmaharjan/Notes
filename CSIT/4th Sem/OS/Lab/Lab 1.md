**1. Write a program in C to implement producer-consumer problem using semaphore.**

- The producer-consumer problem is a classic synchronization problem where:
    - Producers generate data and put it into a buffer
    - Consumers take data from the buffer
    - We need to ensure producers don't add data to a full buffer and consumers don't remove data from an empty buffer

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

The Dining Philosophers problem is a classic synchronization problem that demonstrates challenges in avoiding deadlock when multiple processes compete for limited resources.

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

- **FCFS**
- **SJF**
- **Round Robin**

**For each of the algorithm finds out turnaround time and waiting time.**

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 10

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
} Process;

void fcfs(Process processes[], int n);
void sjf(Process processes[], int n);
void priority(Process processes[], int n);
void round_robin(Process processes[], int n, int quantum);
void print_results(Process processes[], int n);

int main() {
    Process processes[MAX_PROCESSES];
    int n, choice, quantum;

    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("\nProcess %d:\n", i+1);
        processes[i].pid = i+1;
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("\nScheduling Algorithms:\n");
    printf("1. FCFS\n2. SJF\n3. Priority\n4. Round Robin\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            fcfs(processes, n);
            break;
        case 2:
            sjf(processes, n);
            break;
        case 3:
            priority(processes, n);
            break;
        case 4:
            printf("Enter time quantum: ");
            scanf("%d", &quantum);
            round_robin(processes, n, quantum);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    print_results(processes, n);
    return 0;
}

void fcfs(Process processes[], int n) {
    // Sort by arrival time
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(processes[j].arrival_time > processes[j+1].arrival_time) {
                Process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }

    int current_time = 0;
    for(int i = 0; i < n; i++) {
        if(current_time < processes[i].arrival_time)
            current_time = processes[i].arrival_time;
        
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        current_time += processes[i].burst_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void sjf(Process processes[], int n) {
    int completed = 0, current_time = 0;

    while(completed < n) {
        int shortest = -1;
        int min_burst = 9999;

        for(int i = 0; i < n; i++) {
            if(processes[i].arrival_time <= current_time && 
               processes[i].remaining_time > 0 && 
               processes[i].remaining_time < min_burst) {
                min_burst = processes[i].remaining_time;
                shortest = i;
            }
        }

        if(shortest == -1) {
            current_time++;
            continue;
        }

        processes[shortest].remaining_time = 0;
        processes[shortest].turnaround_time = current_time + processes[shortest].burst_time - processes[shortest].arrival_time;
        processes[shortest].waiting_time = processes[shortest].turnaround_time - processes[shortest].burst_time;
        current_time += processes[shortest].burst_time;
        completed++;
    }
}

void priority(Process processes[], int n) {
    int completed = 0, current_time = 0;

    while(completed < n) {
        int highest_priority = -1;
        int min_priority = 9999;

        for(int i = 0; i < n; i++) {
            if(processes[i].arrival_time <= current_time && 
               processes[i].remaining_time > 0 && 
               processes[i].priority < min_priority) {
                min_priority = processes[i].priority;
                highest_priority = i;
            }
        }

        if(highest_priority == -1) {
            current_time++;
            continue;
        }

        processes[highest_priority].remaining_time = 0;
        processes[highest_priority].turnaround_time = current_time + processes[highest_priority].burst_time - processes[highest_priority].arrival_time;
        processes[highest_priority].waiting_time = processes[highest_priority].turnaround_time - processes[highest_priority].burst_time;
        current_time += processes[highest_priority].burst_time;
        completed++;
    }
}

void round_robin(Process processes[], int n, int quantum) {
    int remaining = n;
    int current_time = 0;

    while(remaining > 0) {
        for(int i = 0; i < n; i++) {
            if(processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                int exec_time = (processes[i].remaining_time > quantum) ? quantum : processes[i].remaining_time;
                
                processes[i].remaining_time -= exec_time;
                current_time += exec_time;

                if(processes[i].remaining_time == 0) {
                    remaining--;
                    processes[i].turnaround_time = current_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                }
            }
        }
    }
}

void print_results(Process processes[], int n) {
    float avg_wait = 0, avg_turnaround = 0;

    printf("\nPID\tArrival\tBurst\tPriority\tWaiting\tTurnaround\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n", 
               processes[i].pid,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].priority,
               processes[i].waiting_time,
               processes[i].turnaround_time);

        avg_wait += processes[i].waiting_time;
        avg_turnaround += processes[i].turnaround_time;
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_wait/n);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround/n);
}
```

---

**4. Write a program to simulate Banker's algorithm.**

The Banker's algorithm is a resource allocation and deadlock avoidance algorithm that tests for safety by simulating the allocation of predetermined maximum possible amounts of all resources.

```c
#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int available[MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int n, m; // n = number of processes, m = number of resources

void input_data() {
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("Enter available resources:\n");
    for(int i = 0; i < m; i++) {
        printf("Resource %d: ", i+1);
        scanf("%d", &available[i]);
    }

    printf("Enter maximum demand matrix:\n");
    for(int i = 0; i < n; i++) {
        printf("For process P%d:\n", i);
        for(int j = 0; j < m; j++) {
            printf("Resource %d: ", j+1);
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter allocation matrix:\n");
    for(int i = 0; i < n; i++) {
        printf("For process P%d:\n", i);
        for(int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

bool is_safe() {
    int work[m];
    bool finish[n];
    int safe_sequence[n];
    int count = 0;

    // Initialize work and finish
    for(int i = 0; i < m; i++)
        work[i] = available[i];
    for(int i = 0; i < n; i++)
        finish[i] = false;

    while(count < n) {
        bool found = false;
        for(int i = 0; i < n; i++) {
            if(!finish[i]) {
                bool can_allocate = true;
                for(int j = 0; j < m; j++) {
                    if(need[i][j] > work[j]) {
                        can_allocate = false;
                        break;
                    }
                }

                if(can_allocate) {
                    for(int j = 0; j < m; j++)
                        work[j] += allocation[i][j];
                    safe_sequence[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if(!found) {
            printf("System is not in safe state\n");
            return false;
        }
    }

    printf("System is in safe state\nSafe sequence: ");
    for(int i = 0; i < n; i++)
        printf("P%d ", safe_sequence[i]);
    printf("\n");
    return true;
}

void request_resources() {
    int process_num;
    printf("Enter process number (0-%d): ", n-1);
    scanf("%d", &process_num);

    int request[m];
    printf("Enter request for process P%d:\n", process_num);
    for(int i = 0; i < m; i++) {
        printf("Resource %d: ", i+1);
        scanf("%d", &request[i]);
    }

    // Check if request <= need
    for(int i = 0; i < m; i++) {
        if(request[i] > need[process_num][i]) {
            printf("Error: Request exceeds maximum claim\n");
            return;
        }
    }

    // Check if request <= available
    for(int i = 0; i < m; i++) {
        if(request[i] > available[i]) {
            printf("Process must wait, resources not available\n");
            return;
        }
    }

    // Try to allocate resources temporarily
    for(int i = 0; i < m; i++) {
        available[i] -= request[i];
        allocation[process_num][i] += request[i];
        need[process_num][i] -= request[i];
    }

    // Check if system is still in safe state
    if(is_safe()) {
        printf("Request granted\n");
    } else {
        // Roll back changes
        printf("Request denied - would lead to unsafe state\n");
        for(int i = 0; i < m; i++) {
            available[i] += request[i];
            allocation[process_num][i] -= request[i];
            need[process_num][i] += request[i];
        }
    }
}

int main() {
    int choice;
    input_data();

    while(1) {
        printf("\nBanker's Algorithm Menu:\n");
        printf("1. Check system safety\n");
        printf("2. Request resources\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                is_safe();
                break;
            case 2:
                request_resources();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
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
