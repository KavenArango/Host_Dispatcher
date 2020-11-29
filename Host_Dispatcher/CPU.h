#pragma once
#include "Process.h"
#include "Resource.h"
#include <thread>
#include <iostream>
using namespace std;
class CPU
{
public:
	CPU();
	shared_ptr<Process> getProcess();
	void SetProcess(shared_ptr<Process>);
	int GetCurrentProcessPriority();
	shared_ptr<Process> InterruptCurrentProcess(shared_ptr<Process>);
	bool IsWorkingOnProcess();
	void threadJoin();
	void SpawnThread();
	void runProcess();

private:
	bool ThreadRunning = false;
	void allocateResources();
	void releaseResources();
	shared_ptr<Process> currentProcess = nullptr;
	thread cpuProcess;
};

