testCambio: monedas.cpp
	g++ monedas.cpp -o testCambio
run: testCambio
	./testCambio
clean:
	rm -r *.o *.gch bin
