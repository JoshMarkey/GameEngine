#include "GameManager.h"
#include "Skybox.h"


void GameManager::onInitialise()
{
	std::shared_ptr<Entity> light = getCore()->addEntity();
	light->addComponent<PointLight>();
	light->getTransform()->setPosition(glm::vec3(5, 1, 5));

	std::shared_ptr<Entity> menuEntity = getCore()->addEntity();
	menu = menuEntity->addComponent<Menu>();
	menu->init(getEntity()->getComponent<GameManager>());
	inGame = false;
	isLaserAlive = false;
	laserSpeed = 2;

	music = getEntity()->addComponent<SoundSource>();
	music->setPath("../resources/Audio/Music.ogg");
	music->setLoop(true);
	music->setVol(0.3);
	music->play();

	getCore()->getPrimaryCam()->getEntity()->addComponent<AudioListener>();

}

void GameManager::onTick()
{
	if (!inGame)
		return;

#ifdef WIN32
	getCore()->getPrimaryCam()->setTarget(NULL);
	getCore()->getInput()->centerMouse();
#endif

	if (!isLaserAlive)
	{
		laser = getCore()->addEntity()->addComponent<Laser>();
		laser->init(getEntity()->getComponent<GameManager>(), laserSpeed);
		laserSpeed += 0.2;
		isLaserAlive = true;
	}
	
}

void GameManager::play()
{
	getCore()->addEntity()->addComponent<Skybox>();
	getCore()->getInput()->centerMouse();
	menu->getEntity()->setAlive(false);
	inGame = true;
	floorPrefab = getCore()->addEntity()->addComponent<FloorPrefab>();
	player = getCore()->addEntity()->addComponent<Player>();
#ifdef WIN32
	getCore()->getPrimaryCam()->setTarget(player->getEntity()->getTransform());
#endif
}
