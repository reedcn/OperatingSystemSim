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

#define SIZE 1000


class ProcessControlBlock {
	private:
		int processState;
		int processId;
		std::string *programCounter;
		int cycles;
		std::string name;
		int commandNo;

		std::string* tokenArrClass;
		std::string* tokenArrClass2;


	public:
		ProcessControlBlock() {
			processState = 0;
			processId = 0;
			std::string programCounter = "None";
			name = ".exe";
			cycles = 0;
			commandNo = 0;
		}
		
		addNewProcess(int pState, int pId) {
			processState = pState;
			processId = pId;
			
		}
		
		getCommandNo(int pId);
		getCycles(int pId);
		getState(int pId);
		
		readFile(std::string fileName, int pId, int callNo, int q);
		tokenize(std::string tokens[], int row, int callNo, int q);
		
		updateProcess(int pid, int pState) {
			processState = pState;
		}
		updateCycles(int b) {
			cycles = b;
		}
		updateName(std::string n) {
			name = n;
		}
		updateCommandNo(int c) {
			commandNo = c;
		}
		
		outInfo();
		//void operator()(int x);
		
};