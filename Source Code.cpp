#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void welcome();
void menu();
void game();
void GenerateNSEW(int &, int &, int &, int &);
void config();
void feature();
void credit();
void exits();

int totalPiece = 15, digitFloor = 0, digitCeiling = 5;

class Piece{
	public:
		//Constructor function
		Piece(){}
		
		//Set function
		void setPiece(char l, int N, int S, int E, int W){
			letter = l;
			digitN = N; digitS = S; digitE = E; digitW = W;
			column = '\0'; row = 0;
			placed = 0;
		}
		
		void setLetter(char l){
		    letter = l;
		}

        //Get function
		int getDigit(char const NSEW){
			switch(NSEW){
				case 'N': return digitN; break;
				case 'S': return digitS; break;
				case 'E': return digitE; break;
				case 'W': return digitW; break;
				default: cout << "Error";				
			}
			return EXIT_SUCCESS;
		}
		
		char getLetter(){
		    return letter;
		}

	private:
		char detail[2][2];

		//Piece Appearance
		char letter; // from A-Z
		int digitN,digitS,digitE,digitW; // from 0-9
	
		//Location 
		char column;
		int row;
		bool placed;
};


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
  // Generate the solution array with puzzles pieces
  Piece solution[totalPiece] = {};
  
  for(int pieceID=0; pieceID < totalPiece; pieceID++){
    int l = pieceID + 65, N = 0, S = 0, E = 0, W = 0;
    
    //Generate the digitNSEW for piece1
	if(pieceID == 0)
		GenerateNSEW(N, S, E, W);
    //Generate all left pieces except piece1 
	else if(pieceID % 5 != 0){ 
				GenerateNSEW(N, S, E, W); 
				W = solution[pieceID-1].getDigit('E');		
		}
	else{ 
	    //Generate all other pieces
				GenerateNSEW(N, S, E, W); 
				N = solution[pieceID-5].getDigit('S');
				E = solution[pieceID-1].getDigit('W');
		}
    	
	solution[pieceID].setPiece(l, N, S, E, W);
	/*
    //For Debuging
	cout << l << " " << N << " " << S << " " << E << " " << W << " done " <<  pieceID << endl;
	*/
    }
    
    //Transforming the pieces
    Piece puzzle[totalPiece] = {};
  
    //Initialized letter, digit
    for(int pieceID=0;  pieceID < totalPiece; pieceID++){
        
        puzzle[pieceID].setPiece(
            65 + rand() % totalPiece, 
            solution[pieceID].getDigit('N') ,
            solution[pieceID].getDigit('S') ,
            solution[pieceID].getDigit('E') ,
            solution[pieceID].getDigit('W') 
            );
        /*
        //For Debuging
        cout << puzzle[pieceID].getLetter() << " ";
        */
    }    
    
    cout << endl;
    
    //Transforming the letter
    
    for(int pieceID=1; pieceID < totalPiece;){
        bool change = 0;
        
        for(int i = 0; i < (totalPiece-1); i++){
            if(puzzle[pieceID].getLetter() == puzzle[i].getLetter() && i!= pieceID){
                change = 1;
            }
        }
        
        if(change == 0)
            pieceID++;
        else{
		puzzle[pieceID].setLetter(65 + rand() % totalPiece);
		solution[pieceID].setLetter(puzzle[pieceID].getLetter());   //Save puzzle[] to solution[]
	}
    }
    
    /*
    //For Debuging
     for(int pieceID=0;  pieceID < totalPiece; pieceID++)
        cout << endl << puzzle[pieceID].getLetter() << " ";
    */

    return;
}

//
void GenerateNSEW(int & N, int & S, int & E, int & W){
	for(int i = 0, randNum; i < 4; i++){
	    if((digitCeiling - digitFloor) == 0)
	        randNum = digitFloor;
	    else 
	        randNum = digitFloor + rand() % (digitCeiling - digitFloor + 1);
	    
	    // Assign the number generated randomly to digitNSEW 
	    switch(i){
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
void config(){
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
		do{
			cout << "Input a new value for Number of puzzle piece (from 1-25): ";
			cin >> pieceNum;

			//Checking for Valid input
			if(pieceNum >= 1 && pieceNum <= 25)
				totalPiece = pieceNum;
			else
				cout << "Please input a number from 1 to 25";
		}while(pieceNum < 1 || pieceNum > 25);
		
		break;
	case 2: 
		do{
			cout << "Input a new value for Range of random number (from 0-9):  " << endl
				<< "from";
			cin >> rangeNum1;
			cout << "to";
			cin >> 	rangeNum2;

			//Checking for Valid input
			if(rangeNum1 >= 0 && rangeNum2 >= rangeNum1 && rangeNum2 <= 9){
				digitFloor = rangeNum1;
				digitCeiling = rangeNum2;
			}
			else
				cout << "Please input a number from 0 to 9 for each number";
		}while(rangeNum1 < 0 || pieceNum > 9);

		break;

	case 3: main(); break;

	default: cout << "Please input a number from 1 to 5." << endl << endl;
            config();
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
