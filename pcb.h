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

//#include "pcb.h"
//#include "schedule.h"


class ProcessControlBlock {
	private:
		//Schedule s;
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

		addNewProcess(int pState, int pId,int c, int arrivalNo, std::string nameProcess) {
			processState = pState;
			processId = pId;
			cycles = c;
			arrival = arrivalNo;
			name = nameProcess;
			
		}
		updateProcess(int pState) {
			processState = pState;
		}
		
		updateCycles(int burst) {
			cycles = burst;
		}
		
		getArrivalNo(int pId);
		getCycles(int pId);
		
		outInfo();
		
			
};