### **Unit 1: Introduction to Java**
1. What is Java Bytecode?  
   a) Executable code  
   b) Machine code  
   c) **Intermediate code**  
   d) Assembly code  

2. Which of the following is NOT a feature of Java?  
   a) Platform-independent  
   b) Object-oriented  
   c) **Procedure-oriented**  
   d) Multithreaded  

3. What is the role of the Java Virtual Machine (JVM)?  
   a) Compile Java code  
   b) **Execute Bytecode**  
   c) Write Java programs  
   d) Debug Java programs  

4. Which of the following is a Java keyword?  
   a) **class**  
   b) struct  
   c) include  
   d) define  

5. What is the extension of a Java source file?  
   a) .class  
   b) .exe  
   c) **.java**  
   d) .jar  

6. Which command is used to compile a Java program?  
   a) java  
   b) **javac**  
   c) javadoc  
   d) jvm  

7. What is the default value of an uninitialized integer variable in Java?  
   a) null  
   b) 0.0  
   c) **0**  
   d) undefined  

8. Which of the following is a valid Java identifier?  
   a) 1variable  
   b) variable-name  
   c) **variableName**  
   d) variable name  

9. What is the main purpose of the `public static void main(String[] args)` method in Java?  
   a) To define a class  
   b) **To start the execution of a Java program**  
   c) To compile a Java program  
   d) To debug a Java program  

10. Which of the following is NOT a Java primitive data type?  
    a) int  
    b) float  
    c) **String**  
    d) boolean  

---

### **Unit 2: Tokens, Expressions, and Control Structures**
1. Which of the following is a valid declaration of a boolean variable in Java?  
   a) boolean b = 1;  
   b) **boolean b = true;**  
   c) boolean b = "true";  
   d) boolean b = True;  

2. What is the result of `10 % 3` in Java?  
   a) 0  
   b) **1**  
   c) 3  
   d) 10  

3. Which operator is used for logical AND in Java?  
   a) &  
   b) **&&**  
   c) ||  
   d) |  

4. What is the default value of a boolean variable in Java?  
   a) null  
   b) **false**  
   c) true  
   d) 0  

5. Which of the following is NOT a valid control structure in Java?  
   a) if-else  
   b) switch  
   c) **repeat-until**  
   d) for  

6. What is the output of `System.out.println(5 > 3 ? "Yes" : "No");`?  
   a) No  
   b) **Yes**  
   c) true  
   d) false  

7. Which of the following is a valid way to declare an array in Java?  
   a) int arr[] = new int[5];  
   b) int[] arr = new int[5];  
   c) int arr = new int[5];  
   d) **Both a and b**  

8. What is the purpose of the `break` statement in Java?  
   a) To terminate the program  
   b) **To exit a loop or switch statement**  
   c) To skip the current iteration  
   d) To return a value  

9. Which of the following is a valid Java comment?  
   a) <!-- Comment -->  
   b) **// Comment**  
   c) /* Comment  
   d) ** Comment **  

10. What is the result of `System.out.println(10 + 20 + "30");`?  
    a) 3030  
    b) **3030**  
    c) 60  
    d) 102030  

---

### **Unit 3: Object-Oriented Programming Concepts**
1. What is the keyword used to create an instance of a class in Java?  
   a) class  
   b) **new**  
   c) this  
   d) instance  

2. Which of the following is NOT a principle of OOP?  
   a) Encapsulation  
   b) Inheritance  
   c) Polymorphism  
   d) **Compilation**  

3. What is the purpose of the `this` keyword in Java?  
   a) To create a new object  
   b) **To refer to the current object**  
   c) To call a superclass method  
   d) To define a constructor  

4. Which of the following is true about constructors in Java?  
   a) They can return a value  
   b) They can be inherited  
   c) **They have the same name as the class**  
   d) They can be static  

5. What is method overloading in Java?  
   a) Defining multiple methods with the same name but different return types  
   b) **Defining multiple methods with the same name but different parameters**  
   c) Defining multiple methods with the same name and parameters  
   d) Defining multiple methods with different names  

6. What is the default access modifier for a class in Java?  
   a) public  
   b) private  
   c) **package-private (default)**  
   d) protected  

7. Which of the following is true about recursion in Java?  
   a) It is faster than iteration  
   b) **It involves a method calling itself**  
   c) It cannot be used with methods  
   d) It is not supported in Java  

8. What is the purpose of the `super` keyword in Java?  
   a) To create a new object  
   b) **To refer to the superclass**  
   c) To call a subclass method  
   d) To define a constructor  

9. Which of the following is true about inner classes in Java?  
   a) They cannot access outer class members  
   b) **They can access outer class members**  
   c) They are always static  
   d) They cannot be instantiated  

10. What is the output of the following code?  
    ```java
    class Test {
        int x = 10;
        void display() {
            System.out.println(x);
        }
    }
    public class Main {
        public static void main(String[] args) {
            Test t = new Test();
            t.display();
        }
    }
    ```  
    a) 0  
    b) **10**  
    c) null  
    d) Compilation error  

---

### **Unit 4: Inheritance & Packaging**
1. Which keyword is used to implement inheritance in Java?  
   a) implements  
   b) **extends**  
   c) inherits  
   d) super  

2. What is the purpose of the `super` keyword in Java?  
   a) To create a new object  
   b) **To refer to the superclass**  
   c) To call a subclass method  
   d) To define a constructor  

3. Which of the following is true about method overriding in Java?  
   a) It is done in the same class  
   b) **It requires the method name and parameters to be the same**  
   c) It is not allowed in Java  
   d) It does not involve inheritance  

4. What is the root class of all classes in Java?  
   a) String  
   b) **Object**  
   c) Class  
   d) Main  

5. Which of the following is true about abstract classes in Java?  
   a) They cannot have constructors  
   b) **They cannot be instantiated**  
   c) They cannot have methods  
   d) They cannot be inherited  

6. What is the purpose of the `final` keyword in Java?  
   a) To make a class abstract  
   b) **To prevent inheritance or overriding**  
   c) To make a class static  
   d) To make a class private  

7. Which of the following is true about packages in Java?  
   a) They cannot contain classes  
   b) **They help in organizing classes**  
   c) They are not supported in Java  
   d) They cannot be imported  

8. What is the purpose of the `import` statement in Java?  
   a) To define a package  
   b) **To include classes from other packages**  
   c) To create a new package  
   d) To compile a Java program  

9. Which of the following is true about interfaces in Java?  
   a) They can have constructors  
   b) **They can have abstract methods**  
   c) They cannot be implemented  
   d) They cannot have variables  

10. What is the output of the following code?  
    ```java
    class A {
        void display() {
            System.out.println("Class A");
        }
    }
    class B extends A {
        void display() {
            System.out.println("Class B");
        }
    }
    public class Main {
        public static void main(String[] args) {
            A obj = new B();
            obj.display();
        }
    }
    ```  
    a) Class A  
    b) **Class B**  
    c) Compilation error  
    d) Runtime error  


---

### **Unit 5: Handling Error/Exception**
1. Which keyword is used to handle exceptions in Java?  
   a) try  
   b) catch  
   c) finally  
   d) **All of the above**  

2. What is the purpose of the `finally` block in Java?  
   a) To handle exceptions  
   b) **To execute code regardless of whether an exception occurs**  
   c) To throw exceptions  
   d) To define custom exceptions  

3. Which of the following is a checked exception in Java?  
   a) NullPointerException  
   b) **IOException**  
   c) ArithmeticException  
   d) ArrayIndexOutOfBoundsException  

4. What is the purpose of the `throw` keyword in Java?  
   a) To handle exceptions  
   b) **To explicitly throw an exception**  
   c) To define a custom exception  
   d) To catch exceptions  

5. Which of the following is true about custom exceptions in Java?  
   a) They cannot extend the `Exception` class  
   b) **They must extend the `Exception` class or its subclasses**  
   c) They cannot be thrown  
   d) They are always unchecked exceptions  

6. What is the output of the following code?  
    ```java
    public class Main {
        public static void main(String[] args) {
            try {
                int x = 10 / 0;
            } catch (ArithmeticException e) {
                System.out.println("Exception caught");
            } finally {
                System.out.println("Finally block executed");
            }
        }
    }
    ```  
    a) Exception caught  
    b) Finally block executed  
    c) **Both a and b**  
    d) Compilation error  

7. Which of the following is true about the `throws` keyword in Java?  
   a) It is used to handle exceptions  
   b) **It is used to declare exceptions that a method might throw**  
   c) It is used to throw exceptions  
   d) It is used to define custom exceptions  

8. What is the purpose of the `try-with-resources` statement in Java?  
   a) To handle exceptions  
   b) **To automatically close resources after use**  
   c) To define custom exceptions  
   d) To throw exceptions  

9. Which of the following is NOT a runtime exception in Java?  
   a) NullPointerException  
   b) ArithmeticException  
   c) **IOException**  
   d) ArrayIndexOutOfBoundsException  

10. What is the output of the following code?  
    ```java
    public class Main {
        public static void main(String[] args) {
            try {
                throw new Exception("Custom Exception");
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
    }
    ```  
    a) Custom Exception  
    b) **Custom Exception**  
    c) Compilation error  
    d) Runtime error  

---

### **Unit 6: Handling Strings**
1. Which of the following is a valid way to create a String in Java?  
   a) String s = new String("Hello");  
   b) String s = "Hello";  
   c) **Both a and b**  
   d) None of the above  

2. What is the output of `"Hello".length()`?  
   a) 4  
   b) **5**  
   c) 6  
   d) Compilation error  

3. Which method is used to concatenate two strings in Java?  
   a) concat()  
   b) + operator  
   c) **Both a and b**  
   d) None of the above  

4. What is the output of `"Hello".charAt(1)`?  
   a) H  
   b) **e**  
   c) l  
   d) o  

5. Which of the following is true about the `StringBuffer` class in Java?  
   a) It is immutable  
   b) **It is mutable**  
   c) It cannot be modified  
   d) It is slower than `String`  

6. What is the output of `"Hello".equals("hello")`?  
   a) true  
   b) **false**  
   c) Compilation error  
   d) Runtime error  

7. Which method is used to convert a String to lowercase in Java?  
   a) toLowerCase()  
   b) toLower()  
   c) **toLowerCase()**  
   d) lowerCase()  

8. What is the output of `"Hello".substring(1, 3)`?  
   a) He  
   b) **el**  
   c) llo  
   d) Compilation error  

9. Which of the following is true about the `StringBuilder` class in Java?  
   a) It is immutable  
   b) **It is mutable**  
   c) It is slower than `StringBuffer`  
   d) It cannot be modified  

10. What is the output of `"Hello".indexOf('l')`?  
    a) 1  
    b) **2**  
    c) 3  
    d) 4  

---

### **Unit 7: Threads**
1. Which of the following is a way to create a thread in Java?  
   a) Extending `Thread` class  
   b) Implementing `Runnable` interface  
   c) **Both a and b**  
   d) None of the above  

2. What is the default priority of a thread in Java?  
   a) 1  
   b) **5**  
   c) 10  
   d) 0  

3. Which method is used to start a thread in Java?  
   a) run()  
   b) **start()**  
   c) execute()  
   d) begin()  

4. What is the purpose of the `synchronized` keyword in Java?  
   a) To create a new thread  
   b) **To prevent multiple threads from accessing a resource simultaneously**  
   c) To stop a thread  
   d) To define a thread  

5. Which method is used to pause a thread in Java?  
   a) stop()  
   b) **sleep()**  
   c) pause()  
   d) wait()  

6. What is the output of the following code?  
    ```java
    class MyThread extends Thread {
        public void run() {
            System.out.println("Thread is running");
        }
    }
    public class Main {
        public static void main(String[] args) {
            MyThread t = new MyThread();
            t.start();
        }
    }
    ```  
    a) Compilation error  
    b) Runtime error  
    c) **Thread is running**  
    d) No output  

7. Which of the following is true about thread priorities in Java?  
   a) They cannot be changed  
   b) **They range from 1 to 10**  
   c) They are always 5  
   d) They are not supported  

8. What is the purpose of the `join()` method in Java?  
   a) To start a thread  
   b) **To wait for a thread to finish execution**  
   c) To stop a thread  
   d) To pause a thread  

9. Which of the following is true about deadlock in Java?  
   a) It occurs when a thread is paused  
   b) **It occurs when two or more threads are waiting for each other**  
   c) It occurs when a thread is stopped  
   d) It occurs when a thread is started  

10. What is the output of the following code?  
    ```java
    class MyThread implements Runnable {
        public void run() {
            System.out.println("Thread is running");
        }
    }
    public class Main {
        public static void main(String[] args) {
            MyThread t = new MyThread();
            Thread thread = new Thread(t);
            thread.start();
        }
    }
    ```  
    a) Compilation error  
    b) Runtime error  
    c) **Thread is running**  
    d) No output  


---

### **Unit 8: I/O and Streams**
1. Which package is used for file I/O operations in Java?  
   a) java.util  
   b) **java.io**  
   c) java.net  
   d) java.awt  

2. Which of the following is a character stream class in Java?  
   a) FileInputStream  
   b) **FileReader**  
   c) FileOutputStream  
   d) DataInputStream  

3. What is the purpose of the `File` class in Java?  
   a) To read data from a file  
   b) **To represent a file or directory path**  
   c) To write data to a file  
   d) To delete a file  

4. Which method is used to read a line of text from a file in Java?  
   a) read()  
   b) **readLine()**  
   c) readAll()  
   d) readFile()  

5. What is the purpose of the `Serializable` interface in Java?  
   a) To read data from a file  
   b) **To enable object serialization**  
   c) To write data to a file  
   d) To delete a file  

6. Which of the following is true about byte streams in Java?  
   a) They handle Unicode characters  
   b) **They handle binary data**  
   c) They are slower than character streams  
   d) They cannot be used for file I/O  

7. What is the output of the following code?  
    ```java
    import java.io.*;
    public class Main {
        public static void main(String[] args) throws IOException {
            FileWriter fw = new FileWriter("test.txt");
            fw.write("Hello");
            fw.close();
        }
    }
    ```  
    a) Compilation error  
    b) Runtime error  
    c) **A file named "test.txt" is created with the content "Hello"**  
    d) No output  

8. Which method is used to write data to a file in Java?  
   a) read()  
   b) **write()**  
   c) readLine()  
   d) readAll()  

9. What is the purpose of the `BufferedReader` class in Java?  
   a) To write data to a file  
   b) **To read data efficiently from a file**  
   c) To delete a file  
   d) To represent a file path  

10. Which of the following is true about deserialization in Java?  
    a) It converts an object into a byte stream  
    b) **It converts a byte stream into an object**  
    c) It deletes an object  
    d) It writes data to a file  

---

### **Unit 9: Understanding Core Packages**
1. Which package contains the `Math` class in Java?  
   a) java.util  
   b) **java.lang**  
   c) java.io  
   d) java.awt  

2. What is the output of `Math.sqrt(16)`?  
   a) 2  
   b) **4**  
   c) 8  
   d) 16  

3. Which of the following is a wrapper class in Java?  
   a) int  
   b) **Integer**  
   c) float  
   d) double  

4. What is the purpose of the `Vector` class in Java?  
   a) To store key-value pairs  
   b) **To store a dynamic array of objects**  
   c) To store unique elements  
   d) To store sorted elements  

5. Which of the following is true about the `Hashtable` class in Java?  
   a) It allows null keys and values  
   b) **It does not allow null keys or values**  
   c) It is not synchronized  
   d) It stores elements in sorted order  

6. What is the output of the following code?  
    ```java
    import java.util.*;
    public class Main {
        public static void main(String[] args) {
            Random rand = new Random();
            System.out.println(rand.nextInt(10));
        }
    }
    ```  
    a) A random number between 0 and 9  
    b) **A random number between 0 and 9**  
    c) Compilation error  
    d) Runtime error  

7. Which of the following is true about the `Stack` class in Java?  
   a) It follows FIFO (First In First Out)  
   b) **It follows LIFO (Last In First Out)**  
   c) It allows null values  
   d) It is not synchronized  

8. What is the purpose of the `Enumeration` interface in Java?  
   a) To store key-value pairs  
   b) **To iterate over a collection of elements**  
   c) To store unique elements  
   d) To store sorted elements  

9. Which of the following is true about the `Random` class in Java?  
   a) It generates the same sequence of numbers every time  
   b) **It generates a different sequence of numbers every time**  
   c) It cannot generate random numbers  
   d) It is not part of the `java.util` package  

10. What is the output of the following code?  
    ```java
    import java.util.*;
    public class Main {
        public static void main(String[] args) {
            Vector<Integer> v = new Vector<>();
            v.add(10);
            v.add(20);
            System.out.println(v.get(1));
        }
    }
    ```  
    a) 10  
    b) **20**  
    c) Compilation error  
    d) Runtime error  

---

### **Unit 10: Holding Collection of Data**
1. Which of the following is a collection interface in Java?  
   a) ArrayList  
   b) **List**  
   c) HashSet  
   d) TreeSet  

2. What is the purpose of the `Iterator` interface in Java?  
   a) To store elements  
   b) **To iterate over a collection of elements**  
   c) To sort elements  
   d) To remove elements  

3. Which of the following is true about the `ArrayList` class in Java?  
   a) It does not allow duplicate elements  
   b) **It allows duplicate elements**  
   c) It is synchronized  
   d) It stores elements in sorted order  

4. What is the output of the following code?  
    ```java
    import java.util.*;
    public class Main {
        public static void main(String[] args) {
            List<String> list = new ArrayList<>();
            list.add("Java");
            list.add("Python");
            System.out.println(list.get(1));
        }
    }
    ```  
    a) Java  
    b) **Python**  
    c) Compilation error  
    d) Runtime error  

5. Which of the following is true about the `HashSet` class in Java?  
   a) It allows duplicate elements  
   b) **It does not allow duplicate elements**  
   c) It stores elements in sorted order  
   d) It is synchronized  

6. What is the purpose of the `Comparator` interface in Java?  
   a) To store elements  
   b) **To define custom sorting logic**  
   c) To iterate over elements  
   d) To remove elements  

7. Which of the following is true about the `TreeSet` class in Java?  
   a) It does not allow duplicate elements  
   b) **It stores elements in sorted order**  
   c) It is not synchronized  
   d) It allows null values  

8. What is the output of the following code?  
    ```java
    import java.util.*;
    public class Main {
        public static void main(String[] args) {
            Set<Integer> set = new HashSet<>();
            set.add(10);
            set.add(20);
            set.add(10);
            System.out.println(set.size());
        }
    }
    ```  
    a) 1  
    b) **2**  
    c) 3  
    d) Compilation error  

9. Which of the following is true about the `Map` interface in Java?  
   a) It stores elements in sorted order  
   b) **It stores key-value pairs**  
   c) It does not allow duplicate keys  
   d) It is not part of the `java.util` package  

10. What is the output of the following code?  
    ```java
    import java.util.*;
    public class Main {
        public static void main(String[] args) {
            Map<String, Integer> map = new HashMap<>();
            map.put("Java", 10);
            map.put("Python", 20);
            System.out.println(map.get("Python"));
        }
    }
    ```  
    a) 10  
    b) **20**  
    c) Compilation error  
    d) Runtime error  

---

### **Unit 11: Java Applications**
1. Which of the following is a Swing component in Java?  
   a) Frame  
   b) **JFrame**  
   c) Window  
   d) Panel  

2. What is the purpose of the `JButton` class in Java?  
   a) To display text  
   b) **To create a clickable button**  
   c) To display images  
   d) To create a text field  

3. Which of the following is true about event handling in Java?  
   a) It is not supported in Swing  
   b) **It involves listeners and events**  
   c) It cannot be used with buttons  
   d) It is not part of the AWT package  

4. What is the purpose of the `FlowLayout` manager in Java?  
   a) To arrange components in a grid  
   b) **To arrange components in a flow**  
   c) To arrange components in a border  
   d) To arrange components in a stack  

5. Which of the following is true about the `JTextField` class in Java?  
   a) It is used to display images  
   b) **It is used to accept user input**  
   c) It is not part of Swing  
   d) It cannot be added to a frame  

6. What is the purpose of the `JCheckBox` class in Java?  
   a) To display text  
   b) **To create a checkbox**  
   c) To display images  
   d) To create a button  

7. Which of the following is true about the `JComboBox` class in Java?  
   a) It is used to display images  
   b) **It is used to create a dropdown list**  
   c) It is not part of Swing  
   d) It cannot be added to a frame  

8. What is the purpose of the `JMenuBar` class in Java?  
   a) To display text  
   b) **To create a menu bar**  
   c) To display images  
   d) To create a button  

9. Which of the following is true about the `JTable` class in Java?  
   a) It is used to display images  
   b) **It is used to display data in tabular form**  
   c) It is not part of Swing  
   d) It cannot be added to a frame  

10. What is the purpose of the `JDesktopPane` class in Java?  
    a) To display text  
    b) **To create a multi-document interface (MDI)**  
    c) To display images  
    d) To create a button  

---

### **Unit 12: Introduction to Java Applets**
1. Which of the following is a lifecycle method of an applet?  
   a) start()  
   b) stop()  
   c) init()  
   d) **All of the above**  

2. What is the purpose of the `Applet` class in Java?  
   a) To create a standalone application  
   b) **To create an applet**  
   c) To create a Swing application  
   d) To create a console application  

3. Which of the following is true about applets in Java?  
   a) They cannot be run in a browser  
   b) **They are embedded in web pages**  
   c) They are not part of Java  
   d) They cannot use graphics  

4. What is the purpose of the `paint()` method in an applet?  
   a) To initialize the applet  
   b) **To draw graphics on the applet**  
   c) To start the applet  
   d) To stop the applet  

5. Which of the following is true about the `AppletViewer` tool in Java?  
   a) It is used to compile applets  
   b) **It is used to run applets**  
   c) It is not part of Java  
   d) It cannot be used with applets  

6. What is the output of the following code?  
    ```java
    import java.applet.*;
    import java.awt.*;
    public class MyApplet extends Applet {
        public void paint(Graphics g) {
            g.drawString("Hello", 50, 50);
        }
    }
    ```  
    a) Compilation error  
    b) Runtime error  
    c) **"Hello" is displayed at (50, 50)**  
    d) No output  

7. Which of the following is true about animation in applets?  
   a) It is not supported  
   b) **It can be achieved using threads**  
   c) It cannot use graphics  
   d) It is not part of Java  

8. What is the purpose of the `repaint()` method in an applet?  
   a) To initialize the applet  
   b) **To refresh the applet display**  
   c) To start the applet  
   d) To stop the applet  

9. Which of the following is true about the `Graphics` class in Java?  
   a) It is used to create buttons  
   b) **It is used to draw graphics**  
   c) It is not part of the AWT package  
   d) It cannot be used in applets  

10. What is the output of the following code?  
    ```java
    import java.applet.*;
    import java.awt.*;
    public class MyApplet extends Applet {
        public void paint(Graphics g) {
            g.drawRect(50, 50, 100, 100);
        }
    }
    ```  
    a) Compilation error  
    b) Runtime error  
    c) **A rectangle is drawn at (50, 50)**  
    d) No output  

---

### **Unit 13: Database Programming using JDBC**
1. Which of the following is a JDBC interface?  
   a) Connection  
   b) Statement  
   c) ResultSet  
   d) **All of the above**  

2. What is the purpose of the `Connection` interface in JDBC?  
   a) To execute SQL queries  
   b) **To establish a connection to a database**  
   c) To store query results  
   d) To close the database  

3. Which of the following is true about the `Statement` interface in JDBC?  
   a) It is used to establish a connection  
   b) **It is used to execute SQL queries**  
   c) It is used to store query results  
   d) It is used to close the database  

4. What is the purpose of the `ResultSet` interface in JDBC?  
   a) To establish a connection  
   b) To execute SQL queries  
   c) **To store and retrieve query results**  
   d) To close the database  

5. Which of the following is true about the `DriverManager` class in JDBC?  
   a) It is used to execute SQL queries  
   b) **It is used to manage database drivers**  
   c) It is used to store query results  
   d) It is used to close the database  

6. What is the output of the following code?  
    ```java
    import java.sql.*;
    public class Main {
        public static void main(String[] args) throws SQLException {
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/test", "root", "password");
            System.out.println("Connection established");
        }
    }
    ```  
    a) Compilation error  
    b) Runtime error  
    c) **Connection established**  
    d) No output  

7. Which of the following is true about the `PreparedStatement` interface in JDBC?  
   a) It is used to establish a connection  
   b) **It is used to execute parameterized SQL queries**  
   c) It is used to store query results  
   d) It is used to close the database  

8. What is the purpose of the `executeQuery()` method in JDBC?  
   a) To establish a connection  
   b) **To execute a SELECT query**  
   c) To execute an UPDATE query  
   d) To close the database  

9. Which of the following is true about the `executeUpdate()` method in JDBC?  
   a) It is used to execute a SELECT query  
   b) **It is used to execute INSERT, UPDATE, or DELETE queries**  
   c) It is used to establish a connection  
   d) It is used to close the database  

10. What is the output of the following code?  
    ```java
    import java.sql.*;
    public class Main {
        public static void main(String[] args) throws SQLException {
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/test", "root", "password");
            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT * FROM employees");
            while (rs.next()) {
                System.out.println(rs.getString("name"));
            }
        }
    }
    ```  
    a) Compilation error  
    b) Runtime error  
    c) **The names of all employees are printed**  
    d) No output  

---
