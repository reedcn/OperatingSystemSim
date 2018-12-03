/*Christine Reed
CMSC 312
Operating System Simulator

File: main.cpp
Purpose:  Begin application*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#include <fstream>
#include <pthread.h>

#include "pcb.h"
#include "schedule.h"
#include "kernel.h"

using namespace std;

#define ARGU 2
#define SIZE 1000
#define NUMTHREADS 4


void* continueScheduler(void *test) {
		pthread_mutex_t mtx= PTHREAD_MUTEX_INITIALIZER;
		
		//Critical section using mutex locks
		
		pthread_mutex_lock(&mtx);
		Schedule s;
		s.roundRobinScheduler();
		pthread_mutex_unlock(&mtx);
		
		pthread_exit(NULL);
}

int main() {
	string str = "\nOS >";
	string fileName;
	string quantum;
	
	ProcessControlBlock p;
	Schedule s;
	Kernel k;
	
	ifstream inFile;
	ofstream outFile;

	int row;
	int q = 0;
	int pid = 0;
	int current = 0;
	int i = 0;
	int randomNo = 0;
	int j = 0;
	
	// Prompt user to enter a time quantum for the round robin scheduler
	cout << "Enter time quantum q: ";
	getline(cin,quantum);
	q = atoi(quantum.c_str());
    pthread_t t[NUMTHREADS];
	
	// For find() string function comparison
	static const size_t npos = -1;
	

	// Take in as many files as the user desires
	while (1) {
		row = 0;
		fileName = "";
		
		cout << str << " Enter job file ending in .txt or number of job files to create: ";
		getline(cin, fileName);
		// For entering a job file manually
		if (fileName.find(".txt") != npos) {
			inFile.open(fileName);
			if (!inFile) {
				cerr << "Unable to open file";
				exit(1);
			} else{
				// Multithreading
				pthread_create(&t[i], NULL, continueScheduler, NULL);
				for (auto& th : t) {
						pthread_join(t[i], NULL);
				}
				pid = k.createNewProcess(fileName,q);

				inFile.close();
			}
		// Auto generate job files
		} else {
			int x = stoi(fileName);
				srand(time(NULL));
			for (i = 0; i < x; i++) {
				randomNo = rand() % 2048 + 1;
				
				string name = to_string(randomNo) + ".txt";
				ofstream outFile(name);
				outFile << randomNo << "\r" << endl;
				int calc = rand() % 15 + 5;
				outFile << "CALCULATE " << calc << "\r" << endl;
				int numCommands = rand() % 7 + 1;
				for (j = 0; j < numCommands; j++) {
					int randCommand = rand() % 3;
					if  (randCommand == 0) {
						int io = rand() % 25 + 25;
						outFile << "IO " << io << endl;
					} else if  (randCommand == 1) {
						outFile << "YIELD " << endl;
					} else {
						outFile << "OUT " << endl;
					}
					outFile << "\r" << endl;
				}
					outFile << randomNo << ".exe";
					cout << "New file created called "<< name << endl;
				
				outFile.close();
			}
		}
	}
	return 0;
}
