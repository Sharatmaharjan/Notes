# UNIT 3: Input and Output LAB

## A. FORMATTED INPUT OUTPUT

### a. scanf() - Formatted Input

1. Write a program to demonstrate the usage of whitespace characters in the scanf() function, specifically to handle leading whitespace or newlines when reading characters.

**Note:** The %c specifier doesn't automatically skip leading whitespace (e.g., newline from previous input). Adding a space before %c tells scanf to skip it.

**Sample Input:**
```
5
a
```
**Sample Output:**
```
Enter a number:
Enter a character:
Number=5 	 Character=a
```

**Real-World Usage:** This technique is useful in interactive console applications, like user registration forms, where inputs like numbers followed by characters (e.g., age then gender) need to be read without issues from leftover newlines, ensuring smooth data entry in tools like banking software or surveys.

2. Write a program to demonstrate the use of ordinary characters (like '/') in the control string of the scanf() function to parse structured input like dates.

**Sample Input:**
```
15/06/1995
```
**Sample Output:**
```
Enter your date of birth in sequence day, month and year separated by / character:
Your date of birth is: 15 day  6 month  1995 year.
```

**Real-World Usage:** Parsing dates or structured data like this is common in database entry systems or log file processors, where inputs like "YYYY-MM-DD" need to be broken down accurately for storage in financial transaction records or event logging.

3. Write a program to read a student's marks in a subject, ensuring the input is limited to two digits (less than 100) using field width in scanf().

**Note:** If more than two digits are entered, only the first two are read, and the rest are left in the input buffer.

**Sample Input 1:**
```
85
```
**Sample Output 1:**
```
Enter your marks in C:
Your entered marks=85
```

**Sample Input 2:**
```
123
```
**Sample Output 2:**
```
Enter your marks in C:
Your entered marks=12
```

**Real-World Usage:** Limiting input digits is helpful in grading systems or inventory apps where values like scores or quantities have fixed ranges, preventing overflow errors in constrained databases like those in educational software.

4. Write a program to demonstrate skipping an input field using the '*' character in scanf().

**Sample Input:**
```
10 20 30
```
**Sample Output:** (c may vary based on compiler, but typically garbage)
```
Enter three numbers:
a=10 	 b=30 	 c=0  (or garbage value)
```

**Real-World Usage:** Skipping fields is useful in data import tools, like CSV parsers, where certain columns (e.g., timestamps in logs) can be ignored to focus on relevant data, streamlining processing in analytics software.

5. Write a program to input a string from the user and display it on the screen using scanf() and printf().

**Note:** %s stops at whitespace, so only single words are read.

**Sample Input:**
```
Sharat
```
**Sample Output:**
```
Enter your name:
Your name is: Sharat
```

**Real-World Usage:** Basic string input is essential for username prompts in login systems or search queries in e-commerce apps, where single-word inputs like product names are common.

6. Write a program to take an input string from the user, allowing only uppercase letters.

**Note:** Stops reading at the first non-uppercase character.

**Sample Input:**
```
SHARAT123
```
**Sample Output:**
```
Enter your name in uppercase:
Your name is: SHARAT
```

**Real-World Usage:** Restricting to uppercase is used in license key validators or stock ticker inputs, ensuring consistency in case-sensitive systems like financial trading platforms.

7. Write a program to read a string with multiple words (including spaces) using scanf() and display it.

**Note:** %[^\n] reads until newline.

**Sample Input:**
```
Sharat Maharjan
```
**Sample Output:**
```
Enter your full name:
Your name is: Sharat Maharjan
```

**Real-World Usage:** Reading full strings with spaces is crucial for address fields in shipping software or full names in HR systems, allowing natural user input without restrictions.

### b. printf() - Formatted Output

8. What is the output of the following program? (Focus on integer and float formatting).

```c
#include <stdio.h>

int main() {
    int n = 1234;
    float m = 12.31456;
    printf(" n=%d", n);
    printf("\n n=%6d", n);
    printf("\n n=%2d", n);
    printf("\n n=%-6d", n);
    printf("\n n=%06d", n);
    printf("\n n=%.2f", m);
    return 0;
}
```

**Output:**
```
 n=1234
 n=  1234
 n=1234
 n=1234  
 n=001234
 n=12.31
```

**Real-World Usage:** Formatted integer and float output is used in report generation, like financial statements where numbers need alignment or padding for readability in invoices or dashboards.

9. What is the output of the following program? (Focus on character formatting).

```c
#include <stdio.h>

int main() {
    char ch = 'A';
    printf("ch=%2c", ch);
    printf("\nch=%5c", ch);
    printf("\nch=%-5c", ch);
    return 0;
}
```

**Output:**
```
ch= A
ch=    A
ch=A    
```

**Real-World Usage:** Character formatting helps in creating aligned text outputs, such as in menu displays or ASCII art in command-line games, improving user interface aesthetics.

10. What is the output of the following program? (Focus on string formatting).

```c
#include <stdio.h>

int main() {
    char str[10] = "MY NEPAL";
    printf("%s", str);
    printf("\n%10s", str);
    printf("\n%-10s", str);
    printf("\n%.4s", str);
    printf("\n%4s", str);
    printf("\n%10.6s", str);
    printf("\n%-10.6s", str);
    return 0;
}
```

**Output:** ("MY NEPAL" is 8 characters)
```
MY NEPAL
  MY NEPAL
MY NEPAL  
MY N
MY NEPAL
    MY NEP
MY NEP    
```

**Real-World Usage:** String formatting is applied in logging systems or table prints, where strings need truncation or alignment, like in debug outputs or console-based reports.

11. Write a program to display an integer, a float, and a string value using a single printf() function.

**Sample Output:**
```
integer=10 	 float=2.500000 	 string=Sharat
```

**Real-World Usage:** Combining multiple types in one print is efficient for debugging or status updates in embedded systems, like sensor readings (int temp, float humidity, string status) in IoT devices.

## B. UNFORMATTED INPUT OUTPUT

12. Write a program to read a character from the keyboard using getchar() and display it using putchar().

**Sample Input:**
```
M
```
**Sample Output:**
```
Enter your gender:
Your gender is:M
```

**Real-World Usage:** Unformatted char I/O is used in password inputs (without echo) or simple yes/no prompts in scripts, like confirmation dialogs in installation wizards.

13. Write a program to read two characters from the keyboard: one using getch() (no echo) and another using getche() (with echo), then display them using putch().

**Sample Input:** (1st not echoed, 2nd echoed)
```
x (not shown)
y (shown as y)
```
**Sample Output:**
```
Enter 1st character:
Enter 2nd character:y
1st character: x
2nd character: y
```

**Real-World Usage:** getch/getche are useful for secure inputs like PINs in ATM software or games requiring hidden key presses, enhancing security or interactivity.

14. Write a program to read a string with multiple words (including spaces) using gets() and display it using puts().

**Sample Input:**
```
Sharat Maharjan
```
**Sample Output:**
```
Enter your name:
Your name is:Sharat Maharjan
```

**Real-World Usage:** gets/puts handle full lines in chat applications or note-taking tools, but note: gets is unsafe; prefer fgets in production for buffer safety.


15. Write a program to read a floating-point number with exactly two decimal places using scanf() field width and precision.

**Sample Input:**
```
12.345
```
**Sample Output:**
```
Enter a float with two decimals (e.g., 12.34):
Entered value: 12.34
```

**Real-World Usage:** Precision in floats is critical for currency inputs in e-commerce or scientific measurements in lab software, ensuring accurate rounding without overflow.

16. Write a program to read a string gets(), and display it using puts().

**Sample Input:**
```
Sharat Maharjan
```
**Sample Output:**
```
Enter your full name:
Your name is:Sharat Maharjan
```

**Real-World Usage:** fgets is used in secure file readers or user inputs in web servers, preventing buffer overflows that could lead to vulnerabilities like in network protocols.

17. Write a program to demonstrate precision and width in printf() for floating-point numbers.

**Output:**
```
Pi with default: 3.141593
Pi with 2 decimals: 3.14
Pi right-padded to 10 chars:     3.1416
Pi left-padded to 10 chars: 3.1416    
```

**Real-World Usage:** Float formatting is essential in data visualization tools or reports, like displaying GPS coordinates or stock prices with specific decimals for clarity in apps.
