#ifndef _ANIM_MODEL_H_
#define _ANIM_MODEL_H_
#include "Application.h"

/**
*Forward declare camera
*/
class Camera;

/**
*Represents the Animation class for the main character
*/
class AnimModel : public Component
{
	glm::vec4 pos; ///< Used to get the positions of the translations and scale models.
	std::sr1::shared_ptr<rend::Shader> shader; ///< Create a pointer to the shader.
	std::sr1::shared_ptr<rend::Mesh> mesh; ///< Create a pointer to the mesh.
	std::sr1::shared_ptr < rend::Texture> texture; ///< Create a pointer to the texture.
	int currImg; ///< Get the current image, used in the imgs vector.
	int time = 0; ///< Used to set the animation timer and how often the images will change.
	std::vector<std::shared_ptr<rend::Mesh>> models; ///< Create a vector of models for the 3D animation
	std::vector<std::shared_ptr<rend::Texture>> texs; ///< Create a vector of textures to texture all of the objects in the animation
	std::sr1::shared_ptr<Camera> camera; ///< Create a pointer to the Camera.
public:
	/**
	* \brief Get and load all of the textures that are passed in from main
	*/
	void rendTex(char* _tex);
	/**
	* \brief Get and load in the shader from main. Also initialize the camera pointer
	*/
	void RenderInitialise(char* _shader, std::shared_ptr<Camera> _camera);
	/**
	* \brief Get and load all of the models that are passed in from main
	*/
	void renderMesh(char * _mesh);
	/**
	* \brief Used to be able to set the position of the animation from main
	*/
	void setPosition(glm::vec4 _size);
	/**
	* \brief Run through the loop every tick. This function creates a timer controlling
	* \brief How quickly the animation plays. It also sets the model mesh to the current frame and the texture
	*/
	void onTick();
	/**
	* \brief Set the GlAlphaFun and GLDepthTest. set the model matrix and set the
	* \brief Set the translations, scale and uniforms. Rend everything
	*/
	void onDisplay();
	bool change = false; ///< Used to check if the image of the animation has to be changed to the next frame.

};
#endif