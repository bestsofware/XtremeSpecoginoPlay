#ifndef GLOBAL_H
#define GLOBAL_H

#include <SFML/Graphics.hpp>

#ifdef DEBUG
#include <iostream>

class dbg
{
public:
	dbg() {}
	~dbg() { std::cout << '\n'; }

	template<class T>
	std::ostream& operator<<(T& obj)
	{
		return std::cout << obj;
	}
};
#else

#endif

#define MATH_PI             3.14159265359
#define MATH_RAD_TO_DEG     57.295779513
#define MATH_DEG_TO_RAD     (1.0 / MATH_RAD_TO_DEG)

typedef signed 		char 	int8;
typedef unsigned 	char 	uint8;
typedef signed 		short	int16;
typedef unsigned 	short	uint16;
typedef signed 		long	int32;
typedef unsigned 	long	uint32;
typedef signed   long long	int64;
typedef unsigned long long	uint64;

typedef sf::Vector2f            Vec2f;
typedef sf::Vector2i            Vec2i;

extern sf::RenderWindow* g_appPtr;

extern sf::View g_appView;

extern uint32 g_currentFrame;
//test

sf::Vector2f getGameMousePos();

float symetrizeAngle(float degAngle);

#endif
