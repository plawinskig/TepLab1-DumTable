#pragma once

namespace
{
	const int DEFAULT_FILL_VALUE = 34;
}

void alloc_table_fill_value(int size, int value = DEFAULT_FILL_VALUE);
bool alloc_table_2_dim(int ***table, int size_x, int size_y);
bool dealloc_table_2_dim(int ***table, int size_x);
