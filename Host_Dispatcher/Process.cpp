#include "Process.h"




Process::Process()
{}
Process::Process(int pri, float pTime, int aTime, int mem)
{
    SetPriority(pri);
    SetProcessTime(pTime);
    SetArrivalTime(aTime);
    SetMBytes(mem);
}
Process::~Process()
{}



int Process::GetID()
{
    return ID;
}
void Process::SetID(int newID)
{
    ID = newID;
}



int Process::GetPriority()
{
    return priority;
}
void Process::SetPriority(string newPri)
{
    int testPri;
    remove_if(newPri.begin(), newPri.end(), isspace);
    remove_if(newPri.begin(), newPri.end(), isalpha);
    for (int i = 0; i < newPri.size(); i++)
    {
        if (newPri[i] == '.')
        {
            throw "Invalid priortiy integer only, priority given:", newPri;
        }
    }
    testPri = stoi(newPri);
    if (testPri != 1 && testPri != 2 && testPri != 3 && testPri != 4) // a point of contention this needs to be reviewed do not delete untill reviewed
    {
        throw "Invalid priortiy allowed range 1-4, priority given: ", testPri;
    }
        priority = testPri;
}
void Process::SetPriority(int newPriority)
{
    if (newPriority != 1 && newPriority != 2 && newPriority != 3 && newPriority != 4) // this needs to be reviewed do no ignore this needs to be reviewed before comment is deleted
    {
        throw "Invalid priortiy allowed range 1-4, priority given: ", newPriority;
    }
    priority = newPriority;
}



float Process::GetProcessTime()
{
    return processTime;
}
void Process::SetProcessTime(string newPTime)
{
    float testPTime;
    remove_if(newPTime.begin(), newPTime.end(), isspace);
    remove_if(newPTime.begin(), newPTime.end(), isalpha);
    testPTime = stoi(newPTime);

    if (testPTime < 0)
    {
        throw "Invalid Process time positive numbers only time given: ", testPTime;
    }
    processTime = testPTime;
}
void Process::SetProcessTime(float newPTime)
{
    if (newPTime < 0)
    {
        throw "Invalid Process time positive numbers only time given: ", newPTime;
    }
    processTime = newPTime;
}


int Process::GetArrivalTime()
{
    return arrivalTime;
}
void Process::SetArrivalTime(string newATime)
{
    int testATime;
    remove_if(newATime.begin(), newATime.end(), isspace);
    remove_if(newATime.begin(), newATime.end(), isalpha);
    testATime = stoi(newATime);
    
    for (int i = 0; i < newATime.size(); i++)
    {
        if (newATime[i] == '.')
        {
            throw "Invalid Arrival time integer only, Arrival time given:", newATime;
        }
    }

    if (testATime < 0)
    {
        throw "Invalid Arrival time positive numbers only time given: ", testATime;
    }
    arrivalTime = testATime;
}
void Process::SetArrivalTime(int newATime)
{
    if (newATime < 0)
    {
        throw "Invalid Arrival time positive numbers only time given: ", newATime;
    }
    arrivalTime = newATime;
}


int Process::GetMBytes()
{
    return mBytes;
}
void Process::SetMBytes(string newMem)
{
    int testMem;
    remove_if(newMem.begin(), newMem.end(), isspace);
    remove_if(newMem.begin(), newMem.end(), isalpha);
    for (int i = 0; i < newMem.size(); i++)
    {
        if (newMem[i] == '.')
        {
            throw "Invalid Memory can only be integer, memory given:", newMem;
        }
    }
    testMem = stoi(newMem);
    
    if (testMem < 0)
    {
        throw "Invalid Memory can only be positive numbers memory given: ", testMem;
    }
    mBytes = testMem;
}
void Process::SetMBytes(int newMem)
{
    if (newMem < 0)
    {
        throw "Invalid Memory can only be positive numbers memory given: ", newMem;
    }
    mBytes = newMem;
}