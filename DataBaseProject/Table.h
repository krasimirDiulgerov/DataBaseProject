#pragma once
#include"Column.h"
///this Table class is used to keep information it consists of array of Columns
class Table
{
private:
	
	String name;
	int sizeOfColumns;
	myVector<Column>table;
public:
	/// returns the vector
	myVector<Column>& getTable();
	/// returns name
	String getName();
	///constructor
	Table();
	///constructor
	Table(String name);
	///prints the table in a file using stream
	void print(std::ostream& out);
	///reads info about table and fills our table with the info
	void read(std::istream& in);
	///adds column
	void addColumn(String);
	///adds column
	void addColumn(String, String);
	///adds column
	void addColumn(Column&);
	///adds column
	void addColumn();
	///makes all columns one size and adds rows
	void resizeColumnsInTable();
	///gives info about the columns in the table
	void describeColumns();
	///adds row
	void addRow();
	///renames the table
	void rename(String);
	///prints the types of the columns in the table
	void printTypesOfColumns();
	///prints on console
	void printOnConsole();
	///removes row in specific index
	void removeRow(int index);
	///prints specific row
	void printRow(int index);
	///return the size of the columns
	int getSizeOfColumns();

};

