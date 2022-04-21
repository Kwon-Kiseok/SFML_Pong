#include <SFML/Graphics.hpp>
#include "Bat.h"
#include "Ball.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Pong!", sf::Style::Fullscreen);
    Bat bat(1920.f * 0.5f, 1080.f - 20.f);
    Ball ball(1920.f * 0.5f, 0.f);

    // bool prevColSide = false;
    // bool prevColTop = false;
    // bool prevColBat = false;

    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        float deltaTime = dt.asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
    
        Sides dir = Sides::NONE;
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            dir = Sides::LEFT;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            dir = Sides::RIGHT;
        }
        bat.SetMoveDir(dir);

        FloatRect prevBallBound = ball.GetGlobalBounds();
        Vector2u windowSize = window.getSize();

        // update
        bat.Update(deltaTime);
        ball.Update(deltaTime);

        FloatRect ballBound = ball.GetGlobalBounds();

        // bool currColSide = (ballBound.left < 0.f || ballBound.left + ballBound.width > windowSize.x);
        // bool currColTop = (ballBound.top < 0.f);
        // bool currColBat = (ballBound.intersects(bat.GetGlobalBounds()));

        // if(!prevColSide && currColSide) // 사이드체크
        // if(!prevColTop && currColTop) // 상단체크
        // if(!prevColBat && currColBat) // 막대체크

        if ((ballBound.left < 0.f && prevBallBound.left > 0.f) || 
            (ballBound.left + ballBound.width > windowSize.x && prevBallBound.left + prevBallBound.width < windowSize.x))
        {
            ball.ReboundSides();
        }

        if (ballBound.top < 0.f && prevBallBound.top > 0.f)
        {
            ball.ReboundBatOrTop();
        }

        if (ballBound.intersects(bat.GetGlobalBounds()) && !prevBallBound.intersects(bat.GetGlobalBounds()))
        {
            ball.ReboundBatOrTop();
        }

        if ((ballBound.top + ballBound.height > windowSize.y) && (prevBallBound.top + prevBallBound.height < windowSize.y))
        {
            ball.ReboundBottom();
        }

        // prevColSide = currColSide;
        // prevColTop = currColTop;
        // prevColBat = currColBat;

        // draw
        window.clear();
        window.draw(bat.GetShape());
        window.draw(ball.GetShape());
        window.display();
    }

    return 0;
}