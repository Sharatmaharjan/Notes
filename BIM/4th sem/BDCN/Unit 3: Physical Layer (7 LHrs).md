
# Unit 3: Physical Layer (7 LHrs)

## Introduction
The physical layer, the lowest layer in the OSI model, handles the physical connection between devices and the transmission of raw bit streams over a communication medium. It defines hardware specifications, signal encoding, and transmission media, ensuring reliable data transfer.

**Key Functions**:
- Specifies electrical, mechanical, and procedural interfaces.
- Manages bit-level transmission and reception.
- Supports various media types, including cables and wireless signals.

**Practical Example**: An Ethernet cable connecting a computer to a router transmits bits as electrical signals, managed by the physical layer.

---

## Circuits
Circuits provide pathways for data transmission between devices.

### Circuit Configuration
- **Simplex**: One-way communication (e.g., television broadcast where signals are sent from the broadcaster to receivers).
- **Half-Duplex**: Two-way communication, but only one direction at a time (e.g., walkie-talkies where one party speaks while the other listens).
- **Full-Duplex**: Simultaneous two-way communication (e.g., a telephone call where both parties can speak and hear concurrently).

**Diagram**:
```
[Diagram: Three configurations are shown side by side.
- Simplex: An arrow from a TV broadcaster to multiple receivers.
- Half-Duplex: Two walkie-talkies with arrows showing alternating communication.
- Full-Duplex: Two telephones with bidirectional arrows between them.]
```

### Data Flow
- **Serial Transmission**: Bits are sent sequentially over a single channel (e.g., USB communication).
- **Parallel Transmission**: Multiple bits are sent simultaneously over multiple channels (e.g., older printer cables like Centronics).
- **Advantages of Serial**:
  - Simpler wiring reduces costs.
  - Suitable for long distances due to less crosstalk.
- **Disadvantages of Serial**:
  - Slower for large data transfers unless high-speed protocols are used.
- **Advantages of Parallel**:
  - Faster for short distances due to simultaneous bit transmission.
- **Disadvantages of Parallel**:
  - Complex wiring increases costs.
  - Susceptible to crosstalk and signal skew over long distances.

**Practical Example**: A USB device uses serial transmission to send data to a computer, while an old parallel printer port sends 8 bits simultaneously to a printer.

### Multiplexing
- **Definition**: Combines multiple signals into one channel to optimize bandwidth usage.
- **Types**:
  - **Frequency Division Multiplexing (FDM)**: Allocates different frequency bands to each signal (e.g., cable TV channels).
  - **Time Division Multiplexing (TDM)**: Divides time into slots for each signal (e.g., T1 lines used in telephony).
  - **Wavelength Division Multiplexing (WDM)**: Uses different light wavelengths in fiber optics (e.g., Dense WDM in internet backbones).
- **Advantages**:
  - Efficient use of bandwidth, reducing infrastructure costs.
  - Supports multiple simultaneous transmissions.
- **Disadvantages**:
  - Requires complex equipment, increasing setup costs.
  - Potential for interference between channels (e.g., crosstalk in FDM).

**Numerical Example**: A TDM system supports 24 voice channels, each requiring 64 kbps. Total capacity = 24 × 64 kbps = 1.536 Mbps, often used in T1 lines.

**Diagram**:
```
[Diagram: Three multiplexing types are illustrated.
- FDM: A graph showing multiple frequency bands on a single cable.
- TDM: A timeline with time slots assigned to different signals.
- WDM: A fiber optic cable with multiple light wavelengths carrying data.]
```

---

## Communication Media
Communication media are the physical or wireless paths used for data transmission.

### Twisted Pair Cable
- **Description**: Two insulated copper wires twisted together to reduce interference.
- **Types**: Unshielded Twisted Pair (UTP, e.g., Cat5e) and Shielded Twisted Pair (STP).
- **Use Case**: Ethernet networks in local area networks (LANs).
- **Advantages**:
  - Cost-effective and widely available.
  - Easy to install and terminate.
- **Disadvantages**:
  - Limited bandwidth (e.g., Cat5e supports up to 1 Gbps).
  - Susceptible to electromagnetic interference (EMI), especially UTP.

### Coaxial Cable
- **Description**: A single copper conductor surrounded by a shield, reducing interference.
- **Use Case**: Cable television, broadband internet, and older Ethernet networks.
- **Advantages**:
  - Higher bandwidth than twisted pair (e.g., up to 10 Gbps in some cases).
  - Better noise immunity due to shielding.
- **Disadvantages**:
  - Bulkier and less flexible than twisted pair.
  - More expensive to install and maintain.

### Fiber-Optic Cable
- **Description**: Transmits data as light signals through glass or plastic fibers.
- **Use Case**: High-speed internet backbones, long-distance communication.
- **Advantages**:
  - Extremely high bandwidth (e.g., terabits per second in DWDM systems).
  - Immune to EMI, ensuring signal integrity.
  - Supports very long distances (up to 100 km without repeaters).
- **Disadvantages**:
  - High installation and equipment costs.
  - Requires specialized skills for splicing and termination.

### Radio
- **Description**: Wireless transmission using radio waves.
- **Use Case**: Wi-Fi networks, AM/FM radio broadcasting.
- **Advantages**:
  - No physical cabling required, enabling mobility.
  - Flexible deployment in various environments.
- **Disadvantages**:
  - Limited range (e.g., Wi-Fi typically up to 100 meters).
  - Prone to interference from other devices or physical obstacles.

### Microwave
- **Description**: High-frequency radio waves used for line-of-sight communication.
- **Use Case**: Long-distance telecommunications, cellular backhaul.
- **Advantages**:
  - High bandwidth (e.g., supports gigabit speeds).
  - No cabling required, reducing infrastructure costs.
- **Disadvantages**:
  - Requires line-of-sight, limiting placement.
  - Affected by weather conditions like rain or fog.

### Satellite
- **Description**: Uses orbiting satellites for global communication.
- **Use寻址: [Insert a diagram showing a satellite in orbit with signals connecting to multiple ground stations.]

- **Use Case**: Satellite TV, rural internet access.
- **Advantages**:
  - Wide geographical coverage, ideal for remote areas.
  - Supports broadcast services like TV and radio.
- **Disadvantages**:
  - High latency (e.g., 500-700 ms round-trip delay).
  - Expensive infrastructure and maintenance.

### Media Selection
- **Factors for Selection**:
  - Cost: Twisted pair is cheapest; fiber-optic and satellite are expensive.
  - Distance: Fiber-optic for long distances; twisted pair for short.
  - Bandwidth: Fiber-optic offers the highest; twisted pair the lowest.
  - Environment: Fiber-optic for EMI-prone areas; radio for wireless needs.
  - Security: Fiber-optic is hardest to tap; radio is vulnerable to interception.

**Comparison Table**:

| Media            | Bandwidth   | Distance    | Cost       | Interference | Use Case             |
|-------------------|-------------|-------------|------------|--------------|----------------------|
| Twisted Pair     | Low (1 Gbps)| Short (100m)| Low        | High         | LAN                  |
| Coaxial Cable    | Medium (10 Gbps) | Medium (500m) | Medium     | Medium       | Cable TV             |
| Fiber-Optic      | Very High (Tbps) | Very Long (100km) | High       | None         | Backbone networks    |
| Radio            | Medium (1 Gbps) | Short (100m) | Low        | High         | Wi-Fi                |
| Microwave        | High (10 Gbps) | Long (50km) | Medium     | Medium       | Point-to-point links |
| Satellite        | High (1 Gbps) | Global      | High       | Medium       | Remote areas         |

**Practical Example**: A university campus selects UTP for internal LAN (short distance, low cost), fiber-optic for connecting distant buildings (high bandwidth, long distance), and Wi-Fi for student mobility.

---

## Digital Transmission of Digital Data

### Coding
- **Definition**: Converts binary data into electrical or optical signals for transmission.
- **Schemes**:
  - **Non-Return-to-Zero (NRZ)**: 1 as high voltage, 0 as low voltage.
  - **Manchester**: Each bit has a transition in the middle, aiding clock synchronization.
- **Example**: Manchester encoding in Ethernet ensures reliable timing by transitioning for every bit.

### Transmission Modes
- **Asynchronous**: Data sent with start and stop bits (e.g., UART in serial ports).
- **Synchronous**: Data sent in blocks with a shared clock signal (e.g., SPI in embedded systems).
- **Advantages of Asynchronous**:
  - Simpler, no need for clock synchronization.
  - Suitable for low-speed, intermittent data.
- **Disadvantages of Asynchronous**:
  - Overhead from start/stop bits (e.g., 2 bits overhead per 8-bit byte).
- **Advantages of Synchronous**:
  - More efficient, no start/stop bits.
  - Higher speeds due to continuous data flow.
- **Disadvantages of Synchronous**:
  - Requires clock synchronization, increasing complexity.

**Practical Example**: A microcontroller uses asynchronous UART to send sensor data to a computer at 9600 bps, adding start/stop bits to each byte.

### Digital Transmission
- **Process**: Binary data (1s and 0s) is converted into electrical or optical signals.
- **Example**: A 1 Gbps Ethernet link transmits 1 billion bits per second as voltage levels over twisted pair.

### How Ethernet Transmits Data
- **Mechanism**: Uses CSMA/CD (Carrier Sense Multiple Access with Collision Detection) in traditional Ethernet.
  1. Device listens to the channel (carrier sense).
  2. If idle, it transmits the frame; if busy, it waits.
  3. If a collision is detected, devices stop, wait a random time, and retry.
- **Modern Ethernet**: Uses switches to eliminate collisions, enabling full-duplex communication.

**Numerical Example**: A 1500-byte frame on a 100 Mbps Ethernet takes (1500 × 8) / 100,000,000 = 0.12 ms to transmit, excluding overhead.

**Diagram**:
```
[Diagram: CSMA/CD process.
- Step 1: Two devices listen to the network (arrows showing listening).
- Step 2: Both transmit, causing a collision (overlapping signals).
- Step 3: Both stop, wait random times, and retry (timelines showing backoff).]
```

---

## Analog Transmission of Digital Data

### Modulation
- **Definition**: Converts digital data into analog signals for transmission over analog media.
- **Types**:
  - **Amplitude Shift Keying (ASK)**: Varies signal amplitude (e.g., 0 as low amplitude, 1 as high).
  - **Frequency Shift Keying (FSK)**: Varies signal frequency (e.g., 0 as 1200 Hz, 1 as 2400 Hz).
  - **Phase Shift Keying (PSK)**: Varies signal phase (e.g., 0 as 0°, 1 as 180°).
- **Advanced Modulation**: Quadrature Amplitude Modulation (QAM) combines amplitude and phase (e.g., 64-QAM in cable modems).

**Practical Example**: A cable modem uses 256-QAM to transmit data at 38 Mbps over a coaxial cable.

### Capacity of a Circuit
- **Nyquist Theorem**: Maximum data rate = 2 × Bandwidth × log₂(Levels), where Levels is the number of signal levels.
- **Shannon’s Theorem**: Capacity = Bandwidth × log₂(1 + SNR), where SNR is the signal-to-noise ratio.
- **Numerical Example**: A 4 kHz telephone line with SNR of 1000 has a capacity of 4000 × log₂(1 + 1000) ≈ 39.8 kbps (Shannon). Using 4-level signaling (e.g., QPSK), Nyquist gives 2 × 4000 × log₂(4) = 16 kbps.

### How Modems Transmit Data
- **Process**:
  1. Digital data is modulated into an analog signal (e.g., using QAM).
  2. The analog signal is transmitted over a telephone line.
  3. The receiving modem demodulates the signal back into digital data.
- **Example**: A 56k modem achieves up to 56 kbps by modulating digital data into analog signals compatible with telephone lines.

**Diagram**:
```
[Diagram: Modem operation.
- Left: Digital data (1s and 0s) fed into a modem.
- Middle: Modulation converts data into an analog waveform (sine wave with varying amplitude/phase).
- Right: Receiving modem demodulates the waveform back into digital data.]
```

---

## Digital Transmission of Analog Data

### Translating from Analog to Digital
- **Process** (Pulse Code Modulation - PCM):
  1. **Sampling**: Measure analog signal at regular intervals (e.g., 8 kHz for voice).
  2. **Quantization**: Map each sample to a discrete level (e.g., 8 bits = 256 levels).
  3. **Encoding**: Convert quantized levels into binary data.
- **Numerical Example**: Voice sampled at 8 kHz with 8 bits/sample requires 8000 × 8 = 64 kbps.

**Practical Example**: A telephone system samples a 4 kHz voice signal at 8 kHz, quantizes it to 8 bits, and transmits it as a 64 kbps digital stream.

### How Telephones Transmit Voice Data
- **Process**:
  1. Analog voice signal from the microphone is sampled and digitized using PCM.
  2. Digital data is transmitted over the network (e.g., T1 lines).
  3. At the receiver, digital data is converted back to analog for the speaker.
- **Example**: Traditional telephony uses PCM at 64 kbps to transmit voice over digital lines.

### How Instant Messenger Transmits Voice Data
- **Process**:
  1. Voice is digitized and compressed using codecs (e.g., Opus, G.729).
  2. Compressed data is packetized and sent over IP networks.
  3. The receiver decompresses and plays the audio.
- **Numerical Example**: Opus codec compresses voice to 20-40 kbps, significantly less than PCM’s 64 kbps.

**Practical Example**: WhatsApp voice calls use the Opus codec to transmit voice at ~30 kbps, ensuring efficient bandwidth usage.

### Voice over Internet Protocol (VoIP)
- **Definition**: Transmits voice as digital packets over IP networks using protocols like SIP or RTP.
- **Process**:
  1. Analog voice is digitized and compressed (e.g., using G.711 codec at 64 kbps).
  2. Data is packetized and sent via RTP over IP.
  3. The receiver reassembles packets, decompresses, and converts them back to analog.
- **Advantages**:
  - Cost-effective compared to traditional telephony.
  - Scalable for large networks.
- **Disadvantages**:
  - Sensitive to network latency and jitter.
  - Requires sufficient bandwidth for quality (e.g., 100 kbps per call with overhead).

**Practical Example**: A Skype call experiences a 100 ms latency, acceptable for real-time communication (ideal latency < 150 ms).

**Diagram**:
```
[Diagram: VoIP process.
- Left: Analog voice input (waveform) digitized via PCM.
- Middle: Digital data compressed, packetized, and sent over IP (packets labeled with RTP headers).
- Right: Receiver decompresses packets and converts back to analog (waveform output).]
```

