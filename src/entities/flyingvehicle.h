/*
 * flyingvehicle.h
 */

#ifndef SRC_ENTITIES_FLYINGVEHICLE_H_
#define SRC_ENTITIES_FLYINGVEHICLE_H_

#include "entity.h"

#include <SFML/Graphics.hpp>

namespace ent
{

class FlyingVehicle: public Entity
{
public:
	FlyingVehicle();
	virtual ~FlyingVehicle();

	virtual void think();
	virtual void draw();

	virtual void move();

protected:
	sf::Sprite m_sprite;
	float m_collisionRadius;
};

} /* namespace ent */

#endif /* SRC_ENTITIES_FLYINGVEHICLE_H_ */
