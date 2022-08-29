

void try_catch_blocks()
{
	bool	og_try = false;
	bool	my_try = false;
	try
	{
		std::vector<int>	og(max_size, 10);
	}
	catch(const std::exception& e)
	{
		og_try = true;
	}
	try
	{
		ft::vector<int>		my(max_size, 10);
	}
	catch(const std::exception& e)
	{
		my_try = true;
	}
	if (!check_try_counts(og_try, my_try, "Calling Fill Constructor with negative size"))
		vars->curr++;
	check_scope_diff(vars, "Throwing exception calling Fill Constructor with negative size");
}

void	Fill_constructor_for_loop()
{
	int	max_size = 10;
	int	value = 10;
	std::vector<int>	og(max_size, value);
	ft::vector<int>		my(max_size, value);

	for (size_t i = 0; i < max_size; i++)
	{
		compare_ints_with_message(og[i], my[i], "Differences after Fill Constructor", vars);
	}
	check_scope_diff(vars, "Differences after Fill Constructor");
}
