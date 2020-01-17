#ifndef  _GUI_H_
#define _GUI_H_

#include "Component.h"
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <sr1/memory>
#include "Camera.h"
#include <rend/rend.h>
/**
*Forward declare camera
*/
class Camera;
/**
*Represents the GUI 
*/
class GUI : public Component
{
		glm::vec4 pos; ///< Used to get the positions of the translations and scale models.
		std::sr1::shared_ptr<rend::Shader> shader; ///< Create a pointer to the shader.
		std::sr1::shared_ptr<rend::Mesh> mesh; ///< Create a pointer to the mesh.
		std::sr1::shared_ptr < rend::Texture> texture; ///< Create a pointer to the texture.
public:
		std::vector<std::shared_ptr<GUI>> health; ///< Create a vector of players health
		/**
		* \brief GUI constructor
		*/
		GUI();
		/**
		* \brief GUI destructor
		*/
		~GUI();
		/**
		* \brief Set the GlAlphaFun and GLDepthTest. set the model matrix and set the
		* \brief Set the translations, scale and uniforms. Rend everything
		*/
		void onDisplay();
		/**
		* \brief Get and load all of the textures that are passed in from main
		*/
		void RenderInitialise(char* _shader, char* _texture);
		/**
		* \brief Used to be able to set the position of the GUI image
		*/
		void setPosition(glm::vec4 size);
};

#endif // ! _GUI_H_
