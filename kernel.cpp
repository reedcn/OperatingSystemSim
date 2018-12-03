/*Christine Reed
CMSC 312
Operating System Simulator

File: kernel.cpp
Purpose:  Create new process and handle essential OS functions*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/wait.h>
#include <unistd.h>
#include <queue>
#include <fstream>
#include <pthread.h>

#include "pcb.h"
#include "schedule.h"
#include "kernel.h"

using namespace std;

int Kernel::createNewProcess(string fileName, int q) {
	// Fork the function to create a new process to handle the job file
	pid_t pid = fork();

		if ( pid < 0 ) {
			printf("Fork failed.\n");
			exit(0);
		} else if ( pid > 0 ) { // Parent process
				
			do {
				wpid = wait(&status); // wpid
			} while (!WIFEXITED(status));
			
			cout << "\n Exit Status: " << status;
		} else { // Child function
			s.addQuantum(q);
			s.enterJobQueue(getpid());
			
			// Add process to PCB and begin memory check
			mem = s.getMemory();
			p.addNewProcess(1, getpid());
			pMem = p.readFile(fileName, getpid(), 1, q);

			// Pointers to allocate memory size
			int *allocMem = new int(mem);
			int *allocPMem = new int(pMem);
			
			// If the total memory is more than the memory needed for the process
			if (*allocMem > *allocPMem) {
				cout << "Memory available...\n";
				
				// Set process state to Ready
				p.updateProcess(getpid(), 2);
				if (p.getState(getpid()) == 2) {
					// If Ready, move to ReadyQueue
					s.enterReadyQueue(getpid());
					cout << "Moving to ready queue\n";
				}
				// Subtract process memory from total memory and set as the new memory available
				int usedMemory = mem - pMem;
				s.updateMem(usedMemory);
				
				// Round robin scheduler
				cout << "Starting round robin scheduler..\n" << endl;
				s.getQueues();
				current = s.roundRobinScheduler();
				//if (current == getpid()) {
					// Get cycles/burst of process selected by scheduler
					currentProcessCycles = p.getCycles(current);
				//}
				// Dispatcher
				currentProcessCycles = s.dispatcher(current, currentProcessCycles);
				p.readFile(fileName, getpid(), 2, s.getInstruct());

			} else {
				cout << "Not enough memory, moving process to waiting queue...\n";
				// Move to Waiting state and enter Device Queue
				p.updateProcess(getpid(), 4);
				s.enterDeviceQueue(getpid());
				s.getQueues();
			}

			// Delete pointers to free memory
			free(allocMem);
			free(allocPMem);
		}
		
		return getpid();
		

};
