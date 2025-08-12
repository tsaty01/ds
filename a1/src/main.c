// all answers are written in c
// Satyam Tiwari (1024030088)

// 1)
// -----------------------------------------------------------------------------------------------
#include <stdio.h>

int main() {
  int arr[100];
  int n = 0;
  int choice;
  int i;
  int pos, val;
  int found = 0;

  while (1) {
    printf("\nMENU\n");
    printf("1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. "
           "EXIT\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter size of array: ");
      scanf("%d", &n);
      printf("Enter elements:\n");
      for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
      }
      break;

    case 2:
      printf("Array elements are: ");
      printf("[");
      for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
      }
      printf("]\n");
      break;

    case 3:
      printf("Enter position to insert: ");
      scanf("%d", &pos);
      printf("Enter value to insert: ");
      scanf("%d", &val);
      for (i = n; i > pos - 1; i--) {
        arr[i] = arr[i - 1];
      }
      arr[pos - 1] = val;
      n++;
      break;

    case 4:
      printf("Enter position to delete: ");
      scanf("%d", &pos);
      for (i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
      }
      n--;
      break;

    case 5:
      printf("Enter value to search: ");
      scanf("%d", &val);
      found = 0;
      for (i = 0; i < n; i++) {
        if (arr[i] == val) {
          printf("Found at index %d\n", i);
          found = 1;
          break;
        }
      }
      if (!found)
        printf("Value not found.\n");
      break;

    case 6:
      printf("Exiting...\n");
      return 0;

    default:
      printf("Invalid choice! select from 1 to 6!\n");
      break;
    }
  }

  return 0;
}

// 2)
// -----------------------------------------------------------------------------------------------
#include <stdio.h>

int main() {
  int arr[100];
  int n, i, j, k;

  printf("Enter size of array: ");
  scanf("%d", &n);
  printf("Enter elements:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n;) {
      if (arr[i] == arr[j]) {
        for (k = j; k < n - 1; k++) {
          arr[k] = arr[k + 1];
        }
        n--;
      } else {
        j++;
      }
    }
  }

  printf("Array after deduplicating elements (order not changed):\n");
  printf("[");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("]\n");
  return 0;
}

// 3)
// -----------------------------------------------------------------------------------------------
10000

// 4)
// -----------------------------------------------------------------------------------------------
// a.
#include <stdio.h>

int main() {
  int arr[128], n, i, temp;

  printf("Enter array size: ");
  scanf("%d", &n);
  printf("Enter array elements:\n");
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  for (i = 0; i < n / 2; i++) {
    temp = arr[i];
    arr[i] = arr[n - i - 1];
    arr[n - i - 1] = temp;
  }

  printf("Reversed array:\n");
  printf("[");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("]\n");

  return 0;
}

// b.
#include <stdio.h>

int main() {
  int a[10][10], b[10][10], c[10][10], i, j, k, r1, c1, r2, c2;

  printf("Input the number of rows and columns for matrix A: ");
  scanf("%d%d", &r1, &c1);
  printf("Input the number of rows and columns for matrix B: ");
  scanf("%d%d", &r2, &c2);

  if (c1 != r2) {
    printf("Matrix multiplication not possible.\n");
    return 0;
  }

  printf("Provide the values for Matrix A:\n");
  for (i = 0; i < r1; i++)
    for (j = 0; j < c1; j++)
      scanf("%d", &a[i][j]);

  printf("Provide the values for Matrix B:\n");
  for (i = 0; i < r2; i++)
    for (j = 0; j < c2; j++)
      scanf("%d", &b[i][j]);

  for (i = 0; i < r1; i++) {
    for (j = 0; j < c2; j++) {
      c[i][j] = 0;
      for (k = 0; k < c1; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  printf("The product of Matrix A and Matrix B is:\n");
  for (i = 0; i < r1; i++) {
    for (j = 0; j < c2; j++)
      printf("%d ", c[i][j]);
    printf("\n");
  }

  return 0;
}

// c.
#include <stdio.h>

int main() {
  int original[10][10], transpose[10][10];
  int rowCount, colCount, i, j;

  printf("Enter the number of rows and columns: ");
  scanf("%d %d", &rowCount, &colCount);

  printf("Provide the matrix elements:\n");
  for (i = 0; i < rowCount; i++) {
    for (j = 0; j < colCount; j++) {
      scanf("%d", &original[i][j]);
    }
  }
  for (i = 0; i < rowCount; i++) {
    for (j = 0; j < colCount; j++) {
      transpose[j][i] = original[i][j];
    }
  }
  printf("Transposed matrix:\n");
  for (j = 0; j < colCount; j++) {
    for (i = 0; i < rowCount; i++) {
      printf("%d ", transpose[j][i]);
    }
    printf("\n");
  }

  return 0;
}

// 5)
// -----------------------------------------------------------------------------------------------
#include <stdio.h>

int main() {
  int matrix[10][10], rows, cols;
  int i, j, sum;

  printf("Enter number of rows and columns: ");
  scanf("%d %d", &rows, &cols);

  printf("Input the matrix elements:\n");
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }

  printf("Sum of elements in each row:\n");
  for (i = 0; i < rows; i++) {
    sum = 0;
    for (j = 0; j < cols; j++) {
      sum += matrix[i][j];
    }
    printf("Sum of row %d is %d\n", i + 1, sum);
  }

  printf("Sum of elements in each column:\n");
  for (j = 0; j < cols; j++) {
    sum = 0;
    for (i = 0; i < rows; i++) {
      sum += matrix[i][j];
    }
    printf("Sum of column %d is %d\n", j + 1, sum);
  }

  return 0;
}
