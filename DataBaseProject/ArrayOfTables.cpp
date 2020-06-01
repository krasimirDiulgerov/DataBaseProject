#include "ArrayOfTables.h"

Table ArrayOfTables::operator[](const int index)const {
	return this->arrayOfTables[index];
}

Table& ArrayOfTables::operator[](int index) {
	return this->arrayOfTables[index];
}

void ArrayOfTables::addTable(Table&other) {
	this->arrayOfTables.push_back(other);
	this->namesOfTables.push_back(other.getName());
}

void ArrayOfTables::printNames() {
	std::cout << "The following tables are loaded:" << std::endl;
	for (int i = 0; i < this->arrayOfTables.getSize(); i++) {
		std::cout << arrayOfTables[i].getName() << std::endl;
	}
}

int ArrayOfTables::getSize() {
	return this->arrayOfTables.getSize();
}