#pragma once
#include<iostream>
#include <vector>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<time.h> //FOR SRAND()
#include "Elevator.h"

using namespace std;



void displayPeople(vector<Person> people)
{
	if (people.size() == 0)
	{
		cout << "\nempty\n";
	}
	for (int i = 0; i < people.size(); i++) {
		cout << "\nPerson # " << people[i].getPersonID() << " :   Starting Floor: " << people[i].getStartingFloor() << " Destination Floor: " << people[i].getDesiredFloor() << endl;
		cout << "\nStarting time" << people[i].getStartTime() << endl;
	}
}

void SceneCreator(int numElevtor, int numPeople, vector<Elevator>& elevators, vector<Person>& people)
{

	//vector<Elevator> elevators;
	Elevator newElevator;

	//vector<Person> people;
	Person newPerson;

	//Elevator(int elevatornumber, int currentfloor, bool direction)
	for (int i = 0; i < numElevtor; i++)
	{
		if (i == 0)
		{
			newElevator = Elevator((i + 1), 0, true);
		}
		else if (i == 1)
		{
			newElevator = Elevator((i + 1), 0, false);
		}
		else if (i % 2 == 0)
		{
			newElevator = Elevator((i + 1), 0, true);

		}
		else if (i % 2 == 1)
		{
			newElevator = Elevator((i + 1), 0, false);
		}
		elevators.push_back(newElevator);

	}



	//Person(int personid,int starttime, int startfloor, int desiredfloor)




	//MAKES PEOPLE AND THEIR REQUESTS. INITALIZES IF THEY ARE GOING UP OR DOWN
	srand(time(NULL));
	for (int i = 0; i < numPeople; i++)
	{
		newPerson = Person((i + 1), (rand() % 29) + 1, ((rand() % 9) + 1), ((rand() % 9) + 1));
		while (newPerson.getStartingFloor() == newPerson.getDesiredFloor()) {                   // IF EXAMPLE REQUEST THE SAME FLOOR AS THEY ARE ON
			newPerson = Person((i + 1), (rand() % 29) + 1, ((rand() % 9) + 1), ((rand() % 9) + 1));// THIS WILL KEEP GOING UNTIL THEY GET A NEW ONE. 
		}
		if (newPerson.getDesiredFloor() > newPerson.getStartingFloor()) {  // LETS PROGRAM KNOW IF PERSON is GOING UP
			newPerson.setDirection(true);
		}
		else {
			newPerson.setDirection(false);

		}

		people.push_back(newPerson);
		//cout << "THE SIZE OF THIS IS\n" << people.size() << endl;
	}


}
void sortUp(vector<Person>&calls)
{
	if (calls[0].getDirection() == true)
	{
		for (int i = 0; i < calls.size(); i++) {

			int indexSmallest = i;
			for (int j = i + 1; j < (calls.size()); j++) {

				if (calls[j].getDesiredFloor() < calls[indexSmallest].getDesiredFloor()) {/// SELECTION SORT
					indexSmallest = j;

				}
			}

			// Swap numbers[i] and numbers[indexSmallest]
			Person temp2 = calls[i];
			calls[i] = calls[indexSmallest];
			calls[indexSmallest] = temp2;

		}
	}
}
void oragizedRequester(vector<Person>& people)
{

	if (people.size() > 1)
	{


		//Sorting
		for (int i = 0; i < people.size(); i++) {
			int indexSmallest = i;
			for (int j = i + 1; j < (people.size()); j++) {

				if (people[j].getStartingFloor() < people[indexSmallest].getStartingFloor()) {
					indexSmallest = j;

				}
			}

			// Swap numbers[i] and numbers[indexSmallest]
			Person temp = people[i];
			people[i] = people[indexSmallest];
			people[indexSmallest] = temp;

		}
	}
}

void oraganizeUpDown(vector<Person> people, vector<Person>& people_going_up, vector<Person>& people_going_down)
{

	////clear the up and down
	//if (!people_going_up.empty())
	//{
	//	people_going_up.clear();
	//}
	//if (!people_going_down.empty())
	//{
	//	people_going_down.clear();
	//}

	for (int i = 0; i < people.size(); i++) {
		if (people[i].getDirection() == false) {
			people_going_down.push_back(people[i]); // THIS HERE SHOULD SORT THE UP CALLS AND DOWN CALLS

		}
		else if (people[i].getDirection() == true) {
			people_going_up.push_back(people[i]); // THIS HERE SHOULD SORT THE UP CALLS AND DOWN CALLS

		}

	}
}

int checkProxU(vector<Elevator>elevators)
{
	int size = elevators.size();
	int sizeup;
	vector<Elevator> ups;
	for (int i = 0; i < size; i++)
	{
		if (elevators[i].getUpDown() == true)
		{
			ups.push_back(elevators[i]);
		}
	}
	if (ups.empty())
	{

		return -1; //handle this return
	}
	else
	{
		sizeup = ups.size();
	}
	int x = 0;
	if (sizeup == 1)
	{
		return 0;  //returning the 0 index
	}


	for (int i = 1; i < sizeup; i++)
	{
		if ((ups[x].get_Response_Up() - ups[x].getFloor()) <= (ups[i].get_Response_Up() - ups[i].getFloor()))
		{
			x = i - 1;
		}
		else
		{
			x = i;
		}

	}
	return x;

}

int checkProxD(vector<Elevator>elevators)
{

	int size = elevators.size();
	int sizedown;
	vector<Elevator> downs;
	for (int i = 0; i < size; i++)
	{
		if (elevators[i].getUpDown() == false)
		{
			downs.push_back(elevators[i]);
		}
	}
	if (downs.empty())
	{

		return -1;
	}
	else
	{

		sizedown = downs.size();
	}
	int x = 0;
	if (sizedown == 1)
	{
		return 0;
	}

	for (int i = 1; i < sizedown; i++)
	{

		if ((downs[x].get_Response_Down() - downs[x].getFloor()) <= (downs[i].get_Response_Down() - downs[i].getFloor()))
		{
			x = i - 1;
		}
		else
		{
			x = i;
		}

	}
	return x;

}

void oraganizeEmptyU(vector<Elevator>& elevators, vector<Person> people_going_dir)
{
	sortUp(people_going_dir);
	
	//messed up?
	int size = elevators.size();
	int person = people_going_dir.size();
	for (int i = 0; i < size; i++)
	{
		if (!people_going_dir.empty())
		{
			
			elevators[i].set_Response_Up(people_going_dir[person].getStartingFloor());
			//elevators[1].set_Response_Up(people_going_dir[0].getStartingFloor());
		}
	}
}

void oraganizeEmptyD(vector<Elevator>& elevators, vector<Person> people_going_dir)
{
	sortUp(people_going_dir);
	int size = elevators.size();
	int person = people_going_dir.size();

	for (int i = 0; i < size; i++)
	{
		if (!people_going_dir.empty())
		{
			elevators[i].set_Response_Down(people_going_dir[person].getStartingFloor());
			//elevators[1].set_Response_Up(people_going_dir[0].getStartingFloor());
		}
	}
}

void decidingU(vector<Elevator>&elevators, vector<Person> people_going_up, vector<Person> people_going_down)
{
	int close = checkProxU(elevators);
	if (!people_going_up.empty())
	{
		cout << "Elevator " << elevators[close].getNumber() << " on floor " << elevators[close].getFloor();
		
		elevators[close].setuFloor();
		elevators[close].setdir(true);
		elevators[close].elevator_movingU(people_going_up);
		cout << "\nPicking up at floor " << elevators[close].getPending() << "\n";

		

	}
}
void decidingD(vector<Elevator>&elevators, vector<Person> people_going_up, vector<Person> people_going_down)
{
	int close = checkProxD(elevators);
	if (!people_going_down.empty())
	{
		cout << "Elevator " << elevators[close].getNumber() << " on floor " << elevators[close].getFloor() << " is closer and will handle the down calls.\nFirst going to ";
		elevators[close].elevator_movingD(people_going_down);
		cout << elevators[close].getPending() << "\n";
		elevators[close].setdFloor();
		elevators[close].setdir(false);

	}
}
void deciding(vector<Elevator>&elevators, vector<Person> people_going_up, vector<Person> people_going_down)
{

	//IF PEOPLE ARE GOING UP AND ELEVATOR 1 PROXIMITY IS LOWER THAN ELEVATOR 2,ELEVATOR 1 WILL GO FIRST AND TAKE UP CALLS
	if (!people_going_up.empty() && (elevators[0].get_Response_Up() < elevators[1].get_Response_Up())) {
		cout << "Elevator 1 on floor " << elevators[0].getFloor() << " is closer and will handle the up calls.\n\n" << endl;
		elevators[0].elevator_movingU(people_going_up);
		//IF THE  PEOPLE GOING DOWN VECTOR IS FILLED
		if (!people_going_down.empty()) {
			cout << "Elevator 2 on floor " << elevators[1].getFloor() << " is  will handle the down calls.\n\n" << endl;
			elevators[1].elevator_movingU(people_going_down);
		}
	}
	//IF PEOPLE ARE GOING UP AND ELEVATOR 1 PROXIMITY IS LOWER THAN ELEVATOR 1,ELEVATOR 2 WILL GO FIRST AND TAKE UP CALLS
	else if (!people_going_up.empty() && (elevators[1].get_Response_Up() < elevators[0].get_Response_Up())) {
		cout << "Elevator 2 on floor " << elevators[1].getFloor() << " is closer and will handle the up calls.\n\n" << endl;
		elevators[1].elevator_movingU(people_going_up);
		//IF THE  PEOPLE GOING DOWN VECTOR IS FILLED
		if (!people_going_down.empty()) {
			cout << "Elevator 1 on floor " << elevators[0].getFloor() << " is  will handle the down calls.\n\n" << endl;
			elevators[0].elevator_movingU(people_going_down);
		}
	}
	//IF ELEVATOR 1 AND 2 ARE ON THE SAME FLOOR
	else if (!people_going_up.empty() && (elevators[0].get_Response_Up() == elevators[1].get_Response_Up())) {
		cout << " Elevators are on the same floor. Elevator 1 will move first and will handle the up calls.\n\n" << endl;
		elevators[0].elevator_movingU(people_going_up);

		if (!people_going_down.empty()) {
			cout << "Elevator 2 on floor " << elevators[1].getFloor() << " is will handle the down calls.\n\n" << endl;
			elevators[1].elevator_movingU(people_going_down);
		}
	}
	//IF THERE ARE  ONLY DOWN CALLS AND ELEVATOR 1 IS CLOSER
	else if (people_going_up.empty() && (elevators[0].get_Response_Down() < elevators[1].get_Response_Down())) {
		cout << "Elevator 1 on floor " << elevators[0].getFloor() << " is closer and will handle the down calls.\n\n" << endl;
		elevators[0].elevator_movingU(people_going_down);

	}
	//IF THERE ARE  ONLY DOWN CALLS AND ELEVATOR 2 IS CLOSER
	else if (people_going_up.empty() && (elevators[1].get_Response_Down() < elevators[0].get_Response_Down())) {
		cout << "Elevator 2 on floor " << elevators[1].getFloor() << " is closer and will handle the down calls.\n\n" << endl;
		elevators[1].elevator_movingU(people_going_down);


	}
	//IF THERE ARE  ONLY DOWN CALLS AND BOTH ARE ONE THE SAME FLOOR
	else if (people_going_up.empty() && (elevators[0].get_Response_Down() == elevators[1].get_Response_Down())) {
		cout << "Elevators are on the same floor. Elevator 1 will move first and will handle the down calls.\n\n" << endl;
		elevators[0].elevator_movingU(people_going_down);


	}

}



void wheeloTime(vector<Elevator>elevators, vector<Person> people, int& wheelTime, vector<Person>& requesters)
{
	wheelTime++;
	/*if (!requesters.empty())
	{
	requesters.erase(requesters.begin());
	}*/

	int numberElevators, numberPeople;
	numberElevators = elevators.size();
	numberPeople = people.size();

	cout << "\nTime: " << wheelTime;
	cout << "\n___________________________________________\n";
	//display elevator postion
	for (int i = 0; i < numberElevators; i++)
	{
		cout << elevators[i].getNumber() << " Elevator at Floor " << elevators[i].getFloor() << "going " << elevators[i].getDirection() << "\n";
	}
	//Display people requests by time

	bool itZero = true;
	cout << "Requests:";
	for (int i = 0; i < numberPeople; i++)
	{

		Person requester;

		if (people[i].getStartTime() == wheelTime)
		{
			requester = people[i];
			cout << "\nPerson " << requester.getPersonID() << "starts at floor" << requester.getStartingFloor();
			requesters.push_back(requester);
			itZero = false;
		}
		else if (itZero && (i == (numberPeople - 1)))
		{
			cout << "\nNo Requests at this time\n";
		}

	}
	//once Exited pop that person
	if (!itZero)
	{
		for (int i = 0; i < elevators.size(); i++)
		{
			if (!(elevators[i].getexitingSize() == 0))
			{
				for (int j = 0; i < elevators[i].getexitingSize(); j++)
				{
					if (elevators[i].getExiting(j) == elevators[i].getFloor())
					{
						elevators[i].popExiting(j);
						for (int x = 0; x < requesters.size(); x++)
						{
							if (requesters[x].getPersonID() == elevators[i].getexitingId(j))
							{

								cout << "\nElevator " << elevators[i].getNumber() << " is letting Person " << requesters[x].getPersonID() << " off\n";
								requesters.erase(requesters.begin() + x);
							}
						}
					}
				}
			}
		}
	}



}