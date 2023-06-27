#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Error: missing argument\n";
    return 1;
  }

  // Parse input arguments and store in a vector of integers
  std::vector<int> input;
  for (int i = 1; i < argc; ++i) {
    int n = atoi(argv[i]);
    if (n <= 0) {
      std::cerr << "Error: non-positive integer argument\n";
      return 1;
    }
    input.push_back(n);
  }

  // Print unsorted sequence
  std::cout << "Before:";
  copy(input.begin(), input.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  // Sort sequence using merge-insertion sort
  clock_t start_time = clock();

  // Sort using vector container
  std::vector<int> sorted_vector(input.size());
  for (int i = 0; i < input.size(); ++i) {
    std::vector<int>::iterator it = lower_bound(sorted_vector.begin(), sorted_vector.begin() + i, input[i]);
    copy_backward(it, sorted_vector.begin() + i, sorted_vector.begin() + i + 1);
    *it = input[i];
  }
  clock_t vector_sort_time = clock() - start_time;

  // Sort using list container
  start_time = clock();
  std::list<int> sorted_list;
  for (int i = 0; i < input.size(); ++i) {
    std::list<int>::iterator it = lower_bound(sorted_list.begin(), sorted_list.end(), input[i]);
    sorted_list.insert(it, input[i]);
  }
  clock_t list_sort_time = clock() - start_time;

  // Print sorted sequence
  std::cout << "After:";
  std::copy(sorted_vector.begin(), sorted_vector.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  // Print algorithm times
  std::cout << "Time to process a range of " << input.size() << " elements with vector container: " 
       << (double)vector_sort_time / CLOCKS_PER_SEC << " seconds" << std::endl;
  std::cout << "Time to process a range of " << input.size() << " elements with list container: " 
       << (double)list_sort_time / CLOCKS_PER_SEC << " seconds" << std::endl;

  return 0;
}

// clang++ main.cpp && ./a.out `jot -r 3000 1 100000 | tr '\n' ' '`