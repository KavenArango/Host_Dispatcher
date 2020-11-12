#include "ProcessManager.h"+



ProcessManager::ProcessManager()
{}

void ProcessManager::AddProcess(Process* newProcess)
{

	// TODO: Check if a thread is running and if it isnt then it should make one
	newProcess = AssignID(newProcess);
	// check if priority is correct
	if (newProcess->GetPriority() >= NUMPRIORITYQUEUES)
	{
		string error = "Process does not have a valid priority ";
		error.append(to_string(newProcess->GetID()));
		throw invalid_argument(error);
	}
	AssignQueue(newProcess);
	CheckQueue()
}


void ProcessManager::CheckQueue()
{

}

void ProcessManager::SpawnThread()
{

}

void ProcessManager::CheckValidPriority()
{

}


void ProcessManager::Interrupt()
{}

void ProcessManager::AssignQueue(Process* newProcess)
{
	processQueues[newProcess->GetPriority()].push(newProcess);
}


Process* ProcessManager::AssignID(Process* newProcess)
{
	newProcess->SetID(ID);
	ID++;
	return newProcess;
}