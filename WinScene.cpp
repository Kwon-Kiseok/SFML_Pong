#include "WinScene.h"
#include "UIManager.h"
#include "SceneManager.h"

void WinScene::Init()
{
	UIManager::GetInstance()->SetTextMessage("- YOU WIN -", 75, Color::White);
}

void WinScene::Update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Clear();
		SceneManager::GetInstance()->LoadScene(SCENE_TYPE::TITLE);
	}
}

void WinScene::Draw(sf::RenderWindow* window)
{
	UIManager::GetInstance()->DrawMessage(window);
}

void WinScene::Clear()
{
}
