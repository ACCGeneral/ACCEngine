#include "entitymanager.h"

//we assign components to our needed entities 

entitymanager::entitymanager()
{
	
}

void entitymanager::delete_entity()
{
	entities.clear();
	tooadd.clear();
	todelete.clear();
}


void entitymanager::cleartodelete() //delete all entities we no longer need 
{
	for (int i = 0; i < todelete.size(); i++)
	{
		std::unordered_map<unsigned long int, std::shared_ptr<ACC::entity>>::const_iterator got = entities.find(todelete[i]->returnID());
		if (got != entities.end())
		{
			entities[todelete[i]->returnID()]->setdeleteme();
		}
		entities.erase(todelete[i]->returnID());
		todelete.erase(todelete.begin() + i);
		i--;
	}
	todelete.clear();
}