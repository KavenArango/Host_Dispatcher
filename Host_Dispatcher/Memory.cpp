#include "Memory.h"
#include <iostream>
using namespace std;
void Memory::firstFit(int processID, int processSize)
{
    process.push_back(pair<int, int>(processID, processSize));
    int totalBlocks = sizeof(blockSize) / sizeof(blockSize[0]);
    const int totalProcess = process.size();
    int *allocation = new int[totalProcess];
    memset(allocation, -1, sizeof(allocation));
    //this for loop wll pick eact process and allocate a first fit block to it
    for (int i = 0; i < totalProcess; i++) {
        for (int j = 0; j < totalBlocks; j++) {
            if (blockSize[j] >= blockSize[i]) 
            {
                allocation[i] = j;
                blockSize[j] -= process[i].second;
                break;
            }
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < totalProcess; i++) {
        cout << " " << process[i].first << "\t\t" << process[i].second << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
    cout << blockSize[0] << endl;
}

void Memory::freeAllocation(int processID, int processSize)
{
    for (auto i : process)
    {
        if (i.first == processID && i.second == processSize)
        {
            blockSize[0] += i.second;
        }
    }
}
