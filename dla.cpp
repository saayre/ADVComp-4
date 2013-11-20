// dla.cpp, written by Sayre Christenson, 2013-11-18
// dla.py was way too slow

#include"dla.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	// arg check for diagonal
	int diag = 0;
	if (argc > 3) diag = 1;
		
	// initialize grid
	int side = atoi(argv[1]);
	int bound = side-1;
	MyGrid obj (side);
	
	// loop over walking in particles
	int N = atoi(argv[2]);
	int x, y;
	
	srand(time(NULL));
	for (int n = 0 ; n < N ; n++) {

		// set initial value on edge
		if (rand() % 2 == 0) {
			x = rand() % bound;
			y = (rand() % 2) * bound;
			
		}
		else {
			y = rand() % bound;
			x = (rand() % 2) * bound;

		}

		while (obj.check(x, y, diag) == 0) {
			
			// move
			if (rand() % 2 == 0) {
				if (rand() % 2 == 0) x++;
				else x--;
			}
					
			else {
				if (rand() % 2 == 0) y++;
				else y--;
			}

			x = (x+side)%side;
			y = (y+side)%side;
		}

		obj.add(x, y);
	}

	// count boxes
	// int length_list[] = fun;
	// int box_count[] = obj.yeah;

	// print dimension and map results
	obj.grid_out();

	return 0;
}
