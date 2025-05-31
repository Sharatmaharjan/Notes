# **Unit 1: Introduction to Data Communications**  
**Lecture Hours: 3**  

## **1. Introduction to Data Communications**  
**Definition:**  
Data communication involves the transfer of digital or analog data between devices through a transmission medium, such as wired or wireless channels.  

### **Key Characteristics of Effective Data Communication:**  
1. **Delivery** – Ensures data reaches the intended destination.  
2. **Accuracy** – Guarantees error-free transmission.  
3. **Timeliness** – Provides data within an acceptable time frame (e.g., real-time applications require low latency).  
4. **Jitter** – Refers to inconsistent delays in packet arrival, critical for real-time applications like VoIP.  

**Practical Example:**  
- **Email Transmission:** A user composes an email and sends it. The email travels through multiple network devices (routers, switches) before reaching the recipient’s inbox.  

---

## **2. Data Communication Networks**  

### **A. Components of a Network**  
1. **Sender/Transmitter** – Initiates data transmission (e.g., a computer, smartphone).  
2. **Receiver** – Accepts the transmitted data (e.g., a server, another computer).  
3. **Message/Data** – The information being transmitted (e.g., text, video, audio).  
4. **Transmission Medium** – The physical or wireless path (e.g., fiber optic cable, Wi-Fi).  
5. **Protocols** – Rules governing data exchange (e.g., TCP/IP, HTTP).  

![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/BIM/4th%20sem/BDCN/images/Unit%201/2.png)

**Question:**  
*Q: List and briefly explain the five key components of a data communication network.*  

### **B. Types of Networks**  
1. **Local Area Network (LAN)**  
   - Covers a small geographic area (e.g., office, home).  
   - High data transfer rates.  
   - Example: A university’s computer lab network.  

2. **Wide Area Network (WAN)**  
   - Spans large distances (e.g., cities, countries).  
   - Uses leased lines or satellites.  
   - Example: The Internet.  

<br>

3. **Metropolitan Area Network (MAN)**  
   - Covers a city or campus.  
   - Example: A city-wide broadband network.  

4. **Personal Area Network (PAN)**  
   - Short-range (e.g., Bluetooth, USB).  
   - Example: Connecting a smartphone to a wireless headset.  

**Question:**  
*Q: Differentiate between LAN and WAN with examples.*  

---

## **3. Network Models**  

### **A. Open Systems Interconnection (OSI) Reference Model**   

**Introduction to OSI Model**  
The **OSI (Open Systems Interconnection) model** is a **7-layer conceptual framework** that standardizes network communication. It ensures interoperability between different vendors' devices by defining how data moves from one system to another.  

**Key Features:**  
- Developed by **ISO (International Organization for Standardization)** in 1984.  
- Provides a **layered approach** to network communication.  
- Each layer has **specific functions** and interacts with adjacent layers.  


**OSI Model Layers (Top to Bottom)**  

| **Layer No.** | **Layer Name** | **Function** | **Protocols & Devices** |
|--------------|--------------|--------------|------------------------|
| **7** | **Application Layer** | Provides user interface and network services (e.g., email, file transfer). | HTTP, FTP, SMTP, DNS |
| **6** | **Presentation Layer** | Translates, encrypts, and compresses data for secure transmission. | SSL/TLS, JPEG, MPEG |
| **5** | **Session Layer** | Establishes, manages, and terminates connections between applications. | NetBIOS, RPC, SIP |
| **4** | **Transport Layer** | Ensures reliable end-to-end data delivery (error recovery, flow control). | TCP, UDP, SCTP |
| **3** | **Network Layer** | Routes data packets between different networks using logical addressing. | IP, ICMP, OSPF, Router |
| **2** | **Data Link Layer** | Provides error-free node-to-node communication (MAC addressing). | Ethernet, PPP, Switch, NIC |
| **1** | **Physical Layer** | Transmits raw bitstream over a physical medium (cables, signals). | RJ45, Wi-Fi, Hub, Repeater |

<br>
<br>


**OSI Model Diagram**  

```
+-------------------------+
|     Application (7)     | → HTTP, FTP, SMTP
+-------------------------+
|    Presentation (6)     | → SSL, JPEG, MPEG
+-------------------------+
|       Session (5)       | → NetBIOS, SIP
+-------------------------+
|      Transport (4)      | → TCP, UDP
+-------------------------+
|       Network (3)       | → IP, Router
+-------------------------+
|    Data Link (2)        | → Ethernet, Switch
+-------------------------+
|      Physical (1)       | → RJ45, Hub
+-------------------------+
```

**Key Functions of Each Layer**  

**A. Application Layer (Layer 7)**  
- Provides **user applications** (web browsers, email).  
- Protocols: **HTTP (Web), SMTP (Email), FTP (File Transfer), DNS (Domain Name System).**  

**B. Presentation Layer (Layer 6)**  
- **Encryption (SSL/TLS), Compression (ZIP), Encoding (ASCII, Unicode).**  

**C. Session Layer (Layer 5)**  
- **Manages sessions** (e.g., login/logout).  
- Protocols: **NetBIOS (Windows), SIP (VoIP).**  

**D. Transport Layer (Layer 4)**  
- **Ensures reliable delivery** (TCP = connection-oriented, UDP = connectionless).  
- **Flow control & error checking.**  

**E. Network Layer (Layer 3)**  
- **Logical addressing (IP addresses).**  
- **Routing (Routers use OSPF, BGP).**  

**F. Data Link Layer (Layer 2)**  
- **MAC addressing (Ethernet).**  
- **Switches operate here.**  

**G. Physical Layer (Layer 1)**  
- **Transmits raw bits (electrical/optical signals).**  
- Devices: **Hubs, Repeaters, Cables (Fiber, Copper).**  

---
<br>
<br>
<br>

**Optional for Exam**
**OSI Model Explained with Example (Email Sending Process)**  

**Step-by-Step Data Flow:**  
1. **Application Layer (User sends email via SMTP)**  
   - Email client (e.g., Outlook) formats the message.  
   - Uses **SMTP** protocol.  

2. **Presentation Layer (Encryption & Compression)**  
   - Email is encrypted (**SSL/TLS**) for security.  

3. **Session Layer (Establishes Connection)**  
   - Maintains the session between sender and mail server.  

4. **Transport Layer (Breaks Data into Segments)**  
   - **TCP** ensures reliable delivery.  

5. **Network Layer (Adds IP Address for Routing)**  
   - **IP** adds source & destination addresses.  

6. **Data Link Layer (Frames Data with MAC Addresses)**  
   - **Ethernet** adds MAC addresses.  

7. **Physical Layer (Transmits as Electrical Signals)**  
   - Data sent via **cable or Wi-Fi**.  

At the receiver’s end, the process reverses (**decapsulation**).  

---

### **B. Internet Model (TCP/IP Model – 4 Layers)**  
1. **Network Interface Layer** – Combines OSI’s Physical and Data Link layers.  
2. **Internet Layer** – Handles routing (e.g., IP).  
3. **Transport Layer** – Manages data flow (e.g., TCP, UDP).  
4. **Application Layer** – Combines OSI’s Session, Presentation, and Application layers.  
 

### **C. Message Transmission Using Layers**  
- **Encapsulation:** Data moves down the layers, with each layer adding a header.  
- **Decapsulation:** At the receiver’s end, headers are removed as data moves up. 

**OSI Model vs. TCP/IP Model**  

| **OSI Model (7 Layers)** | **TCP/IP Model (4 Layers)** |
|-------------------------|----------------------------|
| More detailed, theoretical | Practical, used in the Internet |
| Session, Presentation separate | Combined into Application |
| Network Layer = Routing | Internet Layer = IP |
| Transport Layer = TCP/UDP | Same as OSI |
| Data Link + Physical = Network Interface | Same as OSI |

**Questions (10 Marks)**  

**Explain the OSI model with a diagram and protocols used at each layer.**  
- **Answer:**  
  - Define OSI model (7 layers).  
  - Draw the diagram.  
  - List functions & protocols for each layer.  
 

---

## **4. Network Standards**  

### **A. Importance of Standards**  
- Ensures compatibility between devices.  
- Promotes interoperability (e.g., Wi-Fi standards allow different devices to connect).  

### **B. Standards-Making Process**  
1. **Proposal** – A need is identified.  
2. **Drafting** – Experts develop specifications.  
3. **Review & Approval** – Organizations like IEEE, ITU-T finalize standards.  

### **C. Common Standards**  
1. **IEEE 802.11** – Wi-Fi standards.  
2. **Ethernet (IEEE 802.3)** – Wired LAN standard.  
3. **TCP/IP** – Internet protocol suite.  

**Question:**  
*Q: Why are network standards important? Name two key networking standards.*  

---

## **5. Future Trends**  

### **A. Wireless LAN and BYOD (Bring Your Own Device)**  
- Employees use personal devices (laptops, smartphones) for work.  
- Security challenges (e.g., unauthorized access).  

### **B. Internet of Things (IoT)**  
- Smart devices communicate over the internet (e.g., smart homes, wearables).  
- Example: A smart thermostat adjusts temperature based on user behavior.  

### **C. Massively Online (Cloud Computing, Big Data)**  
- Cloud services (AWS, Azure) enable remote data storage and processing.  
- Big data analytics improves decision-making.  

**Question:**  
*Q: Explain how IoT is transforming modern businesses with an example.*  

---

<br>
<br>
<br>
<br>
<br>

## **Summary & Key Takeaways**  
✔ **Data communication** requires delivery, accuracy, timeliness, and minimal jitter.  
✔ **Network types** include LAN, WAN, MAN, and PAN.  
✔ **OSI (7 layers)** and **TCP/IP (4 layers)** models define structured communication.  
✔ **Standards** (e.g., IEEE 802.11, TCP/IP) ensure interoperability.  
✔ **Future trends:** BYOD, IoT, and cloud computing are shaping networking.  

