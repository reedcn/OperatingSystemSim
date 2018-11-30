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
#include "kernel.h"

using namespace std;

int Schedule::printQueue(queue<int> q) {
	queue<int> que = q;
	
	while(!que.empty()) {
		cout << que.front() << " ";
		que.pop();
	}
	cout << "\n";
	return 0;
}

int Schedule::enterJobQueue(int pId) {
		jobQueue.push(pId);
		return 0;
}

int Schedule::enterReadyQueue(int pId) {
		readyQueue.push(pId);
		return 0;
}

int Schedule::enterDeviceQueue(int pId) {
		deviceQueue.push(pId);
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
int selectedProcess = 0;
			
selectedProcess = readyQueue.front();
cout << "Process selected: " << readyQueue.front() << endl;
	return selectedProcess;
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

int Schedule::dispatcher(int pId, int currentProcessCycles) {
	updateCurrentProcess(pId);
	outInfoSched();
	burst = currentProcessCycles;
	p.updateProcess(pId,3);
	cout << "Burst was " << burst << "\n";
	burst -= getQuantum();
	//cout << "quantum is now: " << quantum;
	cout << "Burst is now " << burst << "\n";
	p.updateCycles(burst);
		if (burst <= 0) {
			p.updateProcess(pId, 5);
		}
		
	return 0;
}

int Schedule::getMemory() {
	return totalMem;
}

int Schedule::updateMem(int usedMemory) {
	totalMem = usedMemory;
	return 0;
}


int Schedule::getQuantum() {
	return quantum;
}