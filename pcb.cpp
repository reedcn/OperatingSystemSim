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
	
	cout << "////////////////////////////////////////////////////////////////////" << "\n"
		<< "//PCB Info" << "\n"
		<< "//Process State: " << processStateString << "\n"
		<< "//Process ID: " << processId << "\n"
		<< "//Location of next instruction: " << programCounter << "\n"
		<< "//Cycles/Burst: " << cycles << "\n"
		<< "//Current Queue: " << q << "\n"
		<< "//Arrival Time: " << arrival << "\n"
		<< "//Process name: " << name << "\n"
		<< "///////////////////////////////////////////////////////////////////" << "\n" << "\n";
		//cout << "ARRIVAL IS " << arrival << " FOR PROCESS " << pId; 
	return 0;
}

int ProcessControlBlock::getCycles(int pId) {
	return cycles;
}


int ProcessControlBlock::getArrivalNo(int pId) {
	if (pId == processId) {
		cout << "ARRIVAL IS " << arrival << " FOR PROCESS " << processId; 
		return arrival;
	}
	return 0;
}

int ProcessControlBlock::updateProcess(int pId, int pState) {
	processState = pState;
	return 0;
}

int ProcessControlBlock::getState(int pId) {
	return processState;
}

int ProcessControlBlock::tokenize(string tokens[], int row) {
	int i  = 0;
	string token;
	string token2;
	string tokenArray[SIZE];
	string tokenArray2[SIZE];
	string delimiter = " ";
	string cycles;
	int c = 0;
	
	for (i = 0; i < row; i++) {

		token = tokens[i].substr(0,tokens[i].find(delimiter));
		tokens[i].erase(0, tokens[i].find(delimiter) + delimiter.length());
		token2 = tokens[i].substr(0,tokens[i].find(delimiter));

		if (token.compare(token2) == 0) {
			token2 = "\0";
		}
		tokenArray[i] = token;
		tokenArray2[i] = token2;
		cout << tokenArray[i] << "\n";
		cout << tokenArray2[i] << "\n";
	}
	
	cycles = tokenArray2[0];
	c = atoi(cycles.c_str());
	cout << "cycles: " << c;
	
	
	return c;
}


int ProcessControlBlock::readFile(string fileName, int pId, int arrivalNo) {

	string command = "";
	string memoryString = "";
	string tokens[SIZE];

	int mem = 0;
	int row;

	ifstream inFile;
	inFile.open(fileName);
	
	getline(inFile, memoryString);
	mem = atoi(memoryString.c_str());
	
	while(getline(inFile, command)) {
		tokens[row] = command;
		row++;

	}
	
	name = tokens[row-1];

	cycles = tokenize(tokens, row);
	processId = pId;
	arrival = arrivalNo;
	//cout << "cycles: " << getCycles(pId);
	updateCycles(cycles);
	outInfo();
	//cout << "cycles: " << getCycles(getpid());
	return mem;
}

