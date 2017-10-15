/*
 * flyingvehicle.cpp
 */

#include "flyingvehicle.h"

#include "../ressourcemanager.h"
#include "entityref.h"

#include <cmath>

namespace ent
{

FlyingVehicle::FlyingVehicle() :
		Entity(),
		m_collisionRadius(16.f)
{
	m_sprite.setTexture(RessourceManager::getTexture("test.png"));
    m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.f, m_sprite.getGlobalBounds().height / 2.f);
	m_thinks = true;
    m_visible = true;
    m_collisionMask = COL_FLYING_OBJECTS;
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
    g_appPtr->draw(m_sprite);
}

void FlyingVehicle::move()
{
<<<<<<< HEAD
=======
    if(m_id != 1)
        return;

    Vec2f target = getGameMousePos();

    float targetAngle = ::atan2f(target.y - m_sprite.getPosition().y, target.x - m_sprite.getPosition().x) * MATH_RAD_TO_DEG;
    while(targetAngle < -180.f)
        targetAngle += 360.f;
    while(targetAngle > 180.f)
        targetAngle -= 360.f;

    float speed = 2.f;

    float spriteAngle = symetrizeAngle(m_sprite.getRotation());

    float diffAngle = symetrizeAngle(spriteAngle - targetAngle);

    //if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        if(diffAngle < -3.1f)
            spriteAngle += 3.f;
        else if(diffAngle > 3.1f)
            spriteAngle -= 3.f;
        else
            spriteAngle = targetAngle;
    }

    m_sprite.setRotation(spriteAngle);
    m_sprite.move(::cosf(spriteAngle * MATH_DEG_TO_RAD) * speed, ::sinf(spriteAngle * MATH_DEG_TO_RAD) * speed);

    return;
>>>>>>> master

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
<<<<<<< HEAD
/*
    if ((position.x > 400 && position.x < 430) && (position.y > 400 && position.y < 430))
    {
        m_sprite.rotate(4);
    }

*/


=======
    /*
        if ((position.x > 400 && position.x < 430) && (position.y > 400 && position.y < 430))
        {
            m_sprite.rotate(4);
        }

     */
>>>>>>> master
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
<<<<<<< HEAD



=======
}

void FlyingVehicle::onCollision(const EntityRef& other)
{
    dbg() << "Entity n°" << m_id << " says : \"OUILLE\"";
}

void FlyingVehicle::setPosition(const Vec2f& pos)
{
    m_sprite.setPosition(pos);
>>>>>>> master
}

} /* namespace ent */
