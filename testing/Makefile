# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 23:10:30 by cerdelen          #+#    #+#              #
#    Updated: 2022/08/29 00:15:53 by cerdelen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

SRC = main.cpp

NAME = executable

all:
	$(CC) $(SRC) -o $(NAME)

run: all
	./$(NAME)

leaks:
	leaks -atExit -- ./$(NAME)
	

clean:

fclean: clean
	rm $(NAME)

re: fclean all
	