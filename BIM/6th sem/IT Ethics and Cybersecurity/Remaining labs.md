## **1. Phishing Simulation Using Social Engineering Toolkit (SET) on Windows**

### **Objective:**  
Simulate a phishing attack using the Social Engineering Toolkit (SET) on Windows.

### **Tools Required:**  
- **Kali Linux (as a virtual machine on Windows)** using VirtualBox/VMware  
- **Social Engineering Toolkit (SET)** (pre-installed in Kali)  
- Target Windows machine  
- Internet connection  

### **Steps:**  

1. **Install Kali Linux on VirtualBox:**  
   - Download and install [VirtualBox](https://www.virtualbox.org/).  
   - Install Kali Linux from [Kali.org](https://www.kali.org/downloads/).  

2. **Launch SET on Kali:**  
   Open the Kali Linux terminal and run:  
   ```bash
   sudo setoolkit
   ```

3. **Select Attack Type:**  
   - Choose option `1` (Social-Engineering Attacks).  
   - Select option `2` (Website Attack Vectors).  

4. **Clone Website:**  
   - Select option `3` (Credential Harvester Attack).  
   - Choose option `2` (Site Cloner).  
   - Enter the target website URL (e.g., `https://outlook.com`).  
   - Provide the IP address of the Kali machine (use `ip a` to check).  

5. **Send Phishing Link to Windows Machine:**  
   - Send the generated link via email or chat.  

6. **Capture Credentials:**  
   - Once the target enters login details, they will be saved in:  
     ```bash
     /var/www/html/harvester.txt
     ```

### **Sample Output:**
```
[*] Credential Harvester started...
[*] Cloning https://outlook.com
[*] Harvesting credentials...
[*] Captured login: Username: admin@example.com | Password: Pass@123
```

### **Mitigation Tips:**  
- Use email filtering solutions.  
- Enable multi-factor authentication.  
- Train users to recognize phishing attacks.

---

## **2. Password Cracking on Windows**


### **Objective:**  
Crack a basic password hash using **John the Ripper** on Windows.

### **Tools Required:**  
- Download **John the Ripper for Windows** from:  
  [https://www.openwall.com/john/](https://www.openwall.com/john/)  

### **Steps:**

#### **1. Install and Set Up John the Ripper**
1. Download the ZIP file from the official website.  
2. Extract the contents to `C:\John` (or any folder).  
3. Open **Command Prompt (cmd)** and navigate to the John folder:  
   ```cmd
   cd C:\John\run
   ```

#### **2. Create a Password Hash File**
1. Open Notepad and add the following hash (MD5 example):  
   ```
   user1:$1$5zV7gpqz$PzCDxvsk.69tp8Nk.JpIu0
   ```
2. Save the file as `hash.txt` in the `C:\John\run` directory.

#### **3. Crack the Password**
Run the following command in the command prompt:  
```cmd
john.exe hash.txt
```

#### **4. View Cracked Passwords**
After a few seconds/minutes, view the cracked password using:  
```cmd
john.exe --show hash.txt
```

---

### **Sample Output:**  
```
user1: password123
```

This means the cracked password is `password123`.

---

### **Explanation of the Steps:**  
1. **Hash File:** The `hash.txt` file contains a sample hashed password.  
2. **John Execution:** Runs the cracking process using built-in wordlists.  
3. **Result:** Displays the cracked password if found in the wordlist.

---

### **Mitigation Tips:**  
- Use strong, complex passwords.  
- Avoid dictionary words in passwords.  
- Enable account lockout policies.  

---

Let me know if you need further clarification or another tool for cracking.

### **Mitigation Tips:**  
- Use strong passwords with a mix of characters.  
- Enable account lockout policies.  
- Use password managers.

---

## **3. Firewall Configuration and Analysis on Windows**

### **Objective:**  
Configure and analyze firewall rules using **Windows Defender Firewall.**

### **Tools Required:**  
- Windows Defender Firewall  
- Windows PowerShell  

### **Steps:**

1. **Check Firewall Status:**  
   Open PowerShell as Administrator and run:  
   ```powershell
   Get-NetFirewallProfile
   ```

2. **Allow or Block Specific Ports:**  
   - Allow RDP traffic (port 3389):  
     ```powershell
     New-NetFirewallRule -DisplayName "Allow RDP" -Direction Inbound -Protocol TCP -LocalPort 3389 -Action Allow
     ```

   - Block traffic from a specific IP:  
     ```powershell
     New-NetFirewallRule -DisplayName "Block IP" -Direction Inbound -RemoteAddress 192.168.1.100 -Action Block
     ```

3. **View Firewall Logs:**  
   - Enable logging in the firewall settings.  
   - Check logs at:  
     ```
     C:\Windows\System32\LogFiles\Firewall\pfirewall.log
     ```

4. **Remove Firewall Rules:**  
   ```powershell
   Remove-NetFirewallRule -DisplayName "Block IP"
   ```

### **Sample Output:**
```
Name        : Allow RDP
Action      : Allow
Enabled     : True
Direction   : Inbound
```

### **Mitigation Tips:**  
- Regularly review firewall logs.  
- Block unnecessary ports.  
- Use advanced security settings for sensitive applications.

---

## **4. Incident Response on Windows Machine**

### **Objective:**  
Perform incident response on a potentially compromised Windows system.

### **Tools Required:**  
- **Windows Event Viewer**  
- **Sysinternals Suite** (Download from [Microsoft](https://docs.microsoft.com/en-us/sysinternals/downloads/sysinternals-suite))  
- Windows PowerShell  

### **Steps:**

1. **Analyze Running Processes:**  
   - Open PowerShell and run:  
     ```powershell
     Get-Process | Sort-Object CPU -Descending
     ```

2. **Check Startup Programs:**  
   - Download and run `autoruns.exe` from Sysinternals.  
   - Look for unknown or suspicious startup entries.

3. **Review Windows Event Logs:**  
   - Open Event Viewer (`eventvwr.msc`).  
   - Navigate to:  
     ```
     Windows Logs > Security > Audit Failure
     ```
   - Look for repeated login failures or unauthorized access.

4. **Analyze Open Network Connections:**  
   ```powershell
   netstat -ano | findstr :80
   ```

5. **Kill Suspicious Processes:**  
   ```powershell
   Stop-Process -Id <PID> -Force
   ```

6. **Remove Malicious Registry Entries:**  
   ```powershell
   reg delete "HKCU\Software\Microsoft\Windows\CurrentVersion\Run" /v "malware" /f
   ```

7. **Quarantine Suspicious Files:**  
   Use Windows Defender to scan and quarantine malicious files:  
   ```powershell
   Start-MpScan -ScanType FullScan
   ```

### **Sample Output:**
```
ProcessName   CPU Usage (ms)
------------- -------------
malware.exe   95.8%
```

### **Mitigation Tips:**  
- Regularly update Windows Defender.  
- Conduct regular vulnerability scans.  
- Restrict administrative privileges.  

---

Let me know if you need further details or clarification on any of these labs.
