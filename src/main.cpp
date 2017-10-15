#include <iostream>

#include "global.h"
#include "entities/entityref.h"
#include "entities/entity.h"
#include "entities/flyingvehicle.h"
#include "ressourcemanager.h"
#include <SFML/Graphics.hpp>

using ent::EntityRef;
using ent::Entity;
using ent::FlyingVehicle;

int main(int argc, const char* argv[])
{
	RessourceManager::BAD_TEXTURE.loadFromFile("data/img/badTexture.png");

	sf::RenderWindow app(sf::VideoMode(800, 600), "Test");
	app.setFramerateLimit(60);

	g_appPtr = &app;
        g_appView = app.getDefaultView();

	sf::Event event;

	EntityRef* ref = new EntityRef(new FlyingVehicle());
    (*ref)->spawn();

    EntityRef* ref2 = new EntityRef(new FlyingVehicle());
    (*ref2)->setPosition(Vec2f(200.f, 200.f));
    (*ref2)->spawn();


	while(app.isOpen())
	{
		while(app.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				app.close();
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::O) && ref)
		{
			(*ref)->despawn();
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::K))
		{
			delete ref;
			ref = nullptr;
		}

		app.clear(sf::Color(128, 128, 255));

		Entity::doAllEntitiesThink();
		Entity::doAllEntitiesDraw();

		app.display();
		g_currentFrame++;
	}

	std::cout << "\n======================\nFin du programme\n";

	return 0;
}
