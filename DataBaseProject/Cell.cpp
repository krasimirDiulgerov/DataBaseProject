#include "Cell.h"

void Cell::checkIfLegit() {
	if (isInt) {
		bool isLegit = true;
		if (this->cell[0] != '+' && cell[0] != '-' && (cell[0] <= '0' || cell[0] >= '9'))isLegit = false;
		if (cell[0] == '-' || cell[0] == '+') {
			for (int i = 1; i < cell.size(); i++){
				if(cell[i]<='0'||cell[i]>='9')isLegit=false;
			}
		}
		else {
			for (int i = 0; i < cell.size(); i++) {
				if (cell[i] < '0' || cell[i]>'9')isLegit = false;
			}
		}
		
		if (isLegit == false) {

			setIsEmpty();
		}
		

	}

	else if (isDouble) {
		bool isLegit = true;
		int countDots = 0;
		for (int i = 0; i < cell.size(); i++) {
			if (cell[i] == '.')countDots++;
		}
		if (countDots > 1)isLegit = false;
		if (this->cell[0] != '+' && cell[0] != '-' && (cell[0] <= '0' || cell[0] >= '9')&&cell[0]!='.')isLegit = false;
		if (cell[0] == '-' || cell[0] == '+' || cell[0]=='.') {
			for (int i = 1; i < cell.size(); i++) {
				if ((cell[i] <= '0' || cell[i] >= '9')&&cell[i]!='.')isLegit = false;
			}
		}else {
			for (int i = 0; i < cell.size(); i++) {
				if ((cell[i] < '0' || cell[i]>'9')&&cell[i]!='.')isLegit = false;
			}
		}
		
		if (isLegit == false) {
			setIsEmpty();
		}
	
	}

	else if (isString) {
		bool isLegit = true;
		if (cell[0] != '\"')isLegit = false;
		if (cell[cell.size()] != '\"')isLegit = false;
		for (int i = 1; i < (cell.size() - 1); i++) {
			if (cell[i] == '\"' && cell[i - 1] == '\\')isLegit = false;
			if (cell[i] == '\\' && cell[i - 1] == '\\')isLegit = false;
		}
		if (isLegit == false) {
			setIsEmpty();
		}
		
	}
	
}

void Cell::setCellStr(String info){
	cell = info;
	
}

int Cell::convertToInt(){
	if (isEmpty)return 0;
	if (isInt) {
		if (cell[0] == '+') {
			int sum = 0;
			for (size_t i = 1; i < cell.size(); i++)
			{
				sum *= 10;
				sum += cell[i] - '0';
			}
			return sum;
		}
		if (cell[0] == '-') {
			int sum = 0;
			for (size_t i = 1; i < cell.size(); i++)
			{
				sum *= 10;
				sum += cell[i] - '0';
			}
			return sum*(-1);
		}
		else {
			int sum = 0;
			for (size_t i = 0; i < cell.size(); i++)
			{
				sum *= 10;
				sum += cell[i] - '0';
			}
			return sum;
		}
	}
	
	
}

double Cell::convertToDouble(){
	if (isEmpty)return 0;
	if (isDouble) {

		if (cell[0] == '-') {
			double sum = 0;
			int index = -1;
			for (int i = 1; i < cell.size(); i++) {
				if (cell[i] == '.') {
					index = i;
					break;
				}
				sum *= 10;
				sum += cell[i] - '0';

			}
			double sumFloat = 0;
			if (index != -1) {
				for (int i = index + 1; i < cell.size(); i++) {
					sumFloat += cell[i] - '0';
					sumFloat /= 10;
				}
			}
			return (sum + sumFloat) * (-1);
		}

		else if (cell[0] == '+') {
			double sum = 0;
			int index = -1;
			for (int i = 1; i < cell.size(); i++) {
				if (cell[i] == '.') {
					index = i;
					break;
				}
				sum *= 10;
				sum += cell[i] - '0';

			}
			double sumFloat = 0;
			if (index != -1) {
				for (int i = index + 1; i < cell.size(); i++) {
					sumFloat += cell[i] - '0';
					sumFloat /= 10;
				}
			}
			return (sum + sumFloat);
		}

		else {
			double sum = 0;
			int index = -1;
			for (int i = 0; i < cell.size(); i++) {
				if (cell[i] == '.') {
					index = i;
					break;
				}
				sum *= 10;
				sum += cell[i] - '0';

			}
			double sumFloat = 0;
			if (index != -1) {
				for (int i = index + 1; i < cell.size(); i++) {
					sumFloat += cell[i] - '0';
					sumFloat /= 10;
				}
			}
			return (sum + sumFloat);
		}

	}
	else {
		return 0.0;
	}
}

bool Cell::getIsInt()const{
	return this->isInt;
}

bool Cell::getIsDouble()const{
	return this->isDouble;
}

bool Cell::getIsString()const{
	return this->isString;
}

bool Cell::getIsEmpty()const{
	return this->isEmpty;
}

void Cell::setIsInt(){
	isInt = true;
	isDouble = false;
	isString = false;
	isEmpty = false;
	checkIfLegit();
}

void Cell::setIsDouble(){
	isInt = false;
	isDouble = true;
	isString = false;
	isEmpty = false;
	checkIfLegit();
}

void Cell::setIsString(){
	isInt = false;
	isDouble = false;
	isString = true;
	isEmpty = false;
	checkIfLegit();
}

void Cell::setIsEmpty() {
	setCellStr("NULL");
	this->isEmpty = true;
	
}


Cell::Cell() {
	this->cell ="NULL";
	this->isDouble = false;
	this->isInt = false;
	this->isString = false;

	
}

Cell::Cell(String info) {
	setCellStr(info);
	this->isDouble = false;
	this->isInt = false;
	this->isString = false;
	this->isEmpty = false;
}

void Cell::setString(String info) {
	cell = info;
	checkIfLegit();
}

String Cell::getString() {
	return cell;

}
