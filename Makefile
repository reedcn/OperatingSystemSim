pcb: kernel.o pcb.o 
	g++ -o kernel kernel.o pcb.o
	
kernel.o: kernel.cpp pcb.h
	g++ -c kernel.cpp
	
pcb.o: pcb.cpp pcb.h
	g++ -c pcb.cpp
	
clean:
	rm *.o kernel