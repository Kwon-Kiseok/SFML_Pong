#include "BlockManager.h"
#include "Block.h"


void BlockManager::CreateBlock(float x, float y, sf::Color color)
{
	blockVector.push_back(new Block(x, y, color));
}

void BlockManager::DrawBlock(sf::RenderWindow* window)
{
	for(auto i = 0; i < blockVector.size(); i++)
		window->draw(blockVector[i]->GetShape());
}

void BlockManager::DeleteBlocks()
{
	for (auto iter = blockVector.begin(); iter != blockVector.end(); iter++)
		delete* iter;
	blockVector.clear();
}

void BlockManager::DeleteBlock(int idx)
{

	blockVector.erase(blockVector.begin() + idx);
}

vector<Block*> BlockManager::GetVector()
{
	return blockVector;
}

sf::FloatRect BlockManager::GetBlocksBound(int idx)
{
	return blockVector[idx]->GetGlobalBounds();
}
