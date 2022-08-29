# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 23:10:30 by cerdelen          #+#    #+#              #
#    Updated: 2022/08/29 17:20:03 by cerdelen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

SRC =	main.cpp\
		test_vector_at.cpp\
		utils.cpp\
		test_fill_constructor.cpp\
		test_range_constructor.cpp\

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
	