#ifndef _HEALTH_H_
#define _HEALTH_H_
#include "Application.h"
#include "Component.h"
#include "Entity.h"
#include <algorithm>
#include <iterator>
#include <fstream>
#include <exception>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <sr1/memory>
#include "Camera.h"
#include <rend/rend.h>
#include "Collision.h"

/**
*Forward declare camera
*/
class Collision;
/**
*Represents the Health of the player
*/
class Health : public Component
{
	glm::vec4 pos; ///< Used to get the positions of the translations and scale models.
	std::sr1::shared_ptr<rend::Shader> shader; ///< Create a pointer to the shader.
	std::sr1::shared_ptr<rend::Mesh> mesh; ///< Create a pointer to the mesh.
	std::sr1::shared_ptr < rend::Texture> texture; ///< Create a pointer to the texture.
	std::vector <std::shared_ptr<rend::Texture>> health; ///< Create a vector of health of the player
	std::shared_ptr<Collision> col; ///< Create a pointer to the collision Class
public:

	int healthHit = 0; ///< Initialize the first number for the health hit. This will change when the correct number is passed through
	/**
	* \brief Set the GlAlphaFun and GLDepthTest. set the model matrix and set the
	* \brief Set the translations, scale and uniforms. Rend everything
	* \brief Create if statements to check if the game is paused or not and based on that display health bar
	*/
	void onDisplay();
	/**
	* \brief Used to be able to set the position of the animation from main
	*/
	void setPosition(glm::vec4 size);
	/**
	* \brief Get and load all of the textures that are passed in from main
	*/
	void rendTex(char* _tex);
	/**
	* \brief Get and load all of the textures that are passed in from main and the collision of the objects
	*/
	void RenderInitialise(char* _shader, std::shared_ptr<Collision> _col);
	/**
	* \brief Run every tick and check if the player has paused the game
	*/
	void onTick();
	int imgNum; ///< Create int for image number. this Sets which number in the vector to show for the health bar
	/**
	* \brief Get number from Collision file if the players have been hit and change it to the image number
	*/
	void onGetHit(int healthHit);
	bool gameKey = false; ///< Boolean to check if the right key has been pressed to unpause the game
	bool gamePause = false; ///< Checks if the right key has been pressed to pause the game
	int numb; ///< Create number to check if the right button on the controller has been pressed
	/**
	* \brief Get the input from the controller from application
	*/
	void getInputCont(int _num);

};

#endif