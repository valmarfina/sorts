#include <iostream>

template<typename T>
void shaker_sort(T *array, const size_t SIZE) {
  bool isSorted;
  size_t right = SIZE - 1;
  size_t left = 1;
  do {
    isSorted = true;
    for (int i = left; i <= right; i++) {
      if (array[i - 1] > array[i]) {
        std::swap(array[i - 1], array[i]);
        isSorted = false;
      }
    }
    right--;
    for (int i = right; i >= left; i--) {
      if (array[i] < array[i - 1]) {
        std::swap(array[i], array[i - 1]);
        isSorted = false;
      }
    }
    left++;
  } while (!isSorted);
}