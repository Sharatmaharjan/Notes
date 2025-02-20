# Unit 6: Handling Strings in Java

Strings are one of the most commonly used data types in Java. They are objects of the `String` class and are immutable (cannot be changed once created). Java also provides the `StringBuffer` and `StringBuilder` classes for mutable strings. This unit covers various operations on strings, including creation, concatenation, conversion, and manipulation.

---

## 1. **Creation of a String**
Strings can be created in two ways:
- Using string literals (stored in the string pool).
- Using the `new` keyword (creates a new object in the heap memory).

### Example: String Creation
```java
public class Main {
    public static void main(String[] args) {
        // Using string literal
        String str1 = "Hello, World!";
        
        // Using new keyword
        String str2 = new String("Hello, Java!");

        System.out.println("String 1: " + str1);
        System.out.println("String 2: " + str2);
    }
}
```
**Output:**
```
String 1: Hello, World!
String 2: Hello, Java!
```
**Explanation:**
- `str1` is created using a string literal and is stored in the string pool.
- `str2` is created using the `new` keyword and is stored in the heap memory.

---

## 2. **Concatenation of Strings**
String concatenation is the process of combining two or more strings. In Java, you can concatenate strings using the `+` operator or the `concat()` method.

### Example: String Concatenation
```java
public class Main {
    public static void main(String[] args) {
        String str1 = "Hello";
        String str2 = "World";

        // Using + operator
        String result1 = str1 + ", " + str2 + "!";
        System.out.println("Concatenation using + operator: " + result1);

        // Using concat() method
        String result2 = str1.concat(", ").concat(str2).concat("!");
        System.out.println("Concatenation using concat() method: " + result2);
    }
}
```
**Output:**
```
Concatenation using + operator: Hello, World!
Concatenation using concat() method: Hello, World!
```
**Explanation:**
- The `+` operator is the most common way to concatenate strings.
- The `concat()` method is an alternative for concatenating strings.

---

## 3. **Conversion of a String**
Strings can be converted to other data types (e.g., integers, doubles) and vice versa.

### Example: String Conversion
```java
public class Main {
    public static void main(String[] args) {
        // String to int
        String str1 = "123";
        int num1 = Integer.parseInt(str1);
        System.out.println("String to int: " + num1);

        // int to String
        int num2 = 456;
        String str2 = Integer.toString(num2);
        System.out.println("int to String: " + str2);

        // String to double
        String str3 = "78.9";
        double num3 = Double.parseDouble(str3);
        System.out.println("String to double: " + num3);
    }
}
```
**Output:**
```
String to int: 123
int to String: 456
String to double: 78.9
```
**Explanation:**
- `Integer.parseInt()` converts a string to an integer.
- `Integer.toString()` converts an integer to a string.
- `Double.parseDouble()` converts a string to a double.

---

## 4. **Changing Case**
Java provides methods to convert strings to uppercase or lowercase.

### Example: Changing Case
```java
public class Main {
    public static void main(String[] args) {
        String str = "Hello, World!";

        // Convert to uppercase
        String upperCaseStr = str.toUpperCase();
        System.out.println("Uppercase: " + upperCaseStr);

        // Convert to lowercase
        String lowerCaseStr = str.toLowerCase();
        System.out.println("Lowercase: " + lowerCaseStr);
    }
}
```
**Output:**
```
Uppercase: HELLO, WORLD!
Lowercase: hello, world!
```
**Explanation:**
- `toUpperCase()` converts the string to uppercase.
- `toLowerCase()` converts the string to lowercase.

---

## 5. **Character Extraction**
You can extract individual characters from a string using the `charAt()` method.

### Example: Character Extraction
```java
public class Main {
    public static void main(String[] args) {
        String str = "Hello";
        
        // Extract characters
        char firstChar = str.charAt(0);
        char lastChar = str.charAt(str.length() - 1);

        System.out.println("First character: " + firstChar);
        System.out.println("Last character: " + lastChar);
    }
}
```
**Output:**
```
First character: H
Last character: o
```
**Explanation:**
- `charAt(index)` returns the character at the specified index.

---

## 6. **String Comparison**
Strings can be compared using:
- `equals()`: Compares the content of two strings.
- `equalsIgnoreCase()`: Compares content ignoring case.
- `compareTo()`: Compares strings lexicographically.

### Example: String Comparison
```java
public class Main {
    public static void main(String[] args) {
        String str1 = "Hello";
        String str2 = "hello";

        // Using equals()
        System.out.println("Equals: " + str1.equals(str2));

        // Using equalsIgnoreCase()
        System.out.println("Equals Ignore Case: " + str1.equalsIgnoreCase(str2));

        // Using compareTo()
        System.out.println("Compare To: " + str1.compareTo(str2));
    }
}
```
**Output:**
```
Equals: false
Equals Ignore Case: true
Compare To: -32
```
**Explanation:**
- `equals()` returns `true` if the content is the same.
- `equalsIgnoreCase()` returns `true` if the content is the same, ignoring case.
- `compareTo()` returns 0 if strings are equal, a negative value if the first string is smaller, and a positive value if the first string is larger.

---

## 7. **Searching Strings**
You can search for characters or substrings within a string using methods like `indexOf()` and `contains()`.

### Example: Searching Strings
```java
public class Main {
    public static void main(String[] args) {
        String str = "Hello, World!";

        // Search for a character
        int index = str.indexOf('W');
        System.out.println("Index of 'W': " + index);

        // Search for a substring
        boolean contains = str.contains("World");
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

---

## 8. **Modifying Strings**
Since strings are immutable, you cannot change them directly. However, you can create new strings with modifications using methods like `replace()`, `substring()`, and `trim()`.

### Example: Modifying Strings
```java
public class Main {
    public static void main(String[] args) {
        String str = "  Hello, World!  ";

        // Replace characters
        String replacedStr = str.replace('o', 'x');
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
