### Unit 3: Object-Oriented Programming Concepts (OOP) (9 Hours)

### 3.1 Fundamentals of Classes 

Object-Oriented Programming (OOP) is a programming paradigm that is based on the concept of **objects**, which can contain data and methods. In Java, a **class** is the blueprint from which objects are created. This unit focuses on the **fundamentals of classes**, including creating simple classes, creating class instances (objects), adding methods to classes, and calling functions/methods.

---

### 1. **Introduction to Classes**
A **class** in Java is a blueprint or template for creating objects. It defines a set of attributes (variables) and methods (functions) that describe the behavior of the objects created from the class. An object is an instance of a class.

#### **Basic Syntax of a Class:**
```java
public class ClassName {
    // Attributes (fields) or properties of the class
    int attribute1;
    String attribute2;

    // Constructor (optional)
    public ClassName() {
        // Initialize attributes
    }

    // Methods (functions) for the class
    public void method1() {
        System.out.println("Method 1 of the class.");
    }

    public int add(int a, int b) {
        return a + b;
    }
}
```

### 2. **A Simple Class Example**
Let’s start by creating a simple class called `Person`. This class will have attributes such as `name` and `age`, and a method `greet()` that prints a greeting message.

#### **Example Program:**
```java
public class Person {
    // Attributes (fields)
    String name;
    int age;

    // Constructor to initialize the attributes
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Method to print a greeting message
    public void greet() {
        System.out.println("Hello, my name is " + name + " and I am " + age + " years old.");
    }
}
```

#### **Explanation of the Example:**
- **Class Declaration**: The class `Person` is declared with the keyword `public`. It contains two attributes: `name` (String) and `age` (int).
  
- **Constructor**: The constructor `public Person(String name, int age)` is used to initialize the `name` and `age` attributes when an object is created.
  
- **Method**: The `greet()` method prints a greeting message using the `name` and `age` attributes.

### 3. **Creating Class Instances (Objects)**
An **instance** of a class is an object that is created based on the class template. In Java, objects are created using the `new` keyword.

#### **Example of Creating an Instance:**
```java
public class Main {
    public static void main(String[] args) {
        // Creating an object of the Person class
        Person person1 = new Person("Alice", 25);
        
        // Calling the greet() method on person1
        person1.greet();
    }
}
```

#### **Explanation of the Example:**
- **Creating an Object**: `Person person1 = new Person("Alice", 25);` creates an object `person1` of the class `Person` and initializes it with the values `"Alice"` for the name and `25` for the age.
  
- **Calling a Method**: `person1.greet();` calls the `greet()` method of the `person1` object, which prints the greeting message.

#### **Sample Output:**
```
Hello, my name is Alice and I am 25 years old.
```

### 4. **Adding Methods to a Class**
Methods in Java define the behavior of the objects created from a class. They can accept parameters, perform operations, and return values.

#### **Method Syntax:**
```java
public returnType methodName(parameters) {
    // Method body
    // Perform operations and return a value if needed
}
```

#### **Example: Adding Methods for Calculations**
Let’s add a method to calculate the area of a rectangle in the `Rectangle` class.

```java
public class Rectangle {
    // Attributes (fields)
    double length;
    double width;

    // Constructor to initialize the rectangle's dimensions
    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    // Method to calculate the area of the rectangle
    public double calculateArea() {
        return length * width;
    }
}
```

#### **Explanation of the Example:**
- **Attributes**: The `Rectangle` class has two attributes: `length` and `width`.
  
- **Constructor**: The constructor initializes the `length` and `width` values when a new object of the class is created.
  
- **Method**: The `calculateArea()` method computes and returns the area of the rectangle (i.e., `length * width`).

#### **Using the Rectangle Class:**
```java
public class Main {
    public static void main(String[] args) {
        // Creating an object of Rectangle class
        Rectangle rect = new Rectangle(5.0, 4.0);
        
        // Calling the method to calculate area
        double area = rect.calculateArea();
        
        // Printing the area
        System.out.println("The area of the rectangle is: " + area);
    }
}
```

#### **Explanation of the Example:**
- **Creating an Object**: The object `rect` of class `Rectangle` is created with the length `5.0` and width `4.0`.
  
- **Calling the Method**: `rect.calculateArea();` calculates the area of the rectangle and stores the result in the `area` variable.

#### **Sample Output:**
```
The area of the rectangle is: 20.0
```

### 5. **Calling Functions/Methods**
To **call a method** in Java, you use the object reference for instance methods or the class name for static methods.

#### **Calling Instance Methods**:
An instance method belongs to an object. You must create an object to call the instance method.

```java
objectReference.methodName();
```

#### **Example:**
```java
public class Person {
    String name;

    public Person(String name) {
        this.name = name;
    }

    public void greet() {
        System.out.println("Hello, my name is " + name);
    }
}

public class Main {
    public static void main(String[] args) {
        // Create an object of Person class
        Person person1 = new Person("John");
        
        // Call the greet method
        person1.greet();  // Output: Hello, my name is John
    }
}
```

#### **Calling Static Methods**:
A **static method** belongs to the class itself and can be called without creating an object.

```java
ClassName.methodName();
```

#### **Example with Static Method:**
```java
public class Calculator {
    // Static method for addition
    public static int add(int a, int b) {
        return a + b;
    }
}

public class Main {
    public static void main(String[] args) {
        // Calling the static method without creating an object
        int result = Calculator.add(5, 3);
        
        // Printing the result
        System.out.println("The sum is: " + result);  // Output: The sum is: 8
    }
}
```

### 6. **Access Modifiers in Java**
Java provides **access modifiers** to control the visibility of classes, methods, and variables.

- `public`: Accessible from anywhere.
- `private`: Accessible only within the same class.
- `protected`: Accessible within the same package and by subclasses.
- Default (no modifier): Accessible within the same package.

#### **Example with Access Modifiers:**
```java
public class Person {
    private String name;  // Private field
    public int age;      // Public field

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Public method to access private field
    public String getName() {
        return name;
    }
}

public class Main {
    public static void main(String[] args) {
        Person person = new Person("Alice", 30);
        
        // Accessing public field directly
        System.out.println("Age: " + person.age);
        
        // Accessing private field via a public method
        System.out.println("Name: " + person.getName());
    }
}
```

#### **Sample Output:**
```
Age: 30
Name: Alice
```

---

### Conclusion:
In this unit, we covered the fundamentals of **Classes** in Java. The key concepts include:

1. **Defining a Class**: A class defines the blueprint for objects, containing attributes and methods.
2. **Creating Objects**: Objects are instances of a class, created using the `new` keyword.
3. **Adding Methods**: Methods define the behavior of a class and operate on its attributes.
4. **Calling Methods**: Methods can be called using object references (instance methods) or class names (static methods).
5. **Access Modifiers**: Control the visibility and accessibility of class members (fields, methods).

