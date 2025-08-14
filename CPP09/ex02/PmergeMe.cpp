#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <iomanip>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other) : _vector(other._vector), _deque(other._deque)
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}

bool PmergeMe::isValidNumber(const std::string& str) const
{
    if (str.empty())
        return false;
    
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    
    char* endPtr;
    long num = std::strtol(str.c_str(), &endPtr, 10);
    if (num > INT_MAX || num < 0)
        return false;
    
    return true;
}

void PmergeMe::printSequence(const std::vector<int>& seq, const std::string& prefix) const
{
    std::cout << prefix;
    size_t limit = seq.size() > 10 ? 10 : seq.size();
    for (size_t i = 0; i < limit; ++i)
    {
        std::cout << seq[i];
        if (i < limit - 1)
            std::cout << " ";
    }
    if (seq.size() > 10)
        std::cout << " [...]";
    std::cout << std::endl;
}

void PmergeMe::printSequence(const std::deque<int>& seq, const std::string& prefix) const
{
    std::cout << prefix;
    size_t limit = seq.size() > 10 ? 10 : seq.size();
    for (size_t i = 0; i < limit; ++i)
    {
        std::cout << seq[i];
        if (i < limit - 1)
            std::cout << " ";
    }
    if (seq.size() > 10)
        std::cout << " [...]";
    std::cout << std::endl;
}

double PmergeMe::getTimeDifference(clock_t start, clock_t end) const
{
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::insertionSort(std::vector<int>& arr, int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::merge(std::vector<int>& arr, int left, int mid, int right)
{
    std::vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
    
    size_t i = 0, j = 0;
    int k = left;
    
    while (i < leftArr.size() && j < rightArr.size())
    {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }
    
    while (i < leftArr.size())
        arr[k++] = leftArr[i++];
    
    while (j < rightArr.size())
        arr[k++] = rightArr[j++];
}

void PmergeMe::mergeInsertSort(std::vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;
    
    if (right - left < 10)
    {
        insertionSort(arr, left, right);
        return;
    }
    
    int mid = left + (right - left) / 2;
    mergeInsertSort(arr, left, mid);
    mergeInsertSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void PmergeMe::fordJohnsonSort(std::vector<int>& arr)
{
    if (arr.empty())
        return;
    mergeInsertSort(arr, 0, arr.size() - 1);
}

void PmergeMe::insertionSort(std::deque<int>& arr, int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::merge(std::deque<int>& arr, int left, int mid, int right)
{
    std::deque<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    std::deque<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
    
    size_t i = 0, j = 0;
    int k = left;
    
    while (i < leftArr.size() && j < rightArr.size())
    {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }
    
    while (i < leftArr.size())
        arr[k++] = leftArr[i++];
    
    while (j < rightArr.size())
        arr[k++] = rightArr[j++];
}

void PmergeMe::mergeInsertSort(std::deque<int>& arr, int left, int right)
{
    if (left >= right)
        return;
    
    if (right - left < 10)
    {
        insertionSort(arr, left, right);
        return;
    }
    
    int mid = left + (right - left) / 2;
    mergeInsertSort(arr, left, mid);
    mergeInsertSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void PmergeMe::fordJohnsonSort(std::deque<int>& arr)
{
    if (arr.empty())
        return;
    mergeInsertSort(arr, 0, arr.size() - 1);
}

void PmergeMe::processInput(int argc, char* argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg(argv[i]);
        
        if (!isValidNumber(arg))
            throw InvalidInputException();
        
        int num = std::atoi(arg.c_str());
        if (num < 0)
            throw NegativeNumberException();
        
        _vector.push_back(num);
        _deque.push_back(num);
    }
    
    if (_vector.empty())
        throw InvalidInputException();
    
    printSequence(_vector, "Before: ");
    
    clock_t startVector = clock();
    fordJohnsonSort(_vector);
    clock_t endVector = clock();
    
    clock_t startDeque = clock();
    fordJohnsonSort(_deque);
    clock_t endDeque = clock();
    
    printSequence(_vector, "After: ");
    
    double timeVector = getTimeDifference(startVector, endVector);
    double timeDeque = getTimeDifference(startDeque, endDeque);
    
    std::cout << "Time to process a range of " << _vector.size() 
              << " elements with std::vector : " << std::fixed << std::setprecision(5) 
              << timeVector << " us" << std::endl;
    
    std::cout << "Time to process a range of " << _deque.size() 
              << " elements with std::deque  : " << std::fixed << std::setprecision(5) 
              << timeDeque << " us" << std::endl;
}

const char* PmergeMe::InvalidInputException::what() const throw()
{
    return "Error";
}

const char* PmergeMe::NegativeNumberException::what() const throw()
{
    return "Error";
}