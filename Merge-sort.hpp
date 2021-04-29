#ifndef SORTS_MERGE_SORT_HPP
#define SORTS_MERGE_SORT_HPP

template<typename T>
void mergeSort(T *array, const size_t size)
{
  T *tempArray = new T[size];
  int right, rightEnd;
  int i, j, tempIndex;
  for (int k = 1; k < size; k *= 2)
  {
    for (int left = 0; left + k < size; left += k * 2)
    {
      right = left + k;
      rightEnd = right + k;
      if (rightEnd > size)
      {
        rightEnd = size;
      }
      tempIndex = left;
      i = left;
      j = right;
      while (i < right && j < rightEnd)
      {
        if (array[i] <= array[j])
        {
          tempArray[tempIndex] = array[i++];
        }
        else
        {
          tempArray[tempIndex] = array[j++];
        }
        tempIndex++;
      }
      while (i < right)
      {
        tempArray[tempIndex++] = array[i++];
      }
      while (j < rightEnd)
      {
        tempArray[tempIndex++] = array[j++];
      }
      for (tempIndex = left; tempIndex < rightEnd; tempIndex++)
      {
        array[tempIndex] = tempArray[tempIndex];
      }
    }
  }
  delete[] tempArray;
}

#endif
