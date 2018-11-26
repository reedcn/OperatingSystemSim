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
#include "schedule.h"
#include "kernel.h"

using namespace std;

#define ARGU 2
#define SIZE 1000

int main(int argc, char **argv) {
	string str = "\nOS >";
	string fileName;
	string quantum;
	
	ProcessControlBlock p;
	Schedule s;
	Kernel k;
	
	ifstream inFile;

	int row;
	int q = 0;
	int arrivalNo = 0;
	int pid = 0;
	
	cout << "Enter time quantum q: ";
	getline(cin,quantum);
	q = atoi(quantum.c_str());
	
	s.addQuantum(q);
	s.outInfoSched();

	while (1) {
		row = 0;
		fileName = "";
		
		cout << str << " Enter file: ";
		getline(cin, fileName);
		inFile.open(fileName);
		if (!inFile) {
			cerr << "Unable to open file";
			exit(1);
		} else{
			inFile.close();
			pid = k.createNewProcess(fileName, arrivalNo);
			cout << "Pid: " << pid;
			//s.enterJobQueue(pid);

			//s.moveQueue(pid, 2);
			//s.getQueues();

			arrivalNo++;

			inFile.close();
		}
	}
	return 0;
}