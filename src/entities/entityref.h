/*
 * entityref.h
 */

#ifndef ENTITIES_ENTITYREF_H_
#define ENTITIES_ENTITYREF_H_

namespace ent {

class Entity;

///A reference to an Entity.
/*! Allows secure access to an Entity object, with reference counting to manage deletion */
class EntityRef {

	friend Entity;

public:
	EntityRef(Entity* ent); //!< Constructs a reference from an pointer to an already existing Entity
public:
	EntityRef(const EntityRef& other); //!< Copy constructor
	EntityRef(EntityRef&& other); //!< Move constructor
	EntityRef& operator=(const EntityRef& other); //!< Copy operator
	~EntityRef(); //!< Destructor (non virtual)

	Entity* operator->() const; //!< Allows access to the referenced Entity via a pointer

	bool operator==(const EntityRef& other) const; //!< References are equal if they reference the same Entity
	bool operator<(const EntityRef& other) const; //!< Compares using contained pointer values
	bool operator<(const Entity* const ent) const; //!< Compares using contained and argument pointer values

private:
	ent::Entity* m_ent; //!< Pointer to the referenced Entity
};

} /* namespace ent */

#endif /* ENTITIES_ENTITYREF_H_ */
