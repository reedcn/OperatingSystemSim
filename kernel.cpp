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
#include <fstream>

#include "pcb.h"

using namespace std;

#define ARGU 2
#define SIZE 1000

int tokenize(string tokens[], int row) {
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

	return c;
}

void createNewProcess(int mem, string nameProcess, int burst, int arrivalNo, int q) {

	pid_t pid = fork();
	int wpid, status;
	ProcessControlBlock p;
		if ( pid < 0 ) {
			printf("Fork failed.\n");
			exit(0);
		} else if ( pid > 0 ) {

			do {
				wpid = wait(&status); // wpid
			} while (!WIFEXITED(status));
			
			cout << "\n Exit Status: " << status;
		} else {
			p.addQuantum(q);
			p.addNewProcess(1, getpid(), burst, arrivalNo, nameProcess);			
			p.moveQueue(getpid());
			p.outInfo();
			
			//execl(name, charTokenArray);
			p.updateProcess(2);
			p.moveQueue(getpid());
			p.outInfo();
			p.roundRobinScheduler();
			
			
		}
		
}

int main(int argc, char **argv) {
	string str = "\nOS >";
	string command = "";
	string memoryString = "";
	string nameProcess = "";
	string tokens[SIZE];
	string fileName;
	string quantum;
	
	int i;
	int burst = 0;
	int mem = 0;
	int row;
	int q = 0;
	int arrivalNo = 0;
	
	cout << "Enter time quantum q: ";
	getline(cin,quantum);
	q = atoi(quantum.c_str());

	ifstream inFile;

	while (1) {
		row = 0;
		fileName = "";
		for (i = 0; i < SIZE; i++) {
			tokens[i] = "\0";
		}
		
		cout << str << " Enter file: ";
		getline(cin, fileName);
		inFile.open(fileName);
		if (!inFile) {
			cerr << "Unable to open file";
			exit(1);
		} else{
			arrivalNo++;

			getline(inFile, memoryString);
			mem = atoi(memoryString.c_str());

			
			while(getline(inFile, command)) {
				tokens[row] = command;
				row++;

			}
			nameProcess = tokens[row-1];

			burst = tokenize(tokens, row);

			createNewProcess (mem, nameProcess, burst, arrivalNo, q);
			cout << "Arrival no: " << arrivalNo;
			inFile.close();
		}
	}
	return 0;
}