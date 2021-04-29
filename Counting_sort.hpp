#include <iostream>
#include <vector>

template<typename T>
void counting_sort(T *array, const size_t SIZE)
{
  size_t min, max;
  max = min = array[0];
  for (size_t i = 1; i < SIZE; i++)
  {
    if (array[i] < min)
    {
      min = array[i];
    }
    if (array[i] > max)
    {
      max = array[i];
    }
  }

  std::vector<size_t> counts(max - min + 1, 0);

  for (size_t i = 0; i < SIZE; i++)
  {
    counts[array[i] - min]++;
  }

  size_t index = 0;
  for (size_t i = 0; i < counts.size(); i++)
  {
    for (size_t j = 0; j < counts[i]; j++)
    {
      array[index++] = i + min;
    }
  }
}
