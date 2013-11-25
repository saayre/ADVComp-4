// dla.hpp, written by Sayre Christenson, 2013-11-18

#include<stdlib.h>
#include<ctime>
#include<iostream>
#include<fstream>
#include<new>
#include<vector>
#include<cmath>
#include<string.h>

using namespace std;

class MyGrid {
	int **grid;
	int bound;
	int grid_sum(int, int, int, int);
  public:
	MyGrid (int, char*, int);
	int check(int, int, int);
	void add(int, int);
	void grid_out();
	vector<int> box_count(vector<int>);
};

MyGrid::MyGrid(int side, char *circ, int top) {
	grid = new int*[side];
	bound = side - 1;

	// grid seed
	double radius = -1;
	if (circ[0] > '0' && circ[0] < '9') radius = atof(circ);

	for (int i = 0 ; i < side ; i++) {
		grid[i] = new int[side];

		for (int j = 0 ; j < side ; j++) {

			grid[i][j] = 0;
			if (sqrt( pow(i - side/2, 2) + pow(j - side/2, 2) ) < radius) grid[i][j] = 1;
		}
	}

	if (top == 0) grid[side/2][side/2] = 1;
	else grid[side/2][3*side/4] = 1;
		
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

vector<int> MyGrid::box_count(vector<int> length_list) {
	vector<int> box_count;
	for (unsigned int i = 0 ; i != length_list.size() ; i++) {
		
		int len = length_list[i];
		int count = 0;
		int y = 0;

		while (y < bound) {

			int x = 0;
			while (x < bound) {

				if ( grid_sum(x, x+len, y, y+len) > 0 ) {
					count++;
				}

				x += len;
			}

			y += len;
		}

		box_count.push_back(count);
	}

	return box_count;
}

int MyGrid::grid_sum(int x_l, int x_r, int y_t, int y_b) {
	int sum = 0;
	if (y_b > bound+1) y_b = bound+1;
	if (x_r > bound+1) x_r = bound+1;
	for (int y_it = y_t ; y_it < y_b ; y_it++) {
		for (int x_it = x_l ; x_it < x_r ; x_it++) {
			if (grid[x_it][y_it] == 1) sum++;
		}
	}

	return sum;
}

vector<int> list_populate(int size) {
	vector<int> list;
	for (int i = 2 ; i < size ; i+=2) {
		list.push_back(i);
	}
	return list;
}
 

void dims_out(vector<int> length_list, vector<int> box_count) {
	ofstream dims;
	dims.open("dims.dat");

	for (unsigned int i = 0 ; i < length_list.size() ; i++) {
		dims << log10(length_list[i]) << ' ' << log10(box_count[i]) << '\n';
	}

	dims.close();
}
