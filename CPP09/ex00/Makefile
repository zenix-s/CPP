NAME = btc

SRCS =	main.cpp \
		BitcoinExchange.cpp

OBJS = ${SRCS:.cpp=.o}

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

%.o: %.cpp
	${CC} ${FLAGS} -o $@ -c $<

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

# Testing targets
test: $(NAME)
	@echo "Running comprehensive valid input tests..."
	@./$(NAME) input/comprehensive_valid_input.txt

test-errors: $(NAME)
	@echo "Running error case tests..."
	@./$(NAME) input/error_cases.txt

test-subject: $(NAME)
	@echo "Running subject example tests..."
	@./$(NAME) input/input.txt

test-all: $(NAME)
	@echo "Running all automated tests..."
	@chmod +x test_all.sh
	@./test_all.sh

test-quick: $(NAME)
	@echo "Running quick validation tests..."
	@./$(NAME) input/test_input.txt

test-valid: $(NAME)
	@echo "Testing all valid cases..."
	@echo "=== Comprehensive Valid Cases ==="
	@./$(NAME) input/comprehensive_valid_input.txt | wc -l
	@echo "=== Basic Valid Cases ==="
	@./$(NAME) input/valid_input.txt | wc -l
	@echo "=== Edge Cases ==="
	@./$(NAME) input/edge_cases_valid.txt | wc -l

help:
	@echo "Available targets:"
	@echo "  make           - Build the program"
	@echo "  make test      - Run comprehensive valid tests"
	@echo "  make test-errors - Run error case tests"
	@echo "  make test-subject - Run subject example"
	@echo "  make test-all  - Run full automated test suite"
	@echo "  make test-quick - Run quick tests"
	@echo "  make test-valid - Count all valid test cases"
	@echo "  make clean     - Remove object files"
	@echo "  make fclean    - Remove all generated files"
	@echo "  make re        - Rebuild everything"

.PHONY: all fclean clean re test test-errors test-subject test-all test-quick test-valid help
.DEFAULT_GOAL = all
