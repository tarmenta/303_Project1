#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int main() {
	int floornum;
	int floor_request;
	int peoplenum;
	int exit_time;
	int wait_Time = 0;
	string up_or_down;


	cout << "This is the elevator simulator\n" << endl;
	vector <int> elevator1;
	vector <int> elevator1A;
	while (true) {
		cout << "What floor is this request?\n" << endl;  // floor request ask
		cin >> floor_request;


		cout << "Are you going up or down?\n" << endl; // will ask if you are going up or down
		cin >> up_or_down;


		cout << " How many people are entering the elevator?\n" << endl; //asks how many people are goin in at one time
		cin >> peoplenum;

		cout << "What floor is everyone going to?\n" << endl; // this will ask everyone what floor they are going to. then uses pushback to put it in the vector
		for (int i = 0; i < peoplenum; i++) {
			cout << "Person " << i + 1 << " What floor are you going too ?\n";
			cin >> floornum;

			if (find(elevator1.begin(), elevator1.end(), floornum) != elevator1.end())
				cout << "\n";
			else
				elevator1.push_back(floornum);
		}


		sort(elevator1.begin(), elevator1.end()); // this will sort the vector using the "include algorithm"
		for (int k = 0; k < elevator1.size(); k++) {
			cout << elevator1[k] << "\n";
		}
		/// THIS SECTION HANDLE INPUT IF PEOPLE ARE GOING DOWN ON AN UP ELEVATOR
		while (((elevator1.at(0) < floor_request) && (up_or_down == "UP"))) { // WHILE THE FIRST INDEX IS LESS THAN FLOOR WHILE GOING UP
			elevator1.push_back(elevator1.at(0));                            // PUSH THAT TO THE END
			elevator1.erase(elevator1.begin() + 0);                            // DELETE THAT FIRST INDEX
			if (elevator1[0] >= floor_request) {                             // ONCE HIGHER  STOOP
				break;
			}
			//cout << "\n\n " << elevator1.at(0) << " This is next\n\n"; JUST FOR TESTING

		}
		///////////////

		/// 
		//THIS WILL PROCESS EACH FLOOR AND  TIMES


		while ((elevator1.at(0) < floor_request) == false) { // This will subtract the elevator floor from the call floor and multiply it times 5

			cout << "\n\n" << "To get to floor " << elevator1[0] << " took aprox: " << (elevator1.at(0) - floor_request) * 5 << " seconds.\n\n" << endl;
			elevator1.erase(elevator1.begin() + 0);
			wait_Time += 5;
		}

		reverse(elevator1.begin(), elevator1.end());// REVERSES VECTOR IN DECENDING ORDER

	}

}