#include <ctime>
#include "Shaker_sort.hpp"
#include "radix.h"
#include "Subtasks.hpp"
#include "shellSort_Sedgewick.h"
#include "shellSort.h"
#include "shellSort_Hibbard.h"
#include "Merge-sort.hpp"
#include "Heapsort.hpp"
#include "Counting_sort.hpp"

const size_t SIZE_10000 = 10000;
const size_t SIZE_50000 = 50000;
const size_t SIZE_100000 = 100000;
const size_t SIZE_5 = 5;


const size_t BITNESS_1000 = 1000;//for random


int main()
{
  int array[SIZE_5];
  initializeRandom(array, SIZE_5, 100);
  test(array, SIZE_5, heapsort);
}

//Шейкерная сортировка(shaker_sort)
//Сортировка поразрядная(radixsort)
//Сортировка Шелла с выбором длин промежутков, предложенных Шеллом(shellSort), Хиббардом(shellSort_Hibbard), Седжвиком(shellSort_Sedgewick)
//сортировка слиянием(mergeSort)
//Пирамидальная сортировка(heapsort)
//Сортировка подсчётом(counting_sort)

//english
//Cocktail shaker sort (shaker_sort)
//radix sort(radixsort)
//merge sort(mergeSort)
//counting sort(counting_sort)
//Heapsort(heapsort)
//shell sort (shellSort)
//shell sort with hibbard increment (shellSort_Hibbard)
//shell sort with sedgewick increment (shellSort_Sedgewick)