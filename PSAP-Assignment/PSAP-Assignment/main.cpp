#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int randomIntegerGenerator() {
	int randomNumber = (rand() % 10) + 1;
	return randomNumber;
}

// This function works on macOS as well
void sleep(float seconds) {
	clock_t startClock = clock();
	float secondsAhead = seconds * CLOCKS_PER_SEC;
	// do nothing until the elapsed time has passed.
	while (clock() < startClock + secondsAhead);
	return;
}

void clearConsole() {
#if defined _WIN32
	system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
#elif defined (__APPLE__)
	system("clear");
#endif
}

int verifyRunnersAction(bool verifyRunner, int randomNumber) {
	int actionNumber;

	if (verifyRunner == true) {
		if (randomNumber >= 1 && randomNumber <= 5)
		{
			actionNumber = 1;
		}
		else if (randomNumber >= 6 && randomNumber <= 7)
		{
			actionNumber = 2;
		}
		else
		{
			actionNumber = 3;
		}
	}
	else
	{
		if (randomNumber >= 1 && randomNumber <= 3)
		{
			actionNumber = 4;
		}
		else if (randomNumber >= 4 && randomNumber <= 5)
		{
			actionNumber = 5;
		}
		else if (randomNumber == 6)
		{
			actionNumber = 6;
		}
		else if (randomNumber >= 7 && randomNumber <= 8)
		{
			actionNumber = 7;
		}
		else
		{
			actionNumber = 8;
		}
	}
	
	return actionNumber;
}

int calculateRunnerPosition(int position_runner, int actionNumber) {
	if (actionNumber == 1)
	{
		position_runner += 3;
		cout << setw(68) << left << setfill(' ') << "| Runner 1 SPRINTS and move 3 squares ahead."  << '|' << endl;
	}
	else if (actionNumber == 2)
	{
		position_runner += 1;
		cout << setw(68) << left << setfill(' ') << "| Runner 1 JOGS and move 1 square ahead." << '|' << endl;
	}
	else if (actionNumber == 3)
	{
		if (position_runner <= 1 || position_runner - 6 <= 1)
		{
			position_runner = 1;
			cout << setw(68) << left << setfill(' ') << "| Runner 1 WALKS and return to starting point." << '|' << endl;
		}
		else
		{
			position_runner -= 6;
			cout << setw(68) << left << setfill(' ') << "| Runner 1 WALKS and move 6 squares behind." << '|' << endl;
		}
	}
	else if (actionNumber == 4)
	{
		position_runner += 5;
		cout << setw(68) << left << setfill(' ') << "| Runner 2 FAST SPRINTS and move 5 squares ahead." << '|' << endl;
	}
	else if (actionNumber == 5)
	{
		position_runner += 3;
		cout << setw(68) << left << setfill(' ') << "| Runner 2 RUNS and move 3 squares ahead." << '|' << endl;
	}
	else if (actionNumber == 6)
	{
		if (position_runner <= 1 || position_runner - 4 <= 1)
		{
			position_runner = 1;
			cout << setw(68) << left << setfill(' ') << "| Runner 2 WALKS and return to starting point." << '|' << endl;
		}
		else
		{
			position_runner -= 2;
			cout << setw(68) << left << setfill(' ') << "| Runner 2 WALKS and move 2 squares behind." << '|' << endl;
		}
	}
	else if (actionNumber == 7)
	{
		if (position_runner <= 1 || position_runner - 4 <= 1)
		{
			position_runner = 1;
			cout << setw(68) << left << setfill(' ') << "| Runner 2 CRAWLS and return to starting point." << '|' << endl;
		}
		else
		{
			position_runner -= 4;
			cout << setw(68) << left << setfill(' ') << "| Runner 2 CRAWLS and move 4 squares behind." << '|' << endl;
		}
	}
	else
	{
		cout << setw(68) << left << setfill(' ') << "| Runner 2 SLEEPS and nothing happens." << '|' << endl;
	}

	return position_runner;
}

void showRunnersLocation(int runnersPosition, int player) {
	cout << "| " << setw(runnersPosition) << right << setfill('-') << player << setw(65 - abs(runnersPosition)) << '-' << " |" << endl;
	//cout << '|' << setw(67) << left << setfill('-') << '-' << '|' << endl;

}

void Gotcha(int positionRunnerOne, int positionRunnerTwo) {
	if (positionRunnerOne == positionRunnerTwo && positionRunnerOne != 1)
	{
		cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
		cout << setw(68) << left << setfill(' ') << "| GOTCHA!!! Both runners clash together!" << '|' << endl;
		cout << setw(68) << left << setfill(' ') << "| GOTCHA!!! Both runners clash together!" << '|' << endl;
		cout << '|' << setw(67) << left << setfill('-') << '-' << '|' << endl;
		cout << "| " << setw(positionRunnerOne) << right << setfill(' ') << 1 << setw(65 - abs(positionRunnerOne)) << ' ' << " |" << endl;
		cout << '|' << setw(67) << left << setfill('-') << '-' << '|' << endl;
		cout << "| " << setw(positionRunnerTwo) << right << setfill(' ') << 2 << setw(65 - abs(positionRunnerTwo)) << ' ' << " |" << endl;
		cout << '|' << setw(67) << left << setfill('-') << '-' << '|' << endl;
	}
}

int main() {
	int position_runnerOne = 1;
	int position_runnerTwo = 1;
	int seconds = 0;
	int moveCounts = 1;
	int randomNumber;
	int actionNumber;
	srand((unsigned)time(NULL));

	while(true)
	{
		seconds += 1;
		cout << ' ' << setw(67) << left << setfill('=') << '=' << ' ' << endl;
		cout << '|'<< setw(42) << right << setfill(' ') << "TRACK & FIELD RACE" << setw(26) << '|' << endl;
		cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
		cout << "| Move Counts: " << setw(53) << left << setfill(' ') << moveCounts << '|' << endl;

		randomNumber = randomIntegerGenerator();
		cout << "| Runner 1 Rolled Number: " << setw(42) << left << setfill(' ') << randomNumber << '|' << endl;
		actionNumber = verifyRunnersAction(true, randomNumber);
		position_runnerOne = calculateRunnerPosition(position_runnerOne, actionNumber);
		cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
		showRunnersLocation(position_runnerOne, 1);
		cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;

		randomNumber = randomIntegerGenerator();
		cout << "| Runner 2 Rolled Number: " << setw(42) << left << setfill(' ') << randomNumber << '|' << endl;
		actionNumber = verifyRunnersAction(false, randomNumber);
		position_runnerTwo = calculateRunnerPosition(position_runnerTwo, actionNumber);
		cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
		showRunnersLocation(position_runnerTwo, 2);
		Gotcha(position_runnerOne, position_runnerTwo);
		cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
		
		cout << "| Time Elapsed: " << setw(52) << left << setfill(' ') << seconds << '|' << endl;
		cout << ' ' << setw(67) << left << setfill('=') << '=' << ' ' << endl << endl;
		sleep(1.0);

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

		moveCounts++;
		clearConsole();
	}
	
	return 0;
}