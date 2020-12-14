#pragma once
#include "Resource.h"

#include <string>
#include <vector>

using namespace std;

class ResourceManager
{
public:
	ResourceManager();

	void SpawnResource(string);
	void AllocateResources(string, int,int);
	void DeAllocateResources(int);
	
	
	~ResourceManager()
	{

		resourceList.clear();
		resourceList.shrink_to_fit();
	}
private:
	vector<Resource*> resourceList;
	
	
	
	
};