#include "PmergeMe.hpp"


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: missing argument\n";
        return 1;
    }

    std::vector<int> input;
    for (int i = 1; i < argc; ++i) {
        int n = atoi(argv[i]);
        if (n <= 0) {
            std::cerr << "Error: non-positive integer argument\n";
            return 1;
        }
        input.push_back(n);
    }

    PmergeMe pmergeme(input);
    pmergeme.run();

    return 0;
}