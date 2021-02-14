#pragma once
#include <iostream>
using namespace std;

class Animal
{
private:
	int rowPosition;
	int columnPosition;
	string name;
	// size of the board, set at the beginning of the application
public:
	Animal();
	Animal(const int&, const int&);
	bool move(const char&, const int&);
	int getRow();
	int getColumn();
	void setName(const string&);
	string getName();
	void setSize(const int&);	
};

