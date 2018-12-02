/*Christine Reed
CMSC 312
Operating System Simulator*/

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
	
//	pthread_t thread;
	
	ifstream inFile;

	int row;
	int q = 0;
	int pid = 0;
	int current = 0;
	int i = 0;
	
	cout << "Enter time quantum q: ";
	getline(cin,quantum);
	q = atoi(quantum.c_str());
    pthread_t t[NUMTHREADS];
	

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
			//std::thread t(test,fileName, q);
			pthread_create(&t[i], NULL, continueScheduler, NULL);
			for (auto& th : t) {
					pthread_join(t[i], NULL);
			}
			pid = k.createNewProcess(fileName,q);
			//for (i = 0; i < 4; i++) {
			//}

			inFile.close();
		}
	}
	return 0;
}
