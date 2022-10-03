# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 18:49:56 by cerdelen          #+#    #+#              #
#    Updated: 2022/10/03 18:26:14 by cerdelen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

SRC = main.cpp
CFLAGS = 
DFLAG = -D DEBUG=1
ULTRAFLAGS = -Wall -Werror -Wextra -std=c++98


NAME = executable

all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

run: all
	@echo ""
	@echo ""
	./$(NAME)

leaks:
	leaks -atExit -- ./$(NAME)

debug: CFLAGS += $(DFLAG)
debug: re

run_debug: CFLAGS += $(DFLAG)
run_debug: fclean run

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all

git:
	git add .
	git commit -m "progress (autogit)"
	git push
	@echo 'successfully pushed'
