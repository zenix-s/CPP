NAME = cpp08

all:
	@echo "Building all CPP08 exercises..."
	@make -C ex00
	@make -C ex01
	@make -C ex02
	@echo "All exercises built successfully!"

clean:
	@echo "Cleaning all CPP08 exercises..."
	@make clean -C ex00
	@make clean -C ex01
	@make clean -C ex02

fclean:
	@echo "Full cleaning all CPP08 exercises..."
	@make fclean -C ex00
	@make fclean -C ex01
	@make fclean -C ex02

re: fclean all

test: all
	@echo "Running all CPP08 tests..."
	@echo "\n=== Running Exercise 00 ==="
	@cd ex00 && ./easyfind
	@echo "\n=== Running Exercise 01 ==="
	@cd ex01 && ./span
	@echo "\n=== Running Exercise 02 ==="
	@cd ex02 && ./mutantstack

.PHONY: all clean fclean re test
