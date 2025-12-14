
# ✅ Unit 3: OOP Concepts

## 1. Circle

```java
class Circle {
    private float radius;

    Circle() {
        radius = 0;
    }

    Circle(float r) {
        radius = r;
    }

    float findArea() {
        return 3.14f * radius * radius;
    }

    float findCircumference() {
        return 2 * 3.14f * radius;
    }
}

class MyCircle {
    public static void main(String[] args) {
        Circle c = new Circle(5);
        System.out.println("Area = " + c.findArea());
        System.out.println("Circumference = " + c.findCircumference());
    }
}
```

---

## 2. Rectangle

```java
class Rectangle {
    private float length, breadth;

    Rectangle() {
        length = breadth = 0;
    }

    Rectangle(float l, float b) {
        length = l;
        breadth = b;
    }

    float findArea() {
        return length * breadth;
    }

    float findPerimeter() {
        return 2 * (length + breadth);
    }
}

class MyRectangle {
    public static void main(String[] args) {
        Rectangle r = new Rectangle(4, 6);
        System.out.println("Area = " + r.findArea());
        System.out.println("Perimeter = " + r.findPerimeter());
    }
}
```

---

## 3. Box

```java
class Box {
    private float length, width, height;

    Box(float l, float w, float h) {
        length = l;
        width = w;
        height = h;
    }

    float findVolume() {
        return length * width * height;
    }

    float findSurfaceArea() {
        return 2 * (length * width + width * height + height * length);
    }
}

class MyBox {
    public static void main(String[] args) {
        Box b = new Box(3, 4, 5);
        System.out.println("Volume = " + b.findVolume());
        System.out.println("Surface Area = " + b.findSurfaceArea());
    }
}
```

---

## 4. Distance

```java
class Distance {
    private int meters, centimeters;

    Distance(int m, int cm) {
        meters = m;
        centimeters = cm;
    }

    Distance addDistance(Distance d) {
        int cm = centimeters + d.centimeters;
        int m = meters + d.meters + cm / 100;
        cm = cm % 100;
        return new Distance(m, cm);
    }

    Distance subtractDistance(Distance d) {
        int m = meters - d.meters;
        int cm = centimeters - d.centimeters;
        if (cm < 0) {
            cm += 100;
            m--;
        }
        return new Distance(m, cm);
    }

    void displayDistance() {
        System.out.println(meters + " meters " + centimeters + " centimeters");
    }
}

class MyDistance {
    public static void main(String[] args) {
        Distance d1 = new Distance(5, 70);
        Distance d2 = new Distance(3, 90);

        Distance sum = d1.addDistance(d2);
        Distance diff = d1.subtractDistance(d2);

        sum.displayDistance();
        diff.displayDistance();
    }
}
```

---

## 5. Student

```java
class Student {
    private int rollNo;
    private String name;
    private float m1, m2, m3;

    Student(int r, String n, float a, float b, float c) {
        rollNo = r;
        name = n;
        m1 = a;
        m2 = b;
        m3 = c;
    }

    float findTotal() {
        return m1 + m2 + m3;
    }

    float findAverage() {
        return findTotal() / 3;
    }

    void displayResult() {
        System.out.println("Roll: " + rollNo);
        System.out.println("Name: " + name);
        System.out.println("Total: " + findTotal());
        System.out.println("Average: " + findAverage());
    }
}

class MyStudent {
    public static void main(String[] args) {
        Student s = new Student(1, "Ram", 70, 80, 90);
        s.displayResult();
    }
}
```

---

## 6. Time

```java
class Time {
    private int hours, minutes, seconds;

    Time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    Time addTime(Time t) {
        int s = seconds + t.seconds;
        int m = minutes + t.minutes + s / 60;
        int h = hours + t.hours + m / 60;
        s %= 60;
        m %= 60;
        return new Time(h, m, s);
    }

    void display() {
        System.out.println(hours + ":" + minutes + ":" + seconds);
    }
}

class MyTime {
    public static void main(String[] args) {
        Time t1 = new Time(2, 45, 30);
        Time t2 = new Time(1, 20, 40);
        Time t3 = t1.addTime(t2);
        t3.display();
    }
}
```

---

## 7. Employee

```java
class Employee {
    private int empId;
    private String empName;
    private double salary;

    Employee(int id, String name, double sal) {
        empId = id;
        empName = name;
        salary = sal;
    }

    double getAnnualSalary() {
        return salary * 12;
    }

    void display() {
        System.out.println(empId + " " + empName);
        System.out.println("Annual Salary = " + getAnnualSalary());
    }
}

class MyEmployee {
    public static void main(String[] args) {
        Employee e = new Employee(101, "Sita", 30000);
        e.display();
    }
}
```

---

## 8. Point

```java
class Point {
    private float x, y;

    Point(float a, float b) {
        x = a;
        y = b;
    }

    double findDistance(Point p) {
        return Math.sqrt(Math.pow(x - p.x, 2) + Math.pow(y - p.y, 2));
    }
}

class MyPoint {
    public static void main(String[] args) {
        Point p1 = new Point(2, 3);
        Point p2 = new Point(5, 7);
        System.out.println("Distance = " + p1.findDistance(p2));
    }
}
```

---

## 9. Complex

```java
class Complex {
    private float real, imaginary;

    Complex(float r, float i) {
        real = r;
        imaginary = i;
    }

    Complex addComplex(Complex c) {
        return new Complex(real + c.real, imaginary + c.imaginary);
    }

    void display() {
        System.out.println(real + " + " + imaginary + "i");
    }
}

class MyComplex {
    public static void main(String[] args) {
        Complex c1 = new Complex(2, 3);
        Complex c2 = new Complex(4, 5);
        Complex c3 = c1.addComplex(c2);
        c3.display();
    }
}
```

---

## 10. Bank Account

```java
class BankAccount {
    private int accountNumber;
    private String accountHolderName;
    private double balance;

    BankAccount(int acc, String name, double bal) {
        accountNumber = acc;
        accountHolderName = name;
        balance = bal;
    }

    void deposit(double amt) {
        balance += amt;
    }

    void withdraw(double amt) {
        balance -= amt;
    }

    void displayBalance() {
        System.out.println("Balance = " + balance);
    }
}

class MyBankAccount {
    public static void main(String[] args) {
        BankAccount b = new BankAccount(123, "Hari", 5000);
        b.deposit(2000);
        b.withdraw(1000);
        b.displayBalance();
    }
}
```

---

# ✅ Unit 4: Inheritance and Interface

---

## 1. Inheritance (Bonus)

```java
class Bonus {
    String salesID;
    double salesAmount;

    double getBonus() {
        return salesAmount * 0.05;
    }
}

class PremiumBonus extends Bonus {
    double getPremiumBonus() {
        return salesAmount * 0.05 + (salesAmount - 2500) * 0.01;
    }
}

class MyBonus {
    public static void main(String[] args) {
        PremiumBonus p = new PremiumBonus();
        p.salesID = "S101";
        p.salesAmount = 5000;

        System.out.println("Bonus = " + p.getBonus());
        System.out.println("Premium Bonus = " + p.getPremiumBonus());
    }
}
```

---

## 2. Multiple Inheritance using Interface

```java
interface Camera {
    void takePhoto();
}

interface MusicPlayer {
    void playMusic();
}

class SmartPhone implements Camera, MusicPlayer {
    public void takePhoto() {
        System.out.println("Photo captured");
    }

    public void playMusic() {
        System.out.println("Music playing");
    }
}

class MyPhone {
    public static void main(String[] args) {
        SmartPhone s = new SmartPhone();
        s.takePhoto();
        s.playMusic();
    }
}
```

---


