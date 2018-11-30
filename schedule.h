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
		int burst;

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
		
		getQuantum();
		getQueues();
		getMemory();
		updateMem(int usedMem);
		updateCurrentProcess(int pId) {
			currentProcess = pId;
		}
		
		enterJobQueue(int pId);
		enterReadyQueue(int pId);
		enterDeviceQueue(int pId);
		
		printQueue(std::queue<int> q);
		
		roundRobinScheduler();
		dispatcher(int pId, int currentProcessCycles);
		
		outInfoSched();
		
			
};