#include "Memory.h"
#include <iostream>
using namespace std;
Memory::Memory()
{
}
void Memory::firstFit(int processID, int processSize)
{
    //process.push_back(pair<int, int>(processID, processSize));
    //int totalBlocks = sizeof(blockSize) / sizeof(blockSize[0]);
    //const int totalProcess = sizeof(processSize) / sizeof(processSize);
    //numofprocesses++;
    //int *allocation = new int[totalProcess];

    //memset(allocation, -1, sizeof(allocation));
    ////this for loop wll pick eact process and allocate a first fit block to it
    //for (int i = 0; i < totalProcess; i++) {
    //    for (int j = 0; j < totalBlocks; j++) {
    //        if (blockSize[j] >= blockSize[i]) 
    //        {
    //            allocation[i] = j;
    //            blockSize[j] -= process[i].second;
    //            break;
    //        }
    //    }
    //}

    //cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    //for (int i = 0; i < numofprocesses; i++) {
    //    cout << " " << process[i].first << "\t\t" << process[i].second << "\t\t";
    //    if (allocation[i] != -1)
    //    {
    //        cout << allocation[i] + 1;
    //    }
    //    else
    //    {
    //        cout << "Not Allocated";
    //    }
    //    cout << endl;
    //}


    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    const int n = sizeof(processSize) / sizeof(processSize);


    // Stores block id of the  
    // block allocated to a process 
    int *allocation = new int[n];

    // Initially no block is assigned to any process 
    memset(allocation, -1, sizeof(allocation));

    // pick each process and find suitable blocks 
    // according to its size ad assign to it 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize)
            {
                // allocate block j to p[i] process 
                allocation[i] = j;

                // Reduce available memory in this block. 
                blockSize[j] -= processSize;

                break;
            }
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t"
            << processSize << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }














}

void Memory::freeAllocation(int processID, int processSize)
{
    int n = sizeof(processSize) / sizeof(processSize);
    int m = sizeof(blockSize) / sizeof(blockSize[0]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize)
            {
                blockSize[j] += processSize;
                break;
            }
        }
    }
}

