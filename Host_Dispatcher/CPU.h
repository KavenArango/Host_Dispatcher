#pragma once

#include "ResourceManager.h"
#include "Resource.h"
#include "Process.h"
#include "Memory.h"

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
class CPU
{
public:
	CPU();
	shared_ptr<Process> GetProcess();
	void SetProcess(shared_ptr<Process> newProcess);
	void RunProcess(shared_ptr<Process>);
	int GetCurrentProcessPriority();
	shared_ptr<Process> InterruptCurrentProcess(shared_ptr<Process>);
	bool IsWorkingOnProcess();
	bool GetRunStatus();
	void StartCPU(shared_ptr<Process>);
private:

	shared_ptr<Process> currentProcess = nullptr;
	
	bool checkRunStatus = false;
	
	void allocateResources();
	void releaseResources();
	
	shared_ptr<Memory> memory = shared_ptr<Memory>(new Memory());
	shared_ptr<ResourceManager> resourcesManager = shared_ptr<ResourceManager>(new ResourceManager());
};