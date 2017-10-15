#include "global.h"

sf::RenderWindow* g_appPtr = nullptr;
sf::View g_appView;
uint32 g_currentFrame = 0;

sf::Vector2f getGameMousePos()
{
    return g_appPtr->mapPixelToCoords(sf::Mouse::getPosition(*g_appPtr), g_appView);
}

float symetrizeAngle(float degAngle)
{
    while(degAngle < -180.f)
        degAngle += 360.f;
    while(degAngle > 180.f)
        degAngle -= 360.f;

    return degAngle;
}