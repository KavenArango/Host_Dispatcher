#include <iostream>
#include <fstream>
#include <string>

#include "Process.h"
#include "ProcessManager.h"

using namespace std;

shared_ptr<Process> MakeProcess(string);


int main()
{
    int badProcesses = 0;
    shared_ptr<Process> currentProcess = shared_ptr<Process>(new Process());
    shared_ptr<ProcessManager> processManager = shared_ptr<ProcessManager>(new ProcessManager());
    
	string line;
	ifstream inFile;
	inFile.open("Processes.txt");
	if (!inFile) 
	{
		cout << "Error opening file" << endl;
		return 1; 
	}
    while (getline(inFile, line))
    {
        try
        {
            currentProcess = MakeProcess(line);
            processManager->AddProcess(currentProcess);
            currentProcess = nullptr;
        }
        catch (const std::invalid_argument& ia)
        {
            cout << ia.what() << endl;
            badProcesses++;
            continue;
        }
    }
    processManager->RunProcesses();
    //processManager->print();
    cout << "num of Bad processes: " << badProcesses << endl;
	return 0;
}

// arrival time, priority, processor time, mbytes, #printers, #scanners, #modems, #CDs
shared_ptr<Process> MakeProcess(string line)
{
    string info;
    string processInfo[8];
    int j = 0;
    for (int i = 0; i <= line.length(); i++)
    {
        if (line[i] == ' ' || i == line.length())
        {
            if (info != "")
            {
                processInfo[j] = info;
                j++;
                info = "";
            }
        }
        else
        {
            if (line[i] != ',')
            {
                info += line[i];
            }
        }
    }
    shared_ptr<Process> tempNode(new Process(processInfo[0], processInfo[1], processInfo[2], processInfo[3], processInfo[4], processInfo[5], processInfo[6], processInfo[7]));
    return tempNode;
}