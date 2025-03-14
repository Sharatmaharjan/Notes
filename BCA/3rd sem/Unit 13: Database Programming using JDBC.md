### Unit 13: Database Programming using JDBC [2 Hrs.]

In this unit, we will explore **Java Database Connectivity (JDBC)**, which is a standard API for connecting Java applications to relational databases. We will learn how to use the `Connection`, `Statement`, and `ResultSet` interfaces to interact with databases, manipulate data, and retrieve results. By the end of this unit, we will be able to perform basic database operations like inserting, updating, deleting, and querying data.

---

### 1. Definition of JDBC

**Definition**:  
JDBC (Java Database Connectivity) is a Java API that provides a standard way for Java programs to interact with relational databases. It allows us to execute SQL queries, retrieve results, and perform database operations like insert, update, and delete.

**Key Components of JDBC**:
1. **DriverManager**: Manages database drivers and establishes a connection to the database.
2. **Connection**: Represents a connection to the database.
3. **Statement**: Used to execute SQL queries.
4. **ResultSet**: Represents the result of a query (e.g., rows returned by a `SELECT` statement).

---

### 2. Steps to Connect to a Database using JDBC

To work with JDBC, we follow these steps:
1. **Load the JDBC Driver**: Register the database driver.
2. **Establish a Connection**: Use `DriverManager` to connect to the database.
3. **Create a Statement**: Use the `Connection` object to create a `Statement` or `PreparedStatement`.
4. **Execute Queries**: Execute SQL queries using the `Statement` object.
5. **Process Results**: Use the `ResultSet` object to process query results.
6. **Close Resources**: Close the `Connection`, `Statement`, and `ResultSet` objects to release resources.

---

### 3. Using `Connection`, `Statement`, and `ResultSet` Interfaces

#### a. **Connection Interface**
**Definition**:  
The `Connection` interface represents a connection to the database. It is used to create `Statement` objects and manage transactions.

**Program Example**:
```java
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class ConnectionExample {
    public static void main(String[] args) {
        Connection connection = null;
        try {
            // Step 1: Load the JDBC driver
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Step 2: Establish a connection
            String url = "jdbc:mysql://localhost:3306/mydatabase";
            String username = "root";
            String password = "password";
            connection = DriverManager.getConnection(url, username, password);

            System.out.println("Connected to the database!");
        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        } finally {
            // Step 6: Close the connection
            if (connection != null) {
                try {
                    connection.close();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
```

**Explanation**:  
- We load the MySQL JDBC driver using `Class.forName()`.
- We establish a connection to the database using `DriverManager.getConnection()`.
- Finally, we close the connection to release resources.

**Sample Output**:  
```
Connected to the database!
```

---

#### b. **Statement Interface**
**Definition**:  
The `Statement` interface is used to execute SQL queries (e.g., `SELECT`, `INSERT`, `UPDATE`, `DELETE`).

**Program Example**:
```java
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class StatementExample {
    public static void main(String[] args) {
        Connection connection = null;
        Statement statement = null;
        try {
            // Step 1: Load the JDBC driver
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Step 2: Establish a connection
            String url = "jdbc:mysql://localhost:3306/mydatabase";
            String username = "root";
            String password = "password";
            connection = DriverManager.getConnection(url, username, password);

            // Step 3: Create a Statement
            statement = connection.createStatement();

            // Step 4: Execute a query
            String sql = "INSERT INTO employees (id, name, salary) VALUES (1, 'John Doe', 50000)";
            int rowsAffected = statement.executeUpdate(sql);
            System.out.println(rowsAffected + " row(s) affected.");
        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        } finally {
            // Step 6: Close resources
            try {
                if (statement != null) statement.close();
                if (connection != null) connection.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
}
```

**Explanation**:  
- We create a `Statement` object using `connection.createStatement()`.
- We execute an `INSERT` query using `statement.executeUpdate()`.
- The `executeUpdate()` method returns the number of rows affected.

**Sample Output**:  
```
1 row(s) affected.
```

---

#### c. **ResultSet Interface**
**Definition**:  
The `ResultSet` interface represents the result of a `SELECT` query. It allows us to iterate through the rows returned by the query.

**Program Example**:
```java
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class ResultSetExample {
    public static void main(String[] args) {
        Connection connection = null;
        Statement statement = null;
        ResultSet resultSet = null;
        try {
            // Step 1: Load the JDBC driver
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Step 2: Establish a connection
            String url = "jdbc:mysql://localhost:3306/mydatabase";
            String username = "root";
            String password = "password";
            connection = DriverManager.getConnection(url, username, password);

            // Step 3: Create a Statement
            statement = connection.createStatement();

            // Step 4: Execute a query
            String sql = "SELECT id, name, salary FROM employees";
            resultSet = statement.executeQuery(sql);

            // Step 5: Process the ResultSet
            while (resultSet.next()) {
                int id = resultSet.getInt("id");
                String name = resultSet.getString("name");
                double salary = resultSet.getDouble("salary");
                System.out.println("ID: " + id + ", Name: " + name + ", Salary: " + salary);
            }
        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        } finally {
            // Step 6: Close resources
            try {
                if (resultSet != null) resultSet.close();
                if (statement != null) statement.close();
                if (connection != null) connection.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
}
```

**Explanation**:  
- We execute a `SELECT` query using `statement.executeQuery()`.
- We use the `ResultSet` object to iterate through the rows and retrieve column values using methods like `getInt()`, `getString()`, and `getDouble()`.

**Sample Output**:  
```
ID: 1, Name: John Doe, Salary: 50000.0
```

---

### 4. Differences Between `Statement` and `PreparedStatement`

| Feature               | Statement                          | PreparedStatement                   |
|-----------------------|------------------------------------|-------------------------------------|
| **SQL Injection**     | Vulnerable to SQL injection.       | Prevents SQL injection.             |
| **Performance**       | Slower for repeated queries.       | Faster for repeated queries.        |
| **Usage**             | Used for static SQL queries.       | Used for dynamic SQL queries.       |

---

### 5. Summary

In this unit, we learned about **JDBC (Java Database Connectivity)**, which is a standard API for connecting Java applications to relational databases. We explored the following key interfaces:
1. **Connection**: Represents a connection to the database.
2. **Statement**: Used to execute SQL queries.
3. **ResultSet**: Represents the result of a query.

We also learned how to:
- Load the JDBC driver.
- Establish a connection to the database.
- Execute SQL queries using `Statement` and `PreparedStatement`.
- Process query results using `ResultSet`.

By mastering JDBC, we can build Java applications that interact with databases to store, retrieve, and manipulate data efficiently. This knowledge is essential for developing data-driven applications.

Let me know if you'd like further clarification or additional examples! 😊
