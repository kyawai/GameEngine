#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "Component.h"
#include <glm/gtx/transform.hpp>
/**
*Represents the main transform functions of the project. Does all of the transform maths
*/
class Transform : public Component
{
		glm::vec3 scale; ///< Creates the scale vector
		float rotY; ///< Create Y rotation float
		float rotX; ///< Create X rotation float
		float rotZ; ///< Create Z rotation float


public:
		glm::mat4 model; ///< create the model
		/**
		* \brief Transform destructor
		*/
		~Transform();
		/**
		* \brief Transform constructor
		*/
		Transform();
		/**
		* \brief Set and return the model matrix
		*/
		glm::mat4 GetModel();
		glm::vec3 pos; ///< Create camera position.
		/**
		* \brief Return the position vector
		*/
		glm::vec3 getPos();
		/**
		* \brief Set the position that has been changed from main
		*/
		void SetPos(glm::vec3 _pos);
		/**
		* \brief Add the position to the current position
		*/
		void AddPos(glm::vec3 _pos);
		/**
		* \brief Get rotation from main
		*/
		float GetRotation();
		/**
		* \brief Set the new rotation
		*/
		void SetRotation(float _rotY, float _rotX, float _rotZ);
		/**
		* \brief Add rotation to the current rotation
		*/
		void AddRotation(float _rotY, float _rotX, float _rotZ);
		/**
		* \brief get the scale from main
		*/
		glm::vec3 getScale();
		/**
		* \brief Set scale
		*/
		void SetScale(glm::vec3 _scale);


};


#endif // ! _TRANSFORM_H_

