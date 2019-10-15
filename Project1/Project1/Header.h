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
void SceneCreator(int floor,int numElevtor, int numPeople, vector<Elevator>& elevators, vector<Person>& people)
{

	//vector<Elevator> elevators;
	Elevator newElevator;

	//vector<Person> people;
	Person newPerson;

	//Elevator(int elevatornumber, int currentfloor, bool direction)
	for (int i = 0; i < numElevtor; i++)
	{
		newElevator = Elevator((i+1), 0, true);
		elevators.push_back(newElevator);

	}
	


	//Person(int personid,int starttime, int startfloor, int desiredfloor, bool direction)
	//Make a constant time
	for (int i = 0; i < numPeople; i++)
	{
		newPerson = Person((i + 1), (rand() % 30), ((rand()  % floor)+1), ((rand() % floor)+1));
		while (newPerson.getDesiredFloor() == newPerson.getStartingFloor())
		{
			newPerson = Person((i + 1), (rand() % 30), ((rand() % floor) + 1), ((rand() % floor) + 1));

		}
			
		people.push_back(newPerson);
	}


	
	
}


void display(vector<int> Anything)
{
	cout << "\n\n Here is the vector: ";
	int size = Anything.size();
	for (int i = 0; i < size; i++)
	{
		cout << Anything[i] << ", ";
	}
}


void sortThis(vector <int> &num)
{
	int i, j, key;

	bool insertionNeeded = false;
	int size = num.size();
	for (j = 1; j < size; j++)
	{
		key = num[j];
		insertionNeeded = false;
		for (i = j - 1; i >= 0; i--) {
			if (key < num[i]) {
				num[i + 1] = num[i]; // larger values move right
				insertionNeeded = true;
			}
			else
				break;
		}
		if (insertionNeeded)
			num[i + 1] = key;    //Put key into its proper location
	}

}
