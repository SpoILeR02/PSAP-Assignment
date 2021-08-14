#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Declaring functions prototype
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
* 1. 'finishingLine' is an integer constant equal to value 60
* 
* 2. 'runners' is an integer array constant with size of 2,
*    storing value 1 and 2 which identify Runner #1 and Runner #2
*/
const int finishingLine = 60;
const int runners[2] = { 1, 2 };

// The main part of the program
int main() {
	/*
	* Declare 5 variables where
	* 1. 'match' is an integer variable equal to value
	* 
	* 2. 'randomNumber' and 'actonNumber' are integer array variable
	*    with size of 2, which currently have no values inside yet
	* 
	* 3. 'positionRunner is an integer array variable with size of 2, storing
	*    the values 1 which identify the initial location of both runners
	* 
	* 4. 'seconds' is an integer variable equal to value 0
	*/
	int match = 1;
	int randomNumber[2];
	int actionNumber[2];
	int positionRunner[2] = { 1, 1 };
	int seconds = 0;
	srand((unsigned)time(NULL));

	/*
	* 1. Call the function 'programTitle' and pass in
	*    variable 'match' as a parameter into the function
	* 
	* 2. Call the function 'showTrack' and pass in
	*    array variables 'positionRunner' index 0 and 1, and 'seconds'
	*    as parameters into the function
	* 
	* 3. Call the function 'timeElapse' and pass in
	*    variable 'seconds' as a parameter into the function
	*    where the variable 'seconds' will be overwritten by
	*    the value return from the function 'timeElapse'
	*/
	programTitle(match);
	showTrack(positionRunner[0], positionRunner[1], seconds);
	seconds = timeElapse(seconds);

	/*
	* This FOR loop will loop for 3 times
	* where integer 'l' is equal to 3 (initial value)
	* while 'l' is more than or equal to 1
	* 'l' will decrement by 1
	* 
	* Inside FOR loop:
	* 1. Display countdown the race 'l' seconds
	* 
	* 2. Call the function 'delay' and pass in
	*    value 1.0 as a parameter into the function
	* End of FOR loop
	*/
	for (int l = 3; l >= 1; l--)
	{
		cout << "Countdown... Race starting in " << l << " second(s)...\n" << endl;
		delay(1.0);
	}

	/*
	* 1. Display the following sentence "BANG..."
	* 
	* 2. Call the function 'delay' and pass in
	*    value 1.0 as a parameter into the function
	* 
	* 3. Call the function 'clearConsole'
	*/
	cout << "BANG!!\n\nAND AWAY THEY GO!!!" << endl;
	delay(1.0);
	clearConsole();

	// This section (WHILE loop) will loop infinitely
	while (true)
	{
		/*
		* This FOR loop will loop for twice
		* where integer 'i' is equal to 0 (initial value)
		* while 'i' is less than or equal to 1
		* 'i' will increment by 1
		* 
		* Inside FOR Loop:
		* 1. Call the function 'randomInteger'
		*    where the array variable 'randomNumber' index 'i' 
		*    will be overwritten by the value
		*    return from the function 'randomInteger'
		* 
		* 2. Call the function 'runnersAction' and pass in
		*    'i' and array variable 'randomNumber' index 'i'
		*    as parameters into the function
		*    where the array variable 'actionNumber' index 'i'
		*    will be overwritten by the value
		*    return from the function 'runnersAction'
		* 
		* 3. Call the function 'calculatePosition' and pass in
		*    array variables 'positionRunner' index 'i' and 
		*    'actionNumber' index 'i' as parameters into the function
		*    where the array variable 'positionRunner' index 'i'
		*    will be overwritten by the value
		*    return from the function 'calculatePosition'
		* End of FOR loop
		*/
		for (int i = 0; i <= 1; i++)
		{
			randomNumber[i] = randomInteger();
			actionNumber[i] = runnersAction(i, randomNumber[i]);
			positionRunner[i] = calculatePosition(positionRunner[i], actionNumber[i]);
		}

		/*
		* 1. Call the function 'programTitle' and pass in
		*    variable 'match' as a parameter into the function
		* 
		* This FOR loop will loop for twice
		* where integer 'j' is equal to 0 (initial value)
		* while 'j' is less than or equal to 1
		* 'j' will increment by 1
		* 
		* Inside FOR loop:
		* 2. Call the function 'actionMessage' and pass in
		*    array variables 'randomNumber', 'runners',
		*    'positionRunner' and 'actionNumber'
		*    where all of them are index 'j'
		*    as parameters into the function
		* End of FOR loop
		*/
		programTitle(match);
		for (int j = 0; j <= 1; j++)
		{
			actionMessage(randomNumber[j], runners[j], positionRunner[j], actionNumber[j]);
		}

		/*
		* 1. Call the function 'showTrack' after FOR loop ended
		*    and pass in array variables 'positionRunner' index 0 and 1,
		*    and 'seconds' as parameters into the function
		* 
		* 2. Call the function 'timeElapse' and pass in
		*    variable 'seconds' as a parameter into the function
		*    where the variable 'seconds' will be overwritten by
		*    the value return from the function 'timeElapse'
		* 
		* 3. Call the function 'delay' and pass in
		*    value 1.0 as a parameter into the function
		*/
		showTrack(positionRunner[0], positionRunner[1], seconds);
		seconds = timeElapse(seconds);
		delay(1.0);

		/*
		* IF the array variable 'positionRunner' index 0
		* is more than or equal to the global constant finishingLine
		* AND the array variable 'positionRunner' index 1
		* is less than the global constant finishingLine
		* 
		* Inside IF statement:
		* 1. Display the sentence "Runner #1 WON..."
		*    then stop the WHILE loop using BREAK
		* End of IF statement
		*/
		if (positionRunner[0] >= finishingLine && positionRunner[1] < finishingLine)
		{
			cout << "RUNNER #1 WON THE MATCH!!!" << endl;
			break;
		}

		/*
		* ELSE-IF the array variable 'positionRunner' index 0
		* is more than or equal to the global constant finishingLine
		* AND the array variable 'positionRunner' index 1
		* is also more than or equal to the global constant finishingLine
		*
		* Inside ELSE-IF statement:
		* 1. Display the sentence "IT'S A TIE!"
		* 
		* 2. This FOR loop will loop for 3 times
		*    where integer 'k' is equal to 3 (initial value)
		*    while 'k' is more than or equal to 1
		*    'k' will decrement by 1
		* 
		* Inside FOR loop:
		* 3. Display countdown the race 'k' seconds
		* 
		* 4. Call the function 'delay' and pass in
		*    value 1.0 as a parameter into the function
		* End of FOR loop
		* 
		* 5. Display the word "REMATCH!!!"
		* 
		* 6. Call the function 'delay' and pass in
		*    value 1.0 as a parameter into the function
		* 
		* 7. Change the values of array index 0 and
		*    index 1 of variable positionRunner into value 1
		*    then increment the variable 'match' by 1
		* End of ELSE-IF statement
		*/
		else if (positionRunner[0] >= finishingLine && positionRunner[1] >= finishingLine)
		{
			cout << "IT'S A TIE!\n" << endl;
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

		/*
		* ELSE-IF the array variable 'positionRunner' index 1
		* is more than or equal to the global constant finishingLine
		* AND the array variable 'positionRunner' index 0
		* is less than the global constant finishingLine
		*
		* Inside ELSE-IF statement:
		* 1. Display the sentence "Runner #2 WON..."
		*    then stop the WHILE loop using BREAK
		* End of ELSE-IF statement
		*/
		else if (positionRunner[1] >= finishingLine && positionRunner[0] < finishingLine)
		{
			cout << "RUNNER #2 WON THE MATCH!!!" << endl;
			break;
		}

		// Call the function 'clearConsole'
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
	* local variable 'randomNumber' is declared as
	* an integer variable where it is equal to
	* the generated integer number by rand() in range of 1 to 10
	*/
	int randomNumber = (rand() % 10) + 1;

	// return 'randomNumber' as the function value
	return randomNumber;
}

/*
* Declare 'delay' as a void return-type function
* pass in a float-type argument, 'seconds' into this function
*/
void delay(float seconds) {
	/*
	* clock_t is a type defined in <ctime> library
	* Call the standard function 'clock' from <ctime> library
	* where the local variable startClock will store
	* the value taken from standard function 'clock'
	*/
	clock_t startClock = clock();

	/*
	* local variable 'secondsAhead' is declared as a float variable
	* where 'secondsAhead' is equal the float-type argument
	* received by this function, 'seconds' multiply with
	* 'CLOCKS_PER_SEC', a Defined Macro found in <ctime> library
	*/
	float secondsAhead = seconds * CLOCKS_PER_SEC;

	/*
	* WHILE clock() is less than
	* 'startClock' + 'secondsAhead'
	* Do nothing until the elapsed time has passed
	*/
	while (clock() < startClock + secondsAhead);
}

/*
* Declare 'clearConsole' as a void return-type function
* there is no argument will be pass into this function
* therefore argument-type void is used inside parentheses
*/
// This function is used to clear the screen of terminal
void clearConsole(void) {
	/*
	* IF the user run the program at WINDOWS machine,
	* pass the command "cls" to the terminal and execute
	* to clear the screen of the terminal
	*/
	#if defined _WIN32
		system("cls");

	/*
	* IF the user run the program at LINUX-based machine,
	* pass the command "clear" to the terminal and execute
	* to clear the screen of the terminal
	*/
	#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
		system("clear");

	/*
	* IF the user run the program at macOS machine,
	* pass the command "clear" to the terminal and execute
	* to clear the screen of the terminal
	*/
	#elif defined (__APPLE__)
		system("clear");
	#endif
}

/*
* Declare 'runnersAction' as an integer return-type function
* pass in 2 integer-type arguments
* 'verifyRunner' and 'randomNumber' into this function
*/
int runnersAction(int verifyRunner, int randomNumber) {
	// local variable 'actionNumber' is declared as an integer variable
	int actionNumber;

	/*
	* IF the integer-type argument received by this function,
	* 'verifyRunner is equal to 0
	* 
	* Inside IF statement:
	* 1. IF the interger-type argument
	*    'randomNumber' is more than or equal to 1
	*    AND less than or equal to 5,
	*    actionNumber will be given value 1
	* 
	* 2. ELSE-IF the interger-type argument
	*    'randomNumber' is more than or equal to 6
	*    AND less than or equal to 7,
	*    actionNumber will be given value 2
	* 
	* 3. ELSE
	*    actionNumber will be given value 3
	*/
	if (verifyRunner == 0) {
		if (randomNumber >= 1 && randomNumber <= 5)
			actionNumber = 1;
		else if (randomNumber >= 6 && randomNumber <= 7)
			actionNumber = 2;
		else
			actionNumber = 3;
	}

	/*
	* ELSE (verifyRunner is not equal to 0)
	*
	* Inside ELSE statement:
	* 1. IF the interger-type argument
	*    'randomNumber' is more than or equal to 1
	*    AND less than or equal to 3,
	*    actionNumber will be given value 4
	*
	* 2. ELSE-IF the interger-type argument
	*    'randomNumber' is more than or equal to 4
	*    AND less than or equal to 5,
	*    actionNumber will be given value 5
	* 
	* 3. ELSE-IF the interger-type argument
	*    'randomNumber' is equal to 6
	*    actionNumber will be given value 6
	* 
	* 4. ELSE-IF the interger-type argument
	*    'randomNumber' is more than or equal to 7
	*    AND less than or equal to 8,
	*    actionNumber will be given value 7
	*
	* 5. ELSE
	*    actionNumber will be given value 8
	*/
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

/*
* Declare 'calculatePosition' as an integer return-type function
* pass in 2 integer-type arguments,
* 'runnerPosition' and 'actionNumber' into this function
*/
int calculatePosition(int runnerPosition, int actionNumber) {
	/*
	* SWITCH CASE is implement, where
	* the interger-type argument 'actionNumber'
	* will be the expression for this SWITCH CASE
	*/
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
	
	/*
	* IF the integer-type argument received by this function,
	* 'runnerPosition' is less than 1 after the calculation in SWITCH CASE
	* 
	* Inside IF statement:
	* 1. overwrite the value of the integer-type argument,
	*    'runnerPosition' into value 1
	* End of IF statement
	*/
	if (runnerPosition < 1)
		runnerPosition = 1;
	
	// return 'runnerPosition' as the function value
	return runnerPosition;
}

/*
* Declare 'programTitle' as a void return-type function
* pass in an integer-type argument, 'match' into this function
*/
void programTitle(int match) {
	/*
	* 1. Display the words "TRACK & FIELD RACE"
	* 
	* 2. Display the words "Match No. ",
	*    following by 'match', which is an integer-type argument
	*    received by this function
	*/
	cout << ' ' << setw(67) << left << setfill('=') << '=' << ' ' << endl;
	cout << '|' << setw(42) << right << setfill(' ') << "TRACK & FIELD RACE" << setw(26) << '|' << endl;
	cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
	cout << "| Match No. " << setw(56) << left << setfill(' ') << match << '|' << endl;
}

/*
* Declare 'actionMessage' as a void return-type function
* pass in 4 integer-type arguments,
* 'randomNumber', 'runner', 'runnerPosition' and 'actionNumber'
* into this function.
*/
void actionMessage(int randomNumber, int runner, int runnerPosition, int actionNumber) {
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
		if (runnerPosition == 1)
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
		if (runnerPosition == 1)
			cout << "| " << setw(66) << left << setfill(' ') << "Runner 2 WALKS and return to starting point." << '|' << endl;
		else
			cout << "| " << setw(66) << left << setfill(' ') << "Runner 2 WALKS and move 2 squares behind." << '|' << endl;
		break;
	case 7:
		if (runnerPosition == 1)
			cout << "| " << setw(66) << left << setfill(' ') << "Runner 2 CRAWLS and return to starting point." << '|' << endl;
		else
			cout << "| " << setw(66) << left << setfill(' ') << "Runner 2 CRAWLS and move 4 squares behind." << '|' << endl;
		break;
	default:
		cout << "| " << setw(66) << left << setfill(' ') << "Runner 2 SLEEPS and nothing happens." << '|' << endl;
	}
	cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
}

/*
* Declare 'showPosition' as a void return-type function
* pass in 2 integer-type arguments,
* 'runnerPosition' and 'runner' into this function
*/
void showPosition(int runnerPosition, int runner) {
	/*
	* 1. IF the integer-type arguments received by this function,
	*    'runnerPosition' is less than the global constant 'finishingLine',
	*    Display a specific output
	* 
	* 2. ELSE-IF the integer-type arguments received by this function,
	*    'runnerPosition' is equal to the global constant 'finishingLine',
	*    Display a specific output
	* 
	* 3. ELSE
	*    Display a specific output
	*/
	if (runnerPosition < finishingLine)
		cout << "| " << setw(runnerPosition) << right << setfill(' ') << runner << setw(60 - runnerPosition) << '|' << setw(7) << " |" << endl;
	else if (runnerPosition == finishingLine)
		cout << "| " << setw(60) << right << setfill(' ') << runner << setw(5) << ' ' << " |" << endl;
	else
		cout << "| " << setw(60) << right << setfill(' ') << '|' << setw(abs(60 - runnerPosition)) << runner << setw(67 - runnerPosition) << " |" << endl;
}

/*
* Declare 'showTrack' as a void return-type function
* pass in 3 integer-type arguments, 'positionRunnerOne',
* 'positionRunnerTwo' and 'seconds' into this function
*/
void showTrack(int positionRunnerOne, int positionRunnerTwo, int seconds) {
	/*
	* 1. Display the words "Runner #", following by 'runners' index 0,
	*    which is an integer array constant and the words "Current Position: ",
	*    following by 'positionRunnerOne', which is an integer-type argument
	*    received by this function
	* 
	* 2. Display the words "Runner #", following by 'runners' index 1,
	*    which is an integer array constant and the words "Current Position: ",
	*    following by 'positionRunnerTwo', which is an integer-type argument
	*    received by this function
	* 
	* 3. Display the word "Track:"
	*/
	cout << "| Runner #" << runners[0] << " Current Position: " << setw(38) << left << setfill(' ') << positionRunnerOne << '|' << endl;
	cout << "| Runner #" << runners[1] << " Current Position: " << setw(38) << left << setfill(' ') << positionRunnerTwo << '|' << endl;
	cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
	cout << '|' << setw(67) << left << setfill(' ') << " Track:" << '|' << endl;
	cout << "| " << setw(60) << right << setfill('-') << '|' << setw(5) << '-' << " |" << endl;

	/*
	* 1. Call the function 'showPosition' and pass in
	*    integer-type argument received by this function,
	*    'positionRunnerOne' and integer array constant 'runners' index 0
	*    as parameters into the function
	* 
	* 2. Call the function 'showPosition' and pass in
	*    integer-type argument received by this function,
	*    'positionRunnerTwo' and integer array constant 'runners' index 1
	*    as parameters into the function
	*/
	showPosition(positionRunnerOne, runners[0]);
	cout << "| " << setw(60) << right << setfill('-') << '|' << setw(5) << '-' << " |" << endl;
	showPosition(positionRunnerTwo, runners[1]);
	cout << "| " << setw(60) << right << setfill('-') << '|' << setw(5) << '-' << " |" << endl;
	cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
	
	/*
	* IF the integer-type arguments received by this function
	* 'positionRunnerOne' and 'positionRunnerTwo'
	* are equal to each others AND another integer-type argument
	* 'seconds' received by this function is more than 1
	* 
	* Inside IF statement:
	* 1. Display the following sentence "GOTCHA!!..."
	* End of IF statement
	*/
	if (positionRunnerOne == positionRunnerTwo && seconds > 1)
	{
		cout << "| " << setw(66) << left << setfill(' ') << "GOTCHA!!! Both runners clash together!" << '|' << endl;
		cout << '|' << setw(67) << left << setfill('=') << '=' << '|' << endl;
	}
}

/*
* Declare 'timeElapse' as an integer return-type function
* pass in an integer-type argument, 'seconds' into this function
*/
int timeElapse(int seconds) {
	/*
	* 1. Display the words "Time Elapsed(s):",
	*    folllowing by 'seconds', which is an integer-type argument
	*    received by this function
	* 
	* 2. Then increment the argument, 'seconds' by 1
	*/
	cout << "| Time Elapsed(s): " << setw(49) << left << setfill(' ') << seconds << '|' << endl;
	cout << ' ' << setw(67) << left << setfill('=') << '=' << ' ' << endl << endl;
	seconds++;

	// return 'seconds' as the function value
	return seconds;
}