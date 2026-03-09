# Unit 2: Cyberattacks, Cybersecurity, and Cyber Law (12 Hrs.)


#### 1. Threat Landscape — Computer Incidents & Types of Exploits

- **Threat Landscape:** The collective set of potential and actual cybersecurity threats (threat actors, attack vectors, vulnerabilities) that an organization or individual faces at a given time. It is constantly evolving.
- **Computer Incident vs. Cyberattack:**
    - **Computer Incident:** An event that actually or potentially jeopardizes the confidentiality, integrity, or availability of an information system or the information it processes . It's a broader term covering any adverse event (e.g., a system crash due to a power outage, an unintentional data leak by an employee).
    - **Cyberattack:** A specific type of incident that is **malicious and intentional**. It is a deliberate act by an attacker to destroy, disclose, alter, disable, steal, or gain unauthorized access to or use of an asset . **All cyberattacks are incidents, but not all incidents are cyberattacks.**
- **Types of Exploits (Common Cyber Threats):** An exploit is a piece of code or technique that takes advantage of a software vulnerability to cause unintended behavior.
    - **Drive-by Exploits:** Malicious code injected into legitimate websites. When a user visits the site, the code automatically scans for and exploits vulnerabilities in their browser or plugins (e.g., Java, Flash) to install malware without any user interaction .
    - **Malware (Worms/Trojans):**
        - **Worms:** Self-replicating malware that spreads across networks without human interaction.
        - **Trojans:** Malware disguised as legitimate software. Once executed, it can perform malicious actions like stealing data, creating backdoors, or downloading other malware .
    - **Code Injection Attacks:** Exploits that inject malicious code into an application to alter its execution.
        - **SQL Injection (SQLi):** Injecting SQL commands into input fields (e.g., a login form) to manipulate a database, often to bypass authentication or steal data.
        - **Cross-Site Scripting (XSS):** Injecting malicious scripts into a trusted website, which are then executed in other users' browsers to steal session cookies or deface websites .
    - **Phishing:** Fraudulent attempts (usually via email or fake websites) to trick individuals into revealing sensitive information like usernames, passwords, or credit card details .
    - **Denial of Service (DoS) / Distributed Denial of Service (DDoS):** Overwhelming a system, server, or network with traffic to make it unavailable to legitimate users .
    - **Ransomware:** A type of malware that encrypts a victim's files and demands a ransom payment for the decryption key.
    - **Exploitation of Public-Facing Applications & Remote Services:** Attackers directly targeting vulnerabilities in web servers, email servers, or remote access protocols (like RDP) to gain initial access to a network .
    - **Privilege Escalation:** Exploiting a vulnerability to gain higher-level permissions (like administrator or root access) on a system after initially compromising a low-privilege account .
- **Threat Actors (Who and Why):**
    - **Cybercriminals:** Motivated by financial gain.
    - **Nation-States:** Motivated by political, military, or economic espionage and disruption.
    - **Hacktivists:** Motivated by social or political causes; their goal is often to deface websites or leak information to promote their agenda.
    - **Insiders (Employees):** Can be malicious (disgruntled employees) or accidental (careless employees). They have inside knowledge and access .
    - **Terrorists:** Motivated by ideology to cause widespread disruption, fear, and physical damage, often targeting critical infrastructure .

---

#### 2. CIA Security Triad

- **Definition:** The CIA Triad is a foundational model used to guide information security policies within an organization. It stands for **Confidentiality, Integrity, and Availability** .
- **1. Confidentiality:**
    - **Definition:** Ensuring that information is accessible only to those authorized to have access. It's about preventing unauthorized disclosure .
    - **Real-World Example:** Only you and your bank should have access to your bank account balance and transaction history. A breach of confidentiality would be a hacker stealing this data.
    - **How to Implement:**
        - **Encryption:** Encrypting data at rest (on hard drives) and in transit (over networks) .
        - **Access Controls:** Implementing strong authentication (e.g., passwords, biometrics) and authorization (e.g., Role-Based Access Control - RBAC) to ensure only the right people can view data .
        - **Data Classification:** Labeling data (e.g., Public, Internal, Confidential, Secret) to dictate handling procedures.
- **2. Integrity:**
    - **Definition:** Ensuring the accuracy, consistency, and trustworthiness of data over its entire lifecycle. Data must not be altered in an unauthorized or undetected manner .
    - **Real-World Example:** When you transfer Rs. 1,000 from your savings to your current account, the transaction must be processed correctly. A breach of integrity would be if the system deducted Rs. 1,000 from savings but only added Rs. 900 to the current account, or if someone altered the transaction amount.
    - **How to Implement:**
        - **Hashing/Checksums:** Using cryptographic hash functions (like SHA-256) to verify that a file or data hasn't been tampered with .
        - **Audit Logs:** Keeping detailed logs of who accessed or modified data and when.
        - **Version Control:** Tracking changes to documents or code, allowing for rollback to previous correct versions.
        - **Input Validation:** Ensuring that data entered into a system meets predefined rules to prevent corruption.
- **3. Availability:**
    - **Definition:** Ensuring that information and resources are accessible to authorized users when needed. It guarantees reliable and timely access .
    - **Real-World Example:** An e-commerce website like Daraz must be up and running, especially during sales like "11.11." A breach of availability is a DDoS attack that takes the site offline, preventing customers from shopping.
    - **How to Implement:**
        - **Redundancy:** Using redundant servers, network paths, and power supplies to ensure no single point of failure.
        - **Disaster Recovery Plans (DRP):** Having a documented plan to restore IT systems and data after a disruptive event (e.g., natural disaster, major cyberattack).
        - **Failover Clusters:** Automatically switching to a backup system if the primary system fails.
        - **Regular Backups:** Creating and safely storing backups of critical data so it can be restored if lost or corrupted.

---

#### 3. Implementing CIA at Different Levels

- **At the Organizational Level:**
    - **Confidentiality:** Develop and enforce a comprehensive security policy, conduct background checks on employees, and sign Non-Disclosure Agreements (NDAs). Implement role-based access control (RBAC) across all departments.
    - **Integrity:** Establish change management processes to ensure all system changes are approved and logged. Conduct regular security awareness training to prevent unintentional data alteration by employees.
    - **Availability:** Develop a Business Continuity Plan (BCP) and Disaster Recovery Plan (DRP). Invest in robust physical security (e.g., backup power generators, secure data centers).
- **At the Network Level:**
    - **Confidentiality:** Use encryption protocols like TLS/SSL for data in transit (HTTPS). Implement Virtual Private Networks (VPNs) for remote access. Use network segmentation and firewalls to isolate sensitive data .
    - **Integrity:** Use digital signatures and message authentication codes (MACs) to ensure data isn't altered during transmission. Implement Intrusion Detection/Prevention Systems (IDS/IPS) to detect and block tampering attempts .
    - **Availability:** Use redundant network links and load balancers to distribute traffic and prevent overload. Implement DDoS mitigation tools and services. Set up firewalls with rules to prevent network floods.
- **At the Application Level:**
    - **Confidentiality:** Implement strong authentication and session management. Encrypt sensitive data stored in application databases. Apply the principle of least privilege to application users.
    - **Integrity:** Validate all user inputs on both client and server sides to prevent code injection. Use parameterized queries to prevent SQL injection. Implement application logging to track all critical transactions.
    - **Availability:** Design applications to scale horizontally (adding more servers). Use rate limiting to prevent a single user from overwhelming the application. Set up application-level monitoring and alerts for downtime .
- **At the End-User Level:**
    - **Confidentiality:** Enforce strong, unique passwords and/or multi-factor authentication (MFA). Educate users about phishing and social engineering. Ensure devices are encrypted.
    - **Integrity:** Keep operating systems and applications patched and updated. Use host-based firewalls and endpoint protection software. Educate users to only download software from official sources.
    - **Availability:** Educate users on how to report issues. Ensure they have offline access to critical data where feasible (e.g., cached emails). Provide clear instructions on what to do if their device is lost or stolen.

---

#### 4. Response to Cyber Attack (Incident Response Phases)

A structured approach to handle security incidents, aiming to minimize damage and recovery time.

1.  **Incident Notification & Detection:** The first phase where an incident is identified.
    - **Sources:** Alerts from IDS/IPS, antivirus software, firewalls; reports from users; unusual system behavior; threat intelligence feeds.
    - **Goal:** To quickly and accurately determine that an incident has occurred and gather initial information.

2.  **Protection of Evidence and Activity Logs:** Crucial for legal proceedings and internal root cause analysis.
    - **Actions:** Immediately create forensic images (bit-for-bit copies) of affected systems, preserving the original as evidence. Securely preserve all relevant logs (firewall, server, application, authentication). Establish a clear **chain of custody** to document who handled the evidence, when, and for what purpose.

3.  **Incident Containment:** The priority is to stop the incident from spreading and causing further damage.
    - **Short-Term Containment:** Isolate the affected system by disconnecting it from the network. Block the attacker's IP address at the firewall.
    - **Long-Term Containment:** Apply temporary fixes or workarounds to allow unaffected systems to continue operating safely while a permanent fix is developed.

4.  **Eradication:** Removing the threat from the environment.
    - **Actions:** Remove malware from affected systems. Disable compromised user accounts. Patch vulnerabilities that were exploited. Rebuild compromised systems from a clean, known-good backup.

5.  **Incident Follow-Up (Recovery & Lessons Learned):**
    - **Recovery:** Carefully and methodically restore systems and data back into the production environment. Monitor restored systems closely for any signs of recurring weakness or abnormal behavior.
    - **Post-Incident Activity (Lessons Learned):** Conduct a formal review meeting with all involved parties. Create a final incident report detailing the timeline, root cause, impact, and effectiveness of the response. Update the incident response plan, security policies, and training based on the lessons learned.

---

#### 5. Using an MSSP (Managed Security Service Provider)

- **Definition:** An MSSP is a third-party company that remotely manages and monitors an organization's security systems and devices 24/7 .
- **Why use an MSSP?** Many organizations lack the in-house expertise, budget, or resources to run a full-scale Security Operations Center (SOC) themselves.
- **Key Services Provided by an MSSP :**
    - **24/7 Monitoring:** Continuous monitoring of firewalls, intrusion detection systems, servers, and endpoints.
    - **Vulnerability Scanning & Management:** Regularly scanning the organization's network for weaknesses and helping prioritize patches.
    - **Incident Response:** Providing expert analysis and remediation support when an incident occurs.
    - **Threat Intelligence:** Keeping the client informed about the latest threats relevant to their industry.
    - **Log Management & Analysis:** Aggregating and analyzing security logs from various sources to identify patterns and anomalies.
    - **Compliance Reporting:** Helping organizations generate reports needed to prove compliance with regulations (like PCI-DSS).
- **Advantages of Using an MSSP:**
    - **Cost-Effective:** Cheaper than building and staffing an in-house SOC.
    - **Access to Expertise:** Provides access to a wide range of specialized security skills.
    - **24/7 Coverage:** Ensures continuous monitoring and faster response times.
    - **Advanced Technology:** MSSPs invest in top-tier security tools that might be too expensive for a single organization.
- **Disadvantages of Using an MSSP:**
    - **Loss of Control:** The organization cedes some direct control over its security operations.
    - **Vendor Lock-in:** Switching providers can be complex and costly.
    - **Communication Challenges:** Potential for delays or miscommunication, especially during a crisis.
    - **Data Privacy Concerns:** Sharing sensitive log and security data with a third party.

---

#### 6. Computer Forensics

- **Definition:** The practice of identifying, preserving, analyzing, and presenting digital evidence in a manner that is legally acceptable. It's the "CSI" for cyber incidents.
- **Primary Goal:** To determine the root cause of a security incident, gather evidence for legal action, and recover lost or deleted data.
- **Key Steps in Computer Forensics:**
    1.  **Identification:** Locating and recognizing potential sources of evidence (e.g., hard drives, RAM, network logs, cloud storage).
    2.  **Preservation:** Isolating and securing the evidence to prevent tampering. This is where creating a forensic image and establishing chain of custody are critical.
    3.  **Analysis:** Examining the preserved evidence using forensic tools to find relevant information like deleted files, attacker activity, timelines, and malware.
    4.  **Documentation:** Creating a detailed record of all findings, techniques used, and actions taken. The goal is to create a clear and repeatable report.
    5.  **Presentation:** Presenting the findings in a clear, concise, and non-technical manner, often to a court, board of directors, or law enforcement.

---

#### 7. Cyber Law

- **Definition:** The area of law that deals with the Internet, cyberspace, and related legal issues. It encompasses the legal, regulatory, and ethical aspects of using computers and networks.
- **Scope of Cyber Law:**
    - **Cybercrimes:** Laws against hacking, fraud, data theft, identity theft, cyber terrorism, etc.
    - **Electronic Commerce (E-Commerce):** Laws governing online contracts, digital signatures, and consumer protection in online transactions.
    - **Intellectual Property (IP) in Cyberspace:** Laws related to copyright, patent, trademark, and domain names on the internet.
    - **Data Protection and Privacy:** Laws governing the collection, use, storage, and disclosure of personal data.

---

#### 8. Provision of Cyber Law and Electronic Transaction Act of Nepal

- **Primary Legislation:** The **Electronic Transactions Act (ETA), 2063 (2008)** is the cornerstone of cyber law in Nepal . It was enacted to provide legal recognition to electronic transactions and to punish cybercrimes.
- **Key Provisions of the ETA 2063:**
    - **Legal Recognition of Electronic Records:** It gives legal validity to any information or record generated in digital form .
    - **Legal Recognition of Digital Signatures:** It establishes a framework for digital signatures, making them legally binding and equivalent to handwritten signatures .
    - **Cyber Offenses and Penalties:** The Act defines a range of computer-related crimes and prescribes punishments .
        - **Unauthorized Access (Hacking):** Accessing a computer program or data without authorization. Punishment: Imprisonment up to 3 years and/or a fine up to NPR 200,000.
        - **Damage to Computer System:** Illegally destroying, altering, or deleting information. Punishment: Imprisonment up to 3 years and/or a fine up to NPR 200,000.
        - **Publication of Illegal Material:** Publishing or displaying obscene material in electronic form. Punishment: Imprisonment up to 5 years and/or a fine up to NPR 100,000.
        - **Confidentiality & Privacy Breach:** Disclosing personal information about another person without their consent. Punishment: Imprisonment up to 1 year and/or a fine up to NPR 50,000.
    - **Cyber Crime Investigation:** It empowers the Nepal Police's **Cyber Bureau** to investigate cybercrimes .
- **Recent Developments and Complementary Laws :**
    - **Cyber Security Bye-Law 2077 (2020):** Issued by the Nepal Telecommunications Authority (NTA). It mandates that telecom and internet service providers conduct regular security audits, establish Security Operation Centers (SOCs), and implement data protection measures.
    - **Individual Privacy Act 2018:** This act further strengthens data protection by outlining principles for the collection, use, and protection of personal information.
    - **Proposed Information Technology and Cyber Security Bill 2080 (2024):** A new comprehensive bill is under discussion to replace the ETA and create a more modern legal framework. It proposes provisions like licensing for IT and cybersecurity service providers, and rules for data centers and cloud services.
