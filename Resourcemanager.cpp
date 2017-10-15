#include "Resourcemanager.h"

Resourecmanager & Resourecmanager::instance() //get instance of our resource manager 
{
	static Resourecmanager myinstance;

	return myinstance;
}

std::shared_ptr<shader> Resourecmanager::getfromshadholder(std::string name) //get a shader 
{
	return shadholder.getshader(name);
}

std::shared_ptr<model> Resourecmanager::getfrommodelholder(std::string name) //get a model 
{
	return modholder.getmode(name);
}

AABB Resourecmanager::getAABB(std::string name) //get the aabb data for a model
{
	return modholder.getAABB(name);
}

OBB Resourecmanager::getOBBfrommodel(std::string name)
{
	return modholder.GetOBB(name);
}

sphere Resourecmanager::getsphere(std::string name)
{
	return modholder.getsphere(name);
}

std::vector<OBB> Resourecmanager::getOBB(std::string name)
{
	return myOBBholder.getOBB(name);
}

sound Resourecmanager::getsound(std::string name)
{
	return mysoundholder.getsound(name);
}

void Resourecmanager::addshader(std::shared_ptr<shader> newshader, std::string name) //add a new shader to the shader holder 
{
	shadholder.addshader(newshader, name);

}

void Resourecmanager::addmodels(std::string modelpath, std::string modelname) //add a normal model
{
	modholder.addmodel(modelpath, modelname);
}

void Resourecmanager::addskybox(std::vector<std::string> cube, std::string modelpath, std::string modelname) //add a skybox model
{
	modholder.addskybox(modelpath, cube, modelname);
}

void Resourecmanager::abbobb(std::string filename, std::string name)
{
	myOBBholder.addOBB(filename, name);
}

void Resourecmanager::addsound(sound newsound, std::string name)
{
	mysoundholder.addsound(newsound, name);
}

void Resourecmanager::modelsinit() //create all of our models that we might need 
{

}

void Resourecmanager::obbinit()
{

}

void Resourecmanager::shaderinit() //create all of our shaders that we might need 
{
	

}

void Resourecmanager::soundsinit()
{
	


}


