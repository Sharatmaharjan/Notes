# **Unit 9: The Internet**  


## **1. Introduction to the Internet**  
The Internet is a **global network of networks** that uses TCP/IP to connect billions of devices. It enables services like WWW, email, and cloud computing through interconnected ISPs.  

### **Key Characteristics:**  
✔ **Decentralized architecture** (no single owner)  
✔ **Packet-switched communication** (IP-based routing)  
✔ **Redundant pathways** (self-healing via BGP)  


---

## **2. How the Internet Works**  

### **A. Basic Architecture**  
| **Component**       | **Function** |  
|---------------------|-------------|  
| **End Systems** | Hosts (computers, smartphones) |  
| **Access Networks** | DSL, Cable, FTTH |  
| **ISP Backbones** | High-speed fiber links (Tier 1/2/3) |  
| **IXPs (Internet Exchange Points)** | ISP interconnection hubs |  

### **B. Connecting to an ISP**  
1. **Physical Connection**:  
   - Home: Modem → Router → ISP Point of Presence (PoP)  
   - Enterprise: Dedicated leased line (e.g., T1, fiber)  

2. **Logical Connection**:  
   - **DHCP**: Assigns IP address  
   - **PPPoE**: Authentication for DSL  

### **C. The Internet Today**  
- **IPv4 exhaustion** → IPv6 adoption (~40% as of 2023)  
- **Content Dominance**:  
  - 60% traffic = video (Netflix, YouTube)  
  - 25% = web browsing  


---

## **3. Internet Access Technologies**  

### **A. Digital Subscriber Line (DSL)**  
| **Type** | **Speed** | **Distance Limit** |  
|----------|----------|-------------------|  
| ADSL | 1-100 Mbps | 5.5 km |  
| VDSL2 | 100-300 Mbps | 1.2 km |  

**Working Principle:**  
- Uses existing telephone lines  
- Frequency division:  
  - 0-4 kHz = Voice  
  - 25 kHz-1.1 MHz = Data  

### **B. Cable Modem**  
- **DOCSIS Standards**:  
  - 3.0 → 1 Gbps down  
  - 4.0 → 10 Gbps down  
- **Shared medium**: Bandwidth splits among neighborhood users  

### **C. Fiber to the Home (FTTH)**  
| **Technology** | **Speed** | **Architecture** |  
|---------------|----------|------------------|  
| GPON | 2.5 Gbps down | Passive optical splitter |  
| XGS-PON | 10 Gbps symmetric | Point-to-multipoint |  

### **D. WiMAX (IEEE 802.16)**  
- **Last-mile wireless** (30-40 km range)  
- **Declining use**: Replaced by 4G/5G  

**Comparison Table:**  
| **Technology** | **Max Speed** | **Latency** | **Best For** |  
|---------------|--------------|------------|-------------|  
| DSL | 300 Mbps | 10-40ms | Rural areas |  
| Cable | 10 Gbps | 5-25ms | Suburban |  
| FTTH | 10 Gbps | 1-5ms | Urban |  
| 5G | 20 Gbps | 1-10ms | Mobile |  

---

## **4. Future of the Internet**  

### **A. Internet Governance**  
| **Organization** | **Role** |  
|------------------|---------|  
| **ICANN** | Manages DNS/IP allocation |  
| **IETF** | Develops protocols (RFCs) |  
| **ITU** | Global telecom standards |  

### **B. Emerging Technologies**  
1. **Web 3.0**:  
   - Decentralized apps (Blockchain, IPFS)  
2. **Metaverse**:  
   - VR/AR integration (Requires <20ms latency)  
3. **Quantum Internet**:  
   - QKD (Quantum Key Distribution) for unhackable links  

### **C. Challenges**  
- **Digital divide** (50% global population still offline)  
- **Cyber sovereignty** (National firewalls, data laws)  

---

  
3. Web 3.0 architecture vs traditional web
