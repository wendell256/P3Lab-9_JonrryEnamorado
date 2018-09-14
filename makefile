main:	main.o Civilizacion.o Player.o
		g++ main.o Civilizacion.o Player.o -o main
		rm *.o

main.o: main.cpp Civilizacion.h Player.h
		g++ -c main.cpp

Civilizacion.o:	Civilizacion.h
				g++ -c Civilizacion.cpp

Player.o: Player.h Civilizacion.h
			g++ -c Player.cpp

