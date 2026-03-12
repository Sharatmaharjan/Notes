# Unit 6: The Application Layer

## 6.1 Functions of Application Layer

### Definition and Position
- **Definition**: Layer 7 of OSI model, the highest layer that provides network services directly to end-user applications 
- **Position**: Interface between user applications and the underlying network layers 
- **Purpose**: Enables applications to communicate with applications on other hosts as if they were directly connected

### Primary Functions

**A. Network Access to Applications**
- Provides interface for user applications to access network services 
- Allows applications to request network services without knowing network details
- **Real-world example**: Web browser requesting webpage without knowing TCP/IP complexities

**B. Resource Sharing and Device Virtualization**
- Implements virtual-file and virtual-terminal protocols 
- Makes remote resources appear local to applications
- **Example**: Network printer appearing as local printer to applications

**C. Service Identification and Advertisement**
- Identifies communication partners and determines resource availability
- Applications advertise services they provide on network
- **Example**: Print server advertising printing service to network clients

**D. Data Exchange and Synchronization**
- Manages data exchange between cooperating applications
- Provides syntax-independent data transfer
- **Example**: Email client and server exchanging messages regardless of platform differences

**E. Error Handling and Recovery**
- Provides error recovery mechanisms for application-level failures
- Ensures reliable communication between distributed applications
- **Example**: File transfer protocol recovering from interrupted downloads

**F. Application-Level Security**
- Implements authentication, authorization, and encryption
- Ensures only authorized users access services
- **Example**: HTTPS providing secure web transactions

### Application Layer Services
- **File transfer**: Moving files between systems
- **Email**: Sending and receiving messages
- **Web browsing**: Accessing distributed hypermedia
- **Directory services**: Looking up resources and addresses
- **Remote login**: Accessing remote systems
- **Network management**: Monitoring and controlling network devices

---

## 6.2 Application Layer Protocols

### 6.2.1 DNS (Domain Name System)

**Overview**
- **Definition**: Hierarchical, distributed naming system that translates domain names to IP addresses 
- **Port**: UDP 53 (primary), TCP 53 (failover/zone transfers) 
- **Purpose**: Humans remember names (google.com), computers need IP addresses (142.250.192.174) 

**DNS Architecture**

| Component | Description | Example |
| :--- | :--- | :--- |
| **Root Servers** | Top of hierarchy, 13 logical root servers worldwide | a.root-servers.net (198.41.0.4)  |
| **TLD Servers** | Manage top-level domains (.com, .org, .edu, .np) | a.edu-servers.net  |
| **Authoritative Servers** | Provide answers for specific domains | dns.google.com, ns.tu.edu.np |
| **Local/Recursive Resolvers** | ISP or organizational DNS servers that query on behalf of clients | 8.8.8.8 (Google), 1.1.1.1 (Cloudflare)  |

**DNS Query Types**

| Type | Value | Purpose |
| :--- | :--- | :--- |
| **A** | 1 | Hostname → IPv4 address  |
| **AAAA** | 28 | Hostname → IPv6 address |
| **MX** | 15 | Mail exchange server for domain  |
| **NS** | 2 | Authoritative name server for domain |
| **CNAME** | 5 | Canonical name (aliasing) |
| **PTR** | 12 | Reverse lookup (IP → hostname) |
| **TXT** | 16 | Text information (SPF, verification) |

**DNS Resolution Process** 

**Iterative Query Example**: Resolving `demo.cs.swarthmore.edu`

| Step | Query To | Response | Action |
| :--- | :--- | :--- | :--- |
| 1 | Root server (198.41.0.4) | "Ask .edu TLD server at 192.54.112.30" | Query TLD server |
| 2 | .edu TLD server (192.54.112.30) | "Ask swarthmore.edu authoritative server at 130.58.64.20" | Query authoritative server |
| 3 | swarthmore.edu authoritative (130.58.64.20) | "demo.cs.swarthmore.edu = 130.58.68.26" | Return to client |

**Recursive Query**: Resolver does all work; client just asks and receives answer (typical home router behavior)

**DNS Caching**
- Responses cached with TTL (Time To Live)
- Reduces network traffic and latency
- Negative caching: Failed lookups also cached

**Anycast DNS** 
- Single IP (8.8.8.8) served by multiple physical servers globally
- BGP routes client to nearest server
- **Advantages**: Low latency, redundancy, DDoS resilience

**Real-world example**: Typing `facebook.com` in browser → DNS resolves to 31.13.71.36 → browser connects to that IP

---

### 6.2.2 DHCP (Dynamic Host Configuration Protocol)

**Overview**
- **Definition**: Protocol automatically assigning IP addresses and network parameters to devices 
- **Ports**: UDP 67 (server), UDP 68 (client) 
- **Purpose**: Eliminate manual IP configuration, prevent address conflicts

**DHCP DORA Process** 

| Phase | Message | Direction | Description |
| :--- | :--- | :--- | :--- |
| **D**iscover | DHCPDISCOVER | Client → Broadcast | Client searches for DHCP server (Source IP: 0.0.0.0, Dest: 255.255.255.255) |
| **O**ffer | DHCPOFFER | Server → Client | Server offers IP address, subnet mask, lease time |
| **R**equest | DHCPREQUEST | Client → Broadcast | Client accepts offer, requests specific IP |
| **A**ck | DHCPACK | Server → Client | Server confirms lease, provides additional options |

**DHCP Message Fields** 
- **Client MAC address**: Hardware identifier
- **Requested IP**: Client-specified preference
- **Options**: Subnet mask, router, DNS servers, lease time, domain name

**DHCP Lease Management** 

| Event | Timing | Action |
| :--- | :--- | :--- |
| **Lease obtained** | T0 | Client gets IP for lease duration (default: 8 days) |
| **Renewal (T1)** | 50% lease | Client unicasts DHCPREQUEST to original server |
| **Rebinding (T2)** | 87.5% lease | Client broadcasts to any server if original unreachable |
| **Expiration** | 100% lease | Client must stop using IP, restart DORA |

**DHCP Components** 

| Component | Description |
| :--- | :--- |
| **Scope** | Range of IP addresses available for lease |
| **Exclusion range** | Addresses within scope NOT offered to clients (for static devices) |
| **Reservation** | Permanent assignment of specific IP to specific MAC address |
| **Superscope** | Multiple scopes on same physical subnet (multinet) |
| **Option** | Additional parameters (DNS, gateway, domain) |

**DHCP Relay Agent** 
- Forwards DHCP broadcasts between subnets
- Allows one DHCP server to serve multiple networks
- Converts broadcast to unicast to reach remote server

**APIPA (Automatic Private IP Addressing)** 
- **Range**: 169.254.0.0/16
- **When used**: DHCP server unavailable
- **Operation**: Client self-assigns, checks uniqueness, continues background DHCP attempts
- **Purpose**: Enable local communication when DHCP fails

**Advantages**
- Centralized IP management
- Eliminates manual configuration errors
- Efficient address reuse through leasing
- Supports mobile devices (plug and play)

**Disadvantages**
- Single point of failure (server redundancy needed)
- DHCP starvation attacks possible
- Requires relay agents for routed networks

**Real-world example**: Laptop connects to campus WiFi → DHCP automatically assigns IP, subnet mask, gateway, DNS → user browses immediately

---

### 6.2.3 WWW (World Wide Web)

**Overview**
- **Definition**: Information system where documents and resources are identified by URLs and accessible via the Internet
- **Components**:
  - **HTML**: Document format
  - **URL/URI**: Resource identifiers
  - **HTTP/HTTPS**: Transfer protocols
  - **Web browsers**: User agents
  - **Web servers**: Resource hosts

**Web Architecture**
- **Client-server model**: Browser requests, server responds
- **Stateless protocol**: Each request independent
- **Resource-based**: Everything identified by URL

---

### 6.2.4 HTTP (Hypertext Transfer Protocol)

**Overview**
- **Definition**: Foundation protocol for data communication on World Wide Web 
- **Port**: TCP 80 
- **Characteristics**: Stateless, plaintext, request-response

**HTTP Request Methods**

| Method | Purpose | Example |
| :--- | :--- | :--- |
| **GET** | Retrieve resource | Download webpage |
| **POST** | Submit data to server | Form submission |
| **PUT** | Upload resource | File upload |
| **DELETE** | Remove resource | Delete file |
| **HEAD** | Get headers only | Check resource existence |
| **OPTIONS** | Query supported methods | CORS preflight |

**HTTP Response Status Codes**

| Code Range | Category | Examples |
| :--- | :--- | :--- |
| **1xx** | Informational | 100 Continue |
| **2xx** | Success | 200 OK, 201 Created |
| **3xx** | Redirection | 301 Moved Permanently, 302 Found |
| **4xx** | Client Error | 404 Not Found, 403 Forbidden |
| **5xx** | Server Error | 500 Internal Server Error, 503 Unavailable |

**HTTP Limitations** 
- **No encryption**: All data in plaintext
- **Vulnerable to**: Packet sniffing, man-in-the-middle attacks, session hijacking
- **No server authentication**: Client cannot verify server identity

---

### 6.2.5 HTTPS (HTTP Secure)

**Overview**
- **Definition**: HTTP over TLS/SSL encryption 
- **Port**: TCP 443 
- **Purpose**: Confidentiality, integrity, authentication

**HTTPS vs HTTP** 

| Feature | HTTP | HTTPS |
| :--- | :--- | :--- |
| **Encryption** | None (plaintext) | TLS/SSL encryption |
| **Data integrity** | Not guaranteed | Cryptographic verification |
| **Authentication** | None | Certificate-based server verification |
| **Port** | 80 | 443 |
| **Trust indicators** | "Not secure" warning | Padlock icon |
| **SEO ranking** | Lower | Higher (Google ranking boost) |

**TLS Handshake Process** 

| Step | Description |
| :--- | :--- |
| **1. Client Hello** | Browser sends supported TLS versions, cipher suites, random value |
| **2. Server Hello** | Server selects cipher, sends SSL certificate and random value |
| **3. Authentication** | Client verifies server certificate against trusted CAs |
| **4. Key Exchange** | Client generates pre-master secret, encrypts with server's public key |
| **5. Session Keys** | Both derive symmetric session keys from pre-master secret |
| **6. Secure Communication** | Encrypted data transfer begins |

**Certificate Management** 
- **Certificate Authority (CA)** : Trusted third-party issuing digital certificates
- **X.509 certificate**: Contains public key, domain name, issuer, validity period
- **Certificate validation**: Browser checks signature, expiration, revocation
- **Short-lived certs**: Decreasing validity periods (47-200 days by 2026)

**Security Benefits** 
- **Confidentiality**: Prevents eavesdropping
- **Integrity**: Detects tampering
- **Authentication**: Ensures correct server
- **Protection against**: MITM attacks, session hijacking, credential theft

**Adoption Statistics** 
- **USA**: ~98% web traffic HTTPS
- **India**: ~92% adoption
- **Indonesia**: ~87% adoption

**Real-world example**: Online banking → HTTPS encrypts login credentials, transaction data, prevents interception

---

### 6.2.6 TELNET

**Overview**
- **Definition**: Protocol providing bidirectional interactive text-oriented communication using virtual terminal connection
- **Port**: TCP 23
- **Purpose**: Remote login to network devices

**Characteristics**
- **Clear text**: All data (including passwords) transmitted unencrypted
- **Simple**: Minimal client required
- **Cross-platform**: Works between different OS types

**Advantages**
- Ubiquitous support on network devices
- Simple troubleshooting tool
- Low overhead

**Disadvantages**
- **Insecure**: No encryption, vulnerable to sniffing
- No authentication mechanisms
- Largely replaced by SSH

**Real-world use**: Legacy systems, network device configuration (insecure networks), testing port connectivity (`telnet host port`)

---

### 6.2.7 FTP (File Transfer Protocol)

**Overview**
- **Definition**: Standard protocol for transferring files between client and server
- **Ports**: TCP 21 (control), TCP 20 (data active mode)
- **Purpose**: Upload, download, delete, rename files

**FTP Operation**

| Connection | Purpose | Direction |
| :--- | :--- | :--- |
| **Control connection** | Commands, authentication | Persistent, port 21 |
| **Data connection** | File transfers, directory listings | Per transfer, port 20 or dynamic |

**FTP Modes**

| Mode | Data Connection | Description |
| :--- | :--- | :--- |
| **Active** | Server initiates to client port 20 | Client must accept incoming connection (firewall issues) |
| **Passive** | Client initiates to server-assigned port | Client-friendly, works through firewalls |

**FTP Commands**
- `USER username` - Authentication
- `PASS password` - Authentication
- `LIST` - Directory listing
- `RETR filename` - Download file
- `STOR filename` - Upload file
- `DELE filename` - Delete file
- `QUIT` - End session

**FTP Response Codes** (similar to HTTP)
- **2xx**: Success
- **3xx**: Intermediate
- **4xx**: Temporary error
- **5xx**: Permanent error

**Advantages**
- Simple, widely supported
- Resume interrupted transfers
- Directory navigation
- Batch file operations

**Disadvantages**
- **Insecure**: Passwords and data in plaintext
- Multiple ports complicate firewall configuration
- Active mode problematic with NAT

**Secure Alternatives**
- **FTPS**: FTP over SSL/TLS
- **SFTP**: SSH File Transfer Protocol (different protocol entirely)

**Real-world example**: Web developers uploading website files to hosting server

---

### 6.2.8 Email Protocols: SMTP, POP, IMAP

Email communication requires three protocols: one for sending, two for receiving .

#### A. SMTP (Simple Mail Transfer Protocol)

**Overview**
- **Definition**: Protocol for sending email messages between servers and from client to server 
- **Ports**: 
  - TCP 25 (default, often blocked for client use)
  - TCP 465 (SSL/TLS)
  - TCP 587 (submission with authentication - recommended) 
- **Purpose**: Outgoing mail delivery

**How SMTP Works**
1. **MUA (Mail User Agent)** → **MSA (Mail Submission Agent)** : Client submits to outgoing server
2. **MSA** → **MTA (Mail Transfer Agent)** : Server-to-server transfer
3. **MTA** → **MDA (Mail Delivery Agent)** : Final delivery to recipient's mailbox

**SMTP Commands**
- `HELO/EHLO` - Identify client
- `MAIL FROM:` - Sender address
- `RCPT TO:` - Recipient address
- `DATA` - Message content
- `QUIT` - End session

**Advantages**
- Simple, text-based protocol
- Reliable store-and-forward
- Handles complex routing

**Disadvantages**
- No built-in security (plaintext)
- Spam vulnerability (solved by authentication)
- Message size limits

#### B. POP3 (Post Office Protocol version 3)

**Overview**
- **Definition**: Protocol for downloading email from server to local client 
- **Ports**: 
  - TCP 110 (default)
  - TCP 995 (SSL/TLS)
- **Purpose**: Retrieve and usually delete messages from server

**POP3 Operation** 

| Phase | Description |
| :--- | :--- |
| **1. Connect** | Client connects to server port 110/995 |
| **2. Authenticate** | USER/PASS commands |
| **3. Transaction** | LIST, RETR, DELE commands |
| **4. Update** | QUIT - server deletes marked messages |

**POP3 Modes**
- **Download and delete**: Messages removed from server (traditional)
- **Download and keep**: Copies left on server

**Advantages** 
- Simple implementation
- Works offline (messages stored locally)
- Minimal server storage required
- Good for single-device access

**Disadvantages**
- Poor for multiple devices (messages scattered)
- No server-side folder management
- Limited search capabilities

#### C. IMAP (Internet Message Access Protocol)

**Overview**
- **Definition**: Protocol for accessing and managing email directly on server 
- **Ports**: 
  - TCP 143 (default)
  - TCP 993 (SSL/TLS)
- **Purpose**: Synchronize email across multiple devices, manage folders server-side

**IMAP Features** 
- **Server-side storage**: Messages remain on server
- **Folder management**: Create, rename, delete mailboxes
- **State synchronization**: Read/unread status across devices
- **Partial fetch**: Download headers first, then specific parts
- **Concurrent access**: Multiple clients simultaneously

**IMAP Commands**
- `LOGIN` - Authenticate
- `SELECT` - Choose mailbox
- `FETCH` - Retrieve messages/parts
- `STORE` - Change flags (read, deleted)
- `SEARCH` - Server-side search
- `LOGOUT` - End session

**Advantages** 
- Multi-device synchronization
- Server-side search
- Centralized backup
- Efficient bandwidth (partial downloads)

**Disadvantages**
- Requires server storage
- More complex than POP3
- Server dependency (no offline access without caching)

### Email Protocol Comparison 

| Feature | SMTP | POP3 | IMAP |
| :--- | :--- | :--- | :--- |
| **Primary use** | Send mail | Receive (download) | Receive (sync) |
| **Direction** | Push | Pull | Pull |
| **Port (plain)** | 25, 587 | 110 | 143 |
| **Port (SSL)** | 465, 587 | 995 | 993 |
| **Message storage** | N/A | Local | Server |
| **Multi-device** | N/A | Poor | Excellent |
| **Offline access** | N/A | Yes (full copy) | Limited (cached) |
| **Server folders** | N/A | No | Yes |

**Real-world email workflow** :
1. **Sending**: Outlook (SMTP port 587) → Gmail SMTP server → Internet → Recipient's mail server
2. **Receiving**: Recipient's phone (IMAP port 993) checks Gmail → Syncs messages and folders
3. **Alternative**: Recipient downloads via Outlook (POP3 port 995) → Messages moved to local PC

---

## 6.3 Concept of Traffic Analyzer

### Overview
Traffic analyzers (network monitors) capture, analyze, and visualize network traffic for troubleshooting, performance monitoring, and security analysis.

### 6.3.1 SNMP (Simple Network Management Protocol)

**Overview**
- **Definition**: Protocol for collecting and organizing information about managed devices on IP networks 
- **Ports**: UDP 161 (queries), UDP 162 (traps)
- **Purpose**: Monitor network devices, modify configurations, receive alerts

**SNMP Components**

| Component | Description |
| :--- | :--- |
| **NMS (Network Management Station)** | Central system running monitoring software |
| **Managed Device** | Network equipment with SNMP agent (router, switch, server) |
| **SNMP Agent** | Software on device collecting and providing management data |
| **MIB (Management Information Base)** | Database defining accessible variables (OIDs) |

**SNMP Operations**

| Operation | Direction | Description |
| :--- | :--- | :--- |
| **GET** | NMS → Agent | Request specific variable value |
| **GET-NEXT** | NMS → Agent | Get next variable (walk through table) |
| **SET** | NMS → Agent | Modify configuration variable |
| **TRAP** | Agent → NMS | Unsolicited alert (event notification) |
| **INFORM** | Agent → NMS | Confirmed trap |

**SNMP Versions**

| Version | Security | Features |
| :--- | :--- | :--- |
| **SNMPv1** | Community strings (plaintext) | Basic monitoring |
| **SNMPv2c** | Community strings (plaintext) | Improved performance, GET-BULK |
| **SNMPv3** | Authentication, encryption | User-based security model |

**Real-world example**: Router sends SNMP trap when interface goes down → NMS alerts administrator

---

### 6.3.2 MRTG (Multi Router Traffic Grapher)

**Overview** 
- **Definition**: Open-source tool monitoring and graphing network traffic using SNMP
- **Developed by**: Tobias Oetiker, Dave Rand
- **Language**: Perl
- **Output**: HTML pages with PNG graphs
- **Platforms**: Windows, Linux, Unix

**How MRTG Works** 
1. **Reads configuration**: Specifies devices, interfaces, polling interval
2. **SNMP queries**: Polls router interfaces at regular intervals (typically 5 minutes)
3. **Logs data**: Stores historical traffic values
4. **Generates graphs**: Creates daily, weekly, monthly, yearly views
5. **Produces HTML**: Creates web-accessible reports

**MRTG Features** 
- **Bandwidth monitoring**: In/out traffic per interface
- **Threshold alerts**: Notify when traffic exceeds limits
- **Multi-device support**: Routers, switches, servers with SNMP
- **Cross-platform**: Runs anywhere with Perl
- **Extensible**: Can monitor CPU, temperature, etc.

**Advantages** 
- Free and open-source
- Lightweight
- Simple to configure
- Long-term trend visualization

**Disadvantages** 
- Limited to SNMP data
- No real-time monitoring (5-min granularity)
- Basic alerting
- Configuration requires command line

**Real-world example**: Network admin monitors core router bandwidth to plan capacity upgrades

---

### 6.3.3 PRTG (Paessler Router Traffic Grapher)

**Overview** 
- **Definition**: Comprehensive network monitoring software with MRTG-like functionality
- **Developer**: Paessler AG
- **Model**: Commercial with free tier (100 sensors)
- **Platform**: Windows-based

**PRTG Features** 
- **All-in-one monitoring**: Bandwidth, servers, applications, virtual environments
- **Multiple protocols**: SNMP, WMI, NetFlow, sFlow, packet sniffing
- **Auto-discovery**: Automatically finds network devices
- **Real-time alerts**: Email, SMS, push notifications
- **Custom dashboards**: User-defined views
- **Mobile apps**: iOS, Android monitoring
- **Historical data**: Long-term storage and trending

**PRTG vs MRTG** 

| Feature | MRTG | PRTG |
| :--- | :--- | :--- |
| **Cost** | Free (open source) | Free up to 100 sensors, paid beyond |
| **Platform** | Cross-platform (Perl) | Windows |
| **Protocols** | SNMP only | SNMP, WMI, NetFlow, packet, etc. |
| **Setup** | Manual configuration | Auto-discovery |
| **Interface** | Static HTML | Web GUI, mobile apps |
| **Alerting** | Basic | Comprehensive |
| **Scaling** | Manual configuration | Auto-scaling |

**Real-world example**: Small office monitors router, switch, servers with PRTG free version → receives email alert when disk space low

---

### 6.3.4 Packet Tracer

**Overview**
- **Definition**: Network simulation tool by Cisco for learning and practicing networking
- **Purpose**: Design, configure, and troubleshoot networks without physical hardware
- **Target**: CCNA students, networking beginners

**Features**
- **Visual interface**: Drag-drop network devices
- **Device simulation**: Routers, switches, PCs, servers, wireless devices
- **Protocol support**: Routing (RIP, OSPF, EIGRP), switching (VLAN, STP), WAN, security
- **Packet simulation**: Visualize packet flow between devices
- **Activity scenarios**: Pre-built labs with grading
- **Multi-user**: Collaborate on network designs

**Advantages**
- No hardware required
- Safe learning environment
- Visual packet tracing
- CCNA curriculum aligned
- Free for Cisco Academy members

**Disadvantages**
- Simulation only (not real traffic)
- Limited to Cisco features
- Not for production monitoring

**Real-world use**: BCA students practice configuring OSPF between routers without buying expensive equipment

---

### 6.3.5 Wireshark

**Overview** 
- **Definition**: Free, open-source packet analyzer for network troubleshooting and analysis
- **Platforms**: Windows, macOS, Linux
- **Purpose**: Capture and interactively browse traffic running on computer network

**Key Features** 

| Feature | Description |
| :--- | :--- |
| **Live capture** | Capture traffic from any network interface |
| **Deep inspection** | Display hundreds of protocols with detailed fields |
| **Filtering** | Display filters to focus on specific traffic |
| **Follow streams** | Reconstruct TCP, UDP, HTTP sessions |
| **Statistics** | Protocol hierarchy, conversations, endpoints |
| **Decryption** | Decrypt TLS/SSL with keys (when available) |
| **VoIP analysis** | Analyze voice calls |

**Wireshark Filters** 

**By protocol:**
- `dns` - Show only DNS traffic
- `http || dns` - HTTP or DNS traffic
- `tcp` - All TCP traffic

**By IP address:**
- `ip.addr == 192.168.1.1` - Traffic to/from IP
- `ip.src == 10.0.0.1` - Traffic from source
- `ip.dst == 8.8.8.8` - Traffic to destination

**By port:**
- `tcp.port == 80` - TCP port 80
- `udp.port == 53` - UDP port 53

**Advanced filters:**
- `tcp.flags.reset == 1` - TCP resets (connection problems)
- `dns.qry.name contains "google"` - DNS queries containing "google"
- `http.request.method == "POST"` - HTTP POST requests

**Following Streams** 
- Right-click packet → Follow → TCP/UDP/HTTP Stream
- Reconstructs entire conversation
- Useful for debugging application protocols

**Wireshark Use Cases** 
- **Troubleshooting**: Identify slow connections, packet loss
- **Security analysis**: Detect suspicious traffic, malware communication
- **Protocol debugging**: Verify application behavior
- **Learning**: Understand how protocols actually work
- **Forensics**: Investigate network incidents

**Advantages** 
- Free and open-source
- Comprehensive protocol support
- Powerful filtering
- Cross-platform
- Active community

**Disadvantages** 
- Captures PII (handle with care)
- Can be overwhelming for beginners
- No intrusion detection (passive only)

**Real-world example**: Network engineer captures traffic during slow browsing → analyzes DNS response times → identifies slow DNS server

---

### Traffic Analyzer Comparison

| Tool | Type | Primary Use | Protocol | Cost |
| :--- | :--- | :--- | :--- | :--- |
| **SNMP** | Protocol | Device monitoring standard | UDP 161/162 | N/A |
| **MRTG** | Application | Bandwidth graphing | SNMP | Free |
| **PRTG** | Application | Comprehensive monitoring | SNMP, WMI, NetFlow | Free/Commercial |
| **Packet Tracer** | Simulator | Learning, practice | N/A | Free (education) |
| **Wireshark** | Analyzer | Deep packet inspection | All | Free |
