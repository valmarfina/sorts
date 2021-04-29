#include <ctime>
#include <random>
#include <chrono>

template<typename T>
bool isRight(T *array, size_t SIZE)
{
  for (size_t i = 0; i < SIZE - 1; i++)
  {
    if (array[i] > array[i + 1])
    {
      return false;
    }
  }
  return true;
}

template<typename T>
void initializeRandom(T *array, const size_t SIZE, const size_t BITNESS = 1000)
{
  srand(time(0));
  for (size_t i = 0; i < SIZE; i++)
  {
    array[i] = rand() % BITNESS + 1;
  }
}

template<typename T>
void printArray(const T *ARRAY, const size_t SIZE)
{
  for (size_t i = 0; i < SIZE; i++)
  {
    std::cout << ARRAY[i] << ' ';
  }
  std::cout << '\n';
}

template<typename T>
void test(T *array, const size_t SIZE, void (*sort)(T *array, const size_t SIZE))
{
  printArray(array, SIZE);
  auto BEGIN = std::chrono::high_resolution_clock::now();
  sort(array, SIZE);
  auto END = std::chrono::high_resolution_clock::now();
  printArray(array, SIZE);
  if (!isRight(array, SIZE))
  {
    std::cerr << "sort is incorrect\n";
    return;
  }
  std::chrono::duration<long double> RESULT = END - BEGIN;
  std::cout << "time of sort: " << RESULT.count() << '\n';
}
