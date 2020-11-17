#pragma once
#include <queue>
#include <array>
#include <stdexcept>
#include <thread>
#include "CPU.h"
#include "Process.h"
#include "Resource.h"
using namespace std;

class ProcessManager
{
public:
	
	ProcessManager();

	void AddProcess(Process*); // check if priority is correct
	void CheckCpu(int);
	void addProcessToCpu();



	~ProcessManager()
	{}
private:
	Resource* resourceManager;
	Process* AssignID(Process*);
	CPU* cpu;
	void SpawnThread();
	void CheckValidPriority(Process*);
	void Interrupt();
	void AssignQueue(Process*);
	const int NUMPRIORITYQUEUES = 4;
	queue<Process*> processQueues[4];
	bool ThreadRunning = false;
	int ID = 0;

};

