# **Unit:** 5: Data Compression (6 Hrs)


### 5.1 Need for Data Compression

- **Definition:** Data compression is the process of encoding information using fewer bits than the original representation .
- **Primary Needs:**
    - **Storage Space Reduction:** Multimedia data (images, audio, video) requires enormous storage capacity. Compression makes it feasible to store large media libraries on devices with limited space .
        - **Real-World Example:** A single minute of uncompressed HD video can be several gigabytes. Compression allows storing a full-length movie on a Blu-ray disc.
    - **Faster Transmission/Bandwidth Efficiency:** Compressed files transfer faster over networks, reducing bandwidth consumption and improving user experience .
        - **Real-World Example:** Streaming a 4K movie on Netflix would be impossible without compression, as the bandwidth required would exceed most internet connections.
    - **Cost Savings:** Reduces costs associated with storage hardware and network bandwidth .
        - **Real-World Example:** Cloud storage providers and data centers use compression to maximize the amount of data they can store and serve, lowering operational costs.
    - **Faster Data Backup and Recovery:** Smaller file sizes mean backups complete more quickly and require less tape or disk space.

### 5.2 Compression Basics

- **Core Concept:** Data compression works by finding and eliminating **redundancy** in data . Redundancy refers to information that is repeated or can be predicted from other parts of the data.
- **Key Processes:**
    - **Encoding:** The process of compressing the original data into a smaller representation using a **codec** (coder/decoder) .
    - **Decoding:** The reverse process of reconstructing the original data (or an approximation of it) from the compressed representation .
- **Compression Ratio:** The primary metric for evaluating compression effectiveness.
    - **Formula:** Compression Ratio = Original Size / Compressed Size .
    - **Interpretation:** A ratio of 10:1 means the compressed file is one-tenth the size of the original.
- **Key Requirements of a Good Compression Algorithm :**
    - **High Compression Ratio:** Achieves maximum size reduction.
    - **High Speed:** Encoding and decoding must be fast enough for the application (e.g., real-time video streaming) .
    - **High Quality (for lossy):** Minimizes perceivable loss of quality.
    - **Low Complexity:** Should not require excessive computational resources, especially on devices with limited battery power (like mobile phones) .

### 5.3 Storage Space

- **Impact of Compression on Storage:**
    - **Before Compression:** Multimedia files occupy massive space. For example, a 5-minute uncompressed audio CD-quality song (~44.1kHz, 16-bit, stereo) is about 50 MB.
    - **After Compression:** The same song compressed with MP3 at 128 kbps might be only 5 MB, a 90% reduction.
- **Trade-offs:**
    - **More Compression (Smaller Storage):** Often requires more complex algorithms, which can increase processing time (CPU usage) and may introduce quality loss .
    - **Less Compression (Larger Storage):** Simpler, faster algorithms or lossless methods preserve quality but consume more disk space.
- **Real-World Example:** A smartphone with 128GB storage can hold thousands of photos and dozens of apps because photos are stored as compressed JPEGs and apps are compressed for distribution.

### 5.4 Coding Requirements

For a compression code to be useful, it must meet certain requirements:

- **Uniquely Decodable:** A compression code must be unambiguous. A given compressed bitstream must correspond to one and only one original message. If two different original sequences can produce the same compressed output, the code is useless.
- **Instantaneous/Self-Synchronizing (Desirable):** The decoder should be able to decode each codeword immediately as it reads the bits, without having to look ahead to future bits. Prefix-free codes (like Huffman) have this property .
- **Efficiency:** The coding process should be computationally efficient to encode and decode .
- **Adaptability (Desirable):** Some codes can adapt to changing statistics in the data (e.g., adaptive Huffman or LZW) .

### 5.5 Lossless and Lossy Compression Techniques

This is the most fundamental classification of compression methods .

| Feature | **Lossless Compression** | **Lossy Compression** |
| :--- | :--- | :--- |
| **Definition** | Data is compressed and decompressed perfectly, with **no loss of information**. The original and decompressed data are identical . | Data is compressed by permanently discarding "unimportant" or redundant information. The decompressed data is an **approximation** of the original . |
| **Reversibility** | Fully reversible. | Irreversible. Original cannot be perfectly reconstructed. |
| **Compression Ratio** | Low to moderate (typically 2:1 to 4:1 for images). | High to very high (10:1 to 100:1 or more for images/video). |
| **Quality** | Perfect, original quality is preserved. | Quality is degraded, but aim is to make the loss imperceptible (perceptual coding). |
| **Typical Uses** | Text files (ZIP), software executables, medical imaging, archival of master copies . | Photographs (JPEG), music (MP3, AAC), video streaming (MPEG, H.264) . |
| **Real-World Example** | Zipping a folder containing a Word document to email it. The unzipped document is identical to the original. | Watching a movie on Netflix. The video you see is a compressed approximation that looks very similar to the studio master. |

### 5.6 Source, Entropy, and Hybrid Coding

- **Source Coding:** A broad term for any process that represents information from a source (like an image or text) in a digital form, often with the goal of compression. It is the foundation of both lossless and lossy compression .
- **Entropy Coding:** A specific class of **lossless** compression techniques that compress data by assigning shorter codes to frequently occurring symbols and longer codes to less frequent symbols . It is based on the concept of **entropy**, which is the theoretical minimum average number of bits required to represent symbols from a source.
    - **Examples:** Huffman coding, Arithmetic coding .
    - **Analogy:** In the English language, the letter 'e' is very common (short code), while 'z' is rare (long code).
- **Hybrid Coding:**
    - **Definition:** The combination of multiple compression techniques to achieve higher compression ratios than any single method could alone . Most modern compression standards are hybrid coders.
    - **Common Hybrid Approach:** A **lossy** stage (like transform coding) is followed by a **lossless** stage (like entropy coding) .
        - **Step 1 (Lossy):** Remove perceptually irrelevant information (e.g., fine details in a photo). This significantly reduces data size.
        - **Step 2 (Lossless/Entropy):** The remaining, smaller set of information is then compressed losslessly using entropy coding.
    - **Real-World Example:** JPEG uses a hybrid method: Discrete Cosine Transform (DCT) and quantization (lossy) followed by Huffman coding (lossless/entropy) .

### 5.7 Lossy Sequential DCT-based Mode

- **Context:** This is the basis of the **JPEG** image compression standard for **sequential encoding**, where the image is encoded and decoded in a single, top-to-bottom pass .
- **Process (Step-by-Step):**
    1.  **Block Preparation:** The image is divided into 8x8 pixel blocks.
    2.  **DCT (Discrete Cosine Transform):** The DCT formula is applied to each block. It converts the spatial pixel values into frequency coefficients. The top-left coefficient represents the average color (DC coefficient), while the others represent finer details at different frequencies (AC coefficients) .
    3.  **Quantization (The Lossy Step):** Each of the 64 coefficients is divided by a corresponding value from a **quantization table**. This is where information is discarded. High-frequency coefficients (details) are often divided by larger numbers, becoming zero or near-zero. This is the primary source of compression and quality loss .
    4.  **Entropy Coding (The Lossless Step):** The quantized coefficients are further compressed losslessly.
        - **Zig-Zag Scan:** The 64 coefficients are read in a zig-zag order to group long runs of zeros together (from the high-frequency areas).
        - **Run-Length Encoding (RLE):** The runs of zeros are encoded efficiently.
        - **Huffman/Arithmetic Coding:** The final step assigns variable-length codes to the remaining data .
- **Real-World Example:** Any standard photo from a digital camera or the web saved as a "baseline" JPEG uses this mode.

### 5.8 Expanded Lossy DCT-based Mode

- **Definition:** An extension of the sequential mode that includes **progressive** and **hierarchical** encoding, offering more flexibility .
- **Progressive DCT-based Mode:**
    - **Concept:** The image is encoded in multiple scans for display. The first scan transmits a rough, low-quality version of the entire image. Subsequent scans progressively add detail, refining the image quality .
    - **Real-World Example:** On a slow internet connection, a progressive JPEG will appear blurry at first and then gradually become clearer as more data is received. This provides a visual feedback to the user faster than a sequential JPEG, which would load from the top down.
- **Advantage:** Better user experience on slow networks.
- **Disadvantage:** Requires more memory and processing power to decode and display the progressive layers.

### 5.9 JPEG and MPEG Compression

These are the most important standards for image and video compression, respectively .

#### JPEG (Joint Photographic Experts Group) 

- **Purpose:** Standard for lossy compression of continuous-tone still images (photographs).
- **Key Features:**
    - Based on the **Lossy Sequential DCT-based Mode** described above.
    - User-adjustable quality level (controlling the quantization step). Higher quality = lower compression, and vice versa.
    - Not well-suited for line art, text, or sharp-edged graphics (where PNG or GIF is better).
- **Advantages:**
    - **High Compression Ratio:** Achieves 10:1 to 20:1 compression with minimal visible loss.
    - **Widely Supported:** Universal standard supported by all browsers, cameras, and image software.
    - **Fine Control:** Users can trade off file size for image quality.
- **Disadvantages:**
    - **Lossy:** Discards information permanently; repeated saving degrades quality.
    - **Artifacts:** Can produce visible "blocky" artifacts at high compression levels.
    - **No Transparency:** Does not support transparent backgrounds.

#### MPEG (Moving Picture Experts Group) 

- **Purpose:** Family of standards for lossy compression of video and audio (e.g., MPEG-1, MPEG-2, MPEG-4).
- **How it Works (Hybrid Approach):** MPEG compression uses a combination of techniques:
    1.  **Spatial Compression:** Each individual frame is compressed similarly to JPEG (intra-frame coding). These are called **I-frames (Intra-coded frames)**.
    2.  **Temporal Compression:** It exploits redundancy *between* frames. Instead of storing every full frame, it only stores the **differences** between frames.
        - **P-frames (Predicted frames):** Predicted from previous I or P frames.
        - **B-frames (Bi-directional frames):** Predicted from both past and future frames to achieve maximum compression.
    3.  **Motion Compensation:** The codec tracks and encodes the movement of blocks of pixels from one frame to the next, further reducing the data needed for P and B frames .
- **Real-World Examples:**
    - **MPEG-1:** The basis for Video CD (VCD).
    - **MPEG-2:** Used for DVD video and standard digital television broadcasts .
    - **MPEG-4 Part 10 (also known as H.264/AVC):** The dominant standard for Blu-ray Discs, YouTube, Netflix, and modern video conferencing (like Zoom) . It offers much better compression than MPEG-2.
- **Advantages:**
    - **Very High Compression Ratios:** Essential for storing and streaming full-length movies.
    - **Good Quality:** Modern MPEG standards (like H.264/HEVC) provide excellent quality even at low bitrates.
- **Disadvantages:**
    - **Computationally Complex:** Encoding, in particular, requires significant processing power.
    - **Generation Loss:** Repeatedly encoding and decoding degrades quality (due to the lossy nature).
