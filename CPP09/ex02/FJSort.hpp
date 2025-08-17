#pragma once

#include <ctime>
#include <deque>
#include <string>
#include <utility>
#include <vector>
class FJSort
{
  private:
    std::vector<int> generateJacobsthal(int limit) const;
    int              binarySearch(const std::vector<int>& arr, int value, int end);

    // vector
    std::vector<int> mergeInsert(std::vector<int>& smallVector, std::vector<int>& bigSortedVector);
    std::vector<int> recursiveHelper(std::vector<int> list);
    std::vector<int> sort(std::vector<int>);

    // deque
    std::deque<int> sort(std::deque<int>);

    // helper
    bool   isValidNumber(const std::string& str) const;
    void   printSequence(const std::vector<int>& seq, const std::string& prefix) const;
    void   printSequence(const std::deque<int>& seq, const std::string& prefix) const;
    double getTimeDifference(clock_t start, clock_t end) const;

  public:
    FJSort();
    FJSort(const FJSort& other);
    ~FJSort();
    FJSort& operator=(const FJSort& other);

    void processInput(int argc, char* argv[]);
};
