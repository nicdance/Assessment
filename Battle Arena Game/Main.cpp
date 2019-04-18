/*
/	@Author Nicole Dance
/   Assessment 2 - Battle Area Game
*/
#include <iostream>
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
void PrintTeams(TeamMember team[]);
void PrintTeams(TeamMember teamOne[], TeamMember teamTwo[]);
void PrintMember(TeamMember* member);


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
	 teamTwo[4] = TeamMember("Any-Man", "Giant Smash", 30, 60, 120);
	 teamTwo[5] = TeamMember("Scarlet Witch", "Crack", 5, 25, 95);

	 bool keepPlaying = true;
	 int round = 1;
	 while (keepPlaying){
		 std::cout << std::endl << std::endl << "** Beginning Round " << round << " **" << std::endl;

		 // Called TeamsAttack the core function
		 TeamsAttack(teamOne, teamTwo);

		 // Sorts the 2 teams  highst to lowst
		 Sort(teamOne, 6);
		 Sort(teamTwo, 6);

		 // Prints out the teams as a list
		 //PrintTeams(teamOne);
		// PrintTeams(teamTwo);
		PrintTeams(teamOne, teamTwo);

		 // Checks if either team is dead. If they are they set keepPLaying to false to exit game loop
		 if (!CheckTeamAlive(teamOne, 6) || !CheckTeamAlive(teamTwo, 6)) {
			 keepPlaying = false;
		 }
		 system("pause");
		 round++;
	 }

	 std::cout << "Game Over" << std::endl;
	 system("pause");
 }

 // Takes an array of TeamMembers and sorts them largest to smallest
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


 // Take a TeamMember array and checks if the team is alive.
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

 // Takes in 2 TeamMember arrays and  has them attack each other
 void TeamsAttack(TeamMember teamOne[], TeamMember teamTwo[]) {
	 for (int i = 0; i < TEAMSIZE; i++)
	 {
		 if (!teamOne[i].IsMemberDead()) {
			 if (!TeamMemberAttack(&teamOne[i], teamTwo)) {
				 i = TEAMSIZE;
			 }
		 }
		 if (!teamTwo[i].IsMemberDead()) {
			 if (!TeamMemberAttack(&teamTwo[i], teamOne)) {
				 i = TEAMSIZE;
			 }
		 }
	 } // End For
 }

 // Takes in a Single Team Member and the TeamMember array of the apposing team
 // Finds a random living team member and attacks 
 // Returns false if there are no living team members
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
		 std::string result = member->GetName() + " attacked " + team[memberToAttack].GetName() +
			 " with " + member->GetAttackName() + ".";
		 int count = 53 - result.size();
		 for (int i = 0; i < count; i++)
		 {
			 result = result + " ";
		 }
		 std::cout << result <<	 "Hit for " << attack << std::endl;
		 if (team[memberToAttack].IsMemberDead()) {
			 std::cout << team[memberToAttack].GetName() << " is KO" << std::endl;
		 }
	 } // End While
	 return true;
 }

 // Prints out a Team list
 void PrintTeams(TeamMember team[]) {
	 std::cout << std::endl << "Team One" << std::endl;
	 for (int i = 0; i < 6; i++)
	 {
		 if (team[i].IsMemberDead()) {
			 std::cout << team[i].GetName() << " is KO" << std::endl;
		 }
		 else {
			 std::cout << team[i].GetName() << " " << team[i].GetHealth() << "/" << team[i].GetMaxHealth() << std::endl;
		 }
	 }
 }

 // Prints out a Team list
 void PrintTeams(TeamMember teamOne[], TeamMember teamTwo[]) {
	 std::cout << std::endl << "Team One                  Team Two" << std::endl;
	 for (int i = 0; i < 6; i++)
	 {
		 PrintMember(&teamOne[i]);
		 PrintMember(&teamTwo[i]);
		 std::cout <<  std::endl;
	 }
 }

 // Prints out a Team list
 void PrintMember(TeamMember* member) {
	 std::string  result = "";
	if (member->IsMemberDead()) {
		result = member->GetName() + " is KO";
	}
	else {
		result = member->GetName();
		int counter = 16 - result.size();
		for (int  i = 0; i < counter; i++)
		{
			result = result + " ";
		}
		result = result +	+ " " + std::to_string(member->GetHealth()) + "/" + std::to_string(member->GetMaxHealth());
	}
	int counter = 26 - result.size();
	for (int i = 0; i < counter; i++)
	{
		result = result + " ";
	}
	std::cout << result;
 }