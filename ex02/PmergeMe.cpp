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

void PmergeMe::merge(std::vector<int>& arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    std::vector<int> temp(right + 1);

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void PmergeMe::mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

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
    clock_t start_time = clock();
    
    std::vector<int> sorted_vector(input_);
    mergeSort(sorted_vector, 0, sorted_vector.size() - 1);
 
    clock_t vector_sort_time = clock() - start_time;
    elapsed_time = (double)vector_sort_time;

    return sorted_vector;
}

std::list<int> PmergeMe::sortList(double& elapsed_time) {
    clock_t start_time = clock();
    
    std::vector<int> temp(input_.begin(), input_.end());
    mergeSort(temp, 0, temp.size() - 1);
    std::list<int> sorted_list(temp.begin(), temp.end());

    clock_t list_sort_time = clock() - start_time;
    elapsed_time = (double)list_sort_time;

    return sorted_list;
}