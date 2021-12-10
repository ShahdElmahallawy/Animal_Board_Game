#pragma once
#include<iostream>
using namespace std;
class board
{
	//attributes 
private:
	int boardSize;
	char** Board;
	int c1c;
	int c1r;
	int c2c;
	int c2r;
public:
	//constructors
	board();
	board(int size, int c_cat1, int r_cat1, int c_cat2, int r_cat2);
	//Getters
	int getBoardSize();
	char getBoardCell(int r, int c);
	~board();
};
