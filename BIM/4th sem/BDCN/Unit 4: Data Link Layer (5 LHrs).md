## Unit 4: Data Link Layer (5 LHrs)

### 1. Introduction

The Data Link Layer is the second layer in the OSI (Open Systems Interconnection) model and is responsible for reliable node-to-node data transfer. It takes raw data from the Physical Layer and transforms it into a reliable link. Its primary function is to enable the error-free transmission of data frames between two directly connected network nodes.

**Key Responsibilities:**

* **Framing:** Divides the stream of bits received from the network layer into manageable data units called frames.
* **Physical Addressing (MAC Addressing):** Adds a physical address (MAC address) to the frame header to identify the source and destination nodes on the local network.
* **Error Control:** Detects and/or corrects errors that may occur during transmission over the physical medium.
* **Flow Control:** Regulates the rate of data transmission to prevent a fast sender from overwhelming a slow receiver.
* **Media Access Control (MAC):** Manages access to the shared physical medium when multiple devices compete for its use.

### 2. Media Access Control (MAC)

Media Access Control (MAC) is a sublayer of the Data Link Layer that defines how devices in a shared medium network gain access to the transmission medium to send data.

#### 2.1 Contention-Based Access(compete)

* **Explanation:** In contention-based access, all devices on a shared medium compete for access to the medium. If the medium is free, a device can transmit. If multiple devices transmit simultaneously, a collision occurs, leading to data corruption. Mechanisms are in place to detect and handle these collisions.
* **Advantages:**
    * Simple to implement for low traffic.
    * No central coordination required.
    * Efficient for bursty traffic (when traffic is low).
* **Disadvantages:**
    * Performance degrades significantly under heavy network load due to increased collisions.
    * Unpredictable latency (variable delays).
    * Not suitable for real-time applications.
* **Practical Example:** Ethernet (CSMA/CD), Wi-Fi (CSMA/CA).

    * **Carrier Sense Multiple Access with Collision Detection (CSMA/CD):**
        * **Explanation:** Used in traditional Ethernet (half-duplex).
            1.  **Carrier Sense:** A station wanting to transmit first "listens" to the medium to check if it's idle.
            2.  **Multiple Access:** If the medium is idle, the station transmits its frame. Multiple stations can attempt to access the medium.
            3.  **Collision Detection:** While transmitting, the station continues to monitor the medium for collisions. A collision occurs if two or more stations transmit simultaneously.
            4.  **Collision Handling:** If a collision is detected, all involved stations immediately stop transmitting and send a "jam signal" to ensure all other stations detect the collision.
            5.  **Backoff Algorithm:** Each station then waits a random amount of time (backoff period) before attempting retransmission. This random delay helps to prevent repeated collisions.

        * **Theoretical Example:** Consider two stations, A and B, in a CSMA/CD network. A starts transmitting. Before A's signal reaches B, B also senses the medium as idle and starts transmitting. A collision occurs. Both A and B detect the collision, send a jam signal, and then independently calculate a random backoff time before attempting to retransmit.

![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/BIM/4th%20sem/BDCN/images/Unit%204/1%20CSMA%20CD.png)

   * **Carrier Sense Multiple Access with Collision Avoidance (CSMA/CA):**
        * **Explanation:** Used in wireless networks (Wi-Fi) where collision detection is difficult due to the "hidden terminal" problem (stations might not hear each other, but both can hear the access point, leading to collisions at the AP). Instead of detecting collisions, CSMA/CA attempts to avoid them.
        * **Mechanism:**
            1.  **Carrier Sense:** A station listens for ongoing transmissions.
            2.  **Interframe Spacing (IFS):** If the medium is idle, the station waits for a short interframe space.
            3.  **Contention Window:** The station then picks a random backoff value from a contention window.
            4.  **Decrement Backoff:** The station decrements its backoff counter as long as the channel is idle.
            5.  **Transmission:** When the counter reaches zero, the station transmits.
            6.  **Acknowledgement (ACK):** The receiver sends an ACK to confirm successful reception. If no ACK is received, it's assumed a collision occurred (or the frame was lost), and the sender retransmits after another backoff.
            7.  **RTS/CTS (Optional):** Request To Send (RTS) and Clear To Send (CTS) handshake can be used to reserve the medium before data transmission, especially in environments with hidden terminals.
        * **Practical Example:** In a Wi-Fi network, a laptop wants to send data. It listens for activity. If the channel is free, it waits for DIFS, then a random backoff. When the backoff expires, it sends data. The AP receives and sends an ACK. If the ACK is not received, the laptop retransmits.

#### 2.2 Controlled Access

* **Explanation:** In controlled access methods, devices must obtain permission before transmitting. This eliminates collisions and provides predictable performance.
* **Advantages:**
    * No collisions, ensuring efficient use of bandwidth.
    * Predictable performance, suitable for real-time applications.
    * Guaranteed access for each station.
* **Disadvantages:**
    * More complex to implement.
    * Less efficient under light load (overhead of control mechanisms).
    * Requires a central controller or a defined order of access.
* **Practical Example:** Polling, Token Passing.

    * **Polling:**
        * **Explanation:** A primary device (controller) polls secondary devices in a predefined order to determine if they have data to send. Only the polled device can transmit.
        * **Disadvantages:** Overhead of polling messages, potential for idle time if polled devices have no data, single point of failure (primary device).
        * **Practical Example:** Older mainframe terminal networks, some point-of-sale systems.

    * **Token Passing:**
        * **Explanation:** A special frame called a "token" circulates among stations in a logical or physical ring. Only the station holding the token is allowed to transmit data. After transmitting, the station passes the token to the next station in the sequence.
        * **Advantages:** Eliminates collisions, fair access, predictable latency.
        * **Disadvantages:** Complexity of token management (what if token is lost or duplicated?), overhead of token passing.
        * **Practical Example:** Token Ring networks.

#### 2.3 Relative Performance

* **Contention:** Performs well under light to moderate load. Throughput drops significantly under heavy load due to collisions. Latency is unpredictable.
* **Controlled Access:** Provides more predictable and stable performance under heavy load, as collisions are eliminated. However, under light load, the overhead of control mechanisms (polling messages, token passing) can make them less efficient than contention-based methods. Latency is more predictable.

**Comparison Table: Media Access Control Methods**

| Feature           | Contention (CSMA/CD, CSMA/CA) | Controlled Access (Polling, Token Passing) |
| :---------------- | :---------------------------- | :--------------------------------------- |
| Collision         | Possible, handled/avoided     | Eliminated                               |
| Performance (Low Load) | Good (simple)                 | Moderate (overhead)                      |
| Performance (High Load) | Degrades (collisions)         | Good (predictable)                       |
| Complexity        | Lower                         | Higher                                   |
| Predictability    | Low (unpredictable latency)   | High (predictable latency)               |
| Overhead          | Low (collision recovery)      | High (control messages)                  |
| Typical Usage     | Ethernet, Wi-Fi               | Token Ring, FDDI, older proprietary systems |

### 3. Error Control

Error control mechanisms ensure that data transmitted over a link is received accurately. It involves detecting errors and, if possible, correcting them.

#### 3.1 Sources of Errors

* **Noise:** Random electrical or electromagnetic interference (e.g., thermal noise, impulse noise, crosstalk, atmospheric noise, cosmic radiation).
* **Attenuation:** Weakening of the signal strength over distance.
* **Distortion:** Changes in the signal's shape or form.
* **Jitter:** Variation in the arrival time of bits.
* **Crosstalk:** Signal leakage from adjacent wires.
* **Delay Distortion:** Different frequency components of a signal travel at different speeds.

#### 3.2 Error Prevention

* **Shielding:** Using shielded cables (STP, coaxial) to prevent external electromagnetic interference.
* **Twisting:** Twisted pair cables reduce crosstalk and EMI.
* **Filtering:** Using filters to block unwanted noise frequencies.
* **Amplifiers/Repeaters:** To boost signal strength and overcome attenuation over long distances. Repeaters regenerate the signal for digital transmission.
* **Proper Grounding:** To prevent electrical interference.
* **High-Quality Components:** Using better quality cables, connectors, and network devices.

#### 3.3 Error Detection

Error detection techniques add redundant information to the data block (frame) before transmission. The receiver uses this redundant information to check if errors occurred during transmission. If an error is detected, the receiver typically discards the corrupted frame and might request retransmission.

* **Parity Check:**
    * **Explanation:** A single bit (parity bit) is added to a block of data (e.g., 7 bits of data + 1 parity bit = 8-bit byte).
        * **Even Parity:** The parity bit is set so that the total number of '1's in the block (data + parity) is even.
        * **Odd Parity:** The parity bit is set so that the total number of '1's in the block (data + parity) is odd.
    * **Advantages:** Simple to implement.
    * **Disadvantages:** Can detect only an odd number of bit errors. Cannot detect an even number of errors (e.g., 2 bits flipped). Cannot correct errors.
      
    ![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/BIM/4th%20sem/BDCN/images/Unit%204/2%20parity%20check.jpg)

* **Checksum:**
    * **Explanation:** The sender computes a sum of all the data segments in a message. This sum is appended to the message. At the receiver, the checksum is recalculated, and if it matches the transmitted checksum, the data is assumed to be error-free.
    * **Advantages:** Simple to implement, can detect more errors than simple parity.
    * **Disadvantages:** Less robust than CRC, may not detect all multiple-bit errors.
  
   ![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/BIM/4th%20sem/BDCN/images/Unit%204/2%20check%20sum.jpg)

* **Cyclic Redundancy Check (CRC):**
    * **Explanation:** A powerful and widely used error detection technique. It treats the data to be transmitted as a binary polynomial. This data polynomial is divided by a predefined generator polynomial (both sender and receiver use the same generator polynomial). The remainder of this division is the CRC checksum (Frame Check Sequence - FCS), which is appended to the data. The receiver performs the same polynomial division. If the remainder is zero, no error is assumed.
    * **Advantages:**
        * Excellent error detection capabilities, particularly for burst errors (multiple consecutive bit errors).
        * Widely used in networking (Ethernet, Wi-Fi, HDLC).
    * **Disadvantages:** More complex to implement than parity or simple checksum.
  
    ![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/BIM/4th%20sem/BDCN/images/Unit%204/2%20CRC.jpg)

**Comparison Table: Error Detection Methods**

| Method         | Error Detection Capability | Complexity | Overhead (bits) | Common Use        |
| :------------- | :------------------------- | :--------- | :-------------- | :---------------- |
| Parity Check   | Single-bit, odd # of errors | Low        | 1 bit           | Simple serial comms |
| Checksum       | Multiple errors, but not all | Medium     | 16 or 32 bits   | IP, TCP, UDP      |
| CRC            | Excellent, especially burst | High       | 8, 16, 32 bits  | Ethernet, Wi-Fi, HDLC |

#### 3.4 Error Correction via Retransmission (Automatic Repeat Request - ARQ)

* **Explanation:** When errors are detected, the receiver informs the sender (via a NAK - Negative Acknowledgment, or timeout for ACK), and the sender retransmits the corrupted or missing data. This is the most common approach for error control in the Data Link Layer.
* **Protocols (ARQ types):**

    * **Stop-and-Wait ARQ:**
        * **Explanation:** The sender transmits one frame and then stops, waiting for an acknowledgment (ACK) from the receiver. If an ACK is received, the next frame is sent. If a NAK is received or a timeout occurs, the current frame is retransmitted.
        * **Advantages:** Simple to implement, guaranteed delivery.
        * **Disadvantages:** Very inefficient for channels with high propagation delay or low bandwidth due to waiting time.
        * **Theoretical Example:** If the round-trip time (RTT) is 100ms and frame transmission time is 1ms, the channel is idle for 99ms between frames.

   ![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/BIM/4th%20sem/BDCN/images/Unit%204/3%20stop%20and%20wait%20arq.png)

    * **Go-Back-N ARQ:**
        * **Explanation:** The sender can transmit multiple frames (up to a window size N) without waiting for an ACK for each. If an error is detected in a frame (or a NAK is received), the sender retransmits the erroneous frame *and all subsequent frames* that were sent after the erroneous one. The receiver discards all frames following the first detected error until the correct frame is received.
        * **Advantages:** More efficient than Stop-and-Wait, especially for high-bandwidth, high-delay links.
        * **Disadvantages:** Can lead to unnecessary retransmissions if many frames are affected or if a single frame is lost, wasting bandwidth. Receiver buffer management is simpler (doesn't need to buffer out-of-order frames).
         
   ![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/BIM/4th%20sem/BDCN/images/Unit%204/3%20go%20back%20n%20arq.jpg)

    * **Selective Repeat ARQ:**
        * **Explanation:** The sender can transmit multiple frames (up to a window size N). If an error is detected in a frame, only that specific erroneous frame is retransmitted. The receiver accepts and buffers frames that arrive out of order (if they are correct) and only passes them to the Network Layer once the missing (retransmitted) frames are received and the sequence is complete.    
        * **Advantages:** Most efficient ARQ protocol as it minimizes retransmissions.
        * **Disadvantages:** Most complex to implement due to receiver buffering and reordering requirements.
      
   ![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/BIM/4th%20sem/BDCN/images/Unit%204/3%20selective%20repeat%20arq.png)


**Comparison Table: ARQ Protocols**

| Feature             | Stop-and-Wait ARQ | Go-Back-N ARQ      | Selective Repeat ARQ   |
| :------------------ | :---------------- | :----------------- | :--------------------- |
| Sender Window Size  | 1                 | N (>1)             | N (>1)                 |
| Receiver Window Size | 1                 | 1                  | N (>1)                 |
| Retransmission      | Single frame      | All frames from error | Only erroneous frame   |
| Efficiency          | Low               | Medium             | High                   |
| Complexity          | Low               | Medium             | High                   |
| Receiver Buffering  | No                | No (discards out-of-order) | Yes (buffers out-of-order) |

#### 3.5 Forward Error Correction (FEC)

* **Explanation:** Instead of retransmission, FEC adds enough redundant information (error-correcting codes) to the transmitted data so that the receiver can detect and *correct* a certain number of errors without needing to request retransmission.
* **Mechanism:** Uses complex mathematical algorithms (e.g., Hamming codes, Reed-Solomon codes, convolutional codes) to generate parity bits that allow for error correction.
* **Advantages:**
    * No retransmission needed, making it suitable for real-time applications (e.g., streaming video, voice) where delays are critical.
    * Useful in noisy channels where retransmissions would be frequent and inefficient.
    * Useful in simplex communication where reverse channel is not available.
* **Disadvantages:**
    * Higher overhead (more redundant bits are sent).
    * More complex to implement.
    * Can only correct a limited number of errors; beyond that, retransmission might still be needed or the error might be uncorrectable.
* **Practical Example:** Used in satellite communications, deep-space communication, QR codes, CD/DVD/Blu-ray players, some wireless standards (e.g., 5G).

#### 3.6 Error Control in Practice

* **Data Link Layer:** Primarily uses ARQ (retransmission) for reliable frame delivery. CRC is almost universally used for error detection.
* **Higher Layers:** TCP (Transport Layer) also provides end-to-end error control using checksums and ARQ, supplementing the Data Link Layer's efforts.
* **Wireless Networks:** Often combine ARQ with some degree of FEC due to the higher error rates in wireless environments. Short, frequent retransmissions (ARQ) combined with FEC for minor errors provide a balance of reliability and efficiency.

### 4. Data Link Protocols

Data link protocols define the rules for transmitting data frames over a link.

#### 4.1 Asynchronous Transmission

* **Explanation:** Data is transmitted one character (byte) at a time. Each character is framed with a start bit at the beginning and one or more stop bits at the end. These start/stop bits define the beginning and end of a character, allowing the receiver to synchronize with each individual character rather than the entire bit stream. There might be idle time between characters.
* **Diagram:** *Insert Diagram: A sequence of bytes with start bits, data bits, and stop bits, showing potential idle time between bytes.*
* **Advantages:**
    * Simple to implement.
    * Suitable for low-speed, bursty data traffic (e.g., keyboard input).
    * No need for precise clock synchronization between sender and receiver over long periods.
* **Disadvantages:**
    * High overhead (2-3 bits per character for start/stop).
    * Lower efficiency for continuous data streams.
* **Practical Example:** RS-232 serial communication ports, old modems.

#### 4.2 Synchronous Transmission

* **Explanation:** Data is transmitted in continuous blocks (frames) without start and stop bits for individual characters. Synchronization is achieved by synchronizing the clocks of the sender and receiver. This often involves sending a preamble or sync characters at the beginning of each frame to align the clocks.
* **Diagram:** *Insert Diagram: A continuous stream of bits organized into frames, with a header (including sync pattern) and trailer.*
* **Advantages:**
    * Higher efficiency due to less overhead (no start/stop bits per character).
    * Suitable for high-speed, continuous data streams.
* **Disadvantages:**
    * Requires more complex hardware for clock synchronization.
    * Loss of synchronization can lead to loss of an entire block of data.
* **Types:**
    * **Character-oriented (Byte-oriented):** Data is treated as a sequence of characters. Control characters (e.g., SYN, STX, ETX) are used to mark the beginning and end of frames. (e.g., BISYNC - Binary Synchronous Communications).
    * **Bit-oriented:** Data is treated as a stream of bits, regardless of character boundaries. Frames are delimited by special bit patterns (flags). (e.g., HDLC - High-level Data Link Control, PPP - Point-to-Point Protocol).
* **Practical Example:** Ethernet, HDLC, SDLC, PPP, ATM.

**Comparison Table: Asynchronous vs. Synchronous Transmission**

| Feature           | Asynchronous Transmission | Synchronous Transmission |
| :---------------- | :------------------------ | :----------------------- |
| Unit of Transmission | Character (byte)          | Frame (block of bits)    |
| Synchronization   | Per character (start/stop bits) | Per frame (clock/sync pattern) |
| Overhead          | High (start/stop bits)    | Low (frame headers/trailers) |
| Efficiency        | Lower                     | Higher                   |
| Data Rate         | Lower                     | Higher                   |
| Complexity        | Simple                    | More complex             |
| Ideal for         | Bursty data, keyboard input | Continuous data, file transfer |
| Example           | RS-232                    | Ethernet, HDLC, PPP      |

### 5. Transmission Efficiency

Transmission efficiency refers to the ratio of the time spent transmitting actual data to the total time spent using the communication channel. It is a measure of how effectively the available bandwidth is utilized.

* **Factors Affecting Efficiency:**
    * **Overhead:**
        * **Protocol Overhead:** Header and trailer information added by the Data Link Layer (e.g., MAC addresses, CRC, control bits).
        * **Encoding Overhead:** Bits added by line coding schemes (e.g., Manchester encoding doubles the bit rate).
        * **Control Overhead:** Polling messages, token passing, ACK/NAK messages in ARQ.
    * **Error Rate:** High error rates lead to more retransmissions, reducing effective throughput.
    * **Propagation Delay:** The time it takes for a signal to travel from sender to receiver. Significant in long-distance or satellite links.
    * **Processing Delay:** Time spent by devices processing frames.
    * **Queueing Delay:** Time spent waiting in queues due to network congestion.
    * **ARQ Protocol Choice:** Stop-and-Wait is highly inefficient for high-delay links. Go-Back-N and Selective Repeat improve efficiency but with increased complexity.
    * **Window Size:** In sliding window protocols, a larger window size allows more frames to be in transit, improving utilization if errors are few.

* **Calculation (Simple Example - Stop-and-Wait Efficiency):**
    * Let $T_f$ be the time to transmit one frame.
    * Let $T_p$ be the one-way propagation delay.
    * Let $T_{ack}$ be the time to transmit an acknowledgment.
    * The total time for one successful frame transmission in Stop-and-Wait is $T_f + 2T_p + T_{ack}$ (assuming ACK arrives after $T_p$ and is processed).
    * Efficiency = $T_f / (T_f + 2T_p + T_{ack})$.
    * Often simplified to $T_f / (T_f + 2T_p)$ if ACK time is negligible.
    * **Numerical Example:**
        * Frame size = 1000 bits
        * Data rate = 1 Mbps ($10^6$ bits/sec)
        * Propagation delay (one-way) = 10 ms ($0.01$ sec)
        * $T_f = 1000 \text{ bits} / 10^6 \text{ bps} = 0.001$ sec.
        * Efficiency = $0.001 / (0.001 + 2 \times 0.01) = 0.001 / (0.001 + 0.02) = 0.001 / 0.021 \approx 0.0476$ or 4.76%. This demonstrates the very low efficiency of Stop-and-Wait for long links.

* **Throughput:** The actual rate of successful data transfer, measured in bits per second (bps) or frames per second. It is the effective data rate, which is always less than or equal to the channel's raw data rate.
    * Throughput = Data Rate $\times$ Efficiency.

* **Strategies to Improve Efficiency:**
    * Use more efficient ARQ protocols (Go-Back-N, Selective Repeat).
    * Increase frame size (up to a limit, as larger frames are more susceptible to errors).
    * Reduce overhead by using more efficient coding or shorter headers.
    * Implement Flow Control to prevent receiver buffer overflow and subsequent retransmissions.
    * Minimize errors through better physical media and error prevention techniques.
    * Utilize full-duplex communication to allow simultaneous transmission and reception, maximizing channel utilization.
