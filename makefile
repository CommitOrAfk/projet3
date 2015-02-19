#Makefile test Date


main.out: date.o client.o compte.o main.cpp
	g++ $^ -o main.out
	
date.o: date.cpp date.h
	g++ -c date.cpp

client.o: client.cpp client.h
	g++ -c client.cpp

compte.o: compte.cpp compte.h
	g++ -c compte.cpp

MrProper:
	rm *.o
