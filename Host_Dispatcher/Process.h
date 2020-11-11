#pragma once

#include <string>
using namespace std;
class Process
{
public:

	Process();
	Process(int, float, int, int);
	

	
	int GetPriority();
	void SetPriority(string);
	void SetPriority(int);
	

	
	float GetProcessTime();
	void SetProcessTime(string);
	void SetProcessTime(float);
	

	
	int GetArrivalTime();
	void SetArrivalTime(string);
	void SetArrivalTime(int);

	
	int GetMBytes();
	void SetMBytes(string);
	void SetMBytes(int);
	
	int GetID();
	void SetID(int);
	
	~Process();
private:
	int ID;
	int priority;
	float processTime;
	int arrivalTime;
	int mBytes;



};

