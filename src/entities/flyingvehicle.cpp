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
	g_appPtr->draw(m_sprite);
}

void FlyingVehicle::move()
{

}

} /* namespace ent */
