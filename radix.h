#ifndef SORTS_RADIX_H
#define SORTS_RADIX_H

#include <iostream>

int getMax(int arr[], int n)
{
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

void countSort(int arr[], int n, int exp)
{
  int output[n];
  int i, count[10] = { 0 };
   for (i = 0; i < n; i++) {
     count[(arr[i] / exp) % 10]++;
   }
  for (i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }
  for (i = n - 1; i >= 0; i--) {
    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }
  for (i = 0; i < n; i++) {
    arr[i] = output[i];
  }
}

template<typename T>
void radixsort(T *array, const size_t SIZE)
{
  int m = getMax(array, SIZE);
  for (int exp = 1; m / exp > 0; exp *= 10)
    countSort(array, SIZE, exp);
}
#endif //SORTS_RADIX_H
