#pragma once
#include <iostream>
#include <string>
#include "Animal.h"
using namespace std;

class Board
{
private:
	int boardSize;
	char** boardarr;
	int numAnimals;
	Animal* Animals;
public:
	Board();
	Board(const int&, const int&, const int&, const int&, const int&);
	~Board();
	char getBoardCell(const int&, const int&);
	void setBoardSize(const int&);
	int getBoardSize();
	void initializeAnimals(const int&);
	int getNumAnimals();
	Animal* getAnimals();
};

