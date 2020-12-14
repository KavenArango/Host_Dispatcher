#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Memory
{
public:

    Memory();
    void firstFit(int processID, int processSize);
    void freeAllocation(int processID, int processSize);

private:
    int blockSize[6] = { 1024, 1024, 1024,1024,1024,1024 };
    vector<pair<int, int>> process;
    int numofprocesses = 0;
};