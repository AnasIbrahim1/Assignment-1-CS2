#include <iostream>
#include <fstream>
#include <string>
#include "Animal.h"
#include "Board.h"
using namespace std;
// by Anas A. Ibrahim, commenting and everything

void inputSize(int&);
void inputCoordinates(int&, int&, const int&);
int main() {
	int size; 
	inputSize(size);
	int x1, y1, x2, y2; // (x1,y1) are the coordinates of the first cat
	// (x2,y2) are the coordinates of the second cat
	cout << "You're going to input the coordinates of the two cats now\n\n";
	inputCoordinates(x1, y1, size);
	inputCoordinates(x2, y2, size);
	cout << endl;
	Board Bee(x1, y1, x2, y2, size);
	Bee.initializeAnimals(size);
	int numAnimals = Bee.getNumAnimals();
	Animal* arr = Bee.getAnimals(); 
	// giving it the same reference because it doesn't matter much
	ifstream st;
	st.open("Animals.txt");
	string x;
	bool flag; // flag for detection of something after the loop
	// assuming that the number of animals is the same as the number of strings
	int len, tmpX, tmpY;
	for (int i = 0; i < numAnimals; i++) {
		st >> x;
		// go through the string, and move the animal according to the string
		len = x.length();
		cout << (*(arr + i)).getName() << ": ";
		flag = true;
		for (int j = 0; j < len; j++) {
			if (!((*(arr + i)).move(x[j], size))) {
				cout << "Drowned outside the island." << endl;
				flag = false;
				break;
			}
			// storing the coordinates in temporary variables so that we can check
			tmpX = (*(arr + i)).getRow(); 
			tmpY = (*(arr + i)).getColumn(); 
			if (Bee.getBoardCell(tmpX, tmpY) == 'C') {
				cout << "Eaten by the cat." << endl;
				flag = false;
				break;
			}
			if (Bee.getBoardCell(tmpX, tmpY) == 'B') {
				cout << "Escaped through the bridge." << endl;
				flag = false;
				break;
			}
		}
		if (flag) { // if it breaks, then the flag is false; if it does not break
					// then it didn't encounter any problem while moving, and so ...
			cout << "Starved ... Stuck inside the board." << endl;
		}
	}
	st.close();
}

void inputSize(int& size) {
	while (true) {
		cout << "Enter the board size (between 9 and 12): ";
		cin >> size;
		if (size < 9 || size > 12) // validate the user input
			cout << "Please enter a valid size!" << endl;
		else
			break; // break if it's valid, otherwise repeat
	}
}

void inputCoordinates(int& x, int& y, const int& size) {
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