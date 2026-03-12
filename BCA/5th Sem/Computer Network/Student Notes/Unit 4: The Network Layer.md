# Unit 4: The Network Layer

## 4.1 Functions of Network Layer

### Definition and Position
- **Definition**: Layer 3 of OSI model that provides end-to-end packet delivery across multiple networks from source to destination 
- **Position**: Interface between transport layer (Layer 4) and data link layer (Layer 2)
- **PDU (Protocol Data Unit)** : Packet
- **Key devices**: Routers operate at this layer

### Primary Functions

**A. Logical Addressing**
- Adds source and destination IP addresses to packets
- Provides unique identification to each device across internetwork
- Addresses are hierarchical (network portion + host portion) unlike flat MAC addresses

**B. Routing**
- Determines best path for packet delivery from source to destination
- Uses routing algorithms and routing tables
- Makes decisions based on topology, traffic load, cost, and other metrics
- **Real-world example**: GPS navigation finding shortest route considering traffic

**C. Packet Forwarding**
- Moves packets from input port to appropriate output port on routers
- Uses forwarding table built by routing protocols
- Can be:
  - **Next-hop forwarding**: Only next router address stored
  - **Network-specific forwarding**: All hosts on network share entry
  - **Default forwarding**: Packets sent to default route if no match

**D. Fragmentation and Reassembly**
- Splits packets into smaller units when they exceed MTU of underlying network
- Different networks have different MTU sizes:
  - Ethernet: 1500 bytes
  - PPP: 1500 bytes (typical)
  - FDDI: 4352 bytes
- Reassembly done only at destination (not intermediate routers) in IPv4

**E. Internetworking**
- Connects different types of networks (LAN, WAN, wireless)
- Hides network heterogeneity from upper layers
- Provides uniform service regardless of underlying technology

**F. Quality of Service (QoS)**
- Provides differentiated treatment for different types of traffic
- Prioritizes real-time traffic (VoIP, video) over bulk data
- Uses Type of Service (ToS) field in IPv4 header

**G. Error Handling and Diagnostics**
- Reports errors (unreachable host, time exceeded) using ICMP
- Assists in troubleshooting network problems
- **Real-world example**: "Destination unreachable" ping message

### Network Layer Design Goals 
- Services independent of subnet technology
- Transport layer unaware of number, type, and topology of subnets
- Uniform network addressing across different networks
- Services provided should be consistent regardless of underlying subnet

---

## 4.2 Virtual Circuits and Datagram Subnets

### 4.2.1 Virtual Circuit (Connection-Oriented) 

**Concept**
- Path established before data transmission begins
- All packets follow same path
- Router resources can be reserved along path

**Operation Phases**

| Phase | Description |
| :--- | :--- |
| **1. Setup** | Path established, routing decision made once |
| **2. Data Transfer** | All packets follow predetermined path |
| **3. Teardown** | Connection terminated, resources released |

**Characteristics**
- Each packet carries virtual circuit identifier (small label) not full destination address
- Router maintains state information per connection
- Guarantees in-sequence delivery
- **Example technologies**: ATM, Frame Relay, MPLS

**Advantages**
- Fast forwarding (simple table lookup using VCI)
- Better QoS guarantees possible
- Predictable performance
- Less overhead per packet (small header)

**Disadvantages**
- Setup delay before data transfer
- Router memory required for connection state
- Vulnerable to router failure (all VC packets lost)
- Less flexible for fault recovery

**Real-world example**: Traditional telephone call—circuit established before conversation

### 4.2.2 Datagram (Connectionless) 

**Concept**
- Each packet routed independently
- No path establishment phase
- Each packet carries full destination address

**Characteristics**
- Packets may take different paths
- Packets may arrive out of order (reordering by transport layer)
- Routers maintain no connection state
- **Example technology**: IP (Internet Protocol)

**Advantages**
- No setup delay
- More robust—packets rerouted around failures
- Better for bursty traffic
- Router failure affects only packets in transit

**Disadvantages**
- Larger packet headers (full addresses)
- No QoS guarantees
- Packets may arrive out of order
- Higher processing per packet

**Real-world example**: Postal service—each letter routed independently

### 4.2.3 Comparison: Virtual Circuit vs Datagram

| Feature | Virtual Circuit | Datagram |
| :--- | :--- | :--- |
| **Path setup** | Required before data transfer | Not required |
| **Addressing** | Each packet carries short VCI | Each packet carries full destination address |
| **State information** | Router maintains per-connection state | Router maintains no connection state |
| **Routing decision** | Made once at setup | Made per packet |
| **Router failure effect** | All VCs through failed router lost | Packets rerouted, only affected packets lost |
| **QoS support** | Easy to support | Difficult |
| **Ordering** | Packets arrive in order | Packets may arrive out of order |
| **Typical use** | ATM, Frame Relay, MPLS | Internet (IP) |

---

## 4.3 IPv4 Addresses

### 4.3.1 Address Space and Notations

**Address Space**
- 32-bit address 
- Total possible addresses: 2³² = 4,294,967,296 (approximately 4.3 billion)
- Binary representation: 32 bits (e.g., 11000000.10101000.00000001.00000001)

**Notations** 

**A. Dotted Decimal Notation** (most common)
- Four decimal numbers separated by dots
- Each decimal = 8 bits (octet)
- Range per octet: 0-255
- **Example**: 192.168.1.10

**B. Binary Notation**
- 32 bits in binary
- **Example**: 11000000 10101000 00000001 00001010

**C. Hexadecimal Notation**
- 8 hexadecimal digits
- **Example**: 0xC0A8010A

### 4.3.2 Classful Addressing 

**Historical architecture** (replaced by CIDR in 1993)

**Address Classes**

| Class | First Octet Range | Default Mask | Network/Host Bits | Number of Networks | Hosts per Network |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Class A** | 0-127 | /8 (255.0.0.0) | 7 bits network, 24 bits host | 128 (2⁷) | 16,777,214 (2²⁴-2) |
| **Class B** | 128-191 | /16 (255.255.0.0) | 14 bits network, 16 bits host | 16,384 (2¹⁴) | 65,534 (2¹⁶-2) |
| **Class C** | 192-223 | /24 (255.255.255.0) | 21 bits network, 8 bits host | 2,097,152 (2²¹) | 254 (2⁸-2) |
| **Class D** | 224-239 | Multicast | - | - | - |
| **Class E** | 240-255 | Experimental | - | - | - |

**Special Addresses** 
- **Network address**: Host bits all zeros (e.g., 192.168.1.0/24) - identifies network itself
- **Broadcast address**: Host bits all ones (e.g., 192.168.1.255/24) - sends to all hosts on network
- **Loopback address**: 127.0.0.0/8 (127.0.0.1 commonly) - tests local protocol stack
- **Private addresses** (RFC 1918) :
  - Class A: 10.0.0.0/8 (10.0.0.0 - 10.255.255.255)
  - Class B: 172.16.0.0/12 (172.16.0.0 - 172.31.255.255)
  - Class C: 192.168.0.0/16 (192.168.0.0 - 192.168.255.255)
- **APIPA/Link-local**: 169.254.0.0/16 (auto-configuration when DHCP fails) 
- **Default route**: 0.0.0.0/0

### 4.3.3 Classless Addressing (CIDR) 

**Concept**
- Classless Inter-Domain Routing
- Abolished rigid class boundaries
- Variable-length subnet masks (VLSM)

**CIDR Notation**
- IP address followed by slash and prefix length
- Prefix length = number of bits in network portion
- **Example**: 192.168.1.0/24 (first 24 bits network, last 8 bits host)

**Advantages over Classful**
- Efficient address utilization
- Reduces routing table size (route aggregation/summarization)
- More flexible allocation

### 4.3.4 Subnetting 

**Definition**: Dividing a single network into multiple smaller subnetworks

**Purpose**
- Efficient IP address utilization
- Improved security (isolate departments)
- Reduced broadcast traffic
- Simplified management

**Subnetting Process**
1. Borrow bits from host portion
2. Add to network portion (subnet bits)
3. New subnet mask identifies network + subnet bits

**Example**: Subnet 192.168.1.0/24 into 4 subnets
- Borrow 2 bits from host portion (2² = 4 subnets)
- New mask: /26 (255.255.255.192)
- Subnets:
  - Subnet 0: 192.168.1.0/26 (hosts: 192.168.1.1-62)
  - Subnet 1: 192.168.1.64/26 (hosts: 192.168.1.65-126)
  - Subnet 2: 192.168.1.128/26 (hosts: 192.168.1.129-190)
  - Subnet 3: 192.168.1.192/26 (hosts: 192.168.1.193-254)

**Subnet Mask**
- 32-bit number identifying network portion
- Binary: 1s for network/subnet bits, 0s for host bits
- **Common masks**:
  - /8: 255.0.0.0
  - /16: 255.255.0.0
  - /24: 255.255.255.0
  - /26: 255.255.255.192
  - /27: 255.255.255.224
  - /28: 255.255.255.240
  - /29: 255.255.255.248
  - /30: 255.255.255.252 (point-to-point links)

**Formulas**
- Number of subnets = 2^(borrowed bits)
- Number of hosts per subnet = 2^(remaining host bits) - 2
- Subtract 2 for network address and broadcast address

### 4.3.5 Network Address Translation (NAT) 

**Definition**: Technique mapping multiple private IP addresses to one or more public IP addresses

**Why NAT?**
- IPv4 address exhaustion
- Allow multiple devices to share single public IP
- Provides basic security (hides internal structure)

**How NAT Works**

| Step | Description |
| :--- | :--- |
| 1 | Internal device (192.168.1.10:5000) sends packet to internet |
| 2 | NAT router changes source IP to public IP (203.0.113.5:5000) |
| 3 | NAT router maintains translation table |
| 4 | Response arrives at public IP:port |
| 5 | NAT router translates back to internal IP:port |
| 6 | Packet delivered to internal device |

**Types of NAT**

| Type | Description | Example |
| :--- | :--- | :--- |
| **Static NAT** | One-to-one mapping (private ↔ public) | Web server mapping |
| **Dynamic NAT** | Pool of public IPs, mapped on demand | Enterprise outbound |
| **PAT (Port Address Translation)** / **NAPT** | Many-to-one using port numbers | Home router (most common) |
| **Source NAT** | Modifies source address (outbound) | Internet access |
| **Destination NAT** | Modifies destination address (inbound) | Port forwarding |

**Advantages** 
- Conserves public IPv4 addresses
- Provides basic firewall (unsolicited inbound blocked)
- Flexibility to change ISP without renumbering internal network

**Disadvantages** 
- Breaks end-to-end connectivity principle
- Complications for peer-to-peer apps
- Performance overhead
- Not a substitute for proper security

**Real-world example**: Your home WiFi router—all devices share single public IP from ISP

---

## 4.4 IPv4 Datagram Format and Fragmentation

### 4.4.1 IPv4 Datagram Format 

**Header Structure** (minimum 20 bytes, maximum 60 bytes)

```
 0                   1                   2                   3
 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|Version|  IHL  |Type of Service|          Total Length         |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|         Identification        |Flags|      Fragment Offset    |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|  Time to Live |    Protocol   |         Header Checksum       |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                       Source Address                          |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                    Destination Address                        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                    Options                    |    Padding    |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                            Data                                |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
```

**Field Descriptions** 

| Field | Length | Description |
| :--- | :--- | :--- |
| **Version** | 4 bits | IP version (IPv4 = 4, IPv6 = 6) |
| **IHL (Internet Header Length)** | 4 bits | Header length in 32-bit words (minimum 5 = 20 bytes, maximum 15 = 60 bytes) |
| **Type of Service (ToS)** | 8 bits | QoS parameters (precedence, delay, throughput, reliability) |
| **Total Length** | 16 bits | Entire packet length (header + data) in bytes (max 65,535) |
| **Identification** | 16 bits | Unique ID for fragmentation/reassembly—all fragments share same ID |
| **Flags** | 3 bits | Fragment control: bit 0: reserved, bit 1: DF (Don't Fragment), bit 2: MF (More Fragments) |
| **Fragment Offset** | 13 bits | Position of fragment in original datagram (in 8-byte units) |
| **Time to Live (TTL)** | 8 bits | Max router hops (decremented each hop; packet discarded when 0) |
| **Protocol** | 8 bits | Upper layer protocol (TCP=6, UDP=17, ICMP=1) |
| **Header Checksum** | 16 bits | Error detection for header only (not data) |
| **Source Address** | 32 bits | Sender's IP address |
| **Destination Address** | 32 bits | Receiver's IP address |
| **Options** | 0-40 bytes | Security, timestamp, record route, source routing (rarely used) |
| **Padding** | Variable | Ensures header ends at 32-bit boundary |
| **Data** | Variable | Upper layer payload (TCP segment, UDP datagram, etc.) |

### 4.4.2 Fragmentation 

**Why Fragmentation Needed?**
- Different networks have different Maximum Transmission Unit (MTU)
- If packet > MTU of outgoing network, must fragment
- **Example**: Ethernet MTU = 1500 bytes, FDDI MTU = 4352 bytes

**Fragmentation Process**

| Step | Description |
| :--- | :--- |
| 1 | Router determines outgoing MTU < packet size |
| 2 | Checks DF flag—if set, packet discarded, ICMP "fragmentation needed" sent |
| 3 | If DF not set, packet fragmented into smaller pieces |
| 4 | Each fragment becomes independent IP packet |
| 5 | Fragments travel independently to destination |
| 6 | Destination reassembles using Identification, Fragment Offset, MF flag |

**Fragment Control Fields**

| Field | Purpose |
| :--- | :--- |
| **Identification** | Same in all fragments—identifies original packet |
| **MF (More Fragments) flag** | 1 = more fragments follow, 0 = last fragment |
| **DF (Don't Fragment) flag** | 1 = do not fragment (discard if too large) |
| **Fragment Offset** | Position in original datagram (multiple of 8 bytes) |

**Fragmentation Example**
Original datagram: 4000 bytes (header 20 + data 3980)
MTU = 1500 bytes → maximum data per fragment = 1480 (1500 - 20 header)

| Fragment | Total Length | MF Flag | Fragment Offset |
| :--- | :--- | :--- | :--- |
| 1 | 1500 (20+1480) | 1 | 0 |
| 2 | 1500 (20+1480) | 1 | 185 (1480/8 = 185) |
| 3 | 1020 (20+1000) | 0 | 370 (2960/8 = 370) |

**Important Rules**
- All fragments except last must be multiple of 8 bytes (for offset field)
- Reassembly done only at destination (not intermediate routers)
- If any fragment lost, entire packet discarded (after timeout)

---

## 4.5 IPv6 Address Structure and Advantages over IPv4

### 4.5.1 IPv6 Address Structure 

**Address Space**
- 128-bit address
- Total possible addresses: 2¹²⁸ = 340 undecillion (3.4 × 10³⁸)
- Approximately 6.7 × 10²³ addresses per square meter of Earth's surface

**Notation** 
- Eight groups of four hexadecimal digits
- Separated by colons
- **Example**: 2001:0db8:0000:0000:0000:0000:0000:0001

**Abbreviation Rules** 
1. Leading zeros in each group can be omitted
   - `2001:0db8:0000:0000` → `2001:db8:0:0`
2. One contiguous sequence of zero groups can be replaced with `::` (only once per address)
   - `2001:db8:0:0:0:0:0:1` → `2001:db8::1`

**Address Types** 

| Type | Prefix | Description |
| :--- | :--- | :--- |
| **Unicast** | Various | Single interface identification |
| **Multicast** | FF00::/8 | Delivered to multiple interfaces |
| **Anycast** | Various | Delivered to nearest of multiple interfaces |
| **Link-local** | FE80::/10 | Single link only, auto-configured (equivalent to 169.254/16 in IPv4) |
| **Unique Local** | FC00::/7 | Private addresses (equivalent to RFC 1918 in IPv4) |
| **Global Unicast** | 2000::/3 | Internet-routable addresses |
| **Loopback** | ::1 | Equivalent to 127.0.0.1 |
| **Unspecified** | :: | Equivalent to 0.0.0.0 |

### 4.5.2 IPv6 Advantages over IPv4 

**A. Larger Address Space**
- 128-bit vs 32-bit
- Solves address exhaustion permanently
- Eliminates need for NAT

**B. Simplified Header Format**
- Fixed 40-byte header (vs variable 20-60 bytes in IPv4)
- Fewer fields (8 fields vs 12 in IPv4)
- Faster router processing
- No checksum (reduces processing)

**C. No Fragmentation at Routers**
- Path MTU Discovery performed by source
- Routers just forward packets
- Reduces router load

**D. Built-in Security (IPsec)**
- IPsec required in IPv6 (optional in IPv4)
- Authentication and encryption built in
- Better end-to-end security

**E. Auto-configuration (SLAAC)** 
- Stateless Address Autoconfiguration
- Devices auto-configure using router advertisements
- No DHCP server required

**F. No Broadcast**
- Replaced with multicast and anycast
- Reduces network overhead
- Prevents broadcast storms

**G. Better Mobility Support**
- Built-in mechanisms for mobile devices
- Roaming between networks without changing address
- Mobile IPv6 more efficient than Mobile IPv4

**H. Improved QoS**
- Flow Label field (20 bits) for special handling
- Better support for real-time traffic

**I. Efficient Routing**
- Hierarchical addressing reduces routing table size
- Aggregation more efficient

### 4.5.3 IPv6 vs IPv4 Comparison 

| Feature | IPv4 | IPv6 |
| :--- | :--- | :--- |
| **Address size** | 32 bits | 128 bits |
| **Address format** | Dotted decimal | Hexadecimal colon-separated |
| **Header size** | 20-60 bytes (variable) | 40 bytes (fixed) |
| **Checksum** | Yes (header only) | No |
| **Fragmentation** | At routers and hosts | At source only |
| **Options** | In header | Extension headers |
| **Security (IPsec)** | Optional | Built-in (required) |
| **Auto-configuration** | DHCP | SLAAC + DHCPv6 |
| **Broadcast** | Yes | No (multicast instead) |
| **NAT** | Common | Rarely needed |
| **Address space** | 4.3 billion | 340 undecillion |

### 4.5.4 Transition Mechanisms 

| Mechanism | Description | Example |
| :--- | :--- | :--- |
| **Dual Stack** | Devices run both IPv4 and IPv6 simultaneously | Modern OS, websites |
| **Tunneling** | IPv6 packets encapsulated in IPv4 for transport | 6to4, Teredo |
| **Translation** | NAT-like translation between IPv4 and IPv6 | NAT64/DNS64 |

---

## 4.6 Routing Algorithms

### 4.6.1 Classification of Routing Algorithms

| Classification | Types | Description |
| :--- | :--- | :--- |
| **Decision timing** | Static vs Dynamic | Static: fixed tables; Dynamic: adapt to changes |
| **Information source** | Distributed vs Centralized | Distributed: each router computes; Centralized: single point computes |
| **Update mode** | Periodic vs Event-driven | Periodic: regular updates; Event-driven: triggered by changes |
| **Algorithm type** | Distance Vector vs Link State | See comparison below |

### 4.6.2 Distance Vector Routing 

**Concept**
- Based on Bellman-Ford algorithm
- Each router maintains table of distances to all networks
- Shares entire routing table with neighbors periodically
- "Routing by rumor"—router knows only distances via neighbors

**Operation**

| Step | Description |
| :--- | :--- |
| 1 | Each router initializes distance to directly connected networks as 1 (or cost) |
| 2 | Periodically sends its entire routing table to neighbors |
| 3 | Neighbor updates table if shorter path found (dx(y) = min[cost(x,v) + dv(y)]) |
| 4 | Continues until convergence |

**Example Protocols**
- **RIP (Routing Information Protocol)** : Hop count metric, max 15 hops
- IGRP (Cisco proprietary)
- BGP (path vector, distance vector variant)

**Advantages** 
- Simple to implement
- Low processing overhead
- Suitable for small networks

**Disadvantages** 
- Slow convergence
- Count-to-infinity problem
- Large routing table updates
- Limited to small networks (RIP: 15 hops)

**Count-to-Infinity Problem** 
- **Scenario**: Router A goes down
- **Problem**: Routers gradually increase distance to A through each other
- **Solution attempts**: Split horizon, poison reverse, hold-down timers

**Real-world example**: RIP in small office networks

### 4.6.3 Link State Routing 

**Concept**
- Based on Dijkstra's shortest path algorithm (SPF)
- Each router learns complete network topology
- Builds map of entire network
- Calculates shortest path tree to all destinations

**Operation (5 Steps)** 

| Step | Description |
| :--- | :--- |
| **1. Discover neighbors** | Send HELLO packets, learn neighbor identities |
| **2. Measure line cost** | Send ECHO packets, measure delay/bandwidth |
| **3. Build Link State Packets (LSPs)** | Create packet with neighbor ID and cost, sequence number, age |
| **4. Distribute LSPs** | Flood LSPs to all routers (reliable flooding) |
| **5. Compute new routes** | Run Dijkstra algorithm on complete topology database |

**Link State Packet (LSP) Contents** 
- Router ID
- Sequence number
- Age (decremented, discard at 0)
- List of neighbors with costs

**Flooding Mechanism**
- Send LSP to all neighbors except incoming
- Duplicate detection using sequence numbers
- Aging to handle corrupted sequence numbers

**Example Protocols**
- **OSPF (Open Shortest Path First)** 
- IS-IS (Intermediate System to Intermediate System)

**Advantages** 
- Fast convergence
- Loop-free paths
- Accurate topology knowledge
- Suitable for large networks

**Disadvantages** 
- More complex
- Higher memory requirements
- Higher CPU usage (frequent SPF calculations)
- Initial flood of LSPs can cause congestion

### 4.6.4 Comparison: Distance Vector vs Link State 

| Feature | Distance Vector | Link State |
| :--- | :--- | :--- |
| **Knowledge** | Knows only neighbors' distances | Knows complete network topology |
| **Updates** | Full routing table to neighbors | Small updates (LSPs) to all routers |
| **Frequency** | Periodic (typically 30-90 seconds) | Event-driven (topology changes) |
| **Convergence** | Slow (count-to-infinity) | Fast |
| **Loops** | Possible (temporary) | Rare (SPF prevents) |
| **Algorithm** | Bellman-Ford | Dijkstra (SPF) |
| **Complexity** | Low | High |
| **Protocols** | RIP, IGRP | OSPF, IS-IS |

### 4.6.5 Dijkstra's Algorithm (Shortest Path First) 

**Purpose**: Find shortest path from source to all destinations

**Algorithm Steps**:
1. Initialize:
   - Source node cost = 0, all others = ∞
   - All nodes unmarked
2. Find unmarked node with smallest cost → mark as permanent
3. For each neighbor of marked node:
   - New cost = marked node cost + link cost
   - If new cost < current cost → update
4. Repeat from step 2 until all nodes marked permanent

**Example** :
```
Step 1: A(0) permanent → label B(2), D(5)
Step 2: B(2) permanent → label C(4), D(4) [update D from 5→4]
Step 3: C(4) permanent → label E(5)
Step 4: D(4) permanent → label E(5) [no change]
Step 5: E(5) permanent
```

### 4.6.6 Other Routing Algorithms

**A. Flooding** 
- Send packet on all outgoing links except incoming
- **Uses**: Military networks (robustness), broadcasting, discovering shortest paths
- **Control**: Sequence numbers, TTL to prevent infinite growth
- **Disadvantage**: Massive resource waste

**B. Shortest Path Routing** 
- Static algorithm using precomputed paths
- Based on physical distance, hops, or delay

**C. Flow-Based Routing**
- Considers both topology and traffic flow
- Uses queuing theory to predict delays
- Optimizes for overall network performance

---

## 4.7 Internet Control Protocols 

### 4.7.1 Address Resolution Protocol (ARP) 

**Definition**: Maps IP addresses to MAC addresses on local network

**Why Needed?**
- Data link layer needs MAC addresses for frame delivery
- Network layer uses IP addresses
- ARP bridges the gap

**ARP Operation**

| Step | Description |
| :--- | :--- |
| 1 | Host A needs MAC for IP X on same network |
| 2 | ARP request broadcast: "Who has IP X? Tell MAC_A" |
| 3 | All hosts on network receive request |
| 4 | Host with IP X responds with ARP reply (unicast): "IP X is at MAC_X" |
| 5 | Host A caches mapping (ARP cache) for future use |

**ARP Packet Format**
- Hardware type (Ethernet = 1)
- Protocol type (IP = 0x0800)
- Hardware address length (MAC = 6)
- Protocol address length (IP = 4)
- Operation (1=request, 2=reply)
- Sender MAC and IP
- Target MAC and IP

**ARP Cache**
- Stores recently resolved mappings
- Entries timeout (typically 2-20 minutes)
- Can be static (permanent)

**Proxy ARP**
- Router answers ARP requests on behalf of remote hosts
- Makes other networks appear directly connected

**Gratuitous ARP**
- Host announces its own IP-MAC mapping
- Used for duplicate address detection, updating neighbor caches

**Real-world example**: Your computer needs MAC of default gateway to send packets to internet

### 4.7.2 Reverse ARP (RARP) 

**Definition**: Maps MAC addresses to IP addresses

**Purpose**: Diskless workstations needing IP address at boot time

**Operation**
1. Station broadcasts RARP request with its MAC address
2. RARP server responds with assigned IP address

**Limitations**
- Obsoleted by BOOTP and DHCP
- Requires RARP server on each network segment

### 4.7.3 Internet Control Message Protocol (ICMP) 

**Definition**: Error reporting and diagnostic protocol for IP

**Characteristics**
- Works at network layer
- ICMP messages encapsulated in IP datagrams
- Not reliable (may be discarded)

**ICMP Message Types**

| Type | Code | Description | Use |
| :--- | :--- | :--- | :--- |
| 0 | 0 | Echo Reply | Ping reply |
| 3 | 0-15 | Destination Unreachable | Various unreachable conditions |
| 3 | 0 | Net Unreachable | No route to network |
| 3 | 1 | Host Unreachable | Destination host down |
| 3 | 3 | Port Unreachable | No process listening |
| 3 | 4 | Fragmentation Needed | DF set but needs fragmentation |
| 5 | 0-3 | Redirect | Better route exists |
| 8 | 0 | Echo Request | Ping request |
| 11 | 0 | Time Exceeded | TTL expired (traceroute) |
| 12 | 0 | Parameter Problem | Header error |

**Common ICMP Applications**

**A. Ping**
- Sends ICMP Echo Request
- Receives ICMP Echo Reply
- Tests reachability and RTT

**B. Traceroute**
- Sends packets with increasing TTL (1,2,3...)
- Each router returns ICMP Time Exceeded
- Maps path to destination

**C. Path MTU Discovery**
- Sends packet with DF=1
- If too large, router returns "Fragmentation Needed"
- Source reduces packet size

---

## 4.8 Routing Protocols: OSPF, BGP, Unicast, Multicast and Broadcast

### 4.8.1 Routing Protocol Classification

| Classification | Types | Description |
| :--- | :--- | :--- |
| **By Scope** | IGP vs EGP | Interior vs Exterior Gateway Protocols |
| **By Algorithm** | Distance Vector vs Link State | Update mechanism |
| **By Operation** | Unicast vs Multicast | Destination type |

### 4.8.2 Interior Gateway Protocols (IGPs)

#### A. OSPF (Open Shortest Path First) 

**Overview**
- Link state IGP
- Standard: RFC 2328 (OSPFv2 for IPv4), RFC 5340 (OSPFv3 for IPv6)
- Uses Dijkstra's SPF algorithm
- Classless (supports VLSM/CIDR)

**Key Features**
- **Fast convergence**: Immediate updates on topology change
- **Hierarchical routing**: Areas reduce routing table size and LSA flooding
- **Authentication**: MD5, SHA for secure updates
- **Load balancing**: Multiple equal-cost paths
- **Cost metric**: Based on bandwidth (default = 10⁸/bandwidth in bps)

**OSPF Hierarchy**

| Component | Description |
| :--- | :--- |
| **Backbone Area (Area 0)** | Core area connecting all other areas |
| **Regular Areas** | Connected to Area 0 |
| **ABR (Area Border Router)** | Connects areas to backbone |
| **ASBR (AS Boundary Router)** | Connects OSPF to other AS |

**OSPF Packet Types**

| Type | Name | Purpose |
| :--- | :--- | :--- |
| 1 | Hello | Discover/maintain neighbors |
| 2 | Database Description | Exchange summary of LSDB |
| 3 | Link State Request | Request specific LSAs |
| 4 | Link State Update | Send LSAs |
| 5 | Link State Ack | Acknowledge LSAs |

**OSPF Multicast Addresses** 
- **224.0.0.5**: All SPF routers (Hello messages)
- **224.0.0.6**: All Designated Routers

**Advantages**
- Fast convergence
- Loop-free
- Scalable (hierarchical)
- Classless

**Disadvantages**
- Complex configuration
- High CPU/memory requirements
- More overhead than distance vector

**Real-world example**: Enterprise networks, campus networks, ISP internal routing

#### B. RIP (Routing Information Protocol)
- Distance vector IGP
- Metric: Hop count (max 15)
- Updates every 30 seconds
- Uses multicast 224.0.0.9 
- Limited to small networks

### 4.8.3 Exterior Gateway Protocols (EGPs)

#### BGP (Border Gateway Protocol) 

**Overview**
- Path vector protocol (distance vector variant)
- Current version: BGP-4 (RFC 4271)
- Connects different Autonomous Systems (AS)
- Used between ISPs and large organizations

**Key Concepts**

| Term | Description |
| :--- | :--- |
| **Autonomous System (AS)** | Network under single administrative control |
| **AS Number (ASN)** | Unique 16-bit or 32-bit identifier |
| **eBGP** | External BGP between different ASes |
| **iBGP** | Internal BGP within same AS |
| **CIDR** | Supports route aggregation |

**BGP Attributes**

| Attribute | Category | Description |
| :--- | :--- | :--- |
| **AS_PATH** | Well-known mandatory | List of ASes traversed (loop prevention) |
| **NEXT_HOP** | Well-known mandatory | Next router IP |
| **LOCAL_PREF** | Well-known discretionary | Higher preference within AS |
| **MED** | Optional non-transitive | Lower metric preferred |
| **COMMUNITY** | Optional transitive | Tagging for policy |

**BGP Operation** 
- TCP port 179 (reliable transport)
- Incremental updates (not full table periodically)
- Path selection based on policies, not just metrics
- No multicast—uses unicast TCP sessions

**BGP Decision Process (simplified)** :
1. Highest LOCAL_PREF
2. Shortest AS_PATH
3. Lowest ORIGIN type (IGP < EGP < incomplete)
4. Lowest MED
5. Prefer eBGP over iBGP
6. Lowest IGP cost to NEXT_HOP

**Advantages**
- Scalable to Internet size
- Policy-based routing
- Loop-free (AS_PATH)
- Stable

**Disadvantages**
- Slow convergence
- Complex configuration
- Large routing tables
- Policy complexity

**Real-world example**: Internet backbone routing between ISPs

### 4.8.4 Comparison: OSPF vs BGP

| Feature | OSPF | BGP |
| :--- | :--- | :--- |
| **Type** | IGP (Interior) | EGP (Exterior) |
| **Scope** | Within AS | Between ASes |
| **Algorithm** | Link State | Path Vector |
| **Metric** | Cost (bandwidth-based) | Path attributes, policies |
| **Convergence** | Fast | Slow |
| **Scalability** | Good (with areas) | Excellent |
| **Transport** | IP (protocol 89) | TCP (port 179) |
| **Updates** | Flooded LSAs | Incremental |
| **Loop prevention** | SPF algorithm | AS_PATH attribute |

### 4.8.5 Unicast, Multicast, and Broadcast 

#### A. Unicast
**Definition**: One-to-one communication
- Single source sends to single destination
- Most common type (web browsing, email, FTP)
- **Example**: Accessing a website

#### B. Multicast
**Definition**: One-to-many communication to specific group
- Source sends once, network replicates to interested receivers
- More efficient than multiple unicasts
- **Multicast addresses**: Class D in IPv4 (224.0.0.0/4), FF00::/8 in IPv6
- **Protocols**:
  - **IGMP** (Internet Group Management Protocol): Hosts join/leave multicast groups
  - **PIM** (Protocol Independent Multicast): Routing for multicast 
  - PIM multicast address: 224.0.0.13 
- **Real-world examples**: IPTV, video conferencing, software updates

#### C. Broadcast
**Definition**: One-to-all communication
- Packet sent to all devices on network
- IPv4 broadcast: 255.255.255.255 (limited) or network-specific
- **IPv6**: No broadcast—replaced with multicast
- **Real-world examples**: ARP requests, DHCP discovery
- **Problems**: Broadcast storms, wasted bandwidth

#### D. Anycast 
**Definition**: One-to-nearest (among group)
- Multiple devices share same address
- Packets routed to closest (topologically)
- **Real-world examples**: DNS root servers, CDN (Cloudflare 1.1.1.1)

### 4.8.6 Summary: Routing Protocols Comparison

| Protocol | Type | Algorithm | Metric | Scope | Convergence |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **RIP** | IGP | Distance Vector | Hops (max 15) | Small networks | Slow |
| **OSPF** | IGP | Link State | Cost (bandwidth) | Enterprise | Fast |
| **IS-IS** | IGP | Link State | Cost | Large networks | Fast |
| **EIGRP** | IGP | Advanced Distance Vector | Composite (bandwidth, delay) | Cisco networks | Fast |
| **BGP** | EGP | Path Vector | Path attributes | Internet | Slow |
