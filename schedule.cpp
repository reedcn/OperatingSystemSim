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
#include "schedule.h"
using namespace std;

int Schedule::printQueue(queue<int> q) {
	queue<int> que = q;
	
	while(!que.empty()) {
		cout << que.front();
		que.pop();
	}
	cout << "\n";
	return 0;
}

int Schedule::moveQueue(int pId) {
		if (processState == 1) {
			jobQueue.push(processId);
			cout << "Moving to job queue\n";
		} else if (processState == 2) {
			readyQueue.push(processId);
			cout << "Moving to ready queue\n";
		} else if (processState == 3) {
			deviceQueue.push(processId);
			cout << "Moving to device queue\n";
		} else {
			cout << "Burst finished, child process now exiting\n";
			exit(1);
		}
		return 0;
}

int Schedule::outInfoSched() {
	string processStateString = "";
	
	cout << "////////////////////////////////////////////////////////////////////" << "\n"
		<< "//Schedule Info" << "\n"
		<< "//Current Process: " << currentProcess << "\n"
		<< "//Quantum: " << quantum << "\n"
		<< "///////////////////////////////////////////////////////////////////" << "\n" << "\n";
		
	return 0;
}

int Schedule::roundRobinScheduler() {
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
	printQueue(readyQueue);
	//cout << "arrivalNo: " << arrival;
	for (i = 0; i < size; i++) {
		temp = readyQueue.front();
		readyProcesses[i] = temp;
		cout << readyProcesses[i];
		readyQueue.pop();
		arrivalOrder[i] = p.getArrivalNo(readyProcesses[i]);
		//cout << "arrival order: " << readyProcesses[i]  << ": "<< arrivalOrder[i] << "\n";
			if (arrival < minArrival) {
				minArrival = arrival;
				index = i;
			} 
	}
	cout << "ROUND ROBIN: " << minArrival;

	dispatcher(readyProcesses[index]);
	
	for (i = 0; i < size; i++) {
		temp = readyProcesses[i];
		readyQueue.push(temp);
	}

	return 0;
}

int Schedule::getQueues() {
	
	cout  << "***********************************" << "\n"
	<< "**JobQ: ";
	printQueue(jobQueue);
	cout << endl;
	cout << "**ReadyQ: ";
	printQueue(readyQueue);
	cout << endl;
	cout << "**DeviceQ: ";
	printQueue(deviceQueue);
	cout << "***********************************" << "\n";
	
	return 0;
}

int Schedule::dispatcher(int pId) {
	int burst; 
	p.updateProcess(3);
	burst = p.getCycles(pId);
	cout << "Burst was " << burst << "\n";
	burst -= quantum;
	cout << "Burst is now " << burst << "\n";
	p.updateCycles(burst);
		if (burst <= 0) {
			p.updateProcess(5);
			moveQueue(pId);
		}
		
	return 0;
}