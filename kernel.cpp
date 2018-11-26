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
			mem = s.getMemory();
			cout << "mem: " << mem;
			p.addNewProcess(1, getpid());
			pMem = p.readFile(fileName, getpid(), arrivalNo);
			int *allocMem = new int(mem);
			int *allocPMem = new int(pMem);
			//cout << "allocMem: " << *allocMem << "allocPMem: " <<  *allocPMem;
			if (*allocMem > *allocPMem) {
				cout << "Memory available, moving to ready queue...\n";
				p.updateProcess(getpid(), 2);
				cout << "State: " << p.getState(getpid());
				int usedMemory = mem - pMem;
				s.updateMem(usedMemory);

			} else {
				cout << "Not enough memory, moving process to waiting queue...\n";
				p.updateProcess(getpid(), 4);
			}

			p.outInfo();
			free(allocMem);
			free(allocPMem);
		}
		
		return getpid();
		

};