#include "PmergeMe.hpp"
#include <climits>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    (void)other;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    (void)other;
    return *this;
}

int PmergeMe::binarySearchVector(const std::vector<int>& arr, int value, int end)
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

std::vector<int> PmergeMe::generateJacobsthalVector(int limit) const
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

std::vector<int> PmergeMe::mergeInsertVector(std::vector<int>& smallVector, std::vector<int>& bigVector)
{
    std::vector<int>                   jacobsthalSequence = generateJacobsthalVector(smallVector.size());
    std::vector<std::pair<int, bool> > smallVectorPairs;
    std::vector<int>                   result;

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

        int pos = binarySearchVector(result, valueToInsert, result.size());
        result.insert(result.begin() + pos, valueToInsert);
        smallVectorPairs[jacobsthalValue].second = true;

        int jacobsthalValueStart = i == 0 ? 0 : jacobsthalSequence[i - 1];
        int jacobsthalValueEnd = jacobsthalValue - 1;
        while (jacobsthalValueEnd >= jacobsthalValueStart)
        {
            int valueToInsert = smallVectorPairs[jacobsthalValueEnd].first;
            if (!smallVectorPairs[jacobsthalValueEnd].second)
            {
                int pos = binarySearchVector(result, valueToInsert, result.size());
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
            int pos = binarySearchVector(result, valueToInsert, result.size());
            result.insert(result.begin() + pos, valueToInsert);
        }
    }

    return result;
}

std::vector<int> PmergeMe::recursiveHelperVector(std::vector<int> list)
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

    std::vector<int> bigVector;
    std::vector<int> smallVector;

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        bigVector.push_back(pairs[i].second);
        smallVector.push_back(pairs[i].first);
    }

    if (isOdd)
        smallVector.push_back(extraElement);

    std::vector<int> bigSortedVector = recursiveHelperVector(bigVector);
    std::vector<int> smallVectorSorted = recursiveHelperVector(smallVector);

    return mergeInsertVector(smallVectorSorted, bigSortedVector);
}

std::vector<int> PmergeMe::sortVector(std::vector<int> originalVector)
{
    if (originalVector.empty())
        return originalVector;

    std::vector<int> sortedVector = recursiveHelperVector(originalVector);
    return sortedVector;
}

int PmergeMe::binarySearchDeque(const std::deque<int>& arr, int value, int end)
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

std::deque<int> PmergeMe::generateJacobsthalDeque(int limit) const
{
    std::deque<int> jacobsthal;
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

std::deque<int> PmergeMe::mergeInsertDeque(std::deque<int>& smallDeque, std::deque<int>& bigDeque)
{
    std::deque<int>                   jacobsthalSequence = generateJacobsthalDeque(smallDeque.size());
    std::deque<std::pair<int, bool> > smallDequePairs;
    std::deque<int>                   result;

    for (size_t i = 0; i < smallDeque.size(); ++i)
        smallDequePairs.push_back(std::make_pair(smallDeque[i], false));
    for (size_t i = 0; i < bigDeque.size(); ++i)
        result.push_back(bigDeque[i]);

    for (size_t i = 0; i < jacobsthalSequence.size(); ++i)
    {
        int jacobsthalValue = jacobsthalSequence[i] - 1;
        int valueToInsert = smallDequePairs[jacobsthalValue].first;
        if (smallDequePairs[jacobsthalValue].second)
            continue;

        int pos = binarySearchDeque(result, valueToInsert, result.size());
        result.insert(result.begin() + pos, valueToInsert);
        smallDequePairs[jacobsthalValue].second = true;

        int jacobsthalValueStart = i == 0 ? 0 : jacobsthalSequence[i - 1];
        int jacobsthalValueEnd = jacobsthalValue - 1;
        while (jacobsthalValueEnd >= jacobsthalValueStart)
        {
            int valueToInsert = smallDequePairs[jacobsthalValueEnd].first;
            if (!smallDequePairs[jacobsthalValueEnd].second)
            {
                int pos = binarySearchDeque(result, valueToInsert, result.size());
                result.insert(result.begin() + pos, valueToInsert);
                smallDequePairs[jacobsthalValueEnd].second = true;
            }
            --jacobsthalValueEnd;
        }
    }

    for (int i = smallDequePairs.size() - 1; i >= 0; --i)
    {
        if (!smallDequePairs[i].second)
        {
            int valueToInsert = smallDequePairs[i].first;
            int pos = binarySearchDeque(result, valueToInsert, result.size());
            result.insert(result.begin() + pos, valueToInsert);
        }
    }

    return result;
}

std::deque<int> PmergeMe::recursiveHelperDeque(std::deque<int> list)
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

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < list.size(); i += 2)
    {
        if (list[i] > list[i + 1])
            std::swap(list[i], list[i + 1]);
        pairs.push_back(std::make_pair(list[i], list[i + 1]));
    }

    std::deque<int> bigDeque;
    std::deque<int> smallDeque;

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        bigDeque.push_back(pairs[i].second);
        smallDeque.push_back(pairs[i].first);
    }

    if (isOdd)
        smallDeque.push_back(extraElement);

    std::deque<int> bigSortedDeque = recursiveHelperDeque(bigDeque);
    std::deque<int> smallDequeSorted = recursiveHelperDeque(smallDeque);

    return mergeInsertDeque(smallDequeSorted, bigSortedDeque);
}

std::deque<int> PmergeMe::sortDeque(std::deque<int> originalDeque)
{
    if (originalDeque.empty())
        return originalDeque;

    std::deque<int> sortedDeque = recursiveHelperDeque(originalDeque);
    return sortedDeque;
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
    long  num = strtol(str.c_str(), &endPtr, 10);
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

void PmergeMe::processInput(int argc, char** argv)
{
    std::vector<int> _vector;
    std::deque<int>  _deque;

    for (int i = 1; i < argc; ++i)
    {
        std::string arg(argv[i]);

        if (!isValidNumber(arg))
            throw std::logic_error("Error");

        int num = atoi(arg.c_str());
        if (num < 0)
            throw std::logic_error("Error");

        _vector.push_back(num);
        _deque.push_back(num);
    }

    if (_vector.empty())
        throw std::logic_error("Error");

    printSequence(_vector, "Before: ");

    clock_t          startVector = clock();
    std::vector<int> _sortedVector = sortVector(_vector);
    clock_t          endVector = clock();

    clock_t         startDeque = clock();
    std::deque<int> _sortedDeque = sortDeque(_deque);
    clock_t         endDeque = clock();

    printSequence(_sortedVector, "After: ");

    double timeVector = getTimeDifference(startVector, endVector);
    double timeDeque = getTimeDifference(startDeque, endDeque);

    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << std::fixed
              << std::setprecision(5) << timeVector << " us" << std::endl;

    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque  : " << std::fixed
              << std::setprecision(5) << timeDeque << " us" << std::endl;
}
