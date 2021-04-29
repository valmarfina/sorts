#ifndef SORTS_SHELLSORT_SEDGEWICK_H
#define SORTS_SHELLSORT_SEDGEWICK_H

int increment(long inc[], long size) {
  int p1, p2, p3, s;
  p1 = p2 = p3 = 1;
  s = -1;
  do {
    if (++s % 2) {
      inc[s] = 8 * p1 - 6 * p2 + 1;
    } else {
      inc[s] = 9 * p1 - 9 * p3 + 1;
      p2 *= 2;
      p3 *= 2;
    }
    p1 *= 2;
  } while(3 * inc[s] < size);
  return s > 0 ? --s : 0;
}

template<typename T>
void shellSort_Sedgewick(T *array, const size_t SIZE) {
  long inc, i, j, seq[40];
  int s;
  s = increment(seq, SIZE);
  while (s >= 0) {
    inc = seq[s--];
    for (i = inc; i < SIZE; i++) {
      T temp = array[i];
      for (j = i - inc; (j >= 0) && (array[j] > temp); j -= inc)
        array[j + inc] = array[j];
      array[j + inc] = temp;
    }
  }
}

#endif //SORTS_SHELLSORT_SEDGEWICK_H