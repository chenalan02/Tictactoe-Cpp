#include <iostream>

class Board
{
public:

	char winner;
	char player;
	char matrix[3][3] = { {'0','0', '0'}, {'0', '0', '0'}, {'0', '0', '0'} };

	Board()
		:player('X'), winner(' ') {}

	void changePlayer()
	{
		if (player == 'X')
			player = 'O';
		else
			player = 'X';
	}

	char checkWinner()
	{
		int totalTilesPlayed = 0;
		int inARow;
		//check columns
		for (int row = 0; row < 3; row++)
		{
			inARow = 0;
			for (int column = 0; column < 3; column++)
			{
				if (matrix[row][column] == player)
				{
					inARow++;
					totalTilesPlayed++;
				}
				if (inARow == 3)
					return player;
			}
		}
		if (totalTilesPlayed == 9)
			return 'N';
		//check rows
		for (int column = 0; column < 3; column++)
		{
			inARow = 0;
			for (int row = 0; row < 3; row++)
			{
				if (matrix[row][column] == player)
					inARow++;
				if (inARow == 3)
					return player;
			}
		}
		//diagonals
		inARow = 0;
		int column = 0;
		for (int row = 0; row < 3; row++)
		{
			if (matrix[row][column] == player)
				inARow++;
			if (inARow == 3)
				return player;
			column++;
		}
		inARow = 0;
		int row = 2;
		for (int column = 0; column < 3; column++)
		{
			if (matrix[row][column] == player)
				inARow++;
			if (inARow == 3)
				return player;
			row--;
		}
		return ' ';
	}
	void printBoard()
	{
		std::cout << std::endl;
		for (int row = 0; row < 3; row++)
		{
			for (int column = 0; column < 3; column++)
			{
				std::cout << matrix[row][column];
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	bool playTile()
	{
		int row, column;
		printBoard();
		std::cout << player << "'s Turn" << std::endl;

		std::cout << "Row:";
		std::cin >> row;
		std::cout << "Column:";
		std::cin >> column;

		if (matrix[row][column] == '0')
			matrix[row][column] = player;
		else
		{
			std::cout << "This tile is already filled" << std::endl;
			return ' ';
		}
		winner = checkWinner();
		changePlayer();
	}
	void displayWinner()
	{
		if (winner == 'N')
			std::cout << "It's a tie" << std::endl;
		else
			std::cout << winner << " wins!" << std::endl;
	}
};
