#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int finishingLine = 60;

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

int verifyRunnersAction(int verifyRunner, int randomNumber) {
	int actionNumber;

	if (verifyRunner == 0) {
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
	switch (actionNumber)
	{
	case 1:
		positionRunner += 3;
		break;
	case 2:
		positionRunner += 1;
		break;
	case 3:
		if (positionRunner - 6 <= 1)
			positionRunner = 1;
		else
			positionRunner -= 6;
		break;
	case 4:
		positionRunner += 5;
		break;
	case 5:
		positionRunner += 3;
		break;
	case 6:
		if (positionRunner - 2 <= 1)
			positionRunner = 1;
		else
			positionRunner -= 2;
		break;
	case 7:
		if (positionRunner - 4 <= 1)
			positionRunner = 1;
		else
			positionRunner -= 4;
		break;
	default:
		positionRunner = positionRunner;
	}
	
	return positionRunner;
}

void programTitle(int match) {
	cout << ' ' << setw(67) << left << setfill('=') << '=' << ' ' << endl;
	cout << '|' << setw(42) << right << setfill(' ') << "TRACK & FIELD RACE" << setw(26) << '|' << endl;
	cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
	cout << "| Match No. " << setw(56) << left << setfill(' ') << match << '|' << endl;
}

void showRolledNumber(int randomNumber, int player) {
	cout << "| Runner " << player << " Rolled Number : " << setw(41) << left << setfill(' ') << randomNumber << '|' << endl;
}

void showActionMessage(int runnersPosition, int actionNumber) {
	switch (actionNumber)
	{
	case 1:
		cout << "| " << setw(66) << left << setfill(' ') << "Runner 1 SPRINTS and move 3 squares ahead." << '|' << endl;
		break;
	case 2:
		cout << "| " << setw(66) << left << setfill(' ') << "Runner 1 JOGS and move 1 square ahead." << '|' << endl;
		break;
	case 3:
		if (runnersPosition == 1)
			cout << "| " << setw(66) << left << setfill(' ') << "Runner 1 WALKS and return to starting point." << '|' << endl;
		else
			cout << "| " << setw(66) << left << setfill(' ') << "Runner 1 WALKS and move 6 squares behind." << '|' << endl;
		break;
	case 4:
		cout << "| " << setw(66) << left << setfill(' ') << "Runner 2 FAST SPRINTS and move 5 squares ahead." << '|' << endl;
		break;
	case 5:
		cout << "| " << setw(66) << left << setfill(' ') << "Runner 2 RUNS and move 3 squares ahead." << '|' << endl;
		break;
	case 6:
		if (runnersPosition == 1)
			cout << "| " << setw(66) << left << setfill(' ') << "Runner 2 WALKS and return to starting point." << '|' << endl;
		else
			cout << "| " << setw(66) << left << setfill(' ') << "Runner 2 WALKS and move 2 squares behind." << '|' << endl;
		break;
	case 7:
		if (runnersPosition == 1)
			cout << "| " << setw(66) << left << setfill(' ') << "Runner 2 CRAWLS and return to starting point." << '|' << endl;
		else
			cout << "| " << setw(66) << left << setfill(' ') << "Runner 2 CRAWLS and move 4 squares behind." << '|' << endl;
		break;
	default:
		cout << "| " << setw(66) << left << setfill(' ') << "Runner 2 SLEEPS and nothing happens." << '|' << endl;
	}

	cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
}

void showCurrentLocation(int positionRunner, int player) {
	cout << "| Runner #" << player << " Current Location: " << setw(38) << left << setfill(' ') << positionRunner << '|' << endl;
}

void showRunnersLocation(int runnersPosition, int player) {
	if (runnersPosition < finishingLine)
		cout << "| " << setw(runnersPosition) << right << setfill(' ') << player << setw(60 - runnersPosition) << '|' << setw(7) << " |" << endl;
	else if (runnersPosition == finishingLine)
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
	int players[2] = { 1, 2 };
	int positionRunner[2] = { 1, 1 };
	int seconds = 1;
	srand((unsigned)time(NULL));

	while (true)
	{
		for (int i = 0; i <= 1; i++)
		{
			randomNumber[i] = randomIntegerGenerator();
			actionNumber[i] = verifyRunnersAction(i, randomNumber[i]);
			positionRunner[i] = calculateRunnerPosition(positionRunner[i], actionNumber[i]);
		}
		programTitle(match);
		for (int j = 0; j <= 1; j++)
		{
			showRolledNumber(randomNumber[j], players[j]);
			showActionMessage(positionRunner[j], actionNumber[j]);
		}
		for (int k = 0; k <= 1; k++)
		{
			showCurrentLocation(positionRunner[k], players[k]);
		}
		showTrack(positionRunner[0], positionRunner[1]);

		seconds = showTimeElapse(seconds);
		
		if (positionRunner[0] >= finishingLine && positionRunner[1] < finishingLine)
		{
			cout << "RUNNER #1 WINS!" << endl;
			break;
		}
		else if (positionRunner[0] >= finishingLine && positionRunner[1] >= finishingLine)
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
		else if (positionRunner[1] >= finishingLine && positionRunner[0] < finishingLine)
		{
			cout << "RUNNER #2 WINS!" << endl;
			break;
		}

		clearConsole();
	}

	return 0;
}