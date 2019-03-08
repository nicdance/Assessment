#include "TeamMember.h"

TeamMember::TeamMember()
{
}


TeamMember::~TeamMember()
{
}

void  TeamMember::TakeDamage(int damageTaken) {
	health -= damageTaken;
}

std::string TeamMember::GetName() {
	return name;
}

std::string TeamMember::GetAttackName() {
	return attackName;
}

int TeamMember::GetMinAttack() {
	return minAttack;
}

int TeamMember::GetMaxAttack() {
	return maxAttack;
}


bool TeamMember::IsMemberDead() {
	if (health<=0) {
		return true;
	}
	else {
		return false;
	}
}