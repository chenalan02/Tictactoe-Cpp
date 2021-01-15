#include "Header.h"

int main()
{
	Board board;

	while (board.winner == ' ')
	{	
		board.playTile();
	}

	board.displayWinner();
	return 0;
}