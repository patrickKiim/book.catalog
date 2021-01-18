//bookRecord.h

#ifndef BOOK_RECORD_H
#define BOOK_RECORD_H

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


class bookRecord{
private:
	string title;
	string author;
	string year;
	string bookType;
	string isbn = 0;
	string pages = 0;

	bool isDigits(const string &str);

	void checkYear();
	void checkBookType();
	void checkIsbn();
	void checkPages();
public:

	bookRecord(string nTitle, string nAuthor, string nYear, string nBookType, string nIsbn, string nPages);
	~bookRecord();

	string getTitle() const ;
	void setTitle(string nTitle);

	string getAuthor() const;
	void setAuthor(string nAuthor);

	string getYear() const;
	void setYear(string nYear);

	string getBookType() const;
	void setBookType(string nBookType);

	string getIsbn() const;
	void setIsbn(string nIsbn);

	string getPages() const ;
	void setPages(string nPages);
};//end of class bookrecord
#endif