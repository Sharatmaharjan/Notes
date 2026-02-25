
## **Unit:** 2: Sound/Audio System (5 Hrs)

### 2.1 Overview of Sound/Audio System

- **Definition:** An audio system is a combination of electronic devices and software designed to capture, process, store, transmit, and reproduce sound .
- **Core Components:**
    - **Input/Source Devices:** Microphones, musical instruments (electric guitar), CD/DVD players, streaming services (Spotify).
    - **Processing Devices:** Mixing consoles, digital signal processors (DSPs), audio interfaces, computer with DAW software. They modify the signal (e.g., add effects, change volume, mix multiple sources).
    - **Amplification:** Power amplifiers that boost the weak audio signal to a level strong enough to drive speakers.
    - **Output/Transduction Devices:** Loudspeakers, headphones, earphones. These convert the electrical signal back into audible sound waves.
- **Function:** To faithfully capture sound, manipulate it as desired, and reproduce it with clarity and power.
- **Real-World Example:** A home theater system: Blu-ray player (source), AV receiver (processor/amplifier), and speaker setup (output). A smartphone with earbuds: Spotify app (source), phone's internal DAC and amp (processor), earbuds (output).

### 2.2 Producing Digital Audio

- This is the process of converting analog sound waves (continuous) into a digital format (discrete numbers) that computers can store and manipulate .
- **The Process (ADC - Analog to Digital Conversion):**
    1.  **Sampling:** Measuring the amplitude of the analog signal at regular intervals.
        - **Sampling Rate:** The number of samples taken per second, measured in Hertz (Hz).
        - **Example:** CD-quality audio uses a sampling rate of 44.1 kHz (44,100 samples per second).
    2.  **Quantization:** Assigning a discrete value to each sampled amplitude from a fixed set of levels.
        - **Bit Depth:** The number of bits used to represent each sample. Determines the dynamic range and accuracy.
        - **Example:** CD-quality audio uses a bit depth of 16 bits, providing 65,536 possible amplitude levels.
    3.  **Encoding:** Representing the quantized values as binary data (0s and 1s) and storing them in a digital file.
- **Playback (DAC - Digital to Analog Conversion):** The reverse process where a Digital-to-Analog Converter reads the binary data and reconstructs a continuous analog voltage to be sent to speakers .
- **Real-World Example:** Recording a podcast. Your voice (analog) hits the microphone, is converted to an electrical signal, and your audio interface performs ADC, sending a digital stream to Audacity (DAW) where it's saved as a digital file.

### 2.3 Music and Speech

- Both are complex auditory signals but have distinct characteristics .
- **Comparison Table:**

| Feature | Music | Speech |
| :--- | :--- | :--- |
| **Primary Goal** | Aesthetic, emotional, and artistic expression . | Convey propositional meaning and information . |
| **Acoustic Structure**| Often based on discrete pitches (scales) and a regular, periodic pulse (isochronic beat) . | Uses continuous pitch contours (intonation) and irregular, non-isochronous rhythms . |
| **Amplitude Modulation** | Relatively slow and steady amplitude changes (approx. 1-2 Hz) . | Faster and more irregular amplitude changes (approx. 4-5 Hz) . |
| **Semantic Load** | Low. Instrumental music has no semantic meaning. Lyrics add a language layer. | High. Every word and sentence structure carries semantic content. |

- **Real-World Example:** Compare a pop song (steady beat, repeating chorus) to a news broadcast (irregular rhythm, information-dense sentences).

### 2.4 Speech Generation

- The process of producing artificial speech, also known as Speech Synthesis or Text-to-Speech (TTS) .
- **Key Steps in Modern TTS:**
    1.  **Text Analysis:** The system analyzes input text to understand structure (sentences, numbers, abbreviations). "Dr." is expanded to "Doctor" or "Drive" based on context.
    2.  **Prosody Generation:** Determines the intonation, rhythm, and stress patterns to make the speech sound natural.
    3.  **Waveform Generation:** Produces the actual audio waveform from the linguistic and prosodic information.
        - **Older Method (Concatenative):** Stitches together pre-recorded snippets of a human voice.
        - **Modern Method (Parametric/Neural):** Uses deep learning models (like the Sesame model) trained on massive datasets to generate speech from scratch, resulting in very natural, human-like voices .
- **Real-World Example:** Virtual assistants like Siri, Alexa, and Google Assistant using TTS to read out search results or set reminders.

### 2.5 Speech Analysis

- The process of extracting meaningful information and features from a speech signal.
- **Key Aspects:**
    - **Feature Extraction:** Identifying key characteristics like:
        - **Pitch (Fundamental Frequency - F0):** Perceived highness or lowness of the voice.
        - **Formants:** Resonant frequencies of the vocal tract that distinguish vowel sounds.
        - **Energy/Amplitude:** Relates to loudness and stress.
    - **Recognition:** The most common application is **Automatic Speech Recognition (ASR)**, where the system converts the speech signal into text.
    - **Speaker Identification/Verification:** Analyzing unique vocal characteristics to determine who is speaking.
- **Real-World Example:** Using "Hey Google" to wake your phone. The phone is constantly performing low-level speech analysis to detect that specific trigger phrase.

### 2.6 Speech Transmission

- The technology and methods used to send a speech signal from one point to another.
- **Key Considerations:**
    - **Digitization:** Speech is first digitized (as in 2.2) to be handled by digital networks.
    - **Compression:** To save bandwidth, the digital speech is compressed using codecs specifically optimized for voice (e.g., in VoIP).
    - **Packetization:** The compressed data is broken into small packets for transmission over IP networks.
    - **Transport:** Sent over various media (copper wire, fiber optics, radio waves).
    - **Error Handling/Concealment:** Techniques to deal with lost packets or network jitter to maintain intelligibility.
- **Real-World Example:**
    - **Telephone Network (PSTN):** Traditional circuit-switched transmission.
    - **VoIP (Voice over IP):** Skype, WhatsApp calls, Zoom meetings. Your voice is packetized and sent over the internet .
    - **Radio:** AM/FM broadcasts transmit speech wirelessly.

### 2.7 Representation of Audio Files

- Audio files are stored in various **container formats**, which specify how the raw audio data (from 2.2) is structured and stored .
- **Uncompressed Formats:**
    - **WAV (Waveform Audio File Format):** Standard format on Windows. Stores raw PCM data. Large file size, but perfect for professional audio editing.
    - **AIFF (Audio Interchange File Format):** Standard on Mac, similar to WAV.
- **Lossless Compressed Formats:**
    - **FLAC (Free Lossless Audio Codec):** Compresses audio without losing any data. File size is about half of WAV, but bit-perfect reconstruction is possible. Preferred by audiophiles.
    - **ALAC (Apple Lossless Audio Codec):** Apple's equivalent of FLAC.
- **Lossy Compressed Formats:**
    - **MP3 (MPEG-1 Audio Layer 3):** The most ubiquitous format. Uses perceptual coding to discard sounds the human ear is less likely to hear, achieving high compression.
    - **AAC (Advanced Audio Coding):** Designed as the successor to MP3, better sound quality at the same bitrate. Used by YouTube, iTunes, and many modern devices .
- **Real-World Example:** An audio engineer records a podcast in WAV (uncompressed) for editing. After editing, they export an MP3 version to upload to Spotify (for streaming) and a FLAC version to offer for download on their Patreon (for audiophile fans).

### 2.8 Computer Music - MIDI

- **Definition:** MIDI (Musical Instrument Digital Interface) is a technical standard protocol that describes a set of commands or "messages" that allow electronic musical instruments, computers, and other devices to communicate and synchronize with each other .
- **What MIDI IS:**
    - A language or a score. It is **not** audio.
    - It contains instructions like: "Play the note Middle C, at a velocity (loudness) of 100, start now, and stop after 1 second."
- **What MIDI IS NOT:**
    - A digital audio file (like an MP3). It contains no actual sound .
    - To hear MIDI, its instructions must be sent to a sound generator (synthesizer, sampler, or software instrument).
- **Key Concepts:**
    - **MIDI Messages:** Note On, Note Off, Program Change (to change instrument), Pitch Bend, Control Change (for modulation, volume).
    - **MIDI Channels (1-16):** Allows a single MIDI cable to carry 16 separate streams of data, each controlling a different instrument.
    - **MIDI Sequencer:** A piece of software (like a DAW) or hardware used to record, edit, and play back MIDI data .

### 2.9 MIDI versus Digital Audio

- This is the most important comparison for this unit.

| Feature | MIDI | Digital Audio |
| :--- | :--- | :--- |
| **What it is** | A set of digital instructions or messages . | A digital recording of an actual sound wave . |
| **Data Representing** | Musical events (note, pitch, velocity, duration). | The amplitude of sound at each sample point (PCM). |
| **File Size** | Extremely small (kilobytes for several minutes of music). | Large (megabytes for a few minutes of CD-quality audio). |
| **Sound Quality** | Dependent entirely on the sound generator (synthesizer/sampler). Can sound different on different devices. | Fixed. It is a recording of the sound. It will sound the same on any device that can play it. |
| **Editability** | Highly editable. You can change a single note, its pitch, or its instrument with a few clicks. | Limited. Editing is like surgical tape editing. Changing pitch/speed is complex and can degrade quality. |
| **Relationship to Sound** | "Recipe" to create sound. | "Photograph" of sound. |
| **Real-World Analogy** | A player piano roll (instructions). | A recording of a piano performance (the actual sound). |
| **Best Use Case** | Composing, arranging, live performance control, applications where file size is critical (e.g., ringtones). | Recording vocals, acoustic instruments, ambient sounds, final music distribution (CDs, MP3s). |
| **Example** | A `.mid` file from a video game soundtrack. | An `.mp3` file of a Beatles song. |
