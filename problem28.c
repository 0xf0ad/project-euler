#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main(void){

	// the max square size
	uint32_t target = 1001;
	// the spiral sum
	uint32_t sum = 1;
	// last summed number
	uint32_t prevnum = 1;

	for(uint32_t i = 2; i < target; i += 2){
		for(uint32_t j = 0; j != 4; j++){
			prevnum += i;
			sum += prevnum;
		}
	}

	printf("the sum of the numbers on the diagonals in a %u by %u spiral formed is %u\n", target, target, sum);

	return EXIT_SUCCESS;

}

