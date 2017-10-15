#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "global.h"

typedef uint8 CollisionMask;

enum
{
    COL_NONE =              0x00,
    COL_FLYING_OBJECTS =    0x01,
};

inline bool testCollisionMasks(CollisionMask a, CollisionMask b)
{
    return (a & b);
}

#endif /* COLLISIONS_H */

