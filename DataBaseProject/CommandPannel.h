#pragma once
#include"ArrayOfTables.h"
///this is the core of the program here I define all functions
class CommandPannel
{
public:
	
	void help();
	void exit();
	///import
	///@param data this is our array of Tables
	///@param nameofFile the name of the file you want to import
	void import(ArrayOfTables& data, String nameofFile);
	///showtables
	///@param data this is our array of Tables
	void showtables(ArrayOfTables& data);
	///@param data this is our array of Tables
	///@param name this is the name of the Table we want to describe
	void describe(ArrayOfTables& data,String name);
	///@param data this is our array of Tables
	///@param name this is the name of the Table we want to print
	void print(ArrayOfTables& data, String name);
	///@param data this is our array of Tables
	///@param name this is the name of the Table we want to export
	///@param name this is the name of the file we want to export the table to
	void exportTable(ArrayOfTables& data, String name, String fileName);
	///@param data this is our array of Tables
	///@param column is the column we want to search in
	///@param value is the value we are searching for
	///@param tableName is the name of the Table we are searching in
	void selectValue(ArrayOfTables& data, int column, String value, String tableName);
	///@param data this is our array of Tables
	///@param tableName is the name of the Table we want to add the Column to
	///@param columnName the name of the Column we want to add
	///@param columnType is the type of the Column we want to add
	void addColumn(ArrayOfTables& data, String tableName, String columnName, String columnType);
	///@param data this is our array of Tables
	///@param tableName is the name of the Table we want to update
	///@param columnS is the Column we are searching in
	///@param searchedValue is the value we are searching for
	///@param columnT is the column we want to change
	///@param targetValue is the value we want columnT to accept
	void update(ArrayOfTables& data, String tableName, int columnS, String searchedValue, int columnT, String targetValue);
	///@param data this is our array of Tables
	///@param tableName is the name of the Table we want to delete the row from
	///@param columnS is the Column we are searching in
	///@param searchedValue is the value we are searching for
	void deleteRow(ArrayOfTables& data, String tableName, int columnS, String searchedValue);
	///@param data this is our array of Tables
	///@param tableName is the name of the Table we want to insert the row
	///@param values is the values we want to add to our new row
	void insertRow(ArrayOfTables& data, String tableName, myVector<String>values);
	///@param data this is our array of Tables
	///@param table1 this is the name of the first Table
	///@param col1 this is the Column we want to add
	///@param table2 this is the name of the second Table
	///@param col2 this is the Column we want to add
	///@param name this is the name of the new Table
	void innerjoin(ArrayOfTables& data, String table1, int col1, String table2, int col2,String name);
	///@param data this is our array of Tables
	///@param oldName this is the name of the Table we want to rename
	///@param newName this is the name we want our Table to recieve
	void rename(ArrayOfTables& data, String oldName, String newName);
	///@param data this is our array of Tables
	///@param tableName this is the name of the Table we want to search in
	///@param column this is the column we want to search
	///@param value this is the value we are searching for
	void count(ArrayOfTables& data, String tableName, int column, String value);
	///@param data this is our array of Tables
	///@param tableName is the name of the Table
	///@param searchedColumn is the Column we are searching in
	///@param searchedValue is the Value we are searching for
	///@param targetColumn this is the column we want to take the numbers from
	///@param operation this is what operation we want to do
	void aggregate(ArrayOfTables& data, String tableName, int searchedColumn, String searchedValue, int targetColumn, String operation);
	///
	void startProgram();

	
};


