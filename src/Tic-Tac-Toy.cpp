//Copyleft Ammo-Srush
//Open Source 
//Tic-Tac-Toy
#include <iostream>
using namespace std;

//Lets Get Started

const int ROW  = 3;
const int COLS = 3;

// Functions prototypes
void displayBoard(char [][COLS]);
void playerTurn(char [][COLS] , char);
bool gameOver(char [][COLS]);
bool playWins(char [][COLS] , char);
bool playCanWin(char [][COLS] , char);
void displayWinner(char [][COLS]);

int main ()
{
	char gameBoard[ROW][COLS]=
	                         {{'*','*','*'},
	                          {'*','*','*'}};

	do
	{ 
		//Call displayBoard
		displayBoard(gameBoard);

		//Call playerTurn
		playerTurn(gameBoard , 'X');

		//Call displayBoard again
		displayBoard(gameBoard);

		//If the the game is not over, let
		//player 2 have a turn.
		if(!gameOver(gameBoard))
			playerTurn(gameBoard , 'O');

	}while (!gameOver(gameBoard));

	//Call displayBoard
	displayBoard(gameBoard);

	//Call displayWinner
	displayWinner(gameBoard);

	return 0;
}

//function 1
void displayBoard(char [][COLS])
{
	//Display the column headings.
	cout << "     Columns\n";
	cout << "      1  2  3\n";

	//Display the rows.
	for(int row = 0; row < ROW; row++)
	{
		//Row label
		cout << "Row " << (row+1) << ":  ";

		//Row contents.
		for(int col = 0; col < COLS; col++)
		{
			cout << board[row][col] <<  "  ";
		}
		cout << endl;
	}
}

//function 2
void playerTurn(char board[][COLS] , char symbol)
{
	//project stop.....
}