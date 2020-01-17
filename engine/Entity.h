#ifndef _ENTITY_H_	
#define _ENTITY_H_

#include <memory>
#include "Application.h"
#include <vector>
/**
*Forward declare
*/
class Component;
class Application;

/**
*Represents the creation of entites and pushing them into vectors
*/
class Entity
{
	friend Application; ///< Make a friend of application so they can share information
	std::weak_ptr<Application> app; ///< create a weak pointer to application
	std::vector<std::shared_ptr<Component>> components; ///< Create a vector of componenets
	std::shared_ptr<Entity> self; ///< Create a shared pointer of self
	char* tag; ///< Create char used to name the entities
public:
	/**
	* \brief Create a template of get Component functions. Go through the componenet vector and return the one called
	*/
	template<class T>
	std::shared_ptr<T> getComponent()
	{
			std::shared_ptr<T> rtn;
			for (std::vector<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
			{
					rtn = std::dynamic_pointer_cast<T>(*it);

					if (rtn)
					{
							return rtn;
					}
					
			}
	}
	/**
	* \brief Create a template to check Componenets functions. Go through the componenet vector and return the one called
	*/
	template<class T>
	bool checkComponent()
	{
			std::shared_ptr<T> ret;
			for (std::vector<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
			{
					ret = std::dynamic_pointer_cast<T>(*it);

					if (ret)
					{
							return true;
					}

			}
			return false;
	}
	std::shared_ptr<Application> getApplication(std::shared_ptr<Application> _app); ///< get application
	/**
	* \brief Create a template to check Componenets functions. Go through the componenet vector and return the one called
	*/
	template<class T>
	std::shared_ptr<T> addComponent()
	{
		std::shared_ptr<T> ret = std::make_shared<T>();
		components.push_back(ret);
		ret->entity = self;
		ret->app = app;
		return ret;
	}
	/**
	* \brief Create a template to check Componenets functions. Go through the componenet vector and return the one called
	*/
	template<class T, class A>
	std::shared_ptr<T> addComponent(A a)
	{
		std::shared_ptr<T> ret = std::make_shared<T>(a);
		components.push_back(ret);
		ret->entity = self;
		ret->app = app;
		return ret;
	}
	/**
	* \brief Create a template to check Componenets functions. Go through the componenet vector and return the one called
	*/
	template<class T, class A, class B>
	std::shared_ptr<T> addComponent(A a, B b)
	{
		std::shared_ptr<T> ret = std::make_shared<T>(a,b);
		components.push_back(ret);
		ret->entity = self;
		ret->app = app;
		return ret;
	}
	/**
	* \brief Create a template to check Componenets functions. Go through the componenet vector and return the one called
	*/
	template<class T, class A, class B, class C>
	std::shared_ptr<T> addComponent(A a, B b, C c)
	{
		std::shared_ptr<T> ret = std::make_shared<T>(a,b,c);
		components.push_back(ret);
		ret->entity = self;
		ret->app = app;
		return ret;
	}

	/**
	* \brief Go through the component vector every tick
	*/
	void tick();
	/**
	* \brief Go through the component vector eve tick and display them
	*/
	void display();
	/**
	* \brief Set the tag of the entity
	*/
	void setTag(char* Tag);

};




#endif // ! _ENTITY_H_
