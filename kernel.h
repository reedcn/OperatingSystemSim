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

#define ARGU 2
#define SIZE 1000

class Kernel {
	private:
		ProcessControlBlock p;
		Schedule s;
		int wpid, status;
		int mem;
		int pMem;
		int usedMem;
		int current;
		int currentProcessCycles;
	
	public:
		Kernel() {
		}
		
		int createNewProcess(std::string fileName, int arrivalNo, int q);
		
};