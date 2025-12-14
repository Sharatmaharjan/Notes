# Unit 3: OOP Concepts

## 1. Circle

**Question:**
Write a Java program to define a class **`Circle`** containing a private data member `radius` of type `float`. Provide suitable constructors to initialize the radius. Define two member methods `findArea()` and `findCircumference()` to calculate and return the area and circumference of the circle respectively. Write a separate class **`MyCircle`** containing the `main()` method to create and use `Circle` objects.

---

## 2. Rectangle

**Question:**
Write a Java program to define a class **`Rectangle`** with private data members `length` and `breadth` of type `float`. Provide suitable constructors to initialize the data members. Define methods `findArea()` and `findPerimeter()` to calculate and return the area and perimeter of the rectangle. Write a separate class **`MyRectangle`** containing the `main()` method to create and use `Rectangle` objects.

---

## 3. Box

**Question:**
Write a Java program to define a class **`Box`** with private data members `length`, `width`, and `height` of type `float`. Provide suitable constructors. Define methods `findVolume()` and `findSurfaceArea()` to calculate and return the volume and surface area of the box. Write a separate class **`MyBox`** containing the `main()` method to create and use `Box` objects.

---

## 4. Distance

**Question:**

Write a Java program to define a class **`Distance`** with private data members `meters` and `centimeters` of type `int`. Provide suitable constructors to initialize distance. Define the following member methods:

* `addDistance(Distance d)` to add two distance objects and return the result.
* `subtractDistance(Distance d)` to subtract one distance object from another and return the result.
* `displayDistance()` to display the distance in meters and centimeters format.

Write a separate class **`MyDistance`** containing the `main()` method to create and use `Distance` objects.
---

## 5. Student

**Question:**
Write a Java program to define a class **`Student`** with private data members `rollNo`, `name`, and marks of three subjects of type `float`. Provide suitable constructors. Define methods `findTotal()`, `findAverage()`, and `displayResult()`. Write a separate class **`MyStudent`** containing the `main()` method to create and use `Student` objects.

---

## 6. Time

**Question:**
Write a Java program to define a class **`Time`** with private data members `hours`, `minutes`, and `seconds` of type `int`. Provide suitable constructors. Define a method `addTime(Time t)` to add two time objects and return the result. Write a separate class **`MyTime`** containing the `main()` method to create and use `Time` objects.

---

## 7. Employee

**Question:**
Write a Java program to define a class **`Employee`** with private data members `empId`, `empName`, and `salary`. Provide suitable constructors. Define methods to calculate annual salary and display employee details. Write a separate class **`MyEmployee`** containing the `main()` method to create and use `Employee` objects.

---

## 8. Point (Distance Between Two Points)

**Question:**
Write a Java program to define a class **`Point`** with private data members `x` and `y` of type `float`. Provide suitable constructors. Define a method `findDistance(Point p)` to calculate and return the distance between two points. Write a separate class **`MyPoint`** containing the `main()` method to create and use `Point` objects.

---

## 9. Complex Number

**Question:**
Write a Java program to define a class **`Complex`** with private data members `real` and `imaginary` of type `float`. Provide suitable constructors. Define a method `addComplex(Complex c)` to add two complex numbers. Write a separate class **`MyComplex`** containing the `main()` method to create and use `Complex` objects.

---

## 10. Bank Account

**Question:**
Write a Java program to define a class **`BankAccount`** with private data members `accountNumber`, `accountHolderName`, and `balance`. Provide suitable constructors. Define methods `deposit()`, `withdraw()`, and `displayBalance()`. Write a separate class **`MyBankAccount`** containing the `main()` method to create and use `BankAccount` objects.

---


# Unit 4: Inheritance and Package

1. Create a base class named Bonus. The class should contain two fields salesID of type String and salesAmount of type double. Include a getBonus method that calculates a salesperson’s bonus using *bonus = sales * 0.05. Create a derived class named PremiumBonus from Bonus. The derived class’s getPremiumBonus method should calculate the bonus using *bonus = sales * 0.05 + (sales - 2500) * 0.01. Write a class with main method to create object of PremiumBonus class and use this object to find both bonus and premium bonus.

---

2. Write a Java program that uses interface to support multiple inheritance.

---

3. Assume that a bank maintains two kinds of account for its customers, one called savings account and the other current account. The savings account provides compound interest and withdrawal facilities but no cheque book facility. The current account provides cheque book facility but no interest. Current account holders should also maintain a minimum balance and if the balance falls below this level, a service charge is imposed.

  Create a class Account that stores customer name, account number and type of account. From this derive the classes Curr_act and Sav_act to make them more specific to their requirements. Include the necessary method in order to achieve the following tasks:
  
  a. Accept deposit from a customer and update the balance.
  
  b. Display the balance.
  
  c. Compute and deposit interest.
  
  d. Permit withdrawal and update the balance.
  
  e. Check for the minimum balance, impose penalty, if necessary, and update the balance.

---


---
