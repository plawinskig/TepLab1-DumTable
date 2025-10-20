#include "alloc_dealloc_tables.hpp"
#include <iostream>
#include <string>
#include "print_table.hpp"

void alloc_table_fill_value(int size, int value)
{
	if (size <= 0)
	{
		std::cerr << "size is not a positive number.\n";
		return;
	}

	int *table = new int[size];

	for (int i = 0; i < size; i++)
	{
		table[i] = value;
	}

	print_table(table, size);

	delete[] table;
}// void alloc_table_fill_value(int size, int value)

bool alloc_table_2_dim(int ***table, int size_x, int size_y)
{
	if (size_x <= 0 || size_y <= 0)
	{
		return false;
	}

	*table = new int *[size_x];

	for (int i = 0; i < size_x; i++)
	{
		(*table)[i] = new int[size_y];
	}

	return true;
}// bool alloc_table_2_dim(int ***table, int size_x, int size_y)

bool dealloc_table_2_dim(int ***table, int size_x)
{
	if (size_x <= 0)
	{
		return false;
	}

	for (int i = 0; i < size_x; i++)
	{
		delete[] (*table)[i];
	}

	delete[] *table;
	table = nullptr;

	return true;
}// bool dealloc_table_2_dim(int ***table, int size_x)


