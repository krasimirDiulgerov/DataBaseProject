#pragma once
#include"Table.h"
///this is my main information source here i keep the tables
class ArrayOfTables
{
private:
	myVector<Table>arrayOfTables;
	myVector<String>namesOfTables;
public:
	///operator[]
	Table operator[](const int index)const;
	///operator[]
	Table& operator[](int index);
	///adds table
	void addTable(Table&);
	///prints the names of the Table
	void printNames();
	///returns size
	int getSize();
};

