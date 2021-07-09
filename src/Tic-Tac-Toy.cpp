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
	//The isAvailable flag is set to true when the
	//player selects a location in the board that
	//is availabel.
	bool isAvailable = false;
	
	int row;
	int col;
	
	cout << "Player " << symbol << "s' turn.\n";
	cout << "Enter a row and column to place an " << symbol << ".\n";
	
	//Get and validate the location.
	while (!isAvailable)
	{
	     //Get the row.
	     cout << "Row: "; cin >> row;
		
	     //Validate the row.
	     while (row < 1 || row > ROWS)
	     {
		  cout << "Invalid Row!\n";
		  cout << "Row: "; cin >> row;
	     }
             
	     //Get the column.
	     cout << "Column: "; cin >> col;
		
	     //Validate the column.
	     while (col < 1 || col > COLS)
	     {
		  cout << "Invalid Column!\n";
		  cout << "Column: "; cin >> col;
	     }
	     //Determine whether the selected
	     //Call is available.
	     if(board[row - 1][col - 1] == '*')
		isAvailabel = true;
	     else
                cout << "That location is not available. " << "Select another location.\n";
		
	}
	
	//place the player's symbol on thw board
	//at the selected location
	board[row - 1][col -1] = symbol;
}

//function 3
bool gameOver(char board[][COLS])
{
       //if either player has already won, game over.
       if(playerWins(board , 'X') || playerWins(board , 'O'))
	    return true;
       else if (playerCanWin(board , 'X') || playerCanWin(board , 'O'))
	    return false;
       else
	    return true;
		
}		
}
