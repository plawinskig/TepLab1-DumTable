#pragma once

#include <string>

namespace{
	const std::string DEFAULT_NAME = "Unknown";
	const int DEFAULT_TABLE_LEN = 8;
	const std::string COPY_SUFFIX = "_copy";
}// namespace

class Table
{
public:
	Table();
	Table(std::string name, int table_len);
	Table(const Table &other);
	~Table();

	void set_name(std::string name);
	bool set_new_size(int table_len);
	Table *clone();
	Table *get_reverted();
	bool set_elem(int value, int index);
	int get_elem(int index);
	int get_len();
	std::string get_name();

private:
	std::string name_;
	int *table_;
	int table_len_;
};// class Table

void mod_tab(Table *tab, int new_size);
void mod_tab(Table tab, int new_size);
