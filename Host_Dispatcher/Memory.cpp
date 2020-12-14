#include "Memory.h"
#include <iostream>
using namespace std;
Memory::Memory()
{
}
void Memory::firstFit(int processID, int processSize)
{
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    const int n = sizeof(processSize) / sizeof(processSize);

    int* allocation = new int[n];


    memset(allocation, -1, sizeof(allocation));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize)
            {
                allocation[i] = j;
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

