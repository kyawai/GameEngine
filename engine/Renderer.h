#ifndef _RENDERER_H_
#define _RENDERER_H_

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
*Represents the main, basic renderer of the program
*/
class Renderer : public Component
{
	std::sr1::shared_ptr<rend::Shader> shader; ///< Create a pointer to the shader.
	std::sr1::shared_ptr<rend::Mesh> mesh; ///< Create a pointer to the mesh.
	std::sr1::shared_ptr < rend::Texture> texture; ///< Create a pointer to the texture.
	std::sr1::shared_ptr<Camera> camera; ///< Create a shared pointer to the camera
public:
	/**
	* \brief Renderer constructor
	*/
	Renderer();
	/**
	* \brief Renderer destructor
	*/
	~Renderer();
	/**
	* \brief Set the model matrix
	* \brief Set the translations, scale and uniforms. Rend everything
	*/
	void onDisplay();
	/**
	* \brief Get and load the shader, the model
	* \brief Texture and the camera
	*/
	void RenderInitialise(char* _shader, char* _model, char* _texture, std::shared_ptr<Camera> _camera);;
};

#endif