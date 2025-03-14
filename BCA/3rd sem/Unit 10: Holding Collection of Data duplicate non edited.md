## Unit 10: Holding Collection of Data [3 Hrs.]

In this unit, we will explore how to hold collections of data in Java using arrays and collection classes/interfaces. We will discuss the `Map`, `List`, and `Set` interfaces, along with their implementations such as `ArrayList`, `LinkedList`, `HashSet`, and `TreeSet`. Additionally, we will learn how to access collections using iterators and how to use the `Comparator` interface for sorting.

---

### 1. Arrays in Java

**Definition**:  
An array is a fixed-size data structure that holds elements of the same type. It provides indexed access to its elements.

**Program Example**:
```java
public class ArrayExample {
    public static void main(String[] args) {
        // Declare and initialize an array
        int[] numbers = {10, 20, 30, 40, 50};

        // Access and print elements
        for (int i = 0; i < numbers.length; i++) {
            System.out.println("Element at index " + i + ": " + numbers[i]);
        }
    }
}
```

**Explanation**:  
- We declare an array `numbers` of type `int` and initialize it with values.
- We use a `for` loop to iterate through the array and print each element.

**Sample Output**:
```
Element at index 0: 10
Element at index 1: 20
Element at index 2: 30
Element at index 3: 40
Element at index 4: 50
```

---

### 2. Collection Interfaces and Classes

#### a. **Map Interface**
**Definition**:  
The `Map` interface represents a collection of key-value pairs. Each key is unique, and it maps to exactly one value.

**Program Example**:
```java
import java.util.HashMap;
import java.util.Map;

public class MapExample {
    public static void main(String[] args) {
        // Create a HashMap
        Map<String, Integer> map = new HashMap<>();

        // Add key-value pairs
        map.put("Apple", 10);
        map.put("Banana", 20);
        map.put("Cherry", 30);

        // Access and print values
        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }
}
```

**Explanation**:  
- We use `HashMap` to implement the `Map` interface.
- We add key-value pairs using the `put` method and iterate through the map using `entrySet`.

**Sample Output**:
```
Apple: 10
Banana: 20
Cherry: 30
```

---

#### b. **List Interface**
**Definition**:  
The `List` interface represents an ordered collection of elements. It allows duplicate elements and provides indexed access.

**Program Example**:
```java
import java.util.ArrayList;
import java.util.List;

public class ListExample {
    public static void main(String[] args) {
        // Create an ArrayList
        List<String> list = new ArrayList<>();

        // Add elements
        list.add("Java");
        list.add("Python");
        list.add("C++");

        // Access and print elements
        for (String language : list) {
            System.out.println(language);
        }
    }
}
```

**Explanation**:  
- We use `ArrayList` to implement the `List` interface.
- We add elements using the `add` method and iterate through the list using a `for-each` loop.

**Sample Output**:
```
Java
Python
C++
```

---

#### c. **Set Interface**
**Definition**:  
The `Set` interface represents a collection of unique elements. It does not allow duplicates.

**Program Example**:
```java
import java.util.HashSet;
import java.util.Set;

public class SetExample {
    public static void main(String[] args) {
        // Create a HashSet
        Set<String> set = new HashSet<>();

        // Add elements
        set.add("Apple");
        set.add("Banana");
        set.add("Apple"); // Duplicate, will not be added

        // Access and print elements
        for (String fruit : set) {
            System.out.println(fruit);
        }
    }
}
```

**Explanation**:  
- We use `HashSet` to implement the `Set` interface.
- We add elements using the `add` method. Duplicates are automatically ignored.

**Sample Output**:
```
Apple
Banana
```

---

### 3. Collection Classes

#### a. **ArrayList**
**Definition**:  
`ArrayList` is a resizable array implementation of the `List` interface. It allows dynamic addition and removal of elements.

**Program Example**:
```java
import java.util.ArrayList;

public class ArrayListExample {
    public static void main(String[] args) {
        // Create an ArrayList
        ArrayList<String> fruits = new ArrayList<>();

        // Add elements
        fruits.add("Apple");
        fruits.add("Banana");
        fruits.add("Cherry");

        // Access and print elements
        for (String fruit : fruits) {
            System.out.println(fruit);
        }
    }
}
```

**Explanation**:  
- `ArrayList` is dynamic and can grow or shrink in size.
- We use the `add` method to insert elements and a `for-each` loop to iterate.

**Sample Output**:
```
Apple
Banana
Cherry
```

---

#### b. **LinkedList**
**Definition**:  
`LinkedList` is a doubly-linked list implementation of the `List` interface. It is efficient for frequent insertions and deletions.

**Program Example**:
```java
import java.util.LinkedList;

public class LinkedListExample {
    public static void main(String[] args) {
        // Create a LinkedList
        LinkedList<String> colors = new LinkedList<>();

        // Add elements
        colors.add("Red");
        colors.add("Green");
        colors.add("Blue");

        // Access and print elements
        for (String color : colors) {
            System.out.println(color);
        }
    }
}
```

**Explanation**:  
- `LinkedList` is ideal for scenarios where we need frequent modifications.
- We use the `add` method to insert elements and a `for-each` loop to iterate.

**Sample Output**:
```
Red
Green
Blue
```

---

#### c. **HashSet**
**Definition**:  
`HashSet` is an implementation of the `Set` interface that uses a hash table for storage. It does not allow duplicates.

**Program Example**:
```java
import java.util.HashSet;

public class HashSetExample {
    public static void main(String[] args) {
        // Create a HashSet
        HashSet<String> cities = new HashSet<>();

        // Add elements
        cities.add("New York");
        cities.add("London");
        cities.add("Paris");
        cities.add("New York"); // Duplicate, will not be added

        // Access and print elements
        for (String city : cities) {
            System.out.println(city);
        }
    }
}
```

**Explanation**:  
- `HashSet` ensures uniqueness of elements.
- We use the `add` method to insert elements and a `for-each` loop to iterate.

**Sample Output**:
```
New York
London
Paris
```

---

#### d. **TreeSet**
**Definition**:  
`TreeSet` is an implementation of the `Set` interface that stores elements in a sorted order.

**Program Example**:
```java
import java.util.TreeSet;

public class TreeSetExample {
    public static void main(String[] args) {
        // Create a TreeSet
        TreeSet<String> animals = new TreeSet<>();

        // Add elements
        animals.add("Lion");
        animals.add("Tiger");
        animals.add("Elephant");

        // Access and print elements
        for (String animal : animals) {
            System.out.println(animal);
        }
    }
}
```

**Explanation**:  
- `TreeSet` sorts elements in natural order.
- We use the `add` method to insert elements and a `for-each` loop to iterate.

**Sample Output**:
```
Elephant
Lion
Tiger
```

---

### 4. Accessing Collections Using Iterator

**Definition**:  
An `Iterator` is an object that allows us to traverse through a collection and access its elements.

**Program Example**:
```java
import java.util.ArrayList;
import java.util.Iterator;

public class IteratorExample {
    public static void main(String[] args) {
        // Create an ArrayList
        ArrayList<String> colors = new ArrayList<>();
        colors.add("Red");
        colors.add("Green");
        colors.add("Blue");

        // Use Iterator to access elements
        Iterator<String> iterator = colors.iterator();
        while (iterator.hasNext()) {
            System.out.println(iterator.next());
        }
    }
}
```

**Explanation**:  
- We use the `iterator` method to obtain an `Iterator` object.
- The `hasNext` method checks if there are more elements, and `next` retrieves the next element.

**Sample Output**:
```
Red
Green
Blue
```

---

### 5. Comparator Interface

**Definition**:  
The `Comparator` interface is used to define custom sorting logic for objects.

**Program Example**:
```java
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class ComparatorExample {
    public static void main(String[] args) {
        // Create an ArrayList
        ArrayList<String> fruits = new ArrayList<>();
        fruits.add("Apple");
        fruits.add("Banana");
        fruits.add("Cherry");

        // Sort using a custom Comparator
        Collections.sort(fruits, new Comparator<String>() {
            @Override
            public int compare(String fruit1, String fruit2) {
                return fruit2.compareTo(fruit1); // Sort in descending order
            }
        });

        // Print sorted list
        for (String fruit : fruits) {
            System.out.println(fruit);
        }
    }
}
```

**Explanation**:  
- We use the `Comparator` interface to define a custom sorting order.
- The `compare` method compares two elements and returns a negative, zero, or positive integer.

**Sample Output**:
```
Cherry
Banana
Apple
```

---

### Differences Between Collection Implementations

| Feature               | ArrayList          | LinkedList         | HashSet            | TreeSet            |
|-----------------------|--------------------|--------------------|--------------------|--------------------|
| **Order**             | Insertion Order    | Insertion Order    | No Order           | Sorted Order       |
| **Duplicates**        | Allowed            | Allowed            | Not Allowed        | Not Allowed        |
| **Performance**       | Fast Access        | Fast Insert/Delete | Fast Lookup        | Slow Insert/Delete |
| **Use Case**          | Frequent Access    | Frequent Modifications | Unique Elements  | Sorted Unique Elements |

---

### Summary

In this unit, we explored various ways to hold collections of data in Java. We learned about arrays, which are fixed-size and indexed, and collection classes/interfaces like `Map`, `List`, and `Set`. We also examined implementations such as `ArrayList`, `LinkedList`, `HashSet`, and `TreeSet`, each with its unique characteristics. Additionally, we discussed how to access collections using iterators and how to use the `Comparator` interface for custom sorting. By understanding these concepts, we can choose the appropriate data structure for our specific needs and write efficient Java programs.
