# **Unit 8: Wide Area Networks (WANs)**

## **1. Introduction to WANs**

A Wide Area Network (WAN) is a telecommunications network that extends over a large geographical area, connecting multiple Local Area Networks (LANs) or Metropolitan Area Networks (MANs). WANs enable organizations to establish communication between geographically dispersed locations.

### **Key Characteristics**
- **Geographical Coverage:** Spans cities, countries, or global connections
- **Ownership:** Typically uses third-party service providers (ISPs, telecom companies)
- **Speed:** Generally slower than LANs (ranging from 1Mbps to 100Gbps)
- **Latency(time taken for to and fro):** Higher than LANs due to longer distances and multiple hops
- **Cost:** More expensive than LANs due to leased infrastructure

### **Components of WANs**
1. **Routers:** Connect LANs to the WAN and route traffic between networks
2. **WAN Switches:** Operate in service provider networks to handle traffic switching
3. **Modems:** Interface between digital networks and analog lines
4. **Communication Links:** Physical or wireless connections between sites

---

## **2. Dedicated-Circuit Networks** 

### **a. Basic Architecture of Dedicated-Circuit Networks**  

A **dedicated-circuit network** provides a permanent, point-to-point connection between two locations with guaranteed bandwidth.  

### **Key Components**  
| **Component**       | **Function** | **Example** |  
|---------------------|-------------|------------|  
| **Local Loop** | Connects customer premises to service provider | Copper/fiber line |  
| **CSU(Channel Service Unit)/DSU(Data Service Unit)** | Converts digital signals between LAN and WAN | T1(T-carrier Level 1) CSU/DSU |  
| **Router** | Routes traffic between LAN and WAN | Cisco ISR |  
| **Demarcation Point** | Boundary between customer and provider equipment | Smart jack |  

| **Old Setup**   | **Modern Home Setup**    |
| --------------- | ------------------------ |
| T1 Line         | Fiber / Cable / DSL / 5G |
| CSU/DSU         | ONT / Modem              |
| Expensive, slow | Fast, affordable         |


### **b. T(Trunk)-Carrier Services**  

### **i. T1(T-carrier Level 1) Line**  
- **Speed:** 1.544 Mbps  
- **Channels:** 24 DS0(Digital Signal 0) channels (64 Kbps each)  
- **Use Case:** Small business voice/data  

### **ii. T3 Line**  
- **Speed:** 44.736 Mbps (28 T1 lines)  
- **Use Case:** Enterprise backbone  

### **Comparison: T1 vs T3**  
| **Feature** | **T1** | **T3** |  
|------------|--------|--------|  
| Speed | 1.544 Mbps | 44.736 Mbps |  
| Cost | Low | High |  
| Channels | 24 DS0 | 672 DS0 |  
| Typical Use | SMBs(Small and Medium-sized Businesses) | ISPs/Enterprises |  

**Advantages:**  
✔ Guaranteed bandwidth  
✔ Low latency  

**Disadvantages:**  
✖ Expensive  
✖ Inflexible (fixed capacity)  


### **c. SONET/SDH Services**  

### **i. SONET-Synchronous Optical Network (North America)**  
- **Base Rate:** Optical Carrier(OC)-1 (51.84 Mbps)  
- **Common Levels:**  
  - OC-3: 155.52 Mbps  
  - OC-12: 622.08 Mbps  
  - OC-192: 9.953 Gbps  

### **ii. SDH-Synchronous Digital Hierarchy (International)**  
- **Base Rate:** STM-1 (155.52 Mbps)  

### **Key Features**  
✔ **Self-healing rings** (Automatic failover in 50ms)  
✔ **Multiplexing:** Combines multiple T1/E1 circuits  
✔ **Synchronization:** Precise timing for voice/video  

**Use Cases:**  
- ISP backbones  
- Cellular backhaul (Backhaul is the network connection that links cell towers (or base stations) to the core network, carrying users’ voice and data traffic from the edge of the network to the main infrastructure.) 

---

## **3. Packet-Switched Networks**  

### **a. Basic Architecture of Packet-Switched Networks**  

Packet-switched networks **break data into packets** that travel independently across shared network infrastructure before being reassembled at the destination.  

### **Key Components**  
| **Component**       | **Function** |  
|---------------------|-------------|  
| **Packets** | Data units with headers (source/destination info) |  
| **Switches/Routers** | Forward packets along optimal paths |  
| **Virtual Circuits** | Logical paths (permanent/switched) |  
| **Control Protocols** | Manage traffic flow and error handling |  


### **b. Frame Relay Services**  

### **i. Core Features**  
- **Speed:** 56 Kbps – 45 Mbps  
- **PVCs (Permanent Virtual Circuits):** Predefined paths  
- **DLCI (Data Link Connection Identifier):** Addresses virtual circuits  

### **ii. Frame Format**  
| **Field** | **Size** | **Purpose** |  
|-----------|---------|------------|  
| Flag | 1 byte | Start/end delimiter |  
| DLCI | 2 bytes | Virtual circuit ID |  
| Data | Variable | Payload (up to 4096 bytes) |  
| FCS | 2 bytes | Error checking |  

**Advantages:**  
✔ Cost-effective (shared infrastructure)  
✔ Low overhead  

**Disadvantages:**  
✖ No QoS guarantees  
✖ Being phased out (legacy tech)   


### **c. IP Services**  

### **i. Characteristics**  
- **Connectionless:** No predefined path  
- **Best-effort delivery:** No guarantees  
- **Fragmentation:** Supports MTU differences  

### **ii. Packet Structure**  
| **Header Field** | **Function** |  
|------------------|-------------|  
| Version | IPv4/IPv6 |  
| TTL | Prevents infinite loops |  
| Protocol | TCP/UDP/ICMP |  
| Checksum | Error detection |  

**Use Cases:**  
- Internet connectivity  
- Enterprise WANs (IPsec VPNs)  


### **d. Ethernet Services**  

### **i. Carrier Ethernet Types**  
| **Service** | **Description** | **Speed** |  
|------------|----------------|----------|  
| (Ethernet)E-Line | Point-to-point (VLAN-based) | 1Mbps-10Gbps |  
| (Ethernet)E-LAN | Multipoint-to-multipoint | 1Mbps-10Gbps |  

### **ii. Key Protocols**  
- **802.1Q:** VLAN tagging  
- **Q-in-Q:** Nested VLANs for carriers  (vlan stacking)

**Advantages:**  
✔ Scalable bandwidth  
✔ Native LAN/WAN integration  


### **e. Comparison Table**  
| **Feature** | **Frame Relay** | **IP** | **Carrier Ethernet** |  
|------------|---------------|--------|---------------------|  
| **Connection** | PVC-based | Connectionless | VLAN-based |  
| **Speed** | ≤45Mbps | Unlimited | 1Mbps-100Gbps |  
| **QoS** | Limited | DiffServ/ToS | Priority tagging |  
| **Cost** | Low | Very low | Moderate |  

---


## **4. Virtual Private Networks (VPNs)**  


### **a. Basic VPN Architecture**  

A **Virtual Private Network (VPN)** creates a secure, encrypted tunnel over a public network (Internet) to connect remote users/sites as if they were on a private network.  

### **Core Components**  
| **Component**       | **Function** |  
|---------------------|-------------|  
| **VPN Client** | Initiates secure connection (e.g., laptop, smartphone) |  
| **VPN Server/Gateway** | Authenticates users and encrypts/decrypts traffic |  
| **Tunneling Protocol** | Encapsulates data packets (e.g., IPsec, OpenVPN) |  
| **Encryption Algorithm** | Secures data (e.g., AES-256) |  


### **b. VPN Types**  

### **i. By Use Case**  
| **Type**             | **Description** | **Example** |  
|----------------------|----------------|------------|  
| **Remote Access VPN** | Connects individual users to a private network | An employee working from home accessing company resources. |  
| **Site-to-Site VPN**  | Links entire networks (e.g., branch offices) | Banks linking their branch offices using an MPLS(Multiprotocol Label Switching) VPN. |  
| **SSL VPN**           | Web-based access via browser | Accessing a cloud application portal securely through a browser. |  

### **ii. By Technology**  
| **Type**       | **Protocols** | **Key Feature** |  
|---------------|--------------|----------------|  
| **IPsec VPN** | IKEv2, ESP, AH | Network-layer security |  
| **SSL/TLS VPN** | HTTPS, OpenVPN | Application-layer security |  
| **WireGuard** | UDP-based | Lightweight, high-speed |  


### **c. How VPNs Work**  

### **Step-by-Step Process**  
i. **Authentication**  
   - User/device verifies identity via:  
     - Username/password  
     - Certificates  
     - 2FA (e.g., OTP)  

ii. **Tunnel Establishment**  
   - Negotiates encryption parameters (IKE Phase 1/2 for IPsec)  
   - Creates secure tunnel using:  
     - **Encapsulation** (e.g., IPsec’s ESP)  
     - **Encryption** (e.g., AES-256)  

iii. **Data Transmission**  
   - Outbound traffic: Encrypted at client → sent through tunnel → decrypted at server  
   - Inbound traffic: Reverse process  

iv. **Termination**  
   - Session ends after timeout or manual disconnect  


---

## **5. Best Practice WAN Design & Performance Optimization** 

### **a. Best Practice WAN Design Principles**  

### **i. Hierarchical Architecture**  
| **Layer**         | **Function**                          | **Devices**               | **Design Considerations**        |
|-------------------|---------------------------------------|---------------------------|----------------------------------|
| **Core Layer**    | High-speed backbone transit           | Carrier-grade routers      | Redundant 100G+ links, <5ms latency |
| **Aggregation**   | Traffic consolidation(combining multiple smaller data streams into one larger stream for easier handling.)                 | MPLS switches             | Route summarization, QoS policies |
| **Edge Layer**    | Customer premises termination         | SD-WAN(Software-Defined Wide Area Network) appliances         | Dual ISP connections(Two internet providers for backup and load sharing), VPN failover(Automatic switch between VPN tunnels for continuous security and connectivity) |

**Key Features:**  
✔ **Modularity**: Independent scalability of layers  
✔ **Resilience**: Diverse physical paths (avoid single points of failure)  
✔ **Security**: Unified threat management at all layers   


### **b. Improving WAN Performance**  

### **i. Device Performance Optimization**  
| **Strategy**             | **Implementation**                          | **Performance Impact**     |
|--------------------------|---------------------------------------------|---------------------------|
| **ASIC(Application-Specific Integrated Circuit)-Based Forwarding** | offload tasks like encryption or packet forwarding from the CPU to hardware  | ↑ 400% throughput |
| **Control Plane Policing** | Rate-limit management traffic              | Protects the router/switch’s brain (CPU) from being starved, ensuring stability   |
| **TCAM(Ternary Content Addressable Memory) Optimization**    | Compact routing tables                      | Faster routing decisions and efficient hardware usage            |


### **ii. Circuit Capacity Enhancement**  
| **Technology**       | **Deployment Example**               | **Bandwidth Gain** |  
|----------------------|--------------------------------------|--------------------|  
| **Link Aggregation** | 4x10Gbps LACP(Link Aggregation Control Protocol) bundle                 | 40Gbps logical link |  
| **Circuit Bonding**  | Merging two or more physical circuits (e.g., DSL lines) to act as one     | 2x throughput      |  
| **QoS Hierarchies-priority**  | Voice (EF-Expedited Forwarding) > Video (AF-Assured Forwarding) > Best Effort(web browsing) | 80% latency reduction |


### **iii. Network Demand Reduction**  
| **Technique**          | **Mechanism**                          | **Traffic Reduction** |  
|------------------------|----------------------------------------|-----------------------|  
| **WAN Optimization**   | LZ77 compression(lossless data compression algorithm) + deduplication       | 50-70%                |  
| **CDN(Content Delivery Network) Integration**    | Cache static content(images, CSS, JS) at edge servers closer to users    | 60% WAN traffic offload |  
| **Protocol Acceleration** | SMB(Server Message Block) 3.1.1 multiplexing (share files,printers)            | 3x faster file transfers |  


---

