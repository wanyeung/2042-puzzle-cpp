#include <iostream>
#include <iomanip>
using namespace std;

void welcome();
void menu();
void game();
void config();
void feature();
void credit();
void exits();

int totalPiece = 15, digitFloor = 0, digitCeiling = 5;

int main()
{
	
	welcome();
	menu();
	return 0;
}


//Welcome Message
void welcome(){
	cout << "[Welcome Message designed by your group]\n";
	cout << "\n";
	return;
}

//Main Menu
void menu(){
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
	
	switch(option){
		case 1 : cout<< endl << endl; game();  break;
		case 2 : cout<< endl << endl; config(); break;
		case 3 : cout<< endl << endl; feature(); break;
		case 4 : cout<< endl << endl; credit();  break;
		case 5 : cout<< endl << endl; exits();  break;
		default: cout << endl << "Please input a number from 1 to 5." << endl << endl; menu();
	}
	return;
}

//Start the game
void game(){
  
}

//setting
void config(){
	int option, pieceNum, rangeNum1, rangeNum2;
	cout << "\n*** Settings Menu ***" << endl
		<< "[1] Change Number of puzzle piece \tCurrent: " << totalPiece << endl
		<< "[2] Change Range of random number \tCurrent: " << digitFloor << " - " << digitCeiling << endl
		<< "[3] Return to Main Menu" << endl
		<< "***************************" << endl << endl
		<< "Option (1-3): ";
	cin >> option;

	switch (option) {
	case 1: 
		do{
			cout << "Input a new value for Number of puzzle piece (from 1-25): ";
			cin >> pieceNum;

			//Checking for Valid input
			(pieceNum >= 1 && pieceNum <= 25)?
				global::totalPiece = pieceNum:
				cout << "Please input a number from 1 to 25";
		}while(pieceNum < 1 || pieceNum > 25)
		
		break;
	case 2: 
		do{
			cout << "Input a new value for Range of random number (from 0-9):  " << endl
				<< "from";
			cin >> rangeNum1;
			cout << "to";
			cin >> 	rangeNum2;

			//Checking for Valid input
			(rangeNum1 >= 0 && rangeNum2 >= rangeNum1 && rangeNum2 <= 9)?
				(rangeNum1 = global::digitFloor;rangeNum2 = global::digitCeiling;) :
				cout << "Please input a number from 0 to 9 for each number";
		}while(rangeNum1 < 0 || pieceNum > 9)

		break;

	case 3: main(); break;

	default: cout << "Please input a number from 1 to 5." << endl << endl << config() ;
    }
}

//Additional Feature
void feature(){
  
}

//Credit
void credit(){
	cout << setw(20) << "Credits:" << endl
		<< "21043941A HON Sin Hang Aaron 203A" << endl
		<< "21000210A Yeung Miu Wan 203A" << endl
		<< "21132728A Li Yin Cheung 203A" << endl
		<< "21073380A Chu Kiu Tsun 203A" << endl
		<< "21079810A Chu Sik Hin 203A" << endl; 
	return;
}

//Exit
void exits(){
	char ch;
	cout << "Stop the game?" << endl;
	cout << "Press 'y' to confirm, 'n' to cancel."<< endl; 
	cin >> ch;
	if(ch == 'y' || ch == 'Y')
		exit(0);
	if(ch == 'n' || ch == 'N'){
		cout << "game continued!"<< endl;
		menu();
	}
	return;
}
