#pragma once

#include "entity.h"
#include "ID_manager.h"
#include "dirlight.h"

#include <gtc/matrix_transform.hpp> 
#include <memory>
#include "Resourcemanager.h"
#include <unordered_map>
#include "orthographicsettings.h"


// the entity manager for creating and holding entities
class entitymanager
{
private:
	ID_manager IDs;

	std::unordered_map<unsigned long int,std::shared_ptr<ACC::entity>> entities;
	std::vector<std::shared_ptr<ACC::entity>> tooadd;
	std::vector<std::shared_ptr<ACC::entity>> todelete;

public:

	
	entitymanager();

	void delete_entity();

	std::vector<std::shared_ptr<ACC::entity>> returntoadd()
	{
		return tooadd;
	}

	std::vector<std::shared_ptr<ACC::entity>> returntodelete()
	{
		return todelete;
	}

	void cleartoadd()
	{
		tooadd.clear();
	}

	void cleartodelete();

   std::unordered_map<unsigned long int,std::shared_ptr<ACC::entity>> returnentities() // return all our entites
   {
	  return entities;
   }

   std::shared_ptr<ACC::entity> getentfromid(unsigned long int ID)
   {
	   return entities[ID];
   }

   void addtodeletelist(std::shared_ptr<ACC::entity> deleteme)
   {
	   deleteme->setdeleteme();
	   todelete.push_back(deleteme);
   }

};
