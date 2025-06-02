## Unit 5. File Management (6 Hrs)

File management is a critical component of an operating system, responsible for organizing, storing, retrieving, and managing files and directories on secondary storage. It provides a logical view of data to users, abstracting the complexities of physical storage.

### 5.1. File Overview

A **file** is a named collection of related information that is recorded on secondary storage (e.g., hard drives, SSDs). From the user's perspective, a file is the smallest logical unit of storage.

#### 5.1.1. File Naming

Files are given names for user convenience. File naming conventions vary across operating systems:
* **Case Sensitivity:** Some OS (e.g., Linux) are case-sensitive (`report.txt` is different from `Report.txt`), while others (e.g., Windows) are case-insensitive but preserve case.
* **Length Limits:** Older systems had strict limits (e.g., 8.3 in MS-DOS); modern systems support long filenames.
* **Allowed Characters:** Restricted characters (e.g., `/`, `\`, `*`, `?`) are typically reserved for special purposes.
* **Extensions:** Often used to indicate file type (e.g., `.txt`, `.pdf`, `.exe`).

#### 5.1.2. File Structure

File structure refers to how a file is organized internally. Common structures include:
* **Unstructured Sequence of Bytes:** The most common model, used by UNIX/Linux and Windows. The OS views the file as a flat sequence of bytes, and the interpretation is left to the application.
    * **Advantages:** Simple, flexible, no overhead from the OS enforcing structure.
    * **Disadvantages:** Applications must define and manage their own internal structure.
* **Simple Record Structure:** A file is a sequence of fixed-length or variable-length records. Used in older mainframe systems for database-like applications.
* **Complex Structures:** Trees, indices, or databases, often managed by a database management system (DBMS) built on top of the OS's unstructured byte stream.

#### 5.1.3. File Types

File types categorize files based on their content and purpose. The OS or applications use file types to determine how to handle a file.
* **Regular Files:** Contain user information (e.g., text files, images, executables, data files).
* **Directories:** System files that store information about other files and directories.
* **Character Special Files:** Used for character-oriented I/O devices (e.g., keyboards, printers).
* **Block Special Files:** Used for block-oriented I/O devices (e.g., hard drives, CD-ROMs).
* **Pipes/FIFOs:** Used for inter-process communication.
* **Sockets:** Used for network communication.

#### 5.1.4. File Access

File access methods define how information within a file can be read or written.
* **Sequential Access:** Data is read/written in order, from the beginning to the end. Common for text files, audio/video streams.
    * **Advantage:** Simple to implement.
    * **Disadvantage:** Inefficient for random lookups.
* **Random Access (Direct Access):** Data can be read/written at any arbitrary position within the file. Requires seeking to a specific byte offset. Essential for databases.
    * **Advantage:** Fast access to specific records/data.
    * **Disadvantage:** More complex to implement.
* **Indexed Sequential Access:** A hybrid approach. Files are organized sequentially, but an index is maintained to allow faster jumps to specific sections, after which sequential reading can continue.

#### 5.1.5. File Attributes

File attributes are metadata associated with a file, providing information about it.
* **Name:** The symbolic name for the file.
* **Type:** Indicates the file's format or purpose (e.g., `.exe`, `.txt`).
* **Location:** Pointer to the file's starting location on disk.
* **Size:** Current size of the file in bytes, blocks, or records.
* **Protection (Permissions):** Controls who can read, write, or execute the file (e.g., owner, group, others).
* **Time, Date, User Identification:** Time of creation, last modification, last access, and the user ID of the creator/owner.
* **Read-only/Archive/Hidden/System flags:** Specific flags for file behavior.

#### 5.1.6. File Operations

Operating systems provide system calls for users and applications to perform operations on files:
* **Create:** Creates a new file, allocates space, and adds an entry to the directory.
* **Delete:** Removes a file, frees its space, and removes its directory entry.
* **Open:** Prepares a file for use. The OS brings file attributes and metadata into memory and returns a file handle/descriptor.
* **Close:** Releases resources associated with an open file, writes back metadata if dirty.
* **Read:** Reads data from a file into a buffer.
* **Write:** Writes data from a buffer into a file.
* **Seek:** Changes the current read/write position (file pointer) within a file (for random access).
* **Truncate:** Deletes the contents of a file but keeps its attributes.
* **Rename:** Changes the name of a file.

#### 5.1.7. Directory Systems

Directory systems organize files in a hierarchical structure, making it easier for users to locate and manage them.

**a) Single-Level Directory System:**
* **Structure:** All files are contained in a single directory.
* **Advantages:** Simple to implement.
* **Disadvantages:**
    * **Naming Conflicts:** All files must have unique names across the entire system.
    * **Scalability Issues:** Hard to manage a large number of files.
    * **No User Isolation:** No way to group files by user or project.
* **Example:** Early personal computer systems.
* **Diagram Suggestion:** A single box labeled "Root Directory" with arrows pointing to multiple file icons.

**b) Two-Level Directory System:**
* **Structure:** Each user has their own separate directory (User File Directory - UFD) within a master file directory (MFD).
* **Advantages:**
    * **Solves Naming Conflicts:** Users can have files with the same name.
    * **User Isolation:** Each user has their private space.
* **Disadvantages:**
    * **No Sharing:** Difficult to share files between users.
    * Still limited for grouping files within a single user's space.
* **Example:** Some multi-user systems.
* **Diagram Suggestion:** A "Master File Directory" pointing to multiple "User File Directories," each pointing to their respective files.

**c) Hierarchical (Tree-Structured) Directory System:**
* **Structure:** The most common model today. Directories can contain both files and other subdirectories, forming a tree-like structure. There is a single root directory.
* **Advantages:**
    * **No Naming Conflicts:** Files with the same name can exist in different directories.
    * **Logical Grouping:** Files can be organized intuitively by project, type, or user.
    * **Easy Sharing:** Files can be shared by referring to their pathnames.
* **Disadvantages:**
    * More complex to implement.
    * Searching for a file can take longer if the path is deep.
* **Example:** UNIX/Linux, Windows.
* **Diagram Suggestion:** A tree structure starting from a "Root" directory, branching into subdirectories and files.

#### 5.1.8. File System Layout

The file system layout describes how the file system is organized on a disk. A disk is divided into sectors, which are grouped into blocks.
* **Partition Table:** At the beginning of the disk, defines how the disk is divided into partitions.
* **Boot Block:** Contains a small program to bootstrap the operating system.
* **Superblock:** Contains key information about the file system (e.g., total blocks, free block count, inode table size, block size, file system state). Crucial for mounting and checking the file system.
* **Free Block Management Area:** Stores information about free (available) disk blocks. (Discussed in 5.4).
* **Inode List (for UNIX-like systems):** A table of inodes, each describing a file (metadata, pointers to data blocks). (Discussed in 5.2.4).
* **Root Directory:** The top-level directory of the file system.
* **Data Blocks:** The actual storage area for file data and directory contents.

* **Diagram Suggestion:** A linear representation of a disk partition showing sections for Boot Block, Superblock, Free Block List, Inode List, Root Directory, and Data Blocks.

### 5.2. Implementing Files (Disk Space Allocation)

This section details how file data is stored on disk and how the OS manages the disk blocks allocated to a file.

#### 5.2.1. Contiguous Allocation

* **Explanation:** Each file occupies a set of contiguous (adjacent) blocks on the disk. The directory entry for the file stores the starting block address and the length (number of blocks) of the file.
* **Example:**
    * File A (3 blocks): starts at block 0, occupies blocks 0, 1, 2.
    * File B (2 blocks): starts at block 3, occupies blocks 3, 4.
* **Advantages:**
    * **Simple:** Easy to implement.
    * **Excellent Read Performance:** Minimal head movement for sequential access; fast random access (start_block + offset).
* **Disadvantages:**
    * **External Fragmentation:** As files are created and deleted, holes of varying sizes appear in memory, making it difficult to find a contiguous block large enough for new files.
    * **Difficulty with File Growth:** If a file needs to grow, it might require relocating the entire file if adjacent space is not available.
    * **Pre-allocation:** Requires knowing the maximum file size in advance or frequent defragmentation.
* **Diagram Suggestion:** A linear representation of disk blocks, showing files occupying contiguous segments, with gaps representing fragmentation.

#### 5.2.2. Linked List Allocation

* **Explanation:** Each file is stored as a linked list of disk blocks. Each block contains a pointer to the next block in the file. The directory entry for the file stores the starting block address and optionally the ending block address.
* **Example:**
    * File X (3 blocks): Block A points to Block B, Block B points to Block C. Directory points to Block A.
* **Advantages:**
    * **No External Fragmentation:** Files can use any available block; holes are automatically linked into the free list.
    * **Flexible File Growth:** Files can grow dynamically by adding more blocks anywhere on the disk.
* **Disadvantages:**
    * **Poor Random Access Performance:** To reach a specific block (e.g., block $N$), the system must traverse $N-1$ blocks sequentially.
    * **Space Overhead:** Each block needs to store a pointer to the next block, reducing the actual data storage per block.
    * **Reliability Issues:** A single broken pointer can lead to the loss of the rest of the file.
* **Diagram Suggestion:** A linear representation of disk blocks, with arrows showing pointers from one block to the next, forming a chain for a file.

#### 5.2.3. Linked List Allocation using Table in Memory (FAT - File Allocation Table)

* **Explanation:** A variation of linked list allocation where the pointers are stored in a separate table in memory (the File Allocation Table) rather than within the data blocks themselves. Each entry in the FAT corresponds to a disk block.
* **How it works:**
    * The directory entry stores the starting block number of the file.
    * To find the next block, the system consults the FAT entry corresponding to the current block number. The FAT entry contains the block number of the next block.
    * A special value (e.g., -1) indicates the end of a file.
* **Example (FAT):**
    * Directory entry for File A: Starts at block 30.
    * FAT: FAT[30] = 31, FAT[31] = 32, FAT[32] = -1 (end of file).
* **Advantages:**
    * **Improved Random Access:** While still not as fast as contiguous, traversing the FAT in memory is much faster than reading blocks from disk.
    * **No External Fragmentation:** Same as simple linked list.
    * **No Pointer Overhead in Data Blocks:** Data blocks are entirely used for data.
* **Disadvantages:**
    * **FAT Size:** The entire FAT must be in memory for efficient operation, which can be very large for large disks with small block sizes.
    * Still sequential traversal for finding arbitrary blocks, though faster than disk traversal.
* **Diagram Suggestion:** A diagram showing a directory pointing to a starting block in a FAT table. The FAT table then shows a chain of pointers to actual data blocks on disk.

#### 5.2.4. Inodes (Indexed Allocation)

* **Explanation:** Used predominantly in UNIX-like file systems. Each file has an **inode** (index node) which is a small data structure containing all the metadata about the file (owner, permissions, size, creation time, etc.) and, critically, pointers to the file's data blocks on disk.
* **Structure of an Inode (simplified):**
    * File attributes (owner, permissions, size, timestamps).
    * **Direct Pointers:** A fixed number of pointers (e.g., 12) point directly to the first few data blocks of the file.
    * **Single Indirect Pointer:** Points to a disk block that contains *additional direct pointers* to data blocks.
    * **Double Indirect Pointer:** Points to a disk block that contains pointers to *single indirect blocks*.
    * **Triple Indirect Pointer:** Points to a disk block that contains pointers to *double indirect blocks*.
* **Advantages:**
    * **Efficient Random Access:** For small files, direct pointers provide very fast access. For larger files, a few disk reads can locate any block.
    * **No External Fragmentation:** Files can be scattered across the disk.
    * **Supports Large Files:** Indirect pointers allow very large files to be stored.
    * **Flexible Growth:** Files can grow dynamically.
* **Disadvantages:**
    * **Overhead:** For very small files, the inode itself might be larger than the file data.
    * **Multiple Disk Accesses:** For very large files, multiple disk reads are required to traverse indirect pointers to find a data block (e.g., 3 reads for a triple indirect block before the actual data block).
* **Diagram Suggestion:** An inode structure box showing direct, single, double, and triple indirect pointers branching out to data blocks and other index blocks.

### 5.3. Directory Operations, Path Names, Directory Implementation, Shared Files

#### 5.3.1. Directory Operations

Directories are special files that store information about other files and directories. Operations on directories include:
* **Search:** Find an entry for a file.
* **Create File:** Add a new file entry.
* **Delete File:** Remove a file entry.
* **List Directory:** Display the names of files and subdirectories.
* **Rename File:** Change a file's name.
* **Traverse Directory:** Navigate through the directory hierarchy.
* **Create Directory:** Create a new subdirectory.
* **Delete Directory:** Remove an empty subdirectory.

#### 5.3.2. Path Names

* **Path Name:** A string that uniquely identifies a file or directory within a hierarchical file system.
* **Absolute Path Name:** Starts from the root directory and specifies the full path to the file (e.g., `/home/user/documents/report.txt` in UNIX; `C:\Users\User\Documents\report.txt` in Windows).
* **Relative Path Name:** Specifies the path relative to the current working directory (e.g., `documents/report.txt` if the current directory is `/home/user/`).

#### 5.3.3. Directory Implementation

Directories are essentially lists of files and their attributes. Their implementation varies:
* **Linear List:** A simple list of file names and pointers to their respective data blocks or inodes.
    * **Advantages:** Simple to implement.
    * **Disadvantages:** Slow search for large directories. Deletion can be complex.
* **Hash Table:** Uses a hash function to map file names to entries in a hash table, which then point to the file information.
    * **Advantages:** Very fast search and insertion on average.
    * **Disadvantages:** Collisions must be handled. Can be complex to resize.
* **B-Tree/B+Tree:** Used for very large directories in some high-performance file systems.
    * **Advantages:** Efficient searching, insertion, and deletion for large datasets.
    * **Disadvantages:** More complex to implement.

#### 5.3.4. Shared Files

Allowing multiple users or processes to access the same file is crucial for collaboration and resource efficiency.
* **Hard Links:** Create multiple directory entries that all point to the *same inode* (in UNIX-like systems) or file control block.
    * **Characteristics:** All hard links are equally valid; deleting one doesn't delete the file until the last hard link is removed. Only possible within the same file system.
    * **Advantages:** Efficient, original file not distinguishable from link.
    * **Disadvantages:** Cannot span file systems; can't link to directories (to avoid cycles).
* **Symbolic Links (Soft Links):** A special file that contains the *path name* of another file or directory.
    * **Characteristics:** The link is just a pointer to a path. If the original file is deleted or moved, the symbolic link breaks (becomes a "dangling pointer"). Can span file systems and link to directories.
    * **Advantages:** Flexible, can link to any file/directory anywhere.
    * **Disadvantages:** Less efficient (requires extra lookup); dangling pointers are possible.

* **Comparison Table Suggestion:** Create a table comparing Hard Links vs. Soft Links, highlighting differences in concept, deletion impact, spanning file systems, and linking directories.

### 5.4. Free Space Management

Managing free disk blocks is essential for allocating space to new files and reclaiming space from deleted files.

#### 5.4.1. Bitmaps (Bit Vector)

* **Explanation:** A bitmap (or bit vector) is a bit array where each bit corresponds to a disk block. A bit value of `1` typically indicates that the block is allocated (in use), and `0` indicates that it is free.
* **Example:** For a disk with $N$ blocks, a bitmap of $N$ bits is used. If Block 5 is free, the 5th bit is 0. If Block 6 is allocated, the 6th bit is 1.
* **Advantages:**
    * **Simple:** Easy to implement and understand.
    * **Efficient for finding contiguous blocks:** Quickly identify sequences of `0`s for contiguous allocation.
    * **Easy to update:** Changing a bit is fast.
* **Disadvantages:**
    * **Space Overhead:** The bitmap itself can be large for very large disks (e.g., a 1 TB disk with 4 KB blocks needs a 32 MB bitmap).
    * Must be kept in memory for efficient access, or at least portions of it.
* **Numerical Example:**
    * Assume a disk has 16 blocks.
    * Initial state: All blocks free. Bitmap: `0000 0000 0000 0000`
    * Allocate Block 0, 1, 2 (for File A): Bitmap: `1110 0000 0000 0000`
    * Allocate Block 7 (for File B): Bitmap: `1110 0001 0000 0000`
    * Free Block 1: Bitmap: `1010 0001 0000 0000`
* **Diagram Suggestion:** A linear representation of disk blocks with a corresponding bitmap above it, showing 0s for free and 1s for allocated.

#### 5.4.2. Linked List (Free List)

* **Explanation:** All free disk blocks are linked together into a list. The first free block contains a pointer to the second free block, which points to the third, and so on. The OS only needs to store a pointer to the head of this free list.
* **Advantages:**
    * **No Space Overhead in Memory:** Only the pointer to the first free block needs to be in memory. The list itself is distributed across the free blocks on disk.
    * **Simple for allocation:** Just take the head of the list.
* **Disadvantages:**
    * **Poor Performance for Finding Contiguous Blocks:** Difficult and slow to find contiguous blocks for contiguous file allocation.
    * **Reliability Issues:** A single lost pointer can lead to the loss of a large number of free blocks.
    * **Sequential Traversal:** Finding a specific number of free blocks might require traversing a long list on disk.
* **Diagram Suggestion:** A linear representation of disk blocks, showing some allocated blocks and a chain of arrows linking together the free blocks.
