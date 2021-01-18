#include "bookRecord.h"
#include "menu.h"

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


bool operator==(const bookRecord& a, const bookRecord& b){
	if (a.getTitle() != b.getTitle()){
		return false;
	}
	if (a.getAuthor() != b.getAuthor()){
		return false;
	}
	if (a.getYear() != b.getYear()){
		return false;
	}
	if (a.getBookType() != b.getBookType()){
		return false;
	}
		if (a.getIsbn() != b.getIsbn()){
		return false;
	}
	if (a.getPages() != b.getPages()){
		return false;
	}
	return true;
}

class dataBase{
private: 
	vector<bookRecord> library;
	vector<bookRecord> searchResults;

	bool isDigits(const string &str){
		return all_of(str.begin(), str.end(), ::isdigit);
	}

	//for random book method
	string randChoice(const vector<string>& v){
		//return random index
		int r = rand() % v.size();
		return v.at(r);
	}
	int randRange(int a, int b){
		return a + (rand() % (b - a + 1));
	}
public:

	dataBase(){}

	~dataBase(){}

	void importFile(){
		int count = 0;
		ifstream dataFile("import.txt");
		if (dataFile.fail()){
			cout << "unable to open file" << endl;
		} else {
			string line;
			string item;
			vector<string> vItem;
			//each line == 1 book
			while(getline(dataFile, line)){
				//adapted from splitting string with delimeter
				istringstream ss(line);
				while(getline(ss, item, '^')){ //delimter ^
					//store parameters of each book in vector
					vItem.push_back(item);
				}
				//initialize book using parameters
				bookRecord book(vItem[0], vItem[1], vItem[2], vItem[3], vItem[4],vItem[5]);
				library.push_back(book);
				vItem.clear();
				count++;
			}
		}
		dataFile.close();
		cout << "successfully imported (" << count << ") books from file.\n";
	}

	//adding random book to library for test purposes
	void addRandomBook(){
		string sCount;
		int count = 0;

		cout << "How many books would you like to add?: ";
		getline(cin, sCount);

		while(!isDigits(sCount) || stoi(sCount) < 0){
			cout << "Enter a numeric value greater than zero.\n";
			cout << "How many books would you like to add?: ";
			getline(cin, sCount);
		}
		count = stoi(sCount);

		vector<string> vTitle = {"Harry Potter and philospher's stone", "Chronicles of Narnia", "Alice In Wonderland", "Harry Potter and Half-blood Prince", "Cinderella", "Adventures of Finn"};
		string title = randChoice(vTitle);

		vector<string> vAuthor = {"Rowling", "Aandy", "Bharlie", "Canders", "Srump", "J.J. Tolkien"};
		string author = randChoice(vAuthor);

		string year = to_string(randRange(1850,2020));

		vector<string> vTypes = {"hardcover", "softcover", "digital"};

		for (int i = 0; i < count; i++){
			string title = randChoice(vTitle);
			string author = randChoice(vAuthor);
			string year = to_string(randRange(1850,2020));
			string bookType = randChoice(vTypes);
			 //13-digit num
			string isbn =  to_string(randRange(100000, 999999)) + to_string(randRange(1000000, 9999999));
			string page = to_string(randRange(10, 500));
			bookRecord book(title, author, year, bookType, isbn, page);
			library.push_back(book);
		}
		cout << "Successfully added (" << count << ") books\n";
	}

	void addBook(){
		cout << "Enter title: ";
		string title;
		getline(cin, title);
		
		cout << "Enter author: ";
		string author;
		getline(cin, author);

		cout << "Enter year published (YYYY): ";
		string year;
		getline(cin, year);

		cout << "Enter book type (hardcover, softcover, digital): ";
		string bookType;
		getline(cin, bookType);

		cout << "Enter ISBN: ";
		string isbn;
		getline(cin, isbn);

		cout << "Enter number of pages: ";
		string pages;
		getline(cin, pages);

		bookRecord book(title, author, year, bookType, isbn, pages);
		library.push_back(book);

		cout << book.getTitle() << " successfully added.\n";
	}

	void exportFile(){
		int count = 0;
		ofstream dataFile("export.txt");
		if (dataFile.fail()){
			cout << "unable to open file" << endl;
		} else {
			for(bookRecord book : library){
				dataFile << book.getTitle() << "^" << book.getAuthor() << "^" << book.getYear() << "^" 
				<< book.getBookType() << "^" << book.getIsbn() << "^" << book.getPages() << "^" << endl;
				count++;
			}
		}
		dataFile.close();
		cout << "successfully exported (" << count << ") books to file.\n";
	}

	//index from searchResult vector
	//need to find eleemnt in library n delete it
	void deleteBook(){
		if(searchResults.empty()){
			cout << "List is empty; cannot delete book.\n";
			return;
		}
		string sIndex;
		cout<< "Enter the number of book to delete: " << endl;
		getline(cin, sIndex);
		while (!isDigits(sIndex) || stoi(sIndex) > searchResults.size() || stoi(sIndex) <= 0){
			cout << "You must enter the number for the book you wish to delete.\n";
			cout<< "Enter your choice: " << endl;
			getline(cin, sIndex);
		}
		int index = 0;
		index = stoi(sIndex);
		//book number - 1 = index
		index--;
		string title = searchResults.at(index).getTitle();
		library.erase(remove_if(library.begin(), library.end(),[&](bookRecord a){
			bookRecord b = searchResults.at(index);
			return (a == b);
		}), library.end());
		searchResults.erase(searchResults.begin() + index);
		cout << title << " successfully deleted" << endl;
	}

	void deleteAll(){
		library.clear();
		resetSearch();
	}


	vector<bookRecord> getLibrary() const {
		return library;
	}
	
	vector<bookRecord> getSearchResults() const {
		return searchResults;
	}

	//show all info about a book
	void displayBook(const int& index,const vector<bookRecord>& books){
		cout << "Title:               " << books.at(index).getTitle() << endl;
		cout << "Author:              " << books.at(index).getAuthor() << endl;
		cout << "Year of Publication: " << books.at(index).getYear() << endl;
		cout << "Book Type:           " << books.at(index).getBookType() << endl;
		cout << "ISBN:                " << books.at(index).getIsbn() << endl;
		cout << "Page number:         " << books.at(index).getPages() << endl;

	}

	//display all books in vector
	void displayAll(const vector<bookRecord>& books){
		for (int i = 0; i < books.size(); i++){
			cout << "--------- Book " << i+1 << " ----------\n";
			displayBook(i, books);
			cout << endl;
		}
	}

	// 1 == organize by title
	// 2 == organize by title (reverse)
	// 3 == organize by author
	// 4 == organize by author (reverse)
	// 5 == organize by date Pubished
	// 6 == organize by date Pubished (reverse)
	// 7 == organize by bookType
	// 8 == organize by bookType (reverse)
	// 9 == organize by Isbn
	// 10 == organize by Isbn (reverse)
	// 11 == organize by number of pages
	// 12 == organize by number of pages (reverse)
	void organize(int commandNum){

		bool sortReverseOrder = false;

		//reverse order for even commands
		if ((commandNum % 2) == 0){
			sortReverseOrder = true;
			commandNum = commandNum / 2;
		} else {
			commandNum = (commandNum / 2) + 1;
		}

		//modified
		// 1 ==  by title
		// 2 ==  by author
		// 3 ==  by date Pubished 
		// 4 ==  by bookType
		// 5 ==  by Isbn
		// 6 ==  by number of pages

		sort(searchResults.begin(), searchResults.end(), [&](const bookRecord& a, const bookRecord& b){
			if (commandNum == 1){ //sort by title
				return a.getTitle() < b.getTitle();

			} else if (commandNum == 2){ //sort author
				return a.getAuthor() < b.getAuthor();
				
			} else if (commandNum == 3){ //sort by year
				return a.getYear() < b.getYear();
				
			} else if (commandNum == 4){ //sort by book type
				return a.getBookType() < b.getBookType();
				
			} else if (commandNum == 5){ //sort by ISBN
				return a.getIsbn() < b.getTitle();
				
			} else if (commandNum == 6){ //sort reverse alphabetical
				return a.getPages() < b.getPages();

			} else {
				cout << "commandNum error\n"; //shoudn't reach here
				return false;
			}
		});

		if (sortReverseOrder){ //reverse order
			reverse(searchResults.begin(), searchResults.end());
		}
		cout << "sort complete" << endl;
		displayAll(searchResults);
	}

	//copy library to search vector (prepping for searching)
	void resetSearch(){
		searchResults = library;
	}

	//commandNum
	// 1 == search by title
	// 2 == search by author
	// 3 == search by date Pubished (range)
	// 4 == search by bookType
	// 5 == search by Isbn
	// 6 == search by number of pages
	void search(const int& commandNum){
		string keyword = "";
		int lowerBound = 0;
		int upperBound = 0;

		if(commandNum != 3 && commandNum != 6){ //1,2,4,5 is keyword search
			cout << "Enter your search: ";
			getline(cin, keyword);
			//turn keyword into lowercase
			transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
		} else { //3,6 is range search
			string sLowerBound;
			cout << "Enter lower bound for range: ";
			getline(cin, sLowerBound);
			string sUpperBound;
			cout << "Enter upper bound for range: ";
			getline(cin, sUpperBound);

			while (!isDigits(sLowerBound) || !isDigits(sUpperBound) || (stoi(sLowerBound) > stoi(sUpperBound))){
				cout << "Error. Bounds must be integers and lower bound cannot be greater than upper bound.\n Please reenter it.\n";
				
				cout << "Enter lower bound for range: ";
				getline(cin, sLowerBound);
				
				cout << "Enter upper bound for range: ";
				getline(cin, sUpperBound);
			}
			lowerBound = stoi(sLowerBound);
			upperBound = stoi(sUpperBound);
		}
		cout << endl;
		cout << "searching..." << endl;
		searchEngine(keyword, lowerBound, upperBound, commandNum);

		cout << "Your search returned (" << searchResults.size() << ") results." << endl;
		displayAll(searchResults);
	}

	void searchEngine(string keyword, const int& lowerBound, const int&upperBound, const int& commandNum){

		//turn keyword into lowercase
		transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);

		//using remove_if erase idiom 
		//remove all results that doesn't contain keyword
		searchResults.erase(remove_if(searchResults.begin(), searchResults.end(), [&](bookRecord book){
			string s;
			int i = 0;

			if (commandNum == 1){ //search by title
				s = book.getTitle();
				//decapitalize title for comparison
				transform(s.begin(), s.end(), s.begin(), ::tolower);
				//returns true if keyword cannot be found in title
				//if true, book is deleted from search vector
				return (s.find(keyword) == string::npos);

			} else if (commandNum == 2){ //search by author
				s = book.getAuthor();
				transform(s.begin(), s.end(), s.begin(), ::tolower);
				return (s.find(keyword) == string::npos);

			} else if (commandNum == 3){ //search by range of year
				//covert string of year to int
				i = stoi(book.getYear());	
				//year not deleted if i is between the range 
				return (!(lowerBound <= i && i <= upperBound));

			} else if (commandNum == 4){ //search by bookType
				s = book.getBookType();
				transform(s.begin(), s.end(), s.begin(), ::tolower);
				return (s.find(keyword) == string::npos);

			} else if (commandNum == 5){ //search by isbn
				s = book.getAuthor();
				transform(s.begin(), s.end(), s.begin(), ::tolower);
				return (s.find(keyword) == string::npos);

			} else if (commandNum == 6){ //search byrange of page
				i = stoi(book.getPages());	
				return (!(lowerBound <= i && i <= upperBound));
			} else {
				cout << "error: invalid commandNum"<< endl; //shouldn't reach here
				return false;
			}

		}), searchResults.end());
	}
};

int main(){
	srand(time(NULL));
	dataBase a;
	menu m;


	bool exit = false;
	int choice = 0;

	while(!exit){
		cout << "************        MainMenu        ************" << endl;
		cout << "Number of books in database: " << a.getLibrary().size() << endl;
		choice = m.userMenu(m.getMain());

		//import file
		if (choice == 1){ 
			choice = m.userMenu(m.getImport());
			//replace entire database
			if (choice == 1){ 
				a.deleteAll();
				a.importFile();
			//add on existing datavase
			} else if (choice == 2){ 
				a.importFile();
			}
		//export file
		} else if (choice == 2){ 
			choice = m.userMenu(m.getExport());
			//export library to file
			if (choice == 1){
				a.exportFile();
			}
		//add book
		} else if (choice == 3){
			choice=m.userMenu(m.getAdd());
			//add via manual entry
			if (choice == 1){
				a.addBook();
			//add random books
			} else if (choice == 2){
				a.addRandomBook();
			}
		//search
		} else if (choice == 4){
			a.resetSearch();
			choice = m.userMenu(m.getSearch());
			//if not exiting
			if (choice != 0){
				a.search(choice);
			}
			//while not returning to main menu
			while(choice != 0){
				choice = m.userMenu(m.getSubSearch());
				//refine search
				if(choice == 1){
					choice = m.userMenu(m.getSearch());
					//if not exiting
					if (choice != 0){
						a.search(choice);
					}
				//sort list
				} else if (choice == 2){
					choice = m.userMenu(m.getSort());
					//if not exiting
					if (choice != 0){
						a.organize(choice);
					}
				//delete book
				} else if (choice == 3){
					a.deleteBook();
				}
			}
		//display all
		} else if (choice == 5){
			a.resetSearch();
			a.displayAll(a.getSearchResults());
			//while not returning to main menu
			while(choice != 0){
				choice = m.userMenu(m.getSubSearch());
				//refine search
				if(choice == 1){
					choice = m.userMenu(m.getSearch());
					//if not exiting
					if (choice != 0){
						a.search(choice);
					}
				//sort list
				} else if (choice == 2){
					choice = m.userMenu(m.getSort());
					//if not exiting
					if (choice != 0){
						a.organize(choice);
					}
				//delete book
				} else if (choice == 3){
					a.deleteBook();
				}
			}
		} else if (choice == 6){
			choice = m.userMenu(m.getDeleteAll());
			if (choice == 1){
				a.deleteAll();
			}
		} else if (choice == 0){
			exit = true;
		} else {
			cout << "error: invalid choice\n"; // shouldn't reach here
		}
	}
}









