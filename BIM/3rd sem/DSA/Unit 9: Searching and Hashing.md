### Unit 9: Searching and Hashing (5 LHs)

#### 1. **Introduction**
   - **Searching** is the process of finding a specific element in a collection of data (e.g., arrays, lists, or databases).
   - **Hashing** is a technique used to map data to a fixed-size table (hash table) for efficient retrieval.
   - Both searching and hashing are fundamental operations in computer science, widely used in databases, compilers, and algorithms.

---

#### 2. **Linear Search**
   - **Definition**: Linear search is a simple searching algorithm that checks each element in a collection sequentially until the target element is found or the end of the collection is reached.
   - **Steps**:
     1. Start from the first element.
     2. Compare the target element with each element in the collection.
     3. If a match is found, return the index of the element.
     4. If no match is found after traversing the entire collection, return -1.
   - **Efficiency**:
     - **Time Complexity**: O(n) in the worst case, where n is the number of elements.
     - **Best Case**: O(1) if the target is the first element.
     - **Worst Case**: O(n) if the target is the last element or not present.
   - **Use Case**: Suitable for small or unsorted datasets.

---

#### 3. **Binary Search**
   - **Definition**: Binary search is an efficient searching algorithm that works on sorted collections. It repeatedly divides the search interval in half.
   - **Steps**:
     1. Start with the middle element of the sorted collection.
     2. If the middle element matches the target, return its index.
     3. If the target is less than the middle element, search the left half.
     4. If the target is greater than the middle element, search the right half.
     5. Repeat until the target is found or the interval is empty.
   - **Efficiency**:
     - **Time Complexity**: O(log n) in the worst case.
     - **Best Case**: O(1) if the target is the middle element.
     - **Worst Case**: O(log n) if the target is at the beginning or end.
   - **Use Case**: Suitable for large, sorted datasets.

---

#### 4. **Efficiency of Searching Algorithms**
   - **Linear Search**:
     - Simple to implement.
     - Works on both sorted and unsorted data.
     - Inefficient for large datasets due to O(n) time complexity.
   - **Binary Search**:
     - Requires sorted data.
     - Highly efficient for large datasets with O(log n) time complexity.
   - **Comparison**:
     - Binary search is faster than linear search for large datasets.
     - Linear search is more flexible as it does not require sorted data.

---

#### 5. **Hashing**
   - **Definition**: Hashing is a technique to map data of arbitrary size to fixed-size values (hash codes) using a hash function. The mapped values are stored in a hash table for quick access.
   - **Hash Table**: A data structure that stores key-value pairs, where keys are mapped to indices using a hash function.
   - **Advantages**:
     - Fast access to data (average time complexity of O(1) for search, insert, and delete operations).
     - Efficient for large datasets.
   - **Disadvantages**:
     - Collisions can occur when two keys map to the same index.
     - Requires a good hash function to minimize collisions.

---

#### 6. **Hash Functions**
   - A hash function converts a key into an index for storing or retrieving data in a hash table.
   - **Properties of a Good Hash Function**:
     - Uniform distribution of keys across the hash table.
     - Minimizes collisions.
     - Computationally efficient.
   - **Types of Hash Functions**:
     1. **Division Method**:
        - Formula: `hash(key) = key % table_size`
        - Example: If the key is 23 and the table size is 10, the hash value is 3.
        - Suitable when the table size is a prime number to reduce collisions.
     2. **Folding Method**:
        - The key is divided into parts, and the parts are added or combined to produce the hash value.
        - Example: For key 123456, split into 12, 34, 56, and add them to get 102.
     3. **Mid-Square Method**:
        - Square the key and extract the middle digits as the hash value.
        - Example: For key 123, square it to get 15129, and extract the middle digits (e.g., 512).
     4. **Extraction Method**:
        - Select specific digits or characters from the key to form the hash value.
        - Example: For key 123456, extract the first and last digits to get 16.

---

#### 7. **Collision Resolution Techniques**
   - **Collision**: Occurs when two different keys produce the same hash value.
   - **Techniques**:
     1. **Separate Chaining**:
        - Each bucket in the hash table stores a linked list of key-value pairs.
        - Colliding keys are stored in the same bucket as a linked list.
     2. **Open Addressing**:
        - All elements are stored in the hash table itself.
        - Techniques include:
          - **Linear Probing**: Search for the next available slot sequentially.
          - **Quadratic Probing**: Use a quadratic function to find the next slot.
          - **Double Hashing**: Use a second hash function to compute the next slot.
     3. **Robin Hood Hashing**:
        - A variation of open addressing where keys with shorter probe sequences are moved closer to their original hash index.

---

#### 8. **Hashing in java.util**
   - Java provides built-in support for hashing through classes like `HashMap`, `HashSet`, and `Hashtable`.
   - **HashMap**:
     - Implements the Map interface using a hash table.
     - Allows null keys and values.
     - Example: `HashMap<String, Integer> map = new HashMap<>();`
   - **HashSet**:
     - Implements the Set interface using a hash table.
     - Stores unique elements.
     - Example: `HashSet<String> set = new HashSet<>();`
   - **Hashtable**:
     - Similar to `HashMap` but synchronized (thread-safe).
     - Does not allow null keys or values.
     - Example: `Hashtable<String, Integer> table = new Hashtable<>();`
   - **Hashing in Java**:
     - Java uses the `hashCode()` method to compute hash values for objects.
     - The `equals()` method is used to handle collisions and compare keys.

---

#### Summary
- **Searching** involves finding elements in a collection, with linear search being simple but inefficient for large datasets, and binary search being efficient but requiring sorted data.
- **Hashing** is a technique for fast data retrieval using hash functions and hash tables.
- **Collision resolution** techniques like separate chaining and open addressing are used to handle collisions in hash tables.
- Java provides built-in support for hashing through classes like `HashMap`, `HashSet`, and `Hashtable`.
