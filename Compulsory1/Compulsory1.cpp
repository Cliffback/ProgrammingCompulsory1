#include <iostream>

char Board[3][3]
{
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'}
};
int input;
int column;
int row;
char turn = 'X';



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

	if (turn == 'X' && Board[row][column] != 'X' && Board[row][column] != 'O')
	{
		Board[row][column] = 'X';
		turn = 'O';
	}
	else if (turn == 'O' && Board[row][column] != 'X' && Board[row][column] != 'O')
	{
		Board[row][column] = 'C';
		turn = 'X';
	}
	else
	{
		std::cout << "Box is already taken. Choose another!\n\n";
		PlayerTurn();
	}
	DisplayBoard();
}

bool gamover()
{
	for (int i = 0; i < 3; i++)
	{


	}
}

int main()
{
	while ()
	{
		std::cout << "\n\n\t\t\tTICK TACK TOE";
	DisplayBoard();
	PlayerTurn();
	}


	return 0;
}