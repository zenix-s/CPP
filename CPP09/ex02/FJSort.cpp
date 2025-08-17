#include "FJSort.hpp"
#include <climits>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

FJSort::FJSort()
{
}

FJSort::FJSort(const FJSort& other)
{
    (void)other;
}

FJSort::~FJSort()
{
}

FJSort& FJSort::operator=(const FJSort& other)
{
    (void)other;
    return *this;
}

int FJSort::binarySearch(const std::vector<int>& arr, int value, int end)
{
    int left = 0, right = end;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

std::vector<int> FJSort::generateJacobsthal(int limit) const
{
    std::vector<int> jacobsthal;
    if (limit <= 0)
        return jacobsthal;

    jacobsthal.push_back(1);
    if (limit == 1)
        return jacobsthal;

    int prev2 = 1, prev1 = 1;
    while (true)
    {
        int next = prev1 + 2 * prev2;
        if (next > limit)
            break;
        jacobsthal.push_back(next);
        prev2 = prev1;
        prev1 = next;
    }

    return jacobsthal;
}

std::vector<int> FJSort::mergeInsert(std::vector<int>& smallVector, std::vector<int>& bigVector)
{
    std::vector<int> jacobsthalSequence = generateJacobsthal(smallVector.size());
    std::vector<std::pair<int, bool> > smallVectorPairs;
    std::vector<int> result;

    for (size_t i = 0; i < smallVector.size(); ++i)
        smallVectorPairs.push_back(std::make_pair(smallVector[i], false));
    for (size_t i = 0; i < bigVector.size(); ++i)
        result.push_back(bigVector[i]);

    for (size_t i = 0; i < jacobsthalSequence.size(); ++i)
    {
        int jacobsthalValue = jacobsthalSequence[i] - 1;
        int valueToInsert = smallVectorPairs[jacobsthalValue].first;
        if (smallVectorPairs[jacobsthalValue].second)
            continue;

        int pos = binarySearch(result, valueToInsert, result.size());
        result.insert(result.begin() + pos, valueToInsert);
        smallVectorPairs[jacobsthalValue].second = true;

        int jacobsthalValueStart = i == 0 ? 0 : jacobsthalSequence[i - 1];
        int jacobsthalValueEnd = jacobsthalValue - 1;
        while (jacobsthalValueEnd >= jacobsthalValueStart)
        {
            int valueToInsert = smallVectorPairs[jacobsthalValueEnd].first;
            if (!smallVectorPairs[jacobsthalValueEnd].second)
            {
                int pos = binarySearch(result, valueToInsert, result.size());
                result.insert(result.begin() + pos, valueToInsert);
                smallVectorPairs[jacobsthalValueEnd].second = true;
            }
            --jacobsthalValueEnd;
        }
    }

    for (int i = smallVectorPairs.size() - 1; i >= 0; --i)
    {
        if (!smallVectorPairs[i].second)
        {
            int valueToInsert = smallVectorPairs[i].first;
            int pos = binarySearch(result, valueToInsert, result.size());
            result.insert(result.begin() + pos, valueToInsert);
        }
    }

    return result;
}

std::vector<int> FJSort::recursiveHelper(std::vector<int> list)
{
    if (list.size() <= 1)
        return list;
    
    if (list.size() == 2)
    {
        if (list[0] > list[1])
            std::swap(list[0], list[1]);
        return list;
    }

    bool isOdd = false;
    int  extraElement = 0;

    if (list.size() % 2 == 1)
    {
        isOdd = true;
        extraElement = list.back();
        list.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < list.size(); i += 2)
    {
        if (list[i] > list[i + 1])
            std::swap(list[i], list[i + 1]);
        pairs.push_back(std::make_pair(list[i], list[i + 1]));
    }

    std::vector<int>                  bigVector;
    std::vector<int> smallVector;

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        bigVector.push_back(pairs[i].second);
        smallVector.push_back(pairs[i].first);
    }

    if (isOdd)
        smallVector.push_back(extraElement);

    std::vector<int> bigSortedVector = recursiveHelper(bigVector);
    std::vector<int> smallVectorSorted = recursiveHelper(smallVector);

    return mergeInsert(smallVectorSorted, bigSortedVector);
}

std::vector<int> FJSort::sort(std::vector<int> originalVector)
{
    if (originalVector.empty())
        return originalVector;

    std::vector<int> sortedVector = recursiveHelper(originalVector);
    return sortedVector;
}

bool FJSort::isValidNumber(const std::string& str) const
{
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!std::isdigit(str[i]))
            return false;
    }

    char* endPtr;
    long  num = strtol(str.c_str(), &endPtr, 10);
    if (num > INT_MAX || num < 0)
        return false;

    return true;
}

void FJSort::printSequence(const std::vector<int>& seq, const std::string& prefix) const
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

void FJSort::printSequence(const std::deque<int>& seq, const std::string& prefix) const
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

double FJSort::getTimeDifference(clock_t start, clock_t end) const
{
    return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

void FJSort::processInput(int argc, char** argv)
{
    std::vector<int> _vector, _sortedVector;
    std::deque<int>  _deque;

    for (int i = 1; i < argc; ++i)
    {
        std::string arg(argv[i]);

        if (!isValidNumber(arg))
            throw std::logic_error("invalid");

        int num = atoi(arg.c_str());
        if (num < 0)
            throw std::logic_error("invalid");

        _vector.push_back(num);
        _deque.push_back(num);
    }

    if (_vector.empty())
        throw std::logic_error("invalid");

    printSequence(_vector, "Before: ");

    clock_t startVector = clock();
    _sortedVector = sort(_vector);
    clock_t endVector = clock();

    bool isSorted = true;
    for (size_t i = 1; i < _sortedVector.size(); ++i)
    {
        if (_sortedVector[i] < _sortedVector[i - 1])
        {
            isSorted = false;
            break;
        }
    }

    // clock_t startDeque = clock();
    // sort(_deque);
    // clock_t endDeque = clock();

    printSequence(_sortedVector, "After: ");

    double timeVector = getTimeDifference(startVector, endVector);
    // double timeDeque = getTimeDifference(startDeque, endDeque);

    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << std::fixed
              << std::setprecision(5) << timeVector << " seconds" << std::endl;
    std::cout << "Is sorted: " << (isSorted ? "true" : "false") << std::endl;

    // std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque  : " << std::fixed
    //           << std::setprecision(5) << timeDeque << " us" << std::endl;
}
