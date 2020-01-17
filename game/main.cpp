#include <iostream>
#include <memory>

#include <engine/Application.h>
#include <engine/Component.h>
#include <engine/Entity.h>
#include <engine/Renderer.h>
#include <engine/Transform.h>
#include <engine/PBR.h>
#include <engine/Skybox.h>
#include <engine/ModelController.h>
#include <engine/Collision.h>
#include <engine/GUI.h>
#include <engine/Pause.h>
#include <engine/AnimModel.h>

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 1020

int main()
{
		//initialize application
		std::shared_ptr<Application> app = Application::Initialize();

		//get all of the entities needed
		std::shared_ptr<Entity> cameraEnt = app->AddEntity();
		std::shared_ptr<Entity> buttonEnt = app->AddEntity();
		std::shared_ptr<Entity> conEnt = app->AddEntity();
		std::shared_ptr<Entity> pauseEnt = app->AddEntity();
		std::shared_ptr<Entity> guiEnt = app->AddEntity();
		std::shared_ptr<Entity> charEnt = app->AddEntity();
		std::shared_ptr<Entity> rockEnt = app->AddEntity();
		std::shared_ptr<Entity> ent = app->AddEntity();

		//tag all of the entities for debugging
		cameraEnt->setTag("CAMERA");
		buttonEnt->setTag("GUI1");
		conEnt->setTag("GUI2");
		pauseEnt->setTag("PAUSE");
		guiEnt->setTag("GUI");
		charEnt->setTag("CHAR");
		rockEnt->setTag("ROCK");

		//get transforms for entities if needed
		std::shared_ptr<Transform> cameraTransform = cameraEnt->addComponent<Transform>();
		std::shared_ptr<Transform> buttonTran = buttonEnt->addComponent<Transform>();
		std::shared_ptr<Transform> conTran = conEnt->addComponent<Transform>();
		std::shared_ptr<Transform> charTran = charEnt->addComponent<Transform>();
		std::shared_ptr<Transform> transform = ent->addComponent<Transform>();
		std::shared_ptr<Transform> rockTran = rockEnt->addComponent<Transform>();

		//get Renderers
		std::shared_ptr<Renderer> rend = ent->addComponent<Renderer>();
			std::shared_ptr<Renderer> rockRend = rockEnt->addComponent<Renderer>();

		//get camera for entities if needed
		std::shared_ptr<Camera> camera = cameraEnt->addComponent<Camera>();

		//get GUI for entities if needed
		std::shared_ptr<GUI> buttonRend = buttonEnt->addComponent<GUI>();
		std::shared_ptr<GUI> conRend = conEnt->addComponent<GUI>();

		//get Health for entities if needed
		std::shared_ptr<Health> guiRend = guiEnt->addComponent<Health>();

		//get Pause for entities if needed
		std::shared_ptr<Pause> pauseRend = pauseEnt->addComponent<Pause>();

		//get Model Controller if needed
		std::shared_ptr<ModelController> charCont = charEnt->addComponent<ModelController>();

		//get Animation model if needed
		std::shared_ptr<AnimModel> charRend = charEnt->addComponent<AnimModel>();

		//get Collision if needed
		std::shared_ptr<Collision> charCol = charEnt->addComponent<Collision>();
		std::shared_ptr<Collision> rockCol = rockEnt->addComponent<Collision>();

		//get Skybox if needed
		std::shared_ptr<Skybox> skybox = ent->addComponent<Skybox>();

		//do Initialize : mixed
		buttonRend->RenderInitialise("../shaders/GUI.txt", "../models/controlls.png");
		conRend->RenderInitialise("../shaders/GUI.txt", "../models/cont.png");
		rockRend->RenderInitialise("../shaders/basicShader.txt", "../models/rock.obj", "../models/rock.png", camera);
		guiRend->RenderInitialise("../shaders/GUI.txt", charCol);
		rend->RenderInitialise("../shaders/basicShader.txt", "../models/Skybox.obj", "../models/space.png", camera);

		//do Initialise : models
		charRend->renderMesh("../models/char/mod1.obj");
		charRend->renderMesh("../models/char/mod2.obj");
		charRend->renderMesh("../models/char/mod3.obj");
		charRend->renderMesh("../models/char/mod4.obj");
		charRend->renderMesh("../models/char/5.obj");
		charRend->renderMesh("../models/char/mod4.obj");
		charRend->renderMesh("../models/char/mod3.obj");
		charRend->renderMesh("../models/char/mod2.obj");

		//do Initialise : shaders
		charRend->RenderInitialise("../shaders/basicShader.txt", camera);
		pauseRend->RenderInitialise("../shaders/GUI.txt");

		//do Initialise : texture
		guiRend->rendTex("../models/fuelfull.png");
		guiRend->rendTex("../models/fuelmore.png");
		guiRend->rendTex("../models/fuelmed.png");
		guiRend->rendTex("../models/fuellower.png");
		guiRend->rendTex("../models/fuellow.png");
		guiRend->rendTex("../models/fuelBack.png");
		pauseRend->rendTex("../models/anim/anim1.png");
		pauseRend->rendTex("../models/anim/anim2.png");
		pauseRend->rendTex("../models/anim/anim3.png");
		pauseRend->rendTex("../models/anim/anim4.png");
		pauseRend->rendTex("../models/anim/anim5.png");
		pauseRend->rendTex("../models/anim/anim6.png");
		pauseRend->rendTex("../models/anim/anim7.png");
		pauseRend->rendTex("../models/anim/anim8.png");
		pauseRend->rendTex("../models/anim/anim9.png");
		pauseRend->rendTex("../models/anim/anim10.png");
		pauseRend->rendTex("../models/anim/anim11.png");
		pauseRend->rendTex("../models/anim/anim12.png");
		pauseRend->rendTex("../models/anim/anim13.png");
		pauseRend->rendTex("../models/anim/anim14.png");
		charRend->rendTex("../models/charTex.png");


		//do Transforms: cam
		cameraTransform->SetPos(glm::vec3(0, 0, 10));
		cameraTransform->SetRotation(1, 1, 1);
		camera->CamIni(65);
		//trans
		transform->SetRotation(0, 0, 0);
		//app
		app->setCam(camera);
		app->setPause(pauseRend);
		app->setHel(guiRend);
		app->setCon(charCont);
		//GUI
		buttonRend->setPosition(glm::vec4((700), (800), 400, 200));
		conRend->setPosition(glm::vec4((0), (800), 400, 200));
		//Pause
		pauseRend->setPosition(glm::vec4((WINDOW_WIDTH / 100 - 10), (WINDOW_HEIGHT / 100 - 10), 1080, 1020));
		app->setPause(pauseRend);
		//Health
		guiRend->setPosition(glm::vec4((WINDOW_WIDTH / 25), (WINDOW_HEIGHT / 25), 400, 100));
		//Character
		charCol->onIni();
		charTran->SetRotation(100, 0, 0);
		charTran->SetPos(glm::vec3(0, 0, 5));
		charTran->SetScale(glm::vec3(0.025f));
		charCont->modelIni();
		charCol->setHealth(guiRend);
		charCol->setPau(pauseRend);
		//skybox
		skybox->SkyboxInitialize(camera);
		//model
		rockTran->SetScale(glm::vec3(0.01f));
		rockCol->onIni();
		rockTran->SetPos(glm::vec3(-2, 0, 5));
		rockCol->setOffset({ 0, -0.2, 0 });
		rockCol->setSize({ 0.3, 0.3, 0.3 });

		//do Sound
		std::shared_ptr<Audio> sound = ent->addComponent<Audio>();
		sound->AudioInit("../sounds/OutThere.ogg");
		sound->PlayAudio();

		//run program
		app->Run();

return 0;
}