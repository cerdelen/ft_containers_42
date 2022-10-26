#ifndef SETUP_HPP_
#define SETUP_HPP_
#include "config.hpp"
#include "colours.h"


#define __compiler_flags
#define __exec_name

#include <iostream>






void	print_block(std::string print, std::string col)
{
	std::cout << col << print;
	for (size_t i = print.length(); i < 22; i++)
	{
		std::cout << " ";
	}
	std::cout << DEFAULT_COL;
}

void	print_test_header(std::string head)
{
	std::cout << BLUE_COL;
	std::cout << "---------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "|";
	for (size_t i = 0; i < (91 - head.length()) / 2; i++)
		std::cout << " ";
	std::cout << head;
	for (size_t i = 0; i < (90 - head.length()) / 2; i++)
		std::cout << " ";
	std::cout << " |" << std::endl;
	std::cout << "---------------------------------------------------------------------------------------------" << std::endl;
	std::cout << DEFAULT_COL;
	print_block("MEMBER FUNCTION", YELLOW_COL);
	print_block("RESULT", YELLOW_COL);
	print_block("FT TIME", YELLOW_COL);
	print_block("STD TIME", YELLOW_COL);
	print_block("LEAKS", YELLOW_COL);
}

void	test_compile(int *status, const char *funciton_filename, char **env)
{
	pid_t	pid;
	char	**exec_arr = (char**)malloc(sizeof(char*) * 9);

	exec_arr[0] = strdup(_CXX);
	exec_arr[1] = strdup("-o");
	exec_arr[2] = strdup(_EXEC_NAME);
	exec_arr[3] = strdup(func_filename);
	#if defined(FLAGS)
	exec_arr[4] = strdup("-std=c++98");
	exec_arr[5] = strdup("-Wall");
	exec_arr[6] = strdup("-Wextra");
	exec_arr[7] = strdup("-Werror");

}

void	execute_test(int *status)
{

}

void	run_test_member_function(std::string function_filename, char **env)			//gets name of cpp file to be compiled and run
{
	int		status = 0;
	std::string tmp = function_filename.substr(function_filename.find_last_of('/') + 1);
	std::string output = tmp.erase(tmp.length() - 4);

	test_compile(&status, function_filename.c_str(),env);
	execute_test(&status);


}





#endif