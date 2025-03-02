# Unit 8: Sorting (6 LHs)

## Introduction to Sorting
Sorting is a fundamental operation in computer science where the elements of a collection (such as an array or a list) are arranged in a specific order, typically in non-decreasing or non-increasing order. Sorting is essential for efficient searching, data analysis, and other computational tasks.

### Key Concepts:
- **Internal Sorting**: All the data to be sorted is stored in the main memory (RAM). This is suitable for small datasets.
- **External Sorting**: Data is stored in external storage (like hard disks) and loaded into memory in chunks. This is used for large datasets that cannot fit into memory.

---

## Sorting Algorithms

### 1. **Bubble Sort**
- **Description**: Bubble Sort repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. This process is repeated until the list is sorted.
- **Time Complexity**:
  - Best Case: \(O(n)\) (when the list is already sorted)
  - Average Case: \(O(n^2)\)
  - Worst Case: \(O(n^2)\)
- **Space Complexity**: \(O(1)\) (in-place sorting)
- **Stability**: Stable
- **Use Case**: Suitable for small datasets or nearly sorted data.

```java
void bubbleSort(int[] arr) {
    int n = arr.length;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
```

---

### 2. **Insertion Sort**
- **Description**: Insertion Sort builds the final sorted array one element at a time. It takes each element and inserts it into its correct position in the already sorted part of the array.
- **Time Complexity**:
  - Best Case: \(O(n)\) (when the list is already sorted)
  - Average Case: \(O(n^2)\)
  - Worst Case: \(O(n^2)\)
- **Space Complexity**: \(O(1)\) (in-place sorting)
- **Stability**: Stable
- **Use Case**: Efficient for small datasets or nearly sorted data.

```java
void insertionSort(int[] arr) {
    int n = arr.length;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
```

---

### 3. **Selection Sort**
- **Description**: Selection Sort divides the array into a sorted and an unsorted part. It repeatedly selects the smallest (or largest) element from the unsorted part and swaps it with the first unsorted element.
- **Time Complexity**:
  - Best Case: \(O(n^2)\)
  - Average Case: \(O(n^2)\)
  - Worst Case: \(O(n^2)\)
- **Space Complexity**: \(O(1)\) (in-place sorting)
- **Stability**: Not stable
- **Use Case**: Suitable for small datasets.

```java
void selectionSort(int[] arr) {
    int n = arr.length;
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap arr[i] and arr[minIndex]
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}
```

---

### 4. **Heap Sort**
- **Description**: Heap Sort uses a binary heap data structure to sort elements. It first builds a max-heap (or min-heap) and then repeatedly extracts the maximum (or minimum) element from the heap and places it at the end of the array.
- **Time Complexity**:
  - Best Case: \(O(n \log n)\)
  - Average Case: \(O(n \log n)\)
  - Worst Case: \(O(n \log n)\)
- **Space Complexity**: \(O(1)\) (in-place sorting)
- **Stability**: Not stable
- **Use Case**: Suitable for large datasets.

```java
void heapSort(int[] arr) {
    int n = arr.length;

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        // Swap root (max element) with last element
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify the reduced heap
        heapify(arr, i, 0);
    }
}

void heapify(int[] arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
```

---

### 5. **Quicksort**
- **Description**: Quicksort is a divide-and-conquer algorithm. It selects a pivot element and partitions the array into two sub-arrays such that elements less than the pivot are on the left, and elements greater than the pivot are on the right. It then recursively sorts the sub-arrays.
- **Time Complexity**:
  - Best Case: \(O(n \log n)\)
  - Average Case: \(O(n \log n)\)
  - Worst Case: \(O(n^2)\) (when the pivot is the smallest or largest element)
- **Space Complexity**: \(O(\log n)\) (due to recursion)
- **Stability**: Not stable
- **Use Case**: Suitable for large datasets.

```java
void quickSort(int[] arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int[] arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i+1] and arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}
```

---

### 6. **Mergesort**
- **Description**: Mergesort is a divide-and-conquer algorithm that divides the array into two halves, recursively sorts them, and then merges the two sorted halves.
- **Time Complexity**:
  - Best Case: \(O(n \log n)\)
  - Average Case: \(O(n \log n)\)
  - Worst Case: \(O(n \log n)\)
- **Space Complexity**: \(O(n)\) (requires additional space for merging)
- **Stability**: Stable
- **Use Case**: Suitable for large datasets, especially when stability is required.

```java
void mergeSort(int[] arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int[] arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int[] L = new int[n1];
    int[] R = new int[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
```

---

### 7. **Radix Sort**
- **Description**: Radix Sort is a non-comparative sorting algorithm that sorts numbers by processing individual digits. It uses counting sort as a subroutine.
- **Time Complexity**:
  - Best Case: \(O(nk)\) (where \(k\) is the number of digits)
  - Average Case: \(O(nk)\)
  - Worst Case: \(O(nk)\)
- **Space Complexity**: \(O(n + k)\)
- **Stability**: Stable
- **Use Case**: Suitable for sorting integers or strings with fixed-length keys.

```java
void radixSort(int[] arr) {
    int max = getMax(arr);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int getMax(int[] arr) {
    int max = arr[0];
    for (int i = 1; i < arr.length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int[] arr, int exp) {
    int n = arr.length;
    int[] output = new int[n];
    int[] count = new int[10];

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
```

---

## Efficiency of Sorting Algorithms
| Algorithm      | Best Case       | Average Case    | Worst Case      | Space Complexity | Stable? |
|----------------|-----------------|-----------------|-----------------|------------------|---------|
| Bubble Sort    | \(O(n)\)        | \(O(n^2)\)      | \(O(n^2)\)      | \(O(1)\)         | Yes     |
| Insertion Sort | \(O(n)\)        | \(O(n^2)\)      | \(O(n^2)\)      | \(O(1)\)         | Yes     |
| Selection Sort | \(O(n^2)\)      | \(O(n^2)\)      | \(O(n^2)\)      | \(O(1)\)         | No      |
| Heap Sort      | \(O(n \log n)\) | \(O(n \log n)\) | \(O(n \log n)\) | \(O(1)\)         | No      |
| Quicksort      | \(O(n \log n)\) | \(O(n \log n)\) | \(O(n^2)\)      | \(O(\log n)\)    | No      |
| Mergesort      | \(O(n \log n)\) | \(O(n \log n)\) | \(O(n \log n)\) | \(O(n)\)         | Yes     |
| Radix Sort     | \(O(nk)\)       | \(O(nk)\)       | \(O(nk)\)       | \(O(n + k)\)     | Yes     |

---

## Sorting in `java.util`
Java provides built-in methods for sorting in the `java.util` package:
1. **`Arrays.sort()`**: Sorts arrays of primitive types and objects.
   - For primitive types, it uses a tuned version of Quicksort.
   - For objects, it uses Mergesort (stable).
   ```java
   int[] arr = {5, 2, 9, 1, 5};
   Arrays.sort(arr);
   ```

2. **`Collections.sort()`**: Sorts lists of objects.
   - Uses Mergesort (stable).
   ```java
   List<Integer> list = Arrays.asList(5, 2, 9, 1, 5);
   Collections.sort(list);
   ```

3. **Custom Sorting**: You can use `Comparator` to define custom sorting logic.
   ```java
   Collections.sort(list, (a, b) -> b - a); // Sort in descending order
   ```

---

This concludes the detailed notes on Sorting in Java. Let me know if you need further clarification!
