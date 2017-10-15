/*
 * flyingvehicle.cpp
 */

#include "flyingvehicle.h"

#include "../ressourcemanager.h"

#include <cmath>

namespace ent
{

FlyingVehicle::FlyingVehicle() :
		Entity(),
		m_collisionRadius(16.f)
{
	m_sprite.setTexture(RessourceManager::getTexture("test.png"));
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2.f, m_sprite.getLocalBounds().height / 2.f);
	m_thinks = true;
	m_visible = true;
}

FlyingVehicle::~FlyingVehicle()
{

}

void FlyingVehicle::think()
{
	move();
}

void FlyingVehicle::draw()
{
    m_sprite.setPosition(getGameMousePos());
    g_appPtr->draw(m_sprite);
}

void FlyingVehicle::move()
{

    //m_sprite.setPosition(200.f + 100.f * sin((float)g_currentFrame / 120.f * 2.f * (float)MATH_PI),200.f + 100.f * cos((float)g_currentFrame / 120.f * 2.f * (float)MATH_PI));

    //sf::Vector2i position = sf::Mouse::getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_sprite.move(-3,0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_sprite.move(3,0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        m_sprite.move(0,-3);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        m_sprite.move(0,3);
    }
/*
    if ((position.x > 400 && position.x < 430) && (position.y > 400 && position.y < 430))
    {
        m_sprite.rotate(4);
    }

*/


    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        m_sprite.rotate(-15);
        dbg() << "Mitraillette a gauche";
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        m_sprite.rotate(15);
        dbg() << "Mitraillette a droite";
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
    {
        m_sprite.rotate(45);
    }



}

} /* namespace ent */
