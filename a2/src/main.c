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
        int temp = arr[j];
        arr[j] = arr[j + 1];
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
swapping the adjacent elements if they are in wrong order. Code the Bubble sort
with the following elements: 64 34 25 12 22 11 90
*/
#include <stdio.h>

int main() {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("[");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("]\n");

  // Bubble Sort
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
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
  int len = (sizeof(arr) / sizeof(*arr));
  int n = len + 1; // Since one number is missing
  int total = (n * (n + 1)) / 2;
  int sum = 0;
  for (int i = 0; i < len; ++i) {
    sum += arr[i];
  }

  int missingNumber = total - sum;
  printf("The missing number is: %d\n", missingNumber);
  return 0;
}
