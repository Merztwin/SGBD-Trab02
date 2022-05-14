ALL:	main

main:	main.o abm.o
		g++ main.o abm.o -o main

main.o:	main.cc abm.hh
		g++ -c main.cc

lista_polimorfica.o: abm.cc abm.hh
		g++ -c abm.cc

clean:
	rm -f *.o main