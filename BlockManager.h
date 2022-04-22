#pragma once
#include "Singleton.h"
#include "SFML/Graphics.hpp"
#include <vector>

using namespace std;

class Block;
class BlockManager : public Singleton<BlockManager>
{
private:
	int countBlock = 0;
	vector<Block*> blockVector;
public:
	void CreateBlock(float x, float y, sf::Color color);
	void DrawBlock(sf::RenderWindow* window);
	void DeleteBlocks();
	void DeleteBlock(int idx);
	vector<Block*> GetVector();
	sf::FloatRect GetBlocksBound(int idx);
};

