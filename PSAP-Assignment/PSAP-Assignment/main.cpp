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
			actionNumber = 1;
		else if (randomNumber >= 6 && randomNumber <= 7)
			actionNumber = 2;
		else
			actionNumber = 3;
	}
	else
	{
		if (randomNumber >= 1 && randomNumber <= 3)
			actionNumber = 4;
		else if (randomNumber >= 4 && randomNumber <= 5)
			actionNumber = 5;
		else if (randomNumber == 6)
			actionNumber = 6;
		else if (randomNumber >= 7 && randomNumber <= 8)
			actionNumber = 7;
		else
			actionNumber = 8;
	}

	return actionNumber;
}

int calculateRunnerPosition(int positionRunner, int actionNumber) {
	if (actionNumber == 1)
		positionRunner += 3;
	else if (actionNumber == 2)
		positionRunner += 1;
	else if (actionNumber == 3)
	{
		if (positionRunner - 6 <= 1)
			positionRunner = 1;
		else
			positionRunner -= 6;
	}
	else if (actionNumber == 4)
		positionRunner += 5;
	else if (actionNumber == 5)
		positionRunner += 3;
	else if (actionNumber == 6)
	{
		if (positionRunner - 2 <= 1)
			positionRunner = 1;
		else
			positionRunner -= 2;
	}
	else if (actionNumber == 7)
	{
		if (positionRunner - 4 <= 1)
			positionRunner = 1;
		else
			positionRunner -= 4;
	}
	else
		positionRunner = positionRunner;

	return positionRunner;
}

void programTitle(int match) {
	cout << ' ' << setw(67) << left << setfill('=') << '=' << ' ' << endl;
	cout << '|' << setw(42) << right << setfill(' ') << "TRACK & FIELD RACE" << setw(26) << '|' << endl;
	cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
	cout << "| Match No. " << setw(56) << left << setfill(' ') << match << '|' << endl;
}

void showRolledNumber(int randomNumber) {
	cout << "| Runner 1 Rolled Number: " << setw(42) << left << setfill(' ') << randomNumber << '|' << endl;
}

void showActionMessage(int runnersPosition, int actionNumber) {
	if (actionNumber == 1)
		cout << "| " << setw(66) << left << setfill(' ') << "Runner 1 SPRINTS and move 3 squares ahead." << '|' << endl;
	else if (actionNumber == 2)
		cout << "| " << setw(66) << left << setfill(' ') << "Runner 1 JOGS and move 1 square ahead." << '|' << endl;
	else if (actionNumber == 3 && runnersPosition == 1)
		cout << "| " << setw(66) << left << setfill(' ') << "Runner 1 WALKS and return to starting point." << '|' << endl;
	else if (actionNumber == 3 && runnersPosition != 1)
		cout << "| " << setw(66) << left << setfill(' ') << "Runner 1 WALKS and move 6 squares behind." << '|' << endl;
	else if (actionNumber == 4)
		cout << "| " << setw(66) << left << setfill(' ') << "Runner 2 FAST SPRINTS and move 5 squares ahead." << '|' << endl;
	else if (actionNumber == 5)
		cout << "| " << setw(66) << left << setfill(' ') << "Runner 2 RUNS and move 3 squares ahead." << '|' << endl;
	else if (actionNumber == 6 && runnersPosition == 1)
		cout << "| " << setw(66) << left << setfill(' ') << "Runner 2 WALKS and return to starting point." << '|' << endl;
	else if (actionNumber == 6 && runnersPosition != 1)
		cout << "| " << setw(66) << left << setfill(' ') << "Runner 2 WALKS and move 2 squares behind." << '|' << endl;
	else if (actionNumber == 7 && runnersPosition == 1)
		cout << "| " << setw(66) << left << setfill(' ') << "Runner 2 CRAWLS and return to starting point." << '|' << endl;
	else if (actionNumber == 7 && runnersPosition != 1)
		cout << "| " << setw(66) << left << setfill(' ') << "Runner 2 CRAWLS and move 4 squares behind." << '|' << endl;
	else
		cout << "| " << setw(66) << left << setfill(' ') << "Runner 2 SLEEPS and nothing happens." << '|' << endl;

	cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
}

void showCurrentAction(int positionRunner, int player) {
	cout << "| Runner #" << player << " Current Location: " << setw(38) << left << setfill(' ') << positionRunner << '|' << endl;
}

void showRunnersLocation(int runnersPosition, int player) {
	if (runnersPosition < 60)
		cout << "| " << setw(runnersPosition) << right << setfill(' ') << player << setw(60 - runnersPosition) << '|' << setw(7) << " |" << endl;
	else if (runnersPosition == 60)
		cout << "| " << setw(60) << right << setfill(' ') << player << setw(5) << ' ' << " |" << endl;
	else
		cout << "| " << setw(60) << right << setfill(' ') << '|' << setw(abs(60 - runnersPosition)) << player << setw(67 - runnersPosition) << " |" << endl;
}

void showTrack(int positionRunnerOne, int positionRunnerTwo) {
	cout << '|' << setw(67) << left << setfill(' ') << " Track:" << '|' << endl;
	cout << "| " << setw(60) << right << setfill('-') << '|' << setw(5) << '-' << " |" << endl;
	showRunnersLocation(positionRunnerOne, 1);
	cout << "| " << setw(60) << right << setfill('-') << '|' << setw(5) << '-' << " |" << endl;
	showRunnersLocation(positionRunnerTwo, 2);
	cout << "| " << setw(60) << right << setfill('-') << '|' << setw(5) << '-' << " |" << endl;
	cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
	if (positionRunnerOne == positionRunnerTwo && positionRunnerOne != 1)
	{
		cout << "| " << setw(66) << left << setfill(' ') << "GOTCHA!!! Both runners clash together!" << '|' << endl;
		cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
	}
}

int showTimeElapse(int seconds) {
	cout << "| Time Elapsed (s): " << setw(48) << left << setfill(' ') << seconds << '|' << endl;
	cout << ' ' << setw(67) << left << setfill('=') << '=' << ' ' << endl << endl;
	sleep(1.0);
	seconds++;

	return seconds;
}

int main() {
	int match = 1;
	int randomNumber[2];
	int actionNumber[2];
	int positionRunner[2] = { 60, 60 };
	int seconds = 1;
	srand((unsigned)time(NULL));

	while (true)
	{
		randomNumber[0] = randomIntegerGenerator();
		actionNumber[0] = verifyRunnersAction(true, randomNumber[0]);
		positionRunner[0] = calculateRunnerPosition(positionRunner[0], actionNumber[0]);
		randomNumber[1] = randomIntegerGenerator();
		actionNumber[1] = verifyRunnersAction(false, randomNumber[1]);
		positionRunner[1] = calculateRunnerPosition(positionRunner[1], actionNumber[1]);

		programTitle(match);
		showRolledNumber(randomNumber[0]);
		showActionMessage(positionRunner[0], actionNumber[0]);
		showRolledNumber(randomNumber[1]);
		showActionMessage(positionRunner[1], actionNumber[1]);
		showCurrentAction(positionRunner[0], 1);
		showCurrentAction(positionRunner[1], 2);
		showTrack(positionRunner[0], positionRunner[1]);

		seconds = showTimeElapse(seconds);
		

		if (positionRunner[0] >= 60 && positionRunner[1] < 60)
		{
			cout << "RUNNER #1 WINS!" << endl;
			break;
		}
		else if (positionRunner[0] >= 60 && positionRunner[1] >= 60)
		{
			cout << "IT'S A TIE!" << endl;
			cout << "PAUSE FOR 3 SECONDS BEFORE THE RACE CONTINUE." << endl;
			sleep(3.0);
			clearConsole();
			cout << "REMATCH!!!" << endl << endl;
			positionRunner[0] = 1;
			positionRunner[1] = 1;
			match++;
			continue;
		}
		else if (positionRunner[1] >= 60 && positionRunner[0] < 60)
		{
			cout << "RUNNER #2 WINS!" << endl;
			break;
		}

		clearConsole();
	}

	return 0;
}