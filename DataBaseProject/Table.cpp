#include "Table.h"

void Table::addColumn() {
	Column* temp = new Column();
	this->table.push_back(*temp);
}

void Table::addColumn(String name) {
	Column* temp = new Column(name);
	this->table.push_back(*temp);
}

Table::Table() {
	this->name = " ";
	sizeOfColumns = 0;
}

Table::Table(String name) {
	this->name = name;
	sizeOfColumns = 0;
}

void Table::print(std::ostream& out){
	
	out << this->name << " " << this->table.getSize() << " " << this->sizeOfColumns << std::endl;
	
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
	for (int i = 0; i < this->sizeOfColumns; i++) {
		for (int j = 0; j < table.getSize(); j++) {
		out << " / " << table[j][i].getString();
		}
		out << std::endl;
	}
	for (int j = 0; j < table.getSize(); j++) {
		out << table[j].getName() << " ";
	}
	out << std::endl;
	for (int i = 0; i < table.getSize(); i++) {
		out << table[i].getType() << " ";
	}
	out << std::endl;
}

void Table::read(std::istream& in){
	String name;
	int colCount;
	int rowCount;
	in >> name;
	in >> colCount;
	in >> rowCount;
	in.ignore();
	this->name = name;
	for (int i = 0; i < colCount; i++) {
		this->addColumn();
	}
	this->sizeOfColumns = rowCount;
	this->resizeColumnsInTable();
	
	for (int i = 0; i < this->sizeOfColumns; i++) {
		for (int j = 0; j < colCount; j++) {
			String temp;
			String a;
			in >> a;
			in >> temp;
			
			
			
			table[j][i].setCellStr(temp);
			
		}
	}
	for (int i = 0; i < colCount; i++) {
		String temp;
		in >> temp;
		this->table[i].setName(temp);
	}
	for (int i = 0; i < colCount; i++) {
		String temp;
		in >> temp;
		this->table[i].setType(temp);


	}
	

}

void Table::addColumn(String name, String type){

	Column* temp = new Column(name, type);
	table.push_back(*temp);
}

void Table::resizeColumnsInTable(){
	for (int i = 0; i < table.getSize(); i++) {
		if (this->sizeOfColumns < table[i].getSize())sizeOfColumns = table[i].getSize();
	}
	for (int j = 0; j < table.getSize(); j++) {
		table[j].completeColumn(sizeOfColumns);
	}

}

void Table::describeColumns(){
	std::cout << "This table has the following types of columns:" << std::endl;
	for (int i = 0; i < table.getSize(); i++) {
		std::cout << table[i].getType() << " ";
	}
	std::cout << std::endl;
}

void Table::addRow(){
	for (int i = 0; i < table.getSize(); i++) {
		Cell* temp = new Cell();
		table[i].pushNewCell(*temp);
	}

}

void Table::rename(String newName) {
	this->name = newName;

}

String Table::getName() {
	return this->name;
}

void Table::printTypesOfColumns() {
	std::cout << "The types of columns of the table are the following:" << std::endl;
	for (int i = 0; i < this->table.getSize(); i++) {
		std::cout << table[i].getType() << std::endl;
	}
}

void Table::printOnConsole() {
	for (int j = 0; j < table.getSize(); j++) {
		std::cout << table[j].getName() << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < this->sizeOfColumns; i++) {
		for (int j = 0; j < table.getSize(); j++) {
			std::cout << " / " << table[j][i].getString();
		}
		std::cout << std::endl;
	}

}

void Table::removeRow(int index){
	for (int i = 0; i < this->table.getSize(); i++) {
		
		table[i].getColumnVector().remove(index);
		sizeOfColumns--;
	}
}

void Table::printRow(int index){
	for (int i = 0; i < table.getSize(); i++) {
		std::cout << table[i][index].getString() << " ";
	}
	std::cout << std::endl;
}

myVector<Column>& Table::getTable() {
	return this->table;
}

void Table::addColumn(Column&other) {
	Column temp(other);
	table.push_back(temp);
}

int Table::getSizeOfColumns() {
	return sizeOfColumns;
}