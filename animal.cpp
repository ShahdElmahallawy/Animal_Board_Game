#include"animal.h"

animal::animal()
{
	rowPosition = 0;
	columnPosition = 0;
	name = "";
}
 animal::animal(board& b, int x, int y, string n)
{
	 name = n;
	 while (b.getBoardCell(x, y) != '-')
	 {
		 cout << "Enter another row number" << endl;
		 cin >> x;
		 cout << "Enter another column number" << endl;
		 cin >> y;
	 }
	rowPosition = x ;
	columnPosition = y;
}
 animal::animal(const animal& a2)
 {
	 rowPosition = a2.rowPosition;
	 columnPosition = a2.columnPosition;
	 name = a2.name;
 }
bool animal::check(int boardSize)
{
	if (rowPosition == -1 || columnPosition == -1 || rowPosition == boardSize || columnPosition == boardSize)
		return false;
	else
		return true;
}
bool animal::move(char c, int size)
{
	if (c == 'L')
		columnPosition = columnPosition - 1;
	else if (c == 'R')
		columnPosition = columnPosition + 1;
	else if (c == 'D')
		rowPosition = rowPosition + 1;
	else if (c == 'U')
		rowPosition = rowPosition - 1;

	return check(size);
}

int animal::getRow()
{
	return rowPosition;
}
int animal::getColumn()
{
	return columnPosition;
}
string animal::getName()
{
	return name;
}
animal::~animal()
{
}