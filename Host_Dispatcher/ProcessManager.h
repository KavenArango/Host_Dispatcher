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

	void AddProcess(shared_ptr<Process>); // check if priority is correct
	void CheckCpu(int);
	void addProcessToCpu();
	void threadJoin();
	shared_ptr<CPU> getCPU();
	void setCPU(shared_ptr<CPU>);
	

	~ProcessManager()
	{}
private:
	shared_ptr<Resource> resourceManager = shared_ptr<Resource>(new Resource());
	shared_ptr<Process> AssignID(shared_ptr<Process>);
	shared_ptr<CPU> cpu = nullptr;
	void SpawnThread();
	void CheckValidPriority(shared_ptr<Process>);
	void Interrupt();
	void AssignQueue(shared_ptr<Process>);
	const int NUMPRIORITYQUEUES = 4;
	queue<shared_ptr<Process>> processQueues[4];
	bool ThreadRunning = false;
	int ID = 0;
	thread ProcessManagerThread;
	
};

