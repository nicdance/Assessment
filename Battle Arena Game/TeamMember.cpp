#include "TeamMember.h"
#include <string>

TeamMember::TeamMember()
{
}

TeamMember::TeamMember(std::string name, std::string attack, int min, int max, int health)
{
	playerName = name;
	attackName = attack;
	minAttack = min;
	maxAttack = max;
	playerHealth = health;
	maxHealth = health;
}


TeamMember::~TeamMember()
{
}

void  TeamMember::TakeDamage(int damageTaken) {
	playerHealth -= damageTaken;
}

std::string TeamMember::GetName() {
	return playerName;
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

int TeamMember::GetHealth() {
	return playerHealth;
}
int TeamMember::GetMaxHealth() {
	return maxHealth;
}

void TeamMember::SetName(std::string name) {
	playerName = name;
}
void TeamMember::SetAttackName(std::string attack) {
	attackName = attack;
}
void TeamMember::SetMinAttack(int min) {
	minAttack = min;

}
void TeamMember::SetMaxAttack(int max) {
	maxAttack = max;
}
void TeamMember::SetHealth(int health) {
	playerHealth = health;
}

bool TeamMember::IsMemberDead() {
	if (playerHealth<=0) {
		return true;
	}
	else {
		return false;
	}
}