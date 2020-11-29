#include "ProcessManager.h"+
#include "Process.h"


ProcessManager::ProcessManager()
{

}

void ProcessManager::AddProcess(shared_ptr<Process> newProcess)
{
	// TODO: Check if a thread is running and if it isnt then it should make one
	newProcess = AssignID(newProcess);
	// check if priority is correct
	CheckValidPriority(newProcess);
	AssignQueue(newProcess);
	if (newProcess->GetID() == 0) {
		addProcessToCpu();
	}
	CheckCpu(newProcess->GetPriority());
	if (ThreadRunning == false) {
		cpu->SpawnThread();
		SpawnThread();
	}
	
}

void ProcessManager::CheckCpu(int newPriority)
{
	if (cpu->GetCurrentProcessPriority() < newPriority)
	{
		Interrupt();
	}
}

void ProcessManager::addProcessToCpu()
{
	for (int i = 0; i < NUMPRIORITYQUEUES; i++) {
		while (!processQueues[i].empty()) {
			cpu->SetProcess(processQueues[i].front());
			processQueues[i].pop();
		}
	}
	cpu->runProcess();
	//ThreadRunning = false;
}

void ProcessManager::threadJoin()
{
	ProcessManagerThread.join();
	ThreadRunning = false;
}

shared_ptr<CPU> ProcessManager::getCPU()
{
	return cpu;
}

void ProcessManager::setCPU(shared_ptr<CPU> newCPU)
{
	cpu = newCPU;
}

void ProcessManager::SpawnThread()
{
	ThreadRunning = true;
	ProcessManagerThread = thread (&ProcessManager::addProcessToCpu, this);
}

void ProcessManager::Interrupt()
{
	for (int i = 0; i < NUMPRIORITYQUEUES; i++) {
		if (!processQueues[i].empty()) {
			AssignQueue(cpu->InterruptCurrentProcess(processQueues[i].front()));
			processQueues[i].pop();
		}
	}
	
	cpu->runProcess();
}

void ProcessManager::AssignQueue(shared_ptr<Process> newProcess)
{
	processQueues[newProcess->GetPriority()].push(newProcess);
}

void ProcessManager::CheckValidPriority(shared_ptr<Process> newProcess)
{
	if (newProcess->GetPriority() >= NUMPRIORITYQUEUES)
	{
		string error = "Process does not have a valid priority ";
		error.append(to_string(newProcess->GetID()));
		throw invalid_argument(error);
	}
}

shared_ptr<Process> ProcessManager::AssignID(shared_ptr<Process> newProcess)
{
	newProcess->SetID(ID);
	ID++;
	return newProcess;
}