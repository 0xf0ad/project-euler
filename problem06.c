#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main(void){
	uint32_t target = 100;

	// the sum is of equation (n^3 - n) * (3n+2) / 12

	uint64_t n_cubic = target * target * target;
	uint64_t three_n_plus_two = 3 * target + 2;
	uint64_t result = ((n_cubic - target) * three_n_plus_two) / 12;

	printf("the difference between the sum of the squares of the first %u natural numbers and the square of the sum is %zu\n", target, result);
	return EXIT_SUCCESS;
}
