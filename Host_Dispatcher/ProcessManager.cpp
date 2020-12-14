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
	processQueues[newProcess->GetPriority()].push(newProcess);
}





void ProcessManager::RunProcesses()
{
	for (int i = 0; i < NUMPRIORITYQUEUES; i++)
	{
		while (!processQueues[i].empty())
		{
			if (cpu->IsWorkingOnProcess() == false)
			{
				cpu->RunProcess(processQueues[i].front());
				processQueues[i].pop();
			}
		}
	}
}


void ProcessManager::SetCPU(shared_ptr<CPU> newCPU)
{
	cpu = newCPU;
}
void ProcessManager::print()
{
	for (int i = 0; i < NUMPRIORITYQUEUES; i++)
	{
		while (!processQueues[i].empty())
		{
			cout << processQueues[i].front()->GetID() << " " << processQueues[i].front()->GetPriority() << endl;
			processQueues[i].pop();
		}
	}
}
shared_ptr<CPU> ProcessManager::GetCPU()
{
	return cpu;
}