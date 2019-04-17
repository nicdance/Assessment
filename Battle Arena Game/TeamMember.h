#ifndef _TEAMMEMBER_H_
#define _TEAMMEMBER_H_

#include <string>
#include "Health.h"
#include "Damage.h"

class TeamMember
{

private:
	std::string playerName;
	std::string attackName;
	Damage damage;
	Health health;

public:
	TeamMember();
	TeamMember(std::string name, std::string attack, int min, int max, int health);
	~TeamMember();

	void TakeDamage(int damageTaken);
	std::string GetName();
	std::string GetAttackName();
	int GetMinAttack();
	int GetMaxAttack();
	int GetHealth();
	int GetMaxHealth();

	void SetName(std::string name);
	void SetAttackName(std::string attack);
	void SetMinAttack(int min);
	void SetMaxAttack(int max);
	void ResetHealth();

	bool IsMemberDead();
};


#endif
