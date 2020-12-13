#pragma once
#include "Process.h"
#include "Resource.h"
#include "Memory.h"
#include "ResourceManager.h"


#include <thread>
#include <iostream>
#include <chrono>
using namespace std;
class CPU
{
public:
	CPU();
	shared_ptr<Process> GetProcess();
	void SetProcess(shared_ptr<Process>);
	int GetCurrentProcessPriority();
	shared_ptr<Process> InterruptCurrentProcess(shared_ptr<Process>);
	bool IsWorkingOnProcess();
	void ThreadJoin();
	void SpawnThread();
	void RunProcess();
	bool GetRunStatus();
	void StartCPU(shared_ptr<Process>);
private:

	shared_ptr<Process> currentProcess = nullptr;
	atomic_bool killThread = false;
	bool checkRunStatus = false;
	bool ThreadRunning = false;
	void allocateResources();
	void releaseResources();
	thread cpuProcess;
	shared_ptr<Memory> memory = shared_ptr<Memory>(new Memory());
	shared_ptr<ResourceManager> resourcesManager = shared_ptr<ResourceManager>(new ResourceManager());
};
