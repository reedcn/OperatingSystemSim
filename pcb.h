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


class ProcessControlBlock {
	private:
		int processState;
		int processId;
		std::string *programCounter;
		int cycles;
		std::string q;
		std::string name;
		
		//std::string tokenArray[SIZE];
		//std::string tokenArray2[SIZE];
		std::string* tokenArrClass;
		std::string* tokenArrClass2;
		//std::string tokenArrClass[SIZE];
		//std::string tokenArrClass2[SIZE];
		//std::vector<std::string> token_vector;
		//std::vector<std::string> tokenQueue;
		
		//int rowsLeft;

	public:
		ProcessControlBlock() {
			processState = 0;
			processId = 0;
			std::string programCounter = "None";
			q = "Job";
			name = ".exe";
			cycles = 0;
		}
		
		addNewProcess(int pState, int pId) {
			processState = pState;
			processId = pId;
			
		}
		
		getCycles(int pId);
		getState(int pId);
		
		readFile(std::string fileName, int pId);
		tokenize(std::string tokens[], int row);
		//executeProcess(int pId);
		
		updateProcess(int pid, int pState);
		updateCycles(int b) {
			cycles = b;
		}
		updateName(std::string n) {
			name = n;
		}
		
		outInfo();
		
};