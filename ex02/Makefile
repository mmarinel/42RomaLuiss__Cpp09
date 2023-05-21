# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 17:34:54 by earendil          #+#    #+#              #
#    Updated: 2023/05/21 15:38:03 by mmarinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/bash

RESET		:= $(shell /bin/echo -e "\033[0m")
BLACK		:= $(shell /bin/echo -e "\033[30m")
RED			:= $(shell /bin/echo -e "\033[31m")
GREEN		:= $(shell /bin/echo -e "\033[32m")
YELLOW		:= $(shell /bin/echo -e "\033[33m")
BLUE		:= $(shell /bin/echo -e "\033[34m")
MAGENTA		:= $(shell /bin/echo -e "\033[35m")
CYAN		:= $(shell /bin/echo -e "\033[36m")
BOLDCYAN	:= $(shell /bin/echo -e "\033[1;36m")
WHITE		:= $(shell /bin/echo -e "\033[37m")
BOLDBLACK	:= $(shell /bin/echo -e "\033[1m\033[30m")
BOLDRED		:= $(shell /bin/echo -e "\033[1m\033[31m")
BOLDGREEN	:= $(shell /bin/echo -e "\033[1m\033[32m")
BOLDYELLOW	:= $(shell /bin/echo -e "\033[1m\033[33m")
BOLDBLUE	:= $(shell /bin/echo -e "\033[1m\033[34m")
BOLDMAGENTA	:= $(shell /bin/echo -e "\033[1m\033[35m")
BOLDCYAN	:= $(shell /bin/echo -e "\033[1m\033[36m")
BOLDWHITE	:= $(shell /bin/echo -e "\033[1m\033[37m")
NL			:= $(shell /bin/echo -e "\n")

CC:= g++
CFLAGS:= -std=c++98 -Wall -Werror -Wextra

NAME := PmergeMe
OBJS_DIR:= bin
OBJS:= $(addprefix $(OBJS_DIR)/, $(shell find . -name "*.cpp" -print | sed 's/\.cpp/\.o/g' | sed 's/\.\///'))
INCLUDES:= $(shell find . -name "*.[t,h]pp" -print)

RMF:= @/bin/rm -rf
MKD:= @mkdir -p
MAKE_REC:= @make --no-print-directory

exercise: .BUILD

run: .RUN
	@printf "$(BOLDCYAN)\nTests running\n\n$(RESET) "; sleep 1; \
	\
	printf "$(CYAN)\nEmpty test\n\n$(RESET) "; sleep 1;
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME);
	@read -p "Press any key to continue..."; clear; \
	\
	printf "$(CYAN)\nSubject tests\n\n$(RESET) "; sleep 1;
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 3 5 9 7 4;
	@read -p "Press any key to continue..."; clear; \
	\
	printf "$(CYAN)\nTesting with 3000 elements\n\n$(RESET) "; sleep 2;
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) `shuf -i 1-100000 -n 3000 | tr "\n" " "`;
	@read -p "Press any key to continue..."; clear; \
	\
	printf "$(CYAN)\nTesting with 10000 elements\n\n$(RESET) ";  sleep 2;
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) `shuf -i 1-100000 -n 10000 | tr "\n" " "`;
	@read -p "Press any key to continue..."; clear;

all:
	@$(MAKE_REC) -C ..

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "\033[0;35mProject done!\n\n\033[0;37m"

$(shell echo $(OBJS_DIR))/%.o: %.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	@printf "removing program executable $(NAME)\n\033[0;37m"
	$(RMF) -f $(NAME)
	@printf "\033[0;35mExecutable removed!\n\n\033[0;37m"

clean:
	@printf "removing Object files $(OBJS)\n\033[0;37m"
	$(RMF) $(OBJS_DIR)
	$(RMF) *_shrubbery
	@printf "\033[0;35mObject files removed!\n\n\033[0;37m"

re: fclean all

.BUILD:
	$(MKD) $(OBJS_DIR)
	@printf "\e[1;33mMaking exercise $(NAME) \n\033[0;37m"
	@$(MAKE_REC) $(NAME)

.RUN:
	$(MAKE_REC) -i exercise