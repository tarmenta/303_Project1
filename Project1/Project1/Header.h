#include <iostream>
#include <vector>
#include<string>
#include "Elevator.h"

using namespace std;


bool YesorNo(char yesorno)
{
	bool tobreak = false;
	bool choice;
	while (tobreak == false)
	{


		//yesorno = toupper(yesorno);
		switch (yesorno)
		{
		case'Y':
			cout << "Ok I'll randomize";
			choice = true;
			tobreak = true;
			break;

		case 'y':
			cout << "Ok I'll randomize";
			choice = true;
			tobreak = true;
			break;

		case 'N':
			cout << "Ok you can choose";
			choice = false;
			tobreak = true;
			break;

		case 'n':
			cout << "OK you can choose";
			choice = false;
			tobreak = true;
			break;

		default:
			cout << "\nPlease pick (y/n)\n";
			tobreak = false;
			cin >> yesorno;
		}
	}
	return choice;

}

void randomizer(int numPeople)
{


}
void Creator(int numElevtor, int numPeople)
{

	vector<Elevator> elevators;
	Elevator newElevator;

	vector<Person> people;
	Person newPerson;

	for (int i = 1; i <= numElevtor; i++)
	{
		newElevator = Elevator(i, 0, true);
		elevators.push_back(newElevator);

	}
	//Person(int starttime, int startfloor, int desiredfloor, bool direction)
	/*for (int i = 1; i <= numPeople, i++)
	{
		newPerson = Person(0, 0, 1, true);
	}*/
}