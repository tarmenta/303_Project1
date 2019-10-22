#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<time.h>
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

	cout << "\nHere is your scene: \n";

	//Creating the vectors
	vector<Elevator> elevators;
	vector<Person> people;           //ALL THE PEOPLE GOING UP
	vector<Person> people_going_down;//ALL THE PEOPLE GOING Down
	SceneCreator(numberElevators, numberPeople, elevators, people);


	//lets see   maybe also put this into another header


	//for (int i = 0; i < numberElevators; i++)
	//{
	//	cout << "\nElevator: " << elevators[i].getNumber() << "\n  floor: " << elevators[i].getFloor() << "\n  Pending: " << elevators[i].getPending() << "\n  direction: " << elevators[i].getDirection();
	//}

	//cout << people[1].getPersonID();

	//for (int i = 0; i < numberPeople; i++)
	//{
	//	cout << "\nPerson: " << people[i].getPersonID() << "\n  Arrival time: " << people[i].getStartTime() << "\n  Starting floor: " << people[i].getStartingFloor() << "\n  Desired floor: " << people[i].getDesiredFloor();
	//}
	//int x;
	//cin >> x;

	//RECENTLY ADD STUFF(WILL)

	/// SELECTION SORT FUNCTION LOW TO HIGH.
	cout << "\nThese are the STARTING FLOOR CALLS UNORGANIZED" << endl;
	for (int i = 0; i < people.size(); i++) {
		cout << "\nStarting Call: " << people[i].getStartingFloor() << " Destination Floor: " << people[i].getDesiredFloor() << endl;
	}

	cout << "stop\nSize of vector is : " << people.size() << endl;


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

	cout << "******\n" << people.size() << endl << "This is the vector calls organized" << endl;
	//people.erase(people.end());

	for (int i = 0; i < people.size(); i++) {
		cout << "\nStarting Call: " << people[i].getStartingFloor() << " Destination Floor: " << people[i].getDesiredFloor() << endl;
	}
	cout << "*******\n" << people.size() << endl;

	for (int i = 0; i < people.size(); i++) {
		if (people[i].getDirection() == false) {
			people_going_down.push_back(people[i]); // THIS HERE SHOULD SORT THE UP CALLS AND DOWN CALLS
			people.erase(people.begin() + i);
		}
	}

	cout << "\nTHIS IS THE NEW DOWN VECTOR\nSIZE: " << people_going_down.size() << endl;

	for (int i = 0; i < people_going_down.size(); i++) {
		cout << "\nStarting Call: " << people_going_down[i].getStartingFloor() << " Destination Floor: " << people_going_down[i].getDesiredFloor() << endl;
	}
	cout << "stop \n THE OLD PEOPLE SIZE IS NOW " << people.size() << "\n" << endl;

	//reverse(people_going_down.begin(), people_going_down.end()); //REVERSES THE GOING DOWN VECTOR FOR PROCESSING

	///cout << "stop \n LARGE TO SMALLEST" << people.size() << endl;

	for (int i = 0; i < people_going_down.size(); i++) {
		cout << "\nStarting Call: " << people_going_down[i].getStartingFloor() << " Destination Floor: " << people_going_down[i].getDesiredFloor() << endl;
	}

	//calculates responses for proximity

	if (!people.empty()) {
		elevators[0].set_Response_Up(people[0].getStartingFloor());
		elevators[1].set_Response_Up(people[0].getStartingFloor());
	}
	if (!people_going_down.empty()) {
		elevators[0].set_Response_Down(people_going_down[1].getStartingFloor());

		elevators[1].set_Response_Down(people_going_down[1].getStartingFloor());
	}


	/// WILL DECIDE WHAT ELEVATOR GOES TO WHAT AND DOES FINAL PROCESS.   //// NOT FINISHED YET
	cout << elevators[0].get_Response_Up() << endl;
	cout << elevators[1].get_Response_Up() << endl;
	if (elevators[0].get_Response_Up() < elevators[1].get_Response_Up()) {
		cout << "Elevator 1 on floor " << elevators[0].getFloor() << " is closer and will handle the up calls.\n\n" << endl;
		elevators[0].elevator_moving(people);
		cout << "Elevator 2 on floor " << elevators[1].getFloor() << " is  will handle the down calls.\n\n" << endl;
		elevators[1].elevator_moving(people_going_down);
	}
	else if (elevators[1].get_Response_Up() < elevators[0].get_Response_Up()) {
		cout << "Elevator 2 on floor " << elevators[1].getFloor() << " is closer and will handle the up calls.\n\n" << endl;
		elevators[1].elevator_moving(people);
		cout << "Elevator 1 on floor " << elevators[0].getFloor() << " is  will handle the down calls.\n\n" << endl;
		elevators[0].elevator_moving(people_going_down);
	}
	else if (elevators[0].get_Response_Up() == elevators[1].get_Response_Up()) {
		cout << " Elevators are on the same floor. Elevator 1 will move first and will handle the up calls.\n\n" << endl;

		elevators[0].elevator_moving(people);
		cout << "Elevator 2 on floor " << elevators[1].getFloor() << " is will handle the down calls.\n\n" << endl;
		elevators[1].elevator_moving(people_going_down);
	}

	return 0;
}