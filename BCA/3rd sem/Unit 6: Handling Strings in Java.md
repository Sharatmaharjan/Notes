## Unit 6: Handling Strings in Java

Strings are one of the most commonly used data types in Java. They are used to represent a sequence of characters. Java provides a rich set of methods to handle strings, making it easy to manipulate and process text data.

### 1. **Creation of a String**

In Java, strings can be created in two ways:
- Using **String Literals**
- Using the **`new`** keyword

#### Example:
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
- **String Literal**: When you create a string using double quotes (" "), Java automatically creates a String object and stores it in the String Pool (a special memory area for strings). If the string already exists in the pool, Java reuses it instead of creating a new object.
- **`new` Keyword**: When you create a string using the new keyword, Java creates a new String object in the heap memory, even if the same string already exists in the String Pool.

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

### Extra:
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

String concatenation is the process of combining two or more strings. In Java, you can concatenate strings using the `+` operator or the `concat()` method.

#### Example:
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

#### Example:
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

#### Example:
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

You can extract characters from a string using the `charAt()` method or by converting the string to a character array.

#### Example:
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

#### Example:
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
You can search for characters or substrings within a string using methods like `indexOf()` and `contains()`.

### Example: Searching Strings
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
Strings in Java are immutable, which means once a string is created, it cannot be changed. However, you can create new strings with modifications using methods like `replace()`, `substring()`, and `trim()`.

### Example: Modifying Strings
```java
public class Main {
    public static void main(String[] args) {
        String str = "  Hello, World!  ";

        // Replace characters
        String replacedStr = str.replace('o', 'x');// immutable: The original string 'str' remains unchanged but returns a new string with the modified value.
        System.out.println("Replaced: " + replacedStr);

        // Extract substring
        String substring = str.substring(7, 12);
        System.out.println("Substring: " + substring);

        // Trim whitespace
        String trimmedStr = str.trim();
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
`StringBuffer` is a mutable sequence of characters. It is thread-safe and is used when you need to modify strings frequently.

### Example: String Buffer
```java
public class Main {
    public static void main(String[] args) {
        StringBuffer sb = new StringBuffer("Hello");

        // Append to StringBuffer
        sb.append(", World!");
        System.out.println("After append: " + sb);

        // Insert into StringBuffer
        sb.insert(5, " Java");
        System.out.println("After insert: " + sb);

        // Reverse StringBuffer
        sb.reverse();
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

---

## Summary
- **Creation**: Use string literals or the `new` keyword.
- **Concatenation**: Use `+` or `concat()`.
- **Conversion**: Use methods like `Integer.parseInt()` and `Double.parseDouble()`.
- **Changing Case**: Use `toUpperCase()` and `toLowerCase()`.
- **Character Extraction**: Use `charAt()`.
- **Comparison**: Use `equals()`, `equalsIgnoreCase()`, and `compareTo()`.
- **Searching**: Use `indexOf()` and `contains()`.
- **Modifying**: Use `replace()`, `substring()`, and `trim()`.
- **StringBuffer**: Use for mutable strings with methods like `append()`, `insert()`, and `reverse()`.
