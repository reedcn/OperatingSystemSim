/*Christine Reed
CMSC 312
Operating System Simulator

File: schedule.h
Purpose:  Scheduler and schedule functions */

#include <iostream>
#include <stdio.h>
#include <string>
#include <bits/stdc++.h>
#include <unistd.h>
#include <unistd.h>
#include <queue>

#include "pcb.h"
#include "schedule.h"
#include "kernel.h"

using namespace std;

// Print specified queue
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

// Print out all Scheduler info
int Schedule::outInfoSched() {
	string processStateString = "";
	
	cout << "////////////////////////////////////////////////////////////////////" << "\n"
		<< "//Schedule Info" << "\n"
		<< "//Current Process: " << currentProcess << "\n"
		<< "//Quantum: " << quantum << "\n"
		<< "///////////////////////////////////////////////////////////////////" << "\n" << "\n";
		
	return 0;
}

// Round Robin Scheduler
int Schedule::roundRobinScheduler() {
int selectedProcess = 0;
			
selectedProcess = readyQueue.front();
cout << "Process selected by the round robin scheduler is: " << readyQueue.front() << endl;
	return selectedProcess;
}

// Print out all queues
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

// Dispatcher
int Schedule::dispatcher(int pId, int currentProcessCycles) {
	updateCurrentProcess(pId);
	outInfoSched();
	burst = currentProcessCycles;
	// Set process to Running
	p.updateProcess(pId,3);
	cout << "Burst was " << burst << "\n";
	// If quantum is greater than the burst time left, find amount of instructions to perform until burst reaches 0
	if (burst < getQuantum()) {
		instruct = burst;
		updateInstruct(instruct);
	} else {
		instruct = getQuantum();
	}
	// Subtract quantum from burst
	burst -= getQuantum();
	
	// Process is finished (burst = 0)
	if (burst <= 0) {
			cout << "Process cycles are complete, terminating process..." << endl;
			// Set process to Terminated
			p.updateProcess(pId, 5);
			//Remove from queues
			jobQueue.pop();
			readyQueue.pop();
			// Set burst to 0 so it cannot be negative
			burst = 0;
	// Process still has some burst left
	} else if (burst > 0) {
			cout << "Burst is now " << burst << "\n";
			// Move to back of queue
			readyQueue.pop();
			readyQueue.push(pId);
	}
	// Update burst
	p.updateCycles(burst);
	updateBurst(burst);
	
	getQueues();
	return burst;
}

int Schedule::getMemory() {
	return totalMem;
}

int Schedule::getBurst() {
	return burst;
}

int Schedule::getInstruct() {
	return instruct;
}

int Schedule::updateMem(int usedMemory) {
	totalMem = usedMemory;
	return 0;
}


int Schedule::getQuantum() {
	return quantum;
}