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


class Schedule {
	private:
		ProcessControlBlock p;
		std::queue<int> jobQueue;
		std::queue<int> readyQueue;
		std::queue<int> deviceQueue;
		int currentProcess;
		int quantum;
		
		int processState;
		int processId;
		int arrival;
		
		int totalMem;
		int usedMem;

	public:
		Schedule() {
			quantum = 0;
			currentProcess = 0;
			totalMem = 2048;
			usedMem = 0;
			
		}
		
		addQuantum(int q) {
			quantum = q;
		}
		
		getQueues();
		getArrivalNo(int pId);
		getMemory();
		updateMem(int usedMem);
		
		moveQueue(int pId, int qNum);
		printQueue(std::queue<int> q);
		
		roundRobinScheduler();
		dispatcher(int pId);
		
		outInfoSched();
		
			
};