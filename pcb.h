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

#define SIZE 1000


class ProcessControlBlock {
	private:
		int processState;
		int processId;
		std::string *programCounter;
		int cycles;
		std::string q;
		int arrival;
		std::string name;

	public:
		ProcessControlBlock() {
			processState = 0;
			processId = 0;
			std::string programCounter = "None";
			q = "Job";
			name = ".exe";
		}

		addNewProcess(int pState, int pId) {
			processState = pState;
			processId = pId;
			
		}
		
		getArrivalNo(int pId);
		getCycles(int pId);
		getState(int pId);
		
		readFile(std::string fileName, int pId, int arrivalNo);
		tokenize(std::string tokens[], int row);
		
		updateProcess(int pid, int pState);
		
		updateCycles(int burst) {
			cycles = burst;
		}
		
		outInfo();
		
};