# Unit 5: The Transport Layer

## 5.1 Functions of Transport Layer

### Definition and Position
- **Definition**: Layer 4 of OSI model that provides logical communication between application processes running on different hosts 
- **Position**: Interface between application layer (Layer 5-7) and network layer (Layer 3)
- **PDU (Protocol Data Unit)** : Segment (TCP) or Datagram (UDP)
- **Key devices**: Gateways, firewalls operate at this layer

### Primary Functions

**A. End-to-End Delivery**
- Provides communication between specific processes on source and destination hosts
- Unlike network layer which delivers between hosts only
- Ensures complete data transfer from source application to destination application

**B. Service-point Addressing (Port Numbers)**
- **Concept**: Network layer address identifies host; transport layer address (port) identifies specific application process 
- **Port numbers**: 16-bit identifiers (0-65535)
  - **Well-known ports**: 0-1023 (HTTP=80, HTTPS=443, FTP=21, SSH=22)
  - **Registered ports**: 1024-49151
  - **Dynamic/private ports**: 49152-65535 (client-side ephemeral ports)
- **Real-world example**: Web server listens on port 80; multiple clients connect using different ephemeral ports

**C. Segmentation and Reassembly**
- Divides application-layer messages into smaller segments suitable for transmission
- Adds sequence numbers to identify order
- Reassembles segments at destination in correct order
- **MTU consideration**: Segment size limited by network's Maximum Transmission Unit

**D. Connection Control**
- **Connection-oriented**: Establishes, maintains, and terminates logical connection (TCP)
- **Connectionless**: Treats each packet independently (UDP)
- Manages connection state during data transfer

**E. Flow Control**
- Prevents fast sender from overwhelming slow receiver
- Uses sliding window mechanism
- Receiver advertises available buffer space

**F. Error Control**
- Detects and corrects transmission errors
- Uses checksums for error detection
- Provides retransmission for lost/corrupted segments
- Ensures data integrity from source to destination

**G. Multiplexing and Demultiplexing**
- **Multiplexing**: Multiple applications share same transport protocol
- **Demultiplexing**: Incoming segments directed to correct application using port numbers 
- **Real-world example**: Your computer can simultaneously browse web (port 80), check email (port 25), and play game (port specific) using same network connection

**H. Quality of Service (QoS)**
- Prioritizes certain types of traffic
- Manages timing requirements for real-time applications
- Controls bandwidth allocation

### Services Provided to Upper Layer
- Reliable or unreliable data transfer (application chooses)
- Error-free delivery (for connection-oriented)
- In-order delivery (for connection-oriented)
- Flow control to prevent buffer overflow
- Process-to-process communication

---

## 5.2 Elements of Transport Protocols

### 5.2.1 Addressing (Port Numbers)

**Socket Concept**
- **Socket**: Combination of IP address and port number
- **Socket pair**: (Source IP, Source Port) + (Destination IP, Destination Port)
- Uniquely identifies each connection globally

**Port Number Assignment**
- **Static assignment**: Well-known ports for standard services
- **Dynamic assignment**: Ephemeral ports allocated by OS for clients
- **Socket creation**: bind() system call associates port with application

**Real-world example**: Web server socket = 192.168.1.10:80; client socket = 192.168.1.20:54321

### 5.2.2 Connection Establishment

**Three-Way Handshake (for TCP)** 

**Purpose**: Synchronize sequence numbers, negotiate options, establish connection state

```
Client (Active Open)          Server (Passive Open)
       |                              |
       |------- SYN (seq=x) -------->|
       |                              |
       |<----- SYN+ACK (seq=y, ack=x+1) ----|
       |                              |
       |------- ACK (ack=y+1) ------->|
       |                              |
       |<===== Connection Established ====>|
```

**Steps**:

| Step | Segment | Direction | Purpose |
| :--- | :--- | :--- | :--- |
| 1 | SYN (seq=x) | Client → Server | Client requests connection, announces initial sequence number |
| 2 | SYN+ACK (seq=y, ack=x+1) | Server → Client | Server acknowledges, announces its own sequence number |
| 3 | ACK (ack=y+1) | Client → Server | Client acknowledges server's sequence number, connection established |

**Handling Duplicate Connections** 
- Transport clock generates unique sequence numbers
- Sequence numbers not reused within Maximum Segment Lifetime (MSL)
- Prevents old duplicate segments from being mistaken for new connection
- MSL = 2 minutes on Internet (standard)

**Connection Refusal**
- Server sends RST (Reset) segment if port not listening
- Client receives "connection refused" error

### 5.2.3 Connection Release

**Asymmetric Release** (Abrupt)
- One side sends FIN or RST
- Connection closed immediately
- May lose data in transit

**Symmetric Release** (Graceful) - TCP's FIN handshake

```
Client                          Server
  |------- FIN (seq=x) -------->|
  |<------ ACK (ack=x+1) -------|
  |<------ FIN (seq=y) ---------|
  |------- ACK (ack=y+1)------->|
  |                              |
  |<==== Connection Closed ====> |
```

**Three-Way FIN Handshake**:
1. Active closer sends FIN → enters FIN-WAIT-1
2. Passive closer ACKs → enters CLOSE-WAIT
3. Passive closer sends FIN → enters LAST-ACK
4. Active closer ACKs → enters TIME-WAIT
5. Connection removed after 2×MSL (ensures all packets expired)

**TIME-WAIT State**
- Duration: 2 × MSL (typically 2-4 minutes)
- Purpose: Ensure remote side received final ACK; allow old segments to expire
- Prevents data from old connection interfering with new connection

### 5.2.4 Flow Control and Buffering

**Flow Control Problem**
- Sender transmits faster than receiver can process
- Receiver buffers overflow → data loss

**Solution: Sliding Window Protocol**

**Receiver Window (rwnd)** 
- Receiver advertises available buffer space
- Sender cannot exceed advertised window
- Prevents receiver buffer overflow

**Buffer Management Strategies**

| Strategy | Description | Use Case |
| :--- | :--- | :--- |
| **Fixed buffers** | Pre-allocated per connection | TCP (typical) |
| **Dynamic buffers** | Allocated on demand | High-performance servers |
| **Chained buffers** | Multiple buffers linked | Large data transfers |

**Flow Control Techniques**
- **Stop-and-Wait**: Send one, wait for ACK (inefficient)
- **Sliding Window**: Multiple segments in flight
- **Credit-based**: Receiver grants transmission credits
- **Rate-based**: Sender paces transmission rate

### 5.2.5 Error Control

**Error Types Handled**
- Damaged segments (bit errors)
- Lost segments
- Out-of-order segments
- Duplicate segments

**Error Control Mechanisms**

| Mechanism | Description | Protocol |
| :--- | :--- | :--- |
| **Checksum** | Detect bit errors | TCP, UDP |
| **Acknowledgments** | Confirm successful receipt | TCP |
| **Retransmission** | Resend lost/corrupted segments | TCP |
| **Sequence numbers** | Detect loss, reorder, duplicates | TCP |
| **Timer** | Trigger retransmission on timeout | TCP |

**ARQ (Automatic Repeat Request)**
- **Stop-and-Wait ARQ**: Send, wait ACK, timeout → retransmit
- **Go-Back-N ARQ**: Send multiple, on loss retransmit from that point
- **Selective Repeat ARQ**: Retransmit only lost segments

### 5.2.6 Multiplexing and Demultiplexing 

**Multiplexing (Sender Side)**
- Multiple applications generate data
- Transport layer combines into single network stream
- Each segment tagged with source port number

**Demultiplexing (Receiver Side)**
- Transport layer receives segments
- Examines destination port number
- Delivers to appropriate application process

**Demultiplexing Types**
- **Connectionless demux**: Uses only destination port (UDP)
- **Connection-oriented demux**: Uses source IP, source port, destination IP, destination port (TCP)

### 5.2.7 Crash Recovery

**Problem**
- Hosts may crash and reboot during connection
- Transport layer must handle gracefully

**Crash Scenarios**

| Scenario | Effect | Recovery |
| :--- | :--- | :--- |
| **Client crashes** | Connection half-open | Server times out, closes |
| **Server crashes** | Client waiting | Client times out, aborts |
| **Both crash** | Orphaned connections | Eventually timeout |

**Recovery Mechanisms**
- **Timers**: Detect dead connections
- **Keep-alive**: Probe idle connections
- **RST segments**: Force immediate termination
- **TIME-WAIT**: Ensure old segments expire

---

## 5.3 User Datagram Protocol (UDP)

### 5.3.1 Overview

**Definition**: Lightweight, connectionless transport protocol defined in RFC 768 

**Characteristics**
- **Connectionless**: No handshake before sending
- **Unreliable**: No guarantee of delivery
- **No ordering**: Packets may arrive out of sequence
- **No congestion control**: Can send at any rate
- **Minimum overhead**: 8-byte header
- **Stateless**: No connection state maintained

### 5.3.2 User Datagram Format 

```
 0                   1                   2                   3
 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|          Source Port          |       Destination Port        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|            Length             |           Checksum            |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                            Data                                |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
```

**Field Descriptions**

| Field | Length | Description |
| :--- | :--- | :--- |
| **Source Port** | 16 bits | Optional (0 if not used) - identifies sending application |
| **Destination Port** | 16 bits | Required - identifies receiving application |
| **Length** | 16 bits | UDP header + data in bytes (minimum 8, maximum 65,535) |
| **Checksum** | 16 bits | Error detection for header + data + pseudo header |
| **Data** | Variable | Application layer payload |

**UDP Options (RFC 9868 Update)** 

Recent update (October 2025) adds UDP transport layer options in surplus area after user data:

| Option | Purpose |
| :--- | :--- |
| **EOL** | End of Options List |
| **NOP** | No Operation (padding) |
| **APC** | Additional Payload Checksum |
| **FRAG** | Fragmentation |
| **MDS** | Maximum Datagram Size |
| **MRDS** | Maximum Reassembled Datagram Size |
| **REQ/RES** | Echo Request/Response |
| **TIME** | Timestamp |
| **AUTH** | Authentication (reserved) |
| **EXP** | Experimental |

### 5.3.3 UDP Operations

**Checksum Calculation**
- Optional in IPv4 (0 disables); mandatory in IPv6
- Covers UDP header + data + **pseudo header**
- Pseudo header includes: Source IP, Destination IP, Protocol (17), UDP Length
- Provides protection against misdelivery

**UDP Pseudo Header**
```
 0                   1                   2                   3
 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                       Source IP Address                        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                    Destination IP Address                       |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|   Zero (0)    |  Protocol (17) |         UDP Length           |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
```

**Queuing**
- Each port has receive queue
- Multiple applications can share port (multicast)
- Packets dropped if queue full

### 5.3.4 Uses of UDP 

**Applications Tolerating Packet Loss**
- Real-time where speed > reliability
- Occasional loss acceptable

**Real-world Applications**

| Application | Why UDP? |
| :--- | :--- |
| **DNS** | Single request-response, low overhead |
| **DHCP** | Broadcast-based, connectionless |
| **SNMP** | Simple network management |
| **RIP** | Periodic routing updates |
| **VoIP (RTP)** | Real-time, loss tolerable |
| **Video streaming** | Live streaming, some loss acceptable |
| **Online gaming** | Fast action, dropped packets ignored |
| **NTP** | Time synchronization |
| **TFTP** | Trivial File Transfer (with ACK) |
| **QUIC** | Modern protocol built on UDP  |

**Advantages** 
- **Low latency**: No connection setup
- **Low overhead**: 8-byte header (vs 20+ TCP)
- **No head-of-line blocking**: Each packet independent
- **Broadcast/multicast support**: Can send to multiple recipients
- **Application-level control**: Developer manages reliability if needed

**Disadvantages**
- Unreliable (no retransmission)
- No congestion control (can flood network)
- No ordering (application must handle)
- No flow control (may overwhelm receiver)

### 5.3.5 Remote Procedure Call (RPC)

**Concept**
- Client calls procedure on remote server as if local
- Built on transport protocols (often UDP or TCP)
- **Sun RPC**: Common implementation using UDP

**RPC over UDP**
- Request message → UDP datagram → server
- Response message → UDP datagram → client
- Timeout + retransmission handled by RPC layer
- **Idempotent operations**: Can safely retry

**RPC Message Format**
- Program number, version, procedure number
- Authentication credentials
- Parameters
- Results

**Advantages of RPC over UDP**
- Simple request-response pattern
- Low latency
- Suitable for stateless services

**Example**: NFS (Network File System) historically used RPC over UDP

---

## 5.4 Principles of Reliable Data Transfer

### 5.4.1 Problem Statement

**Reliable Data Transfer Requirements**
1. No data corruption
2. No data loss
3. In-order delivery
4. No duplicates

**Underlying Channel Imperfections**
- Bit errors
- Packet loss
- Reordering
- Duplication

### 5.4.2 Building Reliable Data Transfer Protocol (rdt)

**A. rdt1.0 - Perfect Channel**
- Assumes no bit errors, no loss
- Sender sends, receiver receives
- No feedback needed
- **Unrealistic** - only theoretical

**B. rdt2.0 - Channel with Bit Errors**

**Mechanisms**:
- **Error detection**: Checksum
- **Positive acknowledgments (ACK)** : Receiver confirms correct receipt
- **Negative acknowledgments (NAK)** : Receiver reports error
- **Retransmission**: Sender resends on NAK

**Protocol**:
```
Sender:                         Receiver:
- Send packet                   - If packet OK → send ACK
- Wait for ACK/NAK              - If error → send NAK
- If NAK → retransmit
- If ACK → send next
```

**Problem**: ACK/NAK themselves may be corrupted

**C. rdt2.1 - Handling Corrupted ACK/NAK**

**Solution**: Add sequence numbers (0 and 1)

**Mechanisms**:
- Sender adds sequence number to packet
- Receiver checks sequence number to detect duplicates
- If ACK/NAK corrupted → retransmit current packet

**Operation**:
- Sender sends packet 0, waits
- Receiver ACKs 0
- Sender sends packet 1, waits
- If ACK corrupted → resend packet 1

**D. rdt2.2 - NAK-free Protocol**

**Mechanism**: Use ACKs with sequence number of expected next packet

**Instead of NAK**:
- Receiver sends ACK for last correctly received packet
- Duplicate ACK indicates error (implicit NAK)

**Advantage**: Simpler, consistent with TCP

**E. rdt3.0 - Channel with Bit Errors AND Loss**

**Problem**: Packets may disappear entirely (no ACK/NAK received)

**Solution**: Add **timer**

**Mechanism**:
- Sender starts timer after sending
- If ACK received before timeout → proceed
- If timeout occurs → retransmit, restart timer

**Limitation**: Stop-and-wait protocol - inefficient for long RTT
- **Performance**: 1 packet per RTT
- **Utilization**: (L/R) / (RTT + L/R) - very low for high BDP

### 5.4.3 Pipelined Reliable Data Transfer Protocols

**Concept**: Send multiple packets without waiting for ACKs

**Benefits**:
- Better link utilization
- Higher throughput

**Trade-off**: More complex error recovery

**Pipelining Parameters**
- **Window size (N)** : Number of outstanding packets allowed
- **Sequence number space**: Must be large enough for N+1

**Efficiency Example**:
- Stop-and-wait: 1 packet/RTT
- Pipelined with N=4: 4 packets/RTT

### 5.4.4 Go-Back-N (GBN)

**Also known as**: Sliding window protocol

**Sender Operation**:
- Maintains **base**: oldest unacknowledged packet
- Maintains **nextseqnum**: next packet to send
- Window = [base, base+N-1]

| Event | Action |
| :--- | :--- |
| **Packet from upper layer** | If within window → send, increment nextseqnum; else buffer/refuse |
| **ACK received (with sequence n)** | Cumulative acknowledgment → base = n+1 |
| **Timeout** | Restart timer; retransmit all packets from base to nextseqnum-1 |

**Receiver Operation**:
- **Simplest**: Accept only in-order packets
- If packet n received:
  - If n == expectedseqnum → deliver to upper, send ACK n, increment expectedseqnum
  - Else → discard packet, resend ACK for last correctly received packet

**Advantages**:
- Simple receiver (no buffering)
- Cumulative ACKs

**Disadvantages**:
- Retransmits many packets on single loss
- Wastes bandwidth for high-loss links

### 5.4.5 Selective Repeat (SR)

**Concept**: Receiver individually acknowledges each packet; sender retransmits only lost packets

**Sender Operation**:
- Window of sequence numbers (size N)
- Timer per packet
- Buffer unacknowledged packets

| Event | Action |
| :--- | :--- |
| **Packet from upper** | If within window → send; else buffer |
| **ACK received** | Mark packet as received; if packet == base → advance window |
| **Timeout** | Retransmit only timed-out packet |

**Receiver Operation**:
- Acknowledges each correctly received packet (even out-of-order)
- Buffers out-of-order packets for eventual in-order delivery

| Event | Action |
| :--- | :--- |
| **Packet n received (in window)** | Send ACK n; if n == expectedseqnum → deliver and advance expectedseqnum |
| **Packet n received (out of window)** | Send ACK n (may be duplicate) |
| **Packet n received (already ACKed)** | Send ACK n (duplicate) |

**Window Size Constraint**: Sequence number space ≥ 2N (prevents ambiguity)

**Example**:
- Window N=4, sequence numbers 0-7
- Without 2N constraint, ACKs lost could cause confusion

**Advantages**:
- More efficient for lossy links
- Saves bandwidth (only retransmit lost packets)

**Disadvantages**:
- Complex receiver buffering
- More sender state (timers per packet)
- Sequence number management complexity

### 5.4.6 Comparison: GBN vs SR

| Feature | Go-Back-N | Selective Repeat |
| :--- | :--- | :--- |
| **Receiver buffering** | None | Yes (out-of-order packets) |
| **Retransmission** | All from lost packet onward | Only lost packets |
| **ACK type** | Cumulative | Individual (selective) |
| **Efficiency** | Lower for lossy links | Higher for lossy links |
| **Complexity** | Low | High |
| **Memory requirements** | Minimal | Buffer for window size |

---

## 5.5 Transmission Control Protocol (TCP)

### 5.5.1 TCP Services 

**Overview**
- **Definition**: Reliable, connection-oriented transport protocol
- **Standard**: RFC 793 (updated by RFC 9293) 
- **Position**: Most widely used transport protocol on Internet

**Key Services**

| Service | Description |
| :--- | :--- |
| **Connection-oriented** | Virtual circuit between processes (3-way handshake) |
| **Reliable delivery** | No data loss, corruption, duplication |
| **In-order delivery** | Segments reassembled in correct order |
| **Flow control** | Prevents overwhelming receiver |
| **Congestion control** | Prevents overwhelming network |
| **Full duplex** | Data flows both directions simultaneously |
| **Stream interface** | Application sends byte stream, not messages |
| **Push service** | Option to deliver immediately |
| **Urgent data** | Out-of-band signaling (obsoleted) |

### 5.5.2 TCP Features 

**A. Connection Orientation**
- Connection established before data transfer
- Connection state maintained at both ends
- Connection released after data transfer

**B. Point-to-Point Communication**
- Single sender, single receiver
- No multicast/broadcast

**C. Reliability**
- Sequence numbers track bytes
- Acknowledgments confirm receipt
- Retransmission on timeout
- Checksum validates integrity

**D. Full Duplex**
- Data flows both directions simultaneously
- Control information piggybacked on data segments

**E. Stream Interface**
- Application sees byte stream, not packets
- TCP segments data into MSS-sized chunks
- No message boundaries preserved

**F. Flow Control**
- Advertised window prevents receiver overflow
- Dynamic window adjustment

**G. Congestion Control**
- Probes network capacity
- Reduces rate on congestion
- AIMD (Additive Increase Multiplicative Decrease)

**H. Piggybacking**
- ACKs carried in data segments when possible
- Reduces network overhead

### 5.5.3 TCP Segment Header 

```
 0                   1                   2                   3
 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|          Source Port          |       Destination Port        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                       Sequence Number                          |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                    Acknowledgment Number                       |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
| Data |           |U|A|P|R|S|F|                                 |
|Offset| Reserved  |R|C|S|S|Y|I|            Window               |
|      |           |G|K|H|T|N|N|                                 |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|           Checksum            |         Urgent Pointer        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                    Options                    |    Padding    |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                            Data                                 |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
```

**Field Descriptions** 

| Field | Length | Description |
| :--- | :--- | :--- |
| **Source Port** | 16 bits | Identifies sending application |
| **Destination Port** | 16 bits | Identifies receiving application |
| **Sequence Number** | 32 bits | Byte number of first data byte in segment |
| **Acknowledgment Number** | 32 bits | Next expected byte (ACK flag set) |
| **Data Offset** | 4 bits | TCP header length in 32-bit words (min 5 = 20 bytes)  |
| **Reserved** | 3 bits | Reserved for future use (must be 0) |
| **Flags** | 9 bits | Control bits (see below) |
| **Window** | 16 bits | Advertised receive window size (flow control) |
| **Checksum** | 16 bits | Error detection for header + data + pseudo header |
| **Urgent Pointer** | 16 bits | Points to urgent data (URG flag set) |
| **Options** | 0-40 bytes | TCP extensions  |
| **Padding** | Variable | Ensures header ends at 32-bit boundary |

**TCP Flags** 

| Flag | Bit | Meaning | Description |
| :--- | :--- | :--- | :--- |
| **URG** | 5 | Urgent | Urgent pointer field valid (obsolete) |
| **ACK** | 4 | Acknowledgment | Acknowledgment field valid |
| **PSH** | 3 | Push | Deliver data immediately to application |
| **RST** | 2 | Reset | Abort connection (error) |
| **SYN** | 1 | Synchronize | Connection establishment (sequence number sync) |
| **FIN** | 0 | Finish | Graceful connection termination |

**TCP Options** 

TCP options space limited to 40 bytes in standard header. TCP Extended Data Offset (EDO) option extends space for non-SYN segments .

| Option | Purpose |
| :--- | :--- |
| **MSS** | Maximum Segment Size negotiation |
| **Window Scale** | Scale window beyond 65,535 (RFC 7323) |
| **Timestamp** | RTT measurement, PAWS (RFC 7323) |
| **SACK-Permitted** | Selective ACK negotiation (RFC 2018) |
| **SACK** | Selective ACK blocks |
| **TCP-AO** | Authentication (RFC 5925) |
| **MP-TCP** | Multipath TCP (RFC 8684) |
| **EDO** | Extended Data Offset (in development)  |

**TCP Pseudo Header** (for checksum calculation)
```
 0                   1                   2                   3
 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                       Source IP Address                        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                    Destination IP Address                       |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|   Zero (0)    |  Protocol (6) |         TCP Length            |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
```

---

## 5.6 Principle of Congestion Control

### 5.6.1 Congestion Concept

**Definition**: Network state where offered load exceeds available capacity, causing performance degradation 

**Congestion vs Flow Control**
- **Flow control**: Prevents sender overwhelming receiver
- **Congestion control**: Prevents sender overwhelming network

**Congestion Manifestations**
- Packet loss (router buffer overflow)
- Increased delays (queuing)
- Reduced throughput
- Wasted retransmissions

### 5.6.2 Causes and Costs of Congestion

**Scenario 1: Two Senders, Infinite Buffers**
- Packets queued at router
- Average delay increases with load
- Throughput remains high
- **Cost**: Large delays

**Scenario 2: Two Senders, Finite Buffers**
- Packets dropped when buffers full
- Retransmissions required
- **Cost**: Wasted bandwidth for dropped packets

**Scenario 3: Four Senders, Multi-hop**
- Packets dropped at intermediate routers
- Retransmissions consume more bandwidth
- **Cost**: Throughput collapse if no control

**Congestion Collapse**
- Offered load increases, throughput decreases
- Network spends most time processing/retransmitting duplicates
- Historical problem (mid-1980s Internet)

### 5.6.3 Congestion Control Approaches

**A. End-to-End Congestion Control**
- Network layer provides no feedback
- End systems infer congestion from observed loss/delay
- **Used by**: TCP

**B. Network-Assisted Congestion Control**
- Routers provide explicit feedback
- **Examples**: ECN (Explicit Congestion Notification), ATM, DECbit

### 5.6.4 TCP Congestion Control 

**Key Principle**: AIMD (Additive Increase Multiplicative Decrease)

**Components**:
- **Congestion Window (cwnd)** : Sender-side limit 
- **Receiver Window (rwnd)** : Receiver-side flow control
- **Effective window**: min(cwnd, rwnd)
- **Slow Start Threshold (ssthresh)** : Transition point 

**TCP Congestion Control Phases** 

**A. Slow Start**
- **Purpose**: Probe network capacity
- **Initial cwnd**: Small (modern: 10 MSS, legacy: 1 MSS)
- **Growth**: Exponential (double each RTT)
- **Per ACK**: cwnd += 1 MSS (effectively doubles per RTT)
- **Until**: cwnd reaches ssthresh OR loss detected

**B. Congestion Avoidance** 
- **Purpose**: Gently probe for available bandwidth
- **Growth**: Additive (linear)
- **Per RTT**: cwnd += 1 MSS
- **Typically**: cwnd += MSS × (MSS/cwnd) per ACK
- **Until**: Loss detected

**C. Fast Retransmit** 
- **Trigger**: 3 duplicate ACKs
- **Action**: Retransmit lost segment immediately (no need to wait for timeout)
- **Assumption**: Duplicate ACKs indicate segment loss but later segments delivered

**D. Fast Recovery** 
- **Purpose**: Avoid Slow Start after single loss
- **Operation**:
  1. Set ssthresh = cwnd/2
  2. Retransmit lost segment (Fast Retransmit)
  3. Set cwnd = ssthresh + 3 MSS
  4. For each duplicate ACK: cwnd += 1 MSS (transmit new if possible)
  5. When ACK for new data arrives: cwnd = ssthresh, enter Congestion Avoidance

**TCP Tahoe vs Reno** 

| Version | Fast Retransmit | Fast Recovery |
| :--- | :--- | :--- |
| **Tahoe** | Yes | No (enters Slow Start) |
| **Reno** | Yes | Yes |

**TCP Congestion Control State Machine**

```
                    [Slow Start]
                         |
                         | (cwnd >= ssthresh)
                         ↓
              [Congestion Avoidance]
                         |
        +----------------+----------------+
        | (3 dup ACKs)                    | (timeout)
        ↓                                 ↓
[Fast Recovery]                      [Slow Start]
  (Reno only)                           (cwnd=1)
        |
        | (new ACK)
        ↓
[Congestion Avoidance]
```

**Modern TCP Variants**
- **TCP Cubic**: Default in Linux, better for high BDP
- **TCP BBR**: Model-based congestion control
- **SEARCH**: New slow start algorithm improving exit decision 

**SEARCH Algorithm** 
- **Problem**: HyStart causes premature exit in wireless links
- **Solution**: Monitor delivered bytes per RTT
- **Expected**: Should double each RTT in slow start
- **If actual < expected**: Exit slow start
- **Benefit**: Better utilization, less loss

### 5.6.5 TCP Congestion Control Summary 

| Phase | Window Growth | Purpose |
| :--- | :--- | :--- |
| **Slow Start** | Exponential (double per RTT) | Quickly reach available capacity |
| **Congestion Avoidance** | Linear (+1 MSS per RTT) | Gently probe for more bandwidth |
| **Fast Recovery** | Varies | Recover from single loss efficiently |

**Loss Recovery** 

| Loss Signal | Action |
| :--- | :--- |
| **Timeout** | Set cwnd=1, ssthresh=half, enter Slow Start |
| **3 Duplicate ACKs** | Fast Retransmit + Fast Recovery (Reno) |

---

## Summary Table: TCP vs UDP 

| Feature | TCP | UDP |
| :--- | :--- | :--- |
| **Connection** | Connection-oriented | Connectionless |
| **Reliability** | Reliable (ACKs, retransmission) | Unreliable (no guarantees) |
| **Ordering** | In-order delivery | No ordering |
| **Header size** | 20-60 bytes | 8 bytes |
| **Flow control** | Yes (sliding window) | No |
| **Congestion control** | Yes (AIMD) | No |
| **Speed** | Moderate | Fast |
| **Use cases** | Web, email, file transfer, DB | DNS, VoIP, gaming, streaming |
| **Analogy** | Certified mail  | Doorstep drop-off  |
