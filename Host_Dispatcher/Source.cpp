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
        processManager->AddProcess(currentProcess);
        currentProcess = nullptr;
    }






	return 0;
}


Process* MakeProcess(string line)
{
    string info;
    Process* tempNode = new Process();
    for (int i = 0; i <= line.length(); i++)
    {
        if (line[i] == ' ')
        {
            if (info != "")
            {
                
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