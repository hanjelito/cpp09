#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::vector<int>& input) : input_(input) {}

PmergeMe::PmergeMe(const PmergeMe& other) : input_(other.input_) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (&other != this) {
        this->input_ = other.input_;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::run() {
    double vector_time, list_time;

    std::cout << "Before:";
    for (int i = 0; i < input_.size(); ++i) {
        std::cout << " " << input_[i];
    }
    std::cout << std::endl;

    std::vector<int> sorted_vector = sortVector(vector_time);
    std::list<int> sorted_list = sortList(list_time);


    std::cout << "After:";
    for (int i = 0; i < sorted_vector.size(); ++i) {
        std::cout << " " << sorted_vector[i];
    }
    std::cout << std::endl;


    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << input_.size() << " elements with std::vector: " 
            << vector_time << " us" << std::endl;
    std::cout << "Time to process a range of " << input_.size() << " elements with std::list: " 
            << list_time << " us" << std::endl;
}

std::vector<int> PmergeMe::sortVector(double& elapsed_time) {
    std::vector<int> sorted_vector(input_.size());
    clock_t start_time = clock();

    for (int i = 0; i < input_.size(); ++i) {
        std::vector<int>::iterator it = std::lower_bound(sorted_vector.begin(), sorted_vector.begin() + i, input_[i]);
        std::copy_backward(it, sorted_vector.begin() + i, sorted_vector.begin() + i + 1);
        *it = input_[i];
    }
 
    clock_t vector_sort_time = clock() - start_time;
    elapsed_time = (double)vector_sort_time / CLOCKS_PER_SEC * 1000;

    return sorted_vector;
}

std::list<int> PmergeMe::sortList(double& elapsed_time) {
    std::list<int> sorted_list;
    clock_t start_time = clock();

    for (int i = 0; i < input_.size(); ++i) {
        std::list<int>::iterator it = std::lower_bound(sorted_list.begin(), sorted_list.end(), input_[i]);
        sorted_list.insert(it, input_[i]);
    }

    clock_t list_sort_time = clock() - start_time;
    elapsed_time = (double)list_sort_time / CLOCKS_PER_SEC * 1000;

    return sorted_list;
}
