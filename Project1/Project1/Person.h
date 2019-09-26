
class Person    //People requesting and getting on elevator
{
private:
	int startTime;
	int startingFloor;
	int desiredFloor;
	bool goingUp;
	int waitTime;




public: // setters and getters for variables
	Person(); //Default constructor
	Person(int starttime, int startfloor, int desiredfloor, bool direction)
	{
		startTime = starttime;
		startingFloor = startfloor;
		desiredFloor = desiredfloor;

		if (direction)
		{
			goingUp = direction;
		}
		else
		{
			goingUp = false;
		}
	}

	int getStartTime()
	{
		return startTime;

	}

	int getStartingFloor()
	{
		return startingFloor;

	}

	int getDesiredFloor()
	{
		return desiredFloor;
	}

	int getDirection()
	{
		return goingUp;
	}

	int getTime()  // Figure out Wait times there has to be a way to explain efficiency
	{
		return waitTime;
	}

};