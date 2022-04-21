#include "UIManager.h"
#include <sstream>

void UIManager::Init()
{
	fontDSDIGI.loadFromFile("fonts/DS-DIGI.ttf");
	textMessage.setFont(fontDSDIGI);
	textScore.setFont(fontDSDIGI);
	textMessage.setString("- PRESS SPACEBAR KEY TO START -");
	textMessage.setCharacterSize(75);
	textScore.setCharacterSize(75);
	textMessage.setFillColor(Color::White);
	textScore.setFillColor(Color::White);

	textScore.setPosition(10.f, 1020.f - 80.f);

	SetRect();

	textMessage.setPosition(1920 * 0.5f, 1080 * 0.5f);
}

void UIManager::SetRect()
{
	textRect = textMessage.getLocalBounds();
	textMessage.setOrigin(
		textRect.left + textRect.width * 0.5f,
		textRect.top + textRect.height * 0.5f
	);
}

void UIManager::Update()
{
	std::stringstream ss;
	ss << "Score = " << UIManager::GetInstance()->GetScore();
	textScore.setString(ss.str());
}

void UIManager::SetScore(int add)
{
	score += add;
}

int UIManager::GetScore()
{
	return score;
}

void UIManager::DrawScore(RenderWindow* window)
{
	window->draw(textScore);
}

void UIManager::DrawMessage(RenderWindow* window)
{
	window->draw(textMessage);
}
