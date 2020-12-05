main : main.cpp Aquarium.o Bestiole.o Milieu.o Comportements
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

#Comportements
Comportements: ComportementGregaire.o ComportementKamikaze.o ComportementPeureuse.o ComportementPrevoyante.o ComportementMultiple.o

ComportementGregaire.o : ComportementGregaire.cpp ComportementGregaire.h IComportement.h
	g++ -Wall -std=c++11  -c ComportementGregaire.cpp -I .

ComportementKamikaze.o : ComportementKamikaze.cpp ComportementKamikaze.h IComportement.h
	g++ -Wall -std=c++11  -c ComportementKamikaze.cpp -I .

ComportementPeureuse.o : ComportementPeureuse.cpp ComportementPeureuse.h IComportement.h
	g++ -Wall -std=c++11  -c ComportementPeureuse.cpp -I .

ComportementPrevoyante.o : ComportementPrevoyante.cpp ComportementPrevoyante.h IComportement.h
	g++ -Wall -std=c++11  -c ComportementPrevoyante.cpp -I .

ComportementMultiple.o : ComportementMultiple.cpp ComportementMultiple.h IComportement.h
	g++ -Wall -std=c++11  -c ComportementMultiple.cpp -I .



