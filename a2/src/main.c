// all answers are written in c
// Satyam Tiwari (1024030088)

/*
1) Implement the Binary search algorithm regarded as a fast search algorithm
with run-time complexity of Ο(log n) in comparison to the Linear Search.
*/
#include <stdio.h>

int main() {
    int arr[100];
    int n = 0;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter elements of array: \n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter element to search: ");
    scanf("%d", &key);

    printf("[");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("]\n");

    printf("Sorting the array using Bubble Sort...\n");

    // Bubble Sort
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp   = arr[j];
                arr[j]     = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("[");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("]\n");

    int left = 0, right = n - 1, mid;
    int found = -1;

    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == key) {
            found = mid;
            break;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (found > 0) {
        printf("Element found at index: %d\n", found);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}

/*
2) Bubble Sort is the simplest sorting algorithm that works by repeatedly
swapping the adjacent elements if they are in wrong order. Code the Bubble
sort with the following elements: 64 34 25 12 22 11 90
*/
#include <stdio.h>

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n     = sizeof(arr) / sizeof(arr[0]);
    printf("[");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("]\n");

    // Bubble Sort
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp   = arr[j];
                arr[j]     = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("[");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("]\n");

    return 0;
}

/*
3) Design the Logic to Find a Missing Number in a Sorted Array.
Assumptions: The array contains n-1 elements in the range of 1 to n.
*/
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8};
    int len   = (sizeof(arr) / sizeof(*arr));
    int n     = len + 1;  // Since one number is missing
    int total = (n * (n + 1)) / 2;
    int sum   = 0;
    for (int i = 0; i < len; ++i) {
        sum += arr[i];
    }

    int missingNumber = total - sum;
    printf("The missing number is: %d\n", missingNumber);
    return 0;
}

/*
4) String Related Programs
(a) Write a program to concatenate one string to another string.
(b) Write a program to reverse a string.
(c) Write a program to delete all the vowels from the string.
(d) Write a program to sort the strings in alphabetical order.
(e) Write a program to convert a character from uppercase to lowercase.
*/
#include <stdio.h>
#include <string.h>

void concat(char* str1, char* str2) {
    while (*str1)
        str1++;
    while ((*str1++ = *str2++))
        ;
}

void reverse(char* str) {
    int len = strlen(str);
    int mid = len / 2;
    for (int i = 0; i < mid; ++i) {
        char temp        = str[i];
        str[i]           = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void deleteVowels(char* str) {
    char* src  = str;
    char* dest = str;
    while (*src) {
        switch (*src) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U': src++; break;
            default : *dest++ = *src++; break;
        }
    }
    *dest = '\0';
}

void sortAlpha(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            if (str[j] > str[j + 1]) {
                char temp  = str[j];
                str[j]     = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

void toLowerCase(char* str) {
    while (*str) {
        if ('A' <= *str && *str <= 'Z') {
            *str += 32;
        }
        str++;
    }
}

int main() {
    char str1[100] = "Hello, ";
    char str2[100] = "World!";

    printf("Original String 1: %s\n", str1);
    printf("Original String 2: %s\n", str2);

    concat(str1, str2);
    printf("Concatenated String (String 1): %s\n", str1);

    reverse(str1);
    printf("Reversed String: %s\n", str1);

    deleteVowels(str1);
    printf("String after deleting vowels: %s\n", str1);

    sortAlpha(str1);
    printf("Sorted String in alphabetical order: %s\n", str1);

    char str3[100] = "PROGRAMMING";
    toLowerCase(str3);
    printf("Lowercase String: %s\n", str3);

    return 0;
}

/*
5) Space required to store any two-dimensional array is number oƒ rows ×
number oƒ columns. Assuming array is used to store elements of the following
matrices, implement an efficient way that reduces the space requirement. (a)
Diagonal Matrix. (b) Tri-diagonal Matrix. (c) Lower triangular Matrix. (d)
Upper triangular Matrix. (e) Symmetric Matrix
*/
#include <stdio.h>
#include <stdlib.h>

void diagonalMatrix() {
    int size;
    printf("Enter the size for Diagonal Matrix: ");
    scanf("%d", &size);

    int* diagonal = malloc(size * sizeof(int));
    printf("Enter the diagonal elements:\n");

    for (int i = 0; i < size; ++i) {
        printf("Matrix [%d][%d]: ", i + 1, i + 1);
        scanf("%d", &diagonal[i]);
    }

    printf("Diagonal Matrix:\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                printf("%d ", diagonal[i]);
            } else {
                printf("0 ");
            }
        }
        puts("");
    }
    puts("");

    free(diagonal);
}

void triDiagonalMatrix() {
    int size;
    printf("Enter the size for Tri-Diagonal Matrix: ");
    scanf("%d", &size);

    int* triDiagonal = malloc((3 * size - 2) * sizeof(int));
    int* ptr         = triDiagonal;

    printf("Enter the diagonal elements:\n");
    for (int i = 0; i < size; ++i) {
        printf("Matrix [%d][%d]: ", i + 1, i + 1);
        scanf("%d", ptr);
        ++ptr;
    }

    printf("Enter the first upper diagonal elements:\n");
    for (int i = 0; i < size - 1; ++i) {
        printf("Matrix [%d][%d]: ", i + 1, i + 2);
        scanf("%d", ptr);
        ++ptr;
    }

    printf("Enter the first lower diagonal elements:\n");
    for (int i = 0; i < size - 1; ++i) {
        printf("Matrix [%d][%d]: ", i + 2, i + 1);
        scanf("%d", ptr);
        ++ptr;
    }

    printf("Tri-Diagonal Matrix:\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                printf("%d ", triDiagonal[i]);
            } else if (i == j - 1) {
                printf("%d ", triDiagonal[size + i]);
            } else if (i - 1 == j) {
                printf("%d ", triDiagonal[size + size - 1 + j]);
            } else {
                printf("0 ");
            }
        }
        puts("");
    }
    puts("");

    free(triDiagonal);
}

int LowerTriangularMatrixGet(int* lowerTri, int size, int row, int col) {
    if (row < col) return 0;

    /*
      Calculate the gap from the col index to the diagonal element required
      Example:
      3 0 0 0
      2 6 0 0
      6 6 2 0
      7 8 4 1

      This would be stored as: 3 6 2 1 2 6 4 6 8 7
      - Getting M[2][1] (6) would require us to find the gap from main diagonal
      M[1][1] (6) (the gap is of 4 elements; gap = initialGap)
      - Getting M[2][0] (6) would require us to find the gap from main diagonal
      M[0][0] (3) (the gap is of 4+3 elements; gap = initialGap + initialGap-1)
    */
    int gap        = 0;
    int count      = row - col;
    int initialGap = size;
    while (count > 0) {
        gap += initialGap;
        initialGap--;
        count--;
    }
    return lowerTri[col + gap];
}

void lowerTriangularMatrix() {
    int size;
    printf("Enter the size for Lower Triangular Matrix: ");
    scanf("%d", &size);

    int* lowerTri = malloc(((size * (size + 1)) / 2) * sizeof(int));

    printf("Enter the lower triangular elements:\n");
    int currentIndex  = 0;
    int diagonalItems = size;
    while (diagonalItems > 0) {
        int diagonalIndex = size - diagonalItems;
        printf("Enter the elements for diagonal %d:\n", diagonalIndex + 1);
        for (int i = 0; i < diagonalItems; ++i) {
            int diagonalItemIndex = diagonalIndex + i;
            printf("Matrix [%d][%d]: ", diagonalItemIndex + 1, i + 1);
            scanf("%d", &lowerTri[currentIndex++]);
        }
        diagonalItems--;
    }

    printf("Stored elements in array: ");
    for (int i = 0; i < ((size * (size + 1)) / 2); ++i) {
        printf("%d ", lowerTri[i]);
    }
    puts("");

    printf("Lower Triangular Matrix:\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", LowerTriangularMatrixGet(lowerTri, size, i, j));
        }
        puts("");
    }
    puts("");

    free(lowerTri);
}

int UpperTriangularMatrixGet(int* upperTri, int size, int row, int col) {
    if (row > col) return 0;

    /*
      Same logic as Lower Triangular Matrix, but for upper triangular matrix
    */
    int gap        = 0;
    int count      = col - row;
    int initialGap = size;
    while (count > 0) {
        gap += initialGap;
        initialGap--;
        count--;
    }
    return upperTri[row + gap];
}

void upperTriangularMatrix() {
    int size;
    printf("Enter the size for Upper Triangular Matrix: ");
    scanf("%d", &size);

    int* upperTri = malloc(((size * (size + 1)) / 2) * sizeof(int));

    printf("Enter the upper triangular elements:\n");
    int currentIndex  = 0;
    int diagonalItems = size;
    while (diagonalItems > 0) {
        int diagonalIndex = size - diagonalItems;
        printf("Enter the elements for diagonal %d:\n", diagonalIndex + 1);
        for (int i = 0; i < diagonalItems; ++i) {
            int diagonalItemIndex = diagonalIndex + i;
            printf("Matrix [%d][%d]: ", diagonalItemIndex + 1, i + 1);
            scanf("%d", &upperTri[currentIndex++]);
        }
        diagonalItems--;
    }

    printf("Stored elements in array: ");
    for (int i = 0; i < ((size * (size + 1)) / 2); ++i) {
        printf("%d ", upperTri[i]);
    }
    puts("");

    printf("Upper Triangular Matrix:\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", UpperTriangularMatrixGet(upperTri, size, i, j));
        }
        puts("");
    }
    puts("");

    free(upperTri);
}

int SymmetricMatrixGet(int* symMat, int size, int row, int col) {
    int low  = row;
    int high = col;
    if (row < col) {
        low  = row;
        high = col;
    } else if (row > col) {
        low  = col;
        high = row;
    }

    /*
      Same logic as Lower Triangular Matrix, but for symmetric matrix
    */
    int gap        = 0;
    int count      = high - low;
    int initialGap = size;
    while (count > 0) {
        gap += initialGap;
        initialGap--;
        count--;
    }
    return symMat[low + gap];
}

void symmetricMatrix() {
    int size;
    printf("Enter the size for Symmetric Matrix: ");
    scanf("%d", &size);

    int* symMat = malloc(((size * (size + 1)) / 2) * sizeof(int));

    printf("Enter the diagonal elements:\n");
    int currentIndex  = 0;
    int diagonalItems = size;
    while (diagonalItems > 0) {
        int diagonalIndex = size - diagonalItems;
        printf("Enter the elements for diagonal %d:\n", diagonalIndex + 1);
        for (int i = 0; i < diagonalItems; ++i) {
            int diagonalItemIndex = diagonalIndex + i;
            printf("Matrix [%d][%d]: ", diagonalItemIndex + 1, i + 1);
            scanf("%d", &symMat[currentIndex++]);
        }
        diagonalItems--;
    }

    printf("Stored elements in array: ");
    for (int i = 0; i < ((size * (size + 1)) / 2); ++i) {
        printf("%d ", symMat[i]);
    }
    puts("");

    printf("Symmetric Matrix:\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", SymmetricMatrixGet(symMat, size, i, j));
        }
        puts("");
    }
    puts("");

    free(symMat);
}

int main() {
    diagonalMatrix();
    triDiagonalMatrix();
    lowerTriangularMatrix();
    upperTriangularMatrix();
    symmetricMatrix();
    return 0;
}

/*
6) Write a program to implement the following operations on a Sparse Matrix,
assuming the matrix is represented using a triplet.
(a) Transpose of a matrix.
(b) Addition of two matrices.
(c) Multiplication of two matrices.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int ROW_INDEX   = 0;
const int COL_INDEX   = 1;
const int VALUE_INDEX = 2;

typedef struct SparseMatrix {
    int* data;
    int rows;
    int cols;
    int tripletCount;
} SparseMatrix;

SparseMatrix SparseMatrixNewInput();
void SparseMatrixSortTriplets(SparseMatrix* sparseMat);
int* SparseMatrixGetTriplet(SparseMatrix* sparseMat, int index);
int SparseMatrixGet(SparseMatrix* sparseMat, int row, int col);
void SparseMatrixDisplay(SparseMatrix* sparseMat);
void SparseMatrixFree(SparseMatrix* sparseMat);

SparseMatrix SparseMatrixNewInput() {
    SparseMatrix sparseMat = {0};
    printf("Enter number of rows and columns in the Sparse Matrix: ");
    scanf("%d%d", &sparseMat.rows, &sparseMat.cols);

    int N;
    printf("Enter the number of non-zero elements (triplets) in the Sparse "
           "Matrix: ");
    scanf("%d", &N);
    sparseMat.tripletCount = N;

    sparseMat.data = malloc(N * 3 * sizeof(int));

    for (int i = 0; i < N; ++i) {
        int* data = SparseMatrixGetTriplet(&sparseMat, i);
        int row, col, val;
        printf("Enter the triplet for non-zero element %d (row, col, value): ",
               i + 1);
        scanf("%d%d%d", &row, &col, &val);
        data[ROW_INDEX]   = row - 1;
        data[COL_INDEX]   = col - 1;
        data[VALUE_INDEX] = val;
    }

    SparseMatrixSortTriplets(&sparseMat);

    for (int i = 0; i < 3 * N; ++i) {
        printf("%d ", sparseMat.data[i]);
    }
    puts("");

    return sparseMat;
}

void SparseMatrixSortTriplets(SparseMatrix* sparseMat) {
    for (int i = 0; i < sparseMat->tripletCount - 1; ++i) {
        for (int j = 0; j < sparseMat->tripletCount - i - 1; ++j) {
            int* triplet1 = SparseMatrixGetTriplet(sparseMat, j);
            int* triplet2 = SparseMatrixGetTriplet(sparseMat, j + 1);
            if (triplet1[ROW_INDEX] > triplet2[ROW_INDEX]
                || (triplet1[ROW_INDEX] == triplet2[ROW_INDEX]
                    && triplet1[COL_INDEX] > triplet2[COL_INDEX])) {
                // Swapping memory (triplet arrays)
                int temp[3];
                memcpy(temp, triplet1, 3 * sizeof(int));
                memcpy(triplet1, triplet2, 3 * sizeof(int));
                memcpy(triplet2, temp, 3 * sizeof(int));
            }
        }
    }
}

int* SparseMatrixGetTriplet(SparseMatrix* sparseMat, int index) {
    return sparseMat->data + index * 3;
}

int SparseMatrixGet(SparseMatrix* sparseMat, int row, int col) {
    int index    = 0;
    int* triplet = SparseMatrixGetTriplet(sparseMat, index);
    while (index < sparseMat->tripletCount && triplet[ROW_INDEX] < row) {
        index++;
        triplet = SparseMatrixGetTriplet(sparseMat, index);
    }

    if (triplet[ROW_INDEX] != row) return 0;

    while (index < sparseMat->tripletCount && triplet[ROW_INDEX] == row
           && triplet[COL_INDEX] < col) {
        index++;
        triplet = SparseMatrixGetTriplet(sparseMat, index);
    }
    if (triplet[ROW_INDEX] != row || triplet[COL_INDEX] != col) return 0;

    return triplet[VALUE_INDEX];
}

void SparseMatrixDisplay(SparseMatrix* sparseMat) {
    for (int i = 0; i < sparseMat->rows; ++i) {
        for (int j = 0; j < sparseMat->cols; ++j) {
            int value = SparseMatrixGet(sparseMat, i, j);
            printf("%3d ", value);
        }
        puts("");
    }
}

void SparseMatrixFree(SparseMatrix* sparseMat) {
    free(sparseMat->data);
    sparseMat->data         = NULL;
    sparseMat->rows         = 0;
    sparseMat->cols         = 0;
    sparseMat->tripletCount = 0;
}

void transposeSparseMatrix() {
    printf("Transpose of the Sparse Matrix: \n");
    SparseMatrix sparseMat = SparseMatrixNewInput();
    SparseMatrixDisplay(&sparseMat);

    printf("Transposing sparse matrix ...\n");
    for (int i = 0; i < sparseMat.tripletCount; ++i) {
        int* triplet       = SparseMatrixGetTriplet(&sparseMat, i);
        int temp           = triplet[ROW_INDEX];
        triplet[ROW_INDEX] = triplet[COL_INDEX];
        triplet[COL_INDEX] = temp;
    }
    SparseMatrixSortTriplets(&sparseMat);
    SparseMatrixDisplay(&sparseMat);
    SparseMatrixFree(&sparseMat);
}

void addSparseMatrices() {
    printf("Addition of two Sparse Matrices: \n");
    SparseMatrix s1 = SparseMatrixNewInput();
    SparseMatrix s2 = SparseMatrixNewInput();
    puts("");
    SparseMatrixDisplay(&s1);
    puts("");
    SparseMatrixDisplay(&s2);
    puts("");

    if (s1.rows != s2.rows || s1.cols != s2.cols) {
        printf("Can't add matrices with different dimensions\n");
        return;
    }

    SparseMatrix s3 = {0};
    s3.rows         = s1.rows;
    s3.cols         = s1.cols;

    int* tempTriplets =
        malloc((s1.tripletCount + s2.tripletCount) * 3 * sizeof(int));

    for (int i = 0; i < s3.rows; ++i) {
        for (int j = 0; j < s3.cols; ++j) {
            int val1 = SparseMatrixGet(&s1, i, j);
            int val2 = SparseMatrixGet(&s2, i, j);
            int val3 = val1 + val2;

            if (val3 != 0) {
                int* triplet3         = tempTriplets + 3 * s3.tripletCount;
                triplet3[ROW_INDEX]   = i;
                triplet3[COL_INDEX]   = j;
                triplet3[VALUE_INDEX] = val3;
                s3.tripletCount++;
            }
        }
    }

    s3.data      = realloc(tempTriplets, s3.tripletCount * 3 * sizeof(int));
    tempTriplets = NULL;

    printf("The sum of the provided matrices:\n");
    SparseMatrixDisplay(&s3);

    SparseMatrixFree(&s1);
    SparseMatrixFree(&s2);
    SparseMatrixFree(&s3);
}

void multiplySparseMatrices() {
    printf("Multiplication of two Sparse Matrices: \n");
    SparseMatrix s1 = SparseMatrixNewInput();
    SparseMatrix s2 = SparseMatrixNewInput();
    puts("");
    SparseMatrixDisplay(&s1);
    puts("");
    SparseMatrixDisplay(&s2);
    puts("");

    if (s1.cols != s2.rows) {
        printf("Can't multiply matrices with different dimensions\n");
        return;
    }

    SparseMatrix s3 = {0};
    s3.rows         = s1.rows;
    s3.cols         = s2.cols;

    int* tempTriplets =
        malloc((s1.tripletCount + s2.tripletCount) * 3 * sizeof(int));

    for (int i = 0; i < s3.rows; ++i) {
        for (int j = 0; j < s3.cols; ++j) {
            int val = 0;
            for (int k = 0; k < s1.cols; ++k) {
                val += SparseMatrixGet(&s1, i, k) * SparseMatrixGet(&s2, k, j);
            }

            if (val != 0) {
                int* triplet3         = tempTriplets + 3 * s3.tripletCount;
                triplet3[ROW_INDEX]   = i;
                triplet3[COL_INDEX]   = j;
                triplet3[VALUE_INDEX] = val;
                s3.tripletCount++;
            }
        }
    }

    s3.data      = realloc(tempTriplets, s3.tripletCount * 3 * sizeof(int));
    tempTriplets = NULL;

    printf("The multiplication of the provided matrices:\n");
    SparseMatrixDisplay(&s3);

    SparseMatrixFree(&s1);
    SparseMatrixFree(&s2);
    SparseMatrixFree(&s3);
}

/*
Sample Inputs:
  4 4 5 1 2 10 1 4 12 3 3 5 4 1 15 4 2 12
  4 4 5 1 3 8 2 4 23 3 3 9 4 1 20 4 2 25
*/

int main() {
    transposeSparseMatrix();
    addSparseMatrices();
    multiplySparseMatrices();
    return 0;
}

/*
7) Let A[1 .... n] be an array of n real numbers. A pair (A[i], A[j ]) is
said to be an inversion if these numbers are out of order, i.e., i < j but
A[i]>A[j ]. Write a program to count the number of inversions in an array.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    int* arr = malloc(N * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }

    printf("Array: [");
    for (int i = 0; i < N; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\b]\n");

    int inversions = 0;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (arr[i] > arr[j]) {
                printf("Inversion found: ([%d] = %d, [%d] = %d)\n", i, arr[i],
                       j, arr[j]);
                inversions++;
            }
        }
    }
    printf("Total inversions: %d\n", inversions);

    free(arr);

    return 0;
}

/*
8) Write a program to count the total number of distinct elements in an array
of length n.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    int* arr = malloc(N * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }

    printf("Array: [");
    for (int i = 0; i < N; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\b]\n");

    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp   = arr[j];
                arr[j]     = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Array: [");
    for (int i = 0; i < N; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\b]\n");

    int distinctCount = 0;
    for (int i = 0; i < N; ++i) {
        distinctCount++;
        // Skip duplicates
        while (i < N - 1 && arr[i] == arr[i + 1])
            i++;
    }
    printf("Total distinct elements: %d\n", distinctCount);

    free(arr);

    return 0;
}
