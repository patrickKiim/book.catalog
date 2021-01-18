//menu.cpp

#include "menu.h"

bool menu::isDigits(const string &str){
	return all_of(str.begin(), str.end(), ::isdigit);
}

menu::menu(){}
menu::~menu(){}

vector<string> menu::getMain() const {
	return vMain;
}

vector<string> menu::getImport() const {
	return vImport;
}

vector<string> menu::getExport() const {
	return vExport;
}

vector<string> menu::getAdd() const {
	return vAdd;
}

vector<string> menu::getSearch() const{
	return vSearch;
}

vector<string> menu::getSubSearch() const{
	return vSubSearch;
}

vector<string> menu::getSort() const{
	return vSort;
}

vector<string> menu::getDeleteAll() const{
	return vDeleteAll;
}

int menu::userMenu(vector<string> m){
	cout << "----- Choose from following options by entering the number -----\n";
	for(int i = 1; i <= m.size(); i++){
		cout << "[" << i << "] " << m.at(i-1) << endl;
	}
	string sAns;
	cout<< "Enter your choice: " << endl;
	getline(cin, sAns);
	while (!isDigits(sAns) || stoi(sAns) > m.size() || stoi(sAns) <= 0){
		cout << "You must enter a number listed on the available options.\n";
		cout<< "Enter your choice: ";
		getline(cin, sAns);
	}
	int ans = 0;
	ans = stoi(sAns);

	//exit and main menu = 0;
	if(ans == m.size()){
		ans = 0;
	}
	return ans;
}