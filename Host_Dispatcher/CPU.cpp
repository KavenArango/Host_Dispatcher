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
	cout << currentProcess->GetID() << endl;
}

void CPU::releaseResources()
{

}

void CPU::SpawnThread()
{
	ThreadRunning = true;
	cpuProcess = thread(&CPU::runProcess, this);
}
