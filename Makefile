main : main.cpp Comportements Capteurs Aquarium.o Bestiole.o Milieu.o 
	g++ -Wall -std=c++11 -o main main.cpp Bestiole.o Aquarium.o Milieu.o ComportementGregaire.o ComportementKamikaze.o ComportementPeureuse.o ComportementPrevoyante.o ComportementMultiple.o SimpleBestiole.o -I . -lX11 -lpthread

#Structure principale
Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

Clones.o : Clones.h Clones.cpp
	g++ -Wall -std=c++11 -c Clones.cpp -I .

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

#Capteurs
Capteurs : SimpleBestiole.o

SimpleBestiole.o : SimpleBestiole.cpp SimpleBestiole.h Bestiole.o
	g++ -Wall -std=c++11  -c SimpleBestiole.cpp -I .

