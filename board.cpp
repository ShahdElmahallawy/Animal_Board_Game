// Implemtation of the class's funtions 
#include"animal.h"
#include"board.h"
board::board()
{
	boardSize = 0;
	c1c = 0;
	c1r = 0;
	c2c = 0;
	c2r = 0;
	Board = new char* [boardSize];
	for (int i = 0; i < boardSize; i++) {
		*(Board + i) = new char[boardSize];
		for(int j = 0; j < boardSize; j++)
			*(*(Board + i) + j) = 0;
	}
}
board::board(int size, int c_cat1, int r_cat1, int c_cat2, int r_cat2)
{
	boardSize = size;
	Board = new char* [boardSize];
	for (int i = 0; i < boardSize; i++)
	{
		*(Board + i) = new char[boardSize];
		for (int j = 0; j < boardSize; j++)
		{
			*(*(Board + i) + j) = '-';
		}
	}

	Board[(boardSize-1)/2][boardSize-1] = 'B';
	while (getBoardCell(r_cat1, c_cat1) != '-')
	{
		cout << "Enter another column number for the first cat" << endl;
		cin >> c_cat1;
		cout << "Enter another row number for the first cat" << endl;
		cin >> r_cat1;
	}
	c1c = c_cat1;
	c1r = r_cat1;
	Board[c1r][c1c] = 'C';
	while (getBoardCell(r_cat2, r_cat2) != '-')
	{
		cout << "Enter another column number for the second cat" << endl;
		cin >> c_cat2;
		cout << "Enter another row number for the second cat" << endl;
		cin >> r_cat2;
	}
	c2c = c_cat2;
	c2r = r_cat2;
	Board[c2r][c2c] = 'C';
}
int board::getBoardSize()
{
	return boardSize;
}
char board::getBoardCell(int r, int c)
{
	return Board[r][c];
}
board::~board()
{
	for (int i = 0; i < boardSize; i++)
	{
		delete[] Board[i];
	}
	delete[] Board;
}


