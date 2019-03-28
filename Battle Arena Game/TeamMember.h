#ifndef _TEAMMEMBER_H_
#define _TEAMMEMBER_H_

#include <string>

class TeamMember
{

private:
	int playerHealth;
	int maxHealth;
	std::string playerName;
	std::string attackName;
	int minAttack;
	int maxAttack;

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
	void SetHealth(int health);

	bool IsMemberDead();
};


#endif
