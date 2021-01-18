Full name: Patrick Kim
SFU student #: 301415276


Compilation Instructions
------------------------

Ensure following files are in the same folder:

makefile (supplied)
bookRecord.h
bookRecord.cpp
menu.h
menu.cpp
cmpt_error.h
cmpt_trace.h
database.cpp
import.txt
export.txt

Using supplied makefile in the folder, enter commands:

make test
./ test

Running Instructions
--------------------


GENERAL INSTRUCTIONS:
Running the program will construct a database with (0) books.
The program will prompt you to enter a number to select an option on the given menu.

Ex.
---------------------------------------------------------------------------------
************        MainMenu        ************
Number of books in database: 23
----- Choose from following options by entering the number -----
[1] Import from file
[2] Export to file
[3] Add book
[4] Search
[5] Display all books
[6] Delete all books
[7] Exit
Enter your choice: 
--------------------------------------------------------------------------------

To select "import from file", type "1". 
To exit the program, type "7" in main menu. 

*important* The program has further menus and user prompts. Follow the prompts given on the screen at all times.

IMPORTING FROM FILE:
The program imports from a textfile called "import.txt". 
Text file format is a line per book, with parameters separated by "^" as field separator

Ex. 
Harry Potter and Half-blood Prince^Rowling^1959^digital^4178526053552^115^

This line in the text file imports the following book.
Title: Harry Potter and Half-Blood Prince
Author: Rowling
Year: 1959
Book type: Digital
ISBN: 4178526053552
Pages:115

*warning* = books with "^" characters cannot be imported

EXPORTING FROM FILE:
Same as importing from file, except it exports to a textfile called "export.txt". 

DELETING A BOOK:
User can select to delete a specific book after displaying a list of books, either by displaying all contents or after a search. 
To delete, select the option to delete a book, followed by the book number on the list above.

Other features are self-explanatory. Please follow the prompts given on the screen. 

Key Features
------------

MainMenu displays how many books are stored in the database.

ISBN can be 10 or 13 digits. If it is 10 digits, you just have to include three 0's at the front.
Ex. 3928519314 -> 0003928519314 

Search by title, author, booktype, and booktype are "keyword" searches.
Partially entering the word will return all results that contain that word.
Ex. Typing in "Har" will return both books "Harry Potter and Philospher's Stone" and "Harry Potter and Half-Blood Prince"

Search by year and pages are a "range" search.
User inputs a lower and upper bound, and the program returns all books that satisfy the given range.
Ex. Typing in 1890 and 1920 as lower and upper bounds for year search will return all books published between 1890 and 1920.

Sorting has 12 different options. Follow the user prompt to select one of them. 
User can select to sort after displaying a list of books, either by displaying all contents or after a search. 

There is an experimental feature to add random books to the database.
It is under "Add books" -> "(Developer mode) Add random books".


Bugs and Limitations
--------------------

Importing and Exporting can only happen with specifically named files.
It will only work if the entire textfile is error-free.
*warning* = books with "^" characters cannot be imported or exported

Author name should only be last name.
If user enters "Patrick Kim", it will treat it as a single name.

Books can have no title or author. This is to accommodate certain books without
known authors or titles.

All People, Websites, and Sources of Help
-----------------------------------------

CMPT 135 lectures
www2.cs.sfu.ca
stackoverflow.com
cplusplus.com
codeproject.com