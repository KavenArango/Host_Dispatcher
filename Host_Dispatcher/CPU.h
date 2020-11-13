#pragma once


#include "Process.h"
class CPU
{
public:
	CPU();
	void SetProcess(Process*);
	int GetCurrentProcessPriority();
	Process* InterruptCurrentProcess(Process*);

private:
	void allocateResources();
	void releaseResources();

};

