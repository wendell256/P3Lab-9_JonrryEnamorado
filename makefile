main:	main.o Civilizacion.o Player.o Aldeano.o Tropa.o Soldado.o Caballeria.o GuerreroEspecial.o Edificio.o Casa.o Cuartel.o Castillo.o
		g++ main.o Civilizacion.o Player.o Aldeano.o Tropa.o Soldado.o Caballeria.o GuerreroEspecial.o Edificio.o Casa.o Cuartel.o Castillo.o -o main
		rm *.o

main.o: main.cpp Civilizacion.h Player.h
		g++ -c main.cpp

Civilizacion.o:	Civilizacion.h Caballeria.h Cuartel.h Soldado.h Casa.h Castillo.h GuerreroEspecial.h Aldeano.h
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

Edificio.o:	Edificio.h
			g++ -c Edificio.cpp

Casa.o:	Casa.h Edificio.h
		g++ -c Casa.cpp

Cuartel.o:	Cuartel.h Edificio.h
		g++ -c Cuartel.cpp

Castillo.o:	Castillo.h Edificio.h
		g++ -c Castillo.cpp