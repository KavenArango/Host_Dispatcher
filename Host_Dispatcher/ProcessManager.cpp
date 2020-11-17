#include "ProcessManager.h"+
#include "Process.h"


ProcessManager::ProcessManager()
{

}

void ProcessManager::AddProcess(Process* newProcess)
{

	// TODO: Check if a thread is running and if it isnt then it should make one
	newProcess = AssignID(newProcess);
	// check if priority is correct
	CheckValidPriority(newProcess);
	AssignQueue(newProcess);
	addProcessToCpu();
	CheckCpu(newProcess->GetPriority());
	if (ThreadRunning == false) {
		SpawnThread();
	}
}

void ProcessManager::CheckCpu(int addedPriority)
{

	if (cpu->GetCurrentProcessPriority() < addedPriority)
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
	ThreadRunning = false;
}

void ProcessManager::SpawnThread()
{
	ThreadRunning = true;
	thread ProcessManagerThread(&ProcessManager::addProcessToCpu, this);
}

void ProcessManager::Interrupt()
{
	for (int i = 0; i < NUMPRIORITYQUEUES; i++) {
		if (!processQueues[i].empty()) {
			AssignQueue(cpu->InterruptCurrentProcess(processQueues[i].front()));
			processQueues[i].pop();
		}
	}
}

void ProcessManager::AssignQueue(Process* newProcess)
{
	processQueues[newProcess->GetPriority()].push(newProcess);
}

void ProcessManager::CheckValidPriority(Process* newProcess)
{
	if (newProcess->GetPriority() >= NUMPRIORITYQUEUES)
	{
		string error = "Process does not have a valid priority ";
		error.append(to_string(newProcess->GetID()));
		throw invalid_argument(error);
	}
}

Process* ProcessManager::AssignID(Process* newProcess)
{
	newProcess->SetID(ID);
	ID++;
	return newProcess;
}