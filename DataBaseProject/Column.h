#pragma once
#include"Cell.h"
#include"MyVector.hpp"
///this class consists of Array of Cells and I use it to build Table
class Column
{
private:
	myVector<Cell> column;
	String type;
	String name;
	void copy(const Column&);
	void clear();
public:
	///sets the Type of the column
	void setType(String);
	///sets the type of the cells of the column
	void setTypeForCells();
	///sets the name of the column
	void setName(String);
	///returns the name of the column
	String getName()const;
	///returns the type of the column
	String getType()const;
	///constructor
	Column();
	///constructor
	Column(const Column&);
	///constructor
	Column(String name, String type);
	///constructor
	Column(String name);
	///destructor
	~Column();
	///operator=
	Column operator=(const Column&);
	///operator[]
	Cell operator[](const int index)const;
	///operator[]
	Cell& operator[](int index);
	///returns the size
	int getSize()const;
	///pushes new cell to the column
	void pushNewCell(Cell&);
	///creates cells to complete the column to specific int
	void completeColumn(int);
	/// searches in the cell for specific value and returns the rows where it can be found
	myVector<int> searchValue(String);
	///returns the vector
	myVector<Cell>& getColumnVector();
};

