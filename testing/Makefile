# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 23:10:30 by cerdelen          #+#    #+#              #
#    Updated: 2022/08/29 23:23:30 by cerdelen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

SRC =	main.cpp\
		utils.cpp\
		test_vector_at.cpp\
		test_vector_fill_constructor.cpp\
		test_vector_range_constructor.cpp\
		test_vector_copy_constructor.cpp\
		test_vector_asign.cpp\

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
	