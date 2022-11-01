CC = c++

SRC_MAP = map_test.cpp 
SRC_VECTOR = vector_test.cpp\
		vector_test/utils.cpp\
		vector_test/test_vector_at.cpp\
		vector_test/test_vector_fill_constructor.cpp\
		vector_test/test_vector_range_constructor.cpp\
		vector_test/test_vector_copy_constructor.cpp\
		vector_test/test_vector_asign.cpp\
		vector_test/test_vector_get_alloc_max_size.cpp\
		vector_test/test_vector_accessing_functions.cpp
SRC_SET = set_test.cpp
SRC_STACK = stack_test.cpp
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g -fsanitize=address
# ULTRAFLAGS = -Wall -Werror -Wextra -std=c++98 -g -fsanitize=address

NAME = executable

all:
	@$(CC) $(CFLAGS) $(SRC_VECTOR) -o $(NAME)
	./executable
	@$(CC) $(CFLAGS) $(SRC_MAP) -o $(NAME)
	./executable
	@$(CC) $(CFLAGS) $(SRC_STACK) -o $(NAME)
	./executable
	@$(CC) $(CFLAGS) $(SRC_SET) -o $(NAME)
	./executable

vector:
	@$(CC) $(CFLAGS) $(SRC_VECTOR) -o $(NAME)
	./executable
map:
	@$(CC) $(CFLAGS) $(SRC_MAP) -o $(NAME)
	./executable
stack:
	@$(CC) $(CFLAGS) $(SRC_STACK) -o $(NAME)
	./executable
set:
	@$(CC) $(CFLAGS) $(SRC_SET) -o $(NAME)
	./executable




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
