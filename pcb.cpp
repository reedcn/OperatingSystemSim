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
		<< "//Process name: " << name << "\n"
		<< "///////////////////////////////////////////////////////////////////" << "\n" << "\n";
	return 0;
}

int ProcessControlBlock::getCycles(int pId) {
	return cycles;
}


int ProcessControlBlock::updateProcess(int pId, int pState) {
	processState = pState;
	return 0;
}

int ProcessControlBlock::getState(int pId) {
	return processState;
}

int ProcessControlBlock::tokenize(string tokens[], int row) {
	//std::vector<std::string> token_vector;
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
		
		//tokenArrClass[i] = tokenArray[i];
		//tokenArrClass2[i] = tokenArray2[i];
		
		//token_vector.push_back(tokenArray[i]);
		//token_vector.push_back(tokenArray2[i]);
		//cout << "tkv: " << token_vector[i] << endl;
		//tokenArrClass[i] = tokenArray[i];
		//tokenArrClass2[i] = tokenArray2[i];
		
		//cout << tokenArray[i] << endl << tokenArray2[i] << endl;
	}
	
	cycles = tokenArray2[0];
	c = atoi(cycles.c_str());
	//cout << "cycles: " << c;
	
	
	return c;
}


int ProcessControlBlock::readFile(string fileName, int pId) {

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
	//rowsLeft = row;
	
	name = tokens[row-1];

	cycles = tokenize(tokens, row);
	processId = pId;
	updateCycles(cycles);
	outInfo();
	return mem;
}

int ProcessControlBlock::executeProcess(int pId) {
	int i = 0;
	//vector<string>  token_vector;
	for (i = 0; i < rowsLeft; i++) {
		cout << tokenArray[i] << endl << tokenArray2[i] << endl;
		//token_vector.push_back(tokenArrClass[i]);
		//token_vector.push_back(tokenArrClass2[i]);
		//cout << token_vector[i] << endl;
	}
}