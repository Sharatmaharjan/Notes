# Unit 7: Network Security

## 7.1 A Model for Network Security

### Definition and Concept
- **Network Security**: Process of protecting data and resources during transmission over a network against unauthorized access, misuse, malfunction, modification, destruction, or improper disclosure
- **Purpose**: Ensure confidentiality, integrity, and availability (CIA triad) of data across communication channels

### The Network Security Model

**Components of Security Model**

| Component | Description | Example |
| :--- | :--- | :--- |
| **Sender/Principal** | Entity that initiates communication | User sending email |
| **Receiver/Principal** | Entity for whom communication is intended | Email recipient |
| **Message/Data** | Information being transmitted | Email content |
| **Secure Channel** | Protected communication path | Encrypted connection |
| **Trusted Third Party** | External entity facilitating secure communication | Certificate Authority |
| **Attacker/Adversary** | Entity trying to breach security | Hacker, malicious software |

**Security Process Flow**
1. **Principal (sender)** wants to send secure information to another principal (receiver)
2. **Sender** uses **security-related transformation** (encryption, digital signature) on message
3. **Secure channel** (logical information channel) established using **secret information** (keys)
4. **Trusted third party** may provide additional services (key distribution, certificate issuance)
5. **Receiver** applies inverse transformation to recover original message

### Security Attacks Categories

| Category | Description | Examples |
| :--- | :--- | :--- |
| **Passive Attacks** | Monitoring/ eavesdropping without modifying data | Sniffing, traffic analysis |
| **Active Attacks** | Modification of data stream or creation of false streams | Masquerade, replay, modification, denial of service |

### Security Services (X.800 Standard)

| Service | Description | Mechanism |
| :--- | :--- | :--- |
| **Authentication** | Verify identity of communicating parties | Passwords, certificates |
| **Access Control** | Prevent unauthorized use of resources | ACLs, permissions |
| **Data Confidentiality** | Protect data from unauthorized disclosure | Encryption |
| **Data Integrity** | Ensure data not modified by unauthorized entities | Hash functions, MAC |
| **Non-Repudiation** | Prevent denial of previous actions | Digital signatures |
| **Availability** | Ensure system/services accessible when needed | Redundancy, DoS protection |

### Security Mechanisms

| Mechanism | Purpose | Example |
| :--- | :--- | :--- |
| **Encipherment** | Hide data using mathematical transformation | AES, RSA |
| **Digital Signature** | Append data to prove authorship and integrity | RSA signatures, DSA |
| **Access Control** | Enforce access rights | Firewall rules |
| **Data Integrity** | Detect data modification | Hash functions |
| **Authentication Exchange** | Verify identity | Challenge-response |
| **Traffic Padding** | Insert dummy data to thwart traffic analysis | Random padding |
| **Routing Control** | Select secure paths | Dynamic routing |
| **Notarization** | Use trusted third party | Digital timestamps |

---

## 7.2 Principles of Cryptography: Symmetric Key and Public Key

### 7.2.1 Cryptography Fundamentals

**Definition**: Practice and study of techniques for secure communication in presence of adversaries

**Basic Terminology**

| Term | Definition |
| :--- | :--- |
| **Plaintext** | Original readable message |
| **Ciphertext** | Encrypted unreadable message |
| **Encryption** | Process of converting plaintext → ciphertext |
| **Decryption** | Process of converting ciphertext → plaintext |
| **Key** | Secret parameter controlling encryption/decryption |
| **Cryptanalysis** | Study of breaking cryptographic systems |
| **Cryptology** | Combined study of cryptography and cryptanalysis |

**Kerckhoffs's Principle**: Cryptographic system should be secure even if everything about system (except key) is public knowledge

### 7.2.2 Symmetric Key Cryptography

**Definition**: Same key used for both encryption and decryption (also called secret-key, single-key, or private-key cryptography)

**Components**:
- **Encryption algorithm**: E(K, P) = C
- **Decryption algorithm**: D(K, C) = P
- **Same key K** used for both operations

**How It Works**
```
Sender                               Receiver
   |                                     |
   |---(Plaintext P)                     |
   |       |                              |
   |   Encrypt using K                    |
   |       ↓                              |
   |   Ciphertext C  -------------------> |
   |                                      |
   |                                  Decrypt using K
   |                                      ↓
   |                               (Plaintext P)
```

**Types of Symmetric Ciphers**

| Type | Description | Examples |
| :--- | :--- | :--- |
| **Stream Ciphers** | Encrypt one bit/byte at a time | RC4, ChaCha20 |
| **Block Ciphers** | Encrypt fixed-size blocks | AES, DES, 3DES |

**Block Cipher Modes**

| Mode | Description | Use Case |
| :--- | :--- | :--- |
| **ECB (Electronic Code Book)** | Each block encrypted independently | Simple, insecure for patterns |
| **CBC (Cipher Block Chaining)** | Each block XORed with previous ciphertext | General purpose encryption |
| **CTR (Counter)** | Block cipher as stream cipher | Parallel encryption |
| **GCM (Galois/Counter Mode)** | Encryption + authentication | High-performance secure comms |

**Advantages of Symmetric Key**
- **Fast**: Much faster than asymmetric encryption
- **Efficient**: Less computational overhead
- **Strong security**: With large keys (AES-256 considered quantum-resistant)
- **Hardware acceleration**: AES-NI instructions in modern CPUs

**Disadvantages**
- **Key distribution problem**: Both parties need same key securely
- **Scalability issues**: n parties need n(n-1)/2 keys
- **No non-repudiation**: Key shared, cannot prove origin
- **No digital signatures**: Not suitable for authentication

**Real-world examples**: AES-256 for disk encryption, file encryption (WinRAR, 7-Zip), Wi-Fi encryption (WPA2/WPA3)

### 7.2.3 Public Key (Asymmetric) Cryptography

**Definition**: Uses two mathematically related keys - public key (widely distributed) and private key (kept secret)

**Concept** (Diffie-Hellman, 1976):
- **Public key (KU)** : Used for encryption, verifies signatures
- **Private key (KR)** : Used for decryption, creates signatures

**Properties**:
- Computationally infeasible to derive private key from public key
- Either key can decrypt what other encrypts

**How It Works (Confidentiality)**
```
Sender                               Receiver
  |                                     |
  |---(Plaintext P)                     |
  |       |                              |
  |   Encrypt using KU_receiver          |
  |       ↓                              |
  |   Ciphertext C  -------------------> |
  |                                      |
  |                                  Decrypt using KR_receiver
  |                                      ↓
  |                               (Plaintext P)
```

**How It Works (Authentication)**
```
Sender                               Receiver
  |                                     |
  |---(Plaintext P)                     |
  |       |                              |
  |   Encrypt using KR_sender            |
  |       ↓                              |
  |   Ciphertext C  -------------------> |
  |                                      |
  |                                  Decrypt using KU_sender
  |                                      ↓
  |                               (Plaintext P)
  |                              (Authenticates sender)
```

**Common Algorithms**

| Algorithm | Year | Key Size | Security Basis | Use |
| :--- | :--- | :--- | :--- | :--- |
| **RSA** | 1977 | 2048-4096 bits | Integer factorization | Encryption, signatures |
| **Diffie-Hellman** | 1976 | 2048-4096 bits | Discrete logarithm | Key exchange |
| **ECC (Elliptic Curve)** | 1985 | 256-521 bits | Elliptic curve discrete log | Encryption, signatures |
| **EdDSA (Edwards-curve)** | 2011 | 256-456 bits | Elliptic curve | Signatures (modern) |

**Advantages**
- **Solves key distribution**: Public keys can be shared openly
- **Scalability**: n parties need n key pairs only
- **Digital signatures**: Provides non-repudiation
- **Key exchange**: Establish shared secret over insecure channel

**Disadvantages**
- **Slow**: 100-1000× slower than symmetric
- **Large keys**: 2048-bit RSA vs 128-bit AES (equivalent security)
- **Computationally expensive**: Not suitable for bulk encryption
- **Vulnerable to quantum attacks**: Shor's algorithm breaks RSA/ECC

**Real-world examples**: HTTPS/SSL/TLS (handshake), SSH authentication, PGP/GPG email encryption, Digital certificates

### 7.2.4 Hybrid Cryptography (Best of Both)

**Approach**: Combine symmetric and asymmetric to leverage advantages

**How It Works** (TLS/SSL Example):
1. **Key exchange** (asymmetric): Client and server use public-key cryptography to agree on shared session key
2. **Bulk encryption** (symmetric): All actual data encrypted with session key (AES)
3. **Integrity** (hash/MAC): Message authentication codes ensure data not tampered

**Real-world example**: Every HTTPS connection uses this hybrid approach

### 7.2.5 Comparison: Symmetric vs Asymmetric

| Feature | Symmetric Key | Asymmetric Key |
| :--- | :--- | :--- |
| **Keys** | Single shared key | Key pair (public + private) |
| **Key distribution** | Major problem | Solved (public keys shareable) |
| **Number of keys** | n(n-1)/2 for n users | n pairs for n users |
| **Speed** | Very fast (hardware accelerated) | Slow (100-1000× slower) |
| **Algorithm examples** | AES, DES, ChaCha20 | RSA, ECC, Diffie-Hellman |
| **Security basis** | Substitution-permutation | Mathematical problems |
| **Key size (equiv)** | 128 bits | 3072 bits (RSA) |
| **Use cases** | Bulk encryption, file encryption | Key exchange, signatures |
| **Quantum resistant** | Yes (with large keys) | No (RSA/ECC broken by Shor's) |

---

## 7.3 Public Key Algorithm — RSA

### Overview
- **Name**: Rivest-Shamir-Adleman (inventors Ron Rivest, Adi Shamir, Leonard Adleman, 1977)
- **Type**: Public-key cryptosystem for encryption and digital signatures
- **Security basis**: Difficulty of factoring large composite numbers

### RSA Key Generation

**Step-by-Step Process**

| Step | Mathematical Operation | Example |
| :--- | :--- | :--- |
| **1. Choose primes** | Select two large prime numbers p and q | p=17, q=11 |
| **2. Compute n** | n = p × q | n = 17×11 = 187 |
| **3. Compute φ(n)** | φ(n) = (p-1)(q-1) | φ(187) = 16×10 = 160 |
| **4. Choose e** | 1 < e < φ(n), gcd(e, φ(n)) = 1 | e = 7 (coprime with 160) |
| **5. Compute d** | d ≡ e⁻¹ mod φ(n) (modular inverse) | 7×23 = 161 ≡ 1 mod 160, so d=23 |

**Key Pair**:
- **Public key**: (n, e) = (187, 7)
- **Private key**: (n, d) = (187, 23)

### RSA Encryption and Decryption

**Encryption** (using public key):
- Formula: C = P^e mod n
- Where P = plaintext (must be < n)
- Example: P=88 → C = 88⁷ mod 187 = 11

**Decryption** (using private key):
- Formula: P = C^d mod n
- Example: C=11 → P = 11²³ mod 187 = 88

### RSA Digital Signature

**Signing** (using private key):
- S = M^d mod n (where M is message hash)

**Verification** (using public key):
- M' = S^e mod n
- If M' = M, signature valid

### Security Considerations

**Key Size Recommendations** (NIST SP 800-57):

| Security Level | RSA Key Size | Validity |
| :--- | :--- | :--- |
| **Legacy (80-bit)** | 1024 bits | Deprecated (broken) |
| **Medium-term (112-bit)** | 2048 bits | Acceptable until 2030 |
| **Long-term (128-bit)** | 3072 bits | Recommended |
| **Very strong (256-bit)** | 15360 bits | Future-proof |

**Attacks on RSA**

| Attack Type | Description | Mitigation |
| :--- | :--- | :--- |
| **Factoring** | Factor n to find p,q → compute d | Large keys (2048+ bits) |
| **Timing attacks** | Measure decryption time variations | Constant-time algorithms |
| **Chosen ciphertext** | Exploit multiplicative property | OAEP padding |
| **Small e attacks** | If e small and message short | Proper padding |
| **Common modulus** | Sharing n dangerous | Never share n |

**Padding Schemes** (Essential for security)
- **PKCS#1 v1.5**: Historical, some weaknesses
- **OAEP (Optimal Asymmetric Encryption Padding)** : Recommended for encryption
- **PSS (Probabilistic Signature Scheme)** : Recommended for signatures

### Advantages and Disadvantages

**Advantages**
- **Widely adopted**: Industry standard, extensive support
- **Proven security**: Extensively analyzed since 1977
- **Both encryption and signatures**: Single algorithm for both
- **Relatively simple**: Mathematically straightforward

**Disadvantages**
- **Slow**: Much slower than ECC for equivalent security
- **Large keys**: 3072-bit RSA vs 256-bit ECC (same security)
- **Vulnerable to quantum computing**: Shor's algorithm breaks RSA completely
- **Padding required**: Must be implemented correctly

**Real-world examples**: SSL/TLS certificates, PGP/GPG, SSH (legacy), secure email

---

## 7.4 Digital Signature Algorithm

### Overview
- **Definition**: Mathematical scheme for demonstrating authenticity of digital messages or documents
- **Purpose**: Provide authentication, non-repudiation, and integrity

**NIST Digital Signature Standard (FIPS 186-5)** :
- Specifies approved digital signature algorithms
- Current version: FIPS 186-5 (February 2023)
- Supersedes previous versions, removes DSA for generation (verification only)

### Digital Signature Properties

| Property | Description |
| :--- | :--- |
| **Authentication** | Verifies identity of signer |
| **Non-repudiation** | Signer cannot deny signing |
| **Integrity** | Detects any modification after signing |
| **Unforgeability** | Only signer can create valid signature |

### How Digital Signatures Work

**Signing Process**:
1. Message → Hash function → Message digest (fixed length)
2. Digest encrypted with **signer's private key** → Digital signature
3. Message + signature transmitted to receiver

**Verification Process**:
1. Receiver computes hash of received message
2. Decrypts signature using **signer's public key** → original digest
3. If digests match → signature valid

```
Signer (Private Key)                 Verifier (Public Key)
       |                                      |
   Message                                   Message
       |                                      |
   Hash function                           Hash function
       |                                      |
   Message digest ←---[transmitted]---→ Message digest
       |                                      |
 Encrypt with private                        Compare
       |                                      |
   Signature  → → → → → → → → → → → →   Yes/No
```

### Digital Signature Algorithms (FIPS 186-5) 

**A. RSA (Rivest-Shamir-Adleman)**

| Feature | Description |
| :--- | :--- |
| **Key sizes** | 2048, 3072, 4096 bits |
| **Hash functions** | SHA-256, SHA-384, SHA-512 |
| **Padding** | PSS (Probabilistic Signature Scheme) |
| **Performance** | Verification fast, signing moderate |

**B. ECDSA (Elliptic Curve Digital Signature Algorithm)**

| Feature | Description |
| :--- | :--- |
| **Key sizes** | 256-521 bits (smaller than RSA) |
| **Curves** | P-256, P-384, P-521 (NIST curves) |
| **Performance** | Faster key generation, smaller signatures |
| **Use case** | Mobile devices, resource-constrained |

**C. EdDSA (Edwards-curve Digital Signature Algorithm)**

| Feature | Description |
| :--- | :--- |
| **Curves** | Ed25519 (255-bit), Ed448 (448-bit) |
| **Advantages** | Fast, constant-time (no side channels) |
| **Deterministic** | No random number needed |
| **Standard** | RFC 8032, FIPS 186-5 |
| **Use case** | Modern applications, crypto libraries |

### Post-Quantum Digital Signatures (NIST) 

**New Standards (August 2024)** :

| Standard | Algorithm | Basis | Signature Size |
| :--- | :--- | :--- | :--- |
| **FIPS 204** | ML-DSA (CRYSTALS-Dilithium) | Lattice-based | ~2.5 KB |
| **FIPS 205** | SLH-DSA (SPHINCS+) | Hash-based | ~8-17 KB |
| **FIPS 206** (planned) | FALCON | Lattice-based | ~0.7 KB |

**Why Post-Quantum?**
- RSA, ECDSA, EdDSA vulnerable to Shor's algorithm (quantum computers)
- NIST standardization complete 2024 
- Transition recommended for long-term security

### Hash Functions Used in Digital Signatures

| Algorithm | Output Size | Status |
| :--- | :--- | :--- |
| **SHA-1** | 160 bits | Broken, deprecated |
| **SHA-256** | 256 bits | Recommended |
| **SHA-384** | 384 bits | Recommended |
| **SHA-512** | 512 bits | Recommended |
| **SHA3-256** | 256 bits | Approved |

### Real-world Applications

| Application | Algorithm Used | Purpose |
| :--- | :--- | :--- |
| **SSL/TLS certificates** | RSA, ECDSA | Authenticate websites |
| **Code signing** | RSA, EdDSA | Verify software integrity |
| **Email (S/MIME, PGP)** | RSA, ECDSA | Authenticate sender |
| **Blockchain/Cryptocurrency** | ECDSA (Bitcoin), EdDSA (some) | Transaction authentication |
| **Document signing (PDF)** | RSA, DSA | Legal documents |
| **UEFI Secure Boot** | RSA | Verify bootloaders |

### Advantages and Disadvantages

**Advantages**
- **Legally binding**: Recognized in many jurisdictions (e-signature laws)
- **Non-repudiation**: Cryptographically proven
- **Scalable**: Works globally with PKI
- **Verifiable**: Anyone with public key can verify

**Disadvantages**
- **Key management**: Must protect private keys
- **Certificate revocation**: Complex infrastructure
- **Quantum vulnerability**: Most current algorithms vulnerable
- **Computational cost**: More expensive than MACs

---

## 7.5 Communication Security: IPSec, VPN, Firewalls, Wireless Security

### 7.5.1 IPSec (IP Security)

**Overview**
- **Definition**: Suite of protocols providing security at IP layer 
- **Standard**: RFC 4301 (Security Architecture for Internet Protocol) 
- **Purpose**: Authentication, confidentiality, integrity for IP packets
- **Maturity**: Designed for both IPv4 and IPv6

**IPsec Services** 
- **Access control**: Prevent unauthorized access
- **Connectionless integrity**: Detect packet modification
- **Data origin authentication**: Verify sender
- **Confidentiality**: Encryption
- **Replay protection**: Sequence numbers
- **Traffic flow confidentiality**: Limited (pad packets)

**IPsec Components** 

| Component | Description |
| :--- | :--- |
| **Security Protocols** | AH (Authentication Header), ESP (Encapsulating Security Payload) |
| **Security Associations (SA)** | One-way logical connection with security parameters |
| **Key Management** | IKE (Internet Key Exchange) - manual or automated |
| **Databases** | SPD (Security Policy Database), SAD (SA Database), PAD (Peer Authorization Database) |

**Security Protocols**

| Feature | AH (Authentication Header) | ESP (Encapsulating Security Payload) |
| :--- | :--- | :--- |
| **RFC** | RFC 4302 | RFC 4303 |
| **Authentication** | Yes | Yes |
| **Confidentiality** | No | Yes |
| **Integrity** | Yes (entire packet) | Yes (ESP payload) |
| **NAT traversal** | No (breaks) | Yes |
| **IPsec implementations** | MAY support | MUST support  |

**IPsec Modes**

| Mode | Description | Use Case |
| :--- | :--- | :--- |
| **Transport Mode** | Protects only payload (original IP header untouched) | Host-to-host communication |
| **Tunnel Mode** | Protects entire IP packet, adds new IP header | Gateway-to-gateway (VPN) |

**Security Association (SA)** 
- **One-way**: Separate SA for each direction
- **Parameters**: SPI (Security Parameter Index), IP destination, protocol
- **Databases**: SAD stores SA parameters, SPD defines policy
- **Management**: IKEv2 for automated key management 

### 7.5.2 VPN (Virtual Private Network)

**Overview**
- **Definition**: Extends private network across public network, enabling secure data transmission 
- **Purpose**: Privacy, security, access blocked content, remote access 

**VPN Characteristics** 
- **Encrypted connection**: Data protected through tunneling protocols
- **Private channel**: Uses IP addressing not allocated to organizations
- **Tunneling**: Encapsulate packets in other packets

**VPN Types** 

| Type | Description | Use Case |
| :--- | :--- | :--- |
| **Remote Access VPN** | Individual users connect to network | Teleworkers, mobile employees |
| **Site-to-Site VPN** | Connect entire networks | Branch offices to HQ |

**VPN Protocols Comparison** 

| Protocol | Security | Speed | Best For |
| :--- | :--- | :--- | :--- |
| **L2TP/IPSec** | Highest | Moderate | Secure, stable connections |
| **SSTP** | High | Moderate | Windows environments |
| **PPTP** | Low (vulnerable) | Fastest | Legacy, non-sensitive (avoid) |
| **IPsec IKEv2** | High | Fast | Mobile devices (roaming) |
| **OpenVPN** | High | Moderate | Cross-platform, open-source |

**Research Findings (2025)** :
- **L2TP/IPSec**: Delivers best QoS and security performance
- **SSTP**: Second best overall
- **PPTP**: Faster but more vulnerable to sniffing
- **Recommendation**: L2TP/IPSec optimal for secure, stable, fast connections

**Advanced VPN Technologies** 

| Technology | Description | Advantage |
| :--- | :--- | :--- |
| **DMVPN (Dynamic Multipoint VPN)** | Dynamic tunnel establishment | Scalability, hub-and-spoke |
| **FlexVPN** | Cisco's unified VPN framework | Flexibility, multiple deployment options |
| **Single Hub** | Central concentrator | Simple management |
| **Dual Hub** | Redundant concentrators | Fault tolerance |

**VPN Routing Protocols** 
- **RIP**: Simple, small networks
- **OSPF**: Scalable, enterprise
- **EIGRP**: Cisco environments

### 7.5.3 Firewalls

**Overview**
- **Definition**: Network security device monitoring and controlling traffic based on predetermined rules
- **Purpose**: Establish barrier between trusted internal and untrusted external networks

**Types of Firewalls**

| Type | Layer | Description | Example |
| :--- | :--- | :--- | :--- |
| **Packet Filtering** | Network (3) | Inspects packets individually, filters based on IP/port | ACLs on routers |
| **Stateful Inspection** | Transport (4) | Tracks connection state, makes decisions based on context | Checkpoint, modern firewalls |
| **Application Gateway (Proxy)** | Application (7) | Intermediary for specific applications | Web proxy, mail gateway |
| **Next-Generation Firewall (NGFW)** | 3-7 | Deep packet inspection, IDS/IPS, application awareness | Palo Alto, Fortinet |

**Firewall Rules Components**
- **Source IP address**
- **Destination IP address**
- **Protocol** (TCP, UDP, ICMP)
- **Source port**
- **Destination port**
- **Action** (ALLOW, DENY, REJECT)
- **Logging** (enabled/disabled)

**Firewall Architectures**

| Architecture | Description | Security Level |
| :--- | :--- | :--- |
| **Single-tier** | Single firewall between networks | Basic |
| **DMZ (Demilitarized Zone)** | Separate network for public servers | Moderate |
| **Multi-tier** | Multiple firewalls, segmented networks | High |

### 7.5.4 Wireless Security

**Wireless Security Evolution**

| Standard | Year | Security Level | Status |
| :--- | :--- | :--- | :--- |
| **WEP** | 1997 | Broken (cracked in minutes) | Deprecated |
| **WPA** | 2003 | Weak (TKIP vulnerabilities) | Deprecated |
| **WPA2** | 2004 | Strong (AES) | Current minimum |
| **WPA3** | 2018 | Very Strong (SAE, 192-bit mode) | Recommended |

**Wi-Fi Encryption Standards** 

| Feature | WPA2 (AES) | WPA3 Personal |
| :--- | :--- | :--- |
| **Encryption** | AES-CCMP | AES-GCMP |
| **Key exchange** | 4-way handshake | SAE (Simultaneous Authentication of Equals) |
| **Offline dictionary attacks** | Vulnerable | Protected |
| **Forward secrecy** | No | Yes |
| **Management frame protection** | Optional | Mandatory |

**Essential Wireless Security Practices** 

| Setting | Recommended Configuration |
| :--- | :--- |
| **Encryption** | WPA3 Personal or WPA2 AES (never WEP, WPA, WPA2 TKIP) |
| **Wi-Fi password** | Long passphrase (5-7 unrelated words, ≥16 characters) |
| **SSID** | Change default, avoid personal information |
| **Router login** | Change default username/password |
| **Remote management** | Disable |
| **WPS (Wi-Fi Protected Setup)** | Disable |
| **UPnP (Universal Plug and Play)** | Disable (enable only temporarily if needed) |
| **Guest network** | Enable for visitors and IoT devices |
| **Firmware** | Regular updates (automatic if available) |

**IoT Device Segmentation** 
- Connect smart home/IoT devices to **Guest Wi-Fi**
- Prevents IoT devices from discovering other devices on main network
- Protects against IoT vulnerabilities spreading to critical devices

**Wireless Security Threats**

| Threat | Description | Mitigation |
| :--- | :--- | :--- |
| **Evil Twin** | Fake AP mimicking legitimate network | Verify certificates, use VPN |
| **Rogue AP** | Unauthorized AP on network | Wireless intrusion detection |
| **De-authentication attack** | Forcibly disconnect clients | WPA3 (protected mgmt frames) |
| **KRACK** | Key reinstallation attack | Patch clients, use WPA3 |
| **Dictionary attack** | Guess weak passwords | Strong passphrase, WPA3 SAE |

---

## Summary Table: Network Security Components

| Component | Purpose | Key Technology | Layer |
| :--- | :--- | :--- | :--- |
| **Cryptography** | Hide data, verify origin | AES, RSA, ECC | Application/Presentation |
| **Digital Signatures** | Authentication, non-repudiation | RSA, ECDSA, EdDSA | Application |
| **IPSec** | IP-layer security | AH, ESP, IKE | Network |
| **VPN** | Secure tunnel over public net | L2TP/IPSec, OpenVPN | Network/Transport |
| **Firewall** | Traffic filtering | Packet filter, stateful | Network-Application |
| **Wireless Security** | Protect Wi-Fi networks | WPA2, WPA3 | Data Link/Physical |
