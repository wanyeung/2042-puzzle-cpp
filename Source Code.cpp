#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

int margin = 30;

//Welcome Message
void welcome() {
	int space = 8;
	int margin = 2;

	cout << "Hints: Make sure your terminal width are 80 characters or above" << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));

	cout << setw(80) << setfill('-') << "" << endl << setfill(' ') << "";
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
	cout << setw(80) << setfill('-') << "" << endl << setfill(' ') << "";

	this_thread::sleep_for(chrono::milliseconds(1000));
	return;
};


int totalPiece = 15, digitFloor = 0, digitCeiling = 5;
int countPlay = 0, countWin = 0, countLose = 0;
bool mode = 0, rule = 0;

class Piece {
public:
	//Constructor function
	Piece() {}

	//Player Action
	void rotate(char direction) { //direction = 'c' or 'a'
		int temp = digitN;
		switch (direction) {
		case 'c':
			digitN = digitW;
			digitW = digitS;
			digitS = digitE;
			digitE = temp;
			break;
		case 'a':
			digitN = digitE;
			digitE = digitS;
			digitS = digitW;
			digitW = temp;
			break;
		case 'q': break;
		default: cout << "Error: Please type c for clockwise, a for anticlockwise, q for cancel";
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
		default: cout << "Error";
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
void gameBoard(Piece puzzle[]);
void GenerateNSEW(int &, int &, int &, int &);
void config();
void feature();
void credit();
void exits();


int main()
{

	welcome();
	menu();
	return 0;
}


//Main Menu
void menu() {
	int option;
	cout << "*** Main Menu ***\n"
		<< "[1] Start Game\n"
		<< "[2] Settings\n"
		<< "[3] Useful feature(s) added\n"
		<< "[4] Credits\n"
		<< "[5] Exit\n"
		<< "****************\n"
		<< "\n"
		<< "Option (1-5): ";
	cin >> option;

	switch (option) {
	case 1: cout << endl << endl; game();  break;
	case 2: cout << endl << endl; config(); break;
	case 3: cout << endl << endl; feature(); break;
	case 4: cout << endl << endl; credit();  break;
	case 5: cout << endl << endl; exits();  break;
	default: cout << endl << "Please input a number from 1 to 5." << endl << endl; menu();
	}

	return;
}

//Start the game
void game() {
	countPlay += 1;
	// Generate the solution array with puzzles pieces
	Piece *solution = new Piece[totalPiece];

	for (int pieceID = 0; pieceID < totalPiece; pieceID++) {
		int l = pieceID + 65, N = 0, S = 0, E = 0, W = 0;

		//Generate the digitNSEW for piece1
		if (pieceID == 0)
			GenerateNSEW(N, S, E, W);
		//Generate all left pieces except piece1 
		else if (pieceID % 5 != 0) {
			GenerateNSEW(N, S, E, W);
			W = solution[pieceID - 1].getDigit('E');
		}
		else {
			//Generate all other pieces
			GenerateNSEW(N, S, E, W);
			N = solution[pieceID - 5].getDigit('S');
			E = solution[pieceID - 1].getDigit('W');
		}

		solution[pieceID].setPiece(l, N, S, E, W);
		/*
		//For Debugging
		cout << l << " " << N << " " << S << " " << E << " " << W << " done " <<  pieceID << endl;
		*/
	}

	//Transforming the pieces
	Piece *puzzle = new Piece[totalPiece];

	//Initialized letter, digit
	for (int pieceID = 0; pieceID < totalPiece; pieceID++) {

		puzzle[pieceID].setPiece(
			65 + rand() % totalPiece,
			solution[pieceID].getDigit('N'),
			solution[pieceID].getDigit('S'),
			solution[pieceID].getDigit('E'),
			solution[pieceID].getDigit('W')
		);
		/*
		//For Debugging
		cout << puzzle[pieceID].getLetter() << " ";
		*/
	}

	cout << endl;

	//Transforming the letter

	for (int pieceID = 1; pieceID < totalPiece;) {
		bool change = 0;

		for (int i = 0; i < (totalPiece - 1); i++) {
			if (puzzle[pieceID].getLetter() == puzzle[i].getLetter() && i != pieceID) {
				change = 1;
			}
		}

		if (change == 0)
			pieceID++;
		else {
			puzzle[pieceID].setLetter(65 + rand() % totalPiece);
			solution[pieceID].setLetter(puzzle[pieceID].getLetter());   //Save puzzle[] to solution[]
		}
	}

	/*
	//For Debugging
	 for(int pieceID=0;  pieceID < totalPiece; pieceID++)
		cout << endl << puzzle[pieceID].getLetter() << " ";

	for(int pieceID=0;  pieceID < totalPiece; pieceID++)
		puzzle[pieceID].print();
	*/


	for (int pieceID = 0; pieceID < totalPiece; pieceID++) {
		//Rotating the pieces in puzzle[] which is playable puzzle
		int randNum = 1 + rand() % 4;
		for (int i = 1; i != randNum; i++)
			puzzle[pieceID].rotate('c');

		//Set Location of pieces
		char column;
		int row;

		switch (pieceID % 5) {
		case 0: column = 'A'; break;
		case 1: column = 'B'; break;
		case 2: column = 'C'; break;
		case 3: column = 'D'; break;
		case 4: column = 'E'; break;
		default: cout << "Error";
		}

		if (pieceID < 5) row = 1;
		else if (pieceID >= 5 && pieceID <= 9) row = 2;
		else if (pieceID >= 10 && pieceID <= 14) row = 3;
		else if (pieceID >= 15 && pieceID <= 19) row = 4;
		else row = 5;

		puzzle[pieceID].setLocation(column, row, 0);

		/*
		//For Debugging
		   cout << pieceID << " Column: " << puzzle[pieceID].getColumn() << " Row: " << puzzle[pieceID].getRow()
		   << " Placed: " << puzzle[pieceID].getPlaced() << endl;
	   */
	}

	gameBoard(puzzle);

	return;
}

//Print Game Board
void gameBoard(Piece puzzle[]) {

	if (mode == 0) {
		(rule == 0) ? cout << left << setw(10) << "  Rule:" << right << setw(margin - 10) << "" :
			cout << setw(margin) << "";

		cout << setw(17) << "A  B  C  D  E";

		if (mode == 0) cout << setw(26) << "+-----^^^------+";

		cout << endl;

		(rule == 0) ? cout << left << setw(10) << "  Rule:" << right << setw(margin - 10) << "" :
			cout << setw(margin) << "";

		cout << " +---------------+";
		if (mode == 0) cout << setw(25) << "|Not-Yet-Placed|" << endl;
	}


	for (int row = 1, r = 0; row <= 5 && r <= 15; r++) {

		if (r % 3 == 0 || r % 3 == 2) {
			cout << setw(margin) << "" << " |";
			for (int column = 65; column <= 69; column++) {
				//Debugging
				//cout << endl << "Now is column" << (char) column << endl;

				bool noExistedPieces = 1;
				for (int pieceID = 0; pieceID < totalPiece; pieceID++) {
					/*
					//Debugging
					cout << endl << "Now is pieceID" << pieceID << " " << puzzle[pieceID].getRow() << " " <<
					(int)puzzle[pieceID].getColumn() << endl;

					//cout << "Row:" << row << " Column:" << column << endl;
					*/

					if ((puzzle[pieceID].getPlaced() == 0)
						&& row == puzzle[pieceID].getRow() && column == ((int)puzzle[pieceID].getColumn())) {
						if (r % 3 == 0) cout << " " << puzzle[pieceID].getDigit('N') << " ";
						if (r % 3 == 2) cout << " " << puzzle[pieceID].getDigit('S') << " ";
						noExistedPieces = 0;
					}
				}
				if (noExistedPieces == 1) cout << "   ";
			}
			if (r % 3 == 2)
				row++;
		}


		if (r % 3 == 1) {
			cout << setw(margin) << "" << row << "|";
			for (int column = 65; column <= 69; column++) {
				bool noExistedPieces = 1;
				for (int pieceID = 0; pieceID < totalPiece; pieceID++) {
					if ((puzzle[pieceID].getPlaced() == 0)
						&& row == puzzle[pieceID].getRow() && column == ((int)puzzle[pieceID].getColumn())) {
						cout << puzzle[pieceID].getDigit('W') << puzzle[pieceID].getLetter() << puzzle[pieceID].getDigit('E');
						noExistedPieces = 0;
					}
				}
				if (noExistedPieces == 1) cout << "   ";
			}
		}

		cout << "|";

		if (mode == 0) {
			int placedRow = 0;
			for (int pieceID = 0; pieceID < totalPiece && placedRow == 0; pieceID++) {
				for (int l = 65; l <= 90 && l != 81; l++)
					if ((char)puzzle[pieceID].getLetter() == l) {
						if (r % 3 == 0) cout << setw(10) << "|" << setw(6) << " " << puzzle[pieceID].getDigit('N') << " " << setw(7) << " |";
						if (r % 3 == 1) cout << setw(10) << "|" << setw(6) << puzzle[pieceID].getDigit('W') << (char)l << puzzle[pieceID].getDigit('E') << setw(7) << " |";
						if (r % 3 == 2) cout << setw(10) << "|" << setw(6) << " " << puzzle[pieceID].getDigit('S') << " " << setw(7) << " |";
						placedRow = 1;
					}
			}
		}

		cout << endl;
	}

	cout << setw(margin) << "" << " +---------------+" << setw(25) << "+-----vvv------+" << endl;
}

//Generate and assign random number to digit NSEW
void GenerateNSEW(int & N, int & S, int & E, int & W) {
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
		default: cout << "Error";
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
				cout << "Error: Please input a number from 1 to 25" << endl;
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
				cout << "Error: Please input a number from 0 to 9 for each number" << endl;
		} while (rangeNum1 < 0 || rangeNum2 > 9 || rangeNum2 <= rangeNum1);
		break;

	case 3: main(); break;

	default: cout << "Error: Please input a number from 1 to 5." << endl << endl;
		config();
	}
}

//Additional Feature
void feature() {
	int option;
	cout << "*** Menu ***\n"
		<< "[1] Statistic\n"
		<< "[2] Gamemode\n"
		<< "[3] Show Rules\n"
		<< "****************\n"
		<< "\n"
		<< "Option (1-3): ";
	cin >> option;

	switch (option) {
	case 1:
		cout << "Puzzles played: " << countPlay << endl
			<< "Puzzles wined: " << countWin << endl
			<< "Puzzles losed: " << countLose << endl
			<< "press q to return to menu: ";
		char option2;
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
	default: cout << endl << "Error: Please input a number from 1 to 2." << endl << endl; menu();
	}

	return;
}

//Credit
void credit() {
	cout << setw(20) << "Credits:" << endl
		<< "21043941A HON Sin Hang Aaron 203A" << endl
		<< "21000210A Yeung Miu Wan 203A" << endl
		<< "21132728A Li Yin Cheung 203A" << endl
		<< "21073380A Chu Kiu Tsun 203A" << endl
		<< "21079810A Chu Sik Hin 203A" << endl;
	return;
}

//Exit
void exits() {
	char ch;
	cout << "Stop the game?" << endl;
	cout << "Press 'y' to confirm, 'n' to cancel." << endl;
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
		exit(0);
	if (ch == 'n' || ch == 'N') {
		cout << "game continued!" << endl;
		menu();
	}
	return;
}
