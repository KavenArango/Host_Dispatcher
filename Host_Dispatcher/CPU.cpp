#include "CPU.h"

CPU::CPU()
{
}

shared_ptr<Process> CPU::getProcess()
{
	return currentProcess;
}

void CPU::SetProcess(shared_ptr<Process> newProcess)
{
	currentProcess = newProcess;
	currentProcess;
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
	return true;
}

void CPU::threadJoin()
{
	cpuProcess.join();
	ThreadRunning = false;
}

void CPU::runProcess()
{
	using namespace std::chrono;
	auto starttimer = high_resolution_clock::now();
	
	checkRunStatus = true;
	
	while (currentProcess->GetProcessTime() > 0)
	{
		auto stoptimer = high_resolution_clock::now();
		auto deltatime = duration_cast<microseconds>(stoptimer - starttimer);
		
		currentProcess->SetProcessTime(currentProcess->GetProcessTime() - deltatime.count());
		cout << currentProcess->GetID() << endl;
	}
	checkRunStatus = false;
}

bool CPU::getRunStatus()
{
	return checkRunStatus;
}

void CPU::releaseResources()
{

}

void CPU::SpawnThread()
{
	ThreadRunning = true;
	cpuProcess = thread(&CPU::runProcess, this);
}
