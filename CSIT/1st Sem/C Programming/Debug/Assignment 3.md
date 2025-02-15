### **1. Library Management System**  
**Task:** Write a C program to simulate a library management system with the following operations:  
- **Add Book:** Collect book details (ID, Title, Author, Quantity).  
- **Search Book:** Search for a book by title or ID.  
- **Issue Book:** Reduce the quantity by one if available.  
- **Return Book:** Increase the quantity by one.  
- **Display All Books:** List all available books.  

**Functions:**  
```c
void addBook();  
void searchBook();  
void issueBook();  
void returnBook();  
void displayBooks();  
```

---

### **2. Student Record Management**  
**Task:** Create a program to manage student records, including:  
- **Add Student:** Collect and store student details (Roll Number, Name, Marks).  
- **Display Records:** Show all students' records.  
- **Search Student:** Find and display a record using Roll Number.  
- **Calculate Average Marks:** Compute and display the average of all students' marks.  

**Functions:**  
```c
void addStudent();  
void displayRecords();  
void searchStudent(int rollNo);  
float calculateAverage();  
```

---

### **3. Inventory Management System**  
**Task:** Develop an inventory management system to handle:  
- **Add Item:** Record item details (Item Code, Name, Price, Quantity).  
- **View Inventory:** Display all items.  
- **Sell Item:** Reduce quantity based on sales and update inventory.  
- **Restock Item:** Increase item quantity.  

**Functions:**  
```c
void addItem();  
void viewInventory();  
void sellItem(int itemCode, int quantity);  
void restockItem(int itemCode, int quantity);  
```

---

### **4. Airline Reservation System**  
**Task:** Simulate an airline ticket reservation system with the following options:  
- **Book Seat:** Collect passenger details and assign a seat.  
- **Cancel Reservation:** Remove a passenger's reservation.  
- **View Available Seats:** Display all available seats.  
- **View Passenger List:** Display all reserved seats with passenger details.  

**Functions:**  
```c
void bookSeat();  
void cancelReservation();  
void viewAvailableSeats();  
void viewPassengerList();  
```

---

### **5. Hospital Management System**  
**Task:** Design a hospital management system to manage patient records with options to:  
- **Register Patient:** Collect patient details (ID, Name, Age, Disease).  
- **Search Patient:** Find patient details by ID.  
- **Discharge Patient:** Remove patient record.  
- **View All Patients:** List all admitted patients.  

**Functions:**  
```c
void registerPatient();  
void searchPatient(int id);  
void dischargePatient(int id);  
void viewPatients();  
```

---
