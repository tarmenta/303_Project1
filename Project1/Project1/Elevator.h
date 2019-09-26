#include<iostream>
#include<vector>
#include"Person.h"

using namespace std;


class Elevator
{
private:
	int elevatorNumber;
	int currentFloor;
	int pendingFloor;
	bool goingUp;






public:
	Elevator();
	Elevator(int elevatornumber, int currentfloor, bool direction)
	{
		elevatorNumber = elevatornumber;
		currentFloor = currentfloor;
		goingUp = direction;
	}






};