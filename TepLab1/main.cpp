#include "alloc_dealloc_tables.hpp"
#include "table.hpp"
#include "print_table.hpp"
#include <iostream>

int main() 
{
    // z1
    std::cout << "\n> alloc table fill value\n";

    int size = 5;

    alloc_table_fill_value(size);

    // z2
    std::cout << "\n> alloc table 2 dim\n";

    int size_x = 5;
    int size_y = 3;
    int **table = nullptr;

    bool is_alloc_successful = alloc_table_2_dim(&table, size_x, size_y);

    if (is_alloc_successful)
    {
        std::cout << "> allocation successful\n";
        print_table(table, size_x, size_y);
    }
    else
    {
        std::cerr << "> allocation unsuccessful\n";
    }

    // z3
    std::cout << "\n> dealloc table 2 dim\n";

    bool is_dealloc_successful = dealloc_table_2_dim(&table, size_x);

    if (is_dealloc_successful)
    {
        std::cout << "> deallocation successful\n";
    }
    else
    {
        std::cerr << "> deallocation unsuccessful\n";
    }
    
    // z4
    std::cout << "\n> create default table\n";
    Table default_table;
    default_table.print();

    std::cout << "\n> create static table\n";
	Table static_table("The_static_table", 5);
	static_table.print();
    
    std::cout << "\n> try mod static table\n";
	mod_tab(static_table, 7);
	static_table.print();

    std::cout << "\n> try mod static table\n";
	mod_tab(static_table, 3);
	static_table.print();

    std::cout << "\n> create clone\n";
	Table *dynamic_table = static_table.clone();
    static_table.print();
	dynamic_table->print();

    std::cout << "\n> set new name for clone\n";
    dynamic_table->set_name("The_dynamic_table");
    dynamic_table->print();

    std::cout << "\n> mod dynamic table\n";
    mod_tab(dynamic_table, 7);
    dynamic_table->print();

    std::cout << "\n> mod dynamic table\n";
    mod_tab(dynamic_table, 3);
    dynamic_table->print();

    std::cout << "\n> delete dynamic table\n";
    delete dynamic_table;

    std::cout << "\n> create array of tables\n";
    Table *array_of_tables = new Table[5];

    std::cout << "\n> modify array of tables\n";
    array_of_tables[2].set_name("Mid");

    std::cout << "\n> delete array of tables\n";
    delete[] array_of_tables;

    std::cout << "\n> test_table END\n";
}// int main()
