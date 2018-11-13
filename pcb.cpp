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

#include "pcb.h"
using namespace std;

int ProcessControlBlock::printQueue(queue<int> q) {
	queue<int> que = q;
	
	while(!que.empty()) {
		cout << que.front();
		que.pop();
	}
	cout << "\n";
	return 0;
}

int ProcessControlBlock::moveQueue(int pId) {
		if (processState == 1) {
			jobQueue.push(processId);
		} else if (processState == 2) {
			readyQueue.push(processId);
		} else if (processState == 3) {
			deviceQueue.push(processId);
		} else {
			cout << "Burst finished, child process now exiting\n";
			exit(1);
		}
		return 0;
}

int ProcessControlBlock::outInfo() {
	string processStateString = "";
	
	if (processState == 1) {
		processStateString = "New";
	} else if (processState == 2) {
		processStateString = "Ready";
	} else if (processState == 3) {
		processStateString = "Running";
	} else if (processState == 4) {
		processStateString = "Waiting";
	} else {
		processStateString = "Terminated";
	}
	
	cout << "PCB Info" << "\n"
		<< "Process State: " << processStateString << "\n"
		<< "Process ID: " << processId << "\n"
		<< "Location of next instruction: " << programCounter << "\n"
		<< "Cycles/Burst: " << cycles << "\n"
		<< "Current Queue: " << q << "\n"
		<< "Arrival Time: " << arrival << "\n"
		<< "Quantum q: " << quantum << "\n"
		<< "Process name: " << name << "\n";
		
	cout << "JobQ: ";
	printQueue(jobQueue);
	cout << endl;
	cout << "ReadyQ: ";
	printQueue(readyQueue);
	cout << endl;
	cout << "DeviceQ: ";
	printQueue(deviceQueue);
	cout << endl;	
	return 0;
}

int ProcessControlBlock::roundRobinScheduler() {
	int i;
	int size;
	size = readyQueue.size();
	int readyProcesses[size];
	int burstTimes[size];
	int arrivalOrder[100];
	int temp;
	int minArrival = 1;
	int index;
	cout << "Q: ";
	//printQueue(readyQueue);
	//cout << "arrivalNo: " << arrival;
	for (i = 0; i < size; i++) {
		temp = readyQueue.front();
		readyProcesses[i] = temp;
		cout << readyProcesses[i];
		readyQueue.pop();
		arrivalOrder[i] = getArrivalNo(readyProcesses[i]);
		//cout << "arrival order: " << readyProcesses[i]  << ": "<< arrivalOrder[i] << "\n";
			if (arrival < minArrival) {
				minArrival = arrival;
				index = i;
			} 
	}
	//cout << "mina: " << minArrival;

	dispatcher(readyProcesses[index]);
	
	for (i = 0; i < size; i++) {
		temp = readyProcesses[i];
		readyQueue.push(temp);
	}

	return 0;
}

int ProcessControlBlock::getCycles(int pId) {
	return cycles;
}

int ProcessControlBlock::getArrivalNo(int pId) {
	if (pId == processId) {
		return arrival;
	}
	return 0;
}

int ProcessControlBlock::dispatcher(int pId) {
	int burst; 
	updateProcess(3);
	burst = getCycles(pId);
	cout << "Burst was " << burst << "\n";
	burst -= quantum;
	cout << "Burst is now " << burst << "\n";
	updateCycles(burst);
		if (burst <= 0) {
			updateProcess(5);
			moveQueue(pId);
		}
		
	return 0;
}