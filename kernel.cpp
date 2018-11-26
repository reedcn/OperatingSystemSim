/*Christine Reed
CMSC 312
Operating System Simulator*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/wait.h>
#include <unistd.h>
#include <queue>
#include <fstream>

#include "pcb.h"
#include "schedule.h"
#include "kernel.h"

using namespace std;


int Kernel::createNewProcess(string fileName, int arrivalNo) {
	pid_t pid = fork();

		if ( pid < 0 ) {
			printf("Fork failed.\n");
			exit(0);
		} else if ( pid > 0 ) {

			do {
				wpid = wait(&status); // wpid
			} while (!WIFEXITED(status));
			
			cout << "\n Exit Status: " << status;
		} else {
			s.enterJobQueue(getpid());
			mem = s.getMemory();
			cout << "mem: " << mem;
			p.addNewProcess(1, getpid());
			pMem = p.readFile(fileName, getpid(), arrivalNo);
			int *allocMem = new int(mem);
			int *allocPMem = new int(pMem);
			//cout << "allocMem: " << *allocMem << "allocPMem: " <<  *allocPMem;
			if (*allocMem > *allocPMem) {
				cout << "Memory available...\n";
				p.updateProcess(getpid(), 2);
				cout << "State: " << p.getState(getpid());
				if (p.getState(getpid()) == 2) {
						s.enterReadyQueue(getpid());
					cout << "Moving to ready queue\n";
				}
				int usedMemory = mem - pMem;
				s.updateMem(usedMemory);

			} else {
				cout << "Not enough memory, moving process to waiting queue...\n";
				p.updateProcess(getpid(), 4);
				s.enterDeviceQueue(getpid());
			}

			p.outInfo();
			s.getQueues();
			free(allocMem);
			free(allocPMem);
		}
		
		return getpid();
		

};