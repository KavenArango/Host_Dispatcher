#include "CPU.h"

CPU::CPU()
{
}

Process* CPU::getProcess()
{

	return process;
}

void CPU::SetProcess(Process* newProcess)
{
	process = newProcess;
}

int CPU::GetCurrentProcessPriority()
{

	return process->GetPriority();
}

Process* CPU::InterruptCurrentProcess(Process* newProcess)
{
	Process* oldProcess = process;
	releaseResources();
	SetProcess(newProcess);
	return oldProcess;
}

bool CPU::IsWorkingOnProcess()
{
	if (process == nullptr)
	{
		return false;
	}
	return true;
}

void CPU::releaseResources()
{

}