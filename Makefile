main.exe: main.o
	g++ -o main.exe main.o database.o

main.o: main.cpp
	g++ -Werror -std=c++11 -c main.cpp

console.o: database.cpp
	g++ -Werror -std=c++11 -c database.cpp