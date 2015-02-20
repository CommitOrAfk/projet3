#Variables
EXEC = gestion
ARGS = -Wall -Wextra -pedantic

EXEC: date.o client.o compte.o test.o main.cpp
	g++ $(ARGS) $^ -o $(EXEC)
	
date.o: date.cpp date.h
	g++ $(ARGS) -c $*.cpp

client.o: client.cpp client.h
	g++ $(ARGS) -c $*.cpp

compte.o: compte.cpp compte.h date.o client.o
	g++ $(ARGS) -c $*.cpp

test.o: test.cpp test.h compte.o
	g++ $(ARGS) -c $*.cpp

MrProper:
	rm *.o
