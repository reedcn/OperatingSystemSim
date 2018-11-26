run: main.o kernel.o pcb.o schedule.o
	g++ -o run main.o kernel.o pcb.o schedule.o
	
main.o: main.cpp kernel.h
	g++ -c main.cpp
	
kernel.o: kernel.cpp kernel.h
	g++ -c kernel.cpp
	
pcb.o: pcb.cpp pcb.h
	g++ -c pcb.cpp
	
schedule.o: schedule.cpp schedule.h
	g++ -c schedule.cpp

	
clean:
	rm *.o run