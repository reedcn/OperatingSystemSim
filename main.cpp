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

void* continueScheduler(void *test) {
	Schedule s;
		s.roundRobinScheduler();
		
		pthread_exit(NULL);
}

int main(int argc, char **argv) {
	string str = "\nOS >";
	string fileName;
	string quantum;
	
	ProcessControlBlock p;
	Schedule s;
	Kernel k;
	
	pthread_t thread;
	
	ifstream inFile;

	int row;
	int q = 0;
	int pid = 0;
	int current = 0;
	
	cout << "Enter time quantum q: ";
	getline(cin,quantum);
	q = atoi(quantum.c_str());
	

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
			pid = k.createNewProcess(fileName,q);
			//pthread_create(&thread, NULL, continueScheduler, NULL);

			inFile.close();
		}
	}
	return 0;
}