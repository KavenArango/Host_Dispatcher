#include "CPU.h"

CPU::CPU()
{
}





void CPU::RunProcess(shared_ptr<Process> newprocess)
{
	SetProcess(newprocess);
	
	cout << endl << "Running Process: " << currentProcess->GetID() << ", Priority: " << currentProcess->GetPriority();	
	allocateResources();
	checkRunStatus = true;

	
	using namespace std::chrono;
	this_thread::sleep_for(std::chrono::microseconds(currentProcess->GetProcessTime()));
	cout << "Finished Process: " << currentProcess->GetID() << ", Priority: " << currentProcess->GetPriority() << endl;
	checkRunStatus = false;
	releaseResources();
}



shared_ptr<Process> CPU::GetProcess()
{
	return currentProcess;
}

void CPU::SetProcess(shared_ptr<Process> newProcess)
{
	currentProcess = newProcess;
}

int CPU::GetCurrentProcessPriority()
{
	return currentProcess->GetPriority();
}

shared_ptr<Process> CPU::InterruptCurrentProcess(shared_ptr<Process> newProcess)
{
	shared_ptr<Process> oldProcess = currentProcess;
	releaseResources();
	SetProcess(newProcess);
	return oldProcess;
}

bool CPU::IsWorkingOnProcess()
{
	if (currentProcess == nullptr)
	{
		return false;
	}

	return checkRunStatus;
}

bool CPU::GetRunStatus()
{
	return checkRunStatus;
}

void CPU::StartCPU(shared_ptr<Process> newProcess)
{
	SetProcess(newProcess);
}

void CPU::allocateResources()
{
	resourcesManager->AllocateResources("Printer", currentProcess->GetPrintersNeeded(), currentProcess->GetID());
	resourcesManager->AllocateResources("Scanner", currentProcess->GetScannersNeeded(), currentProcess->GetID());
	resourcesManager->AllocateResources("Modems", currentProcess->GetModemsNeeded(), currentProcess->GetID());
	resourcesManager->AllocateResources("CD", currentProcess->GetCDsNeeded(), currentProcess->GetID());
	memory->firstFit(currentProcess->GetID(), currentProcess->GetMBytes());
}

void CPU::releaseResources()
{
	resourcesManager->DeAllocateResources(currentProcess->GetID());
	memory->freeAllocation(currentProcess->GetID(),currentProcess->GetMBytes());
}