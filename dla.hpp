// dla.hpp, written by Sayre Christenson, 2013-11-18

#include<stdlib.h>
#include<ctime>
#include<iostream>
#include<fstream>
#include<new>

using namespace std;

class MyGrid {
	int **grid;
	int bound;
  public:
	MyGrid (int);
	int check(int, int, int);
	void add(int, int);
	void grid_out();
};

MyGrid::MyGrid(int side) {
	grid = new int*[side];
	bound = side - 1;

	for (int i = 0 ; i < side ; i++) {
		grid[i] = new int[side];

		for (int j = 0 ; j < side ; j++) grid[i][j] = 0;
	}

	// grid seed
	grid[side/2][side/2] = 1;
}

// return 1 when a neighbor is on
int MyGrid::check(int x, int y, int diag) {
	int check = 0;

	int xp = (x + 1 > bound) ? 0 : x+1;
	int xm = (x-1 < 0) ? bound : x-1;
	int yp = (y + 1 > bound) ? 0 : y+1;
	int ym = (y-1 < 0) ? bound : y-1;

	if (grid[xp][y] == 1) check = 1;
	if (grid[xm][y] == 1) check = 1;
	if (grid[x][yp] == 1) check = 1;
	if (grid[x][ym] == 1) check = 1;

	if (diag == 1) {

		if (grid[xp][yp] == 1) check = 1;
		if (grid[xp][ym] == 1) check = 1;
		if (grid[xm][yp] == 1) check = 1;
		if (grid[xm][ym] == 1) check = 1;
	}

	return check;
}

void MyGrid::add(int x, int y) {
	grid[x][y] = 1;
}

void MyGrid::grid_out() {

	ofstream map;
	map.open("map.dat");

	for (int i = 0 ; i <= bound ; i++) {
		for (int j = 0 ; j <= bound ; j++) {

			map << i << ' ' << j << ' ' << grid[i][j] << '\n';
		}
	}

	map.close();
}
