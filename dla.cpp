// dla.cpp, written by Sayre Christenson, 2013-11-18
// dla.py was way too slow

#include"dla.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	// help text
	if (argc < 5) {
		cout << "Usage: dla side n_particles circ diag\n";
		exit(EXIT_FAILURE);
	}
	
	// arg check for diagonal
	int diag = 0;
	if (strcmp(argv[4], "y") == 0) diag = 1;
		
	// initialize grid
	int side = atoi(argv[1]);
	int bound = side-1;
	MyGrid obj (side, argv[3]);
	
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
	vector<int> length_list = list_populate(side);
	vector<int> box_count = obj.box_count(length_list);

	// print dimension and map results
	dims_out(length_list, box_count);
	obj.grid_out();

	return 0;
}
