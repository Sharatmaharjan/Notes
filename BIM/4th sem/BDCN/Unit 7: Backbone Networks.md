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
✔ **STP/RSTP** for loop prevention  
✔ **Link aggregation** (LACP) for bandwidth scaling  

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

#### **ii) MPLS Backbone**  
- Uses **label switching** for traffic engineering  
- *Advantages*:  
  ✔ QoS guarantees (VoIP/VPN support)  
  ✔ Any-to-any connectivity  


### **C. Protocol Considerations**  
✔ **OSPF** (for dynamic routing)  
✔ **BGP** (for large-scale networks)  
✔ **VRRP/HSRP** (router redundancy)  

**Example**:  
A bank with:  
- Core: Cisco ASR 1000 routers  
- MPLS links between branches  

---

## **4. Comparison: Switched vs Routed Backbones**  

| **Feature**       | **Switched Backbone** | **Routed Backbone** |  
|-------------------|-----------------------|----------------------|  
| **OSI Layer**     | Layer 2+3             | Layer 3              |  
| **Speed**         | Higher (wire-speed)   | Lower (router processing) |  
| **Latency**       | Lower                 | Higher                |  
| **Best For**      | Campus networks       | WAN/distributed sites |  
| **Cost**          | Moderate              | Higher                |  

---



**Diagrams to Study**:  
1. Three-tier hierarchical network design  
2. Collapsed vs distributed backbone layouts  
3. MPLS label switching process  
4. STP operation in switched backbones
