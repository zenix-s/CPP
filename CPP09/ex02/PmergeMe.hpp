#pragma once

#include <ctime>
#include <deque>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

class PmergeMe
{
  private:
    // Vector implementation
    std::vector<int> generateJacobsthalVector(int limit) const;
    int              binarySearchVector(const std::vector<int>& arr, int value, int end);
    std::vector<int> mergeInsertVector(std::vector<int>& smallVector, std::vector<int>& bigVector);
    std::vector<int> recursiveHelperVector(std::vector<int> list);
    std::vector<int> sortVector(std::vector<int> originalVector);

    // Deque implementation
    std::deque<int> generateJacobsthalDeque(int limit) const;
    int             binarySearchDeque(const std::deque<int>& arr, int value, int end);
    std::deque<int> mergeInsertDeque(std::deque<int>& smallDeque, std::deque<int>& bigDeque);
    std::deque<int> recursiveHelperDeque(std::deque<int> list);
    std::deque<int> sortDeque(std::deque<int> originalDeque);

    // Helper functions
    bool   isValidNumber(const std::string& str) const;
    void   printSequence(const std::vector<int>& seq, const std::string& prefix) const;
    void   printSequence(const std::deque<int>& seq, const std::string& prefix) const;
    double getTimeDifference(clock_t start, clock_t end) const;

  public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& other);

    void processInput(int argc, char* argv[]);


};
