#pragma once
#include <string>

using namespace std;


class Resource
{
public:
	Resource();
	Resource(string);

	string GetResourceName();
	void SetResourceName(string);

	bool GetInUse();
	void SetInUse(bool);

	int GetProcessID();
	void SetProcessID(int);

private:
	int processID;
	string resourceName;
	bool InUse = false;

};

