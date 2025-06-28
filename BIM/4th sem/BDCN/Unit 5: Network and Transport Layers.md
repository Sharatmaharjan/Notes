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

## **4. Key Concepts with Examples**  
### **Fragmentation in Network Layer**  
- If a packet exceeds **MTU (Maximum Transmission Unit)**, it is fragmented.  
- Example: MTU = 1500 bytes, Packet size = 4000 bytes → Fragmented into 3 packets.  

### **TCP Congestion Control (Theoretical)**  
- **Slow Start**: Exponential increase in window size until threshold.  
- **Congestion Avoidance**: Linear increase after threshold.  
- **Fast Retransmit**: If 3 duplicate ACKs received, retransmit lost packet.  

---  

## **5. Summary**  
✔ **TCP** is reliable but slow; **UDP** is fast but unreliable.  
✔ **IPv4** uses 32-bit addresses, **IPv6** uses 128-bit.  
✔ **Subnetting** divides networks for efficient addressing.  
✔ **Three-way handshake** establishes TCP connections.  
✔ **Sliding window** in TCP manages flow control.  

---


