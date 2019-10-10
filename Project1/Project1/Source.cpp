#include<iostream>
#include<vector>
#include "Header.h"

using namespace std;


int main()
{
	//Intro Choices
	int numberElevators;
	int numberPeople;
	int floors;
	int choice;

	cout << "Welcome to the elevator sim\n";
	cout << "How many elevators are in the building: ";
	cin >> numberElevators;
	cout << "\nHow many floors are in your building: ";
	cin >> floors;
	cout << "\nHow many people will there be: ";
	cin >> numberPeople;
	
	//Pick your scenario
	choice = WorstToBest();
	cout << "\nHere is your scene: \n";

	//Creating the vectors
	vector<Elevator> elevators;
	vector<Person> people;
	SceneCreator(choice,numberElevators, numberPeople, elevators, people);
	//lets see    maybe also put this into another header

	
	for (int i = 0; i < numberElevators; i++)
	{
		cout << "\nElevator: " << elevators[i].getNumber() << "\n  floor: " << elevators[i].getFloor() << "\n  Pending: " << elevators[i].getPending() << "\n  direction: " << elevators[i].getDirection();
	}

	//cout << people[1].getPersonID();
	
	for (int i = 0; i < numberPeople; i++)
	{
		cout << "\nPerson: " << people[i].getPersonID() << "\n  Arrival time: " << people[i].getStartTime() << "\n  Starting floor: " << people[i].getStartingFloor() << "\n  Desired floor: " << people[i].getDesiredFloor();
	}
	int x;
	cin >> x;

	return 0;
}