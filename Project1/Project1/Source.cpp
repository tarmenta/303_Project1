#include<iostream>
#include<vector>
#include "Header.h"
#include <ctime>

using namespace std;


int main()
{

	srand(time(0));
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
	
	////Pick your scenario   //Not gunna use it but ill leave it for now
	//choice = WorstToBest();
	cout << "\nHere is your scene: \n";

	//Creating the vectors
	vector<Elevator> elevators;
	vector<Person> people;
	SceneCreator(floors,numberElevators, numberPeople, elevators, people);
	//lets see    maybe also put this into another header







	//Make a Function to display for class vector
	
	for (int i = 0; i < numberElevators; i++)
	{
		cout << "\nElevator: " << elevators[i].getNumber() << "\n  floor: " << elevators[i].getFloor() << "\n  Pending: " << elevators[i].getPending() << "\n  direction: " << elevators[i].getDirection();
	}	
	for (int i = 0; i < numberPeople; i++)
	{
		cout << "\nPerson: " << people[i].getPersonID() << "\n  Arrival time: " << people[i].getStartTime() << "\n  Starting floor: " << people[i].getStartingFloor() << "\n  Desired floor: " << people[i].getDesiredFloor();
	}
	




	//This is creating something
	vector <int> elevator1;
	
	//Make a fuction that puts stuff in elevator1 
	cout << "\nWhat floor is everyone going to?\n" << endl; // this will ask everyone what floor they are going to. then uses pushback to put it in the vector
	for (int i = 0; i < numberPeople; i++) {
		cout << "\nPerson " << i + 1 << " is going to " <<people[i].getDesiredFloor();
		//cin >> floornum;

		/*if (find(elevator1.begin(), elevator1.end(), people[i].getDesiredFloor()) != elevator1.end())
			cout << "\n";
		else*/
		elevator1.push_back(people[i].getDesiredFloor());
	}



	vector<int> arrivalTimes;
	vector<int> namesPeople;
	for (int i = 0; i < numberPeople; i++) {
		//cout << "\nPerson " << i + 1 << " is going to " << people[i].getDesiredFloor();
		//cin >> floornum;

		/*if (find(elevator1.begin(), elevator1.end(), people[i].getDesiredFloor()) != elevator1.end())
			cout << "\n";
		else*/
		namesPeople.push_back(people[i].getPersonID());
		arrivalTimes.push_back(people[i].getStartTime());
	}

	//cout << "\n\nArrival\n";
	//display(arrivalTimes);
	//cout << "\n\nNames\n";
	//display(namesPeople);


	sortThis(arrivalTimes,namesPeople);

	/*cout << "\n\n Arrival\n";
	display(arrivalTimes);
	cout << "\n\nNames\n";
	display(namesPeople);*/

	int wheelTime = 0;
	//Start the moving process
	
	while (wheelTime <= 30)
	{
		cout << "\n\nAt time " << wheelTime;
		int i = 0;
		while (arrivalTimes[i] == wheelTime)
		{
			cout << "Person" << namesPeople[i] << " requests on floor" << people[namesPeople[i]-1].getStartingFloor();
			if (people[namesPeople[i] - 1].getDirection())
			{
				if (elevators[0].isGoing()) //Need to loop  to have more than 2 elevators
				{
					cout << "\nElevator" << elevators[0].getNumber()<< " is picking up " << namesPeople[i];
				}
				else
				{
					cout << "\nElevator" << elevators[1].getNumber()<< " is picking up " << namesPeople[i];
				}
			}
			i++;
		}

		
		//check who is going up or down
		//what elevator goes where
		
		wheelTime++;
	}
	cout << "\n\nElevator " << elevators[0].getNumber() << " will pick up ";
	//getting people there display the info
	//popping them from the vector display there wait time
	//showing avaerage wait time



	//display(elevator1);





	system("pause");
	return 0;
}