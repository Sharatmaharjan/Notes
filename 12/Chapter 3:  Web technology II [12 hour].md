## Chapter 3:  Web technology II [12 HRS]

- 3.1  Introduction
- 3.2  Server side and Client Side Scripting
- 3.3  Introduction of internet technology
- 3.4  Adding Java script to HTML page
- 3.5  Java script fundamental
- 3.6  Java Script Data types
- 3.7  Variables and operators
- 3.8  Functions and control structure if-else, if-else- if, switch-case, for, while, do while loop
- 3.9  Object based programming with Java Script and Event handling
- 3.10  Image, event and form objects
- 3.11  Form validation, JQuery
- 3.12  Server Side Scripting using PHP
- 3.13  Introduction to PHP: Hardware and Software Requirements
- 3.14  Object oriented programming with server side scripting
- 3.15 Basic PHP syntax
- 3.16 PHP data types
- 3.17 Basic Programming in PHP
- 3.18 Operators (Arithmetic, logical, comparison, operator precedence)
- 3.19 Variables Manipulation
- 3.20 Database Connectivity
- 3.21 Connecting server side script to database 
- 3.22 Making SQL queries
- 3.23 Fetching data sets getting data about data 
- 3.24 Creating SQL database with server side scripting
- 3.25 Displaying queries in tables

---
### 3.1  Introduction

Web Technology II is designed to equip us with the skills and knowledge required to build sophisticated, secure, and high-performing web applications. Through a mix of theoretical knowledge and practical exercises, we will gain a deep understanding of both the front-end and back-end aspects of web development. By the end of this course, we will be able to develop, deploy, and maintain complex web applications that meet modern standards.

---
### 3.2  Server side and Client Side Scripting

**Web Technology II - Server-Side and Client-Side Scripting**

In modern web development, scripting plays a crucial role in creating dynamic, interactive, and functional web applications. Understanding the distinction between server-side and client-side scripting, as well as their respective roles in web development, is essential.

### **1. Introduction to Scripting:**
- **Scripting Languages**: Lightweight programming languages used to automate tasks, manipulate data, and enhance web applications.
- **Purpose**: Improve the interactivity, functionality, and user experience of web pages.

### **2. Client-Side Scripting:**
Client-side scripting refers to code that runs in the user's browser, executed on the client side of the web architecture. 

#### **Key Concepts:**
- **Execution Environment**: The web browser (e.g., Chrome, Firefox, Safari).
- **Interaction with HTML/CSS**: Modifies the Document Object Model (DOM) and changes the presentation or behavior of the web page in real-time.
- **Speed**: Since the code runs locally in the user's browser, it can provide immediate feedback to user interactions, making the experience more responsive.

#### **Common Client-Side Scripting Languages:**
- **JavaScript**: The most widely used language for client-side scripting. It enables interactive features such as form validation, dynamic content updates, animations, and more.
- **TypeScript**: A superset of JavaScript that adds static typing, making it easier to manage large-scale applications.
- **HTML5 APIs**: Incorporate features like drag-and-drop, local storage, and multimedia controls.
- **JavaScript Libraries and Frameworks**: jQuery, React, Angular, and Vue.js simplify client-side scripting and offer tools to manage complex interactions.

#### **Use Cases:**
- **Form Validation**: Checking user input before submission.
- **Dynamic Content**: Loading content asynchronously without reloading the page (e.g., via AJAX).
- **User Interface Interactions**: Animations, sliders, and drop-down menus.
- **Single-Page Applications (SPA)**: Creating seamless, fast-loading web applications.

### **3. Server-Side Scripting:**
Server-side scripting refers to code that runs on the server, handling backend tasks such as database interactions, user authentication, and content management.

#### **Key Concepts:**
- **Execution Environment**: The web server (e.g., Apache, Nginx, Node.js server).
- **Interaction with Databases**: Directly communicates with the database to retrieve, store, and manage data.
- **Security**: Handles sensitive operations, such as authentication and authorization, securely on the server.

#### **Common Server-Side Scripting Languages:**
- **PHP**: A popular server-side language widely used for web development, especially in conjunction with MySQL.
- **Node.js**: JavaScript runtime built on Chrome's V8 engine, allowing JavaScript to be used for server-side scripting.
- **Python (Django, Flask)**: Python-based frameworks that provide robust tools for web development.
- **Ruby (Ruby on Rails)**: A framework that emphasizes convention over configuration for rapid development.
- **Java (Spring, Java EE)**: A powerful language often used for large-scale enterprise applications.
- **ASP.NET**: A Microsoft framework for building web applications and services.

#### **Use Cases:**
- **Database Operations**: CRUD (Create, Read, Update, Delete) operations.
- **User Authentication**: Managing login sessions, encryption, and access control.
- **Content Management**: Dynamic generation of web pages based on user interactions or database content.
- **Business Logic**: Performing calculations, processing payments, and other complex tasks that require secure, server-side execution.

### **4. Collaboration Between Client-Side and Server-Side Scripting:**

While client-side scripting enhances the user experience with interactive features, server-side scripting handles the heavy lifting behind the scenes. The collaboration between the two is essential for a smooth and functional web application.

#### **Key Points:**
- **AJAX**: Asynchronous JavaScript and XML (or JSON) enables client-side scripts to communicate with the server without reloading the page. This allows for dynamic content updates and more responsive applications.
- **Session Management**: Client-side scripts handle session cookies while server-side scripts manage user sessions and ensure security.
- **Form Handling**: Client-side validation provides quick feedback, while server-side validation ensures data integrity and security.
- **Content Rendering**: Server-side scripts generate dynamic HTML based on user input or database queries, which is then rendered by the client-side script for display.

### **5. Examples of Combined Usage:**
- **E-commerce Websites**: Client-side scripts manage the shopping cart, while server-side scripts process orders and manage inventory.
- **Social Media Platforms**: Client-side scripts update the feed in real-time, while server-side scripts handle user authentication and data storage.
- **Content Management Systems (CMS)**: Client-side scripts provide WYSIWYG (What You See Is What You Get) editors, while server-side scripts manage the content database and user permissions.

---

### 3.3  Introduction of internet technology


**Web Technology II - Introduction to Internet Technology**

Internet technology forms the foundation of modern web development and digital communication. It encompasses the systems, protocols, and tools that enable the global exchange of data and information. Understanding these technologies is crucial for developing web applications, navigating the digital landscape, and appreciating the complexity of the internet as a whole.

### **1. Overview of Internet Technology:**
- **Definition**: Internet technology refers to the suite of protocols, hardware, and software that support the operation and interconnection of computers and devices across the world, allowing for communication, data transfer, and access to information.
- **Evolution**: The internet has evolved from a simple network designed for academic research into a global infrastructure supporting diverse applications like web browsing, email, social media, streaming, e-commerce, and cloud computing.

### **2. Key Components of Internet Technology:**

#### **a. Internet Infrastructure:**
- **Servers and Data Centers**: Physical hardware where data and applications are stored and processed. Servers host websites, applications, and databases, while data centers provide large-scale infrastructure to support massive amounts of data.
- **Internet Service Providers (ISPs)**: Companies that provide access to the internet, enabling users to connect to the global network. ISPs manage the infrastructure necessary to transmit data over various types of networks (fiber optics, cable, DSL, etc.).
- **Transmission Media**: The physical channels through which data travels, including fiber optics, coaxial cables, and wireless networks. These media connect devices and data centers across vast distances.

#### **b. Internet Protocols and Standards:**
- **IP Addressing**: The Internet Protocol (IP) is responsible for assigning unique addresses to each device connected to the internet. IPv4 and IPv6 are the two versions of IP addressing, with IPv6 introduced to overcome the limitations of IPv4.
- **TCP/IP Model**: The fundamental protocol suite that governs communication over the internet. It includes:
  - **Transmission Control Protocol (TCP)**: Ensures reliable data transmission by breaking data into packets, transmitting them, and reassembling them at the destination.
  - **Internet Protocol (IP)**: Handles addressing and routing, ensuring that packets reach the correct destination.
- **HTTP/HTTPS**: HyperText Transfer Protocol (HTTP) is the protocol used for transmitting web pages over the internet. HTTPS is the secure version, encrypting data to protect against eavesdropping and tampering.
- **DNS (Domain Name System)**: Translates human-readable domain names (e.g., www.example.com) into IP addresses that computers use to identify each other on the network.

#### **c. Internet Services and Applications:**
- **World Wide Web (WWW)**: A system of interlinked hypertext documents and multimedia accessible via the internet. The web relies on the HTTP/HTTPS protocols and web browsers to display content.
- **Email**: One of the earliest and most widely used internet services, enabling asynchronous communication between users through protocols like SMTP, POP3, and IMAP.
- **File Transfer Protocol (FTP)**: A standard network protocol used to transfer files between a client and a server on a computer network.
- **VoIP (Voice over Internet Protocol)**: A technology that allows voice communication and multimedia sessions over the internet (e.g., Skype, Zoom).
- **Streaming Services**: Technologies that allow the real-time transmission of audio and video content over the internet, including platforms like YouTube, Netflix, and Spotify.

### **3. Internet Technologies for Web Development:**

#### **a. Web Browsers:**
- **Definition**: Software applications used to access and display web pages. Examples include Google Chrome, Mozilla Firefox, Microsoft Edge, and Safari.
- **Rendering Engines**: The component of the browser responsible for interpreting HTML, CSS, and JavaScript to display web content. Common engines include Blink (Chrome, Edge) and Gecko (Firefox).

#### **b. Web Servers:**
- **Definition**: Software that handles HTTP requests from clients (browsers) and serves web pages in response. Examples include Apache HTTP Server, Nginx, and Microsoft's IIS.
- **Server-Side Languages**: Technologies like PHP, Node.js, Python, and Ruby are used to build dynamic web applications that run on web servers.

#### **c. Web Development Tools:**
- **IDEs (Integrated Development Environments)**: Software applications that provide comprehensive facilities to developers for writing and testing web applications. Examples include Visual Studio Code, WebStorm, and Sublime Text.
- **Version Control Systems**: Tools like Git and GitHub that allow developers to track changes in code, collaborate with others, and manage project versions.

### **4. The Role of Internet Technology in Modern Applications:**

#### **a. Cloud Computing:**
- **Definition**: The delivery of computing services over the internet, including storage, processing power, and software. Cloud services like AWS, Google Cloud, and Azure provide scalable resources for web applications.
- **Applications**: Web hosting, database management, and deployment of applications in a scalable and cost-effective manner.

#### **b. Internet of Things (IoT):**
- **Definition**: A network of interconnected devices that communicate over the internet, collecting and sharing data. Examples include smart home devices, wearable technology, and industrial IoT applications.
- **Impact**: IoT technology has expanded the internet's reach beyond traditional computing devices, enabling new forms of automation and data-driven insights.

#### **c. Web 3.0 and Decentralization:**
- **Definition**: The next evolution of the web, focusing on decentralization, blockchain technology, and user privacy. Web 3.0 aims to give users greater control over their data and online interactions.
- **Technologies**: Blockchain, decentralized applications (dApps), and smart contracts are foundational to Web 3.0.

### **5. Challenges and Future Trends:**
- **Security Concerns**: As internet technology evolves, so do the threats, including cyber-attacks, data breaches, and privacy issues. Continuous advancements in cybersecurity are essential to protect users and data.
- **Scalability**: The growing number of devices and users on the internet requires scalable infrastructure to handle increased traffic and data.
- **AI and Machine Learning**: Integrating AI with internet technology to enhance user experiences, automate tasks, and improve decision-making processes.

---

### 3.4  Adding Java script to HTML page

**Web Technology II - Adding JavaScript to an HTML Page**

JavaScript is a powerful scripting language that enables you to add interactivity, dynamic content, and enhanced functionality to your web pages. Integrating JavaScript into an HTML page allows you to create more engaging user experiences, from simple effects like form validation to complex applications like games and data visualization tools.

### **1. Overview of JavaScript in Web Development:**
- **JavaScript**: A versatile, client-side scripting language that runs in the web browser. It can also be used on the server side with environments like Node.js.
- **Purpose**: JavaScript is used to manipulate the Document Object Model (DOM), handle events, validate user input, create animations, and perform asynchronous operations like loading data from a server.

### **2. Methods for Adding JavaScript to an HTML Page:**

#### **a. Inline JavaScript:**
- **Definition**: JavaScript code is embedded directly within an HTML element's `onEvent` attribute (e.g., `onclick`, `onmouseover`).
- **Usage**: Best suited for simple scripts or when adding quick interactivity to a single element.
- **Example**:
  ```html
  <button onclick="alert('Hello, World!')">Click Me</button>
  ```
  - When the button is clicked, an alert box will pop up with the message "Hello, World!".

#### **b. Internal JavaScript:**
- **Definition**: JavaScript code is placed within a `<script>` tag in the `<head>` or `<body>` section of the HTML document.
- **Usage**: Useful for including script that affects multiple elements or when you want to keep all your JavaScript code in one place within the HTML file.
- **Example**:
  ```html
  <!DOCTYPE html>
  <html>
  <head>
      <title>Internal JavaScript Example</title>
      <script>
          function showMessage() {
              alert('Hello, World!');
          }
      </script>
  </head>
  <body>
      <button onclick="showMessage()">Click Me</button>
  </body>
  </html>
  ```
  - The `showMessage` function is defined within the `<script>` tag and called when the button is clicked.

#### **c. External JavaScript:**
- **Definition**: JavaScript code is stored in a separate `.js` file, which is then linked to the HTML document using a `<script>` tag with the `src` attribute.
- **Usage**: Best practice for larger projects or when reusing scripts across multiple pages. It keeps the HTML clean and separates the structure/content (HTML) from the behavior (JavaScript).
- **Example**:
  **HTML File (`index.html`)**:
  ```html
  <!DOCTYPE html>
  <html>
  <head>
      <title>External JavaScript Example</title>
      <script src="script.js"></script>
  </head>
  <body>
      <button onclick="showMessage()">Click Me</button>
  </body>
  </html>
  ```
  **JavaScript File (`script.js`)**:
  ```javascript
  function showMessage() {
      alert('Hello, World!');
  }
  ```
  - The `script.js` file contains the JavaScript code, and it's linked to the HTML file using the `<script>` tag with the `src` attribute.

### **3. Best Practices for Adding JavaScript:**

#### **a. Placing Script Tags:**
- **Before Closing `</body>` Tag**: Placing the `<script>` tag just before the closing `</body>` tag ensures that the HTML content loads before the JavaScript executes, which can improve page load times.
  ```html
  <body>
      <!-- Page content -->
      <script src="script.js"></script>
  </body>
  ```
- **In the `<head>` Tag with `defer` Attribute**: If you place the script in the `<head>`, use the `defer` attribute to ensure the script runs after the HTML document has been fully parsed.
  ```html
  <head>
      <script src="script.js" defer></script>
  </head>
  ```
- **Asynchronous Loading with `async` Attribute**: The `async` attribute allows the script to load asynchronously with the HTML document. However, it may lead to issues if the script depends on elements that haven’t loaded yet.
  ```html
  <head>
      <script src="script.js" async></script>
  </head>
  ```

#### **b. Separating Concerns:**
- **HTML for Structure**: Keep HTML focused on content and structure.
- **CSS for Presentation**: Use CSS to style and layout the web page.
- **JavaScript for Behavior**: Implement interactivity and dynamic features using JavaScript. Separating these concerns enhances code maintainability and readability.

#### **c. Progressive Enhancement:**
- **Principle**: Design your web pages to work with basic functionality without JavaScript, then enhance them with additional features using JavaScript. This approach ensures that your website remains usable for users with JavaScript disabled or for search engines.

### **4. Common Use Cases for JavaScript in HTML Pages:**

#### **a. Form Validation:**
- **Client-Side Validation**: Check user input before it’s sent to the server, providing immediate feedback and reducing server load.
  ```javascript
  function validateForm() {
      let x = document.forms["myForm"]["fname"].value;
      if (x == "") {
          alert("Name must be filled out");
          return false;
      }
  }
  ```
  - The function `validateForm` checks if the "fname" field is empty and alerts the user if it is.

#### **b. DOM Manipulation:**
- **Dynamic Content**: Use JavaScript to modify HTML elements or CSS styles on the fly.
  ```javascript
  document.getElementById("myDiv").innerHTML = "Content has changed!";
  ```
  - Changes the content of an HTML element with the `id` "myDiv".

#### **c. Event Handling:**
- **User Interaction**: Respond to user actions like clicks, hovers, or keypresses.
  ```javascript
  document.getElementById("myButton").addEventListener("click", function() {
      alert("Button clicked!");
  });
  ```
  - Adds an event listener to a button, triggering an alert when the button is clicked.

### **5. Debugging JavaScript:**
- **Browser Developer Tools**: Most modern browsers (Chrome, Firefox, Edge) come with built-in developer tools that allow you to inspect elements, debug JavaScript, and view console logs.
  - **Console**: Displays errors, warnings, and custom log messages using `console.log()`.
  - **Breakpoints**: Pause script execution at specific lines of code to examine the state of your application.

### **Summary:**
Adding JavaScript to an HTML page is a fundamental skill in web development, enabling us to create interactive and dynamic web experiences. Whether we choose to use inline, internal, or external JavaScript depends on the complexity and scale of your project. By following best practices and understanding the different methods of integrating JavaScript, you can build web applications that are both functional and maintainable.

---

### 3.5  Java script fundamental, 3.6  Java Script Data types, 3.7  Variables and operators and 3.8  Functions and control structure if-else, if-else- if, switch-case, for, while, do while loop

JavaScript is a powerful and versatile programming language essential for creating interactive and dynamic web content. Understanding its fundamentals is crucial for web developers as it forms the basis of client-side scripting and can also be extended to server-side applications.

### **1. Introduction to JavaScript:**
- **JavaScript**: A lightweight, interpreted scripting language primarily used to create interactive effects within web browsers. It’s a core technology of the World Wide Web alongside HTML and CSS.
- **ECMAScript**: JavaScript is based on the ECMAScript standard. ECMAScript defines the language's specifications and features.

### **2. Basic Syntax and Structure:**

#### **a. Comments:**
- **Single-line Comment**: Use `//` to comment out a single line.
  ```javascript
  // This is a single-line comment
  ```
- **Multi-line Comment**: Use `/* ... */` to comment out multiple lines.
  ```javascript
  /*
  This is a multi-line comment
  */
  ```

#### **b. Variables:**
- **Definition**: Variables store data values that can be used and manipulated in a script.
- **Declaration**:
  - **Using `var`**: The traditional way to declare a variable (function-scoped).
    ```javascript
    var x = 10;
    ```
  - **Using `let`**: Introduced in ES6 (block-scoped).
    ```javascript
    let y = 20;
    ```
  - **Using `const`**: Declares a constant, a variable that cannot be reassigned (block-scoped).
    ```javascript
    const z = 30;
    ```
  
#### **c. Data Types:**
- **Primitive Data Types**:
  - **Number**: Numeric values (e.g., `42`, `3.14`).
  - **String**: Textual data, enclosed in quotes (e.g., `"Hello, World!"`).
  - **Boolean**: Logical values `true` or `false`.
  - **Undefined**: A variable that has been declared but not assigned a value.
  - **Null**: Represents the intentional absence of any object value.
  - **Symbol**: A unique and immutable primitive introduced in ES6.

- **Example**:
  ```javascript
  let age = 25;           // Number
  let name = "John Doe";  // String
  let isStudent = true;   // Boolean
  let salary;             // Undefined
  let car = null;         // Null
  ```

#### **d. Operators:**
- **Arithmetic Operators**: Perform mathematical operations.
  - `+` (addition), `-` (subtraction), `*` (multiplication), `/` (division), `%` (modulus)
  - Example:
    ```javascript
    let a = 5;
    let b = 2;
    let sum = a + b;  // sum is 7
    ```
  
- **Assignment Operators**: Assign values to variables.
  - `=`, `+=`, `-=`, `*=`, `/=`
  - Example:
    ```javascript
    let x = 10;
    x += 5;  // x is now 15
    ```
  
- **Comparison Operators**: Compare values and return a boolean (`true` or `false`).
  - `==` (equal to), `!=` (not equal to), `===` (strict equal to), `!==` (strict not equal to), `>` (greater than), `<` (less than)
  - Example:
    ```javascript
    let x = 10;
    let y = "10";
    console.log(x == y);   // true (loose comparison)
    console.log(x === y);  // false (strict comparison)
    ```
  
- **Logical Operators**: Perform logical operations.
  - `&&` (and), `||` (or), `!` (not)
  - Example:
    ```javascript
    let x = true;
    let y = false;
    console.log(x && y);  // false
    console.log(x || y);  // true
    console.log(!x);      // false
    ```

#### **e. Conditional Statements:**
- **If-Else Statement**: Executes code based on a condition.
  - Example:
    ```javascript
    let age = 18;
    if (age >= 18) {
        console.log("You are an adult.");
    } else {
        console.log("You are a minor.");
    }
    ```

- **Switch Statement**: Selects one of many blocks of code to execute.
  - Example:
    ```javascript
    let fruit = "apple";
    switch (fruit) {
        case "banana":
            console.log("Banana is yellow.");
            break;
        case "apple":
            console.log("Apple is red.");
            break;
        default:
            console.log("Unknown fruit.");
    }
    ```

### **3. Functions:**

#### **a. Function Declaration:**
- **Syntax**:
  ```javascript
  function functionName(parameters) {
      // code to be executed
  }
  ```
- **Example**:
  ```javascript
  function greet(name) {
      return "Hello, " + name + "!";
  }
  console.log(greet("John"));  // Outputs: Hello, John!
  ```

#### **b. Function Expression:**
- **Anonymous Function**: Assigned to a variable.
  ```javascript
  let square = function(x) {
      return x * x;
  };
  console.log(square(4));  // Outputs: 16
  ```

#### **c. Arrow Functions:**
- **Introduced in ES6**: A concise way to write functions using `=>`.
  - **Syntax**:
    ```javascript
    let sum = (a, b) => a + b;
    console.log(sum(5, 3));  // Outputs: 8
    ```
  
#### **d. Scope and Hoisting:**
- **Scope**: Refers to the accessibility of variables. JavaScript has function scope and block scope.
  - **Global Scope**: Variables declared outside any function have global scope and can be accessed from anywhere in the code.
  - **Local Scope**: Variables declared inside a function have local scope and can only be accessed within that function.

- **Hoisting**: JavaScript's default behavior of moving declarations to the top of the current scope before code execution.
  - Example:
    ```javascript
    console.log(x);  // undefined due to hoisting
    var x = 5;
    ```

### **4. Objects and Arrays:**

#### **a. Objects:**
- **Definition**: Collections of key-value pairs. An object can contain properties and methods.
- **Syntax**:
  ```javascript
  let person = {
      firstName: "John",
      lastName: "Doe",
      age: 30,
      fullName: function() {
          return this.firstName + " " + this.lastName;
      }
  };
  console.log(person.fullName());  // Outputs: John Doe
  ```

#### **b. Arrays:**
- **Definition**: Ordered collections of values, which can be accessed by their index.
- **Syntax**:
  ```javascript
  let colors = ["red", "green", "blue"];
  console.log(colors[0]);  // Outputs: red
  colors.push("yellow");   // Adds a new element to the array
  console.log(colors.length);  // Outputs: 4
  ```

### **5. Looping Constructs:**

#### **a. For Loop:**
- **Syntax**:
  ```javascript
  for (initialization; condition; increment) {
      // code to be executed
  }
  ```
- **Example**:
  ```javascript
  for (let i = 0; i < 5; i++) {
      console.log("Number: " + i);
  }
  ```

#### **b. While Loop:**
- **Syntax**:
  ```javascript
  while (condition) {
      // code to be executed
  }
  ```
- **Example**:
  ```javascript
  let i = 0;
  while (i < 5) {
      console.log("Number: " + i);
      i++;
  }
  ```

#### **c. Do-While Loop:**
- **Syntax**:
  ```javascript
  do {
      // code to be executed
  } while (condition);
  ```
- **Example**:
  ```javascript
  let i = 0;
  do {
      console.log("Number: " + i);
      i++;
  } while (i < 5);
  ```

### **6. Events and Event Handling:**

#### **a. Event Listeners:**
- **Definition**: JavaScript can react to user actions like clicks, key presses, and mouse movements through events.
- **Example**:
  ```javascript
  document.getElementById("myButton").addEventListener("click", function() {
      alert("Button was clicked!");
  });
  ```

### **7. Error Handling:**

#### **a. Try-Catch:**
- **Syntax**:
  ```javascript
  try {
      // code that may throw an error
  } catch (err) {
      // code to handle the error
  } finally {
      // code that will always run, regardless of error
  }
  ```
- **Example**:
  ```javascript
  try {
      let result = x / y;
  } catch (err) {
      console.log("

Error: " + err.message);
  } finally {
      console.log("Execution completed.");
  }
  ```

### **8. Debugging JavaScript:**

#### **a. Console Logging:**
- **Usage**: `console.log()` is a simple way to debug by printing out variable values and program flow in the browser console.
  ```javascript
  let x = 5;
  console.log("The value of x is: " + x);
  ```

#### **b. Breakpoints:**
- **Definition**: You can set breakpoints in your JavaScript code using browser developer tools to pause execution and inspect variables at specific points.

### **Summary:**
JavaScript fundamentals provide the foundation for creating interactive web pages. Mastery of variables, functions, loops, objects, arrays, and event handling is essential for developing dynamic web content. Understanding these basics will enable us to write efficient and effective code, and lay the groundwork for more advanced JavaScript concepts.

---

### 3.9  Object based programming with Java Script and Event handling

JavaScript is not just a simple scripting language but also a powerful tool for object-based programming. This allows developers to create complex, reusable code structures and handle user interactions efficiently through event handling mechanisms.

### **1. Introduction to Object-Based Programming in JavaScript:**

#### **a. What is Object-Based Programming?**
- **Object-Based Programming (OBP)**: A paradigm centered around objects, which are instances of classes or prototypes in JavaScript. In OBP, the focus is on the creation and manipulation of objects rather than functions alone.
- **Objects**: Containers for related data (properties) and functions (methods). Objects help organize code and model real-world entities.

#### **b. Objects in JavaScript:**
- JavaScript is an object-oriented language, but it’s also object-based because it doesn't strictly enforce class-based inheritance. Instead, it uses prototypes.
- **Prototype-Based Inheritance**: Objects can inherit properties and methods from other objects. Every object in JavaScript has a prototype object.

#### **c. Creating and Using Objects:**

1. **Object Literals**:
   - **Definition**: The simplest way to create an object is using object literals.
   - **Syntax**:
     ```javascript
     let person = {
         firstName: "John",
         lastName: "Doe",
         age: 30,
         fullName: function() {
             return this.firstName + " " + this.lastName;
         }
     };
     console.log(person.fullName());  // Outputs: John Doe
     ```

2. **Constructor Functions**:
   - **Definition**: Functions that serve as blueprints for creating multiple objects of the same type.
   - **Syntax**:
     ```javascript
     function Person(firstName, lastName, age) {
         this.firstName = firstName;
         this.lastName = lastName;
         this.age = age;
         this.fullName = function() {
             return this.firstName + " " + this.lastName;
         };
     }
     let person1 = new Person("Jane", "Doe", 25);
     console.log(person1.fullName());  // Outputs: Jane Doe
     ```

3. **ES6 Classes**:
   - **Definition**: Introduced in ES6, classes are syntactical sugar over prototype-based inheritance.
   - **Syntax**:
     ```javascript
     class Person {
         constructor(firstName, lastName, age) {
             this.firstName = firstName;
             this.lastName = lastName;
             this.age = age;
         }
         fullName() {
             return this.firstName + " " + this.lastName;
         }
     }
     let person2 = new Person("Alice", "Smith", 28);
     console.log(person2.fullName());  // Outputs: Alice Smith
     ```

### **2. Event Handling in JavaScript:**

#### **a. What is Event Handling?**
- **Events**: Actions or occurrences that happen in the browser, such as clicking a button, submitting a form, or pressing a key. JavaScript can detect and respond to these events using event listeners.
- **Event Handling**: The process of capturing and responding to events triggered by users or the browser.

#### **b. Adding Event Listeners:**
- **Syntax**:
  ```javascript
  element.addEventListener(event, function, useCapture);
  ```
  - `element`: The HTML element you want to attach the event listener to.
  - `event`: The type of event, such as `"click"`, `"mouseover"`, `"keydown"`, etc.
  - `function`: The function to be executed when the event occurs.
  - `useCapture`: An optional boolean parameter indicating whether to use event capturing or bubbling (default is `false`).

- **Example**:
  ```javascript
  document.getElementById("myButton").addEventListener("click", function() {
      alert("Button clicked!");
  });
  ```

#### **c. Commonly Used Events:**
- **Mouse Events**: `"click"`, `"dblclick"`, `"mouseover"`, `"mouseout"`
- **Keyboard Events**: `"keydown"`, `"keyup"`, `"keypress"`
- **Form Events**: `"submit"`, `"change"`, `"focus"`, `"blur"`
- **Window Events**: `"load"`, `"resize"`, `"scroll"`

#### **d. Event Propagation:**
- **Event Propagation**: The order in which events are handled. JavaScript event handling consists of two main phases:
  1. **Capturing Phase**: The event starts from the root and goes down to the target element.
  2. **Bubbling Phase**: The event starts from the target element and bubbles up to the root.

- **Stopping Propagation**:
  - `event.stopPropagation()`: Stops the event from bubbling up or capturing down.
  - **Example**:
    ```javascript
    document.getElementById("parent").addEventListener("click", function(event) {
        alert("Parent clicked!");
        event.stopPropagation();
    });

    document.getElementById("child").addEventListener("click", function() {
        alert("Child clicked!");
    });
    ```

#### **e. Event Delegation:**
- **Definition**: A technique that allows you to handle events efficiently by using a single event listener to manage all events for child elements within a parent element.
- **Example**:
  ```javascript
  document.getElementById("parentList").addEventListener("click", function(event) {
      if (event.target && event.target.nodeName == "LI") {
          alert("List item clicked: " + event.target.innerText);
      }
  });
  ```
  - Here, the event listener is added to the parent `ul` element but handles clicks on its child `li` elements.

### **3. Working with the DOM:**

#### **a. DOM Manipulation:**
- **DOM (Document Object Model)**: A programming interface for HTML documents. It represents the page structure as a tree of objects that can be manipulated with JavaScript.

- **Selecting Elements**:
  - `document.getElementById("id")`: Selects an element by its ID.
  - `document.getElementsByClassName("class")`: Selects elements by their class name.
  - `document.getElementsByTagName("tag")`: Selects elements by their tag name.
  - `document.querySelector("selector")`: Selects the first element that matches a CSS selector.
  - `document.querySelectorAll("selector")`: Selects all elements that match a CSS selector.

- **Modifying Elements**:
  - **Inner HTML**: `element.innerHTML = "New content";`
  - **CSS Styles**: `element.style.color = "blue";`
  - **Attributes**: `element.setAttribute("attribute", "value");`

- **Example**:
  ```javascript
  let header = document.getElementById("header");
  header.innerHTML = "Welcome to My Website!";
  header.style.color = "blue";
  ```

### **4. Advanced Event Handling Techniques:**

#### **a. Handling Multiple Events:**
- **Example**:
  ```javascript
  let button = document.getElementById("myButton");
  button.addEventListener("click", function() {
      console.log("Button clicked");
  });
  button.addEventListener("mouseover", function() {
      console.log("Mouse over button");
  });
  ```

#### **b. Removing Event Listeners:**
- **Syntax**: `element.removeEventListener(event, function);`
- **Example**:
  ```javascript
  function showAlert() {
      alert("Button clicked!");
  }
  let button = document.getElementById("myButton");
  button.addEventListener("click", showAlert);
  button.removeEventListener("click", showAlert);  // Removes the click event listener
  ```

### **5. Error Handling in Event Listeners:**
- **Try-Catch Blocks**: Use `try-catch` within event listeners to handle errors gracefully.
  - **Example**:
    ```javascript
    button.addEventListener("click", function() {
        try {
            // Code that might throw an error
            let result = x / y;
        } catch (error) {
            console.error("An error occurred: " + error.message);
        }
    });
    ```

---

### 3.10  Image, event and form objects

### **Web Technology II - Image, Event, and Form Objects in JavaScript**

JavaScript provides a range of objects that allow developers to interact with and manipulate images, forms, and events on web pages. Understanding these objects is crucial for creating dynamic, interactive, and user-friendly web applications.

### **1. Image Objects:**

#### **a. What is an Image Object?**
- **Definition**: The `Image` object in JavaScript allows you to manipulate images in an HTML document. You can dynamically change image sources, set properties, and handle image-related events.

#### **b. Creating and Manipulating Image Objects:**
- **Creating an Image Object**:
  - **Syntax**:
    ```javascript
    let img = new Image();
    img.src = "image.jpg";
    ```
  - This creates a new `Image` object and sets its source to the specified image file.

- **Accessing and Modifying Image Properties**:
  - **Example**:
    ```javascript
    let img = document.getElementById("myImage");
    img.src = "newImage.jpg";  // Changing the source of the image
    img.alt = "A description of the image";  // Setting the alt text
    img.width = 200;  // Setting the width of the image
    img.height = 100;  // Setting the height of the image
    ```

#### **c. Handling Image Events:**
- **onload Event**: Triggered when the image has been fully loaded.
  ```javascript
  img.onload = function() {
      console.log("Image loaded successfully.");
  };
  ```

- **onerror Event**: Triggered if there is an error loading the image.
  ```javascript
  img.onerror = function() {
      console.error("Failed to load the image.");
  };
  ```

### **2. Event Objects:**

#### **a. What is an Event Object?**
- **Definition**: When an event occurs in a web page, such as a click or key press, the browser creates an `Event` object. This object contains details about the event, such as its type, target element, and mouse or keyboard coordinates.

#### **b. Accessing Event Properties:**
- **Example**:
  ```javascript
  document.getElementById("myButton").addEventListener("click", function(event) {
      console.log("Event type: " + event.type);  // Outputs: click
      console.log("Event target: " + event.target.id);  // Outputs the ID of the clicked button
      console.log("Mouse X: " + event.clientX + ", Mouse Y: " + event.clientY);  // Outputs the coordinates of the click
  });
  ```

- **Common Event Properties**:
  - `event.type`: The type of event (e.g., `"click"`, `"mouseover"`).
  - `event.target`: The element that triggered the event.
  - `event.currentTarget`: The element to which the event handler is attached.
  - `event.clientX`, `event.clientY`: The X and Y coordinates of the mouse pointer at the time of the event.

#### **c. Event Methods:**
- **Preventing Default Action**:
  - **Syntax**: `event.preventDefault();`
  - **Example**:
    ```javascript
    document.getElementById("myLink").addEventListener("click", function(event) {
        event.preventDefault();  // Prevents the link from being followed
        alert("Link was clicked, but default action prevented.");
    });
    ```

- **Stopping Event Propagation**:
  - **Syntax**: `event.stopPropagation();`
  - **Example**:
    ```javascript
    document.getElementById("parentDiv").addEventListener("click", function() {
        alert("Parent clicked");
    });

    document.getElementById("childDiv").addEventListener("click", function(event) {
        event.stopPropagation();  // Prevents the event from bubbling up to the parent
        alert("Child clicked");
    });
    ```

### **3. Form Objects:**

#### **a. What is a Form Object?**
- **Definition**: The `Form` object represents an HTML `<form>` element in JavaScript. It provides properties and methods for interacting with and validating form data.

#### **b. Accessing Form and Input Elements:**
- **Example**:
  ```javascript
  let form = document.getElementById("myForm");
  let username = form.elements["username"].value;  // Accessing the value of an input field by its name
  ```

- **Common Form Properties**:
  - `form.elements`: A collection of all form controls (inputs, selects, textareas) within the form.
  - `form.action`: The URL to which the form data will be submitted.
  - `form.method`: The HTTP method used for form submission (GET or POST).

#### **c. Form Validation:**
- **Client-Side Validation**:
  - **Example**:
    ```javascript
    form.addEventListener("submit", function(event) {
        let username = form.elements["username"].value;
        if (username === "") {
            alert("Username cannot be empty.");
            event.preventDefault();  // Prevents form submission if validation fails
        }
    });
    ```

- **HTML5 Validation Attributes**:
  - `required`: Ensures that an input field is not empty.
  - `pattern`: Defines a regex pattern that the input value must match.
  - `minlength` and `maxlength`: Set the minimum and maximum length of the input value.

#### **d. Handling Form Submission:**
- **Event Handling**:
  - **Example**:
    ```javascript
    form.addEventListener("submit", function(event) {
        let data = new FormData(form);  // Collecting form data
        console.log("Form submitted");
        // You can send the data using AJAX or perform additional processing here
        event.preventDefault();  // Prevents the default form submission
    });
    ```

- **Using AJAX to Submit Forms**:
  - **Example**:
    ```javascript
    form.addEventListener("submit", function(event) {
        event.preventDefault();
        let data = new FormData(form);
        fetch(form.action, {
            method: form.method,
            body: data,
        })
        .then(response => response.text())
        .then(result => {
            console.log("Form submission response:", result);
        })
        .catch(error => {
            console.error("Error submitting form:", error);
        });
    });
    ```

---



