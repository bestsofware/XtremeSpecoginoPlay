/*
 * entity.h
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "../global.h"

#include "../collisions.h"

#include <map>
#include <set>
#include <memory>

namespace ent {

class EntityRef;

class Entity {

    friend EntityRef;

public:
    typedef uint32 Id;
    static const Id INVALID_ID;

public:
    static void doAllEntitiesThink();
    static void doAllEntitiesDraw();

private:
    static void clearDespawnQueue();

protected:
    Entity();
    virtual ~Entity();

protected:
    virtual void think();
    virtual void draw();

public:
    inline Id getId() const { return m_id; }
    inline uint32 getRefCount() const { return m_referencesCount; }

    void spawn();
    void despawn();
    inline bool isSpawned() const { return m_spawned; }

private:
    uint32 m_referencesCount;
protected:
    static Id s_lastId;
    Id m_id;

private:
    static std::map<Entity*, std::unique_ptr<EntityRef>> s_spawnedEntities;
    static std::set<Entity*> s_despawnQueue;
    static bool s_instantDespawningAllowed;
    bool m_spawned;

protected:
    bool m_thinks;
    bool m_visible;
        
public:
    inline CollisionMask getCollisionMask() const { return m_collisionMask; }
    virtual void onCollision(const EntityRef& other) {}
protected:
    CollisionMask m_collisionMask;
    
public:
    virtual void setPosition(const Vec2f& pos) {}
};

} /* namespace ent */

#endif /* ENTITY_H_ */
