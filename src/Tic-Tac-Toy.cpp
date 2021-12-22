//in the name of God
#include <iostream>
using namespace std;

#define ROW 3
#define COLS 3
#define TRUE 1
#define FALSE 0

void display_board ( void );
void player_turn ( char player_symbol );
int player_win ( void );

char board[ ROW ][ COLS ] =
        { {'*','*','*',},
          {'*','*','*',},
          {'*','*','*',} };

int main ()
{
	do {

		display_board ();

		player_turn ( 'X' );
		
		display_board ();

		player_turn ( 'O' );

	} while ( TRUE );
}

void display_board ( void )
{
	cout << "\n";
	cout << "        1 2 3 \n";

	for ( int i = 0; i < ROW; i++ ) {

		cout << " ROW " << ( i + 1 ) << ": ";
		for ( int j = 0; j < COLS; j++ )
			cout << board[ i ][ j ] << " ";
		cout << endl;
	}
}

void player_turn ( char player_symbol )
{
	bool check_valid_location = false;
	int row,
	    col;

	cout << " Turn Player " << player_symbol << endl;

	do {

		cout << " Row: "; cin >> row;
		while ( row < 1 || row > 3 ) {
			cout << " Invalid Row Please Try Again: "; cin >> row;
		}

		cout << " Cols: "; cin >> col;
		while ( col < 1 || col > 3 ) {
			cout << " Invalid Col Please Try Again: "; cin >> col;
		}

		if ( board[ row - 1 ][ col - 1 ] == '*' )
			check_valid_location = true;

	} while ( !check_valid_location );

	board[ row - 1 ][ col - 1 ] = player_symbol;

	int result = player_win ();
	if ( result ) {
		
		if ( result == 1 )
			cout << " Player 1 Won " << "( X )";
		if ( result == 2 )
			cout << " Player 2 Won " << "( O )";

		exit( 1 );
	}
}

int player_win ( void )
{

	int x[ 3 ][ 3 ],   // to Record x&o
    	    o[ 3 ][ 3 ];

	for ( int row = 0; row < 3; row++ ) {

		for ( int col = 0; col < 3; col++ ) {

			x[ row ][ col ] = 0, o[ row ][ col ] = 0;

			if ( board[ row ][ col ] == 'X' )
				x[ row ][ col ] = 1;
			if ( board[ row ][ col ] == 'O' )
				o[ row ][ col ] = 1;
		}
	}

	for ( int i = 0; i < 3; i++ ) {

		if ( x[ i ][ 0 ] + x[ i ][ 1 ] + x[ i ][ 2 ] == 3 ||
		     x[ 0 ][ i ] + x[ 1 ][ i ] + x[ 2 ][ i ] == 3 )
			return 1;
		if ( o[ i ][ 0 ] + o[ i ][ 1 ] + o[ i ][ 2 ] == 3 ||
		     o[ 0 ][ i ] + o[ 1 ][ i ] + o[ 2 ][ i ] == 3 )
			return 2;
	}

	if ( x[ 0 ][ 0 ] + x[ 1 ][ 1 ] + x[ 2 ][ 2 ] == 3 || x[ 0 ][ 2 ] + x[ 1 ][ 1 ] + x[ 2 ][ 0 ] == 3 )
		return 1;
	if ( o[ 0 ][ 0 ] + o[ 1 ][ 1 ] + o[ 2 ][ 2 ] == 3 || o[ 0 ][ 2 ] + o[ 1 ][ 1 ] + o[ 2 ][ 0 ] == 3 )
		return 2;
	
	return FALSE;
}
