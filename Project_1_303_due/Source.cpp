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
	while (wheelTime < 60)
	{
		wheeloTime(elevators, people, wheelTime, requesters);
		





		//passrequester instead
		if (!requesters.empty())
		{
			oragizedRequester(requesters);
			oraganizeUpDown(requesters, people_going_up, people_going_down);

			if (!people_going_up.empty())
			{
				oraganizeEmptyU(elevators, people_going_up);
			}
			if (!people_going_down.empty())
			{
				oraganizeEmptyD(elevators, people_going_down);
			}
			
		}
		








		//Display Decsion Time

		cout << "\n****************\n";
		
		if (people_going_up.empty() && people_going_down.empty())
		{
			cout << "No one to go anywhere";

		}
		if (!people_going_up.empty())
		{

			decidingU(elevators, people_going_up,requesters);
		}
		if (!people_going_down.empty())
		{
			decidingD(elevators, people_going_down,requesters);
		}

		int y;
		cin >> y;

		

	}


	int x;
	cin >> x;
	return 0;
}