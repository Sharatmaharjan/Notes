### Chapter 1: Database Management System (DBMS)
1.1 Introduction to Data, Database, Database System, DBMS
Data: Raw facts and figures without context (e.g., numbers, dates, strings).
Database: A structured collection of data, typically stored and accessed electronically from a computer system. Examples include SQL databases, NoSQL databases, etc.
Database System: A software system that uses a standard method of cataloging, retrieving, and running queries on data. It includes the database itself and the DBMS.
DBMS (Database Management System): Software that interacts with end-users, applications, and the database itself to capture and analyze data. It manages data, the database engine, and the database schema to facilitate the organization and manipulation of data.
1.2 Field, Record, Objects, Primary Key, Alternate Key, Candidate Key
Field: The smallest unit of data in a database, representing one piece of information (e.g., a column in a table).
Record: A collection of related fields that usually form a row in a table.
Objects: In databases, objects refer to database structures such as tables, views, indexes, etc.
Primary Key: A field (or combination of fields) that uniquely identifies each record in a table. It must contain unique values and cannot contain NULLs.
Alternate Key: A field (or combination of fields) that could serve as a primary key but is not chosen as the primary key.
Candidate Key: A field, or set of fields, that uniquely identifies a record in a table and can serve as a primary key. Every table can have multiple candidate keys.
1.3 Advantages of Using DBMS
Data Integrity: Ensures accuracy and consistency of data over its lifecycle.
Data Security: Protects data from unauthorized access.
Data Administration: Facilitates efficient data management and storage.
Concurrent Access: Allows multiple users to access the data simultaneously.
Data Abstraction and Independence: Provides a clear separation between physical data storage and logical data structure.
Backup and Recovery: Ensures data preservation and recovery in case of system failures.
Reduced Data Redundancy: Minimizes duplication of data.
1.4 DDL (Data Definition Language) and DML (Data Manipulation Language)
DDL (Data Definition Language): Used to define and modify database structures. Common commands include:
CREATE: To create a new database or table.
ALTER: To modify an existing database structure.
DROP: To delete a database or table.
DML (Data Manipulation Language): Used to retrieve and manipulate data. Common commands include:
SELECT: To query data from a database.
INSERT: To insert data into a table.
UPDATE: To update existing data within a table.
DELETE: To delete data from a table.
1.5 Database Models: Network Model, Hierarchical Model, Relational Database Model
Network Model: Organizes data using a graph structure, allowing more complex relationships among entities. It supports many-to-many relationships.
Hierarchical Model: Organizes data in a tree-like structure where each child record has one parent. It supports one-to-many relationships.
Relational Database Model: Uses tables to represent data and their relationships. Tables (or relations) are made up of rows (records) and columns (fields). It supports powerful querying and data manipulation through SQL.
1.6 Concept of Normalization: 1NF, 2NF, 3NF
Normalization: A process to organize a database into tables to reduce data redundancy and improve data integrity.
1NF (First Normal Form): Ensures that each table cell contains a single value and each record is unique.
2NF (Second Normal Form): Ensures that all non-key attributes are fully functional dependent on the primary key, and the table is already in 1NF.
3NF (Third Normal Form): Ensures that all the attributes are only dependent on the primary key, and there is no transitive dependency, and the table is already in 2NF.
1.7 Centralized vs. Distributed Database
Centralized Database: All data is stored and maintained in a single location. It is easier to manage, secure, and maintain but can become a bottleneck and a single point of failure.
Distributed Database: Data is stored across multiple locations, which can improve performance and reliability. However, it is more complex to manage and ensure data consistency.
1.8 Database Security
Database Security: Measures and controls that ensure the confidentiality, integrity, and availability of a database. Security features include:
Authentication: Verifying the identity of users accessing the database.
Authorization: Granting or denying specific privileges to users.
Encryption: Protecting data by converting it into an unreadable format.
Auditing: Tracking and logging database activities to detect and prevent unauthorized actions.
Backup and Recovery: Ensuring data can be restored in case of loss or corruption.
