#Variables
EXEC = gestion
ARGS = -Wall -Wextra -pedantic

EXEC: date.o client.o compte.o test.o comptebloque.o main.cpp
	g++ $(ARGS) $^ -o $(EXEC)
	
date.o: date.cpp date.h
	g++ $(ARGS) -c $*.cpp

client.o: client.cpp client.h
	g++ $(ARGS) -c $*.cpp

compte.o: compte.cpp compte.h date.o client.o
	g++ $(ARGS) -c $*.cpp

test.o: test.cpp test.h compte.o
	g++ $(ARGS) -c $*.cpp

comptebloque.o: comptebloque.cpp comptebloque.h compte.o
	g++ $(ARGS) -c $*.cpp

clean:
	rm -rf *.o

mrproper:
	rm -rf $(EXEC)
	
tarball:
	@#On va chercher tout (*) dans le repertoire spécifié par -C (./)
	tar -zcvf $(ARCH) * -C ./