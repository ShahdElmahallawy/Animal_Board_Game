#include"animal.h"
#include"board.h"
#include <string>
#include<fstream>

void main()
{
	int size;
	int c_cat1, r_cat1, c_cat2, r_cat2;
	int n_animals;
	//setiing the size of the board
	cout << " Please, enter a size of the board from 9 to 12" << endl;
	cin >> size;
	//setting the position of the two cats
	cout << "Enter the row number for the first cat" << endl;
	cin >> r_cat1;
	cout << "Enter the column number for the first cat" << endl;
	cin >> c_cat1;
	cout << "Enter the row number for the second cat" << endl;
	cin >> r_cat2;
	cout << "Enter the column number for the second cat" << endl;
	cin >> c_cat2;
	board gameBoard(size, c_cat1, r_cat1, c_cat2, r_cat2);
	//setting the animals
	cout << "Enter the number of animals you want to add to the farm" << endl;
	cin >> n_animals;
	animal* animalArray = new animal[n_animals];
	string name;
	int x, y;
	for (int i = 0; i < n_animals; i++)
	{
		cout << "Enter the name of the animal number" << i + 1 << endl ;
		cin >> name;
		cout << "Enter the number of row where you want put " << name << endl;
		cin >> x;
		cout << "Enter the number of column where you want put " << name << endl;
		cin >> y;
		animalArray[i] = animal(gameBoard, x, y, name);
	}
	//moving animals
	ifstream streamReader;
	string move;
	streamReader.open("movements.txt");
	for (int i = 0; i < n_animals; i++)
	{
		getline(streamReader, move);
		bool flag = true;
		for (int m = 0; m < 4; m++) {
			if (animalArray[i].move(move.at(m), gameBoard.getBoardSize()) == false)
			{
				cout  << animalArray[i].getName() << " Drowned outside the island" << endl;
				flag = false;
				break;
			}
			if (gameBoard.getBoardCell(animalArray[i].getRow(), animalArray[i].getColumn()) == 'C')
			{
				cout << animalArray[i].getName() << " Eaten by the cat." << endl;
				flag = false;
				break;
			}
			else if (gameBoard.getBoardCell(animalArray[i].getRow(), animalArray[i].getColumn()) == 'B')
			{
				cout  << animalArray[i].getName() << " Escaped through the bridge." << endl;
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << animalArray[i].getName() << " Starved ...  Stuck inside the board" << endl;
		}
	}
	streamReader.close();
}