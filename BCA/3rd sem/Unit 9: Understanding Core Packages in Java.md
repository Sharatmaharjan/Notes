## Unit 9: Understanding Core Packages in Java

#### 1. **Using java.lang Package**
The `java.lang` package is automatically imported into every Java program. It provides fundamental classes and methods that are essential for Java programming.

##### **java.lang.Math**
The `Math` class provides methods for performing basic numeric operations such as exponential, logarithm, square root, and trigonometric functions.

**Example:**
```java
public class MathExample {
    public static void main(String[] args) {
        double num1 = 25.0;
        double num2 = 4.0;

        System.out.println("Square root of " + num1 + " is: " + Math.sqrt(num1));
        System.out.println("Power of " + num1 + " raised to " + num2 + " is: " + Math.pow(num1, num2));
        System.out.println("Maximum between " + num1 + " and " + num2 + " is: " + Math.max(num1, num2));
        System.out.println("Minimum between " + num1 + " and " + num2 + " is: " + Math.min(num1, num2));
    }
}
```

**Sample Output:**
```
Square root of 25.0 is: 5.0
Power of 25.0 raised to 4.0 is: 390625.0
Maximum between 25.0 and 4.0 is: 25.0
Minimum between 25.0 and 4.0 is: 4.0
```

**Explanation:**
- `Math.sqrt()` calculates the square root of a number.
- `Math.pow()` raises a number to the power of another.
- `Math.max()` returns the greater of two numbers.
- `Math.min()` returns the smaller of two numbers.

##### **Wrapper Classes**
Wrapper classes provide a way to use primitive data types (`int`, `char`, `boolean`, etc.) as objects. Each primitive type has a corresponding wrapper class.

**Example:**
```java
public class WrapperExample {
    public static void main(String[] args) {
        Integer intObj = Integer.valueOf(10);
        Double doubleObj = Double.valueOf(5.5);
        Character charObj = Character.valueOf('A');
        Boolean boolObj = Boolean.valueOf(true);

        System.out.println("Integer Object: " + intObj);
        System.out.println("Double Object: " + doubleObj);
        System.out.println("Character Object: " + charObj);
        System.out.println("Boolean Object: " + boolObj);

        int intValue = intObj.intValue();
        double doubleValue = doubleObj.doubleValue();
        char charValue = charObj.charValue();
        boolean boolValue = boolObj.booleanValue();

        System.out.println("Primitive int: " + intValue);
        System.out.println("Primitive double: " + doubleValue);
        System.out.println("Primitive char: " + charValue);
        System.out.println("Primitive boolean: " + boolValue);
    }
}
```

**Sample Output:**
```
Integer Object: 10
Double Object: 5.5
Character Object: A
Boolean Object: true
Primitive int: 10
Primitive double: 5.5
Primitive char: A
Primitive boolean: true
```

**Explanation:**
- Wrapper classes like `Integer`, `Double`, `Character`, and `Boolean` are used to convert primitive types into objects.
- Methods like `intValue()`, `doubleValue()`, `charValue()`, and `booleanValue()` are used to retrieve the primitive value from the wrapper object.

**Difference Between Primitive Types and Wrapper Classes:**
- Primitive types are not objects and are stored directly in memory, while wrapper classes are objects and provide additional methods for manipulation.

#### 2. **Using java.util Package**
The `java.util` package contains utility classes and interfaces, such as collections, date and time facilities, and random number generation.

##### **Core Classes**
- **Vector**: A dynamic array that can grow or shrink in size.
- **Stack**: A last-in-first-out (LIFO) data structure.
- **Dictionary**: An abstract class that maps keys to values (deprecated in favor of `Map`).
- **Hashtable**: A synchronized implementation of a hash table.
- **Enumerations**: An interface for iterating through a collection of elements.
- **Random Number Generation**: The `Random` class is used to generate random numbers.

**Example of Vector and Stack:**
```java
import java.util.Vector;
import java.util.Stack;

public class VectorStackExample {
    public static void main(String[] args) {
        // Vector Example
        Vector<String> vector = new Vector<>();
        vector.add("Apple");
        vector.add("Banana");
        vector.add("Cherry");
        System.out.println("Vector: " + vector);

        // Stack Example
        Stack<String> stack = new Stack<>();
        stack.push("Red");
        stack.push("Green");
        stack.push("Blue");
        System.out.println("Stack: " + stack);
        System.out.println("Popped Element: " + stack.pop());
        System.out.println("Stack after pop: " + stack);
    }
}
```

**Sample Output:**
```
Vector: [Apple, Banana, Cherry]
Stack: [Red, Green, Blue]
Popped Element: Blue
Stack after pop: [Red, Green]
```

**Explanation:**
- `Vector` is a resizable array that can store elements.
- `Stack` is a LIFO data structure where elements are added and removed from the top.
- `push()` adds an element to the stack, and `pop()` removes the top element.

**Example of Hashtable and Enumerations:**
```java
import java.util.Hashtable;
import java.util.Enumeration;

public class HashtableExample {
    public static void main(String[] args) {
        Hashtable<String, Integer> hashtable = new Hashtable<>();
        hashtable.put("One", 1);
        hashtable.put("Two", 2);
        hashtable.put("Three", 3);

        Enumeration<String> keys = hashtable.keys();
        while (keys.hasMoreElements()) {
            String key = keys.nextElement();
            System.out.println("Key: " + key + ", Value: " + hashtable.get(key));
        }
    }
}
```

**Sample Output:**
```
Key: One, Value: 1
Key: Two, Value: 2
Key: Three, Value: 3
```

**Explanation:**
- `Hashtable` stores key-value pairs.
- `Enumeration` is used to iterate through the keys of the `Hashtable`.

**Example of Random Number Generation:**
```java
import java.util.Random;

public class RandomExample {
    public static void main(String[] args) {
        Random random = new Random();
        System.out.println("Random Integer: " + random.nextInt(100));
        System.out.println("Random Double: " + random.nextDouble());
        System.out.println("Random Boolean: " + random.nextBoolean());
    }
}
```

**Sample Output:**
```
Random Integer: 42
Random Double: 0.123456789
Random Boolean: true
```

**Explanation:**
- `Random` generates random numbers.
- `nextInt()` generates a random integer within a specified range.
- `nextDouble()` generates a random double between 0.0 and 1.0.
- `nextBoolean()` generates a random boolean value.

**Difference Between Vector and ArrayList:**
- `Vector` is synchronized, making it thread-safe, while `ArrayList` is not synchronized.
- `Vector` is slower than `ArrayList` due to synchronization overhead.

#### Summary
- The `java.lang` package provides essential classes like `Math` and wrapper classes for primitive types.
- Wrapper classes allow primitive types to be used as objects and provide utility methods.
- The `java.util` package includes core classes like `Vector`, `Stack`, `Hashtable`, and `Random`.
- `Vector` and `Stack` are dynamic data structures, while `Hashtable` is a synchronized key-value store.
- `Random` is used for generating random numbers.
- Understanding these core packages is crucial for effective Java programming.
