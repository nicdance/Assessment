/*
/	@Author Nicole Dance
/   Assessment 2 - Battle Area Game
*/
#include <iostream>
//#include <random>
//#include <time.h>
//#include <string>
#include "TeamMember.h"

const int NOERROR = 0;
const int WRONGSELECTION = 1;
const int INVALIDVALUE = 2;
const int TEAMSIZE = 6;

// Headers
void PlayGame();
void Sort(TeamMember team[], int sizeOfTeam);
void TeamsAttack(TeamMember attackingTeam[], TeamMember defendingTeam[]);
bool TeamMemberAttack(TeamMember* member, TeamMember team[]);
bool CheckTeamAlive(TeamMember team[], int sizeOfTeam);
void PrintTeams(TeamMember teamOne[], TeamMember teamTwo[]);


 int main() {
	bool playOn = true;
	int errorCode = NOERROR;
	while (playOn) {

		system("cls");
		std::cout << " ################################################################################# " << std::endl;
		std::cout << "###                                                                             ###" << std::endl;
		std::cout << "##     BBBB   AAA  TTTTT TTTTT L     EEEEE      AAA  RRRR  EEEEE N   N  AAA      ##" << std::endl;
		std::cout << "##     B   B A   A   T     T   L     E         A   A R  RR E     NN  N A   A     ##" << std::endl;
		std::cout << "##     BBBB  AAAAA   T     T   L     EEEEE     AAAAA RRRR  EEEEE N N N AAAAA     ##" << std::endl;
		std::cout << "##     B   B A   A   T     T   L     E         A   A R  R  E     N  NN A   A     ##" << std::endl;
		std::cout << "##     BBBB  A   A   T     T   LLLLL EEEEE     A   A R   R EEEEE N   N A   A     ##" << std::endl;
		std::cout << "###                                                                             ###" << std::endl;
		std::cout << " ################################################################################ " << std::endl;

		int menuSelection = 0;
		
		switch(errorCode) {
			case WRONGSELECTION:
				std::cout << "ERROR -> Please enter ender a number between 1-2." << std::endl;
				break;
			case INVALIDVALUE:
				std::cout << "ERROR -> Please enter a numerical Value." << std::endl;
				break;
			default:
				break;
		}

		std::cout << "Menu" << std::endl;
		std::cout << "1. Start Game" << std::endl;
		std::cout << "2. Quit Game" << std::endl;
		std::cout << "-> ";

		std::cin >> menuSelection;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1);
			errorCode = INVALIDVALUE;
		}
		else {
			switch (menuSelection) {
				case 1:
					PlayGame();
					break;
				case 2:
					playOn = false;
					std::cout << "Thankyou for Playing. Good Bye" <<  std::endl;
					break;
				default:
					errorCode = WRONGSELECTION;
					break;
			}
		}
	}
	system("pause");
	return 0;
}

 void PlayGame() {
	 TeamMember teamOne[6];
	 TeamMember teamTwo[6];

	 teamOne[0] = TeamMember("Iron Man", "Blaster", 10, 50, 100);
	 teamOne[1] = TeamMember("War Machine", "War", 10, 40,120);
	 teamOne[2] = TeamMember("Black Widow", "kick", 15, 35, 90);
	 teamOne[3] = TeamMember("Black Panther", "Scratch", 25, 35, 95);
	 teamOne[4] = TeamMember("The Vision", "Zap", 30, 60, 150);
	 teamOne[5] = TeamMember("Spider-Man", "Web", 5, 25, 85);

	 teamTwo[0] = TeamMember("Captain America", "Thump", 10, 50, 150);
	 teamTwo[1] = TeamMember("Hawkeye", "Pew Pew", 10, 40, 100);
	 teamTwo[2] = TeamMember("Falcon", "Swoosh", 15, 35, 85);
	 teamTwo[3] = TeamMember("Bucky Barns", "Bash", 25, 35, 90);
	 teamTwo[4] = TeamMember("And-Man", "Giant Smash", 30, 60, 120);
	 teamTwo[5] = TeamMember("Scarlet Witch", "Crack", 5, 25, 95);

	 Sort(teamOne, 6);
	 Sort(teamTwo, 6);

	 bool keepPlaying = true;

	 while (keepPlaying){

		 TeamsAttack(teamOne, teamTwo);

		 Sort(teamOne, 6);
		 Sort(teamTwo, 6);

		 PrintTeams(teamOne, teamTwo);

		 if (!CheckTeamAlive(teamOne, 6) || !CheckTeamAlive(teamTwo, 6)) {
			 keepPlaying = false;
		 }
		 system("pause");
	 }

	 std::cout << "Game Over" << std::endl;
	 system("pause");
	 //TeamMember* member = new TeamMember();
		 // Create 2 arrays  of TeamMember clases

		 // Member 1 of team 1 attacks random member of team 2
		 // Member 1 of team 2 attacks random member of team 1
		 // go thrugh all live team members 
		 // if member dies display msg to console

		 // Once end sort heros in decending health.

		 // Repeat until all team members in one team are dead
 }

 void Sort(TeamMember team[], int sizeOfTeam) {
	 for (int i = 0; i < sizeOfTeam; i++)
	 {
		 for (int j = i+1; j < sizeOfTeam; j++)
		 {
			 if(team[i].GetHealth() < team[j].GetHealth() ) {
				 TeamMember temp = team[i];
				 team[i] = team[j];
				 team[j] = temp;
			 }
		 }
	 }
 }


 bool CheckTeamAlive(TeamMember team[], int sizeOfTeam) {
	 bool alive = false;
	 for (int i = 0; i < sizeOfTeam; i++)
	 {
		 if (!team[i].IsMemberDead()) {
			 alive = true;
		 }
	 }
	 return alive;
 }

 void TeamsAttack(TeamMember teamOne[], TeamMember teamTwo[]) {
	 for (int i = 0; i < TEAMSIZE; i++)
	 {
		 if (!TeamMemberAttack(&teamOne[i], teamTwo)) {
			 i = TEAMSIZE;
		 }
		 else if (!TeamMemberAttack(&teamTwo[i], teamOne)) {
			 i = TEAMSIZE;
		 }
	 } // End For
 }

 bool TeamMemberAttack(TeamMember* member, TeamMember team[]) {
	 bool findMemberToAttack = true;
	 while (findMemberToAttack) {

		 if (!CheckTeamAlive(team, 6)) {
			 return false;
		 }
		 int memberToAttack = 0;
		 while (findMemberToAttack) {
			 memberToAttack = rand() % (TEAMSIZE - 1);
			 if (!team[memberToAttack].IsMemberDead()) {
				 findMemberToAttack = false;
			 }
		 }
		 int attack = member->Attack(&team[memberToAttack]);
		 std::cout << member->GetName() << " attacked " << team[memberToAttack].GetName() <<
			 " with " << member->GetAttackName() << ". Hit for " << attack << std::endl;
		 if (team[memberToAttack].IsMemberDead()) {
			 std::cout << team[memberToAttack].GetName() << " is KO" << std::endl;
		 }
	 } // End While
	 return true;
 }
 void PrintTeams(TeamMember teamOne[], TeamMember teamTwo[]) {
	 std::cout << std::endl << "Team One" << std::endl;
	 for (int i = 0; i < 6; i++)
	 {
		 if (teamOne[i].IsMemberDead()) {
			 std::cout << teamOne[i].GetName() << " is KO" << std::endl;
		 }
		 else {
			 std::cout << teamOne[i].GetName() << " " << teamOne[i].GetHealth() << "/" << teamOne[i].GetMaxHealth() << std::endl;
		 }
	 }

	 std::cout << std::endl << "Team Two" << std::endl;
	 for (int i = 0; i < 6; i++)
	 {

		 if (teamTwo[i].IsMemberDead()) {
			 std::cout << teamTwo[i].GetName() << " is KO" << std::endl;
		 }
		 else {
			 std::cout << teamTwo[i].GetName() << " " << teamTwo[i].GetHealth() << "/" << teamTwo[i].GetMaxHealth() << std::endl;
		 }
	 }
 }
 /*const int MAX = 10;
 std::default_random_engine dre(time(0));
 std::uniform_int_distribution<int> uid(0, MAX);

 uid(dre); // Generate random number

 // Second way
 srand(time(0));
 srand() % MAX;
  std::cout << "This is a Test"<< std::endl;
 */