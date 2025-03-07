## Unit 8: I/O and Streams in Java

#### 1. **java.io Package**
The `java.io` package provides classes for system input and output through data streams, serialization, and the file system. It is one of the core packages in Java for handling I/O operations.

#### 2. **Files and Directories**
Java provides the `File` class in the `java.io` package to work with files and directories. This class can be used to create, delete, rename, and check the existence of files and directories.

**Example:**
```java
import java.io.File;

public class FileExample {
    public static void main(String[] args) {
        File file = new File("example.txt");

        // Check if file exists
        if (file.exists()) {
            System.out.println("File exists.");
        } else {
            System.out.println("File does not exist.");
        }

        // Create a new file
        try {
            if (file.createNewFile()) {
                System.out.println("File created: " + file.getName());
            } else {
                System.out.println("File already exists.");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
```

**Sample Output:**
```
File does not exist.
File created: example.txt
```

**Explanation:**
- The `File` class is used to represent the file `example.txt`.
- The `exists()` method checks if the file exists.
- The `createNewFile()` method creates a new file if it does not already exist.

#### 3. **Streams: Byte Streams and Character Streams**
Streams in Java are used to perform input and output operations. There are two types of streams:
- **Byte Streams**: Handle I/O of raw binary data. Classes include `InputStream` and `OutputStream`.
- **Character Streams**: Handle I/O of character data. Classes include `Reader` and `Writer`.

**Example of Byte Stream:**
```java
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class ByteStreamExample {
    public static void main(String[] args) {
        try (FileInputStream in = new FileInputStream("input.txt");
             FileOutputStream out = new FileOutputStream("output.txt")) {
            int c;
            while ((c = in.read()) != -1) {
                out.write(c);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

**Sample Output:**
- This program reads the contents of `input.txt` and writes them to `output.txt`.

**Explanation:**
- `FileInputStream` reads bytes from `input.txt`.
- `FileOutputStream` writes bytes to `output.txt`.
- The `read()` method reads a byte of data, and `write()` writes a byte of data.

**Example of Character Stream:**
```java
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class CharacterStreamExample {
    public static void main(String[] args) {
        try (FileReader in = new FileReader("input.txt");
             FileWriter out = new FileWriter("output.txt")) {
            int c;
            while ((c = in.read()) != -1) {
                out.write(c);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

**Sample Output:**
- This program reads the contents of `input.txt` and writes them to `output.txt`.

**Explanation:**
- `FileReader` reads characters from `input.txt`.
- `FileWriter` writes characters to `output.txt`.
- The `read()` method reads a character, and `write()` writes a character.

**Difference Between Byte Streams and Character Streams:**
- Byte streams handle binary data, while character streams handle text data.
- Byte streams use `InputStream` and `OutputStream`, while character streams use `Reader` and `Writer`.

#### 4. **Reading/Writing Console Input/Output**
Java provides `System.in`, `System.out`, and `System.err` for console I/O. The `Scanner` class is commonly used for reading input from the console.

**Example:**
```java
import java.util.Scanner;

public class ConsoleIOExample {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your name: ");
        String name = scanner.nextLine();
        System.out.println("Hello, " + name);
    }
}
```

**Sample Output:**
```
Enter your name: John
Hello, John
```

**Explanation:**
- `Scanner` reads input from the console.
- `nextLine()` reads a line of text input.

#### 5. **Reading and Writing Files**
Java provides various classes for reading and writing files, such as `FileReader`, `FileWriter`, `BufferedReader`, and `BufferedWriter`.

**Example:**
```java
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class FileReadWriteExample {
    public static void main(String[] args) {
        try (BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
             BufferedWriter writer = new BufferedWriter(new FileWriter("output.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                writer.write(line);
                writer.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

**Sample Output:**
- This program reads lines from `input.txt` and writes them to `output.txt`.

**Explanation:**
- `BufferedReader` reads text from `input.txt`.
- `BufferedWriter` writes text to `output.txt`.
- `readLine()` reads a line of text, and `write()` writes a line of text.

#### 6. **The Serialization Interface**
Serialization is the process of converting an object into a byte stream, and deserialization is the process of converting a byte stream back into an object. The `Serializable` interface is used to mark classes that can be serialized.

**Example:**
```java
import java.io.*;

class Student implements Serializable {
    private String name;
    private int age;

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public String toString() {
        return "Student{name='" + name + "', age=" + age + "}";
    }
}

public class SerializationExample {
    public static void main(String[] args) {
        Student student = new Student("John", 20);

        // Serialization
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("student.ser"))) {
            out.writeObject(student);
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Deserialization
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream("student.ser"))) {
            Student deserializedStudent = (Student) in.readObject();
            System.out.println(deserializedStudent);
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
```

**Sample Output:**
```
Student{name='John', age=20}
```

**Explanation:**
- The `Student` class implements the `Serializable` interface.
- `ObjectOutputStream` serializes the `Student` object and writes it to `student.ser`.
- `ObjectInputStream` deserializes the `Student` object from `student.ser`.

#### 7. **Serialization & Deserialization**
- **Serialization**: Converts an object into a byte stream.
- **Deserialization**: Converts a byte stream back into an object.

**Difference Between Serialization and Deserialization:**
- Serialization is the process of converting an object to a byte stream, while deserialization is the process of converting a byte stream back to an object.

#### Summary
- The `java.io` package provides classes for I/O operations.
- Files and directories can be managed using the `File` class.
- Byte streams handle binary data, while character streams handle text data.
- Console I/O can be performed using `System.in`, `System.out`, and `Scanner`.
- Files can be read and written using classes like `FileReader`, `FileWriter`, `BufferedReader`, and `BufferedWriter`.
- Serialization and deserialization allow objects to be converted to and from byte streams using the `Serializable` interface.

This unit covers essential I/O operations in Java, enabling efficient handling of files, streams, and serialization.
