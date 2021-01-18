//bookRecord.cpp
#include "bookRecord.h"


bool bookRecord::isDigits(const string &str){
	return all_of(str.begin(), str.end(), ::isdigit);
}

void bookRecord::checkYear(){
	while (year.length() != 4 || !isDigits(year)){
		cout << "Invalid year of publication for " << title << ".\nIt should be a 4 digit number in a format of YYYY.\nPlease reenter it.\n";
		getline(cin, year);
	}
}

void bookRecord::checkBookType(){
	while (bookType != "hardcover" && bookType != "softcover" && bookType != "digital"){
		cout << "Invalid book type for " << title << ".\nIt should be either 'hardcover', 'softcover', or 'digital'.\nPlease reenter it.\n";
		getline(cin, bookType);
	}
}

void bookRecord::checkIsbn(){
	while (isbn.length() != 13 || !isDigits(isbn)){
		cout << "Invalid ISBN for " << title << ".\nIf it is a 10 digit ISBN, you should enter it with 000 at the front. (ex. 000##########)\nPlease reenter it.\n";
		getline(cin, isbn);
	}
}

void bookRecord::checkPages(){
	while (!isDigits(pages) || stoi(pages) <= 0 ){
		cout << "Invalid page number for " << title << ".\n It needs to be bigger than 0.\n Please reenter it.\n";
		getline(cin, pages);
	}
}

bookRecord::bookRecord(string nTitle, string nAuthor, string nYear, string nBookType, string nIsbn, string nPages)
: title(nTitle), author(nAuthor), year(nYear),bookType(nBookType), isbn(nIsbn), pages(nPages)
{
	checkYear();
	checkBookType();
	checkIsbn();
	checkPages();
}

bookRecord::~bookRecord(){}

string bookRecord::getTitle() const {
	return title;
}

void bookRecord::setTitle(string nTitle){
	title = nTitle;
}

string bookRecord::getAuthor() const {
	return author;
}

void bookRecord::setAuthor(string nAuthor){
	author = nAuthor;
}

string bookRecord::getYear() const {
	return year;
}

void bookRecord::setYear(string nYear){
	year = nYear;
	checkYear();
}

string bookRecord::getBookType() const {
	return bookType;
}

void bookRecord::setBookType(string nBookType) {
	bookType = nBookType;
	checkBookType();
}

string bookRecord::getIsbn() const {
	return isbn;
}

void bookRecord::setIsbn(string nIsbn) {
	isbn = nIsbn;
	checkIsbn();
}

string bookRecord::getPages() const {
	return pages;
}

void bookRecord::setPages(string nPages){
	pages = nPages;
	checkPages();
}