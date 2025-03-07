## Unit 10: Holding Collection of Data in Java

#### 1. **Arrays**
Arrays are fixed-size data structures that store elements of the same type. They provide indexed access to elements.

**Example:**
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

#### 2. **Collection Classes/Interfaces**
The Java Collections Framework provides interfaces and classes to store and manipulate groups of objects. The main interfaces are `Collection`, `List`, `Set`, and `Map`.

##### **Map Interface**
The `Map` interface stores key-value pairs. Each key is unique, and it maps to a single value.

**Example:**
```java
import java.util.HashMap;
import java.util.Map;

public class MapExample {
    public static void main(String[] args) {
        Map<String, Integer> map = new HashMap<>();
        map.put("Apple", 10);
        map.put("Banana", 20);
        map.put("Cherry", 30);

        System.out.println("Map: " + map);
        System.out.println("Value for key 'Banana': " + map.get("Banana"));
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

##### **List Interface**
The `List` interface stores an ordered collection of elements. It allows duplicate elements.

**Example:**
```java
import java.util.ArrayList;
import java.util.List;

public class ListExample {
    public static void main(String[] args) {
        List<String> list = new ArrayList<>();
        list.add("Apple");
        list.add("Banana");
        list.add("Cherry");

        System.out.println("List: " + list);
        System.out.println("Element at index 1: " + list.get(1));
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

##### **Set Interface**
The `Set` interface stores a collection of unique elements. It does not allow duplicates.

**Example:**
```java
import java.util.HashSet;
import java.util.Set;

public class SetExample {
    public static void main(String[] args) {
        Set<String> set = new HashSet<>();
        set.add("Apple");
        set.add("Banana");
        set.add("Cherry");
        set.add("Apple"); // Duplicate, will not be added

        System.out.println("Set: " + set);
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

#### 3. **Collection Classes**
##### **ArrayList**
`ArrayList` is a resizable array implementation of the `List` interface.

**Example:**
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

##### **LinkedList**
`LinkedList` is a doubly-linked list implementation of the `List` interface.

**Example:**
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

##### **HashSet**
`HashSet` is a hash table implementation of the `Set` interface.

**Example:**
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

##### **TreeSet**
`TreeSet` is a red-black tree implementation of the `Set` interface. It stores elements in sorted order.

**Example:**
```java
import java.util.TreeSet;

public class TreeSetExample {
    public static void main(String[] args) {
        TreeSet<String> set = new TreeSet<>();
        set.add("Apple");
        set.add("Banana");
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

#### 4. **Accessing Collections/Use of an Iterator**
An `Iterator` is used to traverse through a collection.

**Example:**
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

#### 5. **Comparator**
The `Comparator` interface is used to define custom sorting logic for objects.

**Example:**
```java
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class ComparatorExample {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();
        list.add("Apple");
        list.add("Banana");
        list.add("Cherry");

        // Sort in reverse order
        Collections.sort(list, new Comparator<String>() {
            @Override
            public int compare(String s1, String s2) {
                return s2.compareTo(s1);
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

#### Difference Between `List`, `Set`, and `Map`
- **List**: Ordered collection that allows duplicates.
- **Set**: Unordered collection that does not allow duplicates.
- **Map**: Stores key-value pairs. Keys are unique.

#### Summary
- Arrays are fixed-size data structures for storing elements of the same type.
- The Java Collections Framework provides interfaces like `List`, `Set`, and `Map` for storing collections of objects.
- `ArrayList` and `LinkedList` are implementations of the `List` interface.
- `HashSet` and `TreeSet` are implementations of the `Set` interface.
- `Iterator` is used to traverse through collections.
- `Comparator` is used to define custom sorting logic.
- Understanding these concepts is essential for effective data management in Java.
