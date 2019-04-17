#include "TeamMember.h"

#include <string>

TeamMember::TeamMember()
{
}

TeamMember::TeamMember(std::string name, std::string attack, int min, int max, int startHealth)
{
	playerName = name;
	attackName = attack;
	damage = {min, max};
	health = { startHealth,startHealth };
}


TeamMember::~TeamMember()
{
}

void  TeamMember::TakeDamage(int damageTaken) {
	health.currentHealth -= damageTaken;
}

std::string TeamMember::GetName() {
	return playerName;
}

std::string TeamMember::GetAttackName() {
	return attackName;
}

int TeamMember::GetMinAttack() {
	return damage.minDamage;
}

int TeamMember::GetMaxAttack() {
	return damage.maxDamage;
}

int TeamMember::GetHealth() {
	return health.currentHealth;
}
int TeamMember::GetMaxHealth() {
	return health.maxHealth;
}

void TeamMember::SetName(std::string name) {
	playerName = name;
}
void TeamMember::SetAttackName(std::string attack) {
	attackName = attack;
}
void TeamMember::SetMinAttack(int min) {
	damage.minDamage = min;

}
void TeamMember::SetMaxAttack(int max) {
	damage.maxDamage = max;
}
void TeamMember::ResetHealth() {
	health.currentHealth = health.maxHealth;
}

bool TeamMember::IsMemberDead() {
	if (health.currentHealth<=0) {
		return true;
	}
	else {
		return false;
	}
}