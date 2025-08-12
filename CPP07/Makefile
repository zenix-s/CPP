NAME = cpp07

all:
	@echo "Building all CPP07 exercises..."
	@make -C ex00
	@make -C ex01
	@make -C ex02
	@echo "All exercises built successfully!"

clean:
	@echo "Cleaning all CPP07 exercises..."
	@make clean -C ex00
	@make clean -C ex01
	@make clean -C ex02

fclean:
	@echo "Full cleaning all CPP07 exercises..."
	@make fclean -C ex00
	@make fclean -C ex01
	@make fclean -C ex02

re: fclean all

test: all
	@echo "Running all CPP07 tests..."
	@echo "\n=== Running Exercise 00 ==="
	@cd ex00 && ./ex00
	@echo "\n=== Running Exercise 01 ==="
	@cd ex01 && ./ex01
	@echo "\n=== Running Exercise 02 ==="
	@cd ex02 && ./array

.PHONY: all clean fclean re test
