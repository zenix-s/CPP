#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${YELLOW}=== CPP09 Module Test Suite ===${NC}\n"

# Test Exercise 00: Bitcoin Exchange
echo -e "${GREEN}Testing Exercise 00: Bitcoin Exchange${NC}"
cd ex00
make re > /dev/null 2>&1

echo "Test 1: Valid input file"
echo "date | value" > test_input.txt
echo "2011-01-03 | 3" >> test_input.txt
echo "2011-01-03 | 2" >> test_input.txt
echo "2011-01-09 | 1" >> test_input.txt
echo "2012-01-11 | 1" >> test_input.txt
./btc test_input.txt

echo -e "\nTest 2: Invalid inputs"
echo "date | value" > test_input.txt
echo "2011-01-03 | -1" >> test_input.txt
echo "2011-01-03 | 1001" >> test_input.txt
echo "2001-42-42" >> test_input.txt
echo "not_a_date | 5" >> test_input.txt
./btc test_input.txt

echo -e "\nTest 3: No arguments"
./btc

echo -e "\nTest 4: Non-existent file"
./btc non_existent.txt

rm -f test_input.txt
make fclean > /dev/null 2>&1
cd ..

echo -e "\n${GREEN}Testing Exercise 01: RPN${NC}"
cd ex01
make re > /dev/null 2>&1

echo "Test 1: Basic operations"
echo -n "8 9 * 9 - 9 - 9 - 4 - 1 + = "
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

echo -n "7 7 * 7 - = "
./RPN "7 7 * 7 -"

echo -n "1 2 * 2 / 2 * 2 4 - + = "
./RPN "1 2 * 2 / 2 * 2 4 - +"

echo -e "\nTest 2: Division"
echo -n "9 3 / = "
./RPN "9 3 /"

echo -e "\nTest 3: Invalid expressions"
echo -n "Invalid: (1 + 1) = "
./RPN "(1 + 1)"

echo -n "Invalid: 1 2 = "
./RPN "1 2"

echo -n "Invalid: 1 + = "
./RPN "1 +"

echo -e "\nTest 4: No arguments"
./RPN

echo -e "\nTest 5: Complex expression"
echo -n "5 1 2 + 4 * + 3 - = "
./RPN "5 1 2 + 4 * + 3 -"

make fclean > /dev/null 2>&1
cd ..

echo -e "\n${GREEN}Testing Exercise 02: PmergeMe${NC}"
cd ex02
make re > /dev/null 2>&1

echo "Test 1: Small sequence"
./PmergeMe 3 5 9 7 4

echo -e "\nTest 2: Already sorted"
./PmergeMe 1 2 3 4 5

echo -e "\nTest 3: Reverse sorted"
./PmergeMe 5 4 3 2 1

echo -e "\nTest 4: Duplicates"
./PmergeMe 3 1 4 1 5 9 2 6 5 3

echo -e "\nTest 5: Single element"
./PmergeMe 42

echo -e "\nTest 6: Invalid input (negative)"
./PmergeMe -1 2 3

echo -e "\nTest 7: Invalid input (non-numeric)"
./PmergeMe 1 2 abc 4

echo -e "\nTest 8: No arguments"
./PmergeMe

echo -e "\nTest 9: Large sequence (100 elements)"
echo "Testing with 100 random elements..."
./PmergeMe $(seq 1 100 | shuf | head -100 | tr '\n' ' ') | head -3

echo -e "\nTest 10: Very large sequence (3000 elements)"
echo "Testing with 3000 random elements..."
./PmergeMe $(seq 1 10000 | shuf | head -3000 | tr '\n' ' ') | grep "Time to process"

make fclean > /dev/null 2>&1
cd ..

echo -e "\n${YELLOW}=== All tests completed ===${NC}"
