//menu.h

#ifndef MENU_H
#define MENU_H

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <iostream>
#include "cmpt_error.h"
#include <string>

using namespace std;

class menu{
private:
	vector<string> vMain = {"Import from file", "Export to file", "Add book", "Search", "Display all books", "Delete all books", "Exit"};
	vector<string> vImport = {"Replace entire database", "Add to existing database", "Main menu"};
	vector<string> vExport = {"Export entire database","Main menu"};
	vector<string> vAdd = {"Add via manual entry", "(Developer mode) Add random books", "Main menu"};
	vector<string> vSearch = {"By title", "By author", "By year of publication", "By book type", "By ISBN", "By page number", "Main menu"};
	vector<string> vSubSearch = {"Refine search", "Sort list", "Delete book", "Main Menu"};
	vector<string> vSort = {"By title (A-Z)", "By title (Z-A)", "By author (A-Z)", "By author (Z-A)", "By year of publication (ascending)", "By year of publication (descending)",
	"By book type (A-Z)", "By book type (Z-A)",  "By ISBN (ascending)", "By ISBN(descending)",  "By number of pages (ascending)", "By number of pages (descending)", "Main Menu"};
	vector<string> vDeleteAll = {"Confirm deleting all books", "Main Menu"};

	bool isDigits(const string &str);
public:
	menu();
	~menu();

	vector<string> getMain() const;

	vector<string> getImport() const;

	vector<string> getExport() const;

	vector<string> getAdd() const ;

	vector<string> getSearch() const;

	vector<string> getSubSearch() const;

	vector<string> getSort() const;

	vector<string> getDeleteAll() const;
	
	int userMenu(vector<string> m);
};
#endif