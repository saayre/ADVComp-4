// dla.cpp, written by Sayre Christenson, 2013-11-18
// dla.py was way too slow

#include"dla.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	// help text
	if (argc < 6) {
		cout << "Usage: dla side n_particles circ diag top\n";
		exit(EXIT_FAILURE);
	}
	
	// arg check for diagonal and top
	int diag = 0; int top = 0;
	if (strcmp(argv[4], "y") == 0) diag = 1;
	if (strcmp(argv[5], "y") == 0) top = 1;
		
	// initialize grid
	int side = atoi(argv[1]);
	int bound = side-1;
	MyGrid obj (side, argv[3], top);
	
	// loop over walking in particles
	int N = atoi(argv[2]);
	int x, y;
	
	srand(time(NULL));
	for (int n = 0 ; n < N ; n++) {

		// set initial value on edge
		if (top == 0) {
			if (rand() % 2 == 0) {
				x = rand() % bound;
				y = (rand() % 2) * bound;
			
			}
			else {
				y = rand() % bound;
				x = (rand() % 2) * bound;

			}
		}

		else {
			y = 0;
			x = rand() % bound;
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

			// reflect on y if necessary
			if (top == 1) {
				if (y == -1) y = 1;
			}

			x = (x+side)%side;
			y = (y+side)%side;
		}

		obj.add(x, y);
	}

	// count boxes
	vector<int> length_list = list_populate(side);
	vector<int> box_count = obj.box_count(length_list);

	// print dimension and map results
	dims_out(length_list, box_count);
	obj.grid_out();

	return 0;
}
