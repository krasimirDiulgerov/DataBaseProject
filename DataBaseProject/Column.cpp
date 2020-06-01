#include "Column.h"

Column::Column(String name) {
	this->name = name;
	this->type = " ";
}

void Column::setType(String type_) {
	this->type = type_;
	setTypeForCells();
}

void Column::setTypeForCells() {
	for (int i = 0; i < column.getSize(); i++) {
		if (type == "int") {
			column[i].setIsInt();
		}
		if (type == "double") {
			column[i].setIsDouble();
		}
		if (type == "string") {
			column[i].setIsString();
		}
	}
}

void Column::clear() {
	column.clear();
	
}

void Column::copy(const Column& other) {
	for (int i = 0; i < other.getSize(); i++) {
		this->column.push_back(other[i]);
	}
	name = other.name;
	type = other.type;

}

String Column::getName()const {
	return this->name;
}

String Column::getType()const{
	return this->type;
}

Column::Column() {
	this->name = " ";
	this->type = " ";

}

Column::Column(String name, String type) {
	this->name = name;
	this->type = type;
	setTypeForCells();
}

Column::Column(const Column& other) {
	this->copy(other);
	setTypeForCells();
}

Column::~Column() {
	this->clear();
}

Column Column::operator=(const Column& other) {
	if (this != &other) {
		this->clear();
		this->copy(other);

	}
	return *this;
}

Cell Column::operator[] (const int index)const {
	return column[index];

}

int Column::getSize()const {

	return column.getSize();
}

void Column::pushNewCell(Cell& other) {
	column.push_back(other);
	setTypeForCells();
}

void Column::completeColumn(int amount) {
	if (amount > column.getSize()) {
		int needed = amount - column.getSize();
		for (int i = 0; i < needed; i++) {
			Cell* temp = new Cell();
			this->column.push_back(*temp);
		}
	}
	setTypeForCells();
}

myVector<int> Column::searchValue(String value) {
	myVector<int>rowsNeeded;
	for (int i = 0; i < column.getSize(); i++) {
		if (column[i].getString() == value)rowsNeeded.push_back(i);
	}
	return rowsNeeded;
}

void Column::setName(String name) {
	this->name = name;
}

Cell& Column::operator[](int index) {
	return column[index];
}

myVector<Cell>& Column::getColumnVector() {
	return this->column;
}