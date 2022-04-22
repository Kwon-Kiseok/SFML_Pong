#include "UIManager.h"
#include <sstream>

void UIManager::Init()
{
	fontDSDIGI.loadFromFile("fonts/DS-DIGI.ttf");
	textMessage.setFont(fontDSDIGI);
	textScore.setFont(fontDSDIGI);
	textLife.setFont(fontDSDIGI);

	textMessage.setString("- PRESS ENTER KEY TO START -");
	textMessage.setCharacterSize(75);
	textScore.setCharacterSize(75);
	textLife.setCharacterSize(75);
	textMessage.setFillColor(Color::White);
	textScore.setFillColor(Color::White);
	textLife.setFillColor(Color::White);

	textScore.setPosition(10.f, 1020.f - 100.f);
	SetRect();

	textMessage.setPosition(1920 * 0.5f, 1080 * 0.5f);

	life = 5;
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
	ss << "Score = " << UIManager::GetInstance()->GetScore() << std::endl;
	ss << "Life = " << UIManager::GetInstance()->GetLife();
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

void UIManager::SetLife(int add)
{
	life += add;
}

int UIManager::GetLife()
{
	return life;
}

void UIManager::DrawScore(RenderWindow* window)
{
	window->draw(textScore);
}

void UIManager::DrawMessage(RenderWindow* window)
{
	window->draw(textMessage);
}

void UIManager::DrawLife(RenderWindow* window)
{
	window->draw(textLife);
}

Text& UIManager::SetTextMessage(const char* str, int size, Color color)
{
	textMessage.setString(str);
	textMessage.setCharacterSize(size);
	textMessage.setFillColor(color);
	textMessage.setPosition(1920 * 0.5f, 1080 * 0.5f);
	SetRect();
	return textMessage;
}
