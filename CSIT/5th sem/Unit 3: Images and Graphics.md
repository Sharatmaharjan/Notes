### **Unit 3: Images and Graphics**  
#### **3.1 Digital Image Representation**  
A digital image is a numerical representation of a two-dimensional visual object. It is composed of individual elements called **pixels** (picture elements), each having a specific location and color value. 

---

#### **Key Concepts in Digital Image Representation**  

1. **Pixels**:  
   - The smallest unit of a digital image.  
   - Represented as points or squares arranged in a grid.  
   - Each pixel has an intensity value that determines its color or shade.  
   - Higher resolution images have more pixels, providing greater detail.

2. **Resolution**:  
   - Number of pixels in an image, usually specified as width × height (e.g., 1920 × 1080).  
   - Higher resolution means more detail but requires more storage space.  

3. **Color Models**:  
   - **Grayscale**: Images with shades of gray ranging from black (0) to white (255 for 8-bit images).  
   - **RGB (Red, Green, Blue)**: Most common model for colored images. Each pixel has three values (R, G, B).  
   - **CMYK (Cyan, Magenta, Yellow, Black)**: Used in printing.  
   - **YUV/YCrCb**: Used in video and TV broadcasting.  

4. **Bit Depth**:  
   - Determines the number of colors or shades per pixel.  
   - Example:
     - **1-bit**: Black and white only.  
     - **8-bit**: 256 shades of gray or colors.  
     - **24-bit**: Over 16 million colors (8 bits for each of RGB).

---

#### **Image Formats and Storage Formats**  

Digital images can be stored in various formats, depending on the required quality, compression, and intended application.

1. **Raster Formats** (Pixel-Based):  
   Store images as a grid of colored pixels.  
   - **Examples**:  
     - **BMP**: Uncompressed; large file size; used for simple storage.  
     - **JPEG**: Compressed format; supports lossy compression; commonly used in photography.  
     - **PNG**: Lossless compression; supports transparency.  
     - **GIF**: Supports animation; limited to 256 colors.  

   **Example: PNG vs. JPEG**
   ```text
   - PNG: Higher quality, larger file size, supports transparency.
   - JPEG: Compressed, smaller file size, no transparency support.
   ```

2. **Vector Formats** (Mathematical Representation):  
   Store images as geometric shapes, paths, and text rather than pixels.  
   - **Examples**:  
     - **SVG**: Scalable Vector Graphics, commonly used for web and UI design.  
     - **EPS**: Used in professional printing.  

3. **Hybrid Formats**:  
   Combine raster and vector data.  
   - **Example**: PDF (Portable Document Format).  

---

#### **Image Storage Formats**  

1. **Raw Formats**:  
   - Captures unprocessed image data from devices like cameras.  
   - Example: **RAW**, **DNG**.  

2. **Compressed Formats**:  
   Reduce file size by eliminating redundancy.  
   - **Lossy Compression**: Reduces quality but significantly decreases file size (e.g., JPEG).  
   - **Lossless Compression**: Maintains original quality (e.g., PNG, GIF).

3. **Application-Specific Formats**:  
   Designed for specific applications.  
   - Example: **TIFF** for printing and publishing.

---

### **Summary**
- **Digital Image Representation**: Based on pixels, resolution, color models, and bit depth.  
- **Image Formats**: Include raster, vector, and hybrid, with compression options.  
- **Storage Formats**: Vary based on quality and file size requirements.  

---

### **3.2 Image and Graphics Formats**  

Image and graphics formats define how visual information is stored, compressed, and presented digitally. Each format is designed for specific use cases, balancing factors like quality, file size, compatibility, and intended application.

---

### **Categories of Image and Graphics Formats**  

1. **Raster Formats**  
   - Represent images as a grid of pixels, where each pixel has a color value.  
   - Best suited for photographs and images with complex details.  

2. **Vector Formats**  
   - Store images as mathematical paths, shapes, and text rather than pixels.  
   - Ideal for illustrations, logos, and designs that require scalability.  

3. **Hybrid Formats**  
   - Combine features of both raster and vector formats for specific applications.  

---

### **Common Image and Graphics Formats**  

#### **1. Raster Formats**
- **BMP (Bitmap):**  
  - Stores uncompressed images pixel by pixel.  
  - Large file sizes and high quality.  
  - Use Case: Basic image editing, older applications.  

- **JPEG (Joint Photographic Experts Group):**  
  - Compressed format with lossy compression.  
  - Reduces file size at the cost of some quality.  
  - Use Case: Digital photography, web images.  

- **PNG (Portable Network Graphics):**  
  - Supports lossless compression and transparency.  
  - Use Case: Web design, images with sharp edges or text.  

- **GIF (Graphics Interchange Format):**  
  - Limited to 256 colors but supports animation.  
  - Use Case: Simple animations, memes.  

- **TIFF (Tagged Image File Format):**  
  - High-quality format, supports lossless compression.  
  - Use Case: Professional printing, image archiving.  

#### **2. Vector Formats**
- **SVG (Scalable Vector Graphics):**  
  - XML-based, allowing scalability without losing quality.  
  - Use Case: Web graphics, icons, logos.  

- **EPS (Encapsulated PostScript):**  
  - Supports both vector and raster elements.  
  - Use Case: Professional design and printing.  

- **PDF (Portable Document Format):**  
  - Versatile format combining text, vector, and raster graphics.  
  - Use Case: Document sharing, printing.  

#### **3. Hybrid Formats**
- **PSD (Photoshop Document):**  
  - Proprietary format for Adobe Photoshop.  
  - Supports layers and multiple elements.  
  - Use Case: Advanced image editing.  

- **RAW:**  
  - Captures unprocessed image data from digital cameras.  
  - Requires post-processing.  
  - Use Case: Professional photography.  

---

### **Comparison of Key Formats**

| **Format** | **Type**   | **Compression**   | **Transparency** | **Scalability** | **Best Use Case**                |
|------------|------------|-------------------|------------------|-----------------|-----------------------------------|
| BMP        | Raster     | None             | No               | No              | Basic image editing              |
| JPEG       | Raster     | Lossy            | No               | No              | Photos, web graphics             |
| PNG        | Raster     | Lossless         | Yes              | No              | Transparent images, web design   |
| GIF        | Raster     | Lossless         | Yes              | No              | Simple animations, memes         |
| TIFF       | Raster     | Lossless         | Yes              | No              | High-quality printing            |
| SVG        | Vector     | None             | Yes              | Yes             | Web icons, logos                 |
| EPS        | Vector     | None             | Yes              | Yes             | Professional design              |
| RAW        | Hybrid     | None             | No               | No              | Professional photography         |

---

### **Choosing the Right Format**
1. **Web and Digital Media**:  
   - Use **JPEG** for photos and **PNG** for sharp images or transparency.  

2. **Print Media**:  
   - Use **TIFF** or **EPS** for high-quality output.  

3. **Scalable Graphics**:  
   - Use **SVG** for logos and icons that need to scale.  

4. **Animation**:  
   - Use **GIF** for simple animated graphics.  

5. **Professional Photography**:  
   - Use **RAW** for unprocessed, high-quality image data.  

---

### **Summary**
Image and graphics formats are diverse, catering to different needs like quality, file size, and usability. Understanding the characteristics of each format helps in selecting the appropriate one for specific projects, whether it’s for the web, print, or multimedia applications.
