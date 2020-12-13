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
    int blockSize[1] = { 1024 };
    vector<pair<int, int>> process;

};