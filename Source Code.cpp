#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

using namespace std;

//Global variable
int margin = 20;
int totalPiece = 25, digitFloor = 0, digitCeiling = 5;
int countPlay = 0, countWin = 0, countLose = 0;
bool mode = 0, rule = 0;

//Repetitive line for reuse
void anyKey() {
	cout << "Press any key to continue...";
	_getch();
	cout << endl;
};

void divder() {
	cout << setw(80) << setfill('-') << "" << endl << setfill(' ') << "";
};

void newPage() {
	divder();
	for (int i = 0; i < 27; i++)
		cout << endl;
};

void errorMsg(string msg) {
	cout << endl << setw(20) << "" << "Error: " << msg << endl;
	divder();
};

//Welcome Message
void welcome() {
	int space = 8;
	int margin = 2;

	// Instruction for gaming environment, 80 is the default terminal size
	cout << "Hints: Make sure your terminal width are 80 characters or above" << endl 
		<< "Loading..." << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(1000)); //waiting for 1second

	divder();
	cout << setw(margin) << "" << "xxxxxxxxxxx " << " xxxxxxxxxxxx   " << " xxxxxxxxxx " << " xxxxxxxxxxxx " << "xxxxxxxxxxx" << setw(space + 1) << "====" << endl
		<< setw(margin) << "" << "xx       xx " << " x++++++++++x   " << " x++++++++x " << " x+++++++++x " << " x+++++++++x" << setw(space) << "||" << endl
		<< setw(margin) << "" << "xx  xxxxxxx " << " x++xxxxxx++x   " << " x++xxxx++x " << " x++xxxxxxxx " << " x++xxxxxxxx" << setw(space) << "||" << endl
		<< setw(margin) << "" << "xx  xx      " << " x++x    x++x   " << " x++x  x++x " << " x++x        " << " x++x       " << setw(space) << "||" << endl
		<< setw(margin) << "" << "xx  xx      " << " x++xxxxxx++x   " << " x++x  x++x " << " x++xxxxxxxx " << " x++xxxxxxxx" << setw(space) << "||" << endl
		<< setw(margin) << "" << "xx  xx      " << " x++++++++++x   " << " x++x  x++x " << " x+++++++++x " << " x+++++++++x" << " |=========|" << endl
		<< setw(margin) << "" << "xx  xx      " << " x++xxxx++xxx   " << " x++x  x++x " << " xxxxxxxx++x " << " xxxxxxxx++x" << setw(space) << "||" << endl
		<< setw(margin) << "" << "xx  xx      " << " x++x  x++x     " << " x++x  x++x " << "        x++x " << "        x++x" << setw(space) << "||" << endl
		<< setw(margin) << "" << "xx  xxxxxxx " << " x++x  x++xxxxx " << " x++xxxx++x " << " xxxxxxxx++x " << " xxxxxxxx++x" << setw(space) << "||" << endl
		<< setw(margin) << "" << "xx       xx " << " x++x  x++++++x " << " x++++++++x " << " x+++++++++x " << " x+++++++++x" << setw(space) << "||" << endl
		<< setw(margin) << "" << "xxxxxxxxxxx " << " xxxx  xxxxxxxx " << " xxxxxxxxxx " << " xxxxxxxxxxx " << " xxxxxxxxxxx" << setw(space + 1) << "====" << endl;
	cout << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));

	cout << setw(margin) << "" << "xxxxxxxxxxx " << " xxxx  xxxx " << " xxxxxxxxxxxx " << " xxxxxxxxxxxx " << " xxxx         " << " xxxxxxxxxx " << endl
		<< setw(margin) << "" << "xx       xx " << " x++x  x++x " << " x++++++++++x " << " x++++++++++x " << " x++x         " << " x++++++++x " << endl
		<< setw(margin) << "" << "xx  xxxx xx " << " x++x  x++x " << " xxxxxxxxx++x " << " xxxxxxxxx++x " << " x++x         " << " x++xxxxxxx " << endl
		<< setw(margin) << "" << "xx  x  x xx " << " x++x  x++x " << "      xx++xx  " << "      xx++xx  " << " x++x         " << " x++x       " << endl
		<< setw(margin) << "" << "xx  xxxx xx " << " x++x  x++x " << "     xx++xx   " << "     xx++xx   " << " x++x         " << " x++xxxxxxx " << endl
		<< setw(margin) << "" << "xx       xx " << " x++x  x++x " << "    xx++xx    " << "    xx++xx    " << " x++x         " << " x++++++++x " << endl
		<< setw(margin) << "" << "xx  xxxxxxx " << " x++x  x++x " << "  xx++xx      " << "  xx++xx      " << " x++x         " << " x++xxxxxxx " << endl
		<< setw(margin) << "" << "xx  xx      " << " x++x  x++x " << " xx++xx       " << " xx++xx       " << " x++x         " << " x++x       " << endl
		<< setw(margin) << "" << "xx  xx      " << " x++xxxx++x " << " x++xxxxxxxxx " << " x++xxxxxxxxx " << " x++xxxxxxxxx " << " x++xxxxxxx " << endl
		<< setw(margin) << "" << "xx  xx      " << " x++++++++x " << " x++++++++++x " << " x++++++++++x " << " x++++++++++x " << " x++++++++x " << endl
		<< setw(margin) << "" << "xxxxxx      " << " xxxxxxxxxx " << " xxxxxxxxxxxx " << " xxxxxxxxxxxx " << " xxxxxxxxxxxx " << " xxxxxxxxxx " << endl;

	cout << endl << endl;

	divder();
	anyKey();

	return;
};

//All member fucntions and data member of Puzzle Pieces 
class Piece {
public:
	//Constructor function
	Piece() {}

	//Player Action
	void rotate(char direction) { //direction = 'c' or 'a'
		int temp = digitN;
		switch (direction) {
		case 'c':
			digitN = digitW; digitW = digitS; digitS = digitE; digitE = temp; break;
		case 'a':
			digitN = digitE; digitE = digitS; digitS = digitW; digitW = temp; break;
		case 'q': break;
		default: divder();  errorMsg("Please enter c for clockwise, a for anticlockwise, q for cancel");
		}
	}

	void print() {
		cout << " " << digitN << " " << endl
			<< digitW << letter << digitE << endl
			<< " " << digitS << " " << endl;
	}

	//Set function
	void setPiece(char l, int N, int S, int E, int W) {
		letter = l;
		digitN = N; digitS = S; digitE = E; digitW = W;
		column = '\0'; row = 0;
		placed = 0;
	}

	void setLetter(char l) {
		letter = l;
	}

	void setLocation(char c, int r, bool p) {
		column = c;
		row = r;
		placed = p;
		if (mode == 1)
			placed = 1;
	}

	void setPlaced(bool p) {
		placed = p;
	}

	//Get function
	int getDigit(char const NSEW) {
		switch (NSEW) {
		case 'N': return digitN; break;
		case 'S': return digitS; break;
		case 'E': return digitE; break;
		case 'W': return digitW; break;
		default: errorMsg("");
		}
		return EXIT_SUCCESS;
	}

	char getLetter() {
		return letter;
	}

	char getColumn() {
		return column;
	}

	int getRow() {
		return row;
	}

	bool getPlaced() {
		return placed;
	}

private:
	char detail[2][2];

	//Piece Appearance
	char letter; // from A-Z
	int digitN, digitS, digitE, digitW; // from 0-9

	//Location 
	char column;
	int row;
	bool placed;
};

void menu();
void game();
void rules();
void gameBoard(Piece [], int &);
void GenerateNSEW(int&, int&, int&, int&);
void config();
void feature();
void credit();
void exits();


int main()
{
	cout << "\033[0;37m" << endl; // white color : normal text color 
	welcome();
	menu();
	return 0;
}


//Main Menu
void menu() {
	newPage();

	int option = 0, margin = 2;

	cout << setw(margin) << "" << "*** Main Menu ***\n"
		<< setw(margin) << "" << "[1] Start Game\n"
		<< setw(margin) << "" << "[2] Settings\n"
		<< setw(margin) << "" << "[3] Useful feature(s) added\n"
		<< setw(margin) << "" << "[4] Credits\n"
		<< setw(margin) << "" << "[5] Exit\n"
		<< setw(margin) << "" << "****************\n"
		<< setw(margin) << "" << "\n"
		<< setw(margin) << "" << "Option (1-5): ";
	cin >> option;
	divder();

	switch (option) {
	case 1: game();  break;
	case 2: config(); break;
	case 3: feature(); break;
	case 4: credit();  break;
	case 5: exits();  break;
	default: 
		errorMsg("Please enter a number from 1 to 5.");
		divder(); 
		anyKey();
		menu();
	}

	return;
}

int searchIndex(int page) {
	int l = 65;
	switch (page) {
		case 1: l = 65; break;
		case 2: l = 70; break;
		case 3: l = 75; break;
		case 4: l = 80; break;
		case 5: l = 86; break;
		default: errorMsg("");
	}
	return l;
}

//Start the game
void game() {
	newPage(); countPlay += 1;
	cout << "Game started! Now generating your puzzle..." << endl;
	this_thread::sleep_for(chrono::milliseconds(2000)); 

	// Algorithm: solution[] digitNSEW -> letter -> saved to puzzle[] -> puzzle[] rotate


	// Generate the solution
	Piece* solution = new Piece[totalPiece];

	// Generate digitNSEW and letter
	for (int pieceID = 0; pieceID < totalPiece; pieceID++) 
	{
		int N = 0, S = 0, E = 0, W = 0;

		if (pieceID == 0) GenerateNSEW(N, S, E, W); //For piece1
		else if (pieceID % 5 != 0) { //For the first pieces of the row
			GenerateNSEW(N, S, E, W);
			W = solution[pieceID - 1].getDigit('E');
		}
		else { //Other pieces
			GenerateNSEW(N, S, E, W);
			N = solution[pieceID - 5].getDigit('S');
			E = solution[pieceID - 1].getDigit('W');
		}

		// Random repeatable letter excluding Q
		int l = 65 + rand() % (totalPiece+1);
		while (l == 'Q') {
			l = 65 + rand() % (totalPiece+1);
		}

		solution[pieceID].setPiece(l, N, S, E, W);
		// cout << l << " " << N << " " << S << " " << E << " " << W << " done " <<  pieceID << endl; //For Debugging
	}

	// Transforming letter
	for (int pieceID = 1; pieceID < totalPiece;) { //The first letter won't be Q
		bool invalid = 0; //invalid means repeated letter or the letter is Q

		if (solution[pieceID].getLetter() == 'Q') 
			invalid = 1;

		for (int i = 0; i < (totalPiece - 1); i++) {
			if (solution[pieceID].getLetter() == solution[i].getLetter() && i != pieceID) 
				invalid = 1;
		}

		if(invalid == 0) pieceID++;
		else solution[pieceID].setLetter(65 + rand() % (totalPiece+1));
	}

	/* //For Debugging
	for(int pieceID=0;  pieceID < totalPiece; pieceID++){
		cout << "Now is piece" << pieceID << endl;
		solution[pieceID].print(); divder();
	} */
	
	Piece* puzzle = new Piece[totalPiece];

	for (int pieceID = 0; pieceID < totalPiece; pieceID++) {
		//Saved to puzzle[]
		puzzle[pieceID].setPiece(
			solution[pieceID].getLetter(),
			solution[pieceID].getDigit('N'),
			solution[pieceID].getDigit('S'),
			solution[pieceID].getDigit('E'),
			solution[pieceID].getDigit('W')
		);

		//Rotate the pieces
		int randNum = 1 + rand() % 4;
		for (int i = 1; i != randNum; i++)
			puzzle[pieceID].rotate('c');
	}



	for (int pieceID = 0; pieceID < totalPiece; pieceID++) {
		//Set Location of pieces
		char column; int row;

		switch (pieceID % 5) {
			case 0: column = 'A'; break;
			case 1: column = 'B'; break;
			case 2: column = 'C'; break;
			case 3: column = 'D'; break;
			case 4: column = 'E'; break;
			default: errorMsg("");
		}

		if (pieceID < 5) row = 1;
			else if (pieceID >= 5 && pieceID <= 9) row = 2;
			else if (pieceID >= 10 && pieceID <= 14) row = 3;
			else if (pieceID >= 15 && pieceID <= 19) row = 4;
			else row = 5;

		puzzle[pieceID].setLocation(column, row, 0);
		solution[pieceID].setLocation(column, row, 1);

		/* //For Debugging
		   cout << pieceID << " Column: " << puzzle[pieceID].getColumn() << " Row: " << puzzle[pieceID].getRow()
		   << " Placed: " << puzzle[pieceID].getPlaced() << endl;
	   */
	}	
	
	rules();
	int page = 5;

	gameBoard(puzzle, page);
	return;
}

void rules() {
	newPage();
	divder();
	cout << setw(margin * 2 - 4) << "" << "Rules:" << endl << endl;
	cout << setw(margin-9) << "" << "To win, place all the puzzle piece into the gameboard." << endl
		<< setw(margin-11) << "" << "Make sure all the touching digit of pieces are same. E.g." << endl << endl
		<< setw(margin + 9) << "" << "piecesA" << "     " << "piecesB" << endl
		<< setw(margin + 9) << "" << "   0   " << "     " << "   1   " << endl
		<< setw(margin + 9) << "" << "  2A3  " << "     " << "  3B4  " << endl
		<< setw(margin + 9) << "" << "   5   " << "     " << "   6   " << endl;
	cout << endl << endl << endl 
		<< setw(margin * 2 - 4) << "" << "Enjoy!" << endl << endl;
	
	divder();
	cout << endl << endl << endl << endl << endl << endl << endl << endl;

	anyKey();
	return;
}

//Printing Game Board
void gameBoard(Piece puzzle[], int & page) {
	newPage();

	//Header
	cout << left << setw(10) << "Gamemode : " << right << setw(margin - 10) << ""
		<< setw(15) << "A  B  C  D  E";

	if (mode == 0) cout << setw(37) << "+-----^^^------+"; //Not-Yet-Placed box

	cout << endl
		<< left << setw(10) << ((mode == 0) ? " Default" : " Tidy Mode") << right << setw(margin - 10) << ""
		<< " +---------------+";

	if (mode == 0) cout << setw(35) << "|Not-Yet-Placed|"; //Not-Yet-Placed box

	cout << endl;

	//Print from Row 1 of the game board to the last row (Row 15)
	for (int r = 0, row = 1; row <= 5 && r <= 15; r++) { 
		//r is the row for console, row is row of gameboard

		if (r % 3 == 2) row++; //After printed digitS, switch to next row of gameboard

		// For the row without row number index 
		if (r % 3 == 0 || r % 3 == 2) {
			cout << setw(margin) << "" << " |";

			for (int column = 65; column <= 69; column++) {
				bool noMatchedPieces = 1;

				//Searching for the matched pieces
				for (int pieceID = 0; pieceID < totalPiece; pieceID++) {
					if ((puzzle[pieceID].getPlaced() == 1)
						&& row == puzzle[pieceID].getRow() && column == ((int)puzzle[pieceID].getColumn())) {
						if (r % 3 == 0) cout << " " << puzzle[pieceID].getDigit('N') << " ";
						if (r % 3 == 2) cout << " " << puzzle[pieceID].getDigit('S') << " ";
						noMatchedPieces = 0;
					}
				}
				if (noMatchedPieces == 1) cout << "   ";
			}
		}

		// For the row with row number index
		if (r % 3 == 1) {
			HANDLE console_color; 
			console_color = GetStdHandle(STD_OUTPUT_HANDLE); // Color of the console

			cout << setw(margin) << "" << row << "|";

			for (int column = 65; column <= 69; column++) {
				bool noMatchedPieces = 1;

				//Searching for the matched pieces
				for (int pieceID = 0; pieceID < totalPiece; pieceID++) {
					if ((puzzle[pieceID].getPlaced() == 1)
						&& row == puzzle[pieceID].getRow() && column == ((int)puzzle[pieceID].getColumn())) {

							cout << puzzle[pieceID].getDigit('W');
								SetConsoleTextAttribute(console_color, 8); // light grey 
							cout << puzzle[pieceID].getLetter() << "\033[0;37m" 
								<< puzzle[pieceID].getDigit('E');

							noMatchedPieces = 0;
					}
				}
				if (noMatchedPieces == 1) cout << "   ";
			}
		}

		cout << "\033[0;37m" << "|";

		if (mode == 1) { cout << endl; continue; } // If mode is "Tidy mode", do not print the pieces List

		//Not-Yet-Placed Pieces List
		HANDLE console_color; 
		console_color = GetStdHandle(STD_OUTPUT_HANDLE); // Color of the console

		int placedRow = 0, l = (row-1) + searchIndex(page);
		bool noMatchedPieces = 0;
		if (l >= 81) l += 1;

		for (int pieceID = 0; pieceID < totalPiece && placedRow == 0; pieceID++) {
			if (puzzle[pieceID].getLetter() == l) {
				noMatchedPieces = 1;
				if (r % 3 == 0) {
					cout << setw(20) << "|" << setw(6) << " ";
					SetConsoleTextAttribute(console_color, 4);
					cout << puzzle[pieceID].getDigit('N') << "\033[0;37m" << " " << setw(7) << " |";
				}
				if (r % 3 == 1) {
					cout << setw(20) << "|" << setw(6);
					SetConsoleTextAttribute(console_color, 4);
					cout << puzzle[pieceID].getDigit('W') << (char)l << puzzle[pieceID].getDigit('E') << "\033[0;37m" << setw(7) << " |";
				}
				if (r % 3 == 2) {
					cout << setw(20) << "|" << setw(6) << " ";
					SetConsoleTextAttribute(console_color, 4);
					cout << puzzle[pieceID].getDigit('S') << "\033[0;37m" << " " << setw(7) << " |";
				}
				placedRow = 1;
				cout << "\033[0;37m";
			}
		}
		 if (noMatchedPieces == 0) 
			cout << setw(20) << "|" << setw(6) << "   " << setw(9) << " |";

		cout << endl;
	}

	//Last line
	cout << setw(margin) << "" << " +---------------+" << setw(35);
	if (mode == 0) cout << "+-----vvv------+" << endl;


}

//Generate and assign random number to digit NSEW
void GenerateNSEW(int& N, int& S, int& E, int& W) {
	for (int i = 0, randNum; i < 4; i++) {
		if ((digitCeiling - digitFloor) == 0)
			randNum = digitFloor;
		else
			randNum = digitFloor + rand() % (digitCeiling - digitFloor + 1);

		// Assign the number generated randomly to digitNSEW 
		switch (i) {
		case 0: N = randNum; break;
		case 1: S = randNum; break;
		case 2: E = randNum; break;
		case 3: W = randNum; break;
		default: errorMsg("");
		}
	}
	return;
}

//setting
void config() {
	int option, pieceNum, rangeNum1, rangeNum2;
	cout << "\n*** Settings Menu ***" << endl
		<< "[1] Change Number of puzzle piece \n\t-> Current: " << totalPiece << endl
		<< "[2] Change Range of random number \n\t-> Current: " << digitFloor << " - " << digitCeiling << endl
		<< "[3] Return to Main Menu" << endl
		<< "***************************" << endl << endl
		<< "Option (1-3): ";
	cin >> option;

	switch (option) {
	case 1:
		do {
			cout << "Input a new value for Number of puzzle piece (from 1-25): ";
			cin >> pieceNum;

			//Checking for Valid input
			if (pieceNum >= 1 && pieceNum <= 25) {
				totalPiece = pieceNum;
				menu();
			}
			else
				errorMsg("Please input a number from 1 to 25");
		} while (pieceNum < 1 || pieceNum > 25);
		break;

	case 2:
		do {
			cout << "Input a new value for Range of random number (from 0-9):  " << endl
				<< "from ";
			cin >> rangeNum1;
			cout << "to ";
			cin >> rangeNum2;

			//Checking for Valid input
			if (rangeNum1 >= 0 && rangeNum2 >= rangeNum1 && rangeNum2 <= 9) {
				digitFloor = rangeNum1;
				digitCeiling = rangeNum2;
				menu();
			}
			else
				errorMsg("Please input a number from 0 to 9 for each number");
		} while (rangeNum1 < 0 || rangeNum2 > 9 || rangeNum2 <= rangeNum1);
		break;

	case 3: main(); break;

	default: 
		errorMsg("Please input a number from 1 to 5.");
		config();
	}
}

//Additional Feature
void feature() {
	int option;
	cout << "*** Menu ***\n"
		<< "[1] Statistic\n"
		<< "[2] Gamemode\n"
		<< "[3] Displaying Rules\n"
		<< "****************\n"
		<< "\n"
		<< "Option (1-3): ";
	cin >> option;

	switch (option) {
	case 1:
		char option2;

		cout << "Puzzles played: " << countPlay << endl
			<< "Puzzles wined: " << countWin << endl
			<< "Puzzles losed: " << countLose << endl
			<< "press q to return to menu: ";
		
		cin >> option2;
		if (option2 == 'q' || option2 == 'Q')
			cout << endl;
		menu();
		break;

	case 2:
		char option3;

		cout << "Current Gamemode: Default" << endl
			<< "Type y to change to 'Tidy' Mode, type anything else to cancel: ";

		cin >> option3;
		if (option3 == 'y' || option3 == 'Y')
			mode = 1;
		menu();
		break;

	case 3:
		break;
	default: errorMsg("Please input a number from 1 to 3"); feature();
	}

	return;
}

//Credit
void credit() {
	newPage();

	int margin = 2;
	char option;
	cout << setw(margin) << "" << "Credits:" << endl
		<< setw(margin) << "" << "21043941A HON Sin Hang Aaron 203A" << endl
		<< setw(margin) << "" << "21000210A Yeung Miu Wan 203A" << endl
		<< setw(margin) << "" << "21132728A Li Yin Cheung 203A" << endl
		<< setw(margin) << "" << "21073380A Chu Kiu Tsun 203A" << endl
		<< setw(margin) << "" << "21079810A Chu Sik Hin 203A" << endl << endl;

	anyKey();
	menu();
	return;
}

//Exit
void exits() {
	newPage();

	char ch;
	cout << "Close the game? Please noted that your data will be lost when closing the game" << endl
		<< "Enter y for yes, n for no." << endl;
	cin >> ch;

	if (ch == 'n' || ch == 'N'){
		cout << "Game continued!" << endl << "Returning to Main menu...";
		this_thread::sleep_for(chrono::milliseconds(1000)); 
		menu();
	}
	else if (ch == 'y' || ch == 'Y') exit(0); //Program terminates
	else { 
		errorMsg("Please enter y for yes, n for no."); 
		exits();
	}
	return;
}
