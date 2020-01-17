#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <memory>
#include <vector>
#include <list>
#include "SDL2/SDL.h"
#include <rend/rend.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/vec3.hpp>
#include "glm/gtx/string_cast.hpp"
#include <GL/glew.h>
#include <sr1/memory>
#include <vector>
#include "openAL/AL/al.h"
#include "openAL/AL/alc.h"
#include <cmath>
#include <glm/glm.hpp>
#include <iostream>
#include <GL/glew.h>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <exception>
#include <string>

#include "Transform.h"
#include "Entity.h"
#include "Component.h"
#include "Renderer.h"
#include "Audio.h"
#include "Collision.h"
#include "Health.h"
#include "ModelController.h"
#include "Pause.h"
#include "Camera.h"
#include "GUI.h"

/**
*Forward declare all of the classes as they will be used but later on in the program
*/

class Application;
class Entity;
class ModelController;
class Pause;
class Health;
class Camera;
/**
*Represents the core of the engine. This holds all of the information
*Snd the initialization of the SDL such as window.
*This also includes the main game loop. and Holds the movement inputs for controller
*/
class Application
{
	bool running; ///< Set the whole program as running.
	std::vector<std::shared_ptr<Entity>> entities; ///< Create a pointer to a vector of entities
	std::weak_ptr<Application> self; ///< Create a weak pointer to self
	std::shared_ptr<ModelController> mod; ///< Create a pointer to the Model Controller for controller input
	std::shared_ptr<Pause> pause; ///< Create pointer to the Pause file
	std::shared_ptr<Health> hel; ///< Create pointer to the Health file
	std::shared_ptr<Camera> cam; ///< Create pointer to the Camera file
	SDL_Window* window; ///< Create Window
	ALCdevice* device; ///< Create Sound
	ALCcontext* soundContext; ///< Create contest for the Sound file

public:
	std::sr1::shared_ptr<rend::Context> context; ///< Create a shared pointer to the context
	/**
	* \brief Start of the program. Creates window and Controller and all of the contexts
	*/
	static std::shared_ptr<Application> Initialize(); 
	/**
	* \brief Main game loop. Has the event system and the controller inputs along with FPS controller
	* \brief Also sets up the window to be rendered then rendered the whole window
	*/
	void Run();
	/**
	* \brief Function to push any entities that are added into a vector of entities
	*/
	std::shared_ptr<Entity> AddEntity(); 
	/**
	* \brief Get the number passed in from main and set it
	*/
	void setCon(std::shared_ptr<ModelController> _mod);
	/**
	* \brief Get the number passed in from main and set it
	*/
	void setPause(std::shared_ptr<Pause> _p);
	/**
	* \brief Get the number passed in from main and set it
	*/
	void setHel(std::shared_ptr<Health> _h);
	/**
	* \brief Get the number passed in from main and set it
	*/
	void setCam(std::shared_ptr<Camera> _c);
	/**
	* \brief Stop running the program
	*/
	void Stop();
	/**
	* \brief Destructor for the application
	*/
	~Application();
	int num; ///< Number, used to see which button of the controller was pressed and pass it into different files
	float lastTime; ///< Used in the making of the FPS limiter
	float time; ///< Used in the making of the FPS limiter
	float diff; ///< Used in the making of the FPS limiter
	float deltaTime; ///< Used in the making of the FPS limiter
	float idealTime; ///< Used in the making of the FPS limiter

	/**
	* \brief A template iterator that pushes all of the entities added into a new vector then returns the vector 
	* \brief when called. Used from other files
	*/
	template<class T>
	std::vector<std::shared_ptr<Entity>> getEntities()
	{
			bool ret;
			std::vector<std::shared_ptr<Entity>> retVec;
			for (std::vector<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
			{
					ret = (*it)->checkComponent<T>();
					if (ret)
					{
							retVec.push_back(*it);
					}

			}
			return retVec;
	}
};

#endif // !_APPLICATION_H_
