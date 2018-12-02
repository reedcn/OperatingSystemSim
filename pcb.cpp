/*Christine Reed
CMSC 312
Operating System Simulator*/

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

// struct thread_data {
	// int thread_id;
	// string s;
	// string s2;
// }

/*void ProcessControlBlock::operator()(int x) {
	cout << "test";
}*/

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
	//struct thread_data td[q][q];
	
	for (i = 0; i < row; i++) {

		token = tokens[i].substr(0,tokens[i].find(delimiter));
		tokens[i].erase(0, tokens[i].find(delimiter) + delimiter.length());
		token2 = tokens[i].substr(0,tokens[i].find(delimiter));

		if (token.compare(token2) == 0) {
			token2 = "\0";
		}
		tokenArray[i] = token;
		tokenArray2[i] = token2;
	}
	programCounter = &tokenArray[0];
	//cout << "Location of instruction: " << &tokenArray[0] << " " << programCounter;
/* 	if (callNo == 2) {
		tokenArrClass = tokenArray;
		tokenArrClass2 = tokenArray2;
		updateProcess(getpid(), 3);
		for (i = 0; i < q; i++) {
			s = *(tokenArrClass + i);
			s2 = *(tokenArrClass2 + i);
			
			if (s.compare("CALCULATE") == 0) {
				cout << "calc" << endl;
				cycles = s2;
				c = atoi(cycles.c_str());
			} else if (s.compare("IO") == 0) {
				cout << "io" << endl;
				updateProcess(getpid(), 4);
			}else if (s.find("IO") != npos) {
				cout << "io" << endl;
				srand(time(NULL));
				randomNo = rand() % 25 + 25;
				updateProcess(getpid(), 4);
			} else if (s.find("YIELD") != npos) {
				cout << "yield" << endl;
				break;
			} else if (s.find("OUT") != npos) {
				cout << "out" << endl;
				outInfo();
			}
			//cout << s << endl;
			//cout << s2 << endl;
		}
	} */
	
	cycles = tokenArray2[0];
	c = atoi(cycles.c_str());
	
	if (callNo == 2) {
		tokenArrClass = tokenArray;
		tokenArrClass2 = tokenArray2;
		updateProcess(getpid(), 3);
		for (i =  getCommandNo(getpid()); i <  q; i++) {
			//cout << "Location of instruction2: " << &tokenArray[0] << " " << programCounter;
			// //cout << "GCN: " << getCommandNo(getpid());
			//for (b = 0; b < q; i++) {
			 //td[i][i] = *(tokenArrClass + i) + *(tokenArrClass2 + i);
			 //s = *(tokenArrClass + i);
			 s = *(tokenArrClass + i);;
			s2 = *(tokenArrClass2 + i);
			//cout << "s: " << s << endl;
			//cout << s2 << endl;
			//pthread_create(&threads[i], NULL, &ProcessControlBlock::execCommands, NULL);
			//std::thread t(ProcessControlBlock(), 3);
			//t.join();
			if (s.compare("CALCULATE") == 0) {
				//cout << q << " command(s) completed" << endl;
				cycles = s2;
				c = atoi(cycles.c_str());
			} else if (s.compare("IO") == 0) {
				//cout << "Command complete" << endl;
				updateProcess(getpid(), 4);
			}else if (s.find("IO") != npos) {
				srand(time(NULL));
				randomNo = rand() % 25 + 25;
				updateProcess(getpid(), 4);
				cout << "Random number generated: " << randomNo << endl;
			} else if (s.find("YIELD") != npos) {
				//cout << "Command complete" << endl;
				break;
			} else if (s.find("OUT") != npos) {
				outInfo();
				//cout << "Command complete" << s2 << endl;
			}
			//cout << s << endl;
			//cout << s2 << endl;
			commandNo++;
		}
		cout << q << " command(s) completed" << endl;
		updateCommandNo(commandNo);
		programCounter = &tokenArray[commandNo];
		//cout << "Location of instruction2: " << commandNo << tokenArray[commandNo] << " " << programCounter;
	}
	
	return c;
}


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
	//outInfo();
	return mem;
}