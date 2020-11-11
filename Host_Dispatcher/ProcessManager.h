#pragma once
#include <queue>
#include <array>

#include "Process.h"

using namespace std;

class ProcessManager
{
public:
	void AddProcess(Process*);
	void CheckQueue();

private:
	void Interrupt();
	queue<Process*> processQueues[4];


};

