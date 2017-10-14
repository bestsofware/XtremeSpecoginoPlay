/*
 * flyingvehicle.cpp
 */

#include "flyingvehicle.h"

#include "../ressourcemanager.h"

namespace ent
{

FlyingVehicle::FlyingVehicle() :
		Entity(),
		m_collisionRadius(16.f)
{
	m_sprite.setTexture(RessourceManager::getTexture("texture.png"));
}

FlyingVehicle::~FlyingVehicle()
{

}

void FlyingVehicle::think()
{

}

void FlyingVehicle::draw()
{
	appPtr->draw(m_sprite);
}

void FlyingVehicle::move()
{

}

} /* namespace ent */
