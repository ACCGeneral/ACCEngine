#pragma once

#include <glm.hpp>
#include "glew.h"
#include <vector>
#include "shader.h"
#include <gtc/quaternion.hpp>
#include <gtx/quaternion.hpp>
#include "Light.h"
#include <memory>
#include "model.h"
#include "OBB.h"
#include "AABB.h"
#include "shadersettings.h"
#include "Sphere.h"
#include "sound.h"

//here is a list of all of our components that we need for the game and the demo. every component is based of the base class ACC:component 
//For use components only contain data while systems do the needed logic

namespace ACC 
{

	class entity;
 
	class component 
	{

	public:

		virtual int GetType() const = 0;
		
	};

}

// typeID is used for getting the component from the entity vector list

class transposecomponent : public ACC::component
{

public:

	static const int TypeID = 1;

	int GetType() const { return TypeID; };

  glm::mat4 modelMatrix;

  glm::vec3 position;

  glm::quat myquat;

  glm::quat animquat;

  glm::vec3 scale;

};



class directioncomponent : public ACC::component
{
 public:

	 static const int TypeID = 2;

	 int GetType() const  { return TypeID; };

   glm::vec3 direction;

   glm::vec3 newdirect;

};

class modelcomponent : public ACC::component
{
public:

	static const int TypeID = 3;

	int GetType() const { return TypeID; };

	std::shared_ptr<model> mymodel;
	std::shared_ptr<shader> myshader;
	std::unique_ptr<shadersettings> extra;

	bool drawme;
	bool effectedbylights;
	float mystrenght;
	float myshine;
	bool depth;

};


class lightcomp : public ACC::component
{
public:


	static const int TypeID = 4;

	int GetType() const { return TypeID; };

	std::shared_ptr<light> mylight;

};


class healthcomponent : public ACC::component
{

public:

	static const int TypeID = 5;

	float health;

	float maxhp;

	std::pair<bool,bool> hitdelete;

	int GetType() const { return TypeID; };

};

class animationholdercomp : public ACC::component
{

public:
	static const int TypeID = 6;

	enum type { light, trans };

	type mytype;

	std::shared_ptr<ACC::entity> myowner;

	glm::vec3 offset;

	int GetType() const { return TypeID; };

};


class physics : public ACC::component
{

public:

	static const int TypeID = 7;

	float mass;
	float maxvelocity;
	glm::vec3 velocity;
	float speed;
	float maxforce;
	glm::vec3 force;
	bool physicsobject;

	int GetType() const { return TypeID; };

};

class collisioncomp : public ACC::component
{

public:

	static const int TypeID = 8;

	std::vector<std::shared_ptr<OBB>> myobb;
	std::shared_ptr<AABB> myAABB;
	std::shared_ptr<sphere> mysphere;
	bool imstatic;
	bool physicseffected;
	std::vector<unsigned long int> dontcolwith;

	int GetType() const { return TypeID; };
};

class owner : public ACC::component
{

public:

	static const int TypeID = 9;
	std::shared_ptr<ACC::entity> myowner;

	int GetType() const
	{
		return TypeID;
	}

};

class thingsiown : public ACC::component
{

public:

	static const int TypeID = 10;

	std::vector<std::shared_ptr<ACC::entity>> stuffiown;

	int GetType() const
	{
		return TypeID;
	}

};


