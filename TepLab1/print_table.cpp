#include "print_table.hpp"
#include <iostream>

namespace 
{
	const std::string SEPARATOR = "\t";
}// namespace

void print_table(int *table, int size) 
{
	for (int i = 0; i < size; i++) 
	{
		std::cout << table[i] << SEPARATOR;
	}

	std::cout << "\n";
}// void print_table(int *table, int size)

void print_table(int **table, int size_x, int size_y)
{
	for (int i = 0; i < size_x; i++)
	{
		for (int j = 0; j < size_y; j++)
		{
			std::cout << table[i][j] << SEPARATOR;
		}

		std::cout << "\n";
	}
}

void print_table(Table &table)
{
	std::cout << table.get_name() << ": ";
	for (int i = 0; i < table.get_len(); i++)
	{
		std::cout << table.get_elem(i) << SEPARATOR;
	}

	std::cout << "\n";
}