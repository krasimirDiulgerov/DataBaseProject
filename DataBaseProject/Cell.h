#pragma once
#include"String.h"
///this class is used as a base of the program it can be String Double or Int
class Cell
{
private:
	String cell;
	bool isInt;
	bool isDouble;
	bool isString;
	bool isEmpty;
	

public:
	///This function sets the String in the cell
	void setCellStr(String);
	///This function converts the Cell in int
	int convertToInt();
	///This function converts the cell in double
	double convertToDouble();
	///returns whether it is int or not
	bool getIsInt()const;
	///eturns whether it is double or not
	bool getIsDouble()const;
	///returns whether it is string or not
	bool getIsString()const;
	///returns whether it is empty or not
	bool getIsEmpty()const;
	///sets the bool for whether it is int or not
	void setIsInt();
	///sets the bool for whether it is double or not
	void setIsDouble();
	///sets the bool for whether it is string or not
	void setIsString();
	///sets the bool for whether it is empty or not
	void setIsEmpty();
	///sets the string of the cell
	void setString(String);
	///returns the string of the cell
	String getString();
	///constructor
	Cell();
	///constructor
	Cell(String info);
	///checks if its legit
	void checkIfLegit();
	

};

