#include "CPU.h"

CPU::CPU()
{
}

shared_ptr<Process> CPU::GetProcess()
{
	return currentProcess;
}

void CPU::SetProcess(shared_ptr<Process> newProcess)
{
	ThreadJoin();
	currentProcess = newProcess;
	SpawnThread();
}

int CPU::GetCurrentProcessPriority()
{
	return currentProcess->GetPriority();
}

shared_ptr<Process> CPU::InterruptCurrentProcess(shared_ptr<Process> newProcess)
{
	ThreadJoin();
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

void CPU::ThreadJoin()
{
	if (cpuProcess.joinable())
	{
		killThread == true;
		if (ThreadRunning == true)
		{
			cpuProcess.join();
			ThreadRunning = false;
		}
	}
}

void CPU::RunProcess()
{
	allocateResources();
	using namespace std::chrono;
	auto starttimer = high_resolution_clock::now();
	
	checkRunStatus = true;
	
	cout << "Running Process: " << currentProcess->GetID() << ", Priority: " << currentProcess->GetPriority() << endl;
	
	while (currentProcess->GetProcessTime() > 0)
	{
		if (killThread == true)
		{
			killThread = false;
			return;
		}
		auto stoptimer = high_resolution_clock::now();
		auto deltatime = duration_cast<microseconds>(stoptimer - starttimer);
		
		currentProcess->SetProcessTime(currentProcess->GetProcessTime() - deltatime.count());
	}
	cout << "Finished Process: " << currentProcess->GetID() << ", Priority: " << currentProcess->GetPriority() << endl;
	checkRunStatus = false;
	ThreadRunning = false;
	releaseResources();
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
	resourcesManager->AllocateResources("Printer", currentProcess->GetCDsNeeded(), currentProcess->GetID());
	resourcesManager->AllocateResources("Scanner", currentProcess->GetCDsNeeded(), currentProcess->GetID());
	resourcesManager->AllocateResources("Modems", currentProcess->GetCDsNeeded(), currentProcess->GetID());
	resourcesManager->AllocateResources("CD", currentProcess->GetCDsNeeded(), currentProcess->GetID());
	memory->firstFit(currentProcess->GetID(), currentProcess->GetMBytes());
}

void CPU::releaseResources()
{
	resourcesManager->DeAllocateResources("Printer", currentProcess->GetID());
	resourcesManager->DeAllocateResources("Scanner", currentProcess->GetID());
	resourcesManager->DeAllocateResources("Modems", currentProcess->GetID());
	resourcesManager->DeAllocateResources("CD", currentProcess->GetID());
	memory->freeAllocation(currentProcess->GetID(),currentProcess->GetMBytes());
}

void CPU::SpawnThread()
{
	if (ThreadRunning == false)
	{
		ThreadRunning = true;
		cpuProcess = thread(&CPU::RunProcess, this);
	}
}
