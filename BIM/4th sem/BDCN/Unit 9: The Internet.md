# **Unit 9: The Internet**  


## **1. Introduction to the Internet**  
The Internet is a **global network of networks** that uses TCP/IP to connect billions of devices. It enables services like WWW, email, and cloud computing through interconnected ISPs.  

### **Key Characteristics:**  
✔ **Decentralized architecture** (no single owner)  
✔ **Packet-switched communication** (IP-based routing)  
✔ **Redundant pathways** (self-healing via BGP-automatically reroute traffic if one path fails)  


---

## **2. How the Internet Works**  

### **A. Basic Architecture**  
| **Component**       | **Function** |  
|---------------------|-------------|  
| **End Systems** | Hosts (computers, smartphones) |  
| **Access Networks** | DSL, Cable, FTTH |  
| **ISP Backbones** | High-speed fiber links (Tier 1/2/3) |  
| **IXPs (Internet Exchange Points)** | ISP interconnection hubs |  


Tier 1: Owns and operates the main intercontinental highways.<br>
Tier 2: Connects cities and towns via regional roads, some of which use Tier 1 highways.<br>
Tier 3: Provides local streets to homes and small offices.<br>



### **B. Connecting to an ISP**  
1. **Physical Connection**:  
   - Home: Modem → Router → ISP Point of Presence (PoP)  
   - Enterprise: Dedicated leased line (e.g., T1, fiber)  

2. **Logical Connection**:  
   - **DHCP**: Assigns IP address  
   - **PPPoE(Point-to-Point Protocol over Ethernet)**: Authentication for DSL  (When you enter your ISP-provided username and password into your router/modem (e.g., for WorldLink or Vianet in Nepal), that’s typically using PPPoE.)

### **C. The Internet Today**  
- **IPv4 exhaustion** → IPv6 adoption (~40% as of 2023)  
- **Content Dominance**:  
  - 60% traffic = video (Netflix, YouTube)  
  - 25% = web browsing  


---

## **3. Internet Access Technologies**  

### **A. Digital Subscriber Line (DSL)**  

DSL is a family of technologies that provides internet access over traditional telephone lines (copper wires). It enables high-speed data transmission while allowing simultaneous voice calls and internet usage.
DSL is commonly used in homes and small businesses where fiber may not be available.

| **Type**                             | **Speed**                                       | **Distance Limit**          | **Description**                                                                                                      |
| ------------------------------------ | ----------------------------------------------- | --------------------------- | -------------------------------------------------------------------------------------------------------------------- |
| **ADSL** (Asymmetric DSL)            | **1–100 Mbps** (typically lower upstream speed) | **Up to 5.5 km** from DSLAM | Optimized for **download-heavy** activities like web browsing and streaming. Upload speed is lower.                  |
| **VDSL2** (Very-high-bit-rate DSL 2) | **100–300 Mbps** (higher in short distances)    | **Up to 1.2 km** from DSLAM | Offers much **faster speeds** than ADSL, suitable for HD video, gaming, and VoIP. Speed drops sharply with distance. |


**Working Principle:**  
- Uses existing telephone lines  
- Frequency division:  
  - 0-4 kHz = Voice  
  - 25 kHz-1.1 MHz = Data  

### **B. Cable Modem**  

A Cable Modem provides internet access over the same coaxial cable network used for cable TV. It is widely used in residential and business broadband connections.

| **Version**    | **Maximum Download Speed** | **Notes**                                                    |
| -------------- | -------------------------- | ------------------------------------------------------------ |
| **DOCSIS 3.0** | Up to **1 Gbps**           | Supports channel bonding for higher speeds                   |
| **DOCSIS 4.0** | Up to **10 Gbps**          | Latest standard with improved upstream and downstream speeds |
 
- **Shared medium**: Bandwidth splits among neighborhood users  

### **C. Fiber to the Home (FTTH)**  

FTTH delivers high-speed internet access by running fiber-optic cables directly to individual homes or businesses. This technology offers much faster and more reliable connections compared to copper-based DSL or coaxial cable.

| **Technology**                                             | **Speed**                                                  | **Architecture**                                                                                                              |
| ---------------------------------------------------------- | ---------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------- |
| **GPON** (Gigabit Passive Optical Network)                 | Up to **2.5 Gbps downstream**                              | Uses **passive optical splitters** to share a single fiber among multiple users                                               |
| **XGS-PON** (10 Gigabit Symmetric Passive Optical Network) | Up to **10 Gbps symmetric** (both downstream and upstream) | Also uses **point-to-multipoint architecture** with passive splitters but supports much higher speeds and symmetric bandwidth |
 

### **D. WiMAX (IEEE 802.16)**  

WiMAX (Worldwide Interoperability for Microwave Access) is a wireless broadband technology designed to provide high-speed internet access over long distances, especially for the last-mile connection.

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

Internet governance refers to the coordination and management of key technical and policy aspects of the Internet to ensure it operates smoothly, securely, and reliably worldwide.

| **Organization**                                                | **Role**                                                                                                                                                |
| --------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **ICANN** (Internet Corporation for Assigned Names and Numbers) | Manages the **Domain Name System (DNS)** and IP address allocation worldwide. Ensures unique naming and addressing.                                     |
| **IETF** (Internet Engineering Task Force)                      | Develops and promotes **Internet standards and protocols** through RFCs (Request for Comments). Responsible for protocols like TCP/IP, HTTP, SMTP, etc. |
| **ITU** (International Telecommunication Union)                 | UN agency that sets **global telecommunications standards** and coordinates international radio spectrum and satellite orbits.                          |


### **B. Emerging Technologies**  
1. **Web 3.0**:  
   - Decentralized apps (Blockchain, IPFS(InterPlanetary File System))  
2. **Metaverse**:  
   - VR/AR integration (Requires <20ms latency)  
3. **Quantum Internet**:  
   - QKD (Quantum Key Distribution) for unhackable links  

### **C. Challenges**  
- **Digital divide** (50% global population still offline)  
- **Cyber sovereignty** (National firewalls, data laws)  

---

  
3. Web 3.0 architecture vs traditional web
