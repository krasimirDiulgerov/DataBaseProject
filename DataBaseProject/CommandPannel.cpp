#include"CommandPannel.h"

void CommandPannel::help(){
	std::cout << "The following commands are supported:" << std::endl;
	std::cout << "import<file name>     Loads a table from a file" << std::endl;
	std::cout << "showtables            Shows the names of the tables loaded at the moment" << std::endl;
	std::cout << "describe<name>        Loads info about the types in a table" << std::endl;
	std::cout << "print<name>           Prints a specific table" << std::endl;
	std::cout << "export                Saves a table in file" << std::endl;
	std::cout << "select                Returns all rows of table who contain a specific value in specific place" << std::endl;
	std::cout << "addcolumn             Adds column in table" << std::endl;
	std::cout << "update                changes the value of specific cell in specific table" << std::endl;
	std::cout << "delete                deletes all rows from a table who contain a specific value" << std::endl;
	std::cout << "insert                inserts new row in table" << std::endl;
	std::cout << "innerjoin             Inner JOIN" << std::endl;
	std::cout << "rename                changes the name of the Table" << std::endl;
	std::cout << "count                 Returns the amount of rows containing specific value" << std::endl;
	std::cout << "aggregate             Makes specific operations" << std::endl;
	std::cout << "help                  Returns information about the functions" << std::endl;
	std::cout << "exit                  Leaves the program" << std::endl;


}

void CommandPannel::exit() {
	std::cout << "EXIT" << std::endl;
}

void CommandPannel::import(ArrayOfTables& data,String nameofFile) {
	Table temp;
	nameofFile.addChar('.');
	nameofFile.addChar('t');
	nameofFile.addChar('x');
	nameofFile.addChar('t');
	std::ifstream inFile(nameofFile.getCharArray(), std::ios::in);

	if (!inFile) {
		std::cerr << "File couldnt be opened! \n";
	}
	if (inFile) {
		temp.read(inFile);
	}
	inFile.close();
	bool isNew = true;
	for (int i = 0; i < data.getSize(); i++) {
		if (strcmp(temp.getName().getCharArray(), data[i].getName().getCharArray()) == 0) {
			isNew = false;
		}
	}
	if (isNew) {
		data.addTable(temp);
	}
	else {
		std::cout << "This name is already taken the table will not be added" << std::endl;
	}
}

void CommandPannel::showtables(ArrayOfTables& data) {
	data.printNames();
}

void CommandPannel::describe(ArrayOfTables& data, String name) {
	for (int i = 0; i < data.getSize(); i++) {
		if (strcmp(data[i].getName().getCharArray(), name.getCharArray()) == 0) {
			data[i].printTypesOfColumns();
		}
	}

}

void CommandPannel::print(ArrayOfTables& data, String name) {
	for (int i = 0; i < data.getSize(); i++) {
		if (strcmp(data[i].getName().getCharArray(), name.getCharArray()) == 0) {
			data[i].printOnConsole();
		}
	}

}

void CommandPannel::exportTable(ArrayOfTables& data, String name,String fileName) {
	fileName.addChar('.');
	fileName.addChar('t');
	fileName.addChar('x');
	fileName.addChar('t');
	std::ofstream oFile;
	oFile.open(fileName.getCharArray(), std::ios::out, std::ios::trunc);
	if (!oFile) {
		std::cerr << "File couldnt be opened! \n";
	}

	for (int i = 0; i < data.getSize(); i++) {
		if (strcmp(data[i].getName().getCharArray(), name.getCharArray()) == 0) {
			data[i].print(oFile);
		}
	}
	oFile.close();
}

void CommandPannel::selectValue(ArrayOfTables& data,int column, String value, String tableName) {
	int index = -1;
	for (int i = 0; i < data.getSize(); i++) {
		if (strcmp(data[i].getName().getCharArray(), tableName.getCharArray()) == 0) {
			index = i;
		}
	}
	if (index == -1)std::cout << "No table with that name" << std::endl;
	else {

		myVector<int>rows = data[index].getTable()[column].searchValue(value);
		if (rows.getSize() == 0)std::cout << "No such value found in this table" << std::endl;
		else{
			std::cout << "The following rows contain the value:" << std::endl;
			for (int i = 0; i < rows.getSize(); i++) {
				data[index].printRow(rows[i]);
			}
		}
	}

}

void CommandPannel::addColumn(ArrayOfTables& data, String tableName,String columnName,String columnType){
	bool legitType = true;
	if (columnType != "int" && columnType != "double" && columnType != "string")legitType = false;
	if (legitType) {
		for (int i = 0; i < data.getSize(); i++) {
			if (strcmp(data[i].getName().getCharArray(), tableName.getCharArray()) == 0) {
				data[i].addColumn(columnName, columnType);
				data[i].resizeColumnsInTable();
			}
		}
	}

}

void CommandPannel::update(ArrayOfTables& data, String tableName, int columnS, String searchedValue,int columnT, String targetValue){
	int index = -1;
	for (int i = 0; i < data.getSize(); i++) {
		if (strcmp(data[i].getName().getCharArray(), tableName.getCharArray()) == 0) {
			index = i;
		}
	}
	if (index == -1)std::cout << "No table with that name" << std::endl;
	else {

		myVector<int>rows = data[index].getTable()[columnS].searchValue(searchedValue);
		if (rows.getSize() == 0)std::cout << "No such value found in this table" << std::endl;
		else {
			
			for (int i = 0; i < rows.getSize(); i++) {
				std::cout << data[index].getTable()[columnT][rows[i]].getString();
				//takes the table on index place takes its columnT column and finds the rows we are searching for and changes the value
				data[index].getTable()[columnT].getColumnVector()[rows[i]].setCellStr(targetValue);
				std::cout << targetValue;
				std::cout << data[index].getTable()[columnT].getColumnVector()[rows[i]].getString();
			}
		}
	}
}

void CommandPannel::deleteRow(ArrayOfTables& data, String tableName, int columnS, String searchedValue){
	int index = -1;
	for (int i = 0; i < data.getSize(); i++) {
		if (strcmp(data[i].getName().getCharArray(), tableName.getCharArray()) == 0) {
			index = i;
		}
	}
	if (index == -1)std::cout << "No table with that name" << std::endl;
	else {

		myVector<int>rows = data[index].getTable()[columnS].searchValue(searchedValue);
		if (rows.getSize() == 0)std::cout << "No such value found in this table" << std::endl;
		else {

			for (int i = 0; i < rows.getSize(); i++) {

				data[index].removeRow(rows[i]);
			}
		}
	}

}

void CommandPannel::insertRow(ArrayOfTables& data, String tableName,myVector<String>values){
	int index = -1;
	for (int i = 0; i < data.getSize(); i++) {
		if (strcmp(data[i].getName().getCharArray(), tableName.getCharArray()) == 0) {
			index = i;
		}
	}
	if (index == -1)std::cout << "No table with that name" << std::endl;
	else {
		if (values.getSize() > data[index].getTable().getSize()) {
			int remaining = values.getSize() - data[index].getTable().getSize();
			for (int j = 0; j < remaining; j++) {
				data[index].addColumn();
			}
		}
		
		for (int i = 0; i < values.getSize(); i++) {
			Cell* temp = new Cell(values[i]);
			data[index].getTable()[i].pushNewCell(*temp);

		}
		data[index].resizeColumnsInTable();
	}
}

void CommandPannel::innerjoin(ArrayOfTables& data,String table1,int col1,String table2,int col2,String name){
	Table temp;
	int index1 = -1;
	int index2 = -1;
	for (int i = 0; i < data.getSize(); i++) {
		if (strcmp(data[i].getName().getCharArray(), table1.getCharArray()) == 0) {
			index1 = i;
		}
	}
	for (int i = 0; i < data.getSize(); i++) {
		if (strcmp(data[i].getName().getCharArray(), table2.getCharArray()) == 0) {
			index2 = i;
		}
	}
	if (index1 == -1||index2==-1)std::cout << "No table with that name" << std::endl;
	else {
		Column tempNew1(data[index1].getTable()[col1]);
		Column tempNew2(data[index2].getTable()[col2]);
		temp.addColumn(tempNew1);
		temp.addColumn(tempNew2);
		temp.resizeColumnsInTable();
		bool isNew = true;
		for (int i = 0; i < data.getSize(); i++) {
			if (strcmp(temp.getName().getCharArray(), data[i].getName().getCharArray()) == 0) {
				isNew = false;
			}
		}
		if (isNew) {
			temp.rename(name);
			data.addTable(temp);
			std::cout << "Table successfully added" << std::endl;
		}
		else {
			std::cout << "This name is already taken the table will not be added" << std::endl;
		}
	}

}

void CommandPannel::rename(ArrayOfTables& data,String oldName,String newName){
	int index1 = -1;
	bool isFreeName = true;
	for (int i = 0; i < data.getSize(); i++) {
		if (strcmp(data[i].getName().getCharArray(), oldName.getCharArray()) == 0) {
			index1 = i;
		}
	}
	for (int i = 0; i < data.getSize(); i++) {
		if (strcmp(data[i].getName().getCharArray(), newName.getCharArray()) == 0) {
			isFreeName = false;
		}
	}
	if (index1 == -1)std::cout << "No table with that name" << std::endl;
	else if (isFreeName == false)std::cout << "This name is taken " << std::endl;
	else{
		data[index1].rename(newName);
	
	}
}

void CommandPannel::count(ArrayOfTables& data,String tableName,int column,String value){
	int index1 = -1;
	int count = 0;
	bool isFreeName = true;
	for (int i = 0; i < data.getSize(); i++) {
		if (strcmp(data[i].getName().getCharArray(), tableName.getCharArray()) == 0) {
			index1 = i;
		}
	}
	if (index1 == -1)std::cout << "No table with that name" << std::endl;
	else {
		for (int i = 0; i < data[i].getTable()[column].getSize(); i++) {
			if (strcmp(value.getCharArray(), data[index1].getTable()[column][i].getString().getCharArray()) == 0) {
				count++;
			}
		}
		std::cout << "We found this value " << count << " times!" << std::endl;
	}
}

void CommandPannel::aggregate(ArrayOfTables& data,String tableName,int searchedColumn,String searchedValue,int targetColumn,String operation){
	int index1 = -1;
	int count = 0;
	bool isFreeName = true;
	for (int i = 0; i < data.getSize(); i++) {
		if (strcmp(data[i].getName().getCharArray(), tableName.getCharArray()) == 0) {
			index1 = i;
		}
	}
	if (index1 == -1)std::cout << "No table with that name" << std::endl;
	else {
		myVector<int> rows = data[index1].getTable()[searchedColumn].searchValue(searchedValue);
		if (rows.getSize() == 0)std::cout << "The value was not found" << std::endl;
		else {
			if (strcmp(data[index1].getTable()[targetColumn].getType().getCharArray(), "string") == 0)std::cout << "The target column do not contain numbers" << std::endl;
			else {
				if (strcmp(data[index1].getTable()[targetColumn].getType().getCharArray(), "int") == 0) {
					myVector<int>numbers;
					for (int i = 0; i < rows.getSize(); i++) {
						numbers.push_back(data[index1].getTable()[targetColumn][rows[i]].convertToInt());
					}
					if (operation == "sum") {
						int sum = 0;
						for (int i = 0; i < numbers.getSize(); i++) {
							sum += numbers[i];
						}
						std::cout << "The sum is: " << sum << std::endl;
					}
					if(operation=="product"){
						int product = 1;
						for (int i = 0; i < numbers.getSize(); i++) {
							product *= numbers[i];
						}
						std::cout << "The product is: " << product << std::endl;
					}
					if(operation=="maximum"){
						int max = 0;
						for (int i = 0; i < numbers.getSize(); i++) {
							if (max < numbers[i])max = numbers[i];
						}
						std::cout << "The product is: " << max << std::endl;
					}
					if(operation=="minimum"){
						int min =numbers[0];
						for (int i = 0; i < numbers.getSize(); i++) {
							if (min > numbers[i])min = numbers[i];
						}
						std::cout << "The product is: " << min << std::endl;
					}

				}
				else if (strcmp(data[index1].getTable()[targetColumn].getType().getCharArray(), "double") == 0) {
					myVector<double>numbers;
					for (int i = 0; i < rows.getSize(); i++) {
						numbers.push_back(data[index1].getTable()[targetColumn][rows[i]].convertToDouble());
					}
					if (operation == "sum") {
						double sum = 0;
						for (int i = 0; i < numbers.getSize(); i++) {
							sum += numbers[i];
						}
						std::cout << "The sum is: " << sum << std::endl;
					}
					if (operation == "product") {
						double product = 1;
						for (int i = 0; i < numbers.getSize(); i++) {
							product *= numbers[i];
						}
						std::cout << "The product is: " << product << std::endl;
					}
					if (operation == "maximum") {
						double max = 0;
						for (int i = 0; i < numbers.getSize(); i++) {
							if (max < numbers[i])max = numbers[i];
						}
						std::cout << "The product is: " << max << std::endl;
					}
					if (operation == "minimum") {
		
						double min = numbers[0];
						for (int i = 0; i < numbers.getSize(); i++) {
							if (min > numbers[i])min = numbers[i];
						}
						std::cout << "The product is: " << min << std::endl;
					}
				}
			}
		}
	}
	
}


void CommandPannel::startProgram() {

	ArrayOfTables data;
	while (true) {
		 String command;
		std::cout << "Type a command and press exit to exit and if command is insert write only the word" << std::endl;
		std::cin >> command;
		if (strcmp(command.getCharArray(), "help") == 0) {
			this->help();
		};
		
		if (strcmp(command.getCharArray(), "exit") == 0) {
			this->exit();
			break;
		};
		
		if (strcmp(command.getCharArray(), "import") == 0)  {
			
			String nameOfFile;
			std::cin >> nameOfFile;
			this->import(data, nameOfFile);
		}
		
		if (strcmp(command.getCharArray(), "showtables") == 0) {
			this->showtables(data);
		};
		
		if (strcmp(command.getCharArray(), "describe") == 0) {
			String name;
			std::cin >> name;
			this->describe(data, name);
		};
		
		if (strcmp(command.getCharArray(), "print") == 0) {
			String name;
			std::cin >> name;
			this->print(data, name);
		};
		
		if (strcmp(command.getCharArray(), "export") == 0) {
			String name;
			String fileName;
			std::cin >> name;
			std::cin >> fileName;
			this->exportTable(data, name, fileName);
		};
		
		if (strcmp(command.getCharArray(), "select") == 0) {
			int column;
			String value;
			String tableName;
			std::cin >> column;
			std::cin.ignore();
			std::cin >> value;
			std::cin >> tableName;
			this->selectValue(data,column,value,tableName);
		};
		
		if (strcmp(command.getCharArray(), "addcolumn") == 0) {
			String tableName;
			String columnName;
			String columnType;
			std::cin >> tableName;
			std::cin >> columnName;
			std::cin >> columnType;
			this->addColumn(data, tableName, columnName, columnType);
		};
		
		if (strcmp(command.getCharArray(), "update") == 0) {
			String tableName;
			int columnS;
			String searchedValue;
			int columnT;
			String targetValue;
			std::cin >> tableName;
			std::cin >> columnS;
			std::cin.ignore();
			std::cin >> searchedValue;
			std::cin >> columnT;
			std::cin.ignore();
			std::cin >> targetValue;
			update(data, tableName, columnS, searchedValue, columnT, targetValue);
		};
		
		if (strcmp(command.getCharArray(), "delete") == 0) {
			String tableName;
			int searchedColumn;
			String searchedValue;
			std::cin >> tableName;
			std::cin >> searchedColumn;
			std::cin.ignore();
			std::cin >> searchedValue;
			deleteRow(data, tableName, searchedColumn, searchedValue);
		};
		
		if (strcmp(command.getCharArray(), "insert") == 0) {
			String tableName;
			int cellCount;
			std::cout << "Please type the name of the table:" << std::endl;
			std::cin >> tableName;
			myVector<String> values;
			std::cout << "How many cells will this row have?" << std::endl;
			std::cin >> cellCount;
			std::cin.ignore();
			for (int i = 0; i < cellCount; i++) {
				String value;
				std::cin >> value;
				values.push_back(value);
			}
			this->insertRow(data, tableName, values);
		};
		
		if (strcmp(command.getCharArray(), "innerjoin") == 0) {
			String table1;
			int column1;
			String table2;
			int column2;
			std::cin >> table1;
			std::cin >> column1;
			std::cin.ignore();
			std::cin >> table2;
			
			std::cin >> column2;
			std::cin.ignore();
			std::cout << "How do you want your new table to be  called :" << std::endl;
			String nameofTable;
			std::cin >> nameofTable;
			this->innerjoin(data, table1, column1, table2, column2,nameofTable);
		};
		
		if (strcmp(command.getCharArray(), "rename") == 0) {
			String oldName;
			String newName;
			std::cin >> oldName;
			std::cin >> newName;
			this->rename(data, oldName, newName);
		};
		
		if (strcmp(command.getCharArray(), "count") == 0) {
			String tableName;
			int column;
			String value;
			std::cin >> tableName;
			std::cin >> column;
			std::cin.ignore();
			std::cin >> value;
			this->count(data, tableName, column, value);
		};
		
		if (strcmp(command.getCharArray(), "aggregate") == 0) {
			String  tableName;
			int searchedColumn;
			String searchedValue;
			int targetColumn;
			String operation;
			std::cin >> tableName;
			std::cin >> searchedColumn;
			std::cin.ignore();
			std::cin >> searchedValue;
			std::cin >> targetColumn;
			std::cin.ignore();
			std::cin >> operation;
			this->aggregate(data, tableName, searchedColumn, searchedValue, targetColumn, operation);

		};

	}
}
