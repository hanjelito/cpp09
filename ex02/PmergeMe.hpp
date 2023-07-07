#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <ctime>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <vector>
#include <list>
#include <ctime>
#include <sstream>

class PmergeMe {
private:
    std::vector<int> input_;
    std::vector<int> sortVector(double& elapsed_time);
    std::list<int> sortList(double& elapsed_time);

    //merge y mergeSort
    void merge(std::vector<int>& arr, int left, int mid, int right);
    void mergeSort(std::vector<int>& arr, int left, int right);

public:
    PmergeMe(const std::vector<int>& input);
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void run();
};

#endif

// ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`