# Variables
EXEC = gestion
ARCH = projet4_groupe_alexander.tar.gz
# Il y a bien un -std= pour g++, mais la norme n'est pas c11 mais c++11!
# Ce qui donne tout son sens au -pedantic, Mea Culpa (Théo).
ARGS = -std=c++11 -Wall -Wextra -pedantic

EXEC: date.o client.o compte.o comptecourant.o livret.o comptebloque.o pel.o ecompte.o main.cpp
	g++ $(ARGS) $^ -o $(EXEC)
	
date.o: date.cpp date.h
	g++ $(ARGS) -c $*.cpp

compte.o: compte.cpp compte.h date.o
	g++ $(ARGS) -c $*.cpp

comptecourant.o: comptecourant.cpp comptecourant.h compte.o
	g++ $(ARGS) -c $*.cpp

comptebloque.o : comptebloque.cpp comptebloque.h compte.o
	g++ $(ARGS) -c $*.cpp
	
livret.o: livret.cpp livret.h compte.o
	g++ $(ARGS) -c $*.cpp

ecompte.o: ecompte.cpp ecompte.h compte.o
	g++ $(ARGS) -c $*.cpp

pel.o: pel.cpp pel.h compte.o
	g++ $(ARGS) -c $*.cpp

client.o: client.cpp client.h comptecourant.o livret.o comptebloque.o pel.o ecompte.o
	g++ $(ARGS) -c $*.cpp

clean:
	rm -rf *.o

mrproper:
	rm -rf $(EXEC)
	
tarball:
	@#On va chercher tout (*) dans le repertoire spécifié par -C (./)
	tar -zcvf $(ARCH) * -C ./
