#include "SceneManager.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "WinScene.h"

void SceneManager::LoadScene(SCENE_TYPE sceneType)
{
	ClearScene();

	switch (sceneType)
	{
	case SCENE_TYPE::TITLE:
		scene = new TitleScene();
		break;
	case SCENE_TYPE::GAME:
		scene = new GameScene();
		break;
	case SCENE_TYPE::WIN:
		scene = new WinScene();
		break;
	default:
		break;
	}

	scene->Init();
}

void SceneManager::UpdateScene(sf::RenderWindow* window)
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window->close();
	}

	scene->Update(window);
}

void SceneManager::DrawScene(sf::RenderWindow* window)
{
	window->clear();
	scene->Draw(window);
	window->display();
}

void SceneManager::ClearScene()
{
	if (nullptr != scene)
	{
		delete scene;
		scene = nullptr;
	}
}
