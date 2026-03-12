# Unit 3: The Data Link Layer

## 3.1 Functions of Data Link Layer

### Definition and Position
- **Definition**: Layer 2 of OSI model that provides node-to-node data transfer between two directly connected nodes 
- **Position**: Sits between Physical Layer (Layer 1) and Network Layer (Layer 3), acting as interface between hardware and higher-level protocols 
- **PDU (Protocol Data Unit)** : Frame

### Primary Functions 

**A. Framing**
- Divides raw bit stream from Physical Layer into manageable data units called frames
- Adds header and trailer to each frame for synchronization and addressing
- Enables receiver to detect start and end of each frame

**B. Physical Addressing**
- Adds MAC (Media Access Control) addresses of source and destination in frame header
- MAC addresses are 48-bit unique identifiers burned into NIC hardware
- Ensures frame reaches correct device within local network

**C. Error Detection and Correction**
- Detects transmission errors using techniques like CRC (Cyclic Redundancy Check)
- May correct errors or discard corrupted frames and request retransmission
- Ensures data integrity between adjacent nodes

**D. Flow Control**
- Regulates data transmission speed between sender and receiver
- Prevents fast sender from overwhelming slow receiver
- Uses techniques like sliding window, stop-and-wait

**E. Access Control**
- Manages which device gets to use shared communication medium at what time
- Critical when multiple devices share same transmission channel
- Implements multiple access protocols (CSMA/CD, CSMA/CA, etc.)

**F. Reliable Delivery**
- Provides acknowledgment mechanisms for successful frame reception
- Implements retransmission strategies for lost or corrupted frames
- Ensures data reaches next node intact

### Sublayers of Data Link Layer 

The IEEE 802 project divided DLL into two sublayers:

**A. Logical Link Control (LLC) - Upper Sublayer** 
- Defined in IEEE 802.2 standard
- Interfaces between Network Layer and MAC sublayer
- Provides multiplexing - multiple network layer protocols (IP, IPX, AppleTalk) can use same physical link
- Handles flow control and error control
- Adds protocol information to identify which upper-layer protocol is being used

**B. Media Access Control (MAC) - Lower Sublayer** 
- Manages access to physical medium
- Handles physical addressing (MAC addresses)
- Implements access control mechanisms (CSMA/CD, token passing, etc.)
- Defines frame formats specific to network type (Ethernet, Wi-Fi, etc.)
- Resolves collisions when multiple devices transmit simultaneously

### Devices Operating at Data Link Layer 
- **Switch**: Forwards frames based on MAC addresses, creates multiple collision domains
- **Bridge**: Connects two LAN segments, filters traffic based on MAC addresses
- **Network Interface Card (NIC)** : Adds MAC addresses to frames, interfaces with physical medium
- **Wireless Access Point**: Manages wireless MAC addresses, enables wireless devices to connect to wired network

### Services Provided to Network Layer 
- **Connectionless service**: Frames sent independently, no acknowledgments (used in Ethernet)
- **Connection-oriented service**: Frames numbered, acknowledged, and retransmitted if lost (used in HDLC)

---

## 3.2 Data Link Control: Framing, Flow and Error Control

### 3.2.1 Framing

**Definition**: Process of dividing bit stream into discrete frames and adding delimiters to identify frame boundaries 

**Frame Size Types** :

**A. Fixed-Size Framing**
- All frames are same size
- No need for boundary delimiters - frame size itself acts as delimiter
- Simpler implementation
- **Disadvantage**: Wastage if data is smaller than frame size

**B. Variable-Size Framing**
- Frame sizes vary based on data
- Needs mechanisms to define frame boundaries
- Two approaches:

**Character-Oriented Framing** 
- Data is 8-bit characters from coding system (ASCII, EBCDIC)
- Header and trailer also multiples of 8 bits
- Uses 8-bit **flag** (01111110) at beginning and end of frame
- **Problem**: Flag pattern may appear in data
- **Solution**: **Byte stuffing** - add escape character before any flag appearing in data
- Receiver removes stuffed characters before passing to upper layer
- **Example**: PPP uses character-oriented framing

**Bit-Oriented Framing** 
- Data is sequence of bits, not interpreted as characters
- Uses special 8-bit flag **01111110** as delimiter
- **Problem**: Flag pattern may appear in data bits
- **Solution**: **Bit stuffing** - after five consecutive 1s, insert a 0
  - Sender: After five 1s, adds 0
  - Receiver: After five 1s followed by 0, removes that 0
- Ensures flag pattern never appears in data
- **Example**: HDLC uses bit-oriented framing

### 3.2.2 Flow Control

**Definition**: Technique to regulate data transmission speed so slow receiver is not overwhelmed by fast sender 

**Buffers**: Both sender and receiver have buffers to temporarily store frames 

**Flow Control Methods:**

**A. Stop-and-Wait Flow Control**
- Sender transmits one frame, then waits for acknowledgment
- Receiver sends ACK when ready for next frame
- **Advantages**: Simple to implement
- **Disadvantages**: Inefficient for long-distance links (channel idle while waiting)

**B. Sliding Window Flow Control**
- Sender can transmit multiple frames (window) before receiving ACK
- Window size negotiated between sender and receiver
- Receiver acknowledges frames, allowing window to slide forward
- **Advantages**: Better utilization of bandwidth
- **Disadvantages**: More complex implementation

### 3.2.3 Error Control

**Definition**: Mechanisms to detect and correct errors occurring during transmission 

**Two Approaches** :

**Approach 1: Discard Only**
- If frame is corrupted → silently discarded
- If frame is error-free → delivered to Network Layer
- Used in wired LANs like Ethernet
- Relies on upper layers for error recovery

**Approach 2: Discard with Acknowledgment**
- If frame is corrupted → silently discarded
- If frame is error-free → acknowledgment sent to sender
- Sender retransmits if no ACK received (timeout)
- Used in reliable connection-oriented protocols

**Automatic Repeat Request (ARQ)** : Combined flow and error control where receiver acknowledges correct frames and sender retransmits lost/corrupted frames

### Data Link Layer Protocols 

**A. Simple Protocol**
- No flow control, no error control
- Sender assumes receiver can handle infinite speed
- Only for idealized scenarios

**B. Stop-and-Wait Protocol**
- Uses both flow and error control
- Sender: Send one frame → wait for ACK → send next
- Receiver: Receive frame → send ACK
- **Sequence numbers**: Needed to distinguish new frame from retransmission
- **Timer**: Starts after sending; retransmit on timeout

**C. Go-Back-N ARQ**
- Sender can send multiple frames (window size > 1)
- If frame lost/corrupted, sender goes back to that frame and retransmits all subsequent frames
- Receiver only accepts frames in order; discards out-of-order frames
- **Efficiency**: Better than Stop-and-Wait

**D. Selective Repeat ARQ**
- Sender can send multiple frames
- Receiver accepts out-of-order frames and buffers them
- Only lost/corrupted frames are retransmitted
- **Efficiency**: Best among ARQ protocols
- **Complexity**: Requires more buffering and logic

### Piggybacking 
- **Definition**: Combining data and acknowledgment in same frame
- Frame from A to B carries: Data for B + ACK for previous frame from B
- **Advantage**: Efficient use of bandwidth (reduces separate ACK frames)
- **Used in**: HDLC, PPP

---

## 3.3 Error Detection and Correction

### Types of Errors

**A. Single-Bit Error**
- Only one bit in data unit changes from 1 to 0 or 0 to 1
- Occurs in parallel transmission (e.g., memory)

**B. Burst Error**
- Multiple bits change (contiguous or non-contiguous)
- More common in serial transmission
- Burst length = number of bits from first corrupted to last corrupted
- **Example**: Lightning strike causing multiple bit flips

### Error Detection Methods

**A. Parity Check** (Simple but weak)
- **Single Parity Bit**: Add one extra bit to make total number of 1s even (even parity) or odd (odd parity)
- **Detects**: Odd number of bit errors
- **Fails**: Even number of bit errors (undetected)
- **Example**: ASCII transmission with parity bit

**B. Cyclic Redundancy Check (CRC)** 
- **Concept**: Treat data as polynomial, divide by predetermined generator polynomial, append remainder
- **Process**:
  1. Sender: Data + (n-1) zeros ÷ generator → remainder
  2. Append remainder to data (now divisible by generator)
  3. Receiver: Divide received data by same generator
  4. If remainder = 0 → no error detected; else → error
- **Generator polynomials**: CRC-32 (Ethernet), CRC-16, CRC-CCITT
- **Detects**: All single-bit errors, all double-bit errors, any odd number of errors, all burst errors up to polynomial length
- **Advantages**: Extremely reliable, efficient hardware implementation
- **Real-world example**: Ethernet frames use CRC-32 in trailer

**C. Checksum**
- **Concept**: Sum all data words, take complement, send as checksum
- **Process**:
  1. Divide data into k segments of n bits each
  2. Add segments using 1's complement arithmetic
  3. Complement result = checksum
  4. Receiver adds all segments including checksum; result should be all 1s
- **Used in**: Internet protocols (IP, TCP, UDP) - but at higher layers
- **Advantages**: Simple software implementation
- **Disadvantages**: Weaker than CRC

### Error Correction Methods

**A. Forward Error Correction (FEC)**
- Add enough redundant bits to allow receiver to correct errors without retransmission
- Used where retransmission is impossible/expensive (satellite, deep space)

**B. Hamming Code**
- **Concept**: Add redundant bits (r) positioned at bit positions that are powers of 2
- **Formula**: For data bits m, need r such that 2^r ≥ m + r + 1
- **Process**:
  1. Place data bits in non-power-of-2 positions
  2. Each parity bit checks specific set of positions
  3. Receiver recalculates parity; position of error = sum of failed parity positions
- **Can correct**: Single-bit errors
- **Can detect**: Double-bit errors (with extra parity bit)
- **Example**: 7-bit Hamming code (4 data + 3 parity) corrects single error

**C. Reed-Solomon Codes** 
- **Concept**: Block-based error correcting codes working on symbols (bytes) rather than bits
- **Used in**: CDs/DVDs, QR codes, satellite communication
- **Can correct**: Burst errors

**D. Convolutional Codes** 
- **Concept**: Encoder has memory; output depends on current and previous inputs
- **Used with**: Viterbi decoding algorithm
- **Applications**: Deep space communications, voice transmission

**E. Turbo Codes** 
- **Concept**: Combine convolutional codes with interleaving and iterative decoding
- **Performance**: Approach Shannon limit
- **Used in**: 3G/4G mobile communications

### Comparison: Detection vs Correction

| Feature | Error Detection | Error Correction |
| :--- | :--- | :--- |
| **Redundancy** | Less overhead | More overhead |
| **Mechanism** | Detect errors, request retransmission | Correct errors at receiver |
| **Efficiency** | Better for reliable links | Better for high-latency links |
| **Examples** | CRC, Parity, Checksum | Hamming, Reed-Solomon, Turbo |
| **Use case** | Wired networks (Ethernet) | Wireless, satellite, deep space |

---

## 3.4 High-Level Data Link Control (HDLC) & Point-to-Point Protocol (PPP)

### 3.4.1 High-Level Data Link Control (HDLC)

**Overview** 
- **Definition**: Bit-oriented synchronous data link layer protocol developed by ISO
- **Based on**: SDLC (IBM)
- **Supports**: Point-to-point and multipoint configurations
- **Transfer modes**:
  - **Normal Response Mode (NRM)** : Unbalanced configuration with primary station controlling secondary stations
  - **Asynchronous Balanced Mode (ABM)** : Balanced, peer-to-peer communication (most common)
  - **Asynchronous Response Mode (ARM)** : Secondary can initiate transmission without permission

**HDLC Frame Structure** 

HDLC frame contains up to six fields:

| Field | Length | Description |
| :--- | :--- | :--- |
| **Flag** | 8 bits | Synchronization pattern **01111110** at both ends |
| **Address** | 8+ bits | Address of secondary station |
| **Control** | 8/16 bits | Identifies frame type, sequence numbers, ACKs |
| **Information** | Variable | User data from network layer |
| **FCS** | 16/32 bits | CRC error detection |
| **Flag** | 8 bits | Ending delimiter |

**HDLC Frame Types** 

**A. I-Frames (Information Frames)**
- **Purpose**: Carry user data from network layer
- **Control field**: First bit = 0
- **Contains**:
  - **N(S)** : 3-bit send sequence number
  - **N(R)** : 3-bit receive sequence number (acknowledgment)
  - **P/F bit**: Poll (primary to secondary) or Final (secondary to primary)
- **Feature**: Supports piggybacking (data + acknowledgment in same frame)

**B. S-Frames (Supervisory Frames)** 
- **Purpose**: Flow and error control when piggybacking not possible
- **Control field**: First 2 bits = 10
- **Types** (code subfield):
  - **00 - RR (Receive Ready)** : Acknowledges safe receipt, ready for more
  - **10 - RNR (Receive Not Ready)** : Acknowledges but indicates busy (slow down)
  - **01 - REJ (Reject)** : Go-Back-N ARQ request for retransmission
  - **11 - SREJ (Selective Reject)** : Selective Repeat ARQ request
- **No information field**

**C. U-Frames (Unnumbered Frames)** 
- **Purpose**: Link management, session control
- **Control field**: First 2 bits = 11
- **Functions**: Set up connection, disconnect, mode setting
- **May contain information field** for system management

**HDLC Advantages**:
- Reliable, connection-oriented service
- Supports multiple frame types for different purposes
- Bit stuffing ensures transparency

**HDLC Disadvantages**:
- Complex implementation
- Overhead for control fields

### 3.4.2 Point-to-Point Protocol (PPP)

**Overview** 
- **Definition**: Data link layer protocol for point-to-point connections
- **Standard**: RFC 1661
- **Based on**: HDLC frame format but extended with additional features
- **Purpose**: Transport multiple network layer protocols over serial links (dial-up, DSL, T1/E1)

**PPP Features** 
- **Media independent**: Can run over various physical layers (serial, Ethernet - PPPoE)
- **Protocol multiplexing**: Carries multiple Layer 3 protocols simultaneously (IP, IPX, AppleTalk)
- **Authentication**: PAP (Password Authentication Protocol), CHAP (Challenge Handshake Authentication Protocol)
- **Link configuration**: Negotiates options (maximum packet size, compression)
- **Address assignment**: Can assign IP addresses dynamically (like DHCP)
- **Compression**: Stacker, Predictor compression protocols
- **Error detection**: Uses CRC but no retransmission (relies on upper layers)
- **Loop detection**: Magic numbers detect looped-back connections

**PPP Components** 

**A. HDLC Framing**
- Uses HDLC-like framing with flags, address, control, protocol, information, FCS
- **Address field**: Always 11111111 (broadcast)
- **Control field**: 00000011 (UI - Unnumbered Information)

**B. Link Control Protocol (LCP)** 
- Establishes, configures, and tests data link connection
- Negotiates options: Maximum Receive Unit (MRU), authentication protocol, compression
- Link termination when done

**C. Network Control Protocols (NCPs)** 
- One per network layer protocol
- **IPCP (IP Control Protocol)** : Configures IP addresses, compression
- **IPXCP**: For Novell IPX
- **ATCP**: For AppleTalk

**PPP Operation Phases**:
1. **Link Dead**: Physical layer not ready
2. **Link Establishment**: LCP exchanges configuration packets
3. **Authentication** (optional): PAP or CHAP verification
4. **Network Layer Configuration**: NCP configures network protocols
5. **Link Open**: Data transfer
6. **Link Termination**: LCP terminates connection

### Comparison: HDLC vs PPP 

| Feature | HDLC | PPP |
| :--- | :--- | :--- |
| **Type** | Bit-oriented | Character-oriented (but uses HDLC framing) |
| **Standard** | ISO | IETF (RFC 1661) |
| **Multiprotocol support** | Limited | Yes (explicit Protocol field) |
| **Authentication** | No | Yes (PAP, CHAP, EAP) |
| **Dynamic addressing** | No | Yes (IPCP assigns addresses) |
| **Compression** | No | Yes (Stacker, Predictor) |
| **Link quality monitoring** | No | Yes |
| **Error detection** | CRC | CRC |
| **Vendor proprietary** | Cisco HDLC (proprietary extension) | Open standard |
| **Use cases** | Legacy WAN, Cisco routers | Dial-up, DSL, PPPoE, VPN |

**Real-world example**: When you connect to internet via DSL modem, PPP is often used over Ethernet (PPPoE) to authenticate and assign IP address.

---

## 3.5 Channel Allocation Problem

### Definition
- **Channel Allocation Problem**: How to allocate a single broadcast channel among multiple competing users efficiently and fairly 
- **Also known as**: Multiple Access Problem, Medium Access Control (MAC) problem

### Classification of Channel Allocation Schemes 

**A. Static Channel Allocation**
- **Fixed allocation** of channel resources to users
- **Examples**: FDM (Frequency Division Multiplexing), TDM (Time Division Multiplexing)
- **Advantages**: Simple, no overhead for coordination
- **Disadvantages**: Inefficient when users have bursty traffic (idle slots wasted)
- **When suitable**: Constant traffic, small number of users

**B. Dynamic Channel Allocation**
- **On-demand allocation** of channel resources
- Channel allocated when user needs to transmit
- **Advantages**: Efficient for bursty traffic
- **Disadvantages**: Overhead for coordination, potential collisions

### Static vs Dynamic Allocation

| Parameter | Static Allocation | Dynamic Allocation |
| :--- | :--- | :--- |
| **Channel partitioning** | Fixed | On-demand |
| **Efficiency for bursty traffic** | Low | High |
| **Delay** | Predictable | Variable |
| **Implementation complexity** | Low | High |
| **Suitable for** | Voice (constant bit rate) | Data (bursty traffic) |

### Assumptions for Dynamic Channel Allocation 

1. **Station Model**: N independent stations generate frames with Poisson distribution
2. **Single Channel**: All stations contend for single shared channel
3. **Collision Detection**: Stations can detect collisions (wired) or not (wireless)
4. **Continuous Time vs Slotted Time**:
   - **Continuous**: Frames transmitted at any time
   - **Slotted**: Time divided into discrete slots
5. **Carrier Sense vs No Carrier Sense**:
   - **Carrier Sense**: Stations can detect if channel is busy before transmitting
   - **No Carrier Sense**: Stations just transmit and hope

---

## 3.6 Multiple Access Protocols 

### Classification

```
MULTIPLE ACCESS PROTOCOLS
├── Random Access Protocols
│   ├── ALOHA (Pure, Slotted)
│   ├── CSMA (1-persistent, Non-persistent, p-persistent)
│   ├── CSMA/CD (Collision Detection)
│   └── CSMA/CA (Collision Avoidance)
├── Controlled Access Protocols
│   ├── Reservation
│   ├── Polling
│   └── Token Passing
└── Channelization Protocols
    ├── FDMA
    ├── TDMA
    └── CDMA
```

### 3.6.1 Random Access Protocols

#### A. ALOHA 

**Pure ALOHA**
- **Concept**: Station transmits whenever it has data
- **Collision**: If two stations transmit simultaneously → collision → both lost
- **Acknowledgement**: Sender waits for ACK; if no ACK within timeout, retransmits after random delay
- **Vulnerable period**: 2 × frame transmission time (collision if any other transmits during this period)
- **Throughput**: Maximum 18.4% (S = G × e^(-2G))
- **Real-world example**: Early University of Hawaii network, satellite communications

**Slotted ALOHA**
- **Concept**: Time divided into discrete slots equal to frame transmission time
- **Rule**: Transmit only at beginning of time slot
- **Synchronization**: All stations must be synchronized
- **Vulnerable period**: Reduced to 1 slot (only collisions at slot boundaries)
- **Throughput**: Maximum 36.8% (S = G × e^(-G)) - double of Pure ALOHA
- **Real-world example**: Some satellite systems

#### B. CSMA (Carrier Sense Multiple Access) 

**Concept**: Listen before transmitting - "sense carrier" to check if channel busy

**Persistence Strategies**:

**1-persistent CSMA**
- If channel idle → transmit immediately (probability = 1)
- If channel busy → continuously sense; transmit as soon as idle
- **Problem**: If multiple stations waiting, all transmit simultaneously → collision

**Non-persistent CSMA**
- If channel idle → transmit
- If channel busy → wait random time, then sense again
- **Advantage**: Reduces collisions compared to 1-persistent
- **Disadvantage**: Increases delay (idle channel may go unused)

**p-persistent CSMA** (for slotted channels)
- If channel idle → transmit with probability p; delay one slot with probability (1-p)
- Continue until transmitted or channel becomes busy
- **Goal**: Balance between collisions and idle time

#### C. CSMA/CD (CSMA with Collision Detection) 

**Concept**: Listen while transmitting; if collision detected, abort immediately

**Process**:
1. Sense channel
2. If idle → transmit and monitor
3. If collision detected → abort transmission, send jam signal
4. Wait random time (binary exponential backoff) → retry

**Binary Exponential Backoff** :
- First collision: wait random time from 0 to 2d (d = max propagation delay)
- Second collision: wait from 0 to 4d
- Third collision: wait from 0 to 8d
- After 10 collisions: interval fixed at 1024d
- After 16 collisions: give up, report error

**Real-world example**: Original Ethernet (IEEE 802.3) 

**Requirements**:
- Frame must be long enough to detect collision before transmission ends
- Minimum frame size = 2 × propagation delay × bandwidth

#### D. CSMA/CA (CSMA with Collision Avoidance) 

**Why needed?** Wireless networks cannot detect collisions reliably (hidden terminal problem)

**Hidden Terminal Problem** :
- Station A can reach B, station C can reach B
- A and C cannot sense each other
- Both transmit to B simultaneously → collision at B but A/C unaware

**CSMA/CA Solution** :

1. **Virtual carrier sensing using RTS/CTS**:
   - Sender sends short **RTS (Request to Send)** frame
   - Receiver replies with **CTS (Clear to Send)** frame
   - RTS/CTS contains duration information
   - All stations hearing either RTS or CTS set NAV (Network Allocation Vector) and remain silent

2. **Explicit acknowledgment**:
   - Receiver sends ACK after successful reception
   - If no ACK, sender retransmits after random backoff

3. **Interframe spacing (IFS)** :
   - Different priority levels: SIFS < PIFS < DIFS

**Real-world example**: Wi-Fi (IEEE 802.11) 

### 3.6.2 Controlled Access Protocols 

#### A. Reservation
- **Concept**: Stations reserve future time slots for transmission
- **Process**:
  1. Contention period: Stations send reservation requests
  2. Reservation period: Controller announces allocation
  3. Transmission period: Stations transmit in assigned slots
- **Real-world example**: Satellite communication, DOCSIS (cable modems)

#### B. Polling 
- **Concept**: Central controller (primary) invites stations (secondaries) to transmit
- **Process**:
  1. Controller sends poll message to station
  2. Station responds with data (or "pass" if no data)
  3. Controller polls next station
- **Types**:
  - **Roll-call polling**: Poll each station individually
  - **Hub polling**: Station passes poll to next station
- **Real-world example**: IBM mainframe terminals, Bluetooth (master-slave)

#### C. Token Passing 
- **Concept**: Special frame (token) circulates; station holding token may transmit
- **Process**:
  1. Token passed in logical ring order
  2. Station with data: captures token, transmits frame(s), releases token
  3. Station without data: immediately passes token
- **Advantages**: No collisions, deterministic delay
- **Disadvantages**: Token management overhead (lost token, duplicate token)
- **Real-world example**: Token Ring (IEEE 802.5), FDDI, Token Bus (IEEE 802.4) 

### 3.6.3 Channelization Protocols 

#### A. FDMA (Frequency Division Multiple Access)
- **Concept**: Frequency band divided into channels; each station assigned fixed frequency
- **Process**: Station transmits continuously on its frequency
- **Guard bands**: Prevent interference between adjacent channels
- **Real-world example**: Analog cellular (AMPS), radio stations
- **Advantages**: Continuous transmission, no synchronization
- **Disadvantages**: Inflexible, waste if station silent

#### B. TDMA (Time Division Multiple Access) 
- **Concept**: Time divided into slots; each station assigned fixed slot(s)
- **Process**: Station transmits in its slot(s), silent otherwise
- **Synchronization**: All stations must be synchronized
- **Real-world example**: GSM (2G cellular), satellite systems
- **Advantages**: Flexible allocation, digital
- **Disadvantages**: Synchronization overhead, burst transmission

#### C. CDMA (Code Division Multiple Access) 
- **Concept**: All stations transmit simultaneously on same frequency using orthogonal codes
- **Principle**: Each bit multiplied by chip sequence (code)
- **Process**:
  - Each station assigned unique orthogonal code
  - All transmit simultaneously; signals combine (sum)
  - Receiver multiplies by same code to extract original signal
- **Orthogonal codes**: Inner product of different codes = 0
- **Real-world example**: 3G cellular (UMTS), GPS
- **Advantages**: High capacity, security, no coordination needed
- **Disadvantages**: Complex receivers, near-far problem (requires power control)

---

## 3.7 Wired LAN: Ethernet Standards and FDDI

### 3.7.1 Ethernet (IEEE 802.3) 

**Overview**
- **Definition**: Most widely used wired LAN protocol
- **Standard**: IEEE 802.3
- **Original design**: CSMA/CD with coaxial cable
- **Evolution**: Supports various media (twisted pair, fiber) and speeds

**Ethernet Frame Structure**

| Field | Length | Description |
| :--- | :--- | :--- |
| **Preamble** | 7 bytes | Alternating 1/0 for synchronization |
| **SFD** | 1 byte | Start Frame Delimiter (10101011) |
| **Destination MAC** | 6 bytes | Receiver physical address |
| **Source MAC** | 6 bytes | Sender physical address |
| **Length/Type** | 2 bytes | Data length OR protocol type |
| **Data** | 46-1500 bytes | Payload (Network layer PDU) |
| **Pad** | Variable | Ensures minimum frame size (64 bytes) |
| **FCS** | 4 bytes | CRC-32 error detection |

**Minimum frame size**: 64 bytes (required for CSMA/CD to detect collisions)

**Ethernet Standards Evolution**

| Standard | Speed | Media | Year | Notes |
| :--- | :--- | :--- | :--- | :--- |
| **10BASE5** | 10 Mbps | Thick coaxial | 1983 | Original "Thick Ethernet", 500m segments |
| **10BASE2** | 10 Mbps | Thin coaxial | 1985 | "Thin Ethernet", 185m segments |
| **10BASE-T** | 10 Mbps | Cat3 UTP | 1990 | Twisted pair, star topology |
| **100BASE-TX**  | 100 Mbps | Cat5 UTP | 1995 | Fast Ethernet, based on FDDI technology |
| **100BASE-FX**  | 100 Mbps | Fiber | 1995 | Fast Ethernet over fiber |
| **1000BASE-T** | 1 Gbps | Cat5e UTP | 1999 | Gigabit Ethernet over copper |
| **1000BASE-SX/LX** | 1 Gbps | Fiber | 1998 | Gigabit Ethernet over fiber |
| **10GBASE-T** | 10 Gbps | Cat6a/7 UTP | 2006 | 10 Gigabit Ethernet |
| **40GBASE-T** | 40 Gbps | Cat8 | 2016 | 40 Gigabit Ethernet |
| **100GBASE** | 100 Gbps | Fiber | 2010 | Data center/backbone |

**Naming Convention**: [Speed][BASE][Medium Type]
- **BASE**: Baseband signaling
- **T**: Twisted pair
- **FX/SX/LX**: Fiber types

**Ethernet MAC Sublayer** 
- **Half-duplex**: CSMA/CD, only one station transmits at a time
- **Full-duplex**: Simultaneous transmission/reception, no collisions, requires switched connections

### 3.7.2 FDDI (Fiber Distributed Data Interface) 

**Overview**
- **Definition**: 100 Mbps token-passing network using fiber optic cable
- **Standard**: ANSI X3T9.5, later ISO 9314
- **Topology**: Dual counter-rotating rings (primary + secondary)
- **Maximum nodes**: 500
- **Maximum ring length**: 100 km (200 km with dual ring)
- **Maximum distance between nodes**: 2 km (multimode fiber)

**Key Features**

**Dual Ring Architecture**:
- **Primary ring**: Carries data in one direction
- **Secondary ring**: Backup (idle) or carries data in opposite direction
- **Self-healing**: If ring breaks, stations wrap around to secondary ring

**Token Passing**:
- Station must capture token before transmitting
- Multiple frames can be transmitted per token
- Token released after transmission (early token release)

**Timed Token Protocol**:
- Target Token Rotation Time (TTRT) negotiated
- Guarantees maximum delay for synchronous traffic
- Supports both synchronous (real-time) and asynchronous traffic

**Frame Format**:
- Similar to Token Ring but with longer maximum frame size (4500 bytes)

**Applications**:
- Campus backbone networks (1990s)
- Metropolitan Area Networks (MANs)
- Critical applications requiring redundancy

**Advantages**:
- Deterministic access (unlike Ethernet's CSMA/CD)
- High reliability (dual ring, self-healing)
- Long distance capability
- Immunity to EMI (fiber)

**Disadvantages**:
- Expensive (fiber, optical components)
- Complex management
- Obsoleted by Fast/Gigabit Ethernet

**Historical Significance**:
- 100BASE-TX Fast Ethernet borrowed physical layer technology from FDDI 
- FDDI technology lives on in Ethernet standards

---

## 3.8 Wireless LAN: IEEE 802.11x and Bluetooth Standards

### 3.8.1 IEEE 802.11 (Wi-Fi) 

**Overview**
- **Definition**: Set of standards for Wireless Local Area Networks (WLANs)
- **Frequency bands**: 2.4 GHz, 5 GHz, 6 GHz
- **MAC layer**: CSMA/CA (not CSMA/CD - can't detect collisions)
- **Topology**: Infrastructure mode (with Access Point) or Ad-hoc mode

**IEEE 802.11 Standards Evolution** 

| Standard | Year | Frequency | Max Data Rate | Notes |
| :--- | :--- | :--- | :--- | :--- |
| **802.11** | 1997 | 2.4 GHz | 2 Mbps | Original, FHSS/DSSS |
| **802.11a** | 1999 | 5 GHz | 54 Mbps | OFDM, not compatible with b |
| **802.11b** | 1999 | 2.4 GHz | 11 Mbps | DSSS, popularized Wi-Fi |
| **802.11g** | 2003 | 2.4 GHz | 54 Mbps | Backward compatible with b |
| **802.11n** | 2009 | 2.4/5 GHz | 600 Mbps | MIMO, multiple antennas |
| **802.11ac** | 2013 | 5 GHz | 1.3 Gbps+ | Wider channels, MU-MIMO |
| **802.11ax (Wi-Fi 6)** | 2019 | 2.4/5/6 GHz | 9.6 Gbps | OFDMA, better efficiency |
| **802.11be (Wi-Fi 7)** | 2024 | 2.4/5/6 GHz | 46 Gbps | 320 MHz channels, Multi-link |

**802.11 MAC Sublayer Features** 

**A. Distributed Coordination Function (DCF)** :
- CSMA/CA with binary exponential backoff
- Mandatory for all stations

**B. Point Coordination Function (PCF)** :
- Optional, centralized contention-free service
- Access Point acts as point coordinator

**C. Frame Types**:
- **Management frames**: Association, authentication, beacon
- **Control frames**: RTS, CTS, ACK
- **Data frames**: Carry upper layer data

**D. Fragmentation**:
- Large frames fragmented to improve reliability in noisy environments

**E. Power Management**:
- Stations can sleep and wake up for beacons

**802.11 Security** 

| Standard | Security Feature | Status |
| :--- | :--- | :--- |
| **WEP** | Wired Equivalent Privacy | Broken, not secure |
| **WPA** | Wi-Fi Protected Access | Temporary improvement |
| **802.11i/WPA2**  | AES encryption, 802.1X authentication | Current standard |
| **WPA3** | Simultaneous Authentication of Equals (SAE) | Latest, stronger |

**802.11i (Robust Security Network)** :
- **TKIP**: Temporal Key Integrity Protocol (transitional)
- **CCMP**: AES-based encryption (strong)
- **802.1X**: Authentication framework with RADIUS server

### 3.8.2 Bluetooth (IEEE 802.15.1) 

**Overview**
- **Definition**: Short-range wireless technology for Personal Area Networks (PANs)
- **Frequency**: 2.4 GHz ISM band
- **Range**: 10-100 meters (depending on class)
- **Data rate**: 1-3 Mbps (Classic), up to 2 Mbps (LE)
- **Topology**: Piconet and Scatternet

**Bluetooth Architecture**

**Piconet**:
- One master + up to 7 active slaves
- Master determines hopping sequence and timing
- Slaves communicate only with master
- More slaves can be "parked" (inactive but synchronized)

**Scatternet**:
- Multiple interconnected piconets
- A device can be slave in multiple piconets
- Or master in one, slave in another

**Bluetooth Protocol Stack**

| Layer | Function |
| :--- | :--- |
| **Radio** | Physical layer, frequency hopping (1600 hops/sec) |
| **Baseband** | MAC layer, piconet/channel management |
| **LMP** | Link Manager Protocol, connection setup |
| **L2CAP** | Logical Link Control and Adaptation Protocol |
| **RFCOMM** | Serial port emulation |
| **SDP** | Service Discovery Protocol |
| **Profiles** | Application-specific (HSP, HFP, A2DP, etc.) |

**Bluetooth Versions**

| Version | Year | Key Features |
| :--- | :--- | :--- |
| **1.0/1.1** | 1999-2001 | Initial versions |
| **1.2** | 2003 | Adaptive Frequency Hopping (AFH) |
| **2.0+EDR** | 2004 | Enhanced Data Rate (3 Mbps) |
| **3.0+HS** | 2009 | High Speed (uses Wi-Fi for data) |
| **4.0** | 2010 | Bluetooth Low Energy (BLE) |
| **4.2** | 2014 | IP connectivity, improved privacy |
| **5.0** | 2016 | 2x speed, 4x range, 8x broadcast capacity |
| **5.1/5.2** | 2019-2020 | Angle of Arrival (AoA), LE Audio |
| **5.3/5.4** | 2021-2023 | Improved efficiency, periodic advertising |

**Bluetooth vs Wi-Fi**

| Feature | Bluetooth | Wi-Fi |
| :--- | :--- | :--- |
| **Range** | Short (10-100m) | Medium (50-100m indoor) |
| **Data rate** | Low (1-3 Mbps) | High (11 Mbps - 9.6 Gbps) |
| **Power consumption** | Very low | Moderate to high |
| **Network size** | Small (8 active) | Large (255+ devices) |
| **Topology** | Master-slave | Star (AP-based) or ad-hoc |
| **Application** | Peripheral connectivity | Internet access, file transfer |

---

## 3.9 Token Bus, Token Ring and Virtual LAN

### 3.9.1 Token Bus (IEEE 802.4) 

**Overview**
- **Definition**: Network combining physical bus topology with token-passing access method
- **Standard**: IEEE 802.4
- **Purpose**: Combine benefits of bus (simple cabling) with deterministic token passing
- **Primary use**: Industrial automation, Manufacturing Automation Protocol (MAP) by General Motors 

**Architecture** 
- **Physical topology**: Bus (coaxial cable)
- **Logical topology**: Ring (token passed in logical order)
- Each station knows address of its predecessor and successor in logical ring
- Token circulates according to logical ring order, not physical position

**Token Passing Mechanism** 
1. Station with token may transmit for specified time
2. After transmission (or if no data), passes token to next station in logical ring
3. Token contains destination address of next station
4. All stations monitor bus; addressed station accepts token

**Ring Management Functions**:
- **Ring initialization**: Establishing logical order when network starts
- **Station insertion**: New station must be added to logical ring
- **Station deletion**: Station leaving must be removed
- **Recovery**: Handling lost token, duplicate token

**Advantages** :
- **Deterministic**: Maximum waiting time guaranteed (unlike Ethernet's CSMA/CD)
- **Fair access**: All stations get chance to transmit
- **No collisions**: Token ensures only one transmitter at a time
- **Priority support**: Can implement priority classes

**Disadvantages**:
- Complex protocol (ring management overhead)
- Expensive hardware compared to Ethernet
- Poor performance under light load (waiting for token)
- Obsoleted by switched Ethernet

**Historical significance**: Used in factory automation, process control where predictable timing was critical 

### 3.9.2 Token Ring (IEEE 802.5)

**Overview**
- **Definition**: Network with star topology but logical ring using token passing
- **Standard**: IEEE 802.5
- **Developed by**: IBM
- **Speed**: 4 Mbps, 16 Mbps (later 100 Mbps - FDDI)

**Architecture**
- **Physical topology**: Star (all stations connect to Multistation Access Unit - MSAU)
- **Logical topology**: Ring (signal passes from station to station in logical order)
- **MSAU**: Wiring concentrator that maintains ring if station disconnected

**Token Ring Frame Format**

| Field | Length | Description |
| :--- | :--- | :--- |
| **Start Delimiter** | 1 byte | Signals frame start (J,K symbols) |
| **Access Control** | 1 byte | Priority, token bit, monitor bit |
| **Frame Control** | 1 byte | Data or MAC frame type |
| **Destination MAC** | 6 bytes | Receiver address |
| **Source MAC** | 6 bytes | Sender address |
| **Data** | Variable | Upper layer data |
| **FCS** | 4 bytes | CRC-32 |
| **End Delimiter** | 1 byte | Frame end, error detection |
| **Frame Status** | 1 byte | Address recognized, frame copied |

**Token Ring Operation**
1. **Token circulation**: 3-byte token circulates when no data
2. **Capture**: Station with data changes token to start of frame
3. **Transmission**: Data frame circulates, each station repeats
4. **Removal**: Sender removes its frame after full circulation
5. **Release**: Sender releases new token

**Priority Mechanism**:
- 3 priority bits in Access Control field
- Stations can reserve priority for next token
- Supports 8 priority levels

**Monitor Station**:
- One station acts as active monitor
- Detects lost token, cleans up circulating frames
- Ensures maximum token holding time

**Advantages**:
- Deterministic access (good for real-time)
- Fairness (each station gets turn)
- Priority support

**Disadvantages**:
- Expensive (active components in each station)
- Complex management
- Vulnerable to single station failure (unless bypassed)
- Obsoleted by switched Ethernet

### 3.9.3 Virtual LAN (VLAN) 

**Overview**
- **Definition**: Logical grouping of devices in same broadcast domain regardless of physical location
- **Standard**: IEEE 802.1Q
- **Purpose**: Overcome limitations of physical LAN segmentation

**Why VLANs Needed?**
- In flat switched network, all devices receive broadcasts
- Broadcasts consume bandwidth and CPU
- Security concerns (any device can see any traffic)
- Physical relocation requires recabling

**VLAN Benefits**
- **Broadcast control**: Limits broadcast domain size
- **Security**: Isolate sensitive traffic
- **Flexibility**: Logical grouping independent of physical location
- **Simplified management**: Moves/changes done logically
- **Performance**: Reduces unnecessary traffic

**How VLAN Works**
- Switch assigns ports to VLANs
- Each VLAN is separate broadcast domain
- Frames only delivered within same VLAN
- Inter-VLAN communication requires router/Layer 3 switch

**VLAN Types**

| Type | Description | Example |
| :--- | :--- | :--- |
| **Port-based** | VLAN membership by switch port | Ports 1-10 = VLAN 10, Ports 11-20 = VLAN 20 |
| **MAC-based** | Membership by device MAC address | Specific servers always in same VLAN |
| **Protocol-based** | Membership by Layer 3 protocol | IP traffic in VLAN 10, IPX in VLAN 20 |
| **Subnet-based** | Membership by IP subnet | 192.168.1.0/24 = VLAN 10 |

**IEEE 802.1Q Tagging**

When frame travels between switches, VLAN information must be preserved:

| Field | Length | Description |
| :--- | :--- | :--- |
| **TPID** | 2 bytes | Tag Protocol Identifier (0x8100) |
| **TCI** | 2 bytes | Tag Control Information |
| ├─ **PCP** | 3 bits | Priority Code Point (802.1p QoS) |
| ├─ **DEI** | 1 bit | Drop Eligible Indicator |
| └─ **VID** | 12 bits | VLAN Identifier (1-4094) |

**Trunking**:
- Link carrying multiple VLANs between switches
- Uses 802.1Q tagging to identify frames
- Native VLAN (usually VLAN 1) untagged

**VLAN Configuration Example**:
```
Engineering VLAN (VLAN 10): Ports 1-8, 15-20
Marketing VLAN (VLAN 20): Ports 9-14, 21-24
Server VLAN (VLAN 100): Ports 45-48
Management VLAN (VLAN 99): Special access for administrators
```

**Advantages** :
- **Segmentation**: Split network logically without new hardware
- **Security**: Isolate sensitive departments (HR, Finance)
- **Cost reduction**: Fewer routers/switches needed
- **Simplified moves**: User moves office but stays in same VLAN
- **Load balancing**: Distribute traffic across multiple paths

**Disadvantages**:
- **Complexity**: Requires careful planning and documentation
- **VLAN hopping attacks**: Security risk if misconfigured
- **Troubleshooting difficulty**: Traffic invisible across VLANs

**Real-world example**: University campus network with:
- Student VLAN (internet only, no internal access)
- Staff VLAN (internal resources, email)
- Server VLAN (protected, restricted access)
- Guest VLAN (internet only, isolated)

---

## Summary Table: Multiple Access Protocols Comparison

| Protocol | Access Method | Collisions | Deterministic | Efficiency | Example |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Pure ALOHA** | Random | Yes | No | 18% max | Satellite |
| **Slotted ALOHA** | Random | Yes | No | 37% max | Satellite |
| **CSMA/CD** | Random | Detected | No | High | Ethernet |
| **CSMA/CA** | Random with avoidance | Avoided | No | Medium | Wi-Fi |
| **Token Passing** | Controlled | None | Yes | High | Token Ring, FDDI |
| **Polling** | Controlled | None | Yes | Medium | Bluetooth (master-slave) |
| **Reservation** | Controlled | None | Yes | High | Satellite, cable |
| **FDMA** | Channelization | None | Yes | Low (idle waste) | Analog cellular |
| **TDMA** | Channelization | None | Yes | Medium | GSM |
| **CDMA** | Channelization | None | No | High | 3G cellular |
