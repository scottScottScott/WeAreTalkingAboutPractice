#include <iostream>
#include <fstream>

#define MAXSTEPS 160000

using namespace std;

char table[10][10];

typedef enum {
	NORTH,
	EAST,
	SOUTH,
	WEST
} Direction;

typedef struct {
	int x;
	int y;
	Direction dir;
} Info;

void makeStep(Info *thingPtr) {
	if(thingPtr->dir == NORTH) {
		if(thingPtr->y == 0 || table[thingPtr->y - 1][thingPtr->x] == '*')
			thingPtr->dir = EAST;
		else
			thingPtr->y -= 1;
	}
	else if(thingPtr->dir == EAST) {
		if(thingPtr->x == 9 || table[thingPtr->y][thingPtr->x + 1] == '*')
			thingPtr->dir = SOUTH;
		else 
			thingPtr->x += 1;
	}
	else if(thingPtr->dir == SOUTH) {
		if(thingPtr->y == 9 || table[thingPtr->y + 1][thingPtr->x] == '*')
			thingPtr->dir = WEST;
		else 
			thingPtr->y += 1;
	}
	else if(thingPtr->dir == WEST) {
		if(thingPtr->x == 0 || table[thingPtr->y][thingPtr->x - 1] == '*')
			thingPtr->dir = NORTH;
		else 
			thingPtr->x -= 1;
	}
}

int main() {
	ifstream fin("ttwo.in");
	ofstream fout("ttwo.out");

	Info cow;
	Info farm;
	cow.dir = NORTH;
	farm.dir = NORTH;

	//parse in input
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			char curr;
			fin >> curr;
			if(curr == 'C') {
				cow.x = j;
                cow.y = i;
				curr = '.';
			}
			else if (curr == 'F') {
				farm.x = j;
                farm.y = i;
				curr = '.';
			}
			table[i][j] = curr;
		}
	}

	int numMinutes = 0;
	for(int i = 0; i < MAXSTEPS; i++) {
		numMinutes++;
		makeStep(&farm);
		makeStep(&cow);
		if(farm.x == cow.x && farm.y == cow.y) {
			fout << numMinutes << endl;
			return 0;
		}
	}

	fout << 0 << endl;
	return 0;
}
