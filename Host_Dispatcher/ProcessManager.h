#pragma once
#include <queue>
#include <array>
#include <stdexcept>

#include "Process.h"

using namespace std;

class ProcessManager
{
public:
	
	ProcessManager();

	void AddProcess(Process*); // check if priority is correct
	void CheckQueue();




	~ProcessManager()
	{}
private:
	
	void SpawnThread();
	void CheckValidPriority();
	Process* AssignID(Process*);
	void Interrupt();
	void AssignQueue(Process*);

	const int NUMPRIORITYQUEUES = 4;
	queue<Process*> processQueues[4];

	int ID = 0;

};

