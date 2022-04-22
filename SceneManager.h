#pragma once
#include "Singleton.h"
#include "Scene.h"

enum class SCENE_TYPE
{
	TITLE,
	GAME,
	WIN,
	DEFAULT
};

class SceneManager : public Singleton<SceneManager>
{
private:
	Scene* scene = nullptr;
public:
	void LoadScene(SCENE_TYPE sceneType);
	void UpdateScene(sf::RenderWindow* window);
	void DrawScene(sf::RenderWindow* window);
	void ClearScene();
};

