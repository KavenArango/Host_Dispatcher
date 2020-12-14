#pragma once

#include <string>
using namespace std;
class Process
{
public:

	Process();
	Process(int, int, int, int, int, int, int, int);
	Process(string, string, string, string, string, string, string, string);

	
	int GetPriority();
	void SetPriority(string);
	void SetPriority(int);
	
	
	int GetProcessTime();
	void SetProcessTime(string);
	void SetProcessTime(int);
	

	
	int GetArrivalTime();
	void SetArrivalTime(string);
	void SetArrivalTime(int);

	
	int GetMBytes();
	void SetMBytes(string);
	void SetMBytes(int);
	
	int GetID();
	void SetID(int);

	
	int GetPrintersNeeded();
	void SetPrintersNeeded(string);
	void SetPrintersNeeded(int);

	
	int GetScannersNeeded();
	void SetScannersNeeded(string);
	void SetScannersNeeded(int);


	int GetModemsNeeded();
	void SetModemsNeeded(string);
	void SetModemsNeeded(int);

	int GetCDsNeeded();
	void SetCDsNeeded(string);
	void SetCDsNeeded(int);
	
	~Process();
private:
	string RemoveSpaceAndAlpha(string);
	bool CheckIfInt(string);
	int ID;
	int arrivalTime;
	int priority;
	float processTime;
	int mBytes;

	int printers;
	int scanners;
	int modems;
	int CDs;

};

