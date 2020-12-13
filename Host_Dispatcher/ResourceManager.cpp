#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	SpawnResource("Printer");
	SpawnResource("Scanner");
	SpawnResource("Modems");
	SpawnResource("CD");
}

void ResourceManager::SpawnResource(string newResourceName)
{
	Resource* resource = new Resource(newResourceName);
	resourceList.push_back(resource);
	resource = nullptr;
}

void ResourceManager::AllocateResources(string resourceName, int numOfResources, int ID)
{
	vector<int> resourcesUsedForThisRun;
	bool resourceFound = false;
	for (int i = 0; i < resourceList.size(); i++)
	{
		if (resourceList[i]->GetResourceName() == resourceName)
		{
			resourceFound = true;
			if (resourceList[i]->GetInUse() == false)
			{
				resourceList[i]->SetInUse(true);
				resourceList[i]->SetProcessID(ID);
				numOfResources--;
				resourcesUsedForThisRun.push_back(i);
				if (numOfResources == 0);
				{
					break;
				}
			}
		}
	}
	if (resourceFound == false)
	{
		throw "Resource Requested Does Not Exist";
	}
	else
	{
		if (numOfResources > 0)
		{
			for (int i = 0; i < resourcesUsedForThisRun.size(); i++)
			{
				resourceList[resourcesUsedForThisRun[i]]->SetInUse(false);
			}
			throw "Number of resources Requested out number resources availble";
		}
	}
}

void ResourceManager::DeAllocateResources(string resourceName, int ID)
{
	for (int i = 0; i < resourceList.size(); i++)
	{
		if (resourceList[i]->GetProcessID() == ID)
		{
			if (resourceList[i]->GetResourceName() == resourceName)
			{
				resourceList[i]->SetInUse(false);
			}
		}
	}
}
