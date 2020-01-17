#ifndef _COLLISION_H_
#define _COLLISION_H_
#include "Component.h"
#include "Transform.h"
#include "Application.h"
#include "Entity.h"
#include "Health.h"
#include "Pause.h"
#include "GUI.h"
/**
*Forward declare
*/
class Health;
class Pause;
class GUI;

/**
*Represents all of the collision code. Creates collision boxes, checks for
*collisions and responds if there are collisions
*/
class Collision : public Component
{
		glm::vec3 size; ///< Create for size of the collision box
		glm::vec3 offset; ///< Create for the offset of the collision box
		glm::vec3 lastPos; ///< Create to set from the new position then to be used to create collsion box movement.
		/**
		* \brief Every tick check the collision box function if collision is detected
		*/
		void onTick();
	    std::shared_ptr<Health> hel; ///< Create a pointer to health
		std::shared_ptr<Pause> pau; ///< Create a  pointer to Pause
		/**
		* \brief Gets if there is collision and moves the object so they dont hit eachother
		*/
		glm::vec3 getCollision(glm::vec3 pos, glm::vec3 size); 

public:
		/**
		* \brief Initialise the initial size and offset 
		*/
		void onIni();
		/**
		* \brief Sets the offset of the collision box from main
		*/
		void setOffset(const glm::vec3 offset);
		/**
		* \brief Sets the size of the collision box from main
		*/
		void setSize(const glm::vec3 &size);
		/**
		* \brief Sets the players health number and passes it to the pause file
		*/
		void setHealth(std::shared_ptr<Health> _hel);
		/**
		* \brief Sets number if the player has paused the game
		*/
		void setPau(std::shared_ptr<Pause> _pau);
		bool hit = false; ///< checks if there is a collision, used for the health bar
		/**
		* \brief Returns bool if the object has been hit
		*/
		bool isHit();
		/**
		* \brief Gets the correct objects to be checked for collision and sets the positions if there has been collision
		*/
		int collisionBox(int &_isCol);
		int healthH = 0; ///< Passes in the health value of the player
			/**
		* \brief Checks the positions of the objects and if they are colliding
		*/
		bool isColliding(glm::vec3 pos, glm::vec3 size);
		bool isHittingnow = false; ///< Checks if the objects are currently colliding
		int healthInt = 6; ///< Sets the full health value
		int timer = 0; ///< Creates a timer. Cooldown between when the player is hit by object

};


#endif