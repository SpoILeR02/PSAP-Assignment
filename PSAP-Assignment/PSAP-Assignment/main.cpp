#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

// Declaring functions prototype
int randomInteger(void);
void delay(float);
void clearConsole(void);
int runnersAction(int, int);
int calculatePosition(int, int);
void programTitle(int);
void actionMessage(int, int, int, int);
void showPosition(int, int);
void showTrack(int, int, int);
int timeElapse(int);

// Declare and initialize values for 2 constants
const int finishingLine = 60;
const int runners[2] = { 1, 2 };

// Main function of the program
int main() {
	// Declare and initialize values for 5 variables
	int match = 1;
	int randomNumber[2];
	int actionNumber[2];
	int positionRunner[2] = { 1, 1 };
	int seconds = 0;
	srand((unsigned)time(NULL));

	/*
	* SECTION 1 of Main:
	* Call and pass in different arguments into the functions
	*/
	programTitle(match);
	showTrack(positionRunner[0], positionRunner[1], seconds);
	seconds = timeElapse(seconds);

	// Loop for thrice
	for (int l = 3; l >= 1; l--)
	{
		cout << "Countdown... Race starting in " << l << " second(s)...\n" << endl;
		delay(1.0);
	}

	cout << "BANG!!\n\nAND AWAY THEY GO!!!" << endl;
	delay(1.0);
	clearConsole();
	// End of SECTION 1

	/*
	* SECTION 2 of Main:
	* WHILE loop which will loop infinitely
	*/
	while (true)
	{
		// Loop for twice
		for (int i = 0; i < 2; i++)
		{
			// Overwrite the values of variables with the values return from functions
			randomNumber[i] = randomInteger();
			actionNumber[i] = runnersAction(i, randomNumber[i]);
			positionRunner[i] = calculatePosition(positionRunner[i], actionNumber[i]);
		}

		// Loop for twice
		programTitle(match);
		for (int j = 0; j < 2; j++)
		{
			// Call and pass in different arguments into the function 'actionMessage'
			actionMessage(randomNumber[j], runners[j], positionRunner[j], actionNumber[j]);
		}

		// Call and pass in different arguments into the functions
		showTrack(positionRunner[0], positionRunner[1], seconds);
		seconds = timeElapse(seconds);
		delay(1.0);
		
		// ELSE-IF statements which execute different actions based on the conditions
		if (positionRunner[0] >= finishingLine && positionRunner[1] < finishingLine)
		{
			cout << "RUNNER #1 WON THE MATCH!!!" << endl;
			break;
		}
		else if (positionRunner[0] >= finishingLine && positionRunner[1] >= finishingLine)
		{
			cout << "IT'S A TIE!\n" << endl;

			// Loop for thrice
			for (int k = 3; k >= 1; k--)
			{
				cout << "Countdown... Rematch in " << k << " second(s)...\n" << endl;
				delay(1.0);
			}
			cout << "REMATCH!!!" << endl;
			delay(1.0);
			positionRunner[0] = 1;
			positionRunner[1] = 1;
			match++;
		}
		else if (positionRunner[1] >= finishingLine && positionRunner[0] < finishingLine)
		{
			cout << "RUNNER #2 WON THE MATCH!!!" << endl;
			break;
		}

		clearConsole();
	}

	return 0;
}

/*
* Declare 'randomInteger' as an integer return-type function
* there is no argument will be pass into this function
* therefore argument-type void is used inside parentheses
*/
int randomInteger(void) {
	/*
	* Generate an integer number between 1 to 10,
	* store the generated number into the variable 'randomNumber'
	*/
	int randomNumber = (rand() % 10) + 1;

	// Return 'randomNumber' as the function value
	return randomNumber;
}

/*
* Declare 'delay' as a void return-type function
* receive a float-type argument, 'delay_seconds' into this function
*/
void delay(float delay_seconds) {
	// Store current processor time into the variable 'startClock'
	clock_t startClock = clock();

		
	float secondsAhead = delay_seconds * CLOCKS_PER_SEC;

	// Do nothing until the elapsed time passed
	while (clock() < startClock + secondsAhead);
}


// This function is used to clear the screen of terminal
void clearConsole(void) {

	#if defined _WIN32
		system("cls");


	#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
		system("clear");


	#elif defined (__APPLE__)
		system("clear");
	#endif
}


int runnersAction(int verifyRunner, int randomNumber) {
	// local variable 'actionNumber' is declared as an integer variable
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

	// return 'actionNumber' as the function value
	return actionNumber;
}


int calculatePosition(int runnerPosition, int actionNumber) {

	switch (actionNumber)
	{
	case 1:
		// 'runnerPosition' is equal to 'runnerPosition' + 3
		runnerPosition += 3;
		break;
	case 2:
		// 'runnerPosition' is equal to 'runnerPosition' + 1
		runnerPosition += 1;
		break;
	case 3:
		// 'runnerPosition' is equal to 'runnerPosition' - 6
		runnerPosition -= 6;
		break;
	case 4:
		// 'runnerPosition' is equal to 'runnerPosition' + 5
		runnerPosition += 5;
		break;
	case 5:
		// 'runnerPosition' is equal to 'runnerPosition' + 3
		runnerPosition += 3;
		break;
	case 6:
		// 'runnerPosition' is equal to 'runnerPosition' - 2
		runnerPosition -= 2;
		break;
	case 7:
		// 'runnerPosition' is equal to 'runnerPosition' - 4
		runnerPosition -= 4;
		break;
	case 8:
		// Do nothing, 'runnerPosition' remain the same value
		break;
	}
	
	
	if (runnerPosition < 1)
		runnerPosition = 1;
	
	// return 'runnerPosition' as the function value
	return runnerPosition;
}


void programTitle(int match) {

	cout << ' ' << setw(67) << left << setfill('=') << '=' << ' ' << endl;
	cout << '|' << setw(42) << right << setfill(' ') << "TRACK & FIELD RACE" << setw(26) << '|' << endl;
	cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
	cout << "| Match No. " << setw(56) << left << setfill(' ') << match << '|' << endl;
}


void actionMessage(int randomNumber, int runner, int runnerPosition, int actionNumber) {
	cout << "| Runner " << runner << " Rolled Number : " << setw(41) << left << setfill(' ') << randomNumber << '|' << endl;

	string text;
	switch (actionNumber)
	{
	case 1:
		text = "Runner 1 SPRINTS and move 3 squares ahead.";
		break;
	case 2:
		text = "Runner 1 JOGS and move 1 square ahead.";
		break;
	case 3:
		if (runnerPosition == 1)
			text = "Runner 1 WALKS and return to starting point.";
		else
			text = "Runner 1 WALKS and move 6 squares behind.";
		break;
	case 4:
		text = "Runner 2 FAST SPRINTS and move 5 squares ahead.";
		break;
	case 5:
		text = "Runner 2 RUNS and move 3 squares ahead.";
		break;
	case 6:
		if (runnerPosition == 1)
			text = "Runner 2 WALKS and return to starting point.";
		else
			text = "Runner 2 WALKS and move 2 squares behind.";
		break;
	case 7:
		if (runnerPosition == 1)
			text = "Runner 2 CRAWLS and return to starting point.";
		else
			text = "Runner 2 CRAWLS and move 4 squares behind.";
		break;
	case 8:
		text = "Runner 2 SLEEPS and nothing happens.";
		break;
	}
	cout << "| " << setw(66) << left << setfill(' ') << text << '|' << endl;
	cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
}


void showPosition(int runnerPosition, int runner) {
	
	if (runnerPosition < finishingLine)
		cout << "| " << setw(runnerPosition) << right << setfill(' ') << runner << setw(60 - runnerPosition) << '|' << setw(7) << " |" << endl;
	else if (runnerPosition == finishingLine)
		cout << "| " << setw(60) << right << setfill(' ') << runner << setw(5) << ' ' << " |" << endl;
	else
		cout << "| " << setw(60) << right << setfill(' ') << '|' << setw(abs(60 - runnerPosition)) << runner << setw(67 - runnerPosition) << " |" << endl;
}


void showTrack(int positionRunnerOne, int positionRunnerTwo, int seconds) {
	
	cout << "| Runner #" << runners[0] << " Current Position: " << setw(38) << left << setfill(' ') << positionRunnerOne << '|' << endl;
	cout << "| Runner #" << runners[1] << " Current Position: " << setw(38) << left << setfill(' ') << positionRunnerTwo << '|' << endl;
	cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
	cout << '|' << setw(67) << left << setfill(' ') << " Track:" << '|' << endl;
	cout << "| " << setw(60) << right << setfill('-') << '|' << setw(5) << '-' << " |" << endl;

	
	showPosition(positionRunnerOne, runners[0]);
	cout << "| " << setw(60) << right << setfill('-') << '|' << setw(5) << '-' << " |" << endl;
	showPosition(positionRunnerTwo, runners[1]);
	cout << "| " << setw(60) << right << setfill('-') << '|' << setw(5) << '-' << " |" << endl;
	cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
	
	
	if (positionRunnerOne == positionRunnerTwo && seconds > 1)
	{
		cout << "| " << setw(66) << left << setfill(' ') << "GOTCHA!!! Both runners clash together!" << '|' << endl;
		cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
	}
}


int timeElapse(int seconds) {
	
	cout << "| Time Elapsed(s): " << setw(49) << left << setfill(' ') << seconds << '|' << endl;
	cout << ' ' << setw(67) << left << setfill('=') << '=' << ' ' << endl << endl;
	seconds++;

	// return 'seconds' as the function value
	return seconds;
}