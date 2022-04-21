#include "BlockManager.h"
#include "Block.h"

BlockManager::BlockManager()
	: countBlock(0)
{
}

BlockManager::~BlockManager()
{
}

void BlockManager::CreateBlock(float x, float y)
{
	blockVector.push_back(new Block(x, y));
}

void BlockManager::DrawBlock(sf::RenderWindow* window)
{
	for(auto i = 0; i < blockVector.size(); i++)
		window->draw(blockVector[i]->GetShape());
}

vector<Block*> BlockManager::GetVector()
{
	return blockVector;
}
