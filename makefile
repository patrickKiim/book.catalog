#adapted from "Example: a makefile for Separate Compilation"
#www2.cs.sfu.ca/CourseCentral/135/tjd/makefileNotes.html

test: database.o bookRecord.o menu.o
	g++ -o test database.o bookRecord.o menu.o 

# only need to link if database.cpp has changed
database: database.cpp
	g++ -c database.cpp

# only compile if bookRecord.h or bookRecord.cpp has changed since last compile
bookRecord: bookRecord.h bookRecord.cpp
	g++ -c bookRecord.cpp

# only compile if menu.h or menu.cpp has changed since last compile
menu: menu.h menu.cpp
	g++ -c menu.cpp

clean:
	rm -f test database.o bookRecord.o menu.o

# Set the C++ compiler options:
#   -std=c++14 compiles using the C++14 standard (or at least as 
#    much as is implemented by the compiler, e.g. for g++ see
#    http://gcc.gnu.org/projects/cxx0x.html)
#   -Wall turns on all warnings
#   -Wextra turns on even more warnings
#   -Werror causes warnings to be errors 
#   -Wfatal-errors stops the compiler after the first error
#   -Wno-sign-compare turns off warnings for comparing signed and 
#    unsigned numbers
#   -Wnon-virtual-dtor warns about non-virtual destructors
#   -g puts debugging info into the executables (makes them larger)
CPPFLAGS = -std=c++14 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g
