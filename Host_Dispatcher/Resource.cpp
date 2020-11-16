#include "Resource.h"

Resource::Resource()
{
}

Resource::Resource(string newResourceName)
{
	resourceName = newResourceName;
}

string Resource::GetResourceName()
{
	return resourceName;
}

void Resource::SetResourceName(string newResourceName)
{
	resourceName = newResourceName;
}

bool Resource::GetInUse()
{
	return InUse;
}

void Resource::SetInUse(bool newInUse)
{
	InUse = newInUse;
	if (newInUse == false)
	{
		processID = NULL; // might not work 
	}
}


int Resource::GetProcessID()
{
	return processID;
}

void Resource::SetProcessID(int ID)
{
	processID = ID;
}
