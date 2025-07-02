# **Unit 6: Wired and Wireless Local Area Networks**  
**Detailed Exam-Oriented Notes**  

## **1. Introduction to LANs**  
A **Local Area Network (LAN)** is a network that connects devices within a limited geographical area such as a home, office, or campus. LANs enable resource sharing (files, printers, internet) and communication among connected devices.  

### **Key Characteristics of LANs:**  
✔ **High data transfer rates** (10 Mbps to 100 Gbps)  
✔ **Limited geographical coverage** (typically within a single building)  
✔ **Privately owned and managed**  
✔ **Uses wired (Ethernet) or wireless (Wi-Fi) technologies**  

*(Insert Diagram: Typical LAN Setup with Wired and Wireless Connections)*  

---  

## **2. LAN Components**  

### **A. Network Interface Cards (NICs)**  
- Hardware that connects a device to a network.  
- **Types:**  
  - **Wired NIC** (Ethernet port)  
  - **Wireless NIC** (Wi-Fi adapter)  

#### **Functions:**  
✔ Converts data into electrical signals (for wired) or radio waves (for wireless)  
✔ Provides a unique **MAC address** (e.g., `00:1A:2B:3C:4D:5E`)  

#### **Example:**  
- A **desktop computer’s Ethernet port** (wired NIC) or a **laptop’s Wi-Fi card** (wireless NIC).  

#### **Advantages:**  
✔ Enables network connectivity  
✔ Supports high-speed data transfer  

#### **Disadvantages:**  
✖ Requires proper drivers to function  
✖ Wireless NICs may suffer from interference  

---  

### **B. Network Circuits (Cabling & Wireless Media)**  
- **Wired LANs:**  
  - **Twisted Pair (Cat 5e/6/7)** → Most common (RJ-45 connectors)  
  - **Fiber Optic** → High-speed, long-distance (uses light signals)  

- **Wireless LANs (WLANs):**  
  - **Wi-Fi (IEEE 802.11 standards)** → 2.4 GHz / 5 GHz / 6 GHz bands  

#### **Comparison: Wired vs Wireless LANs**  
| **Feature**       | **Wired LAN** | **Wireless LAN** |  
|-------------------|--------------|----------------|  
| **Speed**         | Up to 10 Gbps+ | Up to 9.6 Gbps (Wi-Fi 6E) |  
| **Reliability**   | High (no interference) | Moderate (signal interference) |  
| **Mobility**      | Limited (fixed cables) | High (no cables) |  
| **Security**      | More secure (physical access needed) | Less secure (requires encryption) |  

*(Insert Diagram: Ethernet Cable vs Wi-Fi Signal Transmission)*  

---  

### **C. Network Hubs, Switches, and Access Points**  

#### **(i) Hub (Obsolete in Modern LANs)**  
- **Broadcasts data to all connected devices** (no intelligence).  
- **Disadvantage:** Causes **network congestion** (collision domain issues).  

#### **(ii) Switch (Intelligent Hub)**  
- **Forwards data only to the intended device** (uses MAC addresses).  
- **Advantages:**  
  ✔ Reduces collisions (each port is a separate collision domain)  
  ✔ Supports **full-duplex communication**  

#### **(iii) Wireless Access Point (WAP)**  
- Allows **Wi-Fi devices** to connect to a wired network.  
- **Example:** A **router’s Wi-Fi** acts as an access point.  

*(Insert Diagram: Hub vs Switch vs Access Point in a LAN)*  

---  

### **D. Network Operating Systems (NOS)**  
- Software that manages network resources (users, security, file sharing).  
- **Examples:**  
  - **Windows Server** (Active Directory, DHCP, DNS)  
  - **Linux (Ubuntu Server, CentOS)**  

#### **Functions of NOS:**  
✔ **User authentication** (login security)  
✔ **File & printer sharing**  
✔ **Network traffic management**  

---  

## **3. Summary Table: LAN Components**  

| **Component**       | **Function** | **Example** |  
|---------------------|-------------|------------|  
| **NIC** | Connects device to network | Ethernet port, Wi-Fi card |  
| **Network Circuits** | Transmits data | Cat 6 cable, Wi-Fi 6 |  
| **Hub** | Broadcasts data (dumb device) | Old 10 Mbps hubs |  
| **Switch** | Forwards data intelligently | Gigabit Ethernet switch |  
| **Access Point** | Provides Wi-Fi connectivity | Wireless router |  
| **NOS** | Manages network resources | Windows Server, Linux |  

---  

## **4. Exam-Oriented Questions**  

**Q1. What is the difference between a hub and a switch?**  
- **Hub:** Broadcasts data to all devices (inefficient).  
- **Switch:** Forwards data only to the target device (uses MAC addresses).  

**Q2. Why is a switch better than a hub?**  
- **Switches reduce collisions**, improve speed, and support full-duplex communication.  

**Q3. What are the advantages of wired LANs over wireless LANs?**  
- **Higher speed, lower latency, better security, no interference.**  

**Q4. What is the role of a Network OS?**  
- To **manage users, security, and shared resources** (files, printers) in a network.  

---  

## **5. Diagrams to Study**  
1. **LAN Topology (Star, Bus, Ring)**  
2. **Hub vs Switch vs Router**  
3. **Ethernet Cable Types (Cat 5e/6/7, Fiber Optic)**  
4. **Wi-Fi Standards (802.11ac, ax, be)**  

*(Refer to **Tanenbaum’s "Computer Networks"** or **Cisco CCNA materials** for diagrams.)*  

**End of Notes** 🚀

# **Unit 6: Wired and Wireless Ethernet**  
**Detailed Exam-Oriented Notes**  

## **1. Wired Ethernet**  

### **A. Ethernet Topologies**  
Ethernet networks use different physical layouts:  

1. **Star Topology (Most Common)**  
   - All devices connect to a central switch  
   - *Advantages*:  
     ✔ Easy troubleshooting  
     ✔ Single device failure doesn't affect others  
   - *Disadvantages*:  
     ✖ Switch becomes single point of failure  

2. **Bus Topology (Legacy)**  
   - All devices share a single backbone cable  
   - *Advantages*:  
     ✔ Simple cabling  
   - *Disadvantages*:  
     ✖ Prone to collisions  
     ✖ Entire network fails if cable breaks  

*(Insert Diagram: Comparison of Star vs Bus Topologies)*  

### **B. Media Access Control (MAC) - CSMA/CD**  
- **Carrier Sense Multiple Access with Collision Detection**  
- How it works:  
  1. Device checks if line is free before transmitting  
  2. If collision occurs, waits random time before retrying  
- *Modern Ethernet*:  
  - Full-duplex switches made CSMA/CD obsolete  
  - Still important for historical understanding  

*(Insert Diagram: CSMA/CD Process Flowchart)*  

### **C. Types of Ethernet**  

| **Standard** | **Speed** | **Cable Type** | **Max Distance** |  
|-------------|----------|----------------|------------------|  
| 10BASE-T    | 10 Mbps  | Cat 3+ UTP     | 100m             |  
| 100BASE-TX  | 100 Mbps | Cat 5 UTP      | 100m             |  
| 1000BASE-T  | 1 Gbps   | Cat 5e/6       | 100m             |  
| 10GBASE-T   | 10 Gbps  | Cat 6a/7       | 100m             |  

*Key Evolution*:  
- From coaxial cables (10BASE5) to modern fiber optics  
- Speed increased from 10Mbps to 100Gbps+  

---

## **2. Wireless Ethernet (Wi-Fi)**  

### **A. Wireless Topologies**  

1. **Infrastructure Mode**  
   - Devices connect through an Access Point (AP)  
   - Used in homes/offices  

2. **Ad-Hoc Mode**  
   - Devices connect directly without AP  
   - Limited to small temporary networks  

*(Insert Diagram: Infrastructure vs Ad-Hoc Networks)*  

### **B. Media Access Control - CSMA/CA**  
- **Carrier Sense Multiple Access with Collision Avoidance**  
- Key differences from wired:  
  ✔ Uses RTS/CTS (Request-to-Send/Clear-to-Send)  
  ✔ Implements NAV (Network Allocation Vector)  
  ✔ Includes acknowledgment frames  

*(Insert Diagram: CSMA/CA Handshake Process)*  

### **C. Wireless Frame Layout**  

| **Field**         | **Size (bytes)** | **Purpose**                |  
|-------------------|------------------|----------------------------|  
| Frame Control     | 2                | Contains protocol info     |  
| Duration/ID       | 2                | How long transmission will take |  
| Address 1-4       | 6 each           | Source/destination addresses |  
| Sequence Control  | 2                | Packet ordering           |  
| Frame Body        | 0-2304           | Actual data payload       |  
| FCS               | 4                | Error checking            |  

### **D. Types of Wireless Ethernet**  

| **Standard** | **Max Speed** | **Frequency** | **Year** |  
|-------------|--------------|---------------|----------|  
| 802.11a     | 54 Mbps      | 5 GHz         | 1999     |  
| 802.11g     | 54 Mbps      | 2.4 GHz       | 2003     |  
| 802.11n     | 600 Mbps     | 2.4/5 GHz     | 2009     |  
| 802.11ac    | 6.9 Gbps     | 5 GHz         | 2013     |  
| 802.11ax    | 9.6 Gbps     | 2.4/5/6 GHz   | 2019     |  

### **E. Wireless Security**  

1. **WEP (Weak)**  
   - 64/128-bit encryption  
   - Easily crackable  

2. **WPA**  
   - TKIP encryption  
   - Better than WEP but still vulnerable  

3. **WPA2 (Recommended)**  
   - AES-CCMP encryption  
   - Enterprise mode with RADIUS  

4. **WPA3 (Latest)**  
   - 192-bit encryption  
   - Protects against brute-force attacks  

*(Insert Table: Comparison of Wireless Security Protocols)*  

---

## **3. Comparison: Wired vs Wireless Ethernet**  

| **Feature**       | **Wired Ethernet** | **Wireless Ethernet** |  
|-------------------|--------------------|-----------------------|  
| Speed             | Up to 100Gbps      | Up to 9.6Gbps         |  
| Reliability       | Very high          | Subject to interference |  
| Mobility          | Limited            | Excellent             |  
| Security          | Physically secure  | Requires encryption   |  
| Installation Cost | Higher             | Lower                 |  

---

## **4. Exam Focus Points**  

✔ Know the difference between CSMA/CD and CSMA/CA  
✔ Memorize Ethernet and Wi-Fi standards with speeds  
✔ Understand wireless frame structure  
✔ Be able to compare wired vs wireless advantages  
✔ Know evolution of wireless security protocols  

**Practice Question:**  
*"A company wants to set up a new office network. Compare the advantages of using wired Ethernet versus wireless Ethernet, considering factors like speed, reliability, and security."*  

*(End of Notes)* 🚀

# **Best Practice LAN Design**  
**Comprehensive Exam-Oriented Guide**  

## **1. Designing User Access with Wired Ethernet**  

### **Key Considerations**  
✔ **Cable Selection**:  
   - **Cat 6/6a** for 1Gbps/10Gbps (100m max)  
   - **Fiber** for long-distance (>100m) or high-EMI areas  

✔ **Switch Selection**:  
   - **Access Layer**: 24/48-port Gigabit switches  
   - **PoE Support** for IP phones/cameras  

✔ **Topology**:  
   - **Star topology** with hierarchical design  
   - **Link aggregation** (LACP) for uplinks  

*(Insert Diagram: Enterprise Wired Access Design)*  

**Best Practices**:  
- Maintain **30% spare ports** for expansion  
- Implement **VLANs** for traffic segmentation  
- Use **802.1X** for port-based authentication  

---

## **2. Designing User Access with Wireless Ethernet**  

### **Key Considerations**  
✔ **Coverage Planning**:  
   - **AP Density**: 1 AP per 1,500 sq.ft (office) / 500 sq.ft (high-density)  
   - **Channel Planning**: Non-overlapping channels (1,6,11 for 2.4GHz)  

✔ **AP Placement**:  
   - **Ceiling-mounted** for optimal coverage  
   - **Avoid** metal obstructions and microwave ovens  

✔ **Controller-Based vs Cloud-Managed**:  
   - **Controller-based**: Cisco WLC, Aruba Mobility Controller  
   - **Cloud-managed**: Meraki, Ubiquiti UniFi  

*(Insert Diagram: Wireless Heat Map for Coverage Planning)*  

**Best Practices**:  
- Implement **WPA3-Enterprise** with RADIUS  
- Enable **Band Steering** to 5GHz  
- Set **Minimum RSSI** to -70dBm for roaming  

---

## **3. Designing the Data Center**  

### **Core Components**  
✔ **Leaf-Spine Architecture**:  
   - **Spine switches**: High-speed 40/100Gbps backbone  
   - **Leaf switches**: Connect servers to spine  

✔ **Server Connectivity**:  
   - **NIC Teaming** for redundancy  
   - **10/25/40Gbps** server connections  

✔ **Storage Networking**:  
   - **iSCSI/NVMe over Fabrics**  
   - **Separate storage VLANs**  

*(Insert Diagram: Modern Leaf-Spine Data Center Design)*  

**Best Practices**:  
- Implement **VXLAN** for network virtualization  
- Use **ECMP** for load balancing  
- Deploy **TOR (Top-of-Rack)** switching  

---

## **4. Designing the e-Commerce Edge**  

### **Critical Elements**  
✔ **DMZ Design**:  
   - **Web/App/DB tiers** in separate security zones  
   - **Reverse proxies** (NGINX, F5)  

✔ **Load Balancing**:  
   - **Round Robin/Least Connections** algorithms  
   - **SSL Offloading** at load balancers  

✔ **Security Measures**:  
   - **WAF** (Web Application Firewall)  
   - **DDoS Protection** (Cloudflare, AWS Shield)  

*(Insert Diagram: 3-Tier e-Commerce Architecture)*  

**Best Practices**:  
- Implement **Auto-scaling** for web tier  
- Use **CDN** for static content  
- **Regular PCI-DSS compliance audits**  

---

## **5. Designing the SOHO Environment**  

### **Key Components**  
✔ **All-in-One Devices**:  
   - **Wireless routers** with 4-port switch  
   - **Basic firewall** capabilities  

✔ **Wireless Considerations**:  
   - **Single AP** typically sufficient  
   - **WPA3-Personal** for security  

✔ **Remote Access**:  
   - **VPN** for secure remote work  
   - **Dynamic DNS** for small servers  

*(Insert Diagram: Typical SOHO Network Setup)*  

**Best Practices**:  
- Enable **Guest Network** isolation  
- Schedule **automatic reboots** for stability  
- Implement **QoS** for VoIP prioritization  

---

## **6. Comparison Tables**  

### **Wired vs Wireless Access Design**  
| **Factor**       | **Wired**               | **Wireless**             |  
|------------------|-------------------------|--------------------------|  
| Speed            | 1Gbps-100Gbps          | 150Mbps-9.6Gbps         |  
| Latency          | <1ms                   | 5-20ms                  |  
| Security         | Physical port security | Encryption required      |  
| Mobility         | None                   | Full mobility            |  

### **Data Center vs SOHO Design**  
| **Aspect**       | **Data Center**         | **SOHO**                |  
|------------------|-------------------------|-------------------------|  
| Switching        | Leaf-Spine 100Gbps      | 4-port 1Gbps switch     |  
| Security         | Advanced segmentation   | Basic firewall          |  
| Redundancy       | Dual power, N+1 cooling | Single power supply     |  
| Management       | Enterprise NMS          | Web GUI                 |  

---

## **7. Exam Focus Points**  

✔ Understand **hierarchical network design principles**  
✔ Know **wireless site survey fundamentals**  
✔ Memorize **data center leaf-spine advantages**  
✔ Be able to **compare different deployment scenarios**  

**Practice Question**:  
*"A university needs to design wireless coverage for a new library building. Describe the key considerations for AP placement, channel planning, and security measures you would recommend."*  

*(End of Notes)* 🚀

# **Improving LAN Performance**  
**Comprehensive Optimization Strategies**  

## **1. Improving Server Performance**  

### **A. Hardware Optimization**  
✔ **SSD Storage**:  
   - Replace HDDs with NVMe SSDs (5-100x faster I/O)  
   - Example: Database server response time drops from 50ms → 2ms  

✔ **RAM Expansion**:  
   - Minimum 16GB for file servers, 32GB+ for virtualization  
   - Reduces disk swapping (page file usage)  

✔ **NIC Configuration**:  
   - **Teaming/LACP**: Combine multiple 1Gbps ports → 2Gbps+  
   - **10Gbps/25Gbps NICs** for high-demand servers  

*(Insert Diagram: Server NIC Teaming Configuration)*  

### **B. Software Optimization**  
✔ **Load Balancing**:  
   - Distribute requests across multiple servers  
   - Algorithms: Round Robin, Least Connections  

✔ **Caching**:  
   - **RAM Caching**: Redis/Memcached for databases  
   - **Web Caching**: Varnish for HTTP acceleration  

**Impact**:  
- Web server throughput ↑ 300% with proper caching  
- Database queries 10x faster with RAM caching  

---

## **2. Improving Circuit Capacity**  

### **A. Bandwidth Upgrades**  
| **Current Tech** | **Upgrade Path** | **Speed Gain** |  
|------------------|------------------|----------------|  
| Fast Ethernet (100Mbps) | Gigabit Ethernet | 10x |  
| 1Gbps Copper | 10Gbps Fiber | 10x |  
| 802.11n Wi-Fi | 802.11ax Wi-Fi 6 | 4x |  

### **B. Traffic Shaping**  
✔ **QoS Policies**:  
   - VoIP/DSCP EF (Expedited Forwarding): Latency <150ms  
   - Video/AF41: Minimum 4Mbps guaranteed  
   - Best Effort: Web browsing  

✔ **Example**:  
```network
Priority 1: Voice (DSCP 46) → 20% bandwidth guarantee  
Priority 2: Video (DSCP 34) → 30% bandwidth  
Priority 3: All other traffic → Remaining 50%  
```

*(Insert Diagram: QoS Traffic Prioritization Schema)*  

### **C. Protocol Optimization**  
✔ **Jumbo Frames**:  
   - Increase MTU from 1500 → 9000 bytes  
   - Requires end-to-end support (30% throughput boost)  

✔ **TCP Window Scaling**:  
   - Allows larger data bursts (critical for high-latency links)  

---

## **3. Reducing Network Demand**  

### **A. Data Compression**  
| **Type**       | **Technology** | **Reduction** |  
|----------------|----------------|---------------|  
| File Transfer | ZIP/7z | 50-90% |  
| Web Content | GZIP/Brotli | 60-80% |  
| Video | H.265 vs H.264 | 50% smaller |  

### **B. Application Optimization**  
✔ **HTTP/2**:  
   - Multiplexing: 6 parallel requests → 1 TCP connection  
   - Header compression (HPACK)  

✔ **Database Optimization**:  
   - Query caching (MySQL query_cache_size)  
   - Index optimization  

### **C. Traffic Filtering**  
✔ **Block Unnecessary Protocols**:  
   - Disable NetBIOS over TCP/IP if not needed  
   - Rate-limit P2P traffic  

✔ **Content Delivery Networks (CDNs)**:  
   - Offload 60-80% of web traffic  
   - Example: Loading time drops from 4s → 1.2s  

---

## **4. Performance Comparison**  

### **Before vs After Optimization**  
| **Metric**       | **Before** | **After** | **Improvement** |  
|------------------|-----------|-----------|-----------------|  
| File Transfer (1GB) | 3 mins | 45 secs | 4x faster |  
| Database Query | 1200ms | 150ms | 8x faster |  
| VoIP Jitter | 25ms | 8ms | 68% reduction |  
| Web Page Load | 4.2s | 1.5s | 64% faster |  

---

## **5. Implementation Checklist**  

**Server Improvements**:  
☑ SSD upgrade  
☑ RAM expansion  
☑ NIC teaming  

**Circuit Upgrades**:  
☑ 1Gbps → 10Gbps core links  
☑ QoS policy implementation  
☑ Jumbo frames enablement  

**Demand Reduction**:  
☑ Enable GZIP compression  
☑ Deploy HTTP/2  
☑ Block unnecessary broadcast traffic  

---

## **6. Exam Focus Points**  

✔ **Memorize** QoS priority classes (EF, AF41, etc.)  
✔ **Understand** TCP window scaling mechanics  
✔ **Calculate** bandwidth requirements:  
   ```  
   Required BW = (Data Size × 8) / Transfer Time  
   ```  
✔ **Compare** optimization techniques (compression vs caching)  

**Practice Question**:  
*"A company's file server is experiencing slow response times. Propose three hardware and two software optimizations to improve performance, explaining how each solution helps."*  

*(End of Notes)* 🚀
