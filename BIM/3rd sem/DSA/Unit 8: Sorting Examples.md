**Unit 8: Sorting Examples**
### 1. **Bubble Sort**
**Example Array**: `[5, 3, 8, 4, 6]`

**Passes**:
1. **First Pass**:
   - Compare 5 and 3 → Swap → `[3, 5, 8, 4, 6]`
   - Compare 5 and 8 → No swap → `[3, 5, 8, 4, 6]`
   - Compare 8 and 4 → Swap → `[3, 5, 4, 8, 6]`
   - Compare 8 and 6 → Swap → `[3, 5, 4, 6, 8]`

2. **Second Pass**:
   - Compare 3 and 5 → No swap → `[3, 5, 4, 6, 8]`
   - Compare 5 and 4 → Swap → `[3, 4, 5, 6, 8]`
   - Compare 5 and 6 → No swap → `[3, 4, 5, 6, 8]`

3. **Third Pass**:
   - Compare 3 and 4 → No swap → `[3, 4, 5, 6, 8]`
   - Compare 4 and 5 → No swap → `[3, 4, 5, 6, 8]`

4. **Fourth Pass**:
   - Compare 3 and 4 → No swap → `[3, 4, 5, 6, 8]`

**Final Sorted Array**: `[3, 4, 5, 6, 8]`

---

### 2. **Insertion Sort**
**Example Array**: `[5, 3, 8, 4, 6]`

**Passes**:
1. **First Pass**:
   - Start with the second element (3). Insert it into the sorted part `[5]` → `[3, 5, 8, 4, 6]`

2. **Second Pass**:
   - Take the third element (8). It is already in the correct position → `[3, 5, 8, 4, 6]`

3. **Third Pass**:
   - Take the fourth element (4). Insert it into the sorted part `[3, 5, 8]` → `[3, 4, 5, 8, 6]`

4. **Fourth Pass**:
   - Take the fifth element (6). Insert it into the sorted part `[3, 4, 5, 8]` → `[3, 4, 5, 6, 8]`

**Final Sorted Array**: `[3, 4, 5, 6, 8]`

---

### 3. **Selection Sort**
**Example Array**: `[5, 3, 8, 4, 6]`

**Passes**:
1. **First Pass**:
   - Find the smallest element (3) and swap it with the first element → `[3, 5, 8, 4, 6]`

2. **Second Pass**:
   - Find the smallest element in the remaining array (4) and swap it with the second element → `[3, 4, 8, 5, 6]`

3. **Third Pass**:
   - Find the smallest element in the remaining array (5) and swap it with the third element → `[3, 4, 5, 8, 6]`

4. **Fourth Pass**:
   - Find the smallest element in the remaining array (6) and swap it with the fourth element → `[3, 4, 5, 6, 8]`

**Final Sorted Array**: `[3, 4, 5, 6, 8]`

---

### 4. **Heap Sort**

### Example Array: [7, 3, 9, 2, 5]

### Passes:

#### 1. Build Max-Heap:
Convert the array into a max-heap. The max-heap property ensures that the root is the largest element in the heap.

- Original array: [7, 3, 9, 2, 5]
- After building max-heap: [9, 5, 7, 2, 3]

---

#### 2. First Pass:
- Swap the root (9) with the last element (3) → [3, 5, 7, 2, 9]
- Rebuild the max-heap for the remaining array → [7, 5, 3, 2]

---

#### 3. Second Pass:
- Swap the root (7) with the last element (2) → [2, 5, 3, 7, 9]
- Rebuild the max-heap for the remaining array → [5, 2, 3]

---

#### 4. Third Pass:
- Swap the root (5) with the last element (3) → [3, 2, 5, 7, 9]
- Rebuild the max-heap for the remaining array → [3, 2]

---

#### 5. Fourth Pass:
- Swap the root (3) with the last element (2) → [2, 3, 5, 7, 9]
- No need to rebuild the heap as only one element remains.

### Final Sorted Array: [2, 3, 5, 7, 9]

---

### 5. **Quicksort**
**Example Array**: `[5, 3, 8, 4, 6]`

**Passes**:
1. **First Partition**:
   - Choose pivot = 6.
   - Partition the array into two sub-arrays:
     - Elements less than 6: `[5, 3, 4]`
     - Elements greater than 6: `[8]`
   - Array after partition: `[5, 3, 4, 6, 8]`

2. **Sort Left Sub-array**:
   - Choose pivot = 4.
   - Partition the sub-array:
     - Elements less than 4: `[3]`
     - Elements greater than 4: `[5]`
   - Sub-array after partition: `[3, 4, 5]`

3. **Sort Right Sub-array**:
   - The sub-array `[8]` is already sorted.

**Final Sorted Array**: `[3, 4, 5, 6, 8]`

---

### 6. **Mergesort**
**Example Array**: `[5, 3, 8, 4, 6]`

**Passes**:
1. **Divide**:
   - Split the array into two halves: `[5, 3]` and `[8, 4, 6]`

2. **Sort Left Half**:
   - Split `[5, 3]` into `[5]` and `[3]`.
   - Merge `[5]` and `[3]` → `[3, 5]`

3. **Sort Right Half**:
   - Split `[8, 4, 6]` into `[8]` and `[4, 6]`.
   - Split `[4, 6]` into `[4]` and `[6]`.
   - Merge `[4]` and `[6]` → `[4, 6]`
   - Merge `[8]` and `[4, 6]` → `[4, 6, 8]`

4. **Merge Both Halves**:
   - Merge `[3, 5]` and `[4, 6, 8]` → `[3, 4, 5, 6, 8]`

**Final Sorted Array**: `[3, 4, 5, 6, 8]`

---

### 7. **Radix Sort**
**Example Array**: `[170, 45, 75, 90, 802, 24, 2, 66]`

**Passes**:
1. **Sort by Units Place**:
   - `[170, 90, 802, 2, 24, 45, 75, 66]`

2. **Sort by Tens Place**:
   - `[802, 2, 24, 45, 66, 170, 75, 90]`

3. **Sort by Hundreds Place**:
   - `[2, 24, 45, 66, 75, 90, 170, 802]`

**Final Sorted Array**: `[2, 24, 45, 66, 75, 90, 170, 802]`

---

### Sorting in `java.util`
**Example Array**: `[5, 3, 8, 4, 6]`

**Using `Arrays.sort()`**:
1. Input: `[5, 3, 8, 4, 6]`
2. Output: `[3, 4, 5, 6, 8]`

**Using `Collections.sort()`**:
1. Input: `[5, 3, 8, 4, 6]`
2. Output: `[3, 4, 5, 6, 8]`

---

