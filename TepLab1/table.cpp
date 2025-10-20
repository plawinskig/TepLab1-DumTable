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
}

void Table::print()
{
	std::cout << name_ << ": ";
	for (int i = 0; i < table_len_; i++)
	{
		std::cout << table_[i] << SEPARATOR;
	}

	std::cout << "\n";
}// Table *Table::clone()

void mod_tab(Table *tab, int new_size)
{
	tab->set_new_size(new_size);
}// void mod_tab(Table *tab, int new_size)

void mod_tab(Table tab, int new_size)
{
	tab.set_new_size(new_size);
}// void mod_tab(Table tab, int new_size)
