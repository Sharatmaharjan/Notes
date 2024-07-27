### Chatper 5: Object- Oriented Programming (OOP) [10-HRS]

- 5.1 Programming paradigms: procedural, structural and object oriented
- 5.2 Features of OOP: Class, Object, Polymorphism and Inheritance
- 5.3 Advantages of OOP 
- 5.4 Application of OOP
____________________________________________________________________________________________________________________________________________________________

### 5.1 Programming Paradigms: Procedural, Structural, and Object-Oriented

Programming paradigms represent different approaches to programming and problem-solving.

### 1. Procedural Programming

**Definition:**
- **Procedural Programming** is a paradigm based on the concept of procedures, routines, or functions. It emphasizes a sequence of operations to be performed and organizes code into reusable procedures.

**Key Concepts:**
- **Procedures/Functions:** Encapsulate specific tasks or operations. Procedures are executed in a step-by-step manner.
- **Sequence:** Code execution follows a linear sequence of commands or function calls.
- **Variables:** Use of variables to store data and state, which are manipulated by procedures.
- **Control Structures:** Use of conditionals (`if`, `else`, `switch`) and loops (`for`, `while`, `do-while`) to control the flow of execution.

**Advantages:**
- **Simplicity:** Easy to understand and implement for small programs.
- **Modularity:** Code can be organized into functions or procedures that can be reused.
- **Performance:** Often efficient for straightforward tasks due to direct control over computation and state.

**Disadvantages:**
- **Scalability:** Can become difficult to manage and understand in large codebases due to interdependencies between procedures.
- **State Management:** State is often managed through global variables, which can lead to side effects and make debugging challenging.

**Example:**
```c
#include <stdio.h>

// Procedure to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) return 1;
    else return n * factorial(n - 1);
}

int main() {
    int number = 5;
    printf("Factorial of %d is %d\n", number, factorial(number));
    return 0;
}
```

### 2. Structural Programming

**Definition:**
- **Structural Programming** is a subset of procedural programming that emphasizes the use of well-defined control structures and modularization to improve code clarity and maintainability.

**Key Concepts:**
- **Control Structures:** Use of `sequence`, `selection` (e.g., `if`, `switch`), and `iteration` (e.g., `for`, `while`) to structure the program.
- **Modularization:** Breaking down code into smaller, manageable modules or functions to enhance readability and maintainability.
- **Top-Down Design:** Design approach where the problem is broken down into smaller subproblems, which are solved independently.

**Advantages:**
- **Improved Readability:** Clear structure and modular code make it easier to understand and maintain.
- **Ease of Debugging:** Well-defined modules and control structures simplify the debugging process.

**Disadvantages:**
- **Limited Abstraction:** Does not provide mechanisms for encapsulating data and behavior together as effectively as object-oriented programming.

**Example:**
```c
#include <stdio.h>

void printMessage() {
    printf("Hello, World!\n");
}

int main() {
    printMessage();
    return 0;
}
```

### 3. Object-Oriented Programming (OOP)

**Definition:**
- **Object-Oriented Programming (OOP)** is a paradigm based on the concept of objects, which encapsulate both data and methods that operate on the data. OOP emphasizes organizing code around objects rather than procedures.

**Key Concepts:**
- **Classes:** Blueprints for creating objects. Define attributes (data) and methods (functions) for objects.
- **Objects:** Instances of classes that encapsulate data and behavior.
- **Inheritance:** Mechanism by which one class can inherit properties and methods from another class, promoting code reuse.
- **Polymorphism:** Ability for different classes to be treated as instances of the same class through a common interface, allowing for method overriding and dynamic method resolution.
- **Encapsulation:** Bundling data and methods within a class and restricting direct access to some of the object's components to protect its integrity.
- **Abstraction:** Hiding complex implementation details and showing only the necessary features of an object.

**Advantages:**
- **Code Reusability:** Inheritance allows for reuse of existing code.
- **Modularity:** Encapsulation and abstraction improve code organization and maintenance.
- **Flexibility:** Polymorphism and dynamic method binding enable more flexible and scalable code.

**Disadvantages:**
- **Complexity:** Can introduce additional complexity, especially for beginners.
- **Overhead:** May involve more memory and processing overhead due to object management.

**Example:**
```php
<?php
class Animal {
    protected $name;

    // Constructor
    public function __construct($name) {
        $this->name = $name;
    }

    // Method
    public function makeSound() {
        echo "Animal makes a sound<br>";
    }
}

class Dog extends Animal {

    // Constructor
    public function __construct($name) {
        parent::__construct($name);
    }

    // Method overriding
    public function makeSound() {
        echo $this->name . " barks<br>";
    }
}

// Main
$dog = new Dog("Buddy");
$dog->makeSound(); // Output: Buddy barks
?>
```

### Summary of Programming Paradigms

| Paradigm         | Focus                                         | Key Concepts                                  | Advantages                                      | Disadvantages                                  | Example                                    |
|------------------|-----------------------------------------------|-----------------------------------------------|-------------------------------------------------|------------------------------------------------|--------------------------------------------|
| **Procedural**   | Sequence of procedures or functions           | Procedures, sequence, variables, control structures | Simplicity, modularity, performance              | Scalability, state management                 | C programming with functions               |
| **Structural**   | Organization of code into well-defined structures | Control structures, modularization, top-down design | Improved readability, ease of debugging         | Limited abstraction                           | Structured C programs with modular design  |
| **Object-Oriented** | Encapsulation of data and behavior into objects | Classes, objects, inheritance, polymorphism, encapsulation, abstraction | Code reusability, modularity, flexibility       | Complexity, overhead                           | Java classes and objects                    |

____________________________________________________________________________________________________________________________________________________________


### 5.2 Features of Object-Oriented Programming (OOP)

Object-Oriented Programming (OOP) is a paradigm centered around objects and classes, which help organize and structure code.
### 1. Class

**Definition:**
- A **class** is a blueprint for creating objects. It defines a data structure that encapsulates data (attributes) and methods (functions) that operate on the data.

**Key Concepts:**
- **Attributes (Data Members):** Variables that hold data or state related to the object.
- **Methods (Member Functions):** Functions defined within the class that operate on the attributes and provide behavior to the objects.

**Characteristics:**
- **Encapsulation:** Combines data and methods into a single unit (class), providing a clear modular structure.
- **Abstraction:** Allows for defining complex data structures and behaviors while hiding implementation details.

**Example:**
```php
<?php
class Car {
    // Attributes
    public $brand;
    public $year;

    // Constructor
    public function __construct($brand, $year) {
        $this->brand = $brand;
        $this->year = $year;
    }

    // Method
    public function displayInfo() {
        echo "Brand: " . $this->brand . ", Year: " . $this->year . "<br>";
    }
}

// Create an object of the class
$myCar = new Car("Toyota", 2020);
$myCar->displayInfo(); // Output: Brand: Toyota, Year: 2020
?>
```

### 2. Object

**Definition:**
- An **object** is an instance of a class. It represents a concrete realization of the class and encapsulates data and methods defined by the class.

**Key Concepts:**
- **Instantiation:** Creating an object from a class using the `new` keyword.
- **State:** The data contained in an object, represented by its attributes.
- **Behavior:** The actions or functions an object can perform, defined by its methods.

**Characteristics:**
- **Unique Identity:** Each object has a unique identity, even if its state is identical to another object.
- **Interaction:** Objects interact with each other through their methods, facilitating communication and functionality within the program.

**Example:**
```php
<?php
class Person {
    public $name;
    public $age;

    public function __construct($name, $age) {
        $this->name = $name;
        $this->age = $age;
    }

    public function introduce() {
        echo "Hello, my name is " . $this->name . " and I am " . $this->age . " years old.<br>";
    }
}

$person1 = new Person("Alice", 30);
$person2 = new Person("Bob", 25);

$person1->introduce(); // Output: Hello, my name is Alice and I am 30 years old.
$person2->introduce(); // Output: Hello, my name is Bob and I am 25 years old.
?>
```

### 3. Polymorphism

**Definition:**
- **Polymorphism** allows objects of different classes to be treated as objects of a common superclass. It enables a single function or method to operate in different ways based on the object invoking it.

**Types of Polymorphism:**
- **Compile-Time Polymorphism (Method Overloading):** Achieved by defining multiple methods with the same name but different parameters within the same class (PHP does not support method overloading in the traditional sense).
- **Runtime Polymorphism (Method Overriding):** Achieved by redefining a method in a subclass that is already defined in its superclass.

**Characteristics:**
- **Method Overloading:** Multiple methods with the same name but different signatures (parameters) in a class (not supported in PHP).
- **Method Overriding:** Subclass provides a specific implementation of a method already defined in its superclass.

**Example:**
```php
<?php
class Animal {
    public function makeSound() {
        echo "Animal makes a sound<br>";
    }
}

class Dog extends Animal {
    public function makeSound() {
        echo "Dog barks<br>";
    }
}

class Cat extends Animal {
    public function makeSound() {
        echo "Cat meows<br>";
    }
}

function makeAnimalSound(Animal $animal) {
    $animal->makeSound();
}

$dog = new Dog();
$cat = new Cat();

makeAnimalSound($dog); // Output: Dog barks
makeAnimalSound($cat); // Output: Cat meows
?>
```

### 4. Inheritance

**Definition:**
- **Inheritance** is a mechanism by which a new class (subclass or derived class) inherits properties and behaviors (attributes and methods) from an existing class (superclass or base class). It promotes code reuse and hierarchical relationships.

**Key Concepts:**
- **Superclass/Base Class:** The class being inherited from.
- **Subclass/Derived Class:** The class that inherits from the superclass and can add or override attributes and methods.
- **Access Modifiers:** Control access to the inherited members (e.g., `public`, `protected`, `private`).

**Types of Inheritance:**
- **Single Inheritance:** A subclass inherits from a single superclass.
- **Multiple Inheritance:** A subclass inherits from multiple superclasses (not directly supported in PHP but can be achieved using interfaces).
- **Hierarchical Inheritance:** Multiple subclasses inherit from a single superclass.
- **Multilevel Inheritance:** A subclass inherits from another subclass.

**Example:**
```php
<?php
class Animal {
    public function eat() {
        echo "Animal eats<br>";
    }
}

class Dog extends Animal {
    public function bark() {
        echo "Dog barks<br>";
    }
}

$dog = new Dog();
$dog->eat();   // Inherited method
$dog->bark();  // Subclass method
?>
```

### Summary of OOP Features

| Feature       | Description                                                                 | Characteristics                                      | Example                            |
|---------------|-----------------------------------------------------------------------------|------------------------------------------------------|------------------------------------|
| **Class**     | Blueprint for creating objects; defines data and behavior                    | Encapsulation, abstraction                           | `class Car` in PHP                 |
| **Object**    | Instance of a class; encapsulates data and methods                           | Unique identity, state, behavior                    | `$myCar = new Car("Toyota", 2020)` |
| **Polymorphism** | Ability to treat objects of different classes as instances of a common superclass | Method overloading (not supported), method overriding | `makeAnimalSound($animal)` example |
| **Inheritance** | Mechanism to create new classes based on existing ones                      | Code reuse, hierarchical relationships               | `class Dog extends Animal` example  |

____________________________________________________________________________________________________________________________________________________________

### 5.3 Advantages of Object-Oriented Programming (OOP)

Object-Oriented Programming (OOP) offers several advantages that contribute to the development of robust, maintainable, and scalable software.

### 1. **Encapsulation**

**Definition:**
- Encapsulation refers to bundling the data (attributes) and methods (functions) that operate on the data into a single unit or class. It also hides the internal implementation details from the outside world.

**Advantages:**
- **Data Hiding:** Internal object details are hidden, exposing only necessary interfaces. This reduces complexity and prevents unintended interference.
- **Improved Maintenance:** Changes to the internal implementation can be made without affecting external code that uses the class.

**Example in PHP:**
```php
<?php
class BankAccount {
    private $balance;

    public function __construct($initialBalance) {
        $this->balance = $initialBalance;
    }

    public function deposit($amount) {
        $this->balance += $amount;
    }

    public function getBalance() {
        return $this->balance;
    }
}

$account = new BankAccount(1000);
$account->deposit(500);
echo $account->getBalance(); // Output: 1500
?>
```

### 2. **Abstraction**

**Definition:**
- Abstraction involves defining complex data structures and operations while hiding the implementation details. It provides a simplified view of an object’s functionality.

**Advantages:**
- **Simplified Interface:** Users interact with the object through a simplified interface without needing to understand its complexity.
- **Enhanced Focus:** Developers can focus on high-level design without getting bogged down by the details.

**Example in PHP:**
```php
<?php
abstract class Shape {
    abstract public function area();
}

class Rectangle extends Shape {
    private $width;
    private $height;

    public function __construct($width, $height) {
        $this->width = $width;
        $this->height = $height;
    }

    public function area() {
        return $this->width * $this->height;
    }
}

$rectangle = new Rectangle(5, 10);
echo $rectangle->area(); // Output: 50
?>
```

### 3. **Inheritance**

**Definition:**
- Inheritance allows one class (subclass) to inherit properties and methods from another class (superclass). This promotes code reuse and creates a hierarchical relationship between classes.

**Advantages:**
- **Code Reuse:** Common functionality can be inherited from a base class, reducing redundancy and improving maintainability.
- **Extensibility:** New classes can be created with additional or modified behavior without altering existing code.

**Example in PHP:**
```php
<?php
class Animal {
    public function eat() {
        echo "Animal eats<br>";
    }
}

class Dog extends Animal {
    public function bark() {
        echo "Dog barks<br>";
    }
}

$dog = new Dog();
$dog->eat();   // Inherited method
$dog->bark();  // Subclass method
?>
```

### 4. **Polymorphism**

**Definition:**
- Polymorphism allows objects of different classes to be treated as objects of a common superclass. It enables a single method or function to operate differently based on the object it is acting upon.

**Advantages:**
- **Flexibility:** The same method or function can work with different types of objects, making code more flexible and extensible.
- **Code Reduction:** Reduces the need for multiple method implementations for similar behavior across different classes.

**Example in PHP:**
```php
<?php
class Animal {
    public function makeSound() {
        echo "Animal makes a sound<br>";
    }
}

class Dog extends Animal {
    public function makeSound() {
        echo "Dog barks<br>";
    }
}

class Cat extends Animal {
    public function makeSound() {
        echo "Cat meows<br>";
    }
}

function makeAnimalSound(Animal $animal) {
    $animal->makeSound();
}

$dog = new Dog();
$cat = new Cat();

makeAnimalSound($dog); // Output: Dog barks
makeAnimalSound($cat); // Output: Cat meows
?>
```

### 5. **Modularity**

**Definition:**
- Modularity involves breaking down a program into separate, self-contained modules or classes. Each module performs a specific function and interacts with other modules through well-defined interfaces.

**Advantages:**
- **Ease of Maintenance:** Changes to one module have minimal impact on others, making it easier to maintain and update code.
- **Improved Organization:** Code is organized into manageable units, enhancing readability and manageability.

**Example in PHP:**
```php
<?php
class Engine {
    public function start() {
        echo "Engine starts<br>";
    }
}

class Car {
    private $engine;

    public function __construct(Engine $engine) {
        $this->engine = $engine;
    }

    public function start() {
        $this->engine->start();
        echo "Car is ready to go<br>";
    }
}

$engine = new Engine();
$car = new Car($engine);
$car->start(); // Output: Engine starts<br> Car is ready to go
?>
```

### Summary of OOP Advantages

| Advantage       | Description                                                                 | Example                                    |
|-----------------|-----------------------------------------------------------------------------|--------------------------------------------|
| **Encapsulation** | Bundles data and methods into a single unit; hides internal details       | `BankAccount` class with private balance   |
| **Abstraction** | Simplifies interaction with complex objects by hiding implementation details | `Shape` abstract class with `Rectangle`    |
| **Inheritance** | Allows code reuse and hierarchical relationships between classes            | `Dog` inherits from `Animal`                |
| **Polymorphism** | Enables a single method to operate differently based on the object          | `makeAnimalSound` method with `Dog` and `Cat` |
| **Modularity**   | Breaks down code into self-contained modules or classes                      | `Car` class using `Engine` class            |

____________________________________________________________________________________________________________________________________________________________

### 5.4 Applications of Object-Oriented Programming (OOP)

Object-Oriented Programming (OOP) is widely used across various domains due to its advantages in organizing, maintaining, and extending code.

### 1. **Web Development**

**Description:**
- OOP is extensively used in web development frameworks and libraries. It helps in managing complex web applications by organizing code into classes and objects, making it easier to develop, maintain, and extend.

**Examples:**
- **Frameworks:** Laravel, Symfony, and Zend Framework in PHP; Django and Flask in Python.
- **Content Management Systems (CMS):** WordPress, Joomla, and Drupal.

**Benefits:**
- **Modular Design:** Facilitates creating reusable components and modules.
- **Encapsulation:** Protects internal data and methods, exposing only necessary parts.

**Example in PHP:**
```php
<?php
// A simple example using a web framework-like approach

class User {
    private $username;
    private $password;

    public function __construct($username, $password) {
        $this->username = $username;
        $this->password = $password;
    }

    public function login() {
        // Login logic here
        echo "User " . $this->username . " logged in.<br>";
    }
}

$user = new User("john_doe", "securepassword");
$user->login(); // Output: User john_doe logged in.
?>
```

### 2. **Game Development**

**Description:**
- OOP helps manage game development by organizing game entities (e.g., players, enemies, levels) into classes. It simplifies the management of game states, behaviors, and interactions.

**Examples:**
- **Game Engines:** Unity (C#), Unreal Engine (C++), Godot (GDScript/C#).

**Benefits:**
- **Inheritance:** Allows creating different types of game characters or objects based on a base class.
- **Polymorphism:** Enables different behaviors for similar methods, like various character actions.

**Example in PHP:**
```php
<?php
class Character {
    public $name;

    public function __construct($name) {
        $this->name = $name;
    }

    public function attack() {
        echo $this->name . " attacks!<br>";
    }
}

class Warrior extends Character {
    public function attack() {
        echo $this->name . " swings a sword!<br>";
    }
}

class Mage extends Character {
    public function attack() {
        echo $this->name . " casts a spell!<br>";
    }
}

$warrior = new Warrior("Arthur");
$mage = new Mage("Merlin");

$warrior->attack(); // Output: Arthur swings a sword!
$mage->attack();   // Output: Merlin casts a spell!
?>
```

### 3. **Desktop Applications**

**Description:**
- OOP is used to design and build desktop applications, providing a structured way to manage complex interactions between user interface elements, business logic, and data.

**Examples:**
- **Applications:** Microsoft Office, Adobe Photoshop, and many custom enterprise applications.

**Benefits:**
- **Modularity:** Allows for the development of reusable components like dialogs, forms, and controls.
- **Encapsulation:** Protects internal logic and data from outside interference.

**Example in PHP (using a desktop GUI library like PHP-GTK):**
```php
<?php
// Example using PHP-GTK

class MyWindow extends GtkWindow {
    public function __construct() {
        parent::__construct();
        $this->set_title("OOP in Desktop Application");
        $this->set_default_size(300, 200);

        $button = new GtkButton("Click Me");
        $button->connect('clicked', array($this, 'onButtonClick'));

        $this->add($button);
        $this->show_all();
    }

    public function onButtonClick() {
        echo "Button was clicked!<br>";
    }
}

$window = new MyWindow();
Gtk::main();
?>
```

### 4. **Software Engineering and Design Patterns**

**Description:**
- OOP is foundational for many design patterns and software engineering practices. It helps in creating reusable and maintainable code through common design patterns.

**Examples:**
- **Design Patterns:** Singleton, Factory, Observer, Strategy.
- **Architectures:** MVC (Model-View-Controller) pattern used in many frameworks.

**Benefits:**
- **Reusability:** Design patterns promote reusable solutions to common problems.
- **Maintainability:** Patterns like MVC help in separating concerns, making the codebase easier to manage.

**Example of the Singleton Pattern in PHP:**
```php
<?php
class Singleton {
    private static $instance = null;

    private function __construct() {
        // Private constructor to prevent multiple instances
    }

    public static function getInstance() {
        if (self::$instance == null) {
            self::$instance = new Singleton();
        }
        return self::$instance;
    }

    public function doSomething() {
        echo "Doing something<br>";
    }
}

$singleton = Singleton::getInstance();
$singleton->doSomething(); // Output: Doing something
?>
```

### 5. **Data Management Systems**

**Description:**
- OOP is used in database management systems and applications to model real-world entities, relationships, and operations. It helps in managing complex data interactions and enforcing data integrity.

**Examples:**
- **ORM Libraries:** Doctrine (PHP), Entity Framework (C#), Hibernate (Java).

**Benefits:**
- **Data Modeling:** Allows mapping database tables to classes, providing a natural way to interact with data.
- **Complex Queries:** Facilitates complex data operations and relationships through object methods.

**Example in PHP (using an ORM-like approach):**
```php
<?php
class User {
    private $id;
    private $name;

    public function __construct($id, $name) {
        $this->id = $id;
        $this->name = $name;
    }

    public function save() {
        // Save user to the database
        echo "User " . $this->name . " saved to the database.<br>";
    }
}

$user = new User(1, "John Doe");
$user->save(); // Output: User John Doe saved to the database.
?>
```

### Summary of OOP Applications

| Application         | Description                                             | Benefits                                      | Example                                      |
|---------------------|---------------------------------------------------------|-----------------------------------------------|----------------------------------------------|
| **Web Development** | Used in frameworks and CMS for managing complex sites | Modular design, encapsulation                 | Laravel, WordPress                           |
| **Game Development**| Organizes game entities and behaviors                  | Inheritance, polymorphism                     | Unity (C#), Unreal Engine (C++)              |
| **Desktop Applications** | Manages complex user interfaces and logic          | Modularity, encapsulation                     | PHP-GTK example                              |
| **Software Engineering** | Utilizes design patterns for reusable solutions      | Reusability, maintainability                  | Singleton, MVC patterns                      |
| **Data Management Systems** | Models real-world data and interactions            | Data modeling, complex queries                | ORM libraries like Doctrine                  |
____________________________________________________________________________________________________________________________________________________________
