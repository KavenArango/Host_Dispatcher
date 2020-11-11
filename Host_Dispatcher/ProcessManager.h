#pragma once
#include <queue>
#include <array>

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
	void Interrupt();
	queue<Process*> processQueues[4];
	int ID = 0;

};

