#include "ProcessManager.h"+
#include "Process.h"

ProcessManager::ProcessManager()
{

}

void ProcessManager::AddProcess(shared_ptr<Process> newProcess)
{
	CheckValidPriority(newProcess);
	newProcess = AssignID(newProcess);
	
	
	AssignQueue(newProcess);
}

void ProcessManager::CheckValidPriority(shared_ptr<Process> newProcess)
{
	if (newProcess->GetPriority() >= NUMPRIORITYQUEUES)
	{
		string error = "Process does not have a valid priority ";
		error.append(to_string(newProcess->GetPriority()));
		throw invalid_argument(error);
	}
}
shared_ptr<Process> ProcessManager::AssignID(shared_ptr<Process> newProcess)
{
	newProcess->SetID(ID);
	ID++;
	return newProcess;
}
void ProcessManager::AssignQueue(shared_ptr<Process> newProcess)
{
	ThreadJoin();
	processQueues[newProcess->GetPriority()].push(newProcess);
	if (cpu->IsWorkingOnProcess() == false)
	{
		SingleAddProcessToCpu();
	}
	else
	{
		CheckCpu(newProcess->GetPriority());
	}
	SpawnThread();
}
void ProcessManager::AddProcessToCpu()
{
	
	for (int i = 0; i < NUMPRIORITYQUEUES; i++) 
	{
		while(!processQueues[i].empty()) 
		{
			if (cpu->IsWorkingOnProcess() == false)
			{
				cpu->SetProcess(processQueues[i].front());
				processQueues[i].pop();
			}
		}
	}
	threadRunning = false;
}


void ProcessManager::SingleAddProcessToCpu()
{
	for (int i = 0; i < NUMPRIORITYQUEUES; i++) {
		if (!processQueues[i].empty()) 
		{
			cpu->SetProcess(processQueues[i].front());
			processQueues[i].pop();
			break;
		
		}
	}
}







void ProcessManager::SpawnThread()
{
	if (threadRunning == true)
	{
		threadRunning = true;
		ProcessManagerThread = thread(&ProcessManager::AddProcessToCpu, this);
	}
}
void ProcessManager::Interrupt()
{
	ThreadJoin();
	for (int i = 0; i < NUMPRIORITYQUEUES; i++) 
	{
		if (!processQueues[i].empty()) 
		{
			AssignQueue(cpu->InterruptCurrentProcess(processQueues[i].front()));
			processQueues[i].pop();
			break;
		}
	}
}
void ProcessManager::CheckCpu(int newPriority)
{
	if (cpu->GetCurrentProcessPriority() < newPriority)
	{
		Interrupt();
	}
}
void ProcessManager::ThreadJoin()
{
	if (ProcessManagerThread.joinable())
	{
		ProcessManagerThread.join();
		threadRunning = false;
	}
}



void ProcessManager::SetCPU(shared_ptr<CPU> newCPU)
{
	cpu = newCPU;
}

shared_ptr<CPU> ProcessManager::GetCPU()
{
	return cpu;
}
