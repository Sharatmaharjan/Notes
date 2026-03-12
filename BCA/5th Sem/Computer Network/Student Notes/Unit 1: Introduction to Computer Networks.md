## Unit 1: Introduction to Computer Networks

### 1.1 Network as an infrastructure for data communication
- **Definition**: A computer network is an infrastructure that connects two or more computers and devices (nodes) together to facilitate data communication and resource sharing .
- **Purpose**: It provides the foundational pathway for data to travel from sender to receiver, similar to how a highway system transports vehicles .
- **Key Components of this Infrastructure**:
    - **Hardware**: Includes NIC (wired/wireless), cables, switches, routers, etc. .
    - **Software**: Includes protocols and network operating systems.
    - **Transmission Media**: The physical path (guided like cables, unguided like radio waves) .
- **Function**: It governs how data is formatted, addressed, transmitted, and received, ensuring all devices can communicate effectively.

### 1.2 Applications of Computer network
- **Business Applications**:
    - **Resource Sharing**: Sharing hardware (printers, scanners) and software across an organization to reduce cost .
    - **Communication**: Enabling video conferencing, VoIP (e.g., Zoom, Skype), and instant messaging for remote collaboration .
    - **Centralized Data Management**: Storing data on central servers for easy access, backup, and management (e.g., company database).
- **Communication Applications**:
    - **Email (SMTP)** : Primary mode of professional and personal written communication .
    - **Social Networking**: Platforms like Facebook, Instagram, and Twitter connect billions of users globally.
    - **VoIP and Video Calls**: Applications like WhatsApp, Google Meet, and Zoom rely on networks for real-time audio/video transmission.
- **E-commerce Applications**:
    - **Online Transactions**: Enabling financial transactions, online banking, and shopping (Amazon, Daraz).
    - **Digital Marketing**: Targeted advertising based on user data and online behavior.
- **Entertainment Applications**:
    - **Streaming Services**: On-demand video (Netflix, YouTube) and music (Spotify) streaming.
    - **Online Gaming**: Multiplayer interactive games connecting players worldwide.
- **Educational Applications**: Online learning platforms (Coursera, TU e-Learning portal), virtual classrooms, and access to digital libraries .

### 1.3 Network Architecture
Network architecture defines how devices are structured and how they interact. The two primary types are:
- **Client-Server Architecture**:
    - **Concept**: A central, powerful server provides services (like file storage, web hosting, email) and multiple clients request these services.
    - **Real-world example**: Accessing the TU exam form portal. Your laptop (client) requests the form from the TU server.
    - **Advantages**: Centralized management, better security, high performance.
    - **Disadvantages**: High cost of server infrastructure, single point of failure (if server goes down, network is useless).
- **Peer-to-Peer (P2P) Architecture**:
    - **Concept**: All devices have equal status and can both request and provide services. There is no central server.
    - **Real-world example**: Sharing files via Bluetooth between two mobiles or using BitTorrent for downloads.
    - **Advantages**: Inexpensive to set up, no single point of failure.
    - **Disadvantages**: Decentralized management, less secure, performance degrades as users increase.

### 1.4 Types of computer Networks
Networks are categorized based on their geographical span :

- **Local Area Network (LAN)** :
    - **Span**: Small area like a room, building, or campus (typically up to 2 miles) .
    - **Ownership**: Usually privately owned (e.g., by an organization).
    - **Speed**: High speed (100 Mbps to 1000 Mbps) .
    - **Technology**: Uses Ethernet and Wi-Fi.
    - **Real-world example**: Computer lab in your BCA college, a cyber cafe, or a home network.
- **Metropolitan Area Network (MAN)** :
    - **Span**: Covers a city or town (larger than LAN, smaller than WAN) .
    - **Ownership**: Can be a single organization (e.g., local government) or a service provider.
    - **Real-world example**: Cable TV network connecting a whole city, or the network connecting different branches of a bank within Kathmandu valley.
- **Wide Area Network (WAN)** :
    - **Span**: Covers large geographical areas like countries or continents .
    - **Ownership**: Typically operated by multiple service providers or large organizations.
    - **Technology**: Uses leased telecommunication lines, satellites, or undersea cables.
    - **Real-world example**: The Internet itself is the largest WAN. Connection between TU Central Library and a university in the USA.

### 1.5 Protocols and Standards
- **Protocols**: A set of rules governing data communication. It defines **what**, **how**, and **when** to communicate .
    - **Key Elements of a Protocol** :
        - **Syntax**: Structure or format of the data (e.g., first 8 bits are sender's address).
        - **Semantics**: Meaning of each section of bits (e.g., what does a specific pattern mean? Is it a control signal or data?).
        - **Timing**: When data should be sent and how fast (synchronization and speed matching).
    - **Real-world example**: A person asking "How are you?" expects a reply about well-being, not their shoe size. This is the protocol of conversation.
- **Standards**: Agreed-upon guidelines providing a common language for interoperability among different vendors' equipment.
    - **De Facto Standard**: Standards that have happened by history or widespread use, not officially approved. **Example**: HTTP, Ethernet.
    - **De Jure Standard**: Standards legislated by an official recognized body. **Example**: OSI model (by ISO) .

### 1.6 The OSI Reference Model
- **Overview**: Open Systems Interconnection model developed by ISO. It is a 7-layer theoretical framework for how network communication should ideally happen .
- **Purpose**: To standardize network functions into distinct layers, promoting interoperability.

**The 7 Layers (from bottom to top):**

| Layer | Name | PDU (Data Unit) | Key Functions | Example Protocols | Real-world Analogy |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **1** | **Physical** | **Bits** | - Transmission of raw bit stream (0s & 1s) over physical medium . <br> - Defines physical & mechanical characteristics (voltage levels, data rates, cable specifications). | Ethernet (cabling), RJ45, Wi-Fi (802.11), Bluetooth  | The **postman** physically carrying the letter packet. The road/vehicle used. |
| **2** | **Data Link** | **Frame** | - **Physical addressing**: Adds MAC (Media Access Control) address of sender/receiver . <br> - **Error control**: Detects and discards corrupted frames (CRC error detection) . <br> - **Framing**: Organizes bits into frames from the physical layer. | Ethernet, PPP, VLAN  | The **postal worker** who sorts letters, puts them in envelopes, and writes the local street address. |
| **3** | **Network** | **Packet** | - **Logical addressing**: Adds logical (IP) addresses to determine source and destination . <br> - **Routing**: Determines the best path for data transmission across networks . | IP (IPv4, IPv6), ICMP, ARP  | The **mail sorter** who reads the city/zip code and decides which truck to put the letter on for the next city. |
| **4** | **Transport** | **Segment** (TCP) / Datagram (UDP) | - **End-to-end connection**: Ensures complete data transfer between hosts . <br> - **Reliability**: Provides error recovery, flow control, and sequencing (for TCP). <br> - **Service-point addressing**: Uses port numbers to distinguish which application gets the data. | TCP (reliable), UDP (fast, unreliable)  | The **dispatcher** who ensures the entire truckload of mail is accounted for and notifies the sender if a box is missing. |
| **5** | **Session** | **Data** | - **Session management**: Establishes, maintains, and terminates sessions (dialogues) between applications . <br> - **Synchronization**: Inserts checkpoints to allow recovery from interruptions. | NetBIOS, RPC, SIP  | The **phone call itself**—establishing a call, talking, and hanging up. |
| **6** | **Presentation** | **Data** | - **Translation**: Converts data format (e.g., EBCDIC to ASCII) . <br> - **Encryption/Decryption**: Secures data (e.g., SSL/TLS) . <br> - **Compression**: Reduces data size for transmission. | SSL/TLS, JPEG, ASCII, MPEG  | The **translator** who converts a letter from English to Nepali so the receiver can understand. |
| **7** | **Application** | **Data** / **Message** | - **Network access to applications**: Provides interface for user applications to access network services . <br> - **File transfer, email, web browsing**: Services directly used by the user. | HTTP, FTP, SMTP, DNS, POP3  | You, the **user**, writing the letter and putting it in the mailbox. |

### 1.7 The TCP/IP Protocol suite
- **Overview**: Transmission Control Protocol/Internet Protocol is a practical, protocol-driven model that forms the backbone of the Internet .
- **Developed by**: U.S. Department of Defense (DoD) / DARPA .
- **Layers (4 Layers)** :

| TCP/IP Layer | Corresponding OSI Layers | Core Protocols | Function |
| :--- | :--- | :--- | :--- |
| **4. Application** | Session, Presentation, Application | HTTP, FTP, SMTP, DNS, POP3  | Handles high-level protocols, data representation, and session control. |
| **3. Transport** | Transport | TCP, UDP  | Provides end-to-end data delivery, reliability, and error checking. |
| **2. Internet** | Network | IP (IPv4, IPv6), ICMP, ARP  | Responsible for logical addressing and routing packets across networks. |
| **1. Network Access** (or Link Layer) | Data Link, Physical | Ethernet, Wi-Fi, ARP (partially)  | Handles the physical transmission and hardware interface. |

### 1.8 Comparison between OSI and TCP/IP Reference model

| Feature | OSI Model | TCP/IP Model |
| :--- | :--- | :--- |
| **Number of Layers** | 7 layers | 4 layers  |
| **Development Approach** | Theoretical: Developed first, then protocols were made to fit . | Practical: Protocols were developed first, then the model was built around them . |
| **Developed By** | International Organization for Standardization (ISO) . | U.S. Department of Defense (DARPA) . |
| **Layer Distinction** | Clear distinction between **Service, Interface, and Protocol**. | No clear distinction; protocols are the primary focus. |
| **Protocol Dependency** | Protocols are better hidden; more generic. | Protocols are not hidden; model is highly protocol-dependent. |
| **Upper Layer Format** | **Session & Presentation** layers are separate. | **Application** layer combines all three upper layers (Session, Presentation, Application) . |
| **Lower Layer Format** | Combines Physical & Data Link as separate layers. | Combines Physical & Data Link into one **Network Access** layer . |

### 1.9 Critiques of OSI and TCP/IP Reference model
- **Critiques of the OSI Model** :
    - **Complex and Theoretical**: The model is overly complex and many layers (like Session and Presentation) are rarely implemented in practice. It serves better as a teaching tool .
    - **Poor Timing**: Protocols were developed after the model was defined, leading to them being clumsy and inefficient, which allowed TCP/IP to dominate.
    - **Duplication of Services**: Some services (like error control) appear in multiple layers, leading to overhead.

- **Critiques of the TCP/IP Model** :
    - **Not Generic**: It is highly specific to the TCP/IP protocol suite and cannot describe any other protocol stack .
    - **No Clear Separation**: The **Network Access** layer is not truly a layer in the sense of service/interface; it's just a place to handle anything related to physical connection. It doesn't clearly separate the Physical and Data Link functions .
    - **Muddled Upper Layers**: The **Application** layer is a "junk drawer" that includes everything from data encryption (Presentation) to session establishment, making it less modular than OSI.
