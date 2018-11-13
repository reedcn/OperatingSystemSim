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
		std::queue<int> jobQueue;
		std::queue<int> readyQueue;
		std::queue<int> deviceQueue;
		int currentProcess;
		int arrival;
		int quantum;
		std::string name;

	public:
		ProcessControlBlock() {
			processState = 0;
			processId = 0;
			std::string programCounter = "None";
			q = "Job";
			name = ".exe";
		}
		addQuantum(int q) {
			quantum = q;
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
		
		moveQueue(int pId);
		printQueue(std::queue<int> q);
		
		roundRobinScheduler();
		
		dispatcher(int pId);
		
		getArrivalNo(int pId);
		getCycles(int pId);
		
		outInfo();
		
			
};