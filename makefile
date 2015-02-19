#Variables
EXEC = gestion
ARGS = -Wall -Wextra -pedantic
ARCH = projet3_groupe_alexander.tar.gz

EXEC: date.o client.o compte.o main.cpp
	g++ $(ARGS) $^ -o $(EXEC)
	
date.o: date.cpp date.h
	g++ $(ARGS) -c $*.cpp

client.o: client.cpp client.h
	g++ $(ARGS) -c $*.cpp

compte.o: compte.cpp compte.h date.o client.o
	g++ $(ARGS) -c $*.cpp

clean:
	rm -rf *.o

mrproper:
	rm -rf $(EXEC)
	
tarball:
	@#On va chercher tout (*) dans le repertoire spécifié par -C (./)
	tar -zcvf $(ARCH) * -C ./