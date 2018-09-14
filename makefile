main:	main.o Civilizacion.o Player.o Aldeano.o Tropa.o Soldado.o Caballeria.o GuerreroEspecial.o
		g++ main.o Civilizacion.o Player.o Aldeano.o Tropa.o Soldado.o Caballeria.o GuerreroEspecial.o -o main
		rm *.o

main.o: main.cpp Civilizacion.h Player.h
		g++ -c main.cpp

Civilizacion.o:	Civilizacion.h
				g++ -c Civilizacion.cpp

Player.o: Player.h Civilizacion.h
			g++ -c Player.cpp

Aldeano.o:	Aldeano.h
			g++ -c Aldeano.cpp	

Tropa.o:	Tropa.h
			g++ -c Tropa.cpp

Soldado.o:	Soldado.h Tropa.h
			g++ -c Soldado.cpp

Caballeria.o:	Caballeria.h Tropa.h
				g++ -c Caballeria.cpp

GuerreroEspecial.o:	GuerreroEspecial.h Tropa.h
					g++ -c GuerreroEspecial.cpp