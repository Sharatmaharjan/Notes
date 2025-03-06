## Unit 7: Threads [3 Hrs.]

Threads in Java allow concurrent execution of tasks, enabling efficient utilization of CPU resources. This unit covers the creation, instantiation, and starting of threads, as well as advanced concepts like thread priorities, synchronization, inter-thread communication, and deadlock.

---

### 1. **Create/Instantiate/Start New Threads**

There are two ways to create and start threads in Java:

#### a) **Extending `java.lang.Thread`**
- Create a class that extends the `Thread` class.
- Override the `run()` method to define the task the thread will perform.
- Create an instance of the class and call the `start()` method to begin execution.

**Lab 1: Creating, instantiating and starting new threads extending `java.lang.Thread` class**
```java
class MyThread extends Thread {
    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(Thread.currentThread().getName() + " - Count: " + i);
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                System.err.println("Thread interrupted: " + e.getMessage());
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        MyThread thread1 = new MyThread();
        MyThread thread2 = new MyThread();

        thread1.start(); // Starts the first thread -> calls parent(Thread) method
        thread2.start(); // Starts the second thread
        //thread1.interrupt();  -> to simulate interrupt
    }
}
```

**Explanation:**
- The `MyThread` class extends `Thread` and overrides the `run()` method.
- Two threads (`thread1` and `thread2`) are created and started using the `start()` method.
- The `run()` method is executed concurrently by both threads.

**Sample Output:**
```
Thread-0 - Count: 1
Thread-1 - Count: 1
Thread-0 - Count: 2
Thread-1 - Count: 2
Thread-0 - Count: 3
Thread-1 - Count: 3
Thread-0 - Count: 4
Thread-1 - Count: 4
Thread-0 - Count: 5
Thread-1 - Count: 5
```

---

#### b) **Implementing `java.lang.Runnable` Interface**
- Create a class that implements the `Runnable` interface.
- Override the `run()` method to define the task.
- Pass an instance of the class to a `Thread` object and call `start()`.

**Lab 2: Creating, instantiating and starting new threads implementing `java.lang.Runnable` interface**
```java
class MyRunnable implements Runnable {
    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(Thread.currentThread().getName() + " - Count: " + i);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        MyRunnable myRunnable = new MyRunnable();
        Thread thread1 = new Thread(myRunnable);
        Thread thread2 = new Thread(myRunnable);

        thread1.start(); // Starts the first thread
        thread2.start(); // Starts the second thread
    }
}
```

**Explanation:**
- The `MyRunnable` class implements the `Runnable` interface and overrides the `run()` method.
- Two threads (`thread1` and `thread2`) are created using the `Thread` constructor and started using the `start()` method.
- The `run()` method is executed concurrently by both threads.

**Sample Output:**
```
Thread-0 - Count: 1
Thread-1 - Count: 1
Thread-0 - Count: 2
Thread-1 - Count: 2
Thread-0 - Count: 3
Thread-1 - Count: 3
Thread-0 - Count: 4
Thread-1 - Count: 4
Thread-0 - Count: 5
Thread-1 - Count: 5
```

---

#### **Difference Between Extending `Thread` and Implementing `Runnable`**
| Feature                  | Extending `Thread`                     | Implementing `Runnable`               |
|--------------------------|---------------------------------------|---------------------------------------|
| **Inheritance**          | Uses up the single inheritance option. | Does not use inheritance; allows extending other classes. |
| **Reusability**          | Less reusable.                        | More reusable; same `Runnable` instance can be passed to multiple threads. |
| **Thread Creation**      | Directly creates a `Thread` object.   | Requires a `Thread` object to wrap the `Runnable`. |
| **Best Use Case**        | When you need to override `Thread` methods. | When you want to separate thread logic from task logic. |

---

### 2. **Thread Execution**
- When a thread is started using the `start()` method, the JVM calls the `run()` method.
- Threads run concurrently, meaning multiple threads can execute simultaneously (depending on the number of CPU cores).

**Lab 3: Thread Execution**
```java
class Task implements Runnable {
    @Override
    public void run() {
        // This code will be executed when the thread starts
        // It prints the name of the currently executing thread
        System.out.println(Thread.currentThread().getName() + " is running.");
    }
}

public class Main {
    public static void main(String[] args) {
        Task task = new Task();

        Thread thread1 = new Thread(task, "Thread-1");// The second argument in the Thread constructor sets the thread's name
        Thread thread2 = new Thread(task, "Thread-2");

        // Start the first thread
        thread1.start();

        // Start the second thread
        thread2.start();
    }
}
```

**Sample Output:**
```
Thread-1 is running.
Thread-2 is running.
```

---

### 3. **Thread Priorities**
- Thread priorities range from `1` (lowest) to `10` (highest).
- The default priority is `5`.
- Use `setPriority(int priority)` to set a thread's priority and `getPriority()` to retrieve it.

**Lab 4:Thread Priorities**
```java
class Task implements Runnable {
    @Override
    public void run() {
        // It prints the name of the currently executing thread and its priority
        System.out.println(Thread.currentThread().getName() + " - Priority: " + Thread.currentThread().getPriority());
    }
}

public class Main {
    public static void main(String[] args) {
        Task task = new Task();
        
        Thread thread1 = new Thread(task, "Thread-1");// The second argument in the Thread constructor sets the thread's name
        Thread thread2 = new Thread(task, "Thread-2");

        // Set the priority of thread1 to the minimum priority (1)
        // Lower priority threads are given less preference by the thread scheduler
        thread1.setPriority(Thread.MIN_PRIORITY); // Priority 1

        // Set the priority of thread2 to the maximum priority (10)
        // Higher priority threads are given more preference by the thread scheduler
        thread2.setPriority(Thread.MAX_PRIORITY); // Priority 10

        // Start the first thread
        thread1.start();

        // Start the second thread
        thread2.start();
    }
}
```

**Sample Output:**
```
Thread-2 - Priority: 10
Thread-1 - Priority: 1
```

---

### 4. **Synchronization**
- Synchronization ensures that only one thread can access a shared resource at a time.
- Use the `synchronized` keyword to create synchronized methods or blocks.

**Program Example:**
```java
class Counter {
    private int count = 0;

    public synchronized void increment() {
        count++;
    }

    public int getCount() {
        return count;
    }
}

public class Main {
    public static void main(String[] args) {
        Counter counter = new Counter();

        Thread t1 = new Thread(() -> {
            for (int i = 0; i < 1000; i++) {
                counter.increment();
            }
        });

        Thread t2 = new Thread(() -> {
            for (int i = 0; i < 1000; i++) {
                counter.increment();
            }
        });

        t1.start();
        t2.start();

        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Count: " + counter.getCount());
    }
}
```

**Sample Output:**
```
Count: 2000
```

---

### 5. **Inter-Thread Communication**
- Threads can communicate using `wait()`, `notify()`, and `notifyAll()`.
- These methods are used in synchronized contexts to coordinate thread execution.

**Program Example:**
```java
class SharedResource {
    private boolean flag = false;

    public synchronized void produce() {
        while (flag) {
            try {
                wait(); // Wait for the consumer to consume
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("Produced...");
        flag = true;
        notify(); // Notify the consumer
    }

    public synchronized void consume() {
        while (!flag) {
            try {
                wait(); // Wait for the producer to produce
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("Consumed...");
        flag = false;
        notify(); // Notify the producer
    }
}

public class Main {
    public static void main(String[] args) {
        SharedResource resource = new SharedResource();

        Thread producer = new Thread(() -> {
            for (int i = 0; i < 5; i++) {
                resource.produce();
            }
        });

        Thread consumer = new Thread(() -> {
            for (int i = 0; i < 5; i++) {
                resource.consume();
            }
        });

        producer.start();
        consumer.start();
    }
}
```

**Sample Output:**
```
Produced...
Consumed...
Produced...
Consumed...
Produced...
Consumed...
Produced...
Consumed...
Produced...
Consumed...
```

---

### 6. **Deadlock**
- Deadlock occurs when two or more threads are blocked forever, waiting for each other to release resources.

**Program Example:**
```java
class Resource {
    synchronized void method1(Resource other) {
        System.out.println(Thread.currentThread().getName() + " executing method1");
        other.method2(this);
    }

    synchronized void method2(Resource other) {
        System.out.println(Thread.currentThread().getName() + " executing method2");
        other.method1(this);
    }
}

public class Main {
    public static void main(String[] args) {
        Resource resource1 = new Resource();
        Resource resource2 = new Resource();

        Thread t1 = new Thread(() -> resource1.method1(resource2), "Thread-1");
        Thread t2 = new Thread(() -> resource2.method1(resource1), "Thread-2");

        t1.start();
        t2.start();
    }
}
```

**Sample Output:**
```
Thread-1 executing method1
Thread-2 executing method1
```

**Explanation:**
- Both threads are stuck waiting for each other to release locks, causing a deadlock.

---

### Summary
- Threads can be created by extending `Thread` or implementing `Runnable`.
- Thread priorities determine the order of execution.
- Synchronization ensures thread-safe access to shared resources.
- Inter-thread communication allows threads to coordinate.
- Deadlock occurs when threads are stuck waiting for each other indefinitely.

This unit provides a foundation for understanding and working with threads in Java.
