## Chapter 1: Database Management System (DBMS) [12-HRS]

- 1.1 Introduction to Data, Database, Database System, DBMS
- 1.2 Field, Record, Objects, Primary Key, Alternate key, Candidate key
- 1.3 Advantages of using DBMS
- 1.4 DDL (Data Definition Language) and DML (Data Manipulation Language)
- 1.5 Database Model: Network Model, Hierarchical Model, Relational database model
- 1.6 Concept of Normalization: 1NF, 2NF, 3NF
- 1.7 Centralized Vs. Distributed Database
- 1.8 Database Security

### 1.1 Introduction to Data, Database, Database System, DBMS

#### Data
- **Definition**: Data are raw, unprocessed facts that need to be processed to gain meaningful information. They can take various forms, such as numbers, text, images, or videos.
- **Examples**:
  - Numbers: 123, 456
  - Text: "John Doe", "Database"
  - Dates: "2023-07-11"
  - Binary data: 101010

#### Database
- **Definition**: A database is an organized collection of data, generally stored and accessed electronically from a computer system. It allows data to be easily managed, updated, and retrieved.
- **Characteristics**:
  - **Structured**: Data is organized in a way that supports easy access and management, usually in tables with rows and columns.
  - **Persistent**: Data is stored in a non-volatile medium, ensuring long-term storage.
  - **Shared**: Databases can be accessed by multiple users and applications simultaneously.
- **Examples**:
  - SQL Databases: MySQL, PostgreSQL, Oracle
  - NoSQL Databases: MongoDB, Cassandra

#### Database System
- **Definition**: A database system is a combination of the database, the DBMS, and the application programs that use the database.
- **Components**:
  - **Hardware**: Physical devices like servers, storage devices.
  - **Software**: DBMS software and applications that interact with the database.
  - **Data**: The actual data stored in the database.
  - **Users**: Database administrators, end-users, and application developers.

#### DBMS (Database Management System)
- **Definition**: A DBMS is a software system that enables users to define, create, maintain, and control access to the database. It acts as an intermediary between the database and the users or application programs.
- **Functions**:
  - **Data Definition**: Allows users to define the structure of the data in the database (tables, columns, data types).
  - **Data Manipulation**: Provides tools for inserting, updating, deleting, and retrieving data.
  - **Data Security**: Ensures that data is protected from unauthorized access and breaches.
  - **Data Integrity**: Ensures the accuracy and consistency of data.
  - **Data Recovery**: Provides mechanisms for backup and recovery of data in case of failures.
  - **Concurrency Control**: Manages simultaneous data access to ensure consistency and integrity.
- **Types of DBMS**:
  - **Relational DBMS (RDBMS)**: Uses tables to store data (e.g., MySQL, Oracle, SQL Server).
  - **NoSQL DBMS**: Uses various data models, including document, key-value, columnar, and graph (e.g., MongoDB, Cassandra).
  - **Object-oriented DBMS**: Stores data in objects, as used in object-oriented programming (e.g., ObjectDB).
  - **Hierarchical DBMS**: Uses a tree-like structure to store data (e.g., IBM’s IMS).

#### Importance of DBMS
- **Efficiency**: Improves the efficiency of data retrieval and manipulation through optimized storage and indexing.
- **Scalability**: Supports large amounts of data and multiple users by efficiently managing resources.
- **Flexibility**: Provides a flexible data model that can adapt to changing requirements and complex queries.
- **Consistency**: Ensures consistent data through integrity constraints and transaction management.


### 1.2 Field, Record, Objects, Primary Key, Alternate Key, Candidate Key

#### Field
- **Definition**: A field is the smallest unit of data in a database, representing a single piece of information about an entity.
- **Example**: In a table representing employees, fields might include `EmployeeID`, `FirstName`, `LastName`, `DateOfBirth`, `Position`, and `Salary`.

#### Record
- **Definition**: A record is a complete set of related fields, typically representing one entity instance within a table. A record is often referred to as a row in a database table.
- **Example**: In the employees table, one record might be:
  - `EmployeeID: 123`
  - `FirstName: John`
  - `LastName: Doe`
  - `DateOfBirth: 1985-06-15`
  - `Position: Software Engineer`
  - `Salary: $80,000`

#### Objects
- **Definition**: Objects in a database refer to the various structures that store or manipulate data. This includes tables, views, indexes, sequences, stored procedures, and triggers.
- **Examples**:
  - **Tables**: The primary structure for storing data in rows and columns.
  - **Views**: Virtual tables representing a subset of data from one or more tables.
  - **Indexes**: Structures that improve the speed of data retrieval.
  - **Sequences**: Objects used to generate unique numerical values.
  - **Stored Procedures**: Predefined SQL code that can be executed to perform tasks.
  - **Triggers**: Procedures that are automatically executed in response to certain events on a particular table or view.

#### Primary Key
- **Definition**: A primary key is a field (or combination of fields) that uniquely identifies each record in a table. It ensures that no two records have the same primary key value and that this value is never NULL.
- **Example**: In the employees table, `EmployeeID` might be the primary key, ensuring that each employee has a unique identifier.

#### Alternate Key
- **Definition**: An alternate key is a field (or combination of fields) that could serve as a primary key but is not chosen as the primary key. It is also known as a secondary key and is unique across the table.
- **Example**: In the employees table, `SocialSecurityNumber` might be an alternate key if it uniquely identifies each employee but is not used as the primary key.

#### Candidate Key
- **Definition**: A candidate key is a field, or set of fields, that uniquely identifies a record in a table and can qualify to be a primary key. A table can have multiple candidate keys, but only one can be chosen as the primary key.
- **Example**: In the employees table, both `EmployeeID` and `SocialSecurityNumber` could be candidate keys since they uniquely identify each employee. Only one of them will be chosen as the primary key, and the other could be an alternate key.

### Summary
- **Fields** are individual pieces of data (columns).
- **Records** are collections of related fields (rows).
- **Objects** are various structures used to store and manipulate data.
- **Primary Key** is a unique identifier for each record.
- **Alternate Key** is a unique identifier that could serve as a primary key but is not chosen.
- **Candidate Key** is any field or set of fields that can uniquely identify a record, including the primary key and alternate keys.

### 1.3 Advantages of Using DBMS
- **Data Integrity**: Ensures accuracy and consistency of data over its lifecycle.
- **Data Security**: Protects data from unauthorized access.
- **Data Administration**: Facilitates efficient data management and storage.
- **Concurrent Access**: Allows multiple users to access the data simultaneously.
- **Data Abstraction and Independence**: Provides a clear separation between physical data storage and logical data structure.
- **Backup and Recovery**: Ensures data preservation and recovery in case of system failures.
- **Reduced Data Redundancy**: Minimizes duplication of data.

### 1.4 DDL (Data Definition Language) and DML (Data Manipulation Language)

#### Data Definition Language (DDL)
DDL is a subset of SQL (Structured Query Language) used to define, alter, and manage database structures. The primary commands in DDL are:

1. **CREATE**:
   - **CREATE DATABASE**: Creates a new database.
     ```sql
     CREATE DATABASE database_name;
     ```
   - **CREATE TABLE**: Creates a new table in the database.
     ```sql
     CREATE TABLE table_name (
         column1 datatype,
         column2 datatype,
         ...
     );
     ```
   - **CREATE INDEX**: Creates an index on a table to enhance data retrieval speed.
     ```sql
     CREATE INDEX index_name
     ON table_name (column1, column2, ...);
     ```

2. **ALTER**:
   - **ALTER TABLE**: Modifies the structure of an existing table, such as adding or deleting columns.
     ```sql
     ALTER TABLE table_name
     ADD column_name datatype;
     ```
     ```sql
     ALTER TABLE table_name
     DROP COLUMN column_name;
     ```

3. **DROP**:
   - **DROP DATABASE**: Deletes an entire database.
     ```sql
     DROP DATABASE database_name;
     ```
   - **DROP TABLE**: Deletes an entire table and all its data.
     ```sql
     DROP TABLE table_name;
     ```
   - **DROP INDEX**: Deletes an index from a table.
     ```sql
     DROP INDEX index_name;
     ```

4. **TRUNCATE**:
   - **TRUNCATE TABLE**: Removes all records from a table, but the table structure remains.
     ```sql
     TRUNCATE TABLE table_name;
     ```

#### Data Manipulation Language (DML)
DML is a subset of SQL used for querying and modifying data. The primary commands in DML are:

1. **SELECT**:
   - Retrieves data from one or more tables.
     ```sql
     SELECT column1, column2, ...
     FROM table_name
     WHERE condition;
     ```
   - Example:
     ```sql
     SELECT first_name, last_name
     FROM employees
     WHERE department = 'Sales';
     ```

2. **INSERT**:
   - Adds new records to a table.
     ```sql
     INSERT INTO table_name (column1, column2, ...)
     VALUES (value1, value2, ...);
     ```
   - Example:
     ```sql
     INSERT INTO employees (first_name, last_name, department)
     VALUES ('John', 'Doe', 'Sales');
     ```

3. **UPDATE**:
   - Modifies existing records in a table.
     ```sql
     UPDATE table_name
     SET column1 = value1, column2 = value2, ...
     WHERE condition;
     ```
   - Example:
     ```sql
     UPDATE employees
     SET department = 'Marketing'
     WHERE first_name = 'John' AND last_name = 'Doe';
     ```

4. **DELETE**:
   - Removes records from a table.
     ```sql
     DELETE FROM table_name
     WHERE condition;
     ```
   - Example:
     ```sql
     DELETE FROM employees
     WHERE first_name = 'John' AND last_name = 'Doe';
     ```

### Differences Between DDL and DML

- **Purpose**:
  - DDL focuses on defining and modifying database structures (schemas, tables, indexes).
  - DML focuses on querying and manipulating the actual data stored within the database.

- **Operations**:
  - DDL operations typically include CREATE, ALTER, DROP, and TRUNCATE.
  - DML operations typically include SELECT, INSERT, UPDATE, and DELETE.

- **Impact**:
  - DDL commands change the structure of the database and can affect the overall schema and storage.
  - DML commands change the data within the database but do not alter the structure of the database.

- **Transactional Nature**:
  - DDL commands are auto-committed, meaning changes are immediately and permanently applied.
  - DML commands are transactional, meaning changes can be rolled back if they are part of a transaction block.

### Examples

**DDL Example**:
```sql
CREATE TABLE students (
    student_id INT PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    enrollment_date DATE
);

ALTER TABLE students
ADD email VARCHAR(100);

DROP TABLE students;
```

**DML Example**:
```sql
INSERT INTO students (student_id, first_name, last_name, enrollment_date)
VALUES (1, 'Alice', 'Smith', '2023-01-10');

SELECT first_name, last_name
FROM students
WHERE enrollment_date > '2023-01-01';

UPDATE students
SET email = 'alice.smith@example.com'
WHERE student_id = 1;

DELETE FROM students
WHERE student_id = 1;
```

### Summary
- **DDL**: Used to define and manage database schemas and structures. Commands include CREATE, ALTER, DROP, and TRUNCATE.
- **DML**: Used to manipulate data within the database. Commands include SELECT, INSERT, UPDATE, and DELETE.

### 1.5 Database Models: Network Model, Hierarchical Model, Relational Database Model

#### Network Model
- **Structure**: The network model uses a graph structure to organize data, where entities are nodes and relationships are edges. It allows a more complex representation of relationships compared to the hierarchical model.
- **Relationships**: Supports many-to-many relationships, which means a record can have multiple parent and child records.
- **Data Access**: Data is accessed using pointers or links, which directly connect related records.
- **Example**: Imagine a database for a university. In the network model, a student can be linked to multiple courses, and each course can be linked to multiple students, representing a many-to-many relationship.
- **Advantages**:
  - More flexible than the hierarchical model.
  - Efficient in handling many-to-many relationships.
- **Disadvantages**:
  - Complex structure makes it harder to design and maintain.
  - Navigating the network can be complicated.

#### Hierarchical Model
- **Structure**: The hierarchical model organizes data in a tree-like structure, where each record has a single parent but can have multiple children.
- **Relationships**: Supports one-to-many relationships. Each child record is connected to one parent, and no child can have more than one parent.
- **Data Access**: Data is accessed by traversing the tree from the root to the desired node.
- **Example**: In a company database, the organization can be represented in a hierarchy: the company is at the root, departments are the branches, and employees are the leaves.
- **Advantages**:
  - Simple and easy to understand.
  - Efficient for queries that follow the tree structure.
- **Disadvantages**:
  - Limited flexibility as it only supports one-to-many relationships.
  - Redundancy can occur if a child needs to relate to multiple parents.
  - Changes in the hierarchy require substantial restructuring.

#### Relational Database Model
- **Structure**: The relational model uses tables (relations) to represent data. Each table consists of rows (records) and columns (fields).
- **Relationships**: Supports one-to-one, one-to-many, and many-to-many relationships through the use of foreign keys.
- **Data Access**: Data is accessed using Structured Query Language (SQL), which allows powerful and flexible querying and data manipulation.
- **Example**: Consider an e-commerce database with tables for customers, orders, and products. Each order can link a customer to multiple products using foreign keys.
- **Advantages**:
  - Highly flexible and scalable.
  - Easy to add, update, and delete data without restructuring the entire database.
  - Supports complex queries and transactions.
  - Enforces data integrity through primary and foreign keys.
- **Disadvantages**:
  - Can become complex with large and highly interconnected data sets.
  - Performance can degrade with very large tables and complex joins.

### Summary
- **Network Model**: Graph-based, supports many-to-many relationships, complex structure.
- **Hierarchical Model**: Tree-based, supports one-to-many relationships, simple but inflexible.
- **Relational Database Model**: Table-based, supports various relationships, highly flexible and widely used.

### 1.6 Concept of Normalization: 1NF, 2NF, 3NF

**Normalization** is a database design technique that organizes tables to minimize redundancy and dependency. The main objective is to divide larger tables into smaller tables and define relationships between them to increase data consistency and integrity.

#### First Normal Form (1NF)
- **Objective**: Ensure that the table is in tabular format and all values are atomic (indivisible).
- **Rules**:
  - Each table cell must contain a single value, i.e., atomicity.
  - Each record (row) must be unique.
- **Example**:
  - Consider a table storing information about students and their courses:
    ```plaintext
    | StudentID | StudentName | Courses         |
    |-----------|-------------|-----------------|
    | 1         | Alice       | Math, Science   |
    | 2         | Bob         | English, History|
    ```
  - This table is not in 1NF because the `Courses` field contains multiple values.
  - To convert it to 1NF, split the courses into separate rows:
    ```plaintext
    | StudentID | StudentName | Course   |
    |-----------|-------------|----------|
    | 1         | Alice       | Math     |
    | 1         | Alice       | Science  |
    | 2         | Bob         | English  |
    | 2         | Bob         | History  |
    ```

#### Second Normal Form (2NF)
- **Objective**: Ensure that all non-key attributes are fully functionally dependent on the primary key. Achieved only after the table is in 1NF.
- **Rules**:
  - The table must be in 1NF.
  - There should be no partial dependency, i.e., no non-key attribute should depend on a part of the composite primary key.
- **Example**:
  - Consider a table with a composite primary key:
    ```plaintext
    | StudentID | CourseID | StudentName | CourseName  |
    |-----------|----------|-------------|-------------|
    | 1         | 101      | Alice       | Math        |
    | 1         | 102      | Alice       | Science     |
    | 2         | 103      | Bob         | English     |
    | 2         | 104      | Bob         | History     |
    ```
  - Here, `StudentName` depends only on `StudentID` and `CourseName` depends only on `CourseID`. This partial dependency violates 2NF.
  - To convert it to 2NF, separate the data into two tables:
    ```plaintext
    Students Table:
    | StudentID | StudentName |
    |-----------|-------------|
    | 1         | Alice       |
    | 2         | Bob         |

    Courses Table:
    | CourseID | CourseName |
    |----------|------------|
    | 101      | Math       |
    | 102      | Science    |
    | 103      | English    |
    | 104      | History    |

    Enrollment Table:
    | StudentID | CourseID |
    |-----------|----------|
    | 1         | 101      |
    | 1         | 102      |
    | 2         | 103      |
    | 2         | 104      |
    ```

#### Third Normal Form (3NF)
- **Objective**: Ensure that all attributes are only dependent on the primary key. Achieved only after the table is in 2NF.
- **Rules**:
  - The table must be in 2NF.
  - There should be no transitive dependency, i.e., non-key attributes should not depend on other non-key attributes.
- **Example**:
  - Consider a table:
    ```plaintext
    | StudentID | StudentName | CourseID | InstructorName |
    |-----------|-------------|----------|----------------|
    | 1         | Alice       | 101      | Prof. Smith    |
    | 1         | Alice       | 102      | Prof. Johnson  |
    | 2         | Bob         | 103      | Prof. Clark    |
    | 2         | Bob         | 104      | Prof. White    |
    ```
  - Here, `InstructorName` depends on `CourseID`, not directly on `StudentID`. This transitive dependency violates 3NF.
  - To convert it to 3NF, separate the data into different tables:
    ```plaintext
    Students Table:
    | StudentID | StudentName |
    |-----------|-------------|
    | 1         | Alice       |
    | 2         | Bob         |

    Courses Table:
    | CourseID | InstructorName |
    |----------|----------------|
    | 101      | Prof. Smith    |
    | 102      | Prof. Johnson  |
    | 103      | Prof. Clark    |
    | 104      | Prof. White    |

    Enrollment Table:
    | StudentID | CourseID |
    |-----------|----------|
    | 1         | 101      |
    | 1         | 102      |
    | 2         | 103      |
    | 2         | 104      |
    ```

By following these normalization steps, databases can be optimized for data integrity and efficiency, reducing redundancy and enhancing consistency across the data storage.

### 1.7 Centralized vs. Distributed Database

#### Centralized Database
A centralized database is a single database located at one site, managed and maintained by a central authority. All data processing operations, data storage, and data management activities occur at this single site. 

##### Features
- **Single Location**: All data is stored in one location.
- **Easier Management**: Simplified administration and management as everything is in one place.
- **Consistency**: Data consistency is easier to maintain since all data is in one location.
- **Cost-Effective**: Lower cost in terms of hardware and maintenance since everything is centralized.

##### Advantages
- **Simplicity**: Easier to design, deploy, and manage.
- **Security**: Simplified security management as all data is in one place.
- **Consistency**: Ensures data integrity and consistency more easily.
- **Backup and Recovery**: Easier to implement and manage backup and recovery procedures.

##### Disadvantages
- **Scalability**: Limited scalability as the database grows, it might require more powerful hardware.
- **Single Point of Failure**: If the central database fails, the entire system becomes unavailable.
- **Performance Bottlenecks**: Can become a bottleneck as the number of users increases, leading to slower performance.
- **Geographical Limitations**: Higher latency for users located far from the central site.

#### Distributed Database
A distributed database is a collection of multiple, interconnected databases spread across different locations, connected via a network. These databases can be located on different physical sites but are perceived as a single logical database by users.

##### Features
- **Multiple Locations**: Data is distributed across multiple sites.
- **Scalability**: Easily scalable by adding more nodes or sites.
- **Redundancy**: Redundant data storage can improve reliability and fault tolerance.
- **Parallel Processing**: Data processing can be parallelized across multiple sites, improving performance.

##### Advantages
- **Scalability**: Can handle increased load by adding more servers or nodes.
- **Fault Tolerance**: If one site fails, others can continue to operate, improving system reliability.
- **Performance**: Localized data access can reduce latency and improve response times for users.
- **Flexibility**: Can be designed to meet the specific needs of different regions or departments within an organization.

##### Disadvantages
- **Complexity**: More complex to design, deploy, and manage.
- **Consistency Challenges**: Maintaining data consistency across multiple sites can be difficult.
- **Security**: More points of entry, making it harder to secure.
- **Cost**: Higher costs associated with managing multiple sites, including hardware, software, and network infrastructure.

#### Comparison Summary

| Feature              | Centralized Database                    | Distributed Database                           |
|----------------------|-----------------------------------------|------------------------------------------------|
| **Location**         | Single site                             | Multiple sites                                 |
| **Management**       | Easier                                  | More complex                                   |
| **Scalability**      | Limited                                 | High                                           |
| **Fault Tolerance**  | Single point of failure                 | High, due to redundancy                        |
| **Performance**      | Potential bottlenecks                   | Better with parallel processing and local access |
| **Consistency**      | Easier to maintain                      | Challenging                                    |
| **Security**         | Easier to secure                        | More complex                                   |
| **Cost**             | Lower                                   | Higher                                         |
| **Backup & Recovery**| Simpler to implement                    | More complex                                   |

In summary, the choice between a centralized and distributed database depends on the specific needs and constraints of the organization, such as scalability requirements, fault tolerance, performance, and budget.

### 1.8 Database Security

Database security encompasses a range of measures, techniques, and policies to protect a database from unauthorized access, misuse, and threats. It ensures the confidentiality, integrity, and availability of the data stored within the database. Here are some key aspects of database security:

#### Authentication
- **Definition**: The process of verifying the identity of a user or system accessing the database.
- **Methods**: 
  - **Username and Password**: The most common form of authentication where users must provide a valid combination.
  - **Multi-Factor Authentication (MFA)**: Requires multiple forms of verification, such as a password plus a code sent to a mobile device.
  - **Biometric Authentication**: Uses biological characteristics (e.g., fingerprint, retina scan) to verify identity.

#### Authorization
- **Definition**: The process of granting or denying specific access rights and privileges to users or systems.
- **Techniques**:
  - **Role-Based Access Control (RBAC)**: Assigns permissions to roles rather than individual users. Users are then assigned roles.
  - **Discretionary Access Control (DAC)**: The data owner determines who has access to specific pieces of data.
  - **Mandatory Access Control (MAC)**: Access rights are regulated by a central authority based on multiple levels of security.

#### Encryption
- **Definition**: The process of converting data into a coded format that is unreadable without the proper decryption key.
- **Types**:
  - **Data-at-Rest Encryption**: Encrypts stored data to protect it from unauthorized access.
  - **Data-in-Transit Encryption**: Encrypts data as it moves between systems to protect it from interception.
  - **Column-Level Encryption**: Encrypts specific columns in a database table, typically those containing sensitive information (e.g., social security numbers).
  - **Transparent Data Encryption (TDE)**: Automatically encrypts and decrypts data as it is written to and read from the storage.

#### Auditing and Monitoring
- **Definition**: Tracking and logging database activities to detect and respond to unauthorized or suspicious actions.
- **Tools and Techniques**:
  - **Database Activity Monitoring (DAM)**: Continuously monitors database activities in real-time.
  - **Log Analysis**: Reviews and analyzes logs of database transactions and activities.
  - **Alerts and Notifications**: Automatically sends alerts when specific activities occur, such as failed login attempts or unauthorized data access.

#### Backup and Recovery
- **Definition**: Ensuring that data can be restored in case of data loss, corruption, or disasters.
- **Techniques**:
  - **Regular Backups**: Periodically copying data to a secure location to allow for restoration in case of data loss.
  - **Disaster Recovery Plan (DRP)**: A comprehensive plan that outlines the steps to recover and restore data after a major failure or disaster.
  - **Point-In-Time Recovery**: Restoring the database to a specific moment in time to recover from data corruption or accidental changes.

#### Network Security
- **Definition**: Protecting the database from threats that come through the network.
- **Measures**:
  - **Firewalls**: Filtering traffic between trusted and untrusted networks to prevent unauthorized access.
  - **Virtual Private Network (VPN)**: Encrypting network traffic between remote users and the database server.
  - **Secure Sockets Layer (SSL)/Transport Layer Security (TLS)**: Encrypting communication between clients and the database server.

#### Physical Security
- **Definition**: Protecting the physical hardware and infrastructure that supports the database.
- **Measures**:
  - **Controlled Access**: Restricting access to the physical locations where servers and storage devices are housed.
  - **Surveillance Systems**: Using cameras and monitoring systems to detect and deter unauthorized physical access.
  - **Environmental Controls**: Ensuring proper climate control, power supply, and disaster prevention measures (e.g., fire suppression systems).

#### Data Masking
- **Definition**: Protecting sensitive data by replacing it with fictional yet realistic data for non-production purposes.
- **Types**:
  - **Static Data Masking**: Replacing sensitive data in a database copy.
  - **Dynamic Data Masking**: Obscuring data in real-time as it is queried.

### Conclusion
Database security is a multi-faceted discipline that requires a combination of policies, technologies, and practices to ensure that data remains protected against various threats. By implementing robust security measures, organizations can safeguard their data, maintain compliance with regulations, and ensure the trust of their users and stakeholders.
