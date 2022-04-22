#include "GameScene.h"
#include "BlockManager.h"
#include "UIManager.h"
#include "SceneManager.h"
#include "Ball.h"
#include "Bat.h"

void GameScene::Init()
{
    bat = new Bat(1920.f * 0.5f, 1080.f - 20.f);
    ball = new Ball((bat->GetGlobalBounds().left + bat->GetGlobalBounds().width / 2), bat->GetGlobalBounds().top - 10.f);
    Color colors[5] = { Color::White, Color::Blue, Color::Green, Color::Cyan, Color::Magenta };

    totalScore = ROW * COL;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            BlockManager::GetInstance()->CreateBlock(j * 203.f + 50.f, i * 53.f + 50.f, colors[i]);
        }
    }
}

void GameScene::Update(sf::RenderWindow* window)
{
    sf::Time dt = clock.restart();
    float deltaTime = dt.asSeconds();

    Sides dir = Sides::NONE;
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        dir = Sides::LEFT;
    }
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        dir = Sides::RIGHT;
    }
    if (Keyboard::isKeyPressed(Keyboard::Space))
    {
         isPause = false;
    }
    bat->SetMoveDir(dir);

    FloatRect prevBallBound = ball->GetGlobalBounds();
    Vector2u windowSize = window->getSize();

    bat->Update(deltaTime);
    if (!isPause)
    {
        ball->Update(deltaTime);
    }
    else
    {
        ball->SetXY((bat->GetGlobalBounds().left + bat->GetGlobalBounds().width / 2), bat->GetGlobalBounds().top - 10.f);
        ball->Update(0);
    }
    UIManager::GetInstance()->Update();

    FloatRect ballBound = ball->GetGlobalBounds();

    if ((ballBound.left < 0.f && prevBallBound.left > 0.f) ||
        (ballBound.left + ballBound.width > windowSize.x && prevBallBound.left + prevBallBound.width < windowSize.x))
    {
        ball->ReboundSides();
    }

    if (ballBound.top < 0.f && prevBallBound.top > 0.f)
    {
        ball->ReboundBatOrTop();
    }

    if (ballBound.intersects(bat->GetGlobalBounds()) && !prevBallBound.intersects(bat->GetGlobalBounds()))
    {
        ball->ReboundBatOrTop();
    }

    for (auto i = 0; i < BlockManager::GetInstance()->GetVector().size(); i++)
    {
        if (ballBound.intersects(BlockManager::GetInstance()->GetBlocksBound(i)) && !prevBallBound.intersects(BlockManager::GetInstance()->GetBlocksBound(i)))
        {

            if (ballBound.left < BlockManager::GetInstance()->GetBlocksBound(i).left
                || ballBound.left + ballBound.width > BlockManager::GetInstance()->GetBlocksBound(i).left + BlockManager::GetInstance()->GetBlocksBound(i).width)
            {
                ball->ReboundSides();
            }
            else if (ballBound.top < BlockManager::GetInstance()->GetBlocksBound(i).top
                || ballBound.top + ballBound.height > BlockManager::GetInstance()->GetBlocksBound(i).top + BlockManager::GetInstance()->GetBlocksBound(i).height)
            {
                ball->ReboundBatOrTop();
            }
            UIManager::GetInstance()->SetScore(1);
            BlockManager::GetInstance()->DeleteBlock(i);

            if (UIManager::GetInstance()->GetScore() == totalScore)
            {
                Clear();
                SceneManager::GetInstance()->LoadScene(SCENE_TYPE::WIN);
            }
            switch (UIManager::GetInstance()->GetScore())
            {
            case 10:
            {
                bat->SetSize(-10);
                ball->SetSpeed(20);
            }
                break;
            case 20:
            {
                bat->SetSize(-10);
                ball->SetSpeed(20);
            }
                break;
            case 30:
            {
                bat->SetSize(-10);
                ball->SetSpeed(20);
            }
                break;
            case 40:
            {
                bat->SetSize(-10);
                ball->SetSpeed(20);
            }
                break;
            default:
                break;
            }
        }
    }
    if ((ballBound.top + ballBound.height > windowSize.y) && (prevBallBound.top + prevBallBound.height < windowSize.y))
    {
        isPause = true;
        UIManager::GetInstance()->SetLife(-1);

        if (UIManager::GetInstance()->GetLife() == 0)
        {
            UIManager::GetInstance()->SetScore(-1 * UIManager::GetInstance()->GetScore());
            Clear();
            SceneManager::GetInstance()->LoadScene(SCENE_TYPE::TITLE);
        }
    }
}

void GameScene::Draw(sf::RenderWindow* window)
{
    window->draw(bat->GetShape());
    window->draw(ball->GetShape());
    BlockManager::GetInstance()->DrawBlock(window);

    UIManager::GetInstance()->DrawScore(window);
    UIManager::GetInstance()->DrawLife(window);
}

void GameScene::Clear()
{
    delete bat;
    delete ball;

    bat = nullptr;
    ball = nullptr;
}
