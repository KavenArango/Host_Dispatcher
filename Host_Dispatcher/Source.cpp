#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include "Process.h"
#include "ProcessManager.h"

using namespace std;

Process* MakeProcess(string);


int main()
{
    Process* currentProcess = new Process();
    ProcessManager* processManager = new ProcessManager();
	string line;
	ifstream inFile;
	inFile.open("processes.txt");
	if (!inFile) 
	{
		cout << "Error opening file" << endl;
		return 1; 
	}

    while (getline(inFile, line))
    {
        currentProcess = MakeProcess(line);
        processManager->AddProcess(currentProcess);// this should start a thread in the p-man
        currentProcess = nullptr;
    }
    //after done reading main thread should wait for spawned thread here to finish processing
	return 0;
}

// arrival time, priority, processor time, mbytes, #printers, #scanners, #modems, #CDs
Process* MakeProcess(string line)
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
    Process* tempNode = new Process(processInfo[0], processInfo[1], processInfo[2], processInfo[3], processInfo[4], processInfo[5], processInfo[6], processInfo[7]);
    return tempNode;
}