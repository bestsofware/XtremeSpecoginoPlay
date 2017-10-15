#include "global.h"

sf::RenderWindow* g_appPtr = nullptr;
uint32 g_currentFrame = 0;

sf::Vector2f getGameMousePos()
{
	return g_appPtr->mapPixelToCoords(sf::Mouse::getPosition());
}
