## Unit 3: Physical Layer (7 LHrs)

### 1. Introduction

The Physical Layer is the lowest layer in the OSI (Open Systems Interconnection) model and TCP/IP protocol suite. Its primary function is to define the electrical and physical specifications for devices and data transmission. It deals with the mechanical, electrical, functional, and procedural characteristics of physical connections to activate, maintain, and deactivate physical links for bit transmission. Essentially, it is responsible for the actual transmission of raw bits over a communication medium.

**Key Responsibilities:**

* **Bit-level transmission:** Deals with the transmission of individual bits.
* **Physical characteristics of interfaces and media:** Defines properties like voltage levels, data rates, cable types, connector types, etc.
* **Representation of bits:** Specifies how bits are converted into electrical or optical signals.
* **Synchronization of bits:** Ensures that the sender and receiver have a common clock for interpreting bit streams.
* **Topology:** Defines the physical layout of the network (e.g., bus, star, ring).

### 2. Circuits

A circuit in the context of networking refers to a communication path over which data can travel.

#### 2.1 Circuit Configuration

Circuit configuration describes how devices are connected to form a communication path.

* **Point-to-Point Configuration:**
    * **Explanation:** A dedicated communication link between two specific devices. Data flows directly from one device to the other.
    * **Diagram:**

   ![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/BIM/4th%20sem/BDCN/images/Unit%203/1%20point-to-point-connection.jpg)

    * **Advantages:**
        * High bandwidth availability for the two connected devices.
        * Reduced interference from other devices.
        * Simpler to set up for small networks.
    * **Disadvantages:**
        * Not scalable for larger networks (requires n-1 connections for n devices).
        * Higher cost for many connections.
        * Redundancy issues if the link fails.
    * **Practical Example:** A dedicated leased line connecting two branch offices of a company.

* **Multipoint Configuration (Shared Circuit):**
    * **Explanation:** Multiple devices share a single communication link. Access to the medium is controlled by some protocol (e.g., polling, contention).
    * **Diagram:**

   ![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/BIM/4th%20sem/BDCN/images/Unit%203/2%20Multipoint-connection.jpg)

    * **Advantages:**
        * Cost-effective as fewer cables are required.
        * Easier to add new devices.
    * **Disadvantages:**
        * Shared bandwidth, leading to potential congestion and lower effective data rates for individual devices.
        * Increased complexity in managing access to the shared medium.
        * Collision potential (e.g., in Ethernet).
    * **Practical Example:** Older bus topology networks, or a wireless local area network (WLAN) where multiple devices share an access point.

#### 2.2 Data Flow

Data flow describes the direction in which data can travel over a communication link.

* **Simplex:**
    * **Explanation:** Data flows in one direction only.
    * **Advantages:** Simple to implement.
    * **Disadvantages:** No acknowledgment or feedback possible.
    * **Practical Example:** Traditional radio broadcasting, TV broadcasting.

* **Half-Duplex:**
    * **Explanation:** Data can flow in both directions, but not simultaneously. Devices take turns transmitting and receiving.
    * **Advantages:** Allows for two-way communication with simpler hardware than full-duplex.
    * **Disadvantages:** Can be slower than full-duplex due to turn-around time.
    * **Practical Example:** Walkie-talkies, older hub-based Ethernet.

* **Full-Duplex:**
    * **Explanation:** Data can flow in both directions simultaneously.
    * **Advantages:**
        * Higher throughput and efficiency as data can be transmitted and received concurrently.
        * No turn-around time overhead.
    * **Disadvantages:** More complex hardware required (e.g., separate transmission and reception paths).
    * **Practical Example:** Modern telephone conversations, switched Ethernet networks.

![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/BIM/4th%20sem/BDCN/images/Unit%203/3%20Half-Duplex-Full-Duplex.png)

**Comparison Table: Data Flow Modes**

| Feature         | Simplex         | Half-Duplex       | Full-Duplex        |
| :-------------- | :-------------- | :---------------- | :----------------- |
| Direction       | One-way         | Two-way, non-sim. | Two-way, sim.      |
| Throughput      | Low             | Medium            | High               |
| Complexity      | Low             | Medium            | High               |
| Usage Example   | Radio broadcast | Walkie-talkie     | Telephone, Switched |

#### 2.3 Multiplexing

Multiplexing is a technique that allows multiple data streams to share a single physical communication medium. It increases the efficiency of the medium by maximizing its utilization.

* **Why Multiplexing?**
    * Economical use of transmission medium.
    * Reduces cost by sharing expensive resources.
    * Increases capacity and throughput.

* **Types of Multiplexing:**

    * **Frequency Division Multiplexing (FDM):**
        * **Explanation:** The available bandwidth of a communication medium is divided into multiple frequency bands. Each data stream is assigned a unique frequency band, and all streams are transmitted simultaneously over the medium. A guard band is often used between channels to prevent interference.
        * **Diagram:**
          
          ![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/BIM/4th%20sem/BDCN/images/Unit%203/4%20FDM.png)

        * **Advantages:**
            * Relatively simple to implement for analog signals.
            * Continuous transmission without time delays.
        * **Disadvantages:**
            * Requires analog signals.
            * Guard bands lead to wasted bandwidth.
            * Susceptible to crosstalk.
            * Not efficient for bursty data.
        * **Practical Example:** Traditional radio and television broadcasting, cellular telephone systems (2G).

    * **Time Division Multiplexing (TDM):**
        * **Explanation:** The total time available on a communication medium is divided into discrete time slots. Each data stream is given a dedicated time slot in a repeating cycle. Data from different streams is transmitted sequentially in their assigned slots. TDM is typically used for digital signals.
        * **Diagram:**
          
          ![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/BIM/4th%20sem/BDCN/images/Unit%203/5%20TDM.png)
          
        * **Types of TDM:**
            * **Synchronous TDM:** Each input source is given a fixed time slot, even if it has no data to send.
            * **Asynchronous (Statistical) TDM:** Time slots are dynamically allocated only to input sources that have data to send, making it more efficient for bursty data.
        * **Advantages:**
            * More efficient for digital signals.
            * No guard bands required.
            * Less susceptible to noise than FDM.
        * **Disadvantages:**
            * Requires precise synchronization between sender and receiver.
            * Idle time slots in synchronous TDM can waste bandwidth.
        * **Practical Example:** T1/E1 digital telephone lines, ISDN (Integrated Services Digital Network).

    * **Wavelength Division Multiplexing (WDM):**
        * **Explanation:** A form of FDM specifically used for optical fiber. Different data streams are transmitted simultaneously over a single fiber using different wavelengths (colors) of light.
        * **Diagram:**
          
          ![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/BIM/4th%20sem/BDCN/images/Unit%203/6%20WDM.png)
          
        * **Advantages:**
            * Vastly increases the capacity of optical fiber.
            * Allows for extremely high data rates.
        * **Disadvantages:** Requires specialized optical equipment (lasers, filters).
        * **Practical Example:** High-capacity backbone networks for the internet.


| Feature / Aspect                  | FDM (Frequency Division Multiplexing)       | TDM (Time Division Multiplexing)           | WDM (Wavelength Division Multiplexing)           |
| --------------------------------- | ------------------------------------------- | ------------------------------------------ | ------------------------------------------------ |
| **Full Form**                     | Frequency Division Multiplexing             | Time Division Multiplexing                 | Wavelength Division Multiplexing                 |
| **Basic Principle**               | Divides bandwidth into multiple frequencies | Divides time into multiple time slots      | Divides light spectrum into wavelengths          |
| **Type of Signal**                | Analog                                      | Digital                                    | Optical                                          |
| **Medium Used**                   | Coaxial cable, radio                        | Twisted pair, digital transmission systems | Fiber optic cable                                |
| **Bandwidth Sharing**             | Users get separate frequency bands          | Users get separate time slots              | Users get separate wavelengths (colors) of light |
| **Synchronization Required**      | No                                          | Yes                                        | Yes (in optical systems)                         |
| **Interference/Crosstalk**        | High (due to adjacent frequencies)          | Low (if synced properly)                   | Very low (excellent isolation)                   |
| **Efficiency**                    | Less efficient due to guard bands           | More efficient in digital systems          | Very efficient in optical systems                |
| **Cost**                          | Low to moderate                             | Moderate                                   | High                                             |
| **Use in Analog/Digital Systems** | Analog systems mostly                       | Digital systems mostly                     | Optical (fiber-based) digital communication      |
| **Scalability**                   | Limited by bandwidth                        | Limited by number of slots and sync issues | Highly scalable (many wavelengths can be used)   |

| Technique | Practical Applications Today                                                                                                             |
| --------- | ---------------------------------------------------------------------------------------------------------------------------------------- |
| **FDM**   | - FM/AM Radio broadcasting<br>- Cable TV<br>- Legacy telephone systems<br>- Some DSL technologies                                        |
| **TDM**   | - Digital telephony (e.g., T1/E1 lines)<br>- 4G/5G mobile systems<br>- Satellite communication<br>- Computer networks                    |
| **WDM**   | - High-speed fiber optic communication<br>- Long-distance internet backbones<br>- Data center interconnects<br>- Submarine cable systems |


### 3. Communication Media

Communication media are the physical pathways over which data travels.

#### 3.1 Twisted Pair Cable

* **Explanation:** Consists of pairs of insulated copper wires twisted together. The twisting helps to reduce electromagnetic interference (EMI) from external sources and crosstalk between adjacent pairs within the cable.
* **Diagram:**

![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/BIM/4th%20sem/BDCN/images/Unit%203/7.png)

* **Types:**
    * **Unshielded Twisted Pair (UTP):** Most common type. No metallic shielding around the pairs.
    * **Shielded Twisted Pair (STP):** Contains a metallic shield around the twisted pairs to further reduce EMI.
* **Advantages:**
    * Relatively inexpensive.
    * Easy to install.
    * Flexible.
    * Widely available.
* **Disadvantages:**
    * Limited bandwidth compared to fiber optics.
    * Susceptible to EMI (especially UTP).
    * Distance limitations (attenuation increases with distance).
* **Practical Example:** Ethernet LANs (Cat5e, Cat6, Cat7).

#### 3.2 Coaxial Cable

* **Explanation:** Consists of a central copper conductor surrounded by an insulating layer, a metallic braid or foil shield, and an outer insulating jacket. The concentric design provides better shielding against EMI than twisted pair.
* **Diagram:**

![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/BIM/4th%20sem/BDCN/images/Unit%203/8%20coaxial%20cable.jpg)

* **Types:**
    * **Thicknet (10BASE5):** Thicker, stiffer, and harder to install.
    * **Thinnet (10BASE2):** Thinner and more flexible.
* **Advantages:**
    * Higher bandwidth than twisted pair.
    * Better noise immunity than UTP.
    * Can support longer distances than UTP.
* **Disadvantages:**
    * More expensive than UTP.
    * Less flexible than UTP.
    * More difficult to install than UTP.
* **Practical Example:** Cable television (CATV) distribution, older Ethernet networks.

#### 3.3 Fiber-Optic Cable

* **Explanation:** Transmits data as pulses of light through thin strands of glass or plastic (fibers). It consists of a core (where light travels), cladding (reflects light back into the core), and a protective jacket.
* **Diagram:**

![Diagram](https://raw.githubusercontent.com/Sharatmaharjan/Notes/main/BIM/4th%20sem/BDCN/images/Unit%203/8%20optical%20fiber.png)

* **Types:**
    * **Single-Mode Fiber (SMF):** Smaller core, allows only one mode (path) of light to propagate. Used for long distances and high bandwidth.
    * **Multi-Mode Fiber (MMF):** Larger core, allows multiple modes (paths) of light to propagate. Used for shorter distances.
* **Advantages:**
    * Extremely high bandwidth.
    * Immune to electromagnetic interference (EMI).
    * Low signal attenuation over long distances.
    * High security (difficult to tap).
    * Smaller and lighter than copper cables.
* **Disadvantages:**
    * More expensive than copper cables.
    * More difficult to install and terminate.
    * Requires specialized equipment (transceivers, fusion splicers).
    * Fragile.
* **Practical Example:** Internet backbone, high-speed data centers, Fiber-to-the-Home (FTTH).

**Comparison Table: Guided Media**

| Feature         | Twisted Pair Cable | Coaxial Cable     | Fiber-Optic Cable      |
| :-------------- | :----------------- | :---------------- | :--------------------- |
| Medium          | Copper             | Copper            | Glass/Plastic          |
| Signal          | Electrical         | Electrical        | Light                  |
| Bandwidth       | Low-Medium         | Medium-High       | Very High              |
| Distance        | Short              | Medium            | Very Long              |
| EMI Immunity    | Low (UTP), Medium (STP) | Medium           | High (Immune)          |
| Cost            | Low                | Medium            | High                   |
| Installation    | Easy               | Medium            | Difficult              |
| Security        | Low                | Medium            | High                   |
| Common Use      | LANs               | CATV, Older LANs  | Backbone, Data Centers |

#### 3.4 Radio (Wireless 3 kHz up to 300 GHz.) 

* **Explanation:** Uses radio waves for communication through the air. Data is modulated onto a carrier wave and transmitted wirelessly.
* **Advantages:**
    * Mobility: Devices can move while maintaining connectivity.
    * Ease of installation (no cables).
    * Broadcast capability (one transmitter can reach multiple receivers).
* **Disadvantages:**
    * Susceptible to interference (other radio sources, physical obstacles).
    * Limited bandwidth compared to wired media.
    * Security concerns (signals can be intercepted).
    * Range limitations.
    * Regulation of frequency bands.
* **Practical Example:** Wi-Fi (802.11), Bluetooth, cellular networks (2G, 3G, 4G, 5G).

#### 3.5 Microwave (Wireless 0.3 GHz to 300 GHz.)

* **Explanation:** Microwaves are actually a subset of radio waves, uses high-frequency radio waves (microwaves) for communication. Typically line-of-sight transmission, meaning the transmitter and receiver must have an unobstructed path.
* **Types:**
    * **Terrestrial Microwave:** Antennas mounted on towers transmit signals directly to each other.
    * **Satellite Microwave:** Signals are beamed from an earth station to a satellite in orbit, which then retransmits them to another earth station.
* **Advantages:**
    * High bandwidth compared to lower frequency radio.
    * Can span long distances (especially satellite).
    * Does not require right-of-way for cabling.
* **Disadvantages:**
    * Requires line-of-sight.
    * Susceptible to atmospheric conditions (rain fade).
    * Expensive to set up (towers, satellites).
    * Security concerns (signals can be intercepted).
* **Practical Example:** Point-to-point communication between buildings, cellular backhaul, long-distance telephony (older systems), satellite TV/internet.

#### 3.6 Satellite (Wireless)

* **Explanation:** A specialized form of microwave communication where communication relays are provided by artificial satellites in Earth orbit. Signals are sent up to the satellite (uplink) and retransmitted down to Earth (downlink).
* **Advantages:**
    * Global coverage, even in remote areas.
    * High bandwidth potential.
    * Broadcasting capability.
* **Disadvantages:**
    * High latency (especially GEO).
    * Expensive to deploy and maintain.
    * Susceptible to rain fade and solar interference.
    * Security concerns.
* **Practical Example:** Global positioning systems (GPS), satellite internet, international telephone communication, satellite TV.

#### 3.7 Media Selection

The choice of communication media depends on several factors:

* **Bandwidth Requirements:** How much data needs to be transmitted per unit of time? (e.g., streaming video requires high bandwidth, text messages require low).
* **Distance:** How far apart are the communicating devices? (e.g., short distances for UTP, long for fiber/satellite).
* **Cost:** Budget constraints for installation and maintenance.
* **Environmental Factors:** Presence of EMI, physical obstacles, need for mobility.
* **Security Concerns:** Sensitivity of the data being transmitted.
* **Reliability and Availability:** Uptime requirements.
* **Ease of Installation and Maintenance:** Skill level required for deployment.

### 4. Digital Transmission of Digital Data

This involves transmitting digital data (bits) using digital signals.

#### 4.1 Coding (Line Coding-digital data (sequence of bits) into a digital signal)

* **Explanation:** Line coding is the process of converting digital data (sequence of bits) into a digital signal that can be transmitted over a physical medium. It defines the voltage levels, pulse shapes, and timing used to represent bits.

* **Common Line Coding Schemes:**

    * **Non-Return-to-Zero (NRZ):**
        * **Explanation:** The voltage level remains constant for the entire duration of the bit.
        * **Types:**
            * **NRZ-Level (NRZ-L):** High voltage for '1', low voltage for '0'.
            * **NRZ-Invert (NRZ-I):** A transition (change in voltage) at the beginning of the bit interval represents '1', no transition represents '0'.
        * **Advantages:** Simple to implement, efficient use of bandwidth.
        * **Disadvantages:** Lack of synchronization for long sequences of '0's or '1's, presence of DC component (NRZ-L).

    * **Return-to-Zero (RZ):**
        * **Explanation:** The signal returns to zero voltage level in the middle of each bit interval.
        * **Advantages:** Provides synchronization (transition in every bit), no DC component.
        * **Disadvantages:** Requires twice the bandwidth of NRZ, more complex.

    * **Manchester Encoding:**
        * **Explanation:** A transition in the middle of each bit interval is used for synchronization and to represent the bit. A transition from low to high represents '0', and a transition from high to low represents '1' (or vice-versa, depending on convention).
        * **Advantages:** Self-clocking (good synchronization).
        * **Disadvantages:** Requires twice the bandwidth of NRZ.
        * **Practical Example:** Used in original Ethernet (10BASE-T).

    * **Differential Manchester Encoding:**
        * **Explanation:** A transition in the middle of the bit interval is always present for clocking. The bit value is determined by the presence or absence of a transition at the beginning of the bit interval. A transition at the beginning represents '0', no transition represents '1' (or vice-versa).
        * **Advantages:** Self-clocking, immune to polarity inversion, no DC component.
        * **Disadvantages:** Requires twice the bandwidth of NRZ.
        * **Practical Example:** Used in Token Ring networks.

    * **Bipolar AMI (Alternate Mark Inversion):**
        * **Explanation:** '0' is represented by no pulse. '1' is represented by alternating positive and negative pulses.
        * **Advantages:** Reduces DC component, some error detection (if two consecutive positive or negative pulses occur).
        * **Disadvantages:** Long sequences of '0's can cause synchronization issues.
        * **Practical Example:** Used in some older digital telephony systems (T1/E1).


#### 4.2 Transmission Modes

Transmission modes refer to how the bits are transmitted relative to each other over a communication link.

* **Parallel Transmission:**
    * **Explanation:** Multiple bits are transmitted simultaneously over multiple parallel wires.
    * **Advantages:** High data rate.
    * **Disadvantages:**
        * Expensive (requires many wires).
        * Limited distance due to skew (bits arriving at different times).
        * Susceptible to crosstalk.
    * **Practical Example:** Internal computer buses.

* **Serial Transmission:**
    * **Explanation:** Bits are transmitted one after another over a single wire.
    * **Advantages:**
        * Inexpensive (fewer wires).
        * Suitable for long distances.
        * Less prone to skew and crosstalk.
    * **Disadvantages:** Lower data rate than parallel transmission.
    * **Practical Example:** Ethernet, USB, RS-232 serial ports.

**Comparison Table: Transmission Modes**

| Feature         | Parallel Transmission | Serial Transmission |
| :-------------- | :-------------------- | :------------------ |
| Wires           | Multiple              | Single              |
| Speed           | High (short distances) | Medium-High (long distances) |
| Cost            | High                  | Low                 |
| Distance        | Short                 | Long                |
| Skew/Crosstalk  | High                  | Low                 |
| Common Use      | Internal computer buses | Network connections |

#### 4.3 Digital Transmission (General Concepts)

* **Data Rate (Bit Rate):** The number of bits transmitted per second (bps).
* **Baud Rate (Symbol Rate):** The number of signal changes (symbols) per second. In digital transmission of digital data, sometimes a symbol can represent more than one bit, leading to data rate > baud rate.
* **Bandwidth:** The range of frequencies a transmission medium can carry.
* **Nyquist Theorem:** For a noiseless channel, the maximum data rate ($C$) is given by $C = 2B \log_2 M$, where $B$ is the bandwidth and $M$ is the number of distinct signal levels. This theorem provides an upper bound on data rate for ideal channels.
* **Shannon-Hartley Theorem:** For a noisy channel, the maximum theoretical data rate ($C$) is given by $C = B \log_2 (1 + S/N)$, where $B$ is the bandwidth, $S$ is the average signal power, and $N$ is the average noise power. $S/N$ is the signal-to-noise ratio, often expressed in decibels (dB) as $10 \log_{10} (S/N)$. This theorem provides a practical upper bound for real-world channels.
    * **Numerical Example:** A channel has a bandwidth of 3000 Hz and a signal-to-noise ratio of 30 dB.
        * First, convert SNR from dB to ratio: $30 = 10 \log_{10} (S/N) \implies 3 = \log_{10} (S/N) \implies S/N = 10^3 = 1000$.
        * Using Shannon-Hartley: $C = 3000 \log_2 (1 + 1000) \approx 3000 \log_2 (1001) \approx 3000 \times 9.96 \approx 29880$ bps.

#### 4.4 How Ethernet Transmits Data

* **Explanation:** Ethernet (specifically older versions like 10BASE-T and 100BASE-TX) uses digital transmission of digital data over twisted-pair cables.
* **Key Aspects:**
    * **Encoding:** 10BASE-T uses Manchester encoding, while 100BASE-TX uses 4B/5B encoding followed by MLT-3. Gigabit Ethernet (1000BASE-T) uses 8B/1T (PAM-5) for more complex signaling over all four pairs.
    * **Access Method:** Carrier Sense Multiple Access with Collision Detection (CSMA/CD) for half-duplex Ethernet. Full-duplex Ethernet does not use CSMA/CD as separate transmit and receive paths eliminate collisions.
    * **Frame Format:** Data is encapsulated into Ethernet frames, which include preamble, start-of-frame delimiter, destination MAC address, source MAC address, length/type, data, and Frame Check Sequence (FCS).
    * **Physical Medium:** Twisted-pair cables (Cat 5e, Cat 6, etc.).
    * **Transmission Process (Simplified):**
        1.  A device wants to send data.
        2.  It listens to the medium (carrier sense) to see if it is idle.
        3.  If idle, it transmits its data frame, encoded into an electrical signal.
        4.  While transmitting, it continues to listen for collisions.
        5.  If a collision is detected, transmission stops, a jam signal is sent, and the device waits a random backoff time before retrying.
        6.  The receiver decodes the electrical signal back into bits and reconstructs the frame.

### 5. Analog Transmission of Digital Data

This involves converting digital data into an analog signal for transmission over an analog medium (e.g., telephone lines, radio channels). This process is called modulation.

#### 5.1 Modulation

* **Explanation:** Modulation is the process of varying one or more properties of a periodic waveform (carrier wave) with a modulating signal, which typically contains information to be transmitted. In this context, the digital data acts as the modulating signal, and an analog carrier wave is modified.
* **Purpose:**
    * To match the characteristics of the signal to the transmission medium.
    * To allow multiple signals to share a medium (FDM).
    * To enable transmission over long distances by using higher frequencies that attenuate less.
* **Types of Modulation (for digital data):**

    * **Amplitude Shift Keying (ASK):**
        * **Explanation:** The amplitude (strength) of the carrier wave is varied to represent different digital values. The frequency and phase remain constant.
        * **Diagram:** *Insert Diagram: A carrier wave with varying amplitude to represent 0s and 1s.*
        * **Advantages:** Simple to implement.
        * **Disadvantages:** Susceptible to noise (amplitude variations caused by noise can be misinterpreted as data).
        * **Practical Example:** Used in some fiber optic links and very low-speed modems.

    * **Frequency Shift Keying (FSK):**
        * **Explanation:** The frequency of the carrier wave is varied to represent different digital values. The amplitude and phase remain constant.
        * **Diagram:** *Insert Diagram: A carrier wave with varying frequency to represent 0s and 1s.*
        * **Advantages:** Less susceptible to noise than ASK.
        * **Disadvantages:** Requires more bandwidth than ASK for the same data rate.
        * **Practical Example:** Used in older modems (up to 1200 bps), low-speed wireless communication.

    * **Phase Shift Keying (PSK):**
        * **Explanation:** The phase of the carrier wave is varied to represent different digital values. The amplitude and frequency remain constant.
        * **Types:**
            * **Binary PSK (BPSK):** Two phases (e.g., 0 and 180 degrees) represent '0' and '1'.
            * **Quadrature PSK (QPSK):** Four phases (e.g., 45, 135, 225, 315 degrees) represent two bits (dibit) per symbol.
        * **Diagram:** *Insert Diagram: A carrier wave with varying phase to represent 0s and 1s (for BPSK and QPSK).*
        * **Advantages:** More robust against noise than ASK, more bandwidth efficient than FSK.
        * **Disadvantages:** More complex to implement.
        * **Practical Example:** Used in DSL, Wi-Fi, satellite communication, cellular networks.

    * **Quadrature Amplitude Modulation (QAM):**
        * **Explanation:** Combines both amplitude and phase modulation to represent multiple bits per symbol. This allows for higher data rates for a given bandwidth.
        * **Diagram:** *Insert Diagram: A constellation diagram showing points representing different combinations of amplitude and phase (e.g., 16-QAM or 64-QAM).*
        * **Advantages:** Very high bandwidth efficiency, high data rates.
        * **Disadvantages:** Most complex to implement, more susceptible to noise than PSK at higher constellations.
        * **Practical Example:** Used in high-speed modems (ADSL, cable modems), Wi-Fi (802.11ac/ax), digital television broadcasting.

#### 5.2 Capacity of a Circuit

The capacity of a circuit refers to the maximum rate at which data can be transmitted reliably over that circuit. This is governed by the Nyquist and Shannon-Hartley theorems discussed in section 4.3.

#### 5.3 How Modems Transmit Data

* **Explanation:** A modem (Modulator-Demodulator) is a device that converts digital data from a computer into an analog signal for transmission over an analog telephone line (modulation) and converts analog signals received from the line back into digital data for the computer (demodulation).
* **Process:**
    1.  **Digital Data Input:** The computer sends digital bits to the modem.
    2.  **Modulation:** The modem uses one or more modulation techniques (e.g., QAM, PSK) to convert these digital bits into an analog signal suitable for the telephone line. This analog signal consists of varying amplitudes, frequencies, or phases of a carrier wave.
    3.  **Transmission:** The analog signal travels over the telephone line to the receiving modem.
    4.  **Demodulation:** The receiving modem demodulates the incoming analog signal, converting it back into the original digital bits.
    5.  **Digital Data Output:** The receiving modem sends these digital bits to the receiving computer.
* **Numerical Example (Conceptual):**
    * A modem uses 16-QAM. Each symbol represents $\log_2 16 = 4$ bits.
    * If the modem can transmit 2400 symbols per second (baud rate), then the data rate is $2400 \times 4 = 9600$ bps.
* **Diagram:** *Insert Diagram: A block diagram showing two computers connected via modems and a telephone line, illustrating modulation and demodulation.*
* **Advantages of using Modems:** Enabled digital communication over existing analog telephone infrastructure.
* **Disadvantages of using Modems:** Limited bandwidth compared to digital lines, susceptible to line noise, required dial-up connection.

### 6. Digital Transmission of Analog Data

This involves converting analog data (e.g., voice, video) into digital form for transmission over digital networks.

#### 6.1 Translating from Analog to Digital

The process of converting analog signals into digital signals is called Analog-to-Digital Conversion (ADC). The key steps are:

* **Sampling:**
    * **Explanation:** The analog signal is measured at regular intervals. The sampling rate (number of samples per second) must be at least twice the highest frequency component of the analog signal to accurately reconstruct the original signal (Nyquist-Shannon sampling theorem).
    * **Practical Example:** For voice (human speech, typically up to 4 kHz), a common sampling rate is 8,000 samples per second.
    * **Diagram:** *Insert Diagram: An analog waveform with discrete points sampled at regular intervals.*

* **Quantization:**
    * **Explanation:** Each sampled analog value is assigned a discrete numerical value from a finite set of levels. This involves rounding the sampled amplitude to the nearest predefined quantization level.
    * **Diagram:** *Insert Diagram: Sampled points being mapped to discrete quantization levels.*
    * **Quantization Error:** The difference between the actual analog sample value and the assigned quantization level. More quantization levels (more bits per sample) reduce quantization error but increase data rate.

* **Encoding (Digital Encoding):**
    * **Explanation:** The quantized values are then converted into a binary code (series of bits). Each quantization level is assigned a unique binary code.
    * **Example:** If 256 quantization levels are used, each sample will be encoded into 8 bits ($2^8 = 256$).
    * **Numerical Example (Pulse Code Modulation - PCM):**
        * Voice signal bandwidth: 4 kHz.
        * Sampling rate (Nyquist): $2 \times 4 \text{ kHz} = 8000$ samples/second.
        * Quantization: 256 levels (8 bits per sample).
        * Data rate: $8000 \text{ samples/second} \times 8 \text{ bits/sample} = 64,000 \text{ bps (64 kbps)}$. This is the standard data rate for a single digital voice channel (DS0) in telephone networks.

#### 6.2 How Telephones Transmit Voice Data

* **Explanation:** Traditional analog telephones transmit voice as continuous electrical analog signals over local loops. However, once voice signals reach the central office, they are digitized for transmission over the digital telephone network (e.g., T1/E1 lines, fiber optic backbones). This digitization is primarily done using Pulse Code Modulation (PCM).
* **Process:**
    1.  **Analog Voice Input:** Sound waves are converted into electrical analog signals by the telephone microphone.
    2.  **Analog-to-Digital Conversion (at the central office or closer to the subscriber with modern technologies like DSL/Fiber):** The analog voice signal is sampled (e.g., 8000 times/second), quantized, and encoded into 8-bit digital samples (64 kbps per voice channel).
    3.  **Multiplexing:** Multiple 64 kbps voice channels are time-division multiplexed (TDM) onto higher-speed digital lines (e.g., 24 voice channels for a T1 line at 1.544 Mbps, or 30 voice channels for an E1 line at 2.048 Mbps).
    4.  **Digital Transmission:** The multiplexed digital signal is transmitted over the digital telephone network.
    5.  **Demultiplexing and Digital-to-Analog Conversion:** At the receiving end, the signal is demultiplexed, and the digital samples are converted back into an analog voice signal by a Digital-to-Analog Converter (DAC).
    6.  **Analog Voice Output:** The analog signal is converted back into sound waves by the telephone speaker.

#### 6.3 How Instant Messenger Transmits Voice Data

* **Explanation:** Instant messenger applications (like WhatsApp, Zoom, Google Meet) transmit voice data over the internet using digital means. They employ voice compression techniques to reduce bandwidth requirements.
* **Process (Simplified):**
    1.  **Analog Voice Input:** Microphone captures analog voice.
    2.  **Analog-to-Digital Conversion:** The voice is sampled and quantized into digital form (e.g., PCM).
    3.  **Voice Compression (Codec):** Unlike traditional telephony that might use uncompressed PCM, instant messengers use audio codecs (e.g., Opus, Speex, G.729) to significantly compress the digital voice data. This reduces the data rate while maintaining acceptable voice quality. Compression techniques remove redundant and perceptually irrelevant information.
    4.  **Packetization:** The compressed digital voice data is broken into small packets.
    5.  **Transmission over IP Network (VoIP):** These packets are encapsulated within UDP (User Datagram Protocol) packets and then IP (Internet Protocol) packets, and transmitted over the internet.
    6.  **De-packetization and Decompression:** At the receiver, packets are reassembled, and the voice data is decompressed by the same codec.
    7.  **Digital-to-Analog Conversion:** The decompressed digital voice is converted back to analog by a DAC.
    8.  **Analog Voice Output:** Speaker produces sound.

#### 6.4 Voice over Internet Protocol (VoIP)

* **Explanation:** VoIP is a technology that allows voice communication to be carried over the internet using the Internet Protocol (IP) rather than traditional circuit-switched telephone networks.
* **Key Principles:**
    * **Packet Switching:** Voice data is digitized, compressed, and sent as packets over a packet-switched network (the internet) instead of dedicated circuits.
    * **Codecs:** Efficient audio codecs are crucial for reducing bandwidth consumption.
    * **Protocols:** Uses various protocols for signaling (e.g., SIP - Session Initiation Protocol, H.323) and media transport (e.g., RTP - Real-time Transport Protocol over UDP).
* **Advantages:**
    * **Cost Savings:** Often cheaper than traditional long-distance calls, especially for international calls.
    * **Integration:** Easier to integrate with other data services and applications (e.g., video conferencing, instant messaging, presence).
    * **Flexibility:** Can be used on various devices (softphones on computers, IP phones, mobile apps).
    * **Scalability:** Easier to scale up or down compared to traditional phone systems.
* **Disadvantages:**
    * **Quality of Service (QoS) Issues:** Susceptible to internet network issues like latency, jitter, and packet loss, which can degrade voice quality.
    * **Power Outages:** VoIP phones often require power to operate, unlike traditional POTS (Plain Old Telephone Service) phones which can draw power from the line.
    * **Emergency Services (E911/112):** Routing emergency calls accurately can be more complex with VoIP, especially for nomadic users.
    * **Security Concerns:** VoIP traffic can be vulnerable to eavesdropping and other attacks if not properly secured.
* **Practical Example:** Skype, Zoom, Google Voice, IP PBX systems used in businesses.
