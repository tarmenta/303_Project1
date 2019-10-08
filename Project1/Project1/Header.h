#include <iostream>
#include <vector>
#include<string>
#include "Elevator.h"

using namespace std;


int WorstToBest()
{
	char scene;
	int choice;
	cout << "\nWhich case would you like to run (1,2,3): Hint pick 1 :"; //hint pick 1
	
	bool tobreak = false;
	
	while (tobreak == false)
	{
		
		
		cin >> scene;
		switch (scene)
		{
		case '1':
			cout << "Ok you picked best case scenario: \n";
			choice = 1;
			tobreak = true;
			break;

		case '2':
			cout << "Ok you picked medium case scenario: \n";
			choice =2;
			tobreak = true;
			break;

		case '3':
			cout << "Ok you picked worst case scenario: \n";
			choice = 3;
			tobreak = true;
			break;

	

		default:
			cout << "\nPlease pick (1,2,3)\n";
			
			
			tobreak = false;
			break;
		}
	}
	return choice;

}

//void randomizer(int numPeople)
//{
//
//
//}
void SceneCreator(int choice,int numElevtor, int numPeople, vector<Elevator>& elevators, vector<Person>& people)
{

	//vector<Elevator> elevators;
	Elevator newElevator;

	//vector<Person> people;
	Person newPerson;

	//Elevator(int elevatornumber, int currentfloor, bool direction)
	for (int i = 1; i <= numElevtor; i++)
	{
		newElevator = Elevator(i, 0, true);
		elevators.push_back(newElevator);

	}
	//Person(int starttime, int startfloor, int desiredfloor, bool directionUP);





	//Best case scene 1
	switch (choice)
	{
	case 1:
		for (int i = 0; i <= numPeople; i++)
		{
			newPerson = Person(i,(0 + i), (0 + i), (1 + i), true);
		}
		break;

	case 2:
		cout << "Just wait";
		break;

	case 3:
		cout << "Just wait";
		break;

	default:
		cout << " nothing here";
	}
	
}