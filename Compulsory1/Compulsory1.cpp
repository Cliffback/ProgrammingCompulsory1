#include <iostream>
#include <conio.h>

// Array for making a board
char Board[3][3]
{
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'}
};

// Declaring variables to be used
int input; // For storing the players choice
int column; // Input shall go into the correct column and correct row
int row;
char turn = 'X';
bool draw = false;

// Function for writing the intro
void Intro()
{
	std::cout << "\n\n\t\t  TICK TACK TOE\n";
	std::cout << "\t\t  for 2 players\n";

}

// Function for displaying the board, using the board array
void DisplayBoard()
{
	std::cout << "\n";
	std::cout << "\t   Player 1 [X]    Player 2 [O]\n\n";
	std::cout << "\t\t     |     |     \n";
	std::cout << "\t\t  " << Board[0][0] << "  |  " << Board[0][1] << "  |  " << Board[0][2] << "\n";
	std::cout << "\t\t_____|_____|_____" << "\n";
	std::cout << "\t\t     |     |     " << "\n";
	std::cout << "\t\t  " << Board[1][0] << "  |  " << Board[1][1] << "  |  " << Board[1][2] << "\n";
	std::cout << "\t\t_____|_____|_____" << "\n";
	std::cout << "\t\t     |     |     " << "\n";
	std::cout << "\t\t  " << Board[2][0] << "  |  " << Board[2][1] << "  |  " << Board[2][2] << "\n";
	std::cout << "\t\t     |     |     " << "\n";
}

// Function for inputing choices
void PlayerTurn()
{
	if (turn == 'X')
	{
		std::cout << "\n\t       Player 1 [X] turn: ";
	}
	else if (turn == 'O')
	{
		std::cout << "\n\t       Player 2 [O] turn: ";
	}


	// For sending the input to the correct row and column
	std::cin >> input;
	switch (input)
	{
	case 1: 
		row = 0;
		column = 0;
		break;

	case 2:
		row = 0;
		column = 1;
		break;

	case 3:
		row = 0;
		column = 2;
		break;

	case 4:
		row = 1;
		column = 0;
		break;

	case 5:
		row = 1;
		column = 1;
		break;

	case 6:
		row = 1;
		column = 2;
		break;

	case 7:
		row = 2;
		column = 0;
		break;

	case 8:
		row = 2;
		column = 1;
		break;

	case 9:
		row = 2;
		column = 2;
		break;

	default:
		std::cout << "Invalid move! Please try again!";
	}

	// Inserting row and column into the corresponding spot on the board. Also checks if it's not already chosen.
	if (turn == 'X' && Board[row][column] != 'X' && Board[row][column] != 'O')
	{
		Board[row][column] = 'X';
		turn = 'O';
	}
	else if (turn == 'O' && Board[row][column] != 'X' && Board[row][column] != 'O')
	{
		Board[row][column] = 'O';
		turn = 'X';
	}
	else
	{
		std::cout << "\n\tBox is already taken. Choose another!\n\n";
		char something = _getch();
		system("CLS");
		Intro();
		DisplayBoard();
		PlayerTurn();
	}
	DisplayBoard();
}

// Checking if either player has won
bool gamover()
{
	// Checks if won by horizontal or vertical 
	for (int i = 0; i < 3; i++)
	{
		if (Board[i][0] == Board[i][1] && Board[i][0] == Board[i][2] || Board[0][i] == Board[1][i] && Board [0][i] == Board[2][i])
		{
			return false;
		}
	}
	// Checks if won by getting either line in a cross
	if (Board[0][0] == Board[1][1] && Board[0][0] == Board[2][2] || Board[0][2] == Board[1][1] && Board[0][2] == Board[2][0])
	{
		return false;
	}

	// Checks if all spots are chosen and returns draw if so
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (Board[i][j] != 'X' && Board[i][j] != 'O')
			{
				return true;
			}
		}
	draw = true;
	return false;
	
}

int main()
{
	// A loop that runs until one of the players has won, or if draw
	while (gamover())
	{
		system("CLS");
		Intro();
		DisplayBoard();
		PlayerTurn();
	}
	if (turn == 'X' && draw == false)
	{
		system("CLS");
		Intro();
		DisplayBoard();
		std::cout << "\n    Congratulations! Player 1 has won the game!\n";
		std::cout << "\n\t       Press a key to exit: ";
		char something = _getch();
	}

	else if (turn == 'O' && draw == false)
	{
		system("CLS");
		Intro();
		DisplayBoard();
		std::cout << "\n    Congratulations! Player 2 has won the game!\n";
		std::cout << "\n\t       Press a key to exit: ";
		char something = _getch();
	}
	else
	{
		system("CLS");
		Intro();
		DisplayBoard();
		std::cout << "\n\t           It's a draw!\n";
		std::cout << "\n\t       Press a key to exit: ";
		char something = _getch();



	}

	return 0;
}