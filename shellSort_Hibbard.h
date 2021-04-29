#ifndef SORTS_SHELLSORT_HIBBARD_H
#define SORTS_SHELLSORT_HIBBARD_H

template<typename T>
void shellSort_Hibbard(T *array, const size_t SIZE) {
  int h_size = floor(log(SIZE + 1) / log(2));
  int *inc = new int[h_size];
  for (int i = 0; i < h_size; i++) {
    inc[i] = pow(2, i + 1) - 1;
  }
  int i, j, tmp;
  for (int r = (h_size - 1); r >= 0; r--) {
    int gap = inc[r];
    for (i = gap; i < SIZE; i++) {
      tmp = array[i];
      for (j = i; j >= gap && tmp < array[j - gap]; j -= gap) {
        array[j] = array[j - gap];
      }
      array[j] = tmp;
    }
  }
  delete [] inc;
}

#endif //SORTS_SHELLSORT_HIBBARD_H
