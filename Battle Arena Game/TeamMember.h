#ifndef _TEAMMEMBER_H_
#define _TEAMMEMBER_H_

#include <string>

class TeamMember
{

private:
	int health;
	std::string name;
	std::string attackName;
	int minAttack;
	int maxAttack;

public:
	TeamMember();
	~TeamMember();

	void TakeDamage(int damageTaken);
	std::string GetName();
	std::string GetAttackName();
	int GetMinAttack();
	int GetMaxAttack();
	bool IsMemberDead();
};


#endif
