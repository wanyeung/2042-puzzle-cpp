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
int totalPiece = 15, digitFloor = 0, digitCeiling = 5;
int countPlay = 0, countWin = 0, countLose = 0, countStep;
int mode = 0, playSavedPuzzle = 0, savedPuzzle = 0;

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
	int rotate(char direction) { //direction = 'c' or 'a'
		int temp = digitN;
		switch (direction) {
		case 'c':
			digitN = digitW; digitW = digitS; digitS = digitE; digitE = temp; break;
		case 'a':
			digitN = digitE; digitE = digitS; digitS = digitW; digitW = temp; break;
		case 'q': break;
		default:
			divder();  errorMsg("Please enter c for clockwise, a for anticlockwise, q for cancel");
			return 1;
		}
		return 0;
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

	void setLocation(char c, int r, bool p) { //bug label 4
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
void gameBoard(Piece[], int&);
void GenerateNSEW(int&, int&, int&, int&);
void config();
void feature();
void credit();
void exits();

//Saved Puzzles
Piece* puzzle1 = new Piece[totalPiece];
Piece* sol_puzzle1 = new Piece[totalPiece];

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
	if (cin.fail()) { // check whether last input was failed
		cin.clear(); // Reset the input error status to no error
		cin.ignore(255, '\n'); // ignore maximum of 255 characters,
		 // or reached end of line.
	}

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
		else if (pieceID < 5) { //For the first pieces of the row 
			GenerateNSEW(N, S, E, W);
			W = solution[pieceID - 1].getDigit('E');
		}
		else { //Other pieces
			GenerateNSEW(N, S, E, W);
			N = solution[pieceID - 5].getDigit('S');
			W = solution[pieceID - 1].getDigit('E');
		}

		// Random repeatable letter excluding Q
		int l = 65 + rand() % (totalPiece + 1);
		while (l == 'Q') {
			l = 65 + rand() % (totalPiece + 1);
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

		if (invalid == 0) pieceID++;
		else solution[pieceID].setLetter(65 + rand() % (totalPiece + 1));
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

		puzzle[pieceID].setPlaced(0);
		solution[pieceID].setLocation(column, row, 1);
		if(mode==1) puzzle[pieceID].setLocation(column, row, 1);

		/* //For Debugging
		   cout << pieceID << " Column: " << puzzle[pieceID].getColumn() << " Row: " << puzzle[pieceID].getRow()
		   << " Placed: " << puzzle[pieceID].getPlaced() << endl;
	   */
	}

	/*
	 //For Debugging
	for(int pieceID=0;  pieceID < totalPiece; pieceID++){
		cout << "Now is piece" << pieceID << endl;
		puzzle[pieceID].print(); divder();
	}
	*/

	// Play saved puzzles
	if (playSavedPuzzle == 1) {
		for (int pieceID = 0; pieceID < totalPiece; pieceID++) {
			puzzle[pieceID].setPiece(puzzle1[pieceID].getLetter(), puzzle1[pieceID].getDigit('N'), puzzle1[pieceID].getDigit('S'), puzzle1[pieceID].getDigit('E'), puzzle1[pieceID].getDigit('W'));
			puzzle[pieceID].setLocation(puzzle1[pieceID].getColumn(), puzzle1[pieceID].getRow(), puzzle1[pieceID].getPlaced());
			solution[pieceID].setPiece(sol_puzzle1[pieceID].getLetter(), sol_puzzle1[pieceID].getDigit('N'), sol_puzzle1[pieceID].getDigit('S'), sol_puzzle1[pieceID].getDigit('E'), sol_puzzle1[pieceID].getDigit('W'));
			solution[pieceID].setLocation(sol_puzzle1[pieceID].getColumn(), sol_puzzle1[pieceID].getRow(), sol_puzzle1[pieceID].getPlaced());
		}
	}

	rules();
	int page = 1, round = 1;
	bool win = 0;

	//Player's Action
	for (round, win; win != 1; round++) {

		//Checking does the player placed all the pieces correctly
		for (int pieceID = 0; pieceID < totalPiece; pieceID++) {
			if (mode == 0 && puzzle[pieceID].getPlaced() == 1) {
				win = 1;
			}
			else win = 0;

			if (
				mode == 1 &&
				puzzle[pieceID].getPlaced() == 1 &&
				puzzle[pieceID].getLetter() == solution[pieceID].getLetter() &&
				puzzle[pieceID].getColumn() == solution[pieceID].getColumn() &&
				puzzle[pieceID].getRow() == solution[pieceID].getRow() &&
				puzzle[pieceID].getDigit('N') == solution[pieceID].getDigit('N') &&
				puzzle[pieceID].getDigit('S') == solution[pieceID].getDigit('S') &&
				puzzle[pieceID].getDigit('E') == solution[pieceID].getDigit('E') &&
				puzzle[pieceID].getDigit('S') == solution[pieceID].getDigit('S')
				) {
				win = 1;
				break;
			}
		}
		gameBoard(puzzle, page);
		cout << endl << endl;

		int margin = 2;

		//Choose an action
		if (mode == 0) {
			int option = 0;
			while (option != 1) {
				cout << endl << endl
					<< setw(margin) << "" << "Enter [1] to select a pieces" << endl
					<< setw(margin) << "" << "Enter [2] to go to next page" << endl
					<< setw(margin) << "" << "Enter [3] to go to previous page" << endl
					<< setw(margin) << "" << "Enter [4] to show rule" << endl
					<< setw(margin) << "" << "Option (1-4): ";
				cin >> option;
				if (cin.fail()) { // check whether last input was failed
					cin.clear(); // Reset the input error status to no error
					cin.ignore(255, '\n'); // ignore maximum of 255 characters,
					 // or reached end of line.
				}

				switch (option) {
				case 1: break;
				case 2:
					page += 1;
					if (page > 5) page = 5;
					gameBoard(puzzle, page); break;
				case 3:
					page -= 1;
					if (page < 1) page = 1;
					gameBoard(puzzle, page); break;
				case 4:
					rules();
					break;
				default: errorMsg("Please enter a number from 1 to 3"); break;
				}
			}
		}

		//Select pieces
		int selectedPiece = 0;
		char index = 'A';

		for (bool matched = 0; matched != 1;) {
			HANDLE console_color;
			console_color = GetStdHandle(STD_OUTPUT_HANDLE); // Color of the console

			cout << endl << endl << "Please enter the index to select a piece: ";
			cin >> index;

			if (index == 'Q' || index == 'q') break;

			for (int pieceID = 0; pieceID < totalPiece; pieceID++) {
				if (puzzle[pieceID].getLetter() == index) {
					selectedPiece = pieceID;
					SetConsoleTextAttribute(console_color, 8);
					cout << setw(margin) << "" << "You have selected piece" << index << endl;
					cout << "\033[0;37m";
					matched = 1;
				}
			}

			divder();
			if (matched == 0) errorMsg("Please enter a existed index in capital letter");
			anyKey();
			gameBoard(puzzle, page);
		}

		if (index == 'Q' || index == 'q') break;

		//Interact with the selected piece which is in the board
		if (mode == 0 && puzzle[selectedPiece].getPlaced() == 1) {
			char option = '0';

			bool valid = 0; // debugging

			for (bool valid = 0; valid == 0;) {
				cout << endl << "Enter y to take out the piece from board, n to cancel";
				cin >> option;
				if (option == 'y' || option == 'Y') {
					puzzle[selectedPiece].setPlaced(0);
					valid = 1;
				}
				else if (option == 'n' || option == 'N')  valid = 1;
				else if (option == 'q' || option == 'Q') valid = 1;
				else errorMsg("Please enter y or n");
			}
		}
		//Interact with the selected piece which is in the not-yet-placecd list
		else if (mode == 0 && puzzle[selectedPiece].getPlaced() == 0) {
			int option;
			bool unselected = 0, rotated = 0, placed = 0;

			while (unselected != 1) {
				cout << endl << endl
					<< setw(margin) << "" << "Enter [1] to rotate piece" << index << endl
					<< setw(margin) << "" << "Enter [2] to place piece" << index << endl
					<< setw(margin) << "" << "Enter [3] to unselect piece" << index << endl
					<< setw(margin) << "" << "Option (1-3): ";
				cin >> option;
				if (cin.fail()) { // check whether last input was failed
					cin.clear(); // Reset the input error status to no error
					cin.ignore(255, '\n'); // ignore maximum of 255 characters,
					 // or reached end of line.
				}


				switch (option) {
				case 1:
					char direction;
					while (rotated != 1) {
						cout << endl << "Enter c for clockwise, a for anticlockwise:, q to cancel ";
						cin >> direction;
						if (puzzle[selectedPiece].rotate(direction) != 1) {
							rotated = 1;
							round++;
							gameBoard(puzzle, page);
						}
					}
					rotated = 0;
					break;

				case 2:
					char column; int row;
					while (placed != 1) {
						cout << endl << "Enter q to cancel, or Enter the column (A-E) to place piece" << index << " : ";
						cin >> column;
						if (column == 'Q' || column == 'q') break;
						cout << "Enter the row to place piece " << index << " : ";
						cin >> row;
						if (cin.fail()) { // check whether last input was failed
							cin.clear(); // Reset the input error status to no error
							cin.ignore(255, '\n'); // ignore maximum of 255 characters,
							 // or reached end of line.
						}

						round++;

						if (((int)column > 64 && (int)column < 70) && (row > 0 && row < 6)) { // bug label 5
							int nowcolumn = column;
							bool checkN = 1, checkS = 1, checkE = 1, checkW = 1;

							for (int pieceID = 0; pieceID < totalPiece && pieceID != selectedPiece; pieceID++) {
								int checkColumn = puzzle[pieceID].getColumn();

								//Check Upper pieces
								if (checkColumn == nowcolumn && puzzle[pieceID].getRow() == (row - 1)
									&& puzzle[pieceID].getDigit('S') != puzzle[selectedPiece].getDigit('N'))
								checkN = 0;
								
								//Check Below pieces
								if (checkColumn == nowcolumn && puzzle[pieceID].getRow() == (row + 1)
									&& puzzle[pieceID].getDigit('N') != puzzle[selectedPiece].getDigit('S'))
									checkS = 0;

								//Check Left pieces
								if (checkColumn == (nowcolumn - 1) && puzzle[pieceID].getRow() == row
									&& puzzle[pieceID].getDigit('E') != puzzle[selectedPiece].getDigit('W'))
									checkW = 0;

								//Check Right pieces
								if (checkColumn == (nowcolumn + 1) && puzzle[pieceID].getRow() == row
									&& puzzle[pieceID].getDigit('W') != puzzle[selectedPiece].getDigit('E'))
									checkE = 0;
							}

							if (checkN == 1 && checkS == 1 && checkE == 1 && checkW == 1) {
								placed = 1;
								puzzle[selectedPiece].setLocation(column, row, 1);
								unselected = 1;
							}
							else errorMsg("The touching side is not the same"); // bug label 1 
						}
						else errorMsg("Please Enter column from A to E in capital and row from 1 to 5.");
					}
					gameBoard(puzzle, page);
					break;

				case 3:
					unselected = 1;
					gameBoard(puzzle, page);
					break;
				default: errorMsg("Please enter a number from 1 to 3");
				}
			}
		}
		//Interact with the selected piece which is in the not-yet-placecd list
		else if (mode == 1) { // bug label 3
			bool rotated = 0;
			char direction;
			while (rotated != 1) {
				cout << endl << "Enter c for clockwise, a for anticlockwise:, q to cancel ";
				cin >> direction;
				if (puzzle[selectedPiece].rotate(direction) != 1) {
					rotated = 1;
					gameBoard(puzzle, page);
				}
			}
		}
		else break;
	}

	//Game Ends
	if (win == 1) {
		countWin += 1;
		newPage();
		cout << setw(margin * 2 - 13) << "" << "Congratulations! You win!" << endl
			<< setw(margin) << "" << "You took " << round << "round to finish the puzzle!" << endl;
		if (round < countStep || countPlay == 1) countStep = round;
	}
	else {
		countLose += 1;
		cout << setw(margin * 2 - 13) << "" << "You lose." << endl;
	}

	cout << setw(margin - 5) << "" << "You can play again and maybe try different mode!" << endl
		<< setw(margin * 2 - 13) << "" << "Here is the solution: " << endl;
	cout << endl << endl;

	page = 1;
	int temp = mode;
	mode = 3;
	gameBoard(solution, page);
	mode = temp; margin = 20;
	cout << endl << endl << endl << setw(0) << "";

	char save = 't';

	while (save != 'y' && save != 'Y' && save != 'n' && save != 'N') {
		cout << "Save this puzzle? y for yes, n for no: ";
		cin >> save;

		if (save == 'y' || save == 'Y') {
			savedPuzzle = 1;
			for (int pieceID = 0; pieceID < totalPiece; pieceID++) {
				puzzle1[pieceID].setPiece(puzzle[pieceID].getLetter(), puzzle[pieceID].getDigit('N'), puzzle[pieceID].getDigit('S'), puzzle[pieceID].getDigit('E'), puzzle[pieceID].getDigit('W'));
				puzzle1[pieceID].setLocation(puzzle[pieceID].getColumn(), puzzle[pieceID].getRow(), puzzle[pieceID].getPlaced());
				sol_puzzle1[pieceID].setPiece(solution[pieceID].getLetter(), solution[pieceID].getDigit('N'), solution[pieceID].getDigit('S'), solution[pieceID].getDigit('E'), solution[pieceID].getDigit('W'));
				sol_puzzle1[pieceID].setLocation(solution[pieceID].getColumn(), solution[pieceID].getRow(), solution[pieceID].getPlaced());
			}
		}
	}
	cout << endl << endl << endl << setw(0) << "" << "Return to main menu..." << endl;
	anyKey();
	menu();
	return;
}

void rules() {
	newPage();
	divder();
	cout << setw(margin * 2 - 4) << "" << "Rules:" << endl << endl;
	cout << setw(margin - 9) << "" << "To win, place " << "\033[0;31m" << "all" << "\033[0;37m" << " the puzzle piece into the gameboard." << endl
		<< setw(margin - 11) << "" << "Make sure all the touching digit of pieces are same. E.g." << endl << endl
		<< setw(margin + 9) << "" << "piecesA" << "     " << "piecesB" << endl
		<< setw(margin + 9) << "" << "   0   " << "     " << "   1   " << endl
		<< setw(margin + 9) << "" << "  2A" << "\033[0;31m" << "3  " << "\033[0;37m" << "     " << "\033[0;31m" << "  3" << "\033[0;37m" << "B4  " << endl
		<< setw(margin + 9) << "" << "   5   " << "     " << "   6   " << endl << endl;
	cout << setw(margin - 11) << "" << "Remember you can always quit the game by entering Q." << endl
		<< setw(margin - 11) << "" << "Make sure all the pieces are placed from column A and row 1" << endl
		<< setw(margin - 11) << "" << "Please rotate the pieces upside down if you cannot win" << endl;

	cout << endl << endl << endl
		<< setw(margin * 2 - 4) << "" << "Enjoy!" << endl << endl;

	divder();
	cout << endl << endl << endl << endl << endl << endl << endl << endl;

	anyKey();
	return;
}


//Printing Game Board
void gameBoard(Piece puzzle[], int& page) {

	if (mode != 3) newPage();
	else margin = 20;

	//Header
	if (mode != 3) {
		cout << left << setw(margin - 10) << "Gamemode : " << right << setw(margin - 10) << ""
			<< setw(margin - 5) << "A  B  C  D  E";
	}
	else cout << setw(margin + 16) << "A  B  C  D  E";

	if (mode == 0) cout << setw(margin + 17) << "+-----^^^------+"; //Not-Yet-Placed box

	cout << endl;

	if (mode != 3) {
		cout << left << setw(margin - 10) << ((mode == 0) ? " Default" : " Easy Mode") << right << setw(margin - 10) << ""
			<< " +---------------+";
	}
	else cout << setw(margin + 18) << " +---------------+";


	if (mode == 0) cout << setw(margin + 15) << "|Not-Yet-Placed|"; //Not-Yet-Placed box

	cout << endl;

	//Print from Row 1 of the game board to the last row (Row 14)
	for (int r = 0, row = 1; row <= 5 && r < 15; r++) {             // bug label 2 
		//r is the row for console, row is row of gameboard

		// For the row without row number index 
		if (r % 3 == 0 || r % 3 == 2) {
			cout << setw(margin) << "" << " |";

			for (int column = 65; column <= 69; column++) {
				bool noMatchedPieces = 1;

				//Searching for the matched pieces
				for (int pieceID = 0; pieceID < totalPiece; pieceID++) {
					HANDLE console_color;
					console_color = GetStdHandle(STD_OUTPUT_HANDLE); // Color of the console
					if ((puzzle[pieceID].getPlaced() == 1)
						&& row == puzzle[pieceID].getRow() && column == ((int)puzzle[pieceID].getColumn())) {
						if (r % 3 == 0) {
							cout << " ";
							SetConsoleTextAttribute(console_color, 8);
							cout << puzzle[pieceID].getDigit('N') << " ";
							cout << "\033[0;37m";
						}
						if (r % 3 == 2) {
							cout << " ";
							SetConsoleTextAttribute(console_color, 8);
							cout << puzzle[pieceID].getDigit('S') << " ";
							cout << "\033[0;37m";
						}
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
						SetConsoleTextAttribute(console_color, 8);
						cout << puzzle[pieceID].getDigit('W');
						cout << "\033[0;37m";
						cout << puzzle[pieceID].getLetter();
						SetConsoleTextAttribute(console_color, 8);
						cout << puzzle[pieceID].getDigit('E');
						cout << "\033[0;37m";

						noMatchedPieces = 0;
					}
				}
				if (noMatchedPieces == 1) cout << "   ";
			}
		}

		cout << "\033[0;37m" << "|";

		if (mode != 0) {
			if (r % 3 == 2) row++; //After printed digitS, switch to next row of gameboard
			cout << endl; continue;
		} // If mode is "Easy mode", do not print the pieces List

//Not-Yet-Placed Pieces List
		HANDLE console_color;
		console_color = GetStdHandle(STD_OUTPUT_HANDLE); // Color of the console

		int placedRow = 0, l = (row - 1) + searchIndex(page);
		bool noMatchedPieces = 0;
		if (l >= 81 && l < 86) l += 1;

		for (int pieceID = 0; pieceID < totalPiece && placedRow == 0; pieceID++) {
			if (puzzle[pieceID].getLetter() == l && puzzle[pieceID].getPlaced() == 0) {
				noMatchedPieces = 1;
				if (r % 3 == 0) {
					cout << setw(margin) << "|" << setw(6) << " ";
					SetConsoleTextAttribute(console_color, 4);
					cout << puzzle[pieceID].getDigit('N') << "\033[0;37m" << " " << setw(7) << " |";
				}
				if (r % 3 == 1) {
					cout << setw(margin) << "|" << setw(6);
					SetConsoleTextAttribute(console_color, 4);
					cout << puzzle[pieceID].getDigit('W') << (char)l << puzzle[pieceID].getDigit('E') << "\033[0;37m" << setw(7) << " |";
				}
				if (r % 3 == 2) {
					cout << setw(margin) << "|" << setw(6) << " ";
					SetConsoleTextAttribute(console_color, 4);
					cout << puzzle[pieceID].getDigit('S') << "\033[0;37m" << " " << setw(7) << " |";
				}
				placedRow = 1;
				cout << "\033[0;37m";
			}
		}
		if (noMatchedPieces == 0)
			cout << setw(margin) << "|" << setw(6) << "   " << setw(9) << " |";

		cout << endl;
		if (r % 3 == 2) row++; //After printed digitS, switch to next row of gameboard

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
	newPage();

	int margin = 2;
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE); // Color of the console

	int option, pieceNum, rangeNum1, rangeNum2;
	cout << setw(margin) << "" << "*** Settings Menu ***" << endl
		<< setw(margin) << "" << "[1] Change Number of puzzle piece \n\t";
	SetConsoleTextAttribute(console_color, 8);
	cout << "-> Current: " << totalPiece << "\033[0;37m" << endl
		<< setw(margin) << "" << "[2] Change Range of random number \n\t";
	SetConsoleTextAttribute(console_color, 8);
	cout << "-> Current: " << digitFloor << " - " << digitCeiling << "\033[0;37m" << endl
		<< setw(margin) << "" << "[3] Return to Main Menu" << endl
		<< setw(margin) << "" << "***************************" << endl << endl
		<< setw(margin) << "" << "Option (1-3): ";
	cin >> option;
	if (cin.fail()) { // check whether last input was failed
		cin.clear(); // Reset the input error status to no error
		cin.ignore(255, '\n'); // ignore maximum of 255 characters,
		 // or reached end of line.
	}


	switch (option) {
	case 1:
		do {
			cout << "Input a new value for Number of puzzle piece (from 1-25): ";
			cin >> pieceNum;
			if (cin.fail()) { // check whether last input was failed
				cin.clear(); // Reset the input error status to no error
				cin.ignore(255, '\n'); // ignore maximum of 255 characters,
				 // or reached end of line.
			}

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
			if (cin.fail()) { // check whether last input was failed
				cin.clear(); // Reset the input error status to no error
				cin.ignore(255, '\n'); // ignore maximum of 255 characters,
				 // or reached end of line.
			}
			cout << "to ";
			cin >> rangeNum2;
			if (cin.fail()) { // check whether last input was failed
				cin.clear(); // Reset the input error status to no error
				cin.ignore(255, '\n'); // ignore maximum of 255 characters,
				 // or reached end of line.
			}

			//Checking for Valid input
			if (rangeNum1 >= 0 && rangeNum2 >= rangeNum1 && rangeNum2 <= 9) {
				digitFloor = rangeNum1;
				digitCeiling = rangeNum2;
				menu();
			}
			else
				errorMsg("Please input a number from 0 to 9 for each number");

		} while (rangeNum1 < 0 || rangeNum2 > 9 || rangeNum2 < rangeNum1);
		break;

	case 3: anyKey(); menu(); break;

	default:
		errorMsg("Please input a number from 1 to 3.");
		config();
	}
}

//Additional Feature
void feature() {
	newPage();

	int option, margin = 2;
	cout << setw(margin) << "" << "*** Menu ***\n"
		<< setw(margin) << "" << "[1] Statistic\n"
		<< setw(margin) << "" << "[2] Gamemode\n"
		<< setw(margin) << "" << "[3] Play Saved Puzzles\n"
		<< setw(margin) << "" << "[4] Return to main menu\n"
		<< setw(margin) << "" << "****************\n"
		<< "\n"
		<< "Option (1-4): ";
	cin >> option;
	if (cin.fail()) { // check whether last input was failed
		cin.clear(); // Reset the input error status to no error
		cin.ignore(255, '\n'); // ignore maximum of 255 characters,
		 // or reached end of line.
	}

	divder();

	switch (option) {

	default:
		errorMsg("Please input a number from 1 to 3");
		feature();
		break;

	case 4:
		anyKey();
		menu();
		break;

	case 1:
		newPage();
		cout << setw(margin) << "" << "Puzzles played: " << countPlay << endl
			<< setw(margin) << "" << "Puzzles wined: " << countWin << endl
			<< setw(margin) << "" << "Puzzles losed: " << countLose << endl
			<< setw(margin) << "" << "Minimum Step: " << countLose << endl << endl;

		anyKey();
		menu();
		break;
	case 2: newPage();
		char option1;

		cout << setw(margin) << "" << "Current Gamemode: Default" << endl
			<< setw(margin) << "" << "Type y to change to 'Easy' Mode, type anything else to cancel: ";
		cin >> option1;

		if (option1 == 'y' || option1 == 'Y') 
			mode = 1; 

		menu();
		break;

	case 3:
		newPage();
		int option2;

		if (savedPuzzle == 0) {
			cout << setw(margin) << "" << "You haven't saved any puzzles yet. Play a game first!" << endl;
			anyKey();
			menu();
			break;
		}

		cout << setw(margin) << "" << "*** Menu ***\n"
			<< setw(margin) << "" << "[1] Show the saved puzzle\n"
			<< setw(margin) << "" << "[2] Show the solution of the puzzle\n"
			<< setw(margin) << "" << "[3] Play the puzzle\n"
			<< setw(margin) << "" << "****************\n"
			<< "\n"
			<< "Option (1-3): ";
		cin >> option2;
		if (cin.fail()) { // check whether last input was failed
			cin.clear(); // Reset the input error status to no error
			cin.ignore(255, '\n'); // ignore maximum of 255 characters,
			 // or reached end of line.
		}


		int temp = mode, page = 0;

		switch (option2) {
		case 1:
			newPage();
			mode = 3;

			gameBoard(puzzle1, page);
			mode = temp;
			cout << endl << endl << endl << setw(0) << "";
			anyKey(); feature();
			break;

		case 2:
			newPage();
			mode = 3;
			gameBoard(sol_puzzle1, page);
			mode = temp;
			cout << endl << endl << endl << setw(0) << "";
			anyKey(); feature();
			break;

		case 3:
			playSavedPuzzle = 1; //bug label
			game();
			break;

		default:
			errorMsg("Please input a number from 1 to 3");
			anyKey();
			break;
		}
	}

}

//Credit
void credit() {
	newPage();

	int margin = 2;
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
	divder();
	cout << setw(margin * 2 + 4) << "***Warning***" << endl << endl
		<< setw(margin - 12) << "" << "Please noted that your data will be lost when closing the game.";
	cout << endl << endl << endl;

	divder();
	cout << endl << endl << endl << endl << endl << endl << endl << endl;

	char ch;
	cout << "Close the game?" << endl
		<< "Enter y for yes, n for no. ";
	cin >> ch;

	if (ch == 'n' || ch == 'N') {
		cout << endl << endl << endl;
		cout << "Game continued!" << endl << "Returning to Main menu...";
		this_thread::sleep_for(chrono::milliseconds(3000));
		menu();
	}
	else if (ch == 'y' || ch == 'Y') exit(0); //Program terminates
	else {
		divder();
		errorMsg("Please enter y for yes, n for no.");
		anyKey();
		exits();
	}
	return;
}
