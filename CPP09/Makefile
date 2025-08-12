# Global Makefile for CPP09 Module

SUBDIRS = ex00 ex01 ex02

all:
	@for dir in $(SUBDIRS); do \
		echo "Building $$dir..."; \
		$(MAKE) -C $$dir; \
	done

clean:
	@for dir in $(SUBDIRS); do \
		echo "Cleaning $$dir..."; \
		$(MAKE) -C $$dir clean; \
	done

fclean:
	@for dir in $(SUBDIRS); do \
		echo "Full cleaning $$dir..."; \
		$(MAKE) -C $$dir fclean; \
	done

re: fclean all

test: all
	@echo "=== Testing Exercise 00: Bitcoin Exchange ==="
	@cd ex00 && echo "date | value" > test.txt && \
		echo "2011-01-03 | 3" >> test.txt && \
		echo "2011-01-09 | 1" >> test.txt && \
		echo "2012-01-11 | 1" >> test.txt && \
		./btc test.txt && rm -f test.txt
	@echo ""
	@echo "=== Testing Exercise 01: RPN ==="
	@cd ex01 && ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" && \
		./RPN "7 7 * 7 -" && \
		./RPN "1 2 * 2 / 2 * 2 4 - +"
	@echo ""
	@echo "=== Testing Exercise 02: PmergeMe ==="
	@cd ex02 && ./PmergeMe 3 5 9 7 4

.PHONY: all clean fclean re test
