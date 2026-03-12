# Unit 2: The Physical Layer

## 2.1 Functions of Physical Layer [6 Hrs.]

### Definition and Scope
- **Definition**: The Physical Layer is the lowest layer (Layer 1) of the OSI model that deals with the physical connection between devices and the transmission of raw bit streams over a communication medium .
- **Scope**: It defines the mechanical, electrical, functional, and procedural specifications for activating, maintaining, and deactivating the physical link .

### Key Functions of Physical Layer

**A. Physical and Mechanical Specifications**
- Defines the physical topology of the network (bus, star, mesh, ring) .
- Specifies connector types, pin assignments, and cable specifications (e.g., RJ45 pins, fiber connectors) .
- Determines the network interface card (NIC) characteristics and physical interface between devices.

**B. Data Encoding and Signaling**
- **Encoding**: Converts digital data (frames from Data Link Layer) into signals suitable for transmission medium .
- **Transmission**: Converts frames into a stream of binary data (bits) .
- **Signal Generation**: Creates electrical, optical, or radio signals that represent 0s and 1s.
- **Real-world example**: Your laptop's Ethernet card converting file data into electrical pulses to send over a cable.

**C. Bit Synchronization**
- Ensures sender and receiver operate at the same bit timing (clock synchronization) .
- Provides clocking mechanisms through encoding schemes (e.g., Manchester encoding) .
- Detects arriving signal levels to synchronize speed and timing between devices.

**D. Transmission and Reception**
- **Transmission functions**:
  - Transmits binary data stream serially (bit by bit) .
  - Uses Media Access Method as determined by Data Link Layer.
  - Generates or amplifies re-transmitted signals along the medium.
- **Reception functions**:
  - Listens for inbound transmissions addressed to the device.
  - Accepts correctly addressed streams.
  - Decodes received signals back into data bits.
  - Passes the bit stream to Data Link Layer for frame conversion .

**E. Interface and Medium Specification**
- Defines the interface between the device and transmission medium.
- Specifies transmission medium characteristics (cable types, wireless frequencies).
- Determines line configuration (point-to-point or multipoint).

**Important Note**: The Physical Layer does NOT perform error correction—it only monitors (detects) transmission errors but cannot correct them . Error detection and correction are handled by higher layers (Data Link Layer).

### Physical Layer Services to Upper Layer
- Provides services to Data Link Layer for data transmission.
- Establishes and releases physical connections.
- Provides physical service data units (bits/frames).
- Provides physical connection endpoints (identifiers for connection points).

---

## 2.2 Data and Signals: Analog and Digital signals, Transmission Impairment, Data Rate Limits, Performance

### 2.2.1 Analog and Digital Signals

**Analog Signals**
- **Definition**: Continuous waveforms that vary smoothly over time, representing infinite values within a range.
- **Characteristics**: Measured in amplitude, frequency, and phase .
- **Examples**: Human voice, AM/FM radio waves, traditional telephone transmission.
- **Applications**: Analog telephony, radio broadcasting, traditional TV.

**Digital Signals**
- **Definition**: Discrete, discontinuous pulses representing only specific values (typically 0 and 1) .
- **Characteristics**: Uses square waves with defined voltage levels for high (1) and low (0).
- **Examples**: Computer data, CD/DVD storage, modern Ethernet.
- **Applications**: Computer networks, digital telephony, digital storage.

**Comparison of Analog vs Digital Signals**

| Feature | Analog Signal | Digital Signal |
| :--- | :--- | :--- |
| **Waveform** | Continuous sine wave | Discrete square wave |
| **Values** | Infinite values in range | Limited to 0 and 1 |
| **Representation** | Voltage/frequency variations | Voltage pulses |
| **Noise immunity** | Low (noise accumulates) | High (noise can be filtered) |
| **Bandwidth** | Lower bandwidth required | Higher bandwidth required |
| **Cost** | Less expensive | More expensive but reliable |
| **Real-world use** | Traditional radio, old phones | Computers, modern networks |

### Signal Properties
- **Amplitude**: Strength or height of signal (measured in volts) .
- **Frequency**: Number of cycles per second (measured in Hertz) .
  - Higher frequency = more data transmission capability but less range.
- **Phase**: Position of waveform relative to time zero.
- **Wavelength**: Physical distance of one complete cycle (λ) .

### 2.2.2 Transmission Impairment
Signals degrade during transmission due to various impairments:

**A. Attenuation**
- **Definition**: Loss of signal energy/strength as distance increases.
- **Cause**: Resistance in the medium, signal absorption.
- **Effect**: Signal becomes weaker, may not be detectable at receiver.
- **Solution**: Amplifiers (analog) or repeaters (digital) to boost signal.
- **Real-world example**: Radio signal getting weaker as you move away from the transmitter.

**B. Distortion**
- **Definition**: Change in signal shape or form during transmission.
- **Cause**: Different frequency components travel at different speeds (propagation velocity varies with frequency).
- **Effect**: Signal components arrive at different times, causing smearing.
- **Particularly affects**: Composite signals with multiple frequencies.

**C. Noise**
- **Definition**: Unwanted random signals that combine with and corrupt the original signal.

**Types of Noise** :
- **Thermal Noise**: Random motion of electrons in conductor (always present).
- **Impulse Noise**: Sudden spikes caused by external factors (lightning, electrical motors, arcing) .
  - Duration: ~10ms, can corrupt multiple bits.
- **Crosstalk**: Interference between adjacent wires (hearing another conversation on phone) .
- **Distorted Frequency**: Changes in signal frequency characteristics.

**Bit Error Rate (BER)** : Probability of bit being corrupted during transmission .

Typical error rates:
- Telephone cable: 1 in 10⁵ bits
- Shielded copper: 1 in 10¹²-10¹³ bits
- Optical fiber: 1 in 10¹⁶-10¹⁷ bits 

### 2.2.3 Data Rate Limits
Maximum possible data rate over a channel is limited by:

**A. Nyquist Theorem (Noiseless Channel)**
- **Formula**: Maximum Data Rate = 2 × Bandwidth × log₂(L) bps
  - Where L = number of signal levels
- **Significance**: For noiseless channel, data rate is limited by bandwidth and signal levels.
- **Example**: Channel with 3 kHz bandwidth and 2 signal levels → max rate = 2 × 3000 × log₂(2) = 6000 bps.

**B. Shannon's Theorem (Noisy Channel)**
- **Formula**: Maximum Data Rate = Bandwidth × log₂(1 + SNR) bps
  - Where SNR = Signal-to-Noise Ratio
- **Significance**: Accounts for noise in real channels.
- **Example**: 3 kHz channel with SNR = 30 dB → SNR ratio = 1000 → max rate = 3000 × log₂(1001) ≈ 30,000 bps.

### 2.2.4 Performance Metrics 

**A. Bandwidth**
- **Definition**: Nominal (peak) number of bits per second possible .
- **Measurement**: Bits per second (bps), MHz (for analog bandwidth).
- **Real-world**: Your ISP advertises "100 Mbps bandwidth" – this is the maximum possible rate.

**B. Throughput**
- **Definition**: Actual measured number of bits per second achieved .
- **Comparison**: Bandwidth is theoretical maximum; throughput is what you actually get.
- **Real-world**: You have 100 Mbps connection but get only 80 Mbps during peak hours.

**C. Latency (Propagation Delay)** 
- **Definition**: Time for first bit to travel from source to destination.
- **Formula**: TPropagation = Distance / Propagation speed
- **Round Trip Time (RTT)** : Time for signal to go and return (2 × latency) .

**D. Total Latency Formula** 
```
TLatency = TPropagation + TTransmission + TQueue
```
Where:
- TPropagation = distance / propagation speed
- TTransmission = message size / bandwidth
- TQueue = time in operating system and switch queues

**Key Insight**: High bandwidth does NOT imply low latency .
- **Example**: Satellite connection has high bandwidth but ~500ms latency due to distance.
- **Car/bus analogy**: A car carries 4 people in 2 hours (bandwidth 2 people/hour); a bus carries 60 people in 2 hours (bandwidth 30 people/hour) but latency still 2 hours .

---

## 2.3 Data Transmission Media: Guided Media, Unguided Media and Satellites

### 2.3.1 Guided Media (Wired)
Physical path between transmitter and receiver.

**A. Twisted Pair Cable**
- **Construction**: Two insulated copper wires twisted together to reduce crosstalk .
- **Types**:
  - **UTP (Unshielded Twisted Pair)** : Common in LANs (Ethernet).
  - **STP (Shielded Twisted Pair)** : Metal shielding for better noise protection.
- **Categories**: Cat5 (100 Mbps), Cat5e (1 Gbps), Cat6 (10 Gbps).
- **Advantages**: Inexpensive, easy to install, widely available.
- **Disadvantages**: Limited distance (~100m), susceptible to EMI.
- **Real-world example**: Office Ethernet cabling, telephone lines.

**B. Coaxial Cable**
- **Construction**: Inner conductor, insulation, braided shield, outer jacket.
- **Applications**: Cable TV, cable internet, CCTV systems.
- **Advantages**: Better shielding than twisted pair, longer distances, higher bandwidth.
- **Disadvantages**: Thicker, less flexible, more expensive than twisted pair.
- **Real-world example**: Connection from wall to cable modem, TV antenna cable.

**C. Fiber Optic Cable**
- **Construction**: Glass/plastic fibers carrying light pulses .
- **Working**: Converts electrical signals to light, transmits through glass fibers (diameter of human hair) .
- **Types**:
  - **Single-mode**: Long distance, laser source.
  - **Multi-mode**: Shorter distance, LED source.
- **Advantages**: Very high bandwidth, immune to EMI, low attenuation, secure .
- **Disadvantages**: Expensive, difficult to install, requires special skills.
- **Real-world example**: Internet backbone, high-speed broadband (FTTH), undersea cables.

### 2.3.2 Unguided Media (Wireless)
Transmission through air, vacuum, or water using electromagnetic waves.

**A. Radio Waves**
- **Frequency Range**: 3 kHz to 1 GHz.
- **Characteristics**: Omnidirectional (travel in all directions), can penetrate walls .
- **Applications**: AM/FM radio, TV broadcasting, cordless phones.
- **Advantages**: Long distance, can pass through obstacles.
- **Disadvantages**: Susceptible to interference, security concerns.

**B. Microwaves**
- **Frequency Range**: 1 GHz to 300 GHz.
- **Characteristics**: Line-of-sight transmission, directional.
- **Applications**: Satellite communication, radar, cellular backhaul.
- **Advantages**: High bandwidth, focused transmission.
- **Disadvantages**: Requires clear line-of-sight, affected by weather (rain fade).

**C. Infrared Waves**
- **Frequency Range**: 300 GHz to 400 THz.
- **Characteristics**: Cannot penetrate walls, short range.
- **Applications**: Remote controls, short-range device communication.
- **Advantages**: Secure (confined to room), no interference between rooms.
- **Disadvantages**: Very short range, line-of-sight required.

**D. WiFi** 
- **Technology**: Uses radio waves (2.4 GHz or 5 GHz frequencies).
- **Standards**: IEEE 802.11 family (a/b/g/n/ac/ax).
- **Range**: Typically 20-100 meters indoors .
- **Components**: Access point (wireless router), wireless clients.
- **Real-world example**: Home WiFi network, campus WiFi (eduroam).

### 2.3.3 Satellite Communication 
- **Definition**: Microwave relay stations in space that receive, amplify, and retransmit signals.
- **Orbit Types**:
  - **Geostationary (GEO)** : 36,000 km above equator, fixed position.
  - **Medium Earth Orbit (MEO)** : 5,000-15,000 km.
  - **Low Earth Orbit (LEO)** : 500-1,500 km (e.g., Starlink, Iridium).
- **Applications**: TV broadcasting, long-distance telephony, GPS, internet for remote areas .
- **Advantages**: Covers vast geographical areas, reaches remote locations.
- **Disadvantages**: High latency (especially GEO: ~500ms), expensive, weather sensitive.

---

## 2.4 Bandwidth Utilization: Multiplexing and Spreading

### 2.4.1 Multiplexing
- **Definition**: Set of techniques allowing simultaneous transmission of multiple signals across a single data link .
- **Purpose**: Efficiency—combine several channels into one .
- **Components**: Multiplexer (MUX) combines signals; Demultiplexer (DEMUX) separates them .

**Types of Multiplexing** :

**A. Frequency-Division Multiplexing (FDM)** 
- **Type**: Analog technique.
- **Principle**: Bandwidth divided into frequency bands; each signal allocated separate band .
- **Guard bands**: Unused frequency spaces between channels to prevent interference.
- **Real-world example**: FM radio stations (each uses different frequency), TV broadcasting.
- **Advantages**: Simultaneous transmission, no synchronization needed.
- **Disadvantages**: Waste of bandwidth (guard bands), limited by frequency range.

**B. Wavelength-Division Multiplexing (WDM)** 
- **Type**: Analog technique for fiber optic cables.
- **Principle**: Multiple light wavelengths (colors) carry different signals through same fiber .
- **Dense WDM (DWDM)** : Many channels, high capacity.
- **Real-world example**: Undersea cables, long-distance fiber backbone.
- **Advantages**: Gigantic bandwidth utilization.
- **Disadvantages**: Expensive equipment required.

**C. Time-Division Multiplexing (TDM)** 
- **Type**: Digital technique.
- **Principle**: Time divided into frames; each frame has slots for each connection .
- **Synchronous TDM**: Each connection gets fixed slot regardless of activity .
  - **Empty slots**: When source has no data, slot goes empty—wasted bandwidth.
  - **Framing bits**: Added for synchronization.
  - **Data rate management strategies**:
    - Multilevel multiplexing
    - Multiple-slot allocation
    - Pulse stuffing (adding dummy bits) 
- **Statistical TDM**: Slots allocated dynamically based on demand .
  - Requires addressing in each slot.
  - More efficient bandwidth usage.
- **Real-world example**: Telephone backbone (T1/E1 lines), SONET/SDH.
- **Advantages**: Efficient for digital data, no guard bands needed.
- **Disadvantages**: Synchronization overhead, queuing delays.

### 2.4.2 Spread Spectrum 
- **Definition**: Techniques that expand signal bandwidth beyond what is needed for transmission.
- **Purpose**: Privacy, anti-jamming, security for wireless communications .
- **Key Principles** :
  1. Allocated bandwidth is much larger than needed (redundancy).
  2. Spreading process is independent of original signal.

**A. Frequency Hopping Spread Spectrum (FHSS)** 
- **Working**: Signal hops between multiple frequencies in pseudorandom pattern.
- **Components**: Pseudorandom noise (PN) code generator, frequency table, synthesizer.
- **Hopping period (Th)** : Time spent on each frequency.
- **Bandwidth sharing**: M frequencies can support M simultaneous users.
- **Real-world example**: Bluetooth, military communications, some cordless phones.
- **Advantages**: Resistant to jamming, hard to intercept, multiple access possible.
- **Disadvantages**: Complex synchronization required.

**B. Direct Sequence Spread Spectrum (DSSS)** 
- **Working**: Each data bit replaced with n bits (chips) using spreading code.
- **Chip rate**: n times the data bit rate.
- **Real-world example**: Original WiFi (802.11b), GPS, CDMA cellular.
- **Advantages**: Resistant to interference, secure, multiple users share same bandwidth.
- **Disadvantages**: Requires more bandwidth, complex receivers.

---

## 2.5 Switching: Circuit switching, Message switching & Packet switching

### 2.5.1 Circuit Switching 
- **Definition**: Dedicated communication path established between sender and receiver for entire session.
- **Phases**: Circuit establishment → Data transfer → Circuit termination.
- **Resource reservation**: Bandwidth reserved along entire path .

**Characteristics** :
- Resources dedicated for connection duration.
- No queuing delay (once circuit established).
- Data transmitted at guaranteed constant rate.
- Switches maintain connection state.

**Real-world example**: Traditional telephone network (PSTN), old-style phone calls.

**Advantages** :
- Guaranteed bandwidth and quality of service.
- No congestion after setup.
- Constant data rate, predictable performance.
- Simple forwarding (no routing decisions per packet).

**Disadvantages** :
- Inefficient for bursty traffic (silent periods waste bandwidth).
- Setup delay before communication.
- Limited number of simultaneous connections.
- Resources idle during silent periods.

**Numerical Example** :
- File size: 640 Kbits
- TDM with 24 slots, link rate: 1.536 Mbps
- Circuit setup time: 500 ms
- Per circuit rate = 1.536 Mbps/24 = 64 Kbps
- Transmission time = 640 Kb / 64 Kbps = 10 seconds
- **Total time = 10.5 seconds**

### 2.5.2 Packet Switching 
- **Definition**: Data broken into packets, each transmitted independently through network without resource reservation.
- **Store-and-forward**: Switch must receive entire packet before forwarding .

**Characteristics** :
- No resource reservation—on-demand usage.
- Packets may wait (queue) at routers.
- Resources shared dynamically.
- Best-effort delivery (no guarantees).

**A. Datagram Approach (Connectionless)**
- Each packet routed independently.
- Packets may take different paths.
- Packets may arrive out of order.
- **Real-world example**: Internet (IP), regular web browsing.

**B. Virtual Circuit Approach (Connection-Oriented)**
- Path established before data transfer (like circuit switching).
- But resources NOT reserved.
- All packets follow same path.
- **Real-world example**: MPLS, Frame Relay, ATM.

**Advantages** :
- Efficient bandwidth usage (statistical multiplexing).
- Handles bursty traffic well.
- Robust—packets can be rerouted around failures.
- No setup delay (for datagram).

**Disadvantages** :
- Variable delays (queuing).
- Potential packet loss (buffer overflow).
- Processing overhead at each router.
- Security concerns (no dedicated path).

### 2.5.3 Message Switching
- **Definition**: Entire message stored and forwarded as complete unit (not broken into packets).
- **Store-and-forward**: Each node receives entire message, stores it, then forwards to next node.
- **Historical significance**: Precursor to packet switching.

**Characteristics**:
- No direct link between sender and receiver.
- Each node stores message temporarily.
- Used in early telegraph networks, email systems.

**Advantages**:
- No dedicated path needed.
- Efficient for low-priority traffic.
- Can prioritize messages at nodes.

**Disadvantages**:
- Large storage requirements at nodes.
- High delay for large messages.
- Not suitable for real-time communication.

### Comparison of Switching Techniques

| Feature | Circuit Switching | Packet Switching | Message Switching |
| :--- | :--- | :--- | :--- |
| **Path establishment** | Required | Not required (datagram) | Not required |
| **Resource reservation** | Yes | No | No |
| **Data unit** | Continuous stream | Packets | Complete message |
| **Store-and-forward** | No | Yes | Yes |
| **Delay** | Low (after setup) | Variable (queuing) | High (message buffering) |
| **Bandwidth efficiency** | Low (idle slots) | High (statistical sharing) | Medium |
| **Real-time support** | Excellent | Fair | Poor |
| **Network example** | Telephone network | Internet | Old telegraph |

---

## 2.6 Telephone, Mobile and Cable network for data Communication

### 2.6.1 Telephone Network for Data Communication 

**A. Dial-up Modems**
- **Technology**: Convert digital data to analog for transmission over voice telephone lines .
- **Process**: Modem modulates digital data to analog at sender, demodulates at receiver.
- **Speed**: Up to 56 Kbps.
- **Characteristics**: Two-device communication only (point-to-point) .
- **Historical note**: Famous "squawking" sound—handshake protocol between modems .
- **Advantages**: Used existing telephone infrastructure, widely available.
- **Disadvantages**: Very slow, occupied phone line.

**B. DSL (Digital Subscriber Line)** 
- **Technology**: High-speed data transmission over existing copper telephone lines .
- **Key feature**: Uses frequencies above voice range—can use phone and internet simultaneously.
- **ADSL (Asymmetric DSL)** : "A" = Asymmetric—download faster than upload .
  - Designed for typical home usage (download heavy, upload light).
  - Download: 1.5-24 Mbps; Upload: 128 Kbps-3.5 Mbps.
- **Advantages**: Uses existing phone lines, always-on connection, voice and data simultaneous.
- **Disadvantages**: Speed decreases with distance from exchange, not all lines support it.

### 2.6.2 Cable Network for Data Communication 

**A. Cable Modem Technology**
- **Technology**: Transmits data over same coaxial cables as cable TV .
- **Frequency usage**: Uses frequencies designed for TV signals—higher bandwidth than voice lines .
- **Shared medium**: Neighborhood shares bandwidth (unlike DSL's dedicated line).
- **Speed**: Typically tens to hundreds of Mbps.
- **DOCSIS standard**: Data Over Cable Service Interface Specification.

**Advantages** :
- Higher bandwidth than DSL initially.
- Always-on connection.
- Uses existing cable TV infrastructure.

**Disadvantages** :
- Shared bandwidth—performance degrades during peak usage.
- Less secure (shared medium).
- Not available in all areas.

### 2.6.3 Mobile Networks for Data Communication 

**A. Cellular Network Evolution**
- **1G**: Analog voice (AMPS, NMT).
- **2G**: Digital voice, SMS, basic data (GSM, CDMA).
- **3G**: Mobile data, internet access (UMTS, EV-DO).
- **4G/LTE**: High-speed mobile broadband, all-IP network.
- **5G**: Ultra-high speed, low latency, massive device connectivity.

**B. Mobile Wireless Access** 
- **Technology**: Mobile devices connect via cellular towers using radio frequencies.
- **Coverage**: Wide area (national/regional coverage).
- **Mobility**: Seamless handoff between cells while moving.
- **Real-world example**: Smartphone internet access, mobile hotspots.

**Advantages** :
- True mobility—connect from anywhere in coverage area.
- No physical infrastructure required at user location.
- Continuous connectivity while moving.

**Disadvantages** :
- Speed varies with signal strength and network load.
- Data caps and usage limits.
- Higher latency than wired connections.
- Signal issues in buildings/remote areas.

### 6.4 Fiber to the Home (FTTH) 
- **Technology**: Fiber optic cable directly to residence/building.
- **Speed**: Tens to hundreds of Mbps, even Gbps.
- **Advantages**: Very high speed, future-proof, immune to interference.
- **Disadvantages**: Expensive to deploy, not widely available in all areas.
- **Real-world example**: NTC/Ncell fiber broadband in Nepal (in urban areas).

### Comparison of Access Technologies

| Technology | Medium | Typical Speed | Sharing | Key Feature |
| :--- | :--- | :--- | :--- | :--- |
| **Dial-up** | Copper phone line | 56 Kbps | Dedicated | Uses voice band |
| **ADSL** | Copper phone line | 1.5-24 Mbps down | Dedicated | Asymmetric, voice+data |
| **Cable Modem** | Coaxial TV cable | 10-500 Mbps | Shared | Higher bandwidth |
| **FTTH** | Fiber optic | 100 Mbps-1 Gbps | Dedicated | Very high speed |
| **Mobile 4G** | Radio (cellular) | 5-100 Mbps | Shared | Mobility |
| **Mobile 5G** | Radio (cellular) | 100 Mbps-10 Gbps | Shared | Ultra-low latency |
| **Satellite** | Radio (satellite) | 10-100 Mbps | Shared | Remote area coverage |
