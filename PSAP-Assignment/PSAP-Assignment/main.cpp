#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int randomIntegerGenerator() {
	int randomNumber = (rand() % 10) + 1;
	return randomNumber;
}

int calculateRunnerPosition(int position_runner, bool verifyRunner, int randomNumber) {
	if (verifyRunner == true)
	{
		if (randomNumber >= 1 && randomNumber <= 5)
		{
			position_runner += 3;
			cout << "Runner 1 uses SPRINT and move 3 squares ahead." << endl;
		}
		else if (randomNumber >= 6 && randomNumber <= 7)
		{
			position_runner += 1;
			cout << "Runner 1 uses JOG and move 1 square ahead." << endl;
		}
		else
		{
			if (position_runner <= 1)
			{
				position_runner = 1;
				cout << "Runner 1 uses WALK and return to starting point." << endl;
			}
			else
			{
				position_runner -= 6;
				cout << "Runner 1 uses WALK and move 6 squares behind." << endl;
			}
		}
	}
	else
	{
		if (randomNumber >= 1 && randomNumber <= 3)
		{
			position_runner += 5;
			cout << "Runner 2 uses FAST SPRINT and move 5 squares ahead." << endl;
		}
		else if (randomNumber >= 4 && randomNumber <= 5)
		{
			position_runner += 3;
			cout << "Runner 2 uses RUN and move 3 squares ahead." << endl;
		}
		else if (randomNumber == 6)
		{
			if (position_runner <= 1)
			{
				position_runner = 1;
				cout << "Runner 1 uses WALK and return to starting point." << endl;
			}
			else
			{
				position_runner -= 2;
				cout << "Runner 2 uses WALK and move 2 squares behind." << endl;
			}
		}
		else if (randomNumber >= 7 && randomNumber <= 8)
		{
			if (position_runner <= 1)
			{
				position_runner = 1;
				cout << "Runner 1 uses CRAWL and return to starting point." << endl;
			}
			else
			{
				position_runner -= 4;
				cout << "Runner 2 uses CRAWL and move 4 squares behind." << endl;
			}
		}
		else
		{
			cout << "Runner 2 uses SLEEP and nothing happens." << endl;
		}
	}

	return position_runner;
}

void showRunnersLocation(int position_runnerOne, int position_runnerTwo) {
	if (position_runnerOne == position_runnerTwo && position_runnerOne != 1)
	{
		cout << "GOTCHA " << setw(position_runnerOne) << right << setfill(' ') << 1 << setw(60 - abs(position_runnerOne)) << ' ' << endl;
		cout << "GOTCHA " << setw(position_runnerTwo) << right << setfill(' ') << 2 << setw(60 - abs(position_runnerTwo)) << ' ' << endl;
	}
	else
	{
		cout << setw(position_runnerOne) << right << setfill('-') << 1 << setw(60 - abs(position_runnerOne)) << '-' << endl;
		cout << setw(position_runnerTwo) << right << setfill('-') << 2 << setw(60 - abs(position_runnerTwo)) << '-' << endl;
	}
}

int main() {
	int position_runnerOne = 1;
	int position_runnerTwo = 1;
	int randomNumber;
	srand((unsigned)time(NULL));

	while(true)
	{
		randomNumber = randomIntegerGenerator();
		cout << "No: " << randomNumber << endl;
		position_runnerOne = calculateRunnerPosition(position_runnerOne, true, randomNumber);
		showRunnersLocation(position_runnerOne, position_runnerTwo);
		if (position_runnerOne >= 60)
		{
			cout << "RUNNER #1 WINS!" << endl;
			break;
		}

		randomNumber = randomIntegerGenerator();
		cout << "No: " << randomNumber << endl;
		position_runnerTwo = calculateRunnerPosition(position_runnerTwo, false, randomNumber);
		showRunnersLocation(position_runnerOne, position_runnerTwo);
		if (position_runnerTwo >= 60)
		{
			cout << "RUNNER #2 WINS!" << endl;
			break;
		}
	}

	return 0;
}