# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 17:11:58 by earendil          #+#    #+#              #
#    Updated: 2023/05/21 18:51:00 by mmarinel         ###   ########.fr        #
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

all:
	@printf "Making all exercises\n"
	@for DIR in $$(find . -print | grep "Makefile" | sed 's/Makefile//g' | grep ex); do \
		make --no-print-directory -C $$DIR exercise; \
	done;
	@echo Exercises done!

ex%: FORCE
	@$(MAKE) -C $@ run

FORCE:#https://www.gnu.org/software/make/manual/make.html#Force-Targets

run:
	@make --no-print-directory -si .RUN

fclean:
	@printf "Destroying all exercises\n"
	@for DIR in $$(find . -print | grep "Makefile" | sed 's/Makefile//g' | grep ex); do \
		make --no-print-directory -C $$DIR fclean; \
	done;
	@echo Exercises destroyed!
	@sleep 0.5; clear

re: fclean all

.RUN:
	@printf "Running all exercises\n"
	@for DIR in $$(find . -print | grep "Makefile" | sed 's/Makefile//g' | grep ex); do \
		clear; \
		make --no-print-directory -C $$DIR run; \
		printf "\n"; \
		printf $(BOLDWHITE); \
		read -p "Press Enter to continue"; \
		printf $(RESET); \
	done;
	@printf "\n"
	@printf "$(BOLDGREEN)Run completed!$(RESET)"
	@printf "\n"
