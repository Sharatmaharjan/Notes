# **Unit 2: Process Management**

## 2.1 Process Fundamentals

### Process vs Program
| Aspect        | Program                      | Process                          |
|---------------|-----------------------------|----------------------------------|
| Nature        | Static (executable file)    | Dynamic (execution instance)     |
| State         | Passive (on disk)           | Active (in memory)               |
| Resources     | No allocated resources      | Has CPU, memory, I/O allocation  |
| Lifetime      | Permanent (stored)          | Temporary (execution duration)   |

### Multiprogramming
- Definition: Running multiple processes simultaneously by switching CPU between them
- Benefits:
  - Increased CPU utilization
  - Better system throughput
  - Efficient resource sharing

### Process Model
- Components:
  1. Text section (program code)
  2. Data section (global variables)
  3. Heap (dynamic memory)
  4. Stack (function calls, local variables)
  5. Process Control Block (PCB)

### Process States
1. New: Being created
2. Ready: Waiting for CPU allocation
3. Running: Executing on CPU
4. Waiting/Blocked: Waiting for I/O or event
5. Terminated: Finished execution

State Transition Diagram:
New → Ready ↔ Running → Waiting → Ready → Terminated

### Process Control Block (PCB)
- OS data structure containing:
  - Process ID (PID)
  - Process state
  - Program Counter
  - CPU registers
  - Memory management info
  - Accounting info
  - I/O status info
  - Scheduling parameters

## 2.2 Threads

### Threads vs Processes
| Feature       | Process                     | Thread                      |
|--------------|----------------------------|-----------------------------|
| Creation     | Heavyweight (slow)         | Lightweight (fast)          |
| Resources    | Separate allocation        | Shares process resources    |
| Communication| IPC required               | Direct shared memory access |
| Overhead     | High context switch cost   | Low context switch cost     |
| Isolation    | Independent address space  | Shared address space        |

### Thread Types

1. User-Level Threads (ULT)
   - Managed by user-level library
   - OS unaware of threads
   - Pros:
     - Fast creation/management
     - Custom scheduling
   - Cons:
     - Blocking system calls affect all threads
     - No true parallel execution on multicore

2. Kernel-Level Threads (KLT)
   - Managed directly by OS
   - Pros:
     - True parallel execution
     - Blocking calls don't block entire process
   - Cons:
     - Slower operations (require system calls)
     - Less flexible scheduling

### Thread Models
1. Many-to-One (Multiple ULT → Single KLT)
   - Old model, limited parallelism
2. One-to-One (Each ULT → KLT)
   - Better parallelism, used in Linux/Windows
3. Many-to-Many (Multiple ULT → Multiple KLT)
   - Best balance, used in Solaris

