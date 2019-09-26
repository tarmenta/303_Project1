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
	char choice;

	cout << "Welcome to the elevator sim\n";
	cout << "How many elevators are in the building: ";
	cin >> numberElevators;
	cout << "\nHow many floors are in your building: ";
	cin >> floors;
	cout << "\nHow many people will there be: ";
	cin >> numberPeople;
	cout << "\nWould you like to randomize there starting floors (y/n): ";
	cin >> choice;
	YesorNo(choice);
	
	

	
	return 0;
}