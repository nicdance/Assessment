#include "Entity.h"

Entity::Entity()
{
}


Entity::~Entity()
{
}

bool Entity::isAlive()
{
	bool check = false;
	if(health >0){
		check = true;
	}
	return check;
}
int Entity::attack()
{
	return 1;
}

void Entity::takeDamage(int damage)
{
	health -= damage;
}
