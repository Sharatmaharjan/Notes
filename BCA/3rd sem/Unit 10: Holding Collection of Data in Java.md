## Unit 10: Holding Collection of Data in Java

### 1. **Arrays**
Arrays are fixed-size data structures that store elements of the same type. They provide indexed access to elements.

**Lab 1: Arrays**
```java
public class ArrayExample {
    public static void main(String[] args) {
        int[] numbers = {10, 20, 30, 40, 50};

        for (int i = 0; i < numbers.length; i++) {
            System.out.println("Element at index " + i + ": " + numbers[i]);
        }
    }
}
```

**Sample Output:**
```
Element at index 0: 10
Element at index 1: 20
Element at index 2: 30
Element at index 3: 40
Element at index 4: 50
```

**Explanation:**
- Arrays store elements of the same type in a contiguous memory location.
- Elements are accessed using an index.
- The `length` property gives the size of the array.

---

### 2. **Collection Classes/Interfaces**
The Java Collections Framework provides interfaces and classes to store and manipulate groups of objects. The main interfaces are `Collection`, `List`, `Set`, and `Map`.

**a. List Interface**

The `List` interface stores an ordered collection(sequence or arrangement of elements is preserved) of elements. It allows duplicate elements.

**Lab 2: List Interface**
```java
import java.util.ArrayList;
import java.util.List;

public class ListExample {
    public static void main(String[] args) {
        List<String> list = new ArrayList<>();    // List is an interface, so we declare the variable as type List and ArrayList is a class that implements the List interface.

        // Add elements to the list (maintains insertion order)
        list.add("Apple");   // Adds "Apple" to the list
        list.add("Banana");  // Adds "Banana" to the list
        list.add("Cherry");  // Adds "Cherry" to the list

        // Print the entire list (List maintains the order of elements)
        System.out.println("List: " + list); // Output: [Apple, Banana, Cherry]

        // Access an element by index using the get() method
        // Note: Indexing starts from 0, so index 1 refers to the second element
        System.out.println("Element at index 1: " + list.get(1)); // Output: Banana
    }
}
```

**Sample Output:**
```
List: [Apple, Banana, Cherry]
Element at index 1: Banana
```

**Explanation:**
- `List` stores elements in an ordered sequence.
- `add()` adds an element to the list.
- `get()` retrieves an element by its index.

**Iterating through a `List`:**
```java
    // Using Iterator
Iterator<String> iterator = list.iterator(); // Step 1: Obtain an Iterator for the list->The Iterator object created by list.iterator() holds a reference to the original list
while (iterator.hasNext()) {                 // Step 2: Check if there are more elements
    System.out.println(iterator.next());    // Step 3: Retrieve and process the next element
}
    
    // Using For-Each Loop
    for (String element : list) {
        System.out.println(element);
    }
```

**b. Set Interface**

The `Set` interface stores a collection of unique elements. It does not allow duplicates.

**Lab 3: Set Interface**
```java
import java.util.HashSet;
import java.util.Set;

public class SetExample {
    public static void main(String[] args) {
        Set<String> set = new HashSet<>();     // Set is an interface, so we declare the variable as type Set and HashSet is a class that implements the Set interface

        // Add elements to the set
        set.add("Apple");   // Adds "Apple" to the set
        set.add("Banana");  // Adds "Banana" to the set
        set.add("Cherry");  // Adds "Cherry" to the set

        // Attempt to add a duplicate element ("Apple")
        // Since Set does not allow duplicates, this will not be added
        set.add("Apple");

        // Print the entire set
        // Note: HashSet does not guarantee any specific order of elements
        System.out.println("Set: " + set); // Output may vary, e.g., [Apple, Banana, Cherry] or [Banana, Cherry, Apple]
    }
}
```

**Sample Output:**
```
Set: [Apple, Banana, Cherry]
```

**Explanation:**
- `Set` stores unique elements.
- `add()` adds an element to the set if it is not already present.

**Iterating through a `Set`:**
```java
    // Using Iterator
    Iterator<String> iterator = set.iterator();
    while (iterator.hasNext()) {
        System.out.println(iterator.next());
    }
    
    // Using For-Each Loop
    for (String element : set) {
        System.out.println(element);
    }
```

**c. Map Interface**

The `Map` interface stores key-value pairs. Each key is unique, and it maps to a single value.

**Lab 4: Map Interface**
```java
import java.util.HashMap;
import java.util.Map;

public class MapExample {
    public static void main(String[] args) {
        Map<String, Integer> map = new HashMap<>();    // Map is an interface, so we declare the variable as type Map and HashMap is a class that implements the Map interface

        // Add key-value pairs to the map using the put() method
        map.put("Apple", 10);   // Associates "Apple" with the value 10
        map.put("Banana", 20);  // Associates "Banana" with the value 20
        map.put("Cherry", 30);  // Associates "Cherry" with the value 30

        // Print the entire map
        // Note: HashMap does not guarantee any specific order of entries
        System.out.println("Map: " + map); // Output may vary, e.g., {Apple=10, Banana=20, Cherry=30} or {Banana=20, Cherry=30, Apple=10}

        // Retrieve the value associated with a specific key using the get() method
        System.out.println("Value for key 'Banana': " + map.get("Banana")); // Output: 20
    }
}
```

**Sample Output:**
```
Map: {Apple=10, Banana=20, Cherry=30}
Value for key 'Banana': 20
```

**Explanation:**
- `Map` stores key-value pairs.
- `put()` adds a key-value pair to the map.
- `get()` retrieves the value associated with a key.

**Iterating through `Map`:**

Must decide whether to iterate over:
    - Keys : Use keySet()
    - Values : Use values().
    - Entries (Key-Value Pairs) : Use entrySet()

```java

    // Using For-Each Loop on keySet()
    for (String key : map.keySet()) {
        System.out.println("Key: " + key + ", Value: " + map.get(key));
    }

    // Using For-Each Loop on values()
    for (Integer value : map.values()) {
        System.out.println("Value: " + value);    //cannot directly retrieve keys using the values() method. The Map interface is designed for efficient forward lookups (key → value), not reverse lookups (value → key).

    }

    // Using Iterator on entrySet()
    Iterator<Map.Entry<String, Integer>> iterator = map.entrySet().iterator();
    while (iterator.hasNext()) {
        Map.Entry<String, Integer> entry = iterator.next();
        System.out.println("Key: " + entry.getKey() + ", Value: " + entry.getValue());
    }
    
    // Using For-Each Loop on entrySet()
    for (Map.Entry<String, Integer> entry : map.entrySet()) {
        System.out.println("Key: " + entry.getKey() + ", Value: " + entry.getValue());
    }
    
```


**Comparison of `List`, `Set`, and `Map`**

| **Feature**               | **List**                                      | **Set**                                       | **Map**                                       |
|---------------------------|-----------------------------------------------|-----------------------------------------------|-----------------------------------------------|
| **Ordering**              | Maintains **insertion order**.                | May or may not maintain order (depends on implementation). | No inherent order (except in `LinkedHashMap` or `TreeMap`). |
| **Duplicates**            | Allows **duplicate elements**.                | Does **not allow duplicates**.                | Keys are unique; values can be duplicated.    |
| **Access by Index/Key**   | Accessed by **index** (`get(index)`).         | No index-based access.                        | Accessed by **key** (`get(key)`).             |
| **Null Elements**         | Allows multiple `null` values.                | Allows at most one `null` value.              | Allows one `null` key (except in `Hashtable`) and multiple `null` values. |
| **Use Case**              | Ordered storage with duplicates (e.g., lists of items). | Unique elements (e.g., removing duplicates). | Key-value associations (e.g., dictionaries, caches). |


---

### 3. **Collection Classes**

**a. ArrayList**

`ArrayList` is a resizable array implementation of the `List` interface.

**Lab 5: ArrayList**
```java
import java.util.ArrayList;

public class ArrayListExample {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();
        list.add("Apple");
        list.add("Banana");
        list.add("Cherry");

        System.out.println("ArrayList: " + list);
    }
}
```

**Sample Output:**
```
ArrayList: [Apple, Banana, Cherry]
```

**Explanation:**
- `ArrayList` dynamically resizes itself as elements are added.
- It provides fast access to elements using an index.

**b. LinkedList**

`LinkedList` is a doubly-linked list implementation of the `List` interface.

**Lab 6: LinkedList**
```java
import java.util.LinkedList;

public class LinkedListExample {
    public static void main(String[] args) {
        LinkedList<String> list = new LinkedList<>();
        list.add("Apple");
        list.add("Banana");
        list.add("Cherry");

        System.out.println("LinkedList: " + list);
    }
}
```

**Sample Output:**
```
LinkedList: [Apple, Banana, Cherry]
```

**Explanation:**
- `LinkedList` stores elements as nodes, each pointing to the next and previous nodes.
- It is efficient for adding and removing elements at both ends.

**c. HashSet**

`HashSet` is a hash table implementation of the `Set` interface.    (The Hashtable is synchronized, while HashSet and HashMap are not.)

**Lab 7: HashSet**
```java
import java.util.HashSet;

public class HashSetExample {
    public static void main(String[] args) {
        HashSet<String> set = new HashSet<>();
        set.add("Apple");
        set.add("Banana");
        set.add("Cherry");
        set.add("Apple"); // Duplicate, will not be added

        System.out.println("HashSet: " + set);
    }
}
```

**Sample Output:**
```
HashSet: [Apple, Banana, Cherry]
```

**Explanation:**
- `HashSet` stores unique elements using a hash table.
- It provides constant-time performance for basic operations.

**d. TreeSet**

`TreeSet` is a red-black tree implementation of the `Set` interface. It stores elements in sorted order.

**Lab 8: TreeSet**
```java
import java.util.TreeSet;

public class TreeSetExample {
    public static void main(String[] args) {
        TreeSet<String> set = new TreeSet<>();
        set.add("Banana");
        set.add("Apple");
        set.add("Cherry");

        System.out.println("TreeSet: " + set);
    }
}
```

**Sample Output:**
```
TreeSet: [Apple, Banana, Cherry]
```

**Explanation:**
- `TreeSet` stores elements in sorted order.
- It provides logarithmic-time performance for basic operations.

---

### 4. **Accessing Collections/Use of an Iterator**

An `Iterator` is used to traverse through a collection.

**Lab 9: Accessing Collections/Use of an Iterator**
```java
import java.util.ArrayList;
import java.util.Iterator;

public class IteratorExample {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();
        list.add("Apple");
        list.add("Banana");
        list.add("Cherry");

        Iterator<String> iterator = list.iterator();
        while (iterator.hasNext()) {
            System.out.println(iterator.next());
        }
    }
}
```

**Sample Output:**
```
Apple
Banana
Cherry
```

**Explanation:**
- `Iterator` provides methods to traverse through a collection.
- `hasNext()` checks if there are more elements.
- `next()` retrieves the next element.

### 5. **Comparator**

The `Comparator` interface is used to define custom sorting logic for objects.

**Lab 10: Comparator**
```java
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class ListExample {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();
        list.add("Apple");
        list.add("Banana");
        list.add("Cherry");

        // Sort in reverse order
        list.sort(new Comparator<String>() {
            @Override
            public int compare(String s1, String s2) {
                return s2.compareTo(s1);    //return s1.compareTo(s2); -> sort alphabetical order
            }
        });

        System.out.println("Sorted List: " + list);
    }
}
```

**Sample Output:**
```
Sorted List: [Cherry, Banana, Apple]
```

**Explanation:**
- `Comparator` defines custom sorting logic.
- `compare()` compares two objects for ordering.

---

### Summary
- Arrays are fixed-size data structures for storing elements of the same type.
- The Java Collections Framework provides interfaces like `List`, `Set`, and `Map` for storing collections of objects.
- `ArrayList` and `LinkedList` are implementations of the `List` interface.
- `HashSet` and `TreeSet` are implementations of the `Set` interface.
- `Iterator` is used to traverse through collections.
- `Comparator` is used to define custom sorting logic.
