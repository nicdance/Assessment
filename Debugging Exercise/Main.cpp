// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

#include <iostream>
#include <vector>
#include "Marine.h"
#include "Zergling.h"

using std::vector;
using std::cout;
using std::endl;

bool marineAlive(vector<Marine> squad); 
bool marineAlive(vector<Marine> squad);
bool zerglingAlive(vector<Zergling> swarm);

int main()
{
	vector<Marine> squad;
	vector<Zergling> swarm;

	int squadSize = 10;
	int swarmSize = 20;

	// Set up the Squad and the Swarm at their initial sizes listed above

	for (size_t i = 0; i < squadSize; i++)
	{
		Marine m;
		squad.push_back(m);
	}

	for (size_t i = 0; i < swarmSize; i++)
	{
		Zergling z;
		swarm.push_back(z);
	}

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!"  << endl;
	// Attack each other until only one team is left alive
	while (marineAlive(squad) && zerglingAlive(swarm)) // If anyone is left alive to fight . . .
	{
		system("pause");
		cout << endl << endl << "Marines Attack" << endl;

		if (marineAlive(squad)) // if there's at least one marine alive
		{
			for (vector<Marine>::iterator i = squad.begin(); i != squad.end(); ++i) // loop through zerglings
			{
				if (swarm.begin() != swarm.end()) {
					cout << "A marine fires for " << i->attack() << " damage. " << endl;
					swarm.begin()->takeDamage(i->attack());
					if (!swarm.begin()->isAlive())
					{
						swarm.erase(swarm.begin());
						cout << "The zergling target dies" << endl;

					}
				}
			}
		}

		system("pause");
		cout << endl << endl << "Zerglings Attack" << endl;

		if (zerglingAlive(swarm)) // if there's at least one zergling alive
		{
			for (vector<Zergling>::iterator i = swarm.begin(); i != swarm.end(); ++i) // loop through zerglings
			{
				if (squad.begin() != squad.end()) {
					cout << "A zergling attacks for " << i->attack() << " damage." << endl;
					squad.begin()->takeDamage(i->attack());
					if (!squad.begin()->isAlive())
					{

						squad.erase(squad.begin());
						cout << "The marine succumbs to his wounds." << endl;

					}
				}	
			}
		}
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. ";
	if (marineAlive(squad))
	{
		cout << "The Marines win." << endl;
	} else 
	{
		cout << "The Zerg win." << endl;
	}
	system("pause");
}

// Is there a Marine Alive?
bool marineAlive(vector<Marine> squad)
{
	return squad.size() > 0;
}

// Is there a zergling Alive
bool zerglingAlive(vector<Zergling> swarm)
{
	return swarm.size();
}
