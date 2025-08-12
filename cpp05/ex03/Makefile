NAME = binex03

SRCS = main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp \


OBJ = ${SRCS:.cpp=.o}

COMPILER = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

%.o: %.cpp
	${COMPILER} ${FLAGS} -o $@ -c $<

${NAME}: ${OBJ}
	${COMPILER} ${FLAGS} ${OBJ} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
.DEFAULT_GOAL = all
