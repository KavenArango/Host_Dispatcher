#pragma once
#include "Process.h"
#include "Resource.h"
#include <thread>

class CPU
{
public:
	CPU();
	Process* getProcess();
	void SetProcess(Process*);
	int GetCurrentProcessPriority();
	Process* InterruptCurrentProcess(Process*);
	bool IsWorkingOnProcess();

private:
	void allocateResources();
	void releaseResources();
	Process* process = new Process();

};

