#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Declaring functions prototype for later use
int randomInteger(void);
int timeElapse(int);
int runnersAction(int, int);
int calculatePosition(int, int);
void delay(float);
void clearConsole(void);
void programTitle(int);
void showPosition(int, int);
void showTrack(int, int, int);
void actionMessage(int, int, int, int);

/*
* Declare two constant where
* 1. 'finishingLine' is an integer constant equal to value 60.
* 
* 2. 'runners' is an integer array constant with size of 2,
*    storing value 1 and 2 which identify Runner #1 and Runner #2.
*/
const int finishingLine = 60;
const int runners[2] = { 1, 2 };

// The main part of the program
int main() {
	/*
	* Declare 5 variables where
	* 1. 'match' is an integer variable equal to value.
	* 
	* 2. 'randomNumber' and 'actonNumber' are integer array variable
	*    with size of 2, which currently have no values inside yet.
	* 
	* 3. 'positionRunner is an integer array variable with size of 2, storing
	*    the values 1 which identify the initial location of both runners.
	* 
	* 4. 'seconds' is an integer variable equal to value 0.
	*/
	int match = 1;
	int randomNumber[2];
	int actionNumber[2];
	int positionRunner[2] = { 1, 1 };
	int seconds = 0;
	srand((unsigned)time(NULL));

	/*
	* 1. Call the function 'programTitle' and pass in
	*    variable 'match' as a parameter into the function.
	* 
	* 2. Call the function 'showTrack' and pass in
	*    array variables 'positionRunner' index 0 and 1, and 'seconds'
	*    as parameters into the function.
	* 
	* 3. Call the function 'timeElapse' and pass in
	*    variable 'seconds' as a parameter into the function
	*    where the variable 'seconds' will be overwritten by
	*    the value return from the function 'timeElapse'.
	*/
	programTitle(match);
	showTrack(positionRunner[0], positionRunner[1], seconds);
	seconds = timeElapse(seconds);

	/*
	* 1. This FOR loop will loop for 3 times
	*    where integer 'l' is equal to 3 (initial value)
	*    while 'l' is bigger than or equal to 1
	*    'l' will decrement by 1.
	* 
	* Inside FOR loop:
	* 2. Display countdown the race 'l' seconds.
	* 
	* 3. Call the function 'delay' and pass in
	*    value 1.0 as a parameter into the function.
	*/
	for (int l = 3; l >= 1; l--)
	{
		cout << "Countdown... Race starting in " << l << " second(s)..." << endl << endl;
		delay(1.0);
	}

	/*
	* 1. Display the following sentence "BANG..."
	*    after FOR loop ended.
	* 
	* 2. Call the function 'delay' and pass in
	*    value 1.0 as a parameter into the function.
	* 
	* 3. Call the function 'clearConsole'.
	*/
	cout << "BANG!!\n\nAND AWAY THEY GO!!!" << endl;
	delay(1.0);
	clearConsole();

	// This section loop infinitely
	while (true)
	{
		/*
		* 1. This FOR loop will loop for twice
		*    where integer 'i' is equal to 0 (initial value)
		*    while 'i' is less than or equal to 1
		*    'i' will increment by 1.
		* 
		* Inside FOR Loop:
		* 2. Call the function 'randomInteger'
		*    where the array variable 'randomNumber' index 'i' 
		*    will be overwritten by the value
		*    return from the function 'randomInteger'.
		* 
		* 3. Call the function 'runnersAction' and pass in
		*    'i' and array variable 'randomNumber' index 'i'
		*    as parameters into the function
		*    where the array variable 'actionNumber' index 'i'
		*    will be overwritten by the value
		*    return from the function 'runnersAction'.
		* 
		* 4. Call the function 'calculatePosition' and pass in
		*    array variables 'positionRunner' index 'i' and 
		*    'actionNumber' index 'i' as parameters into the function
		*    where the array variable 'positionRunner' index 'i'
		*    will be overwritten by the value
		*    return from the function 'calculatePosition'.
		*/
		for (int i = 0; i <= 1; i++)
		{
			randomNumber[i] = randomInteger();
			actionNumber[i] = runnersAction(i, randomNumber[i]);
			positionRunner[i] = calculatePosition(positionRunner[i], actionNumber[i]);
		}

		/*
		* 1. Call the function 'programTitle' and pass in
		*    variable 'match' as a parameter into the function.
		* 
		* 2. This FOR loop will loop for twice
		*    where integer 'j' is equal to 0 (initial value)
		*    while 'j' is less than or equal to 1
		*    'j' will increment by 1.
		* 
		* Inside FOR loop:
		* 3. Call the function 'actionMessage' and pass in
		*    array variables 'randomNumber', 'runners',
		*    'positionRunner' and 'actionNumber'
		*    where all of them are index 'j'
		*    as parameters into the function.
		*/
		programTitle(match);
		for (int j = 0; j <= 1; j++)
		{
			actionMessage(randomNumber[j], runners[j], positionRunner[j], actionNumber[j]);
		}

		/*
		* 1. Call the function 'showTrack' after FOR loop ended
		*    and pass in array variables 'positionRunner' index 0 and 1,
		*    and 'seconds' as parameters into the function.
		* 
		* 2. Call the function 'timeElapse' and pass in
		*    variable 'seconds' as a parameter into the function
		*    where the variable 'seconds' will be overwritten by
		*    the value return from the function 'timeElapse'.
		* 
		* 3. Call the function 'delay' and pass in
		*    value 1.0 as a parameter into the function.
		*/
		showTrack(positionRunner[0], positionRunner[1], seconds);
		seconds = timeElapse(seconds);
		delay(1.0);

		if (positionRunner[0] >= finishingLine && positionRunner[1] < finishingLine)
		{
			cout << "RUNNER #1 WON THE MATCH!!!" << endl;
			break;
		}
		else if (positionRunner[0] >= finishingLine && positionRunner[1] >= finishingLine)
		{
			cout << "IT'S A TIE!" << endl << endl;
			for (int k = 3; k >= 1; k--)
			{
				cout << "Countdown... Rematch in " << k << " second(s)..." << endl << endl;
				delay(1.0);
			}
			cout << "REMATCH!!!" << endl;
			delay(1.0);
			clearConsole();
			positionRunner[0] = 1;
			positionRunner[1] = 1;
			match++;
			continue;
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

int randomInteger(void) {
	int randomNumber = (rand() % 10) + 1;
	return randomNumber;
}

// This function works on macOS as well
void delay(float seconds) {
	clock_t startClock = clock();
	float secondsAhead = seconds * CLOCKS_PER_SEC;
	// do nothing until the elapsed time has passed.
	while (clock() < startClock + secondsAhead);
}

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

int calculatePosition(int positionRunner, int actionNumber) {
	switch (actionNumber)
	{
	case 1:
		positionRunner += 3;
		break;
	case 2:
		positionRunner += 1;
		break;
	case 3:
		positionRunner -= 6;
		break;
	case 4:
		positionRunner += 5;
		break;
	case 5:
		positionRunner += 3;
		break;
	case 6:
		positionRunner -= 2;
		break;
	case 7:
		positionRunner -= 4;
		break;
	default:
		positionRunner = positionRunner;
	}
	
	if (positionRunner < 1)
		positionRunner = 1;
	
	return positionRunner;
}

void programTitle(int match) {
	cout << ' ' << setw(67) << left << setfill('=') << '=' << ' ' << endl;
	cout << '|' << setw(42) << right << setfill(' ') << "TRACK & FIELD RACE" << setw(26) << '|' << endl;
	cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
	cout << "| Match No. " << setw(56) << left << setfill(' ') << match << '|' << endl;
}

void actionMessage(int randomNumber, int runner, int runnersPosition, int actionNumber) {
	cout << "| Runner " << runner << " Rolled Number : " << setw(41) << left << setfill(' ') << randomNumber << '|' << endl;
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

void showPosition(int runnersPosition, int runner) {
	if (runnersPosition < finishingLine)
		cout << "| " << setw(runnersPosition) << right << setfill(' ') << runner << setw(60 - runnersPosition) << '|' << setw(7) << " |" << endl;
	else if (runnersPosition == finishingLine)
		cout << "| " << setw(60) << right << setfill(' ') << runner << setw(5) << ' ' << " |" << endl;
	else
		cout << "| " << setw(60) << right << setfill(' ') << '|' << setw(abs(60 - runnersPosition)) << runner << setw(67 - runnersPosition) << " |" << endl;
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

	return seconds;
}