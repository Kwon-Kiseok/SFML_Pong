#include "BlockManager.h"
#include "UIManager.h"
#include "SceneManager.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Pong!", sf::Style::Fullscreen);
    
    SceneManager::GetInstance()->LoadScene(SCENE_TYPE::TITLE);
    UIManager::GetInstance()->Init();
    while (window.isOpen())
    {
        SceneManager::GetInstance()->UpdateScene(&window);
        SceneManager::GetInstance()->DrawScene(&window);
    }

    BlockManager::GetInstance()->DeleteBlocks();
    return 0;
}