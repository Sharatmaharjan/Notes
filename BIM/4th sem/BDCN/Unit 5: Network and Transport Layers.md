# **Unit 5: Network and Transport Layers**  [7 LHs]
 

## **1. Introduction**  
The **Network Layer (Layer 3)** and **Transport Layer (Layer 4)** of the OSI model play crucial roles in data communication.  

- **Network Layer**: Responsible for logical addressing, routing, and forwarding data packets across different networks.  
- **Transport Layer**: Ensures end-to-end communication, error recovery, flow control, and data segmentation.  

### **Key Functions:**  
| **Layer**       | **Functions** |
|-----------------|--------------|
| **Network Layer** | Logical addressing (IP), Routing, Fragmentation, Congestion Control |
| **Transport Layer** | Connection management, Error control, Flow control, Multiplexing/Demultiplexing | 

---  

## **2. Transport Layer Protocols**  
### **Transmission Control Protocol (TCP)**  
- **Connection-oriented**: Establishes a connection before data transfer (Three-way handshake).  
- **Reliable**: Uses acknowledgments (ACKs) and retransmissions for error recovery.  
- **Flow Control**: Uses sliding window protocol to manage data flow.  
- **Congestion Control**: Adjusts transmission rate to avoid network congestion.  

#### **TCP Header Format**  
![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/BIM/4th%20sem/BDCN/images/Unit%205/1%20tcp%20header%20format.png)  


## TCP Header Fields

### 1. **Source Port (16 bits)**

* **Purpose**: Identifies the **sending port number** on the source device.
* **Why it matters**: It allows the receiver to know which application (like a web browser or FTP client) sent the data.
* ✅ *Example*: A browser might use a random port like 54321 when connecting to a web server.


### 2. **Destination Port (16 bits)**

* **Purpose**: Identifies the **receiving port number** on the destination device.
* **Why it matters**: It tells the destination which application should handle the incoming data.
* ✅ *Example*: Web servers use port 80 (HTTP) or 443 (HTTPS).


### 3. **Sequence Number (32 bits)**

* **Purpose**: Represents the **number of the first byte** of data in this TCP segment.
* **Why it matters**: Ensures that data arrives in the correct order. Each byte of data sent over TCP is numbered.
* ✅ *Example*: If sequence number = 1000 and data is 100 bytes, next segment’s sequence number will be 1100.


### 4. **Acknowledgment Number (32 bits)**

* **Purpose**: If the ACK flag is set, this field contains the **next expected byte** from the sender.
* **Why it matters**: Helps the sender know that previous data was received successfully (used for reliability).
* ✅ *Example*: ACK = 1100 means "I received everything up to byte 1099, send me from 1100 next."


### 5. **Data Offset / Header Length (4 bits)**

* **Purpose**: Specifies the size of the TCP header in 32-bit words.
* **Why it matters**: Tells where the data starts in the segment (important if header includes options).
* ✅ *Example*: Value 5 = 5 × 4 = 20 bytes of header.


### 6. **Reserved (3 bits)**

* **Purpose**: Reserved for future use; must be zero.
* **Why it matters**: Reserved for possible later extension or functionality.


### 7. **Control Flags (9 bits total, main 6 used)**

Control how the TCP connection behaves. Each flag is 1 bit (on/off):

| Flag    | Full Name      | Purpose                                                          |
| ------- | -------------- | ---------------------------------------------------------------- |
| **URG** | Urgent         | Urgent data is being sent.                                       |
| **ACK** | Acknowledgment | Acknowledgment field is valid.                                   |
| **PSH** | Push           | Push data to application immediately (e.g., interactive typing). |
| **RST** | Reset          | Reset the connection immediately.                                |
| **SYN** | Synchronize    | Start of a connection (used in handshake).                       |
| **FIN** | Finish         | End of the connection.                                           |

✅ *Example*: A packet with `SYN` flag starts a connection. One with `FIN` ends it.


### 8. **Window Size (16 bits)**

* **Purpose**: Specifies the **amount of data (in bytes)** the sender is willing to receive.
* **Why it matters**: Implements **flow control**, preventing the sender from overwhelming the receiver.
* ✅ *Example*: Window size = 1024 means “I can receive 1024 bytes now.”


### 9. **Checksum (16 bits)**

* **Purpose**: Error-detection for both header and data.
* **Why it matters**: Ensures data integrity. If checksum fails at receiver, the segment is discarded.
* ✅ *Example*: A wrong checksum means data was corrupted in transit.


### 10. **Urgent Pointer (16 bits)**

* **Purpose**: Points to the **end of urgent data** (used only if URG flag is set).
* **Why it matters**: Tells the receiver to prioritize this data.
* ✅ *Example*: Used rarely; might signal emergency control messages.


### 11. **Options (variable)**

* **Purpose**: Supports extra features like window scaling, timestamps, selective ACKs.
* **Why it matters**: Enhances TCP with performance optimizations.
* ✅ *Example*: TCP window scaling option allows larger window sizes than 65535.


### 12. **Padding (variable)**

* **Purpose**: Adds extra bits to make the header length a multiple of 32 bits(4bytes).
* **Why it matters**: Ensures alignment and proper parsing by receivers.
* ✅ *Example*: If options are 10 bytes, 2 bytes of padding added to make header 32-bit aligned.

---


#### **Three-Way Handshake (Connection Establishment)**  
1. **SYN**: Client sends SYN packet to server.  
2. **SYN-ACK**: Server acknowledges with SYN-ACK.  
3. **ACK**: Client sends final ACK.  

![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/BIM/4th%20sem/BDCN/images/Unit%205/1%20three%20way%20handshake.jpg)   

#### **Advantages of TCP**  
✔ Reliable data delivery  
✔ Flow and congestion control  
✔ Ordered data transmission  

#### **Disadvantages of TCP**  
✖ Higher overhead due to acknowledgments  
✖ Slower than UDP due to connection setup  

---  

### **User Datagram Protocol (UDP)**  
- **Connectionless**: No handshake, faster but unreliable.  
- **No Error Recovery**: No retransmissions or acknowledgments.  
- **Low Overhead**: Suitable for real-time applications (VoIP, video streaming).  

#### **UDP Header Format**  
![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/BIM/4th%20sem/BDCN/images/Unit%205/1%20UDP-header.jpg)   


## UDP Header Fields

### 1. **Source Port (16 bits)**

* **Purpose**: Identifies the **sending port number** on the source device.
* **Why it matters**: Helps the receiver know which application sent the data. This field can be zero if the sender doesn’t need to specify a port (optional).
* ✅ *Example*: A video streaming app might use a specific port to send data.


### 2. **Destination Port (16 bits)**

* **Purpose**: Identifies the **receiving port number** on the destination device.
* **Why it matters**: Directs the datagram to the correct application or service on the receiver side. This is mandatory.
* ✅ *Example*: DNS queries typically use destination port 53.


### 3. **Length (16 bits)**

* **Purpose**: Specifies the **total length** of the UDP datagram, including header and data, in bytes.
* **Why it matters**: Allows the receiver to know where the UDP packet ends. The minimum value is 8 bytes (header only, no data).
* ✅ *Example*: If the length is 20, then 12 bytes of data follow the 8-byte header.


### 4. **Checksum (16 bits)**

* **Purpose**: Provides **error detection** for the UDP header and data.
* **Why it matters**: Helps verify the integrity of the datagram. If the checksum is incorrect, the packet is discarded. It is optional in IPv4 but mandatory in IPv6.
* ✅ *Example*: A corrupted packet will fail checksum validation and be ignored by the receiver.


#### **Advantages of UDP**  
✔ Low latency and faster transmission  
✔ Suitable for real-time applications  
✔ Minimal header overhead  

#### **Disadvantages of UDP**  
✖ No reliability (packets may be lost)  
✖ No congestion or flow control  

#### **TCP vs UDP Comparison Table**  
| **Feature**       | **TCP** | **UDP** |
|------------------|--------|--------|
| **Connection**   | Connection-oriented | Connectionless |
| **Reliability**  | Reliable (ACKs, retransmissions) | Unreliable |
| **Ordering**     | In-order delivery | No ordering |
| **Speed**        | Slower (overhead) | Faster |
| **Use Cases**    | HTTP, FTP, Email | VoIP, Gaming, Streaming |

---  

## **3. Network Layer Protocols**  
### **Internet Protocol (IP)**  
- Provides **logical addressing (IP addresses)** for devices.  
- **IPv4**: 32-bit address (e.g., 192.168.1.1)  
- **IPv6**: 128-bit address (e.g., 2001:0db8:85a3::8a2e:0370:7334)  

#### **IPv4 Header Format**  
![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/BIM/4th%20sem/BDCN/images/Unit%205/2%20IPv4-Datagram-Header.jpg)  


## IPv4 Header Fields

### 1. **Version (4 bits)**

* **Purpose**: Specifies the IP protocol version.
* **Why it matters**: Indicates that the packet is an IPv4 packet (value = 4). Helps devices know how to interpret the header.
* ✅ *Example*: Version field = 4 means IPv4; IPv6 packets have version = 6.


### 2. **Internet Header Length (IHL) (4 bits)**

* **Purpose**: Specifies the length of the IP header in 32-bit words.
* **Why it matters**: Indicates where the data (payload) starts after the header. Minimum value is 5 (20 bytes).
* ✅ *Example*: IHL = 6 means header length is 6 × 4 = 24 bytes (includes options).


### 3. **Type of Service (ToS) / Differentiated Services (8 bits)**

* **Purpose**: Specifies priority and quality of service parameters for the packet.
* **Why it matters**: Helps routers handle packets differently based on priority, delay, throughput, or reliability requirements.
* ✅ *Example*: A packet marked for low delay might be prioritized for voice traffic.


### 4. **Total Length (16 bits)**

* **Purpose**: Specifies the entire packet size (header + data) in bytes.
* **Why it matters**: Lets the receiver know how much data to read for this packet. Maximum is 65,535 bytes.
* ✅ *Example*: Total Length = 1500 means 1500 bytes including header and payload.


### 5. **Identification (16 bits)**

* **Purpose**: Uniquely identifies fragments of the original packet.
* **Why it matters**: Helps receivers reassemble fragmented packets correctly.
* ✅ *Example*: All fragments of a packet carry the same Identification number.


### 6. **Flags (3 bits)**

* **Purpose**: Control fragmentation of packets.
* **Why it matters**: Indicates whether the packet can be fragmented or if more fragments follow.
* ✅ *Example*: The "Don't Fragment" (DF) flag prevents fragmentation.


### 7. **Fragment Offset (13 bits)**

* **Purpose**: Indicates the position of this fragment in the original packet, measured in 8-byte blocks.
* **Why it matters**: Used by the receiver to correctly reassemble fragmented packets.
* ✅ *Example*: Fragment offset = 100 means this fragment starts at byte 800 (100 × 8).


### 8. **Time to Live (TTL) (8 bits)**

* **Purpose**: Limits the packet’s lifetime to prevent infinite looping.
* **Why it matters**: Decreases by one at each router hop; if it reaches zero, the packet is discarded.
* ✅ *Example*: TTL = 64 means the packet can traverse up to 64 routers.


### 9. **Protocol (8 bits)**

* **Purpose**: Indicates the protocol used in the data portion of the packet (e.g., TCP, UDP, ICMP).
* **Why it matters**: Helps the receiver know how to process the payload.
* ✅ *Example*: Protocol = 6 means TCP; 17 means UDP.


### 10. **Header Checksum (16 bits)**

* **Purpose**: Error-checking of the IP header.
* **Why it matters**: Ensures header integrity; corrupted packets are discarded.
* ✅ *Example*: Checksum recalculated at each router hop.


### 11. **Source IP Address (32 bits)**

* **Purpose**: The IP address of the sender.
* **Why it matters**: Identifies where the packet originated from.
* ✅ *Example*: Source IP = 192.168.1.10.


### 12. **Destination IP Address (32 bits)**

* **Purpose**: The IP address of the receiver.
* **Why it matters**: Identifies where the packet should be delivered.
* ✅ *Example*: Destination IP = 172.217.0.46 (Google).


### 13. **Options (variable length)**

* **Purpose**: Optional fields for network testing, security, or routing control.
* **Why it matters**: Used rarely, but provide extra functionality like record route or timestamp.
* ✅ *Example*: Option to record the route the packet takes.


### 14. **Padding (variable length)**

* **Purpose**: Adds extra bits so the header length is a multiple of 32 bits.
* **Why it matters**: Ensures proper alignment for processing.
* ✅ *Example*: If options length is not multiple of 4 bytes, padding bytes are added.


#### **IPv4 vs IPv6 Comparison**  
| **Feature**       | **IPv4** | **IPv6** |
|------------------|---------|---------|
| **Address Size** | 32-bit  | 128-bit |
| **Address Format** | Dotted Decimal (192.168.1.1) | Hexadecimal (2001:0db8::) |
| **Header Complexity** | Complex (variable-length) | Simplified (fixed 40-byte) |
| **Security**     | Optional (IPSec) | Built-in (IPSec) |
| **NAT Requirement** | Yes (due to scarcity) | No (large address space) |

#### **IP Addressing and Subnetting (Numerical Example)**  
**Problem:** Divide `192.168.10.0/24` into 4 subnets.  
**Solution:**  
- New subnet mask: `/26` (since \(2^2 = 4\) subnets).  
- Subnets:  
  1. `192.168.10.0/26` (Hosts: 1-62)  
  2. `192.168.10.64/26` (Hosts: 65-126)  
  3. `192.168.10.128/26` (Hosts: 129-190)  
  4. `192.168.10.192/26` (Hosts: 193-254)  

---  

## **Key Concepts with Examples**  
### **Fragmentation in Network Layer**  
- If a packet exceeds **MTU (Maximum Transmission Unit)**, it is fragmented.  
- Example: MTU = 1500 bytes, Packet size = 4000 bytes → Fragmented into 3 packets.  

### **TCP Congestion Control (Theoretical)**  
- **Slow Start**: Exponential increase in window size until threshold.  
- **Congestion Avoidance**: Linear increase after threshold.  
- **Fast Retransmit**: If 3 duplicate ACKs received, retransmit lost packet.  

---  

## **Summary**  
✔ **TCP** is reliable but slow; **UDP** is fast but unreliable.  
✔ **IPv4** uses 32-bit addresses, **IPv6** uses 128-bit.  
✔ **Subnetting** divides networks for efficient addressing.  
✔ **Three-way handshake** establishes TCP connections.  
✔ **Sliding window** in TCP manages flow control.  

---

# **4. Transport Layer Functions**    

### **Key Functions of the Transport Layer**  
a. **Linking to the Application Layer** (Port Addressing)  
b. **Segmenting and Reassembling Data**  
c. **Session Management** (Connection Establishment & Termination)  
d. **Error Control & Flow Control**  
e. **Multiplexing & Demultiplexing**   

---  

## **a. Linking to the Application Layer (Port Addressing)**  
- The Transport Layer uses **port numbers** to identify different applications.  
- **Well-known ports**:  
  - HTTP (Port 80), HTTPS (443), FTP (21), SSH (22), DNS (53)  
- **Ephemeral ports**: Temporary ports assigned to client applications.  

### **Example: Web Browsing (HTTP)**  
- **Client** sends a request from port **49152** (random) to **Server Port 80**.  
- **Server** responds back to **Client Port 49152**.  

#### **Why Ports are Needed?**  
✔ Allows multiple applications to run simultaneously.  
✔ Ensures correct data delivery to the right application.  

---  

## **b. Segmenting and Reassembling Data**  
- **Segmentation**: Breaking large data into smaller **segments (TCP)** or **datagrams (UDP)**.  
- **Reassembly**: Putting segments back in order at the receiver.  

### **Example: File Transfer (FTP)**  
- A **10 MB file** is divided into **1500-byte segments** (if MTU = 1500 bytes).  
- Each segment has a **sequence number** for reassembly.  

#### **Advantages of Segmentation**  
✔ Efficient transmission over networks with varying MTUs.  
✔ Prevents large data blocks from congesting the network.  

#### **Disadvantages**  
✖ Adds overhead (headers for each segment).  
✖ Requires buffering and reassembly at the receiver.  

---  

## **c. Session Management (Connection Control)**  
### **TCP Connection Management (3-Way Handshake)**  
1. **SYN** → Client initiates connection.  
2. **SYN-ACK** → Server acknowledges.  
3. **ACK** → Client confirms.  

### **TCP Connection Termination (4-Way Handshake)**  
1. **FIN** → Host A requests closure.  
2. **ACK** → Host B acknowledges.  
3. **FIN** → Host B sends its own FIN.  
4. **ACK** → Host A confirms.  

#### **Why Proper Session Management is Important?**  
✔ Ensures reliable data transfer.  
✔ Prevents half-open connections wasting resources.  

---  

## **d. Error Control & Flow Control**  
### **Error Control in TCP**  
- **Acknowledgements (ACKs)**: Receiver confirms received segments.  
- **Retransmission (Timeout)**: Lost packets are resent.  

### **Flow Control (Sliding Window Protocol)**  
- Adjusts transmission speed based on receiver’s buffer capacity.   

#### **Example of Sliding Window**  
- **Window Size = 3** → Sender can transmit 3 packets before waiting for ACK.  
- If ACK for Packet 2 is lost, sender retransmits from Packet 2.  

---  

## **e. Multiplexing & Demultiplexing**  
- **Multiplexing**: Combining multiple application data into one transport layer segment.  
- **Demultiplexing**: Separating received data for different applications.  

### **Example: Web Server Handling Multiple Requests**  
- A single server uses **port 80 (HTTP)** but serves multiple clients using different **ephemeral ports**.  

---  

## **Summary Table: Transport Layer Functions**  
| **Function**               | **Description** | **Protocol Example** |  
|----------------------------|----------------|----------------------|  
| **Port Addressing**         | Links data to correct app using ports | TCP/UDP |  
| **Segmentation**            | Breaks data into smaller units | TCP (Segments), UDP (Datagrams) |  
| **Session Management**      | Establishes & terminates connections | TCP (3-Way Handshake) |  
| **Error Control**           | Detects & recovers lost packets | TCP (ACKs, Retransmission) |  
| **Flow Control**            | Prevents sender from overwhelming receiver | TCP (Sliding Window) |  
| **Multiplexing/Demultiplexing** | Combines/Separates data streams | TCP/UDP |  

---  

# **5. Addressing in Network and Transport Layers**   

## **a. Introduction to Addressing**  
Addressing is a fundamental concept in networking that ensures data is correctly routed from source to destination. The **Network Layer (IP addressing)** and **Data Link Layer (MAC addressing)** work together to achieve this.  

### **Types of Addressing**  
1. **Logical Addressing (IP Addresses)** – Used at the **Network Layer**.  
2. **Physical Addressing (MAC Addresses)** – Used at the **Data Link Layer**.  
3. **Port Addressing (Port Numbers)** – Used at the **Transport Layer**.  

---  

## **b. Assigning Addresses**  
### **A. IP Addressing (Logical Addressing)**  
- **IPv4**: 32-bit address (e.g., `192.168.1.1`)  
- **IPv6**: 128-bit address (e.g., `2001:0db8:85a3::8a2e:0370:7334`)  

#### **IPv4 Address Classes**  
| **Class** | **Range** | **Purpose** |  
|-----------|----------------|------------|  
| **A**     | 1.0.0.0 – 126.255.255.255 | Large Networks |  
| **B**     | 128.0.0.0 – 191.255.255.255 | Medium Networks |  
| **C**     | 192.0.0.0 – 223.255.255.255 | Small Networks |  
| **D**     | 224.0.0.0 – 239.255.255.255 | Multicasting |  
| **E**     | 240.0.0.0 – 255.255.255.255 | Reserved |  
 

#### **Private vs Public IP Addresses**  
| **Type** | **Range** | **Usage** |  
|----------|----------------|----------|  
| **Private** | 10.0.0.0/8, 172.16.0.0/12, 192.168.0.0/16 | Internal networks (NAT needed) |  
| **Public** | All others | Internet communication |  

#### **Subnetting (Numerical Example)**  
**Problem:** Divide `192.168.10.0/24` into 4 subnets.  
**Solution:**  
- New subnet mask: `/26` (since \(2^2 = 4\) subnets).  
- Subnets:  
  1. `192.168.10.0/26` (Hosts: 1-62)  
  2. `192.168.10.64/26` (Hosts: 65-126)  
  3. `192.168.10.128/26` (Hosts: 129-190)  
  4. `192.168.10.192/26` (Hosts: 193-254)  

 
### **B. MAC Addressing (Physical Addressing)**  
- **48-bit hexadecimal** (e.g., `00:1A:2B:3C:4D:5E`)  
- **Assigned by manufacturer** (first 24 bits = OUI, last 24 bits = NIC identifier).  
- Used in **Ethernet & Wi-Fi** for local network communication.  


### **C. Port Addressing (Transport Layer)**  
- **16-bit numbers** (0-65535)  
- **Well-known ports (0-1023)**: HTTP (80), HTTPS (443), FTP (21)  
- **Dynamic ports (49152-65535)**: Temporary client-side ports  

---  

## **c. Address Resolution**  
### **A. Address Resolution Protocol (ARP)**  
- Resolves **IPv4 addresses to MAC addresses** in a local network.  
- Works via **ARP Request (Broadcast)** and **ARP Reply (Unicast)**.  

#### **Example: ARP Process**  
1. **Host A** wants to send data to **Host B (IP: 192.168.1.2)** but doesn’t know its MAC.  
2. **Host A** broadcasts an **ARP Request**: *"Who has 192.168.1.2?"*  
3. **Host B** replies with its MAC address.  
4. **Host A** updates its **ARP Cache**.  


#### **ARP Cache Table Example**  
| **IP Address** | **MAC Address** |  
|----------------|-----------------|  
| 192.168.1.1    | 00:1A:2B:3C:4D:5E |  
| 192.168.1.2    | 00:1B:3C:4D:5E:6F |  

### **B. Reverse ARP (RARP)**  
- Resolves **MAC addresses to IP addresses**.  

### **C. Neighbor Discovery Protocol (NDP) – IPv6 Equivalent of ARP**  
- Uses **ICMPv6** instead of ARP.  

---  

## **d. Comparison: ARP vs RARP vs NDP**  
| **Protocol** | **Function** | **Used in** |  
|-------------|-------------|------------|  
| **ARP** | IP → MAC resolution | IPv4 |  
| **RARP** | MAC → IP resolution | Legacy systems |  
| **NDP** | IP → MAC resolution (IPv6) | IPv6 |  

---  
 
## **e. Summary Table: Addressing in Networking**  
| **Address Type** | **Layer** | **Example** | **Purpose** |  
|-----------------|----------|------------|------------|  
| **IP Address (IPv4/IPv6)** | Network Layer | `192.168.1.1` | Logical addressing across networks |  
| **MAC Address** | Data Link Layer | `00:1A:2B:3C:4D:5E` | Physical addressing in LAN |  
| **Port Number** | Transport Layer | `80 (HTTP)` | Identifies applications |  

---  

# **6. Routing in Computer Networks**  

## **a. Introduction to Routing**  
**Routing** is the process of selecting the best path for data packets to travel from a source to a destination across interconnected networks. It is a core function of the **Network Layer (Layer 3)**.  

### **Key Objectives of Routing:**  
✔ **Path Determination** – Finding the optimal route.  
✔ **Packet Forwarding** – Sending packets along the chosen path.  
✔ **Adaptability** – Adjusting routes based on network changes.   

---  

## **b. Types of Routing**  

### **A. Static Routing**  
- Routes are **manually configured** by an administrator.  
- **No automatic updates** – Changes require manual intervention.  

#### **Example:**  
```  
Router(config)# ip route 192.168.2.0 255.255.255.0 10.0.0.2  
```  
*(This command sets a static route to `192.168.2.0/24` via next-hop `10.0.0.2`.)*  

#### **Advantages:**  
✔ No routing protocol overhead.  
✔ Secure (no dynamic route advertisements).  

#### **Disadvantages:**  
✖ Not scalable for large networks.  
✖ Manual updates needed for topology changes.  

### **B. Dynamic Routing**  
- Routes are **automatically updated** using **routing protocols**.  
- Adapts to network changes (link failures, congestion).  

#### **Example Protocols:**  
- **RIP (Routing Information Protocol)** – Distance-vector, hop-count metric.  
- **OSPF (Open Shortest Path First)** – Link-state, Dijkstra’s algorithm.  
- **BGP (Border Gateway Protocol)** – Path-vector, used in the Internet.  

#### **Advantages:**  
✔ Self-adjusting to network changes.  
✔ Scalable for large networks.  

#### **Disadvantages:**  
✖ Higher CPU/memory usage.  
✖ Vulnerable to routing loops if misconfigured.   

---  

## **c. Routing Protocols**  

### **A. Distance-Vector Protocols**  
- Routers share **entire routing tables** with neighbors.  
- Uses **hop count** as a metric.  

#### **Example: RIP (Routing Information Protocol)**  
- **Max hops = 15** (16 = unreachable).  
- **Updates every 30 sec** (can cause slow convergence).  

### **B. Link-State Protocols**  
- Routers share **link-state advertisements (LSAs)**.  
- Builds a **topology map** using Dijkstra’s algorithm.  

#### **Example: OSPF (Open Shortest Path First)**  
- **Fast convergence** (updates sent immediately on changes).  
- **Hierarchical design** (areas reduce overhead).  

### **C. Hybrid Protocols**  
- Combines **distance-vector and link-state** features.  
- **Example:** EIGRP (Enhanced Interior Gateway Routing Protocol).  

### **Comparison Table: Routing Protocols**  
| **Protocol** | **Type** | **Metric** | **Convergence** | **Use Case** |  
|-------------|---------|-----------|----------------|-------------|  
| **RIP** | Distance-Vector | Hop Count | Slow | Small networks |  
| **OSPF** | Link-State | Cost (Bandwidth) | Fast | Large enterprises |  
| **BGP** | Path-Vector | Path Attributes | Slow | Internet routing |  
| **EIGRP** | Hybrid | Bandwidth + Delay | Fast | Cisco networks |  

---  

## **d. Multicasting**  
- **One-to-many** communication (e.g., video streaming, online meetings).  
- Uses **Class D IP addresses (224.0.0.0 – 239.255.255.255)**.  

### **Key Protocols:**  
- **IGMP (Internet Group Management Protocol)** – Manages multicast group membership.  
- **PIM (Protocol Independent Multicast)** – Forwards multicast traffic.  

---  

## **e. The Anatomy of a Router**  

### **Key Components:**  
1. **CPU** – Executes routing protocols and forwarding decisions.  
2. **RAM** – Stores **routing tables, ARP cache, running config**.  
3. **NVRAM** – Stores **startup configuration**.  
4. **Flash Memory** – Holds **OS (e.g., Cisco IOS)**.  
5. **Interfaces (Ports)** – Ethernet, Serial, WAN.  


### **Routing Table Example:**  
| **Destination** | **Next Hop** | **Interface** | **Metric** |  
|----------------|-------------|--------------|-----------|  
| 192.168.1.0/24 | Directly Connected | FastEthernet0/0 | 0 |  
| 10.0.0.0/8 | 203.0.113.1 | Serial0/0/0 | 1 |  
| 0.0.0.0/0 | 198.51.100.1 | Serial0/0/1 | 0 |  

---  

## **Summary Table: Key Routing Concepts**  
| **Concept** | **Description** | **Example** |  
|------------|----------------|------------|  
| **Static Routing** | Manually configured routes | `ip route 192.168.1.0 255.255.255.0 10.0.0.2` |  
| **Dynamic Routing** | Automatically updated routes | RIP, OSPF, BGP |  
| **Default Route** | Fallback for unknown destinations | `0.0.0.0/0` |  
| **Multicast** | One-to-many communication | Video conferencing (224.0.0.0/4) |  
| **Router Components** | CPU, RAM, NVRAM, Flash, Interfaces | Cisco 2901 |  

---  

# **7. TCP/IP Example: Addressing, Connections, and Layers**   

## **a. Introduction to TCP/IP Communication**  
The **TCP/IP model** governs end-to-end data transmission in modern networks. This section covers:  
✔ **Known vs Unknown Addresses** (How devices find each other)  
✔ **TCP Connection Establishment** (Reliable communication)  
✔ **Interaction of TCP/IP with Network Layer** (Role of IP in routing)  

---  

## **b. Known vs Unknown Addresses**  

### **A. Known Addresses (Direct Communication)**  
- **Scenario:** Devices are on the **same subnet** (e.g., `192.168.1.0/24`).  
- **Process:**  
  1. **Source** checks if the **destination IP is in the same subnet**.  
  2. If yes, it uses **ARP** to find the **MAC address** of the destination.  
  3. Data is sent **directly** via Ethernet/Wi-Fi.  

#### **Example:**  
- **Host A (`192.168.1.10`)** → **Host B (`192.168.1.20`)**  
  - No router needed. ARP resolves `192.168.1.20` to a MAC address.  


### **B. Unknown Addresses (Indirect Communication)**  
- **Scenario:** Devices are on **different networks** (e.g., `192.168.1.10` → `10.0.0.5`).  
- **Process:**  
  1. **Source** identifies the destination is **outside its subnet**.  
  2. It forwards the packet to the **default gateway (router)**.  
  3. The router uses its **routing table** to forward the packet.  

#### **Example:**  
- **Host A (`192.168.1.10`)** → **Server (`10.0.0.5`)**  
  - Host A sends the packet to its **default gateway (`192.168.1.1`)**.  
  - The router routes it toward `10.0.0.0/8`.  

---  

## **c. TCP Connections (3-Way Handshake)**  
### **Step-by-Step TCP Establishment**  
1. **SYN** – Client sends a synchronization packet.  
   - `Seq = X`, `SYN=1`.  
2. **SYN-ACK** – Server acknowledges and sends its own SYN.  
   - `Seq = Y`, `ACK = X+1`, `SYN=1`.  
3. **ACK** – Client confirms the connection.  
   - `Seq = X+1`, `ACK = Y+1`.  


### **Why 3-Way Handshake?**  
✔ Ensures **both devices are ready** to communicate.  
✔ Synchronizes **initial sequence numbers** for reliability.  

---  

## **d. TCP/IP and Network Layer Interaction**  

### **A. Encapsulation Process**  
1. **Application Layer** – HTTP/FTP data.  
2. **Transport Layer (TCP/UDP)** – Adds **port numbers** (e.g., `80` for HTTP).  
3. **Network Layer (IP)** – Adds **source/destination IPs**.  
4. **Data Link Layer** – Adds **MAC addresses**.  

### **B. Role of IP (Network Layer)**  
✔ **Logical Addressing** – Uses IPs to route packets globally.  
✔ **Fragmentation** – Splits large packets if MTU is exceeded.  
✔ **Routing** – Uses protocols like OSPF/BGP to find paths.  

#### **Example: HTTP Request Flow**  
1. **Client** sends `GET /` to `www.example.com:80`.  
2. **TCP** adds port `80`.  
3. **IP** adds source (`192.168.1.10`) and destination (`93.184.216.34`).  
4. **Ethernet** adds MACs for local delivery.  

---  

## **e. Key Scenarios with Examples**  

### **Scenario 1: LAN Communication (Known Address)**  
- **Host A (`192.168.1.10`)** pings **Host B (`192.168.1.20`)**.  
  - ARP resolves `192.168.1.20` to a MAC.  
  - ICMP echo request sent directly.  

### **Scenario 2: WAN Communication (Unknown Address)**  
- **Host A (`192.168.1.10`)** accesses **Google (`142.250.190.78`)**.  
  - Packet goes to the **default gateway**.  
  - Router uses **NAT** to mask private IP.  

### **Scenario 3: TCP File Download**  
1. **SYN** → **SYN-ACK** → **ACK** (Connection established).  
2. Data sent in **segments** with sequence numbers.  
3. **FIN** → **ACK** → **FIN** → **ACK** (Connection closed).  


---  

## **Summary Table: TCP/IP Communication**  
| **Concept** | **Layer** | **Protocol/Address Used** | **Example** |  
|------------|----------|--------------------------|------------|  
| **Known Addresses** | Data Link | MAC (ARP) | `192.168.1.10` → `192.168.1.20` |  
| **Unknown Addresses** | Network | IP + Default Gateway | `192.168.1.10` → `8.8.8.8` |  
| **TCP Connection** | Transport | TCP Ports + 3-Way Handshake | HTTP (Port 80) |  
| **Routing** | Network | IP + Routing Protocols | OSPF, BGP |  

---  
 





