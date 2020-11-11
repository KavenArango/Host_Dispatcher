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
    string processInfo[4];
    int j = 0;
    Process* tempNode = new Process();
    for (int i = 0; i <= line.length(); i++)
    {
        if (line[i] == ' ')
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
    return tempNode;
}