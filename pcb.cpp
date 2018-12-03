/*Christine Reed
CMSC 312
Operating System Simulator

File: pcb.cpp
Purpose:  Process Control Block*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <bits/stdc++.h>
#include <unistd.h>
#include <unistd.h>
#include <queue>
#include <time.h>
#include <stdlib.h>
#include <thread>


#include "pcb.h"
#include "schedule.h"
#include "kernel.h"
using namespace std;

// OUT command: Print out all info on the PCB
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
		<< "//Process name: " << name << "\n"
		<< "///////////////////////////////////////////////////////////////////" << "\n" << "\n";
	return 0;
}

int ProcessControlBlock::getCycles(int pId) {
	return cycles;
}


int ProcessControlBlock::getState(int pId) {
	return processState;
}

int ProcessControlBlock::getCommandNo(int pId) {
	return commandNo;
}

// After reading lines of text file, tokenize them by words to execute each argument
int ProcessControlBlock::tokenize(string tokens[], int row, int callNo, int q) {
	int i  = 0;
	string token;
	string token2;
	string tokenArray[SIZE];
	string tokenArray2[SIZE];
	string delimiter = " ";
	string cycles;
	tokenArrClass = new string[SIZE];
	tokenArrClass2 = new string[SIZE];
	ProcessControlBlock p;
	int c = 0;
	commandNo = 0;
	string s;
	string s2;
	int randomNo;
	static const size_t npos = -1;
	pthread_t threads[q];
	
	for (i = 0; i < row; i++) {
		// First part of command (the word)
		token = tokens[i].substr(0,tokens[i].find(delimiter));
		// Erase first part after putting in array
		tokens[i].erase(0, tokens[i].find(delimiter) + delimiter.length());
		// Second part of command (number or NULL)
		token2 = tokens[i].substr(0,tokens[i].find(delimiter));

		if (token.compare(token2) == 0) {
			token2 = "\0";
		}
		tokenArray[i] = token;
		tokenArray2[i] = token2;
	}
	// Set programCounter to location of first command
	programCounter = &tokenArray[0];
	// Set cycles
	cycles = tokenArray2[0];
	c = atoi(cycles.c_str());
	
	// 2nd time ReadFile is called: execute
	if (callNo == 2) {
		tokenArrClass = tokenArray;
		tokenArrClass2 = tokenArray2;
		// Set process to Running
		updateProcess(getpid(), 3);
		for (i =  getCommandNo(getpid()); i <  q; i++) {
			s = *(tokenArrClass + i);;
			s2 = *(tokenArrClass2 + i);
			if (s.compare("CALCULATE") == 0) {
				cycles = s2;
				c = atoi(cycles.c_str());
				// I/O followed by number
			} else if (s.compare("IO") == 0) {
				updateProcess(getpid(), 4);
				// I/O followed by no number
			}else if (s.find("IO") != npos) {
				srand(time(NULL));
				randomNo = rand() % 25 + 25;
				updateProcess(getpid(), 4);
				cout << "Random number generated for I/O: " << randomNo << endl;
			} else if (s.find("YIELD") != npos) {
				break;
			} else if (s.find("OUT") != npos) {
				outInfo();
			}
			commandNo++;
		}
		cout << q << " command(s) completed" << endl;
		// Update number of commands scheduler will execute
		updateCommandNo(commandNo);
		
		// Update location
		programCounter = &tokenArray[commandNo];
	}
	
	return c;
}

// Read lines of the file
int ProcessControlBlock::readFile(string fileName, int pId, int callNo, int q) {

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

	cycles = tokenize(tokens, row, callNo, q);
	processId = pId;
	updateCycles(cycles);
	return mem;
}