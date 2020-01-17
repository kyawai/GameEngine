#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <memory>
#include <iostream>
#include <glm/glm.hpp>
/**
*Forward declare
*/

class Application;
class Entity;
/**
*Represents the creation and setting of components
*/
class Component
{
	friend Entity; ///< Creates a friendship between entitiy and Component so they can talk to eachother and access eachothers variables and functions
	std::weak_ptr<Entity> entity; ///< Creates a weak pointer to entity

public:
	/**
	* \brief Changes entity to a strong pointer
	*/
	std::shared_ptr<Entity> getEntity();
	std::weak_ptr<Application> app; ///< Creates a weak pointer to the application.
	/**
	* \brief Initial functions that other functions from different files use
	*/
	virtual void onInit();
	/**
	* \brief Initial functions that other functions from different files use
	*/
	virtual void onBegin();
	/**
	* \brief Initial functions that other functions from different files use
	*/
	virtual void onTick();
	/**
	* \brief Initial functions that other functions from different files use
	*/
	virtual void onDisplay();
	/**
	* \brief Makes application a strong pointer
	*/
	std::shared_ptr<Application> getApp();

};



#endif // ! _COMPONENTS_H_
