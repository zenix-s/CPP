#pragma once

#include <vector>
#include <deque>
#include <string>
#include <exception>
#include <ctime>

class PmergeMe
{
  private:
    std::vector<int> _vector;
    std::deque<int>  _deque;
    
    // Ford-Johnson algorithm for vector
    void fordJohnsonSort(std::vector<int>& arr);
    void insertionSort(std::vector<int>& arr, int left, int right);
    void merge(std::vector<int>& arr, int left, int mid, int right);
    void mergeInsertSort(std::vector<int>& arr, int left, int right);
    
    // Ford-Johnson algorithm for deque
    void fordJohnsonSort(std::deque<int>& arr);
    void insertionSort(std::deque<int>& arr, int left, int right);
    void merge(std::deque<int>& arr, int left, int mid, int right);
    void mergeInsertSort(std::deque<int>& arr, int left, int right);
    
    // Helper functions
    bool isValidNumber(const std::string& str) const;
    void printSequence(const std::vector<int>& seq, const std::string& prefix) const;
    void printSequence(const std::deque<int>& seq, const std::string& prefix) const;
    double getTimeDifference(clock_t start, clock_t end) const;

  public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& other);
    
    void processInput(int argc, char* argv[]);
    
    class InvalidInputException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };
    
    class NegativeNumberException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };
};