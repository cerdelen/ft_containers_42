# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 18:49:56 by cerdelen          #+#    #+#              #
#    Updated: 2022/08/28 16:24:03 by cerdelen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

SRC = main.cpp

NAME = executable

all:
	$(CC) $(SRC) -o $(NAME)

run: all
	./$(NAME)

clean:

fclean: clean
	rm $(NAME)

re: fclean all

git:
	git add .
	git commit -m "progress (autogit)"
	git push
	@echo 'successfully pushed'
	