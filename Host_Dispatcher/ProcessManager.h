#pragma once
#include <queue>
#include <array>
#include <stdexcept>
#include <thread>
#include <future>
#include "CPU.h"
#include "Process.h"
#include "Resource.h"
using namespace std;

class ProcessManager
{
public:
	
	ProcessManager();

	void AddProcess(shared_ptr<Process>);
	void ThreadJoin();
	shared_ptr<CPU> GetCPU();
	void SetCPU(shared_ptr<CPU>);
	

	~ProcessManager()
	{}

private:
	shared_ptr<Resource> resourceManager = shared_ptr<Resource>(new Resource());
	shared_ptr<CPU> cpu = nullptr;
	
	
	shared_ptr<Process> AssignID(shared_ptr<Process>);
	
	void CheckCpu(int);
	void AddProcessToCpu();
	void CheckValidPriority(shared_ptr<Process>);
	void AssignQueue(shared_ptr<Process>);
	void SingleAddProcessToCpu();
	
	const int NUMPRIORITYQUEUES = 4;
	queue<shared_ptr<Process>> processQueues[4];
	int ID = 0;
};