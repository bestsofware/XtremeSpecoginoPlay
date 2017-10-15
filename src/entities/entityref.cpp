/*
 * entityref.cpp
 */

#include "entityref.h"

#include "entity.h"

namespace ent
{

EntityRef::EntityRef(Entity* ent)
{
	m_ent = ent;
	m_ent->m_referencesCount++;
}

EntityRef::EntityRef(const EntityRef& other)
{
	m_ent = other.m_ent;
	m_ent->m_referencesCount++;
}

EntityRef::EntityRef(EntityRef&& other)
{
	m_ent = other.m_ent;
}

EntityRef& EntityRef::operator=(const EntityRef& other)
{
	m_ent = other.m_ent;
	m_ent->m_referencesCount++;

	return *this;
}

EntityRef::~EntityRef()
{
	if(m_ent->m_referencesCount <= 1)
	{
		delete m_ent;
		return;
	}

	m_ent->m_referencesCount--;
}

Entity* EntityRef::operator->() const
{
	return m_ent;
}

bool EntityRef::operator==(const EntityRef& other) const
{
	return m_ent == other.m_ent;
}

bool EntityRef::operator<(const EntityRef& other) const
{
	return m_ent < other.m_ent;
}

bool EntityRef::operator<(const Entity* const ent) const
{
	return m_ent < ent;
}

}//namespace ent
