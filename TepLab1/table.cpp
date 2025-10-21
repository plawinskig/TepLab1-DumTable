#include "table.hpp"
#include <iostream>

Table::Table()
{
	name_ = DEFAULT_NAME;
	std::cout << "paramless: " << name_ << "\n";

	table_len_ = DEFAULT_TABLE_LEN;
	table_ = new int[table_len_];
}// Table::Table()

Table::Table(std::string name, int table_len)
{
	name_ = name;
	std::cout << "parameter: " << name_ << "\n";

	if (table_len <= 0)
	{
		table_len = DEFAULT_TABLE_LEN;
	}

	table_len_ = table_len;
	table_ = new int[table_len_];
}// Table::Table(std::string name, int table_len)

Table::Table(const Table &other)
{
	name_ = other.name_ + COPY_SUFFIX;

	table_len_ = other.table_len_;

	table_ = new int[table_len_];

	for (int i = 0; i < table_len_; i++)
	{
		table_[i] = other.table_[i];
	}

	std::cout << "copy: " << name_ << "\n";
}// Table::Table(const Table &other)

Table::~Table()
{
	std::cout << "deleting: " << name_ << "\n";
	delete[] table_;
}// Table::~Table()

void Table::set_name(std::string name)
{
	name_ = name;
}// void Table::set_name(std::string name)

bool Table::set_new_size(int table_len)
{
	if (table_len <= 0)
	{
		return false;
	}

	int *new_table = new int[table_len];

	for (int i = 0; i < table_len && i < table_len_; i++)
	{
		new_table[i] = table_[i];
	}

	delete[] table_;
	table_ = new_table;

	table_len_ = table_len;

	return true;
}// bool Table::set_new_size(int table_len)

Table *Table::clone()
{
	Table *table_clone = new Table(*this);
	table_clone->set_name(name_);
	return table_clone;
}// Table *Table::clone()

Table *Table::get_reverted()
{
	Table *new_table = new Table(name_ + COPY_SUFFIX, table_len_);

	for (int i = 0; i < table_len_; i++)
	{
		new_table->set_elem(table_[table_len_ - i - 1], i);
	}

	return new_table;
}// Table *Table::get_reverted()

bool Table::set_elem(int value, int index)
{
	if (index < 0 || index >= table_len_)
	{
		return false;
	}

	table_[index] = value;

	return true;
}// int Table::set_elem(int value, int index)

int Table::get_elem(int index)
{
	if (index < 0 || index >= table_len_)
	{
		return 0;
	}
	return table_[index];
}// int Table::get_elem(int index)

int Table::get_len()
{
	return table_len_;
}// int Table::get_len()

std::string Table::get_name()
{
	return name_;
}// int Table::get_name()

void mod_tab(Table *tab, int new_size)
{
	tab->set_new_size(new_size);
}// void mod_tab(Table *tab, int new_size)

void mod_tab(Table tab, int new_size)
{
	tab.set_new_size(new_size);
}// void mod_tab(Table tab, int new_size)
