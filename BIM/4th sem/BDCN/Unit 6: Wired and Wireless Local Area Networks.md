# **Unit 6: Wired and Wireless Local Area Networks**  

## **1. Introduction to LANs**  
A **Local Area Network (LAN)** is a network that connects devices within a limited geographical area such as a home, office, or campus. LANs enable resource sharing (files, printers, internet) and communication among connected devices.  

### **Key Characteristics of LANs:**  
✔ **High data transfer rates** (10 Mbps to 100 Gbps)  
✔ **Limited geographical coverage** (typically within a single building)  
✔ **Privately owned and managed**  
✔ **Uses wired (Ethernet) or wireless (Wi-Fi) technologies**  
 

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


| Feature          | Hub                          | Switch                        | Access Point (AP)              |
|------------------|------------------------------|-------------------------------|--------------------------------|
| **Layer**        | Layer 1 (Physical)           | Layer 2 (Data Link)           | Layer 2 (Bridges to Layer 1)   |
| **Function**     | Broadcasts to all ports      | Directs traffic to specific ports | Connects wireless devices to wired networks |
| **Intelligence** | None (dumb device)           | MAC address learning          | Converts wired ↔ wireless signals |
| **Performance**  | Low (shared bandwidth)       | High (dedicated per-port)     | Medium (shared wireless medium) |
| **Collisions**   | High (single collision domain)| None (per-port domain)        | Managed via CSMA/CA            |
| **Security**     | None                         | Port security/VLAN support    | WPA2/WPA3 encryption           |
| **Use Case**     | Obsolete (historical)        | Modern wired networks         | Wi-Fi networks                 |
| **Example**      | 10BASE-T hub                 | Cisco 2960 switch             | Ubiquiti UniFi AP              |


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

## **Summary Table: LAN Components**  

| **Component**       | **Function** | **Example** |  
|---------------------|-------------|------------|  
| **NIC** | Connects device to network | Ethernet port, Wi-Fi card |  
| **Network Circuits** | Transmits data | Cat 6 cable, Wi-Fi 6 |  
| **Hub** | Broadcasts data (dumb device) | Old 10 Mbps hubs |  
| **Switch** | Forwards data intelligently | Gigabit Ethernet switch |  
| **Access Point** | Provides Wi-Fi connectivity | Wireless router |  
| **NOS** | Manages network resources | Windows Server, Linux |  

---  


## **3. Wired Ethernet**  

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

### **B. Media Access Control (MAC) - CSMA/CD**  
- **Carrier Sense Multiple Access with Collision Detection**  
- How it works:  
  1. Device checks if line is free before transmitting  
  2. If collision occurs, waits random time before retrying  
- *Modern Ethernet*:  
  - Full-duplex switches made CSMA/CD obsolete  
  - Still important for historical understanding  
 

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

## **4. Wireless Ethernet (Wi-Fi)**  

### **A. Wireless Topologies**  

1. **Infrastructure Mode**  
   - Devices connect through an Access Point (AP)  
   - Used in homes/offices  

2. **Ad-Hoc Mode**  
   - Devices connect directly without AP  
   - Limited to small temporary networks  

### **B. Media Access Control - CSMA/CA**  
- **Carrier Sense Multiple Access with Collision Avoidance**  
- Key differences from wired:  
  ✔ Uses RTS/CTS (Request-to-Send/Clear-to-Send)  
  ✔ Implements NAV (Network Allocation Vector)  
  ✔ Includes acknowledgment frames   

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

1. **WEP(Wired Equivalent Privacy) (Weak)**  
   - 64/128-bit encryption  
   - Easily crackable  

2. **WPA(Wi-Fi Protected Access)**  
   - TKIP(Temporal Key Integrity Protocol) encryption  
   - Better than WEP but still vulnerable  

3. **WPA2(Wi-Fi Protected Access II) (Recommended)**  
   - AES-CCMP(Advanced Encryption Standard – Counter Mode with Cipher Block Chaining Message Authentication Code Protocol) encryption  
   - Enterprise mode with RADIUS  

4. **WPA3(Wi-Fi Protected Access III) (Latest)**  
   - 192-bit encryption  
   - Protects against brute-force attacks  


---

## **Comparison: Wired vs Wireless Ethernet**  

| **Feature**       | **Wired Ethernet** | **Wireless Ethernet** |  
|-------------------|--------------------|-----------------------|  
| Speed             | Up to 100Gbps      | Up to 9.6Gbps         |  
| Reliability       | Very high          | Subject to interference |  
| Mobility          | Limited            | Excellent             |  
| Security          | Physically secure  | Requires encryption   |  
| Installation Cost | Higher             | Lower                 |  

---

# **5. Best Practice LAN Design**  

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

✔ **AP(Access Point) Placement**:  
   - **Ceiling-mounted** for optimal coverage  
   - **Avoid** metal obstructions and microwave ovens  

✔ **Controller-Based vs Cloud-Managed**:  
   - **Controller-based**: Cisco WLC, Aruba Mobility Controller  
   - **Cloud-managed**: Meraki, Ubiquiti UniFi  


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

**Best Practices**:  
- Implement **VXLAN(Virtual Extensible LAN)** for network virtualization  
- Use **ECMP(Equal-Cost Multi-Path)** for load balancing  
- Deploy **TOR (Top-of-Rack)** switching  

---

## **4. Designing the e-Commerce Edge**  

### **Critical Elements**  
✔ **DMZ(Demilitarized Zone) Design**:  
   - **Web/App/DB tiers** in separate security zones  
   - **Reverse proxies** (NGINX, F5)  

✔ **Load Balancing**:  
   - **Round Robin/Least Connections** algorithms  
   - **SSL Offloading** at load balancers  

✔ **Security Measures**:  
   - **WAF** (Web Application Firewall)  
   - **DDoS Protection** (Cloudflare, AWS Shield)  

**Best Practices**:  
- Implement **Auto-scaling** for web tier  
- Use **CDN(Content Delivery Network)** for static content  
- **Regular PCI-DSS(Payment Card Industry Data Security Standard) compliance audits**  

---

## **5. Designing the SOHO(Small Office/Home Office) Environment**  

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
 

**Best Practices**:  
- Enable **Guest Network** isolation  
- Schedule **automatic reboots** for stability  
- Implement **QoS** for VoIP prioritization  

---

## **Comparison Tables**  

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


# **6. Improving LAN Performance**  

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


