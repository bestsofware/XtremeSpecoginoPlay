/*
 * entity.cpp
 */

#include "entity.h"

#include "entityref.h"

namespace ent {

Entity::Id Entity::s_lastId = Entity::INVALID_ID;
const Entity::Id Entity::INVALID_ID = 0;

std::map<Entity*, std::unique_ptr<EntityRef>> Entity::s_spawnedEntities;
std::set<Entity*> Entity::s_despawnQueue;
bool Entity::s_instantDespawningAllowed = true;


void Entity::doAllEntitiesThink()
{
	s_instantDespawningAllowed = false;
	for(auto& p : s_spawnedEntities)
	{
		if(p.first->m_thinks)
			p.first->think();
	}

	clearDespawnQueue();

	s_instantDespawningAllowed = true;
}

void Entity::doAllEntitiesDraw()
{
	s_instantDespawningAllowed = false;
	for(auto& p : s_spawnedEntities)
	{
		if(p.first->m_visible)
			p.first->draw();
	}

	clearDespawnQueue();

	s_instantDespawningAllowed = true;
}

void Entity::clearDespawnQueue()
{
	for(Entity* e : s_despawnQueue)
		s_spawnedEntities.erase(e);
	s_despawnQueue.clear();
}

Entity::Entity() :
		m_referencesCount(0),
		m_id(++s_lastId),
		m_spawned(false),
		m_thinks(false),
		m_visible(true)
{
	dbg() << "Created ent id " << m_id;
}

Entity::~Entity()
{
	dbg() << "Destroyed ent id " << m_id;
}

void Entity::think()
{
	dbg() << "think";
}

void Entity::draw()
{
	dbg() << "draw";
}

void Entity::spawn()
{
	if(m_spawned)
		return;
	m_spawned = true;
	s_spawnedEntities[this] = std::move(std::unique_ptr<EntityRef>(new EntityRef(this)));
}

void Entity::despawn()
{
	if(!m_spawned)
		return;
	m_spawned = false;;
	if(s_instantDespawningAllowed)
		s_spawnedEntities.erase(this);
	else
		s_despawnQueue.insert(this);
}

} /* namespace ent */
