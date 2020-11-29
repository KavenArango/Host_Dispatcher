#include "Process.h"

Process::Process()
{}
Process::Process(int aTime,int pri, float pTime, int mem, int newPrint, int newScanner, int newModem, int newCDs)
{
    SetPriority(pri);
    SetProcessTime(pTime);
    SetArrivalTime(aTime);
    SetMBytes(mem);

    SetPrintersNeeded(newPrint);
    SetScannersNeeded(newScanner);
    SetModemsNeeded(newModem);
    SetCDsNeeded(newCDs);
}
Process::Process(string aTime, string pri, string pTime, string mem, string newPrint, string newScanner, string newModem, string newCDs)
{
    SetPriority(pri);
    SetProcessTime(pTime);
    SetArrivalTime(aTime);
    SetMBytes(mem);

    SetPrintersNeeded(newPrint);
    SetScannersNeeded(newScanner);
    SetModemsNeeded(newModem);
    SetCDsNeeded(newCDs);
}
Process::~Process()
{}



string Process::RemoveSpaceAndAlpha(string word)
{
    remove_if(word.begin(), word.end(), isspace);
    remove_if(word.begin(), word.end(), isalpha);
    return word;
}
bool Process::CheckIfInt(string testInt)
{
    for (int i = 0; i < testInt.size(); i++)
    {
        if (testInt[i] == '.')
        {
            return true;
        }
    }
    return false;
}



int Process::GetModemsNeeded()
{
    return modems;
}
void Process::SetModemsNeeded(string newModem)
{
    int test;
    newModem = RemoveSpaceAndAlpha(newModem);
    if (CheckIfInt(newModem))
    {
        throw "Invalid Modems used, Modems must be an integer, Modems given: ", newModem;
    }
    if (newModem.size() == 0)
    {
        throw "Invalid Modems used Modems used may not be null Modems given: ", newModem;
    }
    test = stoi(newModem);
    if (test < 0)
    {
        throw "Invalid Modems used Modems must be 0 or more, Modems given: ", newModem;
    }
    modems = test;
}
void Process::SetModemsNeeded(int newModem)
{
    if (newModem < 0)
    {
        throw "Invalid Modems used Modems must be 0 or more, Modems given: ", newModem;
    }
    modems = newModem;
}



int Process::GetCDsNeeded()
{
    return CDs;
}
void Process::SetCDsNeeded(string newCDs)
{
    int test;
    newCDs = RemoveSpaceAndAlpha(newCDs);
    if (CheckIfInt(newCDs))
    {
        throw "Invalid CDs used, CDs must be an integer, CDs given: ", newCDs;
    }
    if (newCDs.size() == 0)
    {
        throw "Invalid CDs used CDs used may not be null CDs given: ", newCDs;
    }
    test = stoi(newCDs);
    if (test < 0)
    {
        throw "Invalid CDs used CDs must be 0 or more, CDs given: ", newCDs;
    }
    CDs = test;
}
void Process::SetCDsNeeded(int newCDs)
{
    if (newCDs < 0)
    {
        throw "Invalid Modems used Modems must be 0 or more, Modems given: ", newCDs;
    }
    CDs = newCDs;
}



int Process::GetScannersNeeded()
{
    return scanners;
}
void Process::SetScannersNeeded(string newScan)
{
    int testPri;
    newScan = RemoveSpaceAndAlpha(newScan);
    if (CheckIfInt(newScan))
    {
        throw "Invalid Scanners used, scanners must be an integer, Scanners given: ", newScan;
    }
    if (newScan.size() == 0)
    {
        throw "Invalid Scanners used scanners used may not be null Scanners given: ", newScan;
    }
    testPri = stoi(newScan);
    if (testPri < 0)
    {
        throw "Invalid printers used printers must be 0 or more, printers given: ", testPri;
    }
    scanners = testPri;
}
void Process::SetScannersNeeded(int newScan)
{
    if (newScan < 0)
    {
        throw "Invalid printers used printers must be 0 or more, printers given: ", newScan;
    }
    scanners = newScan;
}



int Process::GetPrintersNeeded()
{
    return printers;
}
void Process::SetPrintersNeeded(string newPrint)
{
    int testPri;
    newPrint = RemoveSpaceAndAlpha(newPrint);
    
    if (CheckIfInt(newPrint))
    {
        throw "Invalid printers used, printers must be an integer, printers given: ", newPrint;
    }
    if (newPrint.size() == 0)
    {
        throw "Invalid printers used printers used may not be null printers given: ", newPrint;
    }

    testPri = stoi(newPrint);
    if (testPri < 0)
    {
        throw "Invalid printers used printers must be 0 or more, printers given: ", testPri;
    }
    printers = testPri;
}
void Process::SetPrintersNeeded(int newPrint)
{
    if (newPrint < 0)
    {
        throw "Invalid printers used printers must be 0 or more, printers given: ", newPrint;
    }
    printers = newPrint;
}



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
    newPri = RemoveSpaceAndAlpha(newPri);
    
    if (CheckIfInt(newPri))
    {
        throw "Invalid priortiy integer only, priority given:", newPri;
    }
    
    testPri = stoi(newPri);
    if (testPri < 0 )
    {
        throw "Invalid priortiy must be a positive integer: ", testPri;
    }
        priority = testPri;
}
void Process::SetPriority(int newPriority)
{
    if (newPriority < 0)
    {
        throw "Invalid priortiy must be a positive integer: ", newPriority;
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
    newPTime = RemoveSpaceAndAlpha(newPTime);
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
    newATime = RemoveSpaceAndAlpha(newATime);
    testATime = stoi(newATime);
    

    if (CheckIfInt(newATime))
    {
        throw "Invalid Arrival time integer only, Arrival time given:", newATime;
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
    newMem = RemoveSpaceAndAlpha(newMem);
    
    if (CheckIfInt(newMem))
    {
        throw "Invalid Memory can only be integer, memory given:", newMem;
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