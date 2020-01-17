#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Component.h"
#include "Application.h"
#include "Renderer.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/vec3.hpp>
#include "glm/gtx/string_cast.hpp"
#include <cmath>
#include "Pause.h"

/**
*Represents the Camera file. creates the camera and sets it's values
*/
class Camera : public Component
{
		glm::vec3 posi; ///< Create camera position.
		glm::mat4 view; ///< Create camera view.
		glm::mat4 projection; ///< Create camera projection.
		float angle; ///< Create cameras angle, used in rotation.
		glm::mat4 model;  
public:
		/**
		* \brief Create camera constructor
		*/
		Camera();
		/**
		* \brief Create camera destructor
		*/
		~Camera();
		/**
		* \brief Run when camera is initialised in main. pass in angle that is set in main
		*/
		void CamIni(float _angle);
		/**
		* \brief Return the view matrix
		*/
		glm::mat4 getView();
		/**
		* \brief Return the position vector
		*/
		glm::vec3 GetPos();
		/**
		* \brief Return projection matrix
		*/
		glm::mat4 getProjection();
		/**
		* \brief Run function every tick. This function gets the keyboard state and 
		* \brief Checks if the camera needs to rotate based on player movement
		*/
		void Camera::onTick();
		/**
		* \brief Set and return the model matrix
		*/
		glm::mat4 GetModel();
		int numb; ///< number that is got from Application to check if the rotation of the camera is needed.
		/**
		* \brief Set the local number to the number that has been passed through from the application
		*/
		void getInputCont(int _num);
};

#endif

