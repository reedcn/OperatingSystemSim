pcb: kernel.o pcb.o schedule.o
	g++ -o kernel kernel.o pcb.o schedule.o
	
kernel.o: kernel.cpp pcb.h
	g++ -c kernel.cpp
	
pcb.o: pcb.cpp pcb.h
	g++ -c pcb.cpp
	
schedule.o: schedule.cpp schedule.h
	g++ -c schedule.cpp
	
clean:
	rm *.o kernel