#include <iostream>

template <typename T>
void heapify1(T *array, size_t n, size_t i)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && array[left] > array[largest])
    largest = left;

  if (right < n && array[right] > array[largest])
    largest = right;

  if (largest != i)
  {
    std::swap(array[i], array[largest]);
    heapify1(array, n, largest);
  }
}

template<typename T>
void heapsort(T *array, const size_t SIZE)
{
  for (int i = SIZE / 2 - 1; i >= 0; i--) {
    heapify1(array, SIZE, i);
  }

  for (int i = SIZE - 1; i >= 0; i--)
  {
    std::swap(array[0], array[i]);
    heapify1(array, i, 0);
  }
}


