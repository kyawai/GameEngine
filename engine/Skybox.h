#ifndef  _SKYBOX_H_
#define _SKYBOX_H_
#include <gl/glew.h>
#include <string>
#include <stb_image.h>
#include <iostream>
#include "Application.h"
/**
*Represents the Skybox
*/
class Skybox : public Component
{
		std::shared_ptr<Camera> cam;  ///< Create a shared pointer to the camera
public:
		/**
		* \brief Get the camera from main
		*/
		void SkyboxInitialize(std::shared_ptr<Camera> _cam);
		/**
		* \brief Set the position of the skybox relative to where the camera is
		*/
		virtual void onTick();
};




#endif // ! _SKYBOX_DEFINE_
