#include "Marine.h"



Marine::Marine()
{
	health = 50;
	maxHealth = 50;

}


Marine::~Marine()
{
}

int Marine::attack()
{
	return 10;
}

void Marine::takeDamage(int damage)
{

	health -= damage;
	if (health < 0)
		health = 0;
}
