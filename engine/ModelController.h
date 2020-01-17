#ifndef _MODEL_CONTROLLER_H
#define _MODEL_CONTROLLER_H


#include "Component.h"
#include "Application.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/vec3.hpp>
#include "glm/gtx/string_cast.hpp"


/**
*Represents the Controls of the player
*/

class ModelController : public Component
{
		glm::vec3 posi; ///< get position of the player
		glm::mat4 view; ///< Create camera view.
		glm::mat4 projection; ///< Create camera projection.
		float angle; ///< Create cameras angle, used in rotation.
		glm::mat4 model; ///< Create a basic model to be filled in later
		int timer = 0; ///< Used to set the animation timer and how often the images will change.
public:
		/**
		* \brief Set the initial values before they are passed from main
		*/
		void modelIni();
		/**
		* \brief Return the view matrix
		*/
		glm::mat4 getViewModel();
		/**
		* \brief Return the position vector
		*/
		glm::vec3 modelPos();
		/**
		* \brief Return projection matrix
		*/
		glm::mat4 getModelProjection();
		/**
		* \brief Run function every tick. This function gets the keyboard state and
		* \brief Checks if the player needs to be moved and moves them
		*/
		void onTick();
		/**
		* \brief Set and return the model matrix
		*/
		glm::mat4 getModel();
		int numb; ///< number to check what way the player needs to move based on controller input
		/**
		* \brief Get the number from the controller input and set it
		*/
		void getInputCont(int _num);
};
#endif // ! _MODEL_CONTROLLER_H
