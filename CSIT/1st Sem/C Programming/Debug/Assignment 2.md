**C Programming Assignment: Banking Simulation Using Functions**  
**Note: please use functions only,declare variables inside main and make sure it is for single user**
### **Question:**  
Write a C program to simulate basic banking operations using functions. The program should perform the following operations:

#### **Operations to Implement:**  
1. **Create Account:** Collect user details such as Account Number, Name, and Initial Balance.  
2. **Deposit Amount:** Add money to the account balance.  
3. **Withdraw Amount:** Subtract money from the account balance (ensure sufficient balance).  
4. **Check Balance:** Display the current account balance.  
5. **Exit:** Terminate the program.  

---

#### **Program Requirements:**  
- **Function Implementation:** Create separate functions for each operation:  
  ```c
  void createAccount();
  void deposit(float amount);
  void withdraw(float amount);
  void checkBalance();
  ```
  
- **Function Prototypes:** Use appropriate prototypes and call all functions from `main()`.  
- **Input Validation:**  
  - Ensure the user provides valid amounts (e.g., no negative values).  
  - Check for sufficient balance before allowing withdrawals.  
- **User Feedback:** Display appropriate messages for successful operations and errors.  
- **Loop for Repeated Operations:** Continuously display the menu and prompt for user input until the user chooses to exit.  

---

#### **Sample Output:**  
```
Banking System Menu:  
1. Create Account  
2. Deposit Amount  
3. Withdraw Amount  
4. Check Balance  
5. Exit  

Enter your choice: 1  
Enter Account Number: 12345  
Enter Account Holder Name: John Doe  
Enter Initial Deposit: 1000.00  
Account created successfully!  

Banking System Menu:  
1. Create Account  
2. Deposit Amount  
3. Withdraw Amount  
4. Check Balance  
5. Exit  

Enter your choice: 2  
Enter deposit amount: 500  
Deposit successful! New Balance: 1500.00  

Enter your choice: 3  
Enter withdrawal amount: 2000  
Insufficient balance!  

Enter your choice: 4  
Current Balance: 1500.00  

Enter your choice: 5  
Thank you for using the banking system. Goodbye!  
```

---
