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


