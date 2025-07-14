# **Unit 7: Backbone Networks**  

## **1. Introduction to Backbone Networks**  

### **Definition & Purpose**  
A **backbone network** is a high-speed central infrastructure that interconnects different network segments (LANs, subnets, or buildings). It serves as the **core data highway** for an organization.  

### **Key Characteristics**  
✔ **High bandwidth** (10/40/100Gbps+)  
✔ **Low latency** (critical for real-time applications)  
✔ **Redundant paths** (fault tolerance)  
✔ **Scalable architecture**  

---

## **2. Switched Backbones**  

### **A. Basic Concept**  
- Uses **multilayer switches** (Layer 2+3) as the backbone  
- Common in **enterprise campus networks**  

### **B. Design Types**  

#### **i) Collapsed Backbone**  
- Single **core switch** connects all distribution switches  
- *Advantages*:  
  ✔ Cost-effective (fewer devices)  
  ✔ Simplified management  
- *Disadvantages*:  
  ✖ Single point of failure  
  ✖ Limited scalability  

#### **ii) Distributed Backbone**  
- Multiple interconnected switches form the backbone  
- *Advantages*:  
  ✔ Better fault tolerance  
  ✔ Higher scalability  
- *Disadvantages*:  
  ✖ More complex to manage  
  ✖ Higher cost  

### **C. Technical Implementation**  
✔ **VLAN trunking** (802.1Q) between switches  
✔ **STP/RSTP** for loop prevention (Spanning Tree Protocol/Rapid Spanning Tree Protocol)  
✔ **Link aggregation** (LACP-Link Aggregation Control Protocol) for bandwidth scaling  

**Example**:  
A university campus with:  
- Core: Cisco Catalyst 9500 (100Gbps)  
- Distribution: Catalyst 9300 (40Gbps uplinks)  

---

## **3. Routed Backbones**  

### **A. Basic Concept**  
- Uses **routers** (Layer 3) as backbone devices  
- Common in **WANs and large enterprises**  

### **B. Design Approaches**  

#### **i) Subnetted Backbone**  
- Each segment gets unique IP subnet  
- *Advantages*:  
  ✔ Clear traffic segmentation  
  ✔ Improved security (ACLs between subnets)  
- *Disadvantages*:  
  ✖ Higher latency (router hops)  

#### **ii) MPLS(Multiprotocol Label Switching) Backbone**  
- Uses **label switching** for traffic engineering  
- *Advantages*:  
  ✔ QoS guarantees (VoIP/VPN support)  
  ✔ Any-to-any connectivity  


### **C. Protocol Considerations**  
✔ **OSPF(Open Shortest Path First)** (for dynamic routing)  
✔ **BGP(Border Gateway Protocol)** (for large-scale networks)  
✔ **VRRP(Virtual Router Redundancy Protocol)/HSRP(Hot Standby Router Protocol)** (router redundancy)  

**Example**:  
A bank with:  
- Core: Cisco ASR 1000 routers  
- MPLS links between branches  

---

## **Comparison: Switched vs Routed Backbones**  

| **Feature**       | **Switched Backbone** | **Routed Backbone** |  
|-------------------|-----------------------|----------------------|  
| **OSI Layer**     | Layer 2+3             | Layer 3              |  
| **Speed**         | Higher (wire-speed)   | Lower (router processing) |  
| **Latency**       | Lower                 | Higher                |  
| **Best For**      | Campus networks       | WAN/distributed sites |  
| **Cost**          | Moderate              | Higher                |  


---

## **4. Virtual LANs (VLANs)**

### **a. Benefits of VLANs**  
| **Benefit**               | **Description**                                                                 |
|---------------------------|-------------------------------------------------------------------------------|
| **Improved Security**      | Isolates sensitive traffic (e.g., Finance VLAN separate from Guest VLAN)      |
| **Traffic Management**     | Reduces broadcast domains (e.g., 1 large LAN → 3 smaller VLANs)               |
| **Cost Efficiency**        | Eliminates need for physical rewiring to segment networks                     |
| **Flexibility**           | Devices can be grouped logically (by department, function) regardless of physical location |
| **Performance Boost**      | Limits unnecessary broadcast traffic flooding the entire network              |

### **b. How VLANs Work**  
| **Component**          | **Function**                                                                 |
|------------------------|-----------------------------------------------------------------------------|
| **VLAN Tagging (802.1Q)** | Adds a 4-byte tag to Ethernet frames to identify VLAN membership           |
| **Trunk Ports**         | Carries multiple VLAN traffic between switches (uses 802.1Q tagging)        |
| **Access Ports**        | Connects end devices to a single VLAN (untagged traffic)                   |
| **VLAN ID (1-4094)**    | Unique identifier for each VLAN (VLAN 1 = default)                         |

**Key Process**:  
1. A switch assigns a **VLAN ID** to incoming traffic based on:  
   - Port membership (static VLAN)  
   - MAC address/IP (dynamic VLAN)  
2. Tagged frames traverse **trunk links** between switches.  
3. End devices receive **untagged frames** on access ports.  

---

### **Comparison: VLAN vs Physical LAN**  
| **Aspect**       | **VLAN**                          | **Physical LAN**                   |
|------------------|-----------------------------------|------------------------------------|
| **Segmentation** | Logical (software-based)         | Physical (hardware-based)          |
| **Cost**         | Low (uses existing switches)      | High (requires separate switches)  |
| **Flexibility**  | Easy to modify                   | Requires rewiring                  |
| **Scalability**  | Supports 4094 VLANs per network   | Limited by physical ports          |

---

## **5. Best Practice Backbone Design**  

### **A. Hierarchical Design Principles**  
| **Layer**         | **Function**                          | **Devices Used**               | **Best Practices**                  |
|-------------------|---------------------------------------|--------------------------------|-------------------------------------|
| **Core Layer**    | High-speed backbone traffic           | Layer 3 switches, Routers      | - Use redundant 40/100Gbps links    |
| **Distribution**  | Policy enforcement, VLAN routing      | Multilayer switches            | - Implement route summarization     |
| **Access Layer**  | End-device connectivity               | Switches, APs                  | - Use VLANs for segmentation        |

**Key Features**:  
✔ **Modularity**: Easily expandable (e.g., adding new floors/buildings)  
✔ **Resilience**: Dual power supplies, redundant paths (STP/RSTP)  
✔ **Scalability**: Supports 10/40/100Gbps uplinks  


---

## **6. Improving Backbone Performance**  

### **A. Improving Device Performance**  
| **Strategy**             | **Implementation**                          | **Impact**                     |
|--------------------------|---------------------------------------------|--------------------------------|
| **Upgrade Hardware**     | Replace old switches with 10/40Gbps models  | ↑ Throughput, ↓ Latency        |
| **Enable TCAM(Ternary Content Addressable Memory)**          | Use Ternary CAM for faster routing lookups  | Improves packet forwarding     |
| **Optimize Routing Tables** | Implement route summarization (OSPF areas) | Reduces CPU load               |

**Example**:  
- **Before**: 10,000 routing entries → **After**: 500 summarized routes  

---

### **B. Improving Circuit Capacity**  
| **Method**               | **Action**                                 | **Benefit**                    |
|--------------------------|-------------------------------------------|--------------------------------|
| **Link Aggregation**     | Combine 4x1Gbps → 4Gbps (LACP)            | Redundancy + bandwidth boost   |
| **Upgrade to Fiber**     | Replace copper with 10G-SR fiber optics    | Longer reach, EMI immunity     |
| **QoS Prioritization**   | Tag VoIP as DSCP EF (Differentiated Services Code Point Expedited Forwarding) | Guarantees low latency         |

**Case Study**:  
- A campus backbone upgraded from 1Gbps → 10Gbps, reducing VoIP jitter by **70%**.  


---

### **C. Reducing Network Demand**  
| **Technique**          | **How It Works**                          | **Outcome**                   |
|------------------------|------------------------------------------|-------------------------------|
| **Caching**            | Deploy proxy servers for web traffic     | ↓ WAN bandwidth usage         |
| **Compression**        | Enable LZ4(Lempel-Ziv 4) on WAN links                  | ↑ Effective bandwidth         |
| **Block Non-Essential** | Filter Netflix/YouTube during work hours | Frees up **30%+** bandwidth   |

**Real-World Data**:  
- **MPLS + Compression**: Reduced healthcare imaging transfer time from **5 mins → 45 secs**.  

---


