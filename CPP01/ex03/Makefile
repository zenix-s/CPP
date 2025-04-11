#------------------------------------------------------------------------------#
#                                COLORS                                        #
#------------------------------------------------------------------------------#
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#
NAME	= ex03

SRCS = ./main.cpp \
       ./Weapon.cpp \
       ./HumanA.cpp \
       ./HumanB.cpp \

OBJS	= ${SRCS:.cpp=.o}

HEADERS	= -I ./include

CC = c++
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -std=c++98
RM = rm -rf

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#
%.o: %.cpp
	@echo -e "$(YELLOW) ◎ Compiling $(GREEN)$< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) -o $(NAME)
	@echo -e "\n $(GREEN)◎ $(NAME) has been created successfully!$(DEF_COLOR)"

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@echo -e " $(RED)◎ Objects files have been removed!$(DEF_COLOR)"

fclean: clean
	@$(RM)  $(NAME)
	@echo -e " $(RED)◎ $(NAME) has been removed!$(DEF_COLOR)\n"

re: fclean all

#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#
.PHONY: all, clean, fclean, re
.DEFAULT_GOAL = all
