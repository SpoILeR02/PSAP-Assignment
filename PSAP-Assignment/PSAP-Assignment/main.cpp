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
			cout << "Runner 1 SPRINTS and move 3 squares ahead." << endl;
		}
		else if (randomNumber >= 6 && randomNumber <= 7)
		{
			position_runner += 1;
			cout << "Runner 1 JOGS and move 1 square ahead." << endl;
		}
		else
		{
			if (position_runner <= 1 || position_runner - 6 <= 1)
			{
				position_runner = 1;
				cout << "Runner 1 WALKS and return to starting point." << endl;
			}
			else
			{
				position_runner -= 6;
				cout << "Runner 1 WALKS and move 6 squares behind." << endl;
			}
		}
	}
	else
	{
		if (randomNumber >= 1 && randomNumber <= 3)
		{
			position_runner += 5;
			cout << "Runner 2 FAST SPRINTS and move 5 squares ahead." << endl;
		}
		else if (randomNumber >= 4 && randomNumber <= 5)
		{
			position_runner += 3;
			cout << "Runner 2 RUNS and move 3 squares ahead." << endl;
		}
		else if (randomNumber == 6)
		{
			if (position_runner <= 1 || position_runner - 4 <= 1)
			{
				position_runner = 1;
				cout << "Runner 2 WALKS and return to starting point." << endl;
			}
			else
			{
				position_runner -= 2;
				cout << "Runner 2 WALKS and move 2 squares behind." << endl;
			}
		}
		else if (randomNumber >= 7 && randomNumber <= 8)
		{
			if (position_runner <= 1 || position_runner - 4 <= 1)
			{
				position_runner = 1;
				cout << "Runner 2 CRAWLS and return to starting point." << endl;
			}
			else
			{
				position_runner -= 4;
				cout << "Runner 2 CRAWLS and move 4 squares behind." << endl;
			}
		}
		else
		{
			cout << "Runner 2 SLEEPS and nothing happens." << endl;
		}
	}

	return position_runner;
}

void showRunnersLocation(int position_runnerOne, int position_runnerTwo) {
	if (position_runnerOne == position_runnerTwo && position_runnerOne != 1)
	{
		cout << "GOTCHA " << setw(position_runnerOne) << right << setfill(' ') << 1 << setw(60 - abs(position_runnerOne)) << ' ' << endl;
		cout << "GOTCHA " << setw(position_runnerTwo) << right << setfill(' ') << 2 << setw(60 - abs(position_runnerTwo)) << ' ' << endl << endl;
	}
	else
	{
		cout << setw(position_runnerOne) << right << setfill('-') << 1 << setw(60 - abs(position_runnerOne)) << '-' << endl;
		cout << setw(position_runnerTwo) << right << setfill('-') << 2 << setw(60 - abs(position_runnerTwo)) << '-' << endl << endl;
	}
}

int main() {
	int position_runnerOne = 1;
	int position_runnerTwo = 1;
	int timeframe = 1;
	int randomNumber;
	srand((unsigned)time(NULL));

	while(true)
	{
		cout << "Time Frame: " << timeframe << endl << endl;

		randomNumber = randomIntegerGenerator();
		cout << "Runner 1 Rolled Number: " << randomNumber << endl; //just for testing purposes
		position_runnerOne = calculateRunnerPosition(position_runnerOne, true, randomNumber);
		showRunnersLocation(position_runnerOne, position_runnerTwo);

		randomNumber = randomIntegerGenerator();
		cout << "Runner 2 Rolled Number: " << randomNumber << endl; //just for testing purposes
		position_runnerTwo = calculateRunnerPosition(position_runnerTwo, false, randomNumber);
		showRunnersLocation(position_runnerOne, position_runnerTwo);


		if (position_runnerOne >= 60 && position_runnerTwo < 60)
		{
			cout << "RUNNER #1 WINS!" << endl;
			break;
		}
		else if (position_runnerOne >= 60 && position_runnerTwo >= 60)
		{
			cout << "IT'S A TIE!" << endl;
			cout << "REMATCH!" << endl;
			position_runnerOne = 1;
			position_runnerTwo = 2;
			continue;
		}
		else if (position_runnerTwo >= 60 && position_runnerOne < 60)
		{
			cout << "RUNNER #2 WINS!" << endl;
			break;
		}

		timeframe++;
	}

	return 0;
}