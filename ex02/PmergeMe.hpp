#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <ctime>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <vector>
#include <list>
#include <sstream>

class PmergeMe {
private:
    std::vector<int> input_;
    std::vector<int> sortVector(double& elapsed_time);
    std::list<int> sortList(double& elapsed_time);

public:
    PmergeMe(const std::vector<int>& input);
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void run();

};
#endif
