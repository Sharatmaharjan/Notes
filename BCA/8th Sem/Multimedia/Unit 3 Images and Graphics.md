# **Unit:** 3: Images and Graphics (5 Hrs)


### 3.1 Uses of Images and Graphics

Images and graphics are fundamental to multimedia as they provide visual context and appeal.

- **Enhancing Visual Appeal and Aesthetics:** Graphics make multimedia applications attractive and engaging.
    - **Real-World Example:** The visually rich interface of a mobile game or the splash screen of a mobile app.
- **Conveying Information Quickly and Effectively:** Visuals are processed faster by the human brain than text.
    - **Real-World Example:** Using an infographic to explain complex statistical data, or a roadmap with symbols and icons for navigation.
- **Facilitating Learning and Retention:** Educational material paired with relevant images improves understanding and memory.
    - **Real-World Example:** A biology textbook using detailed diagrams of the human heart alongside text.
- **Supporting Communication and User Interface Design:** Icons and symbols provide intuitive navigation.
    - **Real-World Example:** The 'floppy disk' icon for 'Save', the 'trash can' icon for 'Delete' on a computer desktop .
- **Building Brand Identity:** Logos and specific color schemes create a recognizable brand image.
    - **Real-World Example:** The simple, vector-based swoosh logo of Nike or the bitten apple logo of Apple Inc. .
- **Artistic and Creative Expression:** Digital art, photo manipulation, and illustration are forms of creative output.
    - **Real-World Example:** Digital paintings created in software like Adobe Photoshop or Procreate.

### 3.2 Digital Image Representation

This topic explains how images are stored and processed by a computer.

- **Two Primary Models: Raster and Vector** .
    - **Raster (Bitmap) Images:**
        - **Definition:** Composed of a rectangular grid of tiny squares called **pixels** (picture elements) . Each pixel stores color information.
        - **Representation:** Stored as a 2D array or matrix of pixel values .
        - **Key Characteristics:** 
            - **Resolution-Dependent:** Image quality is fixed at capture. Enlarging causes pixelation (loss of sharpness) .
            - **Best for:** Photographs and complex images with continuous tones .
            - **Real-World Example:** A photo taken on a smartphone (JPEG) or a scanned document (TIFF).
    - **Vector Graphics:**
        - **Definition:** Composed of mathematical formulas, commands, and primitives (points, lines, curves, shapes) to define objects .
        - **Representation:** Stored as a set of instructions (e.g., "draw a circle with radius 'r' at coordinates (x,y)").
        - **Key Characteristics:** 
            - **Resolution-Independent:** Can be scaled infinitely without any loss of quality or increase in file size .
            - **Best for:** Logos, illustrations, typography, and technical drawings .
            - **Real-World Example:** A company logo (SVG), fonts (TrueType/OpenType), and maps.

| Feature | Raster Graphics | Vector Graphics |
| :--- | :--- | :--- |
| **Composition** | Pixels (dots)  | Mathematical paths  |
| **Scalability** | Not scalable; loses quality  | Infinitely scalable  |
| **File Size** | Generally larger  | Generally smaller |
| **Real-World Use** | Photographs  | Logos, Illustrations  |

- **Concepts in Raster Representation:** 
    - **Resolution:** The number of pixels in an image (e.g., 1920x1080). Higher resolution means more detail and a larger file size.
    - **Bit Depth / Color Depth:** The number of bits used to represent the color of a single pixel.
        - 1-bit: Black and white.
        - 8-bit: 256 colors or shades of gray.
        - 24-bit: True Color, over 16 million colors (8 bits each for Red, Green, and Blue).
    - **Sampling and Quantization:** The process of converting an analog image to a digital one.
        - **Sampling:** Digitizing the coordinate values (determining the resolution).
        - **Quantization:** Digitizing the amplitude values (assigning color values to each pixel).

### 3.3 Image and Graphics Format

Different file formats are optimized for different types of images and uses. Choosing the right format is critical for balancing quality and file size.

| Format | Full Form | Color Support | Compression | Key Features & Transparency | Typical Uses  |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **JPEG/JPG** | Joint Photographic Experts Group | 24-bit RGB (Millions) | **Lossy** | No Transparency, No Animation | Photographs, web images  |
| **PNG** | Portable Network Graphics | 24-bit RGB (Millions) & 8-bit (256) | **Lossless** | Supports **Alpha Transparency** | Logos, web graphics, images requiring transparent backgrounds  |
| **GIF** | Graphics Interchange Format | 8-bit (Max 256 colors) | Lossless (LZW) | Supports **Animation**, Basic Transparency | Simple animations, memes, icons  |
| **BMP** | Bitmap | Varies (up to 24-bit) | None / Lossless (RLE) | No Compression (large files) | Legacy Windows applications, not recommended for web  |
| **TIFF/TIF**| Tagged Image File Format | Varies (up to 48-bit) | Lossless | High-quality, supports layers | Professional photography, desktop publishing, scanning  |
| **WebP** | Web Picture format | 24-bit RGB | **Lossy & Lossless** | Supports Transparency & Animation | Modern web images; smaller files than JPEG/PNG  |
| **SVG** | Scalable Vector Graphics | RGB (Vector) | Lossless (text-based) | **Vector Format**, XML-based, Scalable | Logos, icons, illustrations on the web  |
| **RAW** | Raw Image Format | Very High (e.g., 48-bit) | None / Lossless (camera-specific) | Unprocessed sensor data | Professional photography workflow  |

### 3.4 Working with Image and Graphics

This involves using software to create, edit, and manipulate images.

- **Categories of Graphics Software:**
    1.  **Raster Graphics Editors (Paint Programs):** Used for editing photos and creating raster-based art .
        - **Tools:** Brushes, pencils, erasers, clone stamp, filters, layers, selections .
        - **Examples:** Adobe Photoshop, GIMP, MS Paint, Affinity Photo.
        - **Real-World Example:** Retouching a portrait to remove blemishes or changing the background of a photo.
    2.  **Vector Graphics Editors (Draw Programs):** Used for creating illustrations, logos, and layouts .
        - **Tools:** Pen tool, shape tools, path editing, type tools .
        - **Examples:** Adobe Illustrator, CorelDRAW, Inkscape, Affinity Designer.
        - **Real-World Example:** Designing a brand logo that can be printed on a business card or a billboard without losing quality.
    3.  **Drawing & CAD Software:** Used for technical and precision drawings.
        - **Examples:** AutoCAD, SketchUp, Rhino .
    4.  **3D Graphics Software:** Used for modeling, rendering, and animation.
        - **Examples:** Blender, Autodesk Maya, 3ds Max.

- **Common Image Manipulation Techniques:** 
    - **Enhancement:** Improving visual quality (adjusting brightness/contrast, color correction, sharpening).
    - **Restoration:** Repairing damaged or old photographs.
    - **Filtering:** Applying effects like blurring, sharpening, or edge detection.
    - **Geometric Transformations:** Scaling, rotating, skewing, or distorting an image.
    - **Color Adjustment:** Changing hue, saturation, and levels.

### 3.5 Image Synthesis, Analysis, and Transmission

This section covers the lifecycle of an image from creation to delivery.

- **Image Synthesis:**
    - **Definition:** The process of creating images from scratch using computer algorithms and models. It is the core of computer graphics .
    - **Methods:**
        - **Rendering:** Converting a 3D scene (models, lights, textures) into a 2D image .
            - **Real-World Example:** Creating the photorealistic frames for an animated movie like "Frozen" or a CGI scene in a blockbuster film.
        - **Painting/Drawing:** Using software tools to create original 2D art.
        - **Procedural Generation:** Creating textures and models algorithmically.
            - **Real-World Example:** Generating an infinite, unique landscape in a video game like "Minecraft."

- **Image Analysis:**
    - **Definition:** The process of extracting meaningful information from an image. It is the core of computer vision .
    - **Process:** Involves techniques like segmentation (partitioning an image into regions), feature extraction (identifying edges, corners, shapes), and pattern recognition.
    - **Real-World Examples:**
        - **Facial Recognition:** Unlocking a smartphone by analyzing the user's face.
        - **Medical Diagnosis:** Analyzing MRI or CT scans to detect tumors or other anomalies .
        - **Optical Character Recognition (OCR):** Converting a scanned document image into editable text.

- **Image Transmission:**
    - **Definition:** The process of sending digital image data from one point to another over a network .
    - **Challenges and Techniques:** 
        - **Large File Size:** Images, especially high-resolution ones, require significant bandwidth.
        - **Compression:** Essential for reducing file size before transmission. Formats like JPEG (lossy) and PNG (lossless) are used .
        - **Progressive Transmission:** An image is transmitted in multiple passes, allowing a low-quality version to be viewed quickly, which then progressively improves . This is common in web browsing on slow connections.
        - **Quality of Service (QoS):** Networks must manage bandwidth and errors to ensure images are transmitted without corruption or excessive delay.
