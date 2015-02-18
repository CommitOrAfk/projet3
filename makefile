#Makefile test Date


main.out: date.o main.cpp
	g++ $^ -o main.out
	
date.o: date.cpp date.h
	g++ -c date.cpp