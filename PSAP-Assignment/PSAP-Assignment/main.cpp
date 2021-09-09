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

// Declare and initialize values for 3 constants
const int finishingLine = 60;
const int runners[2] = { 1, 2 };
const float oneSec = 1.0;

// Main function of the program
int main() {
	// Declare and initialize values for 5 variables
	int match = 1;
	int randomNumber[2];
	int actionNumber[2];
	int positionRunner[2] = { 1, 1 };
	int seconds = 0;

	// Create starting seed for pseudorandom number series and use the current time as seed
	srand(time(NULL));

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
		delay(oneSec);
	}

	cout << "BANG!!\n\nAND AWAY THEY GO!!!" << endl;
	delay(oneSec);
	clearConsole();
	// End of SECTION 1 of Main

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
			actionNumber[i] = runnersAction(i + 1, randomNumber[i]);
			positionRunner[i] = calculatePosition(positionRunner[i], actionNumber[i]);
		}

		programTitle(match);
		// Loop for twice
		for (int j = 0; j < 2; j++)
		{
			// Call and pass in different arguments into the function 'actionMessage'
			actionMessage(randomNumber[j], runners[j], positionRunner[j], actionNumber[j]);
		}

		// Call and pass in different arguments into the functions
		showTrack(positionRunner[0], positionRunner[1], seconds);
		seconds = timeElapse(seconds);
		delay(oneSec);
		
		// IF-ELSE-IF statements which execute different actions based on the conditions
		if (positionRunner[0] >= finishingLine && positionRunner[1] < finishingLine)
		{
			cout << "RUNNER #1 WON THE MATCH!!!" << endl;

			// Stop the infinite WHILE loop
			break;
		}
		else if (positionRunner[1] >= finishingLine && positionRunner[0] < finishingLine)
		{
			cout << "RUNNER #2 WON THE MATCH!!!" << endl;

			// Stop the infinite WHILE loop
			break;
		}
		else if (positionRunner[0] >= finishingLine && positionRunner[1] >= finishingLine)
		{
			cout << "IT'S A TIE!\n" << endl;

			// Loop for thrice
			for (int k = 3; k >= 1; k--)
			{
				cout << "Countdown... Rematch in " << k << " second(s)...\n" << endl;
				delay(oneSec);
			}
			cout << "REMATCH!!!" << endl;
			delay(oneSec);
			positionRunner[0] = 1;
			positionRunner[1] = 1;

			// The variable 'match' increment by 1
			match++;
		}
		// End of SECTION 2 of Main

		clearConsole();
	}

	return 0;
}

/*
* Declare 'randomInteger' as an integer return-type function
* no argument will be pass into this function
*/
int randomInteger(void) {
	/*
	* Generate an integer number between 1 to 10,
	* store the generated number into the local variable 'random_integer'
	*/
	int random_integer = (rand() % 10) + 1;

	// Return 'random_integer' as the function value
	return random_integer;
}

/*
* Declare 'delay' as a void return-type function
* receive a float-type argument, 'delay_seconds' into this function
*/
void delay(float delay_seconds) {
	// Store current processor time into the local variable 'startClock'
	clock_t startClock = clock();

	/*
	* Multiplying the received argument with
	* a Defined Macro found in <ctime> library,
	* store the result into the local variable 'secondsAhead'
	*/
	float secondsAhead = delay_seconds * CLOCKS_PER_SEC;

	// Do nothing until the elapsed time passed
	while (clock() < startClock + secondsAhead);
}

/*
* Declare 'clearConsole' as a void return-type function
* no argument will be pass into this function
*/
// This function is used to clear the screen of terminal
void clearConsole(void) {
	#if defined (__APPLE__)
	// Pass the command "clear" if user run program on macOS
		system("clear");

	#elif defined _WIN32
	// Pass the command "cls" if user run program on WIINDOWS
		system("cls");

	#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	// Pass the command "clear" if user run program on LINUX
		system("clear");

	#endif
}

/*
* Declare 'runnersAction' as an integer return-type function
* receive 2 integer arguments into this function
*/
int runnersAction(int verify_runner, int random_integer) {
	// Declared local variable 'number_action' as an integer variable
	int number_action;

	// Different actions given to Runner #1, based on the range given
	if (verify_runner == 1) {
		if (random_integer >= 1 && random_integer <= 5)
			number_action = 1;
		else if (random_integer >= 6 && random_integer <= 7)
			number_action = 2;
		else
			number_action = 3;
	}

	// Different actions given to Runner #2, based on the range given
	else
	{
		if (random_integer >= 1 && random_integer <= 3)
			number_action = 4;
		else if (random_integer >= 4 && random_integer <= 5)
			number_action = 5;
		else if (random_integer == 6)
			number_action = 6;
		else if (random_integer >= 7 && random_integer <= 8)
			number_action = 7;
		else
			number_action = 8;
	}

	// return 'number_action' as the function value
	return number_action;
}

/*
* Declare 'calculatePosition' as an integer return-type function
* receive 2 integer arguments into this function
*/
int calculatePosition(int location_runner, int number_action) {
	// Calculate 'location_runner', based on 'number_action'
	switch (number_action)
	{
	case 1:
	case 5:
		location_runner += 3;
		break;

	case 2:
		location_runner += 1;
		break;

	case 3:
		location_runner -= 6;
		break;

	case 4:
		location_runner += 5;
		break;

	case 6:
		location_runner -= 2;
		break;

	case 7:
		location_runner -= 4;
		break;

	case 8:
		// Do nothing, 'runnerPosition' remain the same value
		break;
	}
	
	// Overwrite the value of 'location_runner' into 1, if it is less than 1
	if (location_runner < 1)
		location_runner = 1;
	
	// return 'runnerPosition' as the function value
	return location_runner;
}

/*
* Declare 'calculatePosition' as a void return-type function
* receive an integer argument, 'match_num' into this function
*/
void programTitle(int match_num) {
	cout << ' ' << setw(67) << left << setfill('=') << '=' << ' ' << endl;
	cout << '|' << setw(42) << right << setfill(' ') << "TRACK & FIELD RACE" << setw(26) << '|' << endl;
	cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
	cout << "| Match No. " << setw(56) << left << setfill(' ') << match_num << '|' << endl;
}

/*
* Declare 'actionMessage' as a void return-type function
* receive 4 integer arguments into this function
*/
void actionMessage(int random_integer, int identify_runner, int location_runner, int number_action) {
	cout << "| Runner " << identify_runner << " Rolled Number : " << setw(41) << left << setfill(' ') << random_integer << '|' << endl;

	// Declared local variable 'text' as a string variable
	string text;

	// Initialize string value, based on 'number_action'
	switch (number_action)
	{
	case 1:
		text = "Runner 1 SPRINTS and move 3 squares ahead.";
		break;

	case 2:
		text = "Runner 1 JOGS and move 1 square ahead.";
		break;

	case 3:
		if (location_runner == 1)
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
		if (location_runner == 1)
			text = "Runner 2 WALKS and return to starting point.";
		else
			text = "Runner 2 WALKS and move 2 squares behind.";
		break;

	case 7:
		if (location_runner == 1)
			text = "Runner 2 CRAWLS and return to starting point.";
		else
			text = "Runner 2 CRAWLS and move 4 squares behind.";
		break;

	case 8:
		text = "Runner 2 SLEEPS and nothing happens.";
		break;
	}

	// Display the variable 'text'
	cout << "| " << setw(66) << left << setfill(' ') << text << '|' << endl;
	cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
}

/*
* Declare 'showPosition' as a void return-type function
* receive 2 integer arguments into this function
*/
void showPosition(int location_runner, int identify_runner) {
	// Display appropriate output based on different conditions
	if (location_runner < finishingLine)
		cout << "| " << setw(location_runner) << right << setfill(' ') << identify_runner << setw(finishingLine - location_runner) << '|' << setw(7) << " |" << endl;
	else if (location_runner == finishingLine)
		cout << "| " << setw(finishingLine) << right << setfill(' ') << identify_runner << setw(5) << ' ' << " |" << endl;
	else
		cout << "| " << setw(finishingLine) << right << setfill(' ') << '|' << setw(location_runner - finishingLine) << identify_runner << setw(67 - location_runner) << " |" << endl;
}

/*
* Declare 'showTrack' as a void return-type function
* receive 3 integer arguments into this function
*/
void showTrack(int location_runnerOne, int location_runnerTwo, int elapsed_seconds) {
	// Show the current position of two runners in word form
	cout << "| Runner #" << runners[0] << " Current Position: " << setw(38) << left << setfill(' ') << location_runnerOne << '|' << endl;
	cout << "| Runner #" << runners[1] << " Current Position: " << setw(38) << left << setfill(' ') << location_runnerTwo << '|' << endl;
	cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
	cout << '|' << setw(67) << left << setfill(' ') << " Track:" << '|' << endl;
	cout << "| " << setw(60) << right << setfill('-') << '|' << setw(5) << '-' << " |" << endl;

	// Show the current position of two runners in graphical form
	showPosition(location_runnerOne, runners[0]);
	cout << "| " << setw(60) << right << setfill('-') << '|' << setw(5) << '-' << " |" << endl;
	showPosition(location_runnerTwo, runners[1]);
	cout << "| " << setw(60) << right << setfill('-') << '|' << setw(5) << '-' << " |" << endl;
	cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
	
	// Display a message if both runners clash on the same position
	if (location_runnerOne == location_runnerTwo && elapsed_seconds > 0)
	{
		cout << "| " << setw(66) << left << setfill(' ') << "GOTCHA!!! Both runners clash together!" << '|' << endl;
		cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
	}
}

/*
* Declare 'timeElapse' as a integer return-type function
* receive an integer argument, 'elapsed_seconds' into this function
*/
int timeElapse(int elapsed_seconds) {
	// Display the time elapsed during the program runs
	cout << "| Time Elapsed(s): " << setw(49) << left << setfill(' ') << elapsed_seconds << '|' << endl;
	cout << ' ' << setw(67) << left << setfill('=') << '=' << ' ' << endl << endl;

	// The variable 'elapsed_seconds' increment by 1
	elapsed_seconds++;

	// return 'elapsed_seconds' as the function value
	return elapsed_seconds;
}