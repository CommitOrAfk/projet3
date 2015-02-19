#Makefile test Date


main.out: date.o client.o main.cpp
	g++ $^ -o main.out
	
date.o: date.cpp date.h
	g++ -c date.cpp

client.o: client.cpp client.h
	g++ -c client.cpp

MrProper:
	rm *.o
