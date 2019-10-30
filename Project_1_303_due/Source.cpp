#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<time.h>
#include "Header.h"




using namespace std;


int main()
{
	int wheelTime = 0;
	//Intro Choices
	int numberElevators;
	int numberPeople;
	//	int floors;
	//	int choice;

	cout << "Welcome to the elevator sim\n";
	cout << "How many elevators are in the building: ";
	cin >> numberElevators;
	cout << "\nHow many people will there be: ";
	cin >> numberPeople;


	vector<Elevator> elevators;
	vector<Person> people;           //ALL THE PEOPLE 
	vector<Person> people_going_up;  // ALL THE PEOPLE GOING UP
	vector<Person> people_going_down;//ALL THE PEOPLE GOING Down
	vector<Person> requesters;       //People requesting

									 //cout << "\nHere is your scene: \n";
	SceneCreator(numberElevators, numberPeople, elevators, people); /// MAKES SCENE
																	//Scene has that cout
	displayPeople(people);



	//T-man Display
	cout << "\nStarting simulation\n";
	while (wheelTime < 30)
	{
		wheeloTime(elevators, people, wheelTime, requesters);
		////display elevator postion
		//for (int i = 0; i < numberElevators; i++)
		//{
		//	cout << elevators[i].getNumber() << "Elevator at Floor " << elevators[i].getFloor() << "\n";
		//}
		////Display people requests by time
		//vector<Person> requesters;
		//bool itZero = true;
		//for (int i = 0; i < numberPeople; i++)
		//{
		//	
		//	Person requester;
		//	if (people[i].getStartTime() == wheelTime)
		//	{
		//		requester = people[i];
		//		cout << "Requests\nPerson " << requester.getPersonID() << "starts at floor" << requester.getStartingFloor();
		//		requesters.push_back(requester);
		//		itZero = false;
		//	}
		//	else if (itZero && (i == (numberPeople-1)))
		//	{
		//		cout << "\nNo Requests at this time\n";
		//	}
		//	
		//}





		/// SELECTION SORT FUNCTION LOW TO HIGH.
		//Display function
		//cout << "\nThese are the STARTING FLOOR CALLS UNORGANIZED" << endl;
		/*for (int i = 0; i < people.size(); i++) {
		cout <<"\nPerson # "<<people[i].getPersonID()<< " :   Starting Floor: "<< people[i].getStartingFloor() <<" Destination Floor: "<< people[i].getDesiredFloor()<< endl;
		}*/
		//displayPeople(people);





		//passrequester instead
		if (!requesters.empty())
		{
			oragizedRequester(requesters);
			oraganizeUpDown(requesters, people_going_up, people_going_down);
			oraganizeEmptyU(elevators, people_going_up);
			oraganizeEmptyD(elevators, people_going_down);
		}
		//cout << "\nSize of vector The PEOPLE VECTOR is : " << people.size()<< endl;
		//Orgainizing people by size
		//for (int i = 0; i < people.size(); i++) {
		//	int indexSmallest = i;
		//	for (int j = i + 1; j < (people.size()); j++) {

		//		if (people[j].getStartingFloor() < people[indexSmallest].getStartingFloor()) {
		//			indexSmallest = j;
		//	
		//		}
		//	}

		//	// Swap numbers[i] and numbers[indexSmallest]
		//	Person temp = people[i];
		//	people[i] = people[indexSmallest];
		//	people[indexSmallest] = temp;
		//	
		//}



		//Display 
		//cout << "******\n" << people.size() << endl << "This is the PEOPLE VECTOR calls organized" << endl;
		//people.erase(people.end());

		/*for (int i = 0; i < people.size(); i++) {
		cout << "\nPerson # " << people[i].getPersonID() << " :   Starting Floor: " << people[i].getStartingFloor() << " Destination Floor: " << people[i].getDesiredFloor() << endl;
		}*/
		//displayPeople(people);
		//cout << "*******\n" << people.size() << endl;



		//Oraganize up and down
		//Sorting up from down puts into up vector and down vector
		//for (int i = 0; i < people.size(); i++) {
		//	if (people[i].getDirection() == false) {
		//		people_going_down.push_back(people[i]); // THIS HERE SHOULD SORT THE UP CALLS AND DOWN CALLS
		//		
		//	}
		//	else if (people[i].getDirection() == true) {
		//		people_going_up.push_back(people[i]); // THIS HERE SHOULD SORT THE UP CALLS AND DOWN CALLS

		//	}
		//}
		//pass people instead
		////oraganizeUpDown(requesters, people_going_up, people_going_down);




		//Display
		//cout << "\nTHIS IS THE NEW DOWN VECTOR SIZE: " << people_going_down.size() << endl;
		//cout << "\nHERE IS THE GOING DOWN ENTRIES:\n" << endl;
		//displayPeople(people_going_down);
		/*for (int i = 0; i < people_going_down.size(); i++) {
		cout << "\nPerson # " << people_going_down[i].getPersonID()  << " :   Starting floor: " << people_going_down[i].getStartingFloor() << " Destination Floor: " << people_going_down[i].getDesiredFloor()<< endl;
		}*/
		//cout << "stop \n THE PEOPLE GOING UP VECTOR SIZE IS NOW " << people_going_up.size() <<"\n"<< endl;



		//Display
		//cout << "\nHERE IS THE GOING UP ENTRIES:\n" << endl;

		//reverse(people_going_down.begin(), people_going_down.end()); //REVERSES THE GOING DOWN VECTOR FOR PROCESSING

		///cout << "stop \n LARGE TO SMALLEST" << people.size() << endl;
		//displayPeople(people_going_up);
		/*for (int i = 0; i < people_going_up.size(); i++) {
		cout << "\nPerson # " << people_going_up[i].getPersonID() << " :   Starting floor: " << people_going_up[i].getStartingFloor() << " Destination Floor: " << people_going_up[i].getDesiredFloor() << endl;
		}*/






		//oragnize epmpty?
		//calculates responses for proximity

		/*if (!people_going_up.empty()) {
		elevators[0].set_Response_Up(people_going_up[0].getStartingFloor());
		elevators[1].set_Response_Up(people_going_up[0].getStartingFloor());
		}
		if (!people_going_down.empty()) {
		elevators[0].set_Response_Down(people_going_down[0].getStartingFloor());

		elevators[1].set_Response_Down(people_going_down[0].getStartingFloor());
		}*/

		//pass elevators with people going up
		/*oraganizeEmptyU(elevators, people_going_up);
		oraganizeEmptyD(elevators, people_going_down);*/




		//idk!
		/// WILL DECIDE WHAT ELEVATOR GOES TO WHAT AND DOES FINAL PROCESS.  
		/// This gets the proximity for each elevator
		//cout << elevators[0].get_Response_Up() << endl;
		//cout << elevators[1].get_Response_Up() << endl;



		//Display Decsion Time

		cout << "\n****************\n";
		//meh
		/*for (int i = 0; i < numberElevators; i++)
		{
		cout << "Elevator " << elevators[i].getNumber();
		}
		*/
		if (people_going_up.empty() && people_going_down.empty())
		{
			cout << "No one to go anywhere";

		}
		if (!people_going_up.empty())
		{

			decidingU(elevators, people_going_up, people_going_down);
		}
		if (!people_going_down.empty())
		{
			decidingD(elevators, people_going_up, people_going_down);
		}

		int y;
		cin >> y;

		//deciding(elevators, people_going_up, people_going_down);
		//decidingD(elevators, people_going_up, people_going_down);



		////IF PEOPLE ARE GOING UP AND ELEVATOR 1 PROXIMITY IS LOWER THAN ELEVATOR 2,ELEVATOR 1 WILL GO FIRST AND TAKE UP CALLS
		//if (!people_going_up.empty() && ( elevators[0].get_Response_Up() < elevators[1].get_Response_Up())) {
		//	cout << "Elevator 1 on floor " << elevators[0].getFloor()<< " is closer and will handle the up calls.\n\n" << endl;
		//	elevators[0].elevator_moving(people_going_up);
		//	//IF THE  PEOPLE GOING DOWN VECTOR IS FILLED
		//	if (!people_going_down.empty()) {
		//		cout << "Elevator 2 on floor " << elevators[1].getFloor() << " is  will handle the down calls.\n\n" << endl;
		//		elevators[1].elevator_moving(people_going_down);
		//	}
		//}
		////IF PEOPLE ARE GOING UP AND ELEVATOR 1 PROXIMITY IS LOWER THAN ELEVATOR 1,ELEVATOR 2 WILL GO FIRST AND TAKE UP CALLS
		//else if (!people_going_up.empty() && (elevators[1].get_Response_Up() < elevators[0].get_Response_Up())) {
		//	cout << "Elevator 2 on floor " << elevators[1].getFloor() << " is closer and will handle the up calls.\n\n" << endl;
		//	elevators[1].elevator_moving(people_going_up);
		//	//IF THE  PEOPLE GOING DOWN VECTOR IS FILLED
		//	if (!people_going_down.empty()) {
		//		cout << "Elevator 1 on floor " << elevators[0].getFloor() << " is  will handle the down calls.\n\n" << endl;
		//		elevators[0].elevator_moving(people_going_down);
		//	}
		//}
		////IF ELEVATOR 1 AND 2 ARE ON THE SAME FLOOR
		//else if (!people_going_up.empty() && (elevators[0].get_Response_Up() == elevators[1].get_Response_Up())){
		//	cout << " Elevators are on the same floor. Elevator 1 will move first and will handle the up calls.\n\n" << endl;
		//	elevators[0].elevator_moving(people_going_up);

		//	if (!people_going_down.empty()) {
		//		cout << "Elevator 2 on floor " << elevators[1].getFloor() << " is will handle the down calls.\n\n" << endl;
		//		elevators[1].elevator_moving(people_going_down);
		//	}
		//}
		////IF THERE ARE  ONLY DOWN CALLS AND ELEVATOR 1 IS CLOSER
		//else if (people_going_up.empty() && (elevators[0].get_Response_Down() < elevators[1].get_Response_Down())) {
		//	cout << "Elevator 1 on floor " << elevators[0].getFloor() << " is closer and will handle the down calls.\n\n" << endl;
		//	elevators[0].elevator_moving(people_going_down);
		//	
		//}
		////IF THERE ARE  ONLY DOWN CALLS AND ELEVATOR 2 IS CLOSER
		//else if (people_going_up.empty() && (elevators[1].get_Response_Down() < elevators[0].get_Response_Down())) {
		//	cout << "Elevator 2 on floor " << elevators[1].getFloor() << " is closer and will handle the down calls.\n\n" << endl;
		//	elevators[1].elevator_moving(people_going_down);
		//	
		//	
		//}
		//
		////IF THERE ARE  ONLY DOWN CALLS AND BOTH ARE ONE THE SAME FLOOR
		//else if (people_going_up.empty() && (elevators[0].get_Response_Down() == elevators[1].get_Response_Down()))
		//{
		//	cout << "Elevators are on the same floor. Elevator 1 will move first and will handle the down calls.\n\n" << endl;
		//	
		//	elevators[0].elevator_moving(people_going_down);

		//	
		//}

	}


	int x;
	cin >> x;
	return 0;
}