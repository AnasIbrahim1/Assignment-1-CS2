#include "Animal.h"
// by Anas A. Ibrahim, commenting and everything

Animal::Animal() {
	rowPosition = 0;
	columnPosition = 0;
}

Animal::Animal(const int& a, const int& b) {
	rowPosition = a;
	columnPosition = b;
}

bool Animal::move(const char& c, const int& maxSize) {
	// we will treat the grid as if the upperleft corner is the origin, 
	// and as you move to the right, the column index increases,
	// and as you move down, the row index increases
	if (c ==  'U') {
		// decrease the row position by 1, (x,y) >> (x-1,y)
		if (rowPosition < 1) // we have x-1<0, then it's out of bounds
			return false;
		rowPosition--;
		return true;
	}
	else if (c == 'D') {
		// increase the row position by 1, (x,y) >> (x+1,y)
		// if we have x+1> n(rows), then it's out of bounds
		if (rowPosition + 1 >= maxSize)
			return false;
		rowPosition++;
		return true;
	}
	else if (c == 'R') {
		// increase the column position by 1, (x,y) >> (x,y+1)
		// if we have y+1>n(columns), then it's out of bounds
		if (columnPosition + 1 >= maxSize)
			return false;
		columnPosition++;
		return true;
	}
	else if (c == 'L') {
		// decrease the column position by 1, (x,y) >> (x,y-1)
		// if we have y-1<0, then it's out of bounds
		if (columnPosition < 1)
			return false;
		columnPosition--;
		return true;
	}
}

int Animal::getRow() {
	return rowPosition;
}

int Animal::getColumn() {
	return columnPosition;
}

void Animal::setName(const string& x) {
	name = x;
}

string Animal::getName() {
	return name;
}