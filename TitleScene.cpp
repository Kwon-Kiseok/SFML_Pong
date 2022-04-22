#include "TitleScene.h"
#include "UIManager.h"
#include "SceneManager.h"

void TitleScene::Init()
{
	UIManager::GetInstance()->Init();
}

void TitleScene::Update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		Clear();
		SceneManager::GetInstance()->LoadScene(SCENE_TYPE::GAME);
	}
}

void TitleScene::Draw(sf::RenderWindow* window)
{
	UIManager::GetInstance()->DrawMessage(window);
}

void TitleScene::Clear()
{
}
