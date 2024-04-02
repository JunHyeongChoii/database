main.exe: main.o
	g++ -o main.exe main.o database.o in_variable.o

main.o: main.cpp
	g++ -Werror -std=c++11 -c main.cpp

database.o: database.cpp
	g++ -Werror -std=c++11 -c database.cpp

in_variabel.o: in_variabel.cpp
	g++ -Werror -std=c++11 -c in_variabel.cpp