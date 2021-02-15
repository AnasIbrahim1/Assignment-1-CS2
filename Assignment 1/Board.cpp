#include "Board.h"
// by Anas A. Ibrahim, commenting and everything

Board::Board() {
	boardSize = 0;
}

Board::Board(const int& c1r, const int& c1c, const int& c2r, const int& c2c, const int& size) {
	boardSize = size;
	// array initialization
	boardarr = new char* [boardSize];
	for (int i = 0; i < boardSize; i++)
		*(boardarr + i) = new char[boardSize];
	// initializing the cat's positions
	*(*(boardarr + c1r) + c1c) = 'C'; 
	*(*(boardarr + c2r) + c2c) = 'C';
	
	*(*(boardarr + boardSize / 2) + boardSize - 1) = 'B'; 
	// This	assumes that the bridge is at the half of the board,
	// if the size is even, then the bridge is at (size/2,size)
	// if the size is odd, then the bridge is at ((size+1)/2,size)
	// e.g. 9*9 board, bridge is at (5,9), 10*10, bridge is at (5,10)
	// the computed for examples is (4,8) and (4,9) because the array is zero-indexed
}

Board::~Board() {
	for (int i = 0; i < boardSize; i++) {
		*(boardarr + i) = NULL;
		delete[] * (boardarr + i);
	}
	boardarr = NULL;
	delete[] boardarr;
}

char Board::getBoardCell(const int& r, const int& c) {
	return *(*(boardarr + r) + c);
}

void Board::setBoardSize(const int& s) {
	boardSize = s;
}

int Board::getBoardSize() {
	return boardSize;
}

void inputCoordinates(int& x, int& y, const int& size) { // same function as in main.cpp
	while (true) {
		cout << "Enter the coordinates of the cat (separated by spaces): ";
		cin >> x >> y;
		x--; y--; // decrement because the array is zero-indexed
		if (x >= size || y >= size || x < 0 || y < 0) // validate the user input
			cout << "Your coordinates are out of bounds!" << endl;
		else
			break; // break if it's valid, otherwise repeat
	}
}

void Board::initializeAnimals(const int& size) {
	cout << "Enter the number of the animals: ";
	cin >> numAnimals; // Assuming that this input is valid
	Animals = new Animal[numAnimals];
	// we will input the coordinates in x1 and y1 since they are already given
	// to the board
	cout << "You're now going to enter the names and the coordinates of"
		 << " the animals.\n\n";
	int x1, y1;
	string tmpo;
	for (int i = 0; i < numAnimals; i++) {
		cout << "Enter the name of the animal: ";
		cin >> tmpo;
		cout << "Enter the coordinates of the animal (separated by spaces): ";
		inputCoordinates(x1, y1, boardSize);
		cout << endl;
		x1--; y1--; // decrement because the array is zero-indexed
		Animal tmp(x1, y1); // a temporary variable takes x1 and y1 as its coordinates
		*(Animals + i) = tmp; // and then initialize the ith element in the 
		(*(Animals + i)).setName(tmpo); // and then set the animal name
	}
}

int Board::getNumAnimals() {
	return numAnimals;
}
Animal* Board::getAnimals() {
	return Animals;
}