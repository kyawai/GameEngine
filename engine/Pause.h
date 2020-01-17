#ifndef _PAUSE_H_
#define _PAUSE_H_
#include "Component.h"
#include "Application.h"
#include <rend/rend.h>
#include <sr1/memory>
#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>
#include "GUI.h"
#include "Pause.h"
#include "GUI.h"
/**
*Forward declare camera
*/
class GUI;
class Camera;
/**
*Represents the pause screen of the game
*/
class Pause : public Component
{
	glm::vec4 pos; ///< Used to get the positions of the translations and scale models.
	std::sr1::shared_ptr<rend::Shader> shader; ///< Create a pointer to the shader.
	std::sr1::shared_ptr<rend::Mesh> mesh; ///< Create a pointer to the mesh.
	std::sr1::shared_ptr < rend::Texture> texture; ///< Create a pointer to the texture.
	int currImg; ///< Get the current image, used in the imgs vector.
	int time = 0; ///< Used to set the animation timer and how often the images will change.
	std::vector<std::shared_ptr<rend::Texture>> imgs; ///< Create a vector of textures for the pause screen animation
public:
	/**
	* \brief Get and load all of the textures that are passed in from main
	*/
	void rendTex(char* _tex);
	/**
	* \brief Get and load in the shader from main. Also initialize the camera pointer
	*/
	void RenderInitialise(char* _shader);
	/**
	* \brief Used to be able to set the position of the animation from main
	*/
	void setPosition(glm::vec4 _size);
	/**
	* \brief Run through the loop every tick. This function creates a timer controlling
	* \brief How quickly the animation plays. It also sets the images to the current ones in the frame
	*/
	void onTick();
	/**
	* \brief Set the GlAlphaFun and GLDepthTest. set the model matrix and set the
	* \brief Set the translations, scale and uniforms. Rend everything. Check if the game has been paused
	*/
	void onDisplay();
	bool change = false; ///< Used to check if the image of the animation has to be changed to the next frame.
	bool gameKey = false; ///< Checks if the game has been paused
	bool gameUnPause = true; ///< Checks if the game has been unpaused
	void onGetHit(int _hitNum); ///< Gets the value from the collision. If the player is dead show the pause screen
	int numb; ///< Gets the number for controller input
	/**
	* \brief Gets the number from the controller input
	*/
	void getInputCont(int _num);
	int hitNum; ///< Get the number to check when the player has died 
};

#endif