NAME = ex00

SRCS =	main.cpp \

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

.PHONY: all fclean clean re
.DEFAULT_GOAL = all
