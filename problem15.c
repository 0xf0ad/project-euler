#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

uint64_t comb(uint64_t n){
	uint64_t prev_res = 1;
	
	for(uint64_t i = 1; i != n + 1; i++)
		prev_res = prev_res * (4 * i - 2) / i;

	return prev_res;
}

int main(void){
	uint16_t grid_size = 20;

	// the grid defines a path from the top left croner to the bottom right
	// all paths following the problem's rules have the same lenth
	// but all paths that follows the same rules and have the same rules
	// end on the diagnal line passing by the bottom right corner at 45 angle
	// and the patterne of wich path ends on witch point the that diagnal line
	// follows a gaussean distribution so we only need to count the total
	// number of possible paths with the same lenght and rules and multiply 
	// that with the probability of a single random line to end up on our target
	// paths can only go right or down and cannot stop so each time it can
	// do one of two thinks a fixed amount of times so it can be computed by
	// 2 ^ (2*grid_size) and the probability of it getting onour target can
	// be computed using a pascal triangle but we dont need the entire
	// triangle so we will use combinations to get a single element from it
	// EDIT : I relise that those terms can be cancelled becaus they are the
	// same so dont bother computting them anyway
	
	// using the probalistic combination to get the grid_size-th element
	// from the path_len-th row of the alkhayam triangle
	uint64_t num_paths = comb(grid_size);

	printf("in %ux%u grid, exist %zu routes\n", grid_size, grid_size, num_paths);

	return EXIT_SUCCESS;
}

