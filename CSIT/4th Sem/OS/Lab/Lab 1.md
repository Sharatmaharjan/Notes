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


### 1. Basic Concept
Imagine a factory with:
- A producer making items and putting them on a conveyor belt (buffer)
- A consumer taking items off the conveyor belt
- The belt can only hold 5 items at once (BUFFER_SIZE)

### 2. Key Components

**a. The Buffer**
```c
int buffer[BUFFER_SIZE];  // Our "conveyor belt" with 5 slots
int in = 0, out = 0;      // Pointers to track where to add/remove items
```

**b. The Traffic Lights (Semaphores)**
```c
sem_t mutex, empty, full;
```
- `mutex`: Like a bathroom key - only one thread can hold it at a time
- `empty`: Counts empty slots ("Hey producer, there are X free spaces!")
- `full`: Counts full slots ("Hey consumer, there are X items ready!")

### 3. Producer's Job
```c
void *producer(void *arg) {
    int item;
    for (int i = 0; i < 10; i++) {
        // 1. Make a new item (random number)
        item = rand() % 100;
        
        // 2. Wait for empty space (stop if belt is full)
        sem_wait(&empty);
        
        // 3. Get exclusive access (take the bathroom key)
        sem_wait(&mutex);
        
        // 4. Put item on belt
        buffer[in] = item;
        printf("Producer produced %d\n", item);
        in = (in + 1) % BUFFER_SIZE;  // Wrap around if needed
        
        // 5. Release access (return the key)
        sem_post(&mutex);
        
        // 6. Tell consumer "There's one more item!"
        sem_post(&full);
        
        // 7. Take a quick break
        sleep(rand() % 2);
    }
    return NULL;
}
```

### 4. Consumer's Job
```c
void *consumer(void *arg) {
    int item;
    for (int i = 0; i < 10; i++) {
        // 1. Wait for items (stop if belt is empty)
        sem_wait(&full);
        
        // 2. Get exclusive access
        sem_wait(&mutex);
        
        // 3. Take item from belt
        item = buffer[out];
        printf("Consumer consumed %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        
        // 4. Release access
        sem_post(&mutex);
        
        // 5. Tell producer "There's one more empty space!"
        sem_post(&empty);
        
        // 6. Take a quick break
        sleep(rand() % 2);
    }
    return NULL;
}
```

### 5. Main Function
```c
int main() {
    // Initialize our traffic lights:
    sem_init(&mutex, 0, 1);       // Mutex starts at 1 (available)
    sem_init(&empty, 0, BUFFER_SIZE); // 5 empty slots initially
    sem_init(&full, 0, 0);        // 0 full slots initially
    
    // Hire our workers (create threads)
    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);
    
    // Wait for them to finish their shifts
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);
    
    // Remove the traffic lights
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    
    return 0;
}
```

### 6. Visualizing the Flow

```
Producer:                     Consumer:
1. Check for empty space      1. Check for full slots
2. Get permission             2. Get permission
3. Add item to buffer         3. Remove item from buffer
4. Signal "item added"        4. Signal "space freed"
5. Sleep a bit                5. Sleep a bit
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

