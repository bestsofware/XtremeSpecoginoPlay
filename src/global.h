#ifndef GLOBAL_H
#define GLOBAL_H

#ifdef DEBUG
#include <iostream>
#include <SFML/Graphics.hpp>

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

#define MATH_PI 3.14159265359

typedef signed 		char 	int8;
typedef unsigned 	char 	uint8;
typedef signed 		short	int16;
typedef unsigned 	short	uint16;
typedef signed 		long	int32;
typedef unsigned 	long	uint32;
typedef signed   long long	int64;
typedef unsigned long long	uint64;

extern sf::RenderWindow* appPtr;
extern uint32 g_currentFrame;

#endif
