
all:
	g++ src/insertionsort.cpp -o obj/insertion
	g++ src/selectionsort.cpp -o obj/selection

run-insertion: 
	./obj/insertion instancias-num/num.1000.1.in
	./obj/insertion instancias-num/num.1000.4.in
	./obj/insertion instancias-num/num.10000.1.in
	./obj/insertion instancias-num/num.10000.4.in
	./obj/insertion instancias-num/num.100000.1.in
	./obj/insertion instancias-num/num.100000.4.in
	echo >> resultados.txt

run-selection:
	./obj/selection instancias-num/num.1000.1.in
	./obj/selection instancias-num/num.1000.4.in
	./obj/selection instancias-num/num.10000.1.in
	./obj/selection instancias-num/num.10000.4.in
	./obj/selection instancias-num/num.100000.1.in
	./obj/selection instancias-num/num.100000.4.in
	echo >> resultados.txt
	
clean:
	rm ./obj/*
	rm resultados.txt

	