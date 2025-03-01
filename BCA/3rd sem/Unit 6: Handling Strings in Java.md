## Unit 6: Handling Strings in Java

Strings are one of the most commonly used data types in Java. They are used to represent a sequence of characters. Java provides a rich set of methods to handle strings, making it easy to manipulate and process text data.

### 1. **Creation of a String**

In Java, strings can be created in two ways:
- Using **String Literals**
- Using the **`new`** keyword

#### Lab 1: Creation of a String
```java
public class StringCreation {
    public static void main(String[] args) {
        // Using String Literal
        String str1 = "Hello, World!";
        
        // Using new Keyword
        String str2 = new String("Hello, Java!");
        
        System.out.println("String 1: " + str1);
        System.out.println("String 2: " + str2);
    }
}
```

#### Explanation:
- **String Literal**: When we create a string using double quotes (" "), Java automatically creates a String object and stores it in the String Pool (a special memory area for strings). If the string already exists in the pool, Java reuses it instead of creating a new object.
- **`new` Keyword**: When we create a string using the new keyword, Java creates a new String object in the heap memory, even if the same string already exists in the String Pool.

#### Output:
```
String 1: Hello, World!
String 2: Hello, Java!
```
### **Key Differences Between String Literal and `new` Keyword**

| **Aspect**          | **String Literal**                          | **`new` Keyword**                          |
|----------------------|---------------------------------------------|--------------------------------------------|
| **Memory Allocation** | Stored in the **String Pool**              | Stored in the **Heap Memory**              |
| **Object Reuse**     | Reuses existing objects in the String Pool  | Always creates a new object                |
| **Performance**      | More memory-efficient                       | Less memory-efficient                      |
| **Use Case**         | Preferred for fixed strings                 | Used when dynamic string creation is needed|

### Lab 2: Creation of a String
```java
public class StringCreationExample {
    public static void main(String[] args) {
        // Using String Literal
        String str1 = "Hello, World!";
        String str2 = "Hello, World!"; // Reuses the same object from the String Pool
        
        // Using new Keyword
        String str3 = new String("Hello, World!"); // Creates a new object in heap memory
        
        System.out.println("String 1: " + str1);
        System.out.println("String 2: " + str2);
        System.out.println("String 3: " + str3);
        
        // Check if str1 and str2 point to the same object
        System.out.println("Are str1 and str2 the same object? " + (str1 == str2));
        
        // Check if str1 and str3 point to the same object
        System.out.println("Are str1 and str3 the same object? " + (str1 == str3));
    }
}
```
Output:
```
String 1: Hello, World!
String 2: Hello, World!
String 3: Hello, World!
Are str1 and str2 the same object? true
Are str1 and str3 the same object? false
```
---

### 2. **Concatenation of Strings**

String concatenation is the process of combining two or more strings. In Java, we can concatenate strings using the `+` operator or the `concat()` method.

#### Lab 3: Concatenation of Strings
```java
public class StringConcatenation {
    public static void main(String[] args) {
        String str1 = "Hello";
        String str2 = "World";
        
        // Using + operator
        String result1 = str1 + " " + str2;
        
        // Using concat() method
        String result2 = str1.concat(" ").concat(str2);
        
        System.out.println("Result 1: " + result1);
        System.out.println("Result 2: " + result2);
    }
}
```

#### Explanation:
- The `+` operator is overloaded in Java to concatenate strings.
- The `concat()` method appends the specified string to the end of the current string.

#### Output:
```
Result 1: Hello World
Result 2: Hello World
```

---

### 3. **Conversion of a String**

Strings can be converted to other data types (e.g., `int`, `double`) and vice versa using wrapper classes.

#### Lab 4: Conversion of a String
```java
public class StringConversion {
    public static void main(String[] args) {
        // String to int
        String str1 = "123";
        int num1 = Integer.parseInt(str1);
        
        // int to String
        int num2 = 456;
        String str2 = Integer.toString(num2);
        
        System.out.println("String to int: " + num1);
        System.out.println("int to String: " + str2);
    }
}
```

#### Explanation:
- `Integer.parseInt()` converts a string to an integer.
- `Integer.toString()` converts an integer to a string.

#### Output:
```
String to int: 123
int to String: 456
```
### **Summary Table of String Conversion**  

| **Conversion Type**       | **Method Used**                  |  
|--------------------------|--------------------------------|  
| **String → int**         | `Integer.parseInt(str)`       |  
| **int → String**         | `Integer.toString(num)`, `String.valueOf(num)` |  
| **String → double**      | `Double.parseDouble(str)`     |  
| **double → String**      | `Double.toString(num)`        |  
| **String → boolean**     | `Boolean.parseBoolean(str)`  |  
| **boolean → String**     | `Boolean.toString(boolValue)` |  
| **String → char array**  | `toCharArray()`               |  
| **char array → String**  | `new String(charArray)`      |  
| **String → byte array**  | `getBytes()`                  |  
| **byte array → String**  | `new String(byteArray)`      |  
| **String → long**        | `Long.parseLong(str)`        |  
| **long → String**        | `Long.toString(num)`         |  
| **String → float**       | `Float.parseFloat(str)`      |  
| **float → String**       | `Float.toString(num)`        |  
| **String → BigInteger**  | `new BigInteger(str)`        |  
| **BigInteger → String**  | `bigInteger.toString()`      |  
| **String → BigDecimal**  | `new BigDecimal(str)`        |  
| **BigDecimal → String**  | `bigDecimal.toString()`      |  

---

### 4. **Changing Case**

Java provides methods to change the case of a string:
- `toUpperCase()`: Converts the string to uppercase.
- `toLowerCase()`: Converts the string to lowercase.

#### Lab 5: Changing Case
```java
public class ChangeCase {
    public static void main(String[] args) {
        String str = "Hello, World!";
        
        String upperCaseStr = str.toUpperCase();
        String lowerCaseStr = str.toLowerCase();
        
        System.out.println("Uppercase: " + upperCaseStr);
        System.out.println("Lowercase: " + lowerCaseStr);
    }
}
```

#### Output:
```
Uppercase: HELLO, WORLD!
Lowercase: hello, world!
```

---

### 5. **Character Extraction**

We can extract characters from a string using the `charAt()` method or by converting the string to a character array.

#### Lab 6: Character Extraction
```java
public class CharacterExtraction {
    public static void main(String[] args) {
        String str = "Java";
        
        // Using charAt()
        char ch1 = str.charAt(2); // Index starts from 0
        
        // Using toCharArray()
        char[] charArray = str.toCharArray();
        
        System.out.println("Character at index 2: " + ch1);
        System.out.println("Character Array: " + Arrays.toString(charArray)); //Character Array: [J, a, v, a]
        //String str = new String(charArray);
        //System.out.println(str);  // Output: Hello
    }
}
```

#### Output:
```
Character at index 2: v
Character Array: [J, a, v, a]
```

---

### 6. **String Comparison**

Strings can be compared using:
- `equals()`: Compares the content of two strings.
- `equalsIgnoreCase()`: Compares strings ignoring case.
- `compareTo()`: Compares strings lexicographically(based on the Unicode value of each character in the string). The Unicode value for 'H' is 72 and for 'h' is 104.
Since 'H' (72) is lexicographically smaller than 'h' (104), the compareTo() method will return a negative integer (specifically, -32, which is the difference in Unicode values between 'H' and 'h').

#### Lab 7: String Comparison
```java
public class StringComparison {
    public static void main(String[] args) {
        String str1 = "Hello";
        String str2 = "hello";
        
        System.out.println("equals(): " + str1.equals(str2));
        System.out.println("equalsIgnoreCase(): " + str1.equalsIgnoreCase(str2));
        System.out.println("compareTo(): " + str1.compareTo(str2));
    }
}
```

#### Output:
```
equals(): false
equalsIgnoreCase(): true
compareTo(): -32
```

---
## 7. **Searching Strings**
We can search for characters or substrings within a string using methods like `indexOf()` and `contains()`.

### Lab 8: Searching Strings
```java
public class Main {
    public static void main(String[] args) {
        String str = "Hello, World!";//main string

        // Search for a character
        int index = str.indexOf('W');
        System.out.println("Index of 'W': " + index);

        // Search for a substring
        boolean contains = str.contains("World");//sub-string
        System.out.println("Contains 'World': " + contains);
    }
}
```
**Output:**
```
Index of 'W': 7
Contains 'World': true
```
**Explanation:**
- `indexOf()` returns the index of the first occurrence of a character or substring.
- `contains()` returns `true` if the substring is found.

### **Summary of String Searching Methods:**

- **`indexOf()`**: Finds the first occurrence of a character or substring within a string.
- **`lastIndexOf()`**: Finds the last occurrence of a character or substring within a string.
- **`contains()`**: Checks if a specific substring exists within the string.
- **`startsWith()`**: Checks if the string starts with a given substring.
- **`endsWith()`**: Checks if the string ends with a specified substring.
- **`matches()`**: Checks if the string matches a given regular expression.

---

## 8. **Modifying Strings**
Strings in Java are immutable, which means once a string is created, it cannot be changed. However, we can create new strings with modifications using methods like `replace()`, `substring()`, and `trim()`.

### Lab 9: Modifying Strings
```java
public class Main {
    public static void main(String[] args) {
        String str = "  Hello, World!  ";

        // Replace characters
        String replacedStr = str.replace('o', 'x');// immutable: The original string 'str' remains unchanged but returns a new string with the modified value.
        System.out.println("Replaced: " + replacedStr);

        // Extract substring
        String substring = str.substring(7, 12);// immutable: The original string 'str' remains unchanged but returns a new string with the modified value.
        System.out.println("Substring: " + substring);

        // Trim whitespace
        String trimmedStr = str.trim();// immutable: The original string 'str' remains unchanged but returns a new string with the modified value.
        System.out.println("Trimmed: " + trimmedStr);
    }
}
```
**Output:**
```
Replaced:  Hellx, Wxrld!  
Substring: World
Trimmed: Hello, World!
```

**Explanation:**
- `replace()` replaces all occurrences of a character.
- `substring()` extracts a portion of the string.
- `trim()` removes leading and trailing whitespace.

### **Summary of String Modification Methods**:

- **`concat()`**: Concatenate two strings.
- **`replace()`**: Replace characters or substrings.
- **`toUpperCase()` and `toLowerCase()`**: Convert to uppercase or lowercase.
- **`trim()`**: Remove leading and trailing whitespace.
- **`substring()`**: Extract a portion of the string.
- **`replaceAll()` and `replaceFirst()`**: Replace based on regular expressions.
- **`split()`**: Split the string into an array of substrings.
- **`StringBuilder` and `StringBuffer`**: Use mutable strings for efficient modifications.
---

## 9. **String Buffer**
`StringBuffer` is a mutable sequence of characters. It is synchronized(thread-safe) and is used when we need to modify strings frequently.

### Lab 10: String Buffer
```java
public class Main {
    public static void main(String[] args) {
        StringBuffer sb = new StringBuffer("Hello");

        // Append to StringBuffer
        sb.append(", World!");//This modifies the original StringBuffer (mutable operation)
        System.out.println("After append: " + sb);

        // Insert into StringBuffer
        sb.insert(5, " Java");//This modifies the original StringBuffer (mutable operation)
        System.out.println("After insert: " + sb);

        // Reverse StringBuffer
        sb.reverse();//This modifies the original StringBuffer (mutable operation)
        System.out.println("After reverse: " + sb);
    }
}
```
**Output:**
```
After append: Hello, World!
After insert: Hello Java, World!
After reverse: !dlroW ,avaJ olleH
```
**Explanation:**
- `append()` adds text to the end.
- `insert()` inserts text at a specified position.
- `reverse()` reverses the string.

### **Summary of StringBuffer Methods**:

- **`append(String str)`**: Adds the specified string to the end of the `StringBuffer`.  
  - **Arguments**: `str` - The string to be appended.

- **`insert(int index, String str)`**: Inserts the specified string at the given index in the `StringBuffer`.  
  - **Arguments**: `index` - The index where the string should be inserted, `str` - The string to be inserted.

- **`delete(int start, int end)`**: Removes characters from the `StringBuffer` between the specified start and end indices.  
  - **Arguments**: `start` - The starting index, `end` - The ending index (exclusive).

- **`replace(int start, int end, String str)`**: Replaces characters between the specified start and end indices with a new string.  
  - **Arguments**: `start` - The starting index, `end` - The ending index (exclusive), `str` - The string to replace the characters.

- **`reverse()`**: Reverses the characters in the `StringBuffer`.  
  - **Arguments**: None.

- **`capacity()`**: Returns the current capacity of the `StringBuffer`.  
  - **Arguments**: None.

- **`length()`**: Returns the number of characters currently stored in the `StringBuffer`.  
  - **Arguments**: None.

- **`setLength(int newLength)`**: Sets the length of the `StringBuffer`, truncating or padding as needed.  
  - **Arguments**: `newLength` - The new length to set for the `StringBuffer`.

- **`ensureCapacity(int minimumCapacity)`**: Ensures the `StringBuffer` has at least the specified capacity.  
  - **Arguments**: `minimumCapacity` - The minimum capacity to ensure.

- **`charAt(int index)`**: Returns the character at the specified index.  
  - **Arguments**: `index` - The index of the character to retrieve.

- **`substring(int start, int end)`**: Extracts a substring from the `StringBuffer` and returns it as a new string.  
  - **Arguments**: `start` - The starting index, `end` - The ending index (exclusive).
---

### **Summary of What Students Learned in Unit 6: Handling Strings**

In this chapter, students gained a comprehensive understanding of how to work with strings in Java. Here's a summary of the key concepts covered:

---

### **1. Creation of a String**
- Strings can be created using:
  - **String Literals**: Stored in the **String Pool** for memory efficiency.
  - **`new` Keyword**: Creates a new object in the **heap memory**.
- Learned the difference between the two and when to use each.

---

### **2. Concatenation of Strings**
- Strings can be combined using:
  - The `+` operator.
  - The `concat()` method.
- Understood how concatenation works and its performance implications.

---

### **3. Conversion of a String**
- Learned how to convert:
  - Strings to other data types (e.g., `int`, `double`) using methods like `Integer.parseInt()`.
  - Other data types to strings using methods like `Integer.toString()`.

---

### **4. Changing Case**
- Explored methods to change the case of a string:
  - `toUpperCase()`: Converts the string to uppercase.
  - `toLowerCase()`: Converts the string to lowercase.

---

### **5. Character Extraction**
- Learned how to extract characters from a string using:
  - `charAt()`: Returns the character at a specific index.
  - `toCharArray()`: Converts the string to a character array.

---

### **6. String Comparison**
- Understood how to compare strings using:
  - `equals()`: Compares the content of two strings.
  - `equalsIgnoreCase()`: Compares strings while ignoring case.
  - `compareTo()`: Compares strings lexicographically.

---

### **7. Searching Strings**
- Explored methods to search within a string:
  - `indexOf()`: Returns the index of the first occurrence of a character or substring.
  - `lastIndexOf()`: Returns the index of the last occurrence.
  - `contains()`: Checks if a substring exists in the string.

---

### **8. Modifying Strings**
- Learned how to "modify" strings (though strings are immutable, methods return new strings):
  - `replace()`: Replaces characters or substrings.
  - `substring()`: Extracts a portion of the string.
  - `trim()`: Removes leading and trailing whitespace.

---

### **9. String Buffer**
- Introduced to mutable string classes:
  - `StringBuffer`: A thread-safe, mutable sequence of characters.
  - `StringBuilder`: A non-thread-safe, mutable sequence of characters (faster than `StringBuffer`).
- Learned how to use methods like `append()`, `insert()`, and `reverse()` to modify strings efficiently.

---

### **Key Takeaways**
1. **Immutability of Strings**:
   - Strings in Java are immutable, meaning their values cannot be changed after creation.
   - Methods like `toUpperCase()`, `replace()`, etc., return new strings rather than modifying the original.

2. **String Pool**:
   - Strings created using literals are stored in the **String Pool**, which helps save memory by reusing existing strings.

3. **Mutable vs Immutable**:
   - For fixed strings, use the `String` class.
   - For dynamic string manipulation, use `StringBuilder` or `StringBuffer`.

4. **Common String Operations**:
   - Students learned how to create, concatenate, convert, compare, search, and modify strings effectively.

---
