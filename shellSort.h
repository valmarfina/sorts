#ifndef SORTS_SHELLSORT_H
#define SORTS_SHELLSORT_H

template<typename T>
void shellSort(T *array, const size_t SIZE) {
  {
    int i, j, step;
    int tmp;
    for (step = SIZE / 2; step > 0; step /= 2)
      for (i = step; i < SIZE; i++) {
        tmp = array[i];
        for (j = i; j >= step; j -= step) {
          if (tmp < array[j - step])
            array[j] = array[j - step];
          else
            break;
        }
        array[j] = tmp;
      }
  }
}


#endif //SORTS_SHELLSORT_H
