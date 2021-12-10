#pragma once
#include<iostream>
#include"board.h"
using namespace std;
class animal
{
private:
	//attributes 
	int rowPosition;
	int columnPosition;
	string name;
public:
	//constructors
	animal();
	animal(board&b,int x, int y, string n);
	
	animal(const animal& a2);
	// A function to check the position before modifying it 
	bool check(int size);
	//modifiers
	bool move(char c, int size);
	//Getters
	int getRow();
	int getColumn();
	string getName();

	~animal();
};

