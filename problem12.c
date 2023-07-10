#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int main(void){
	uint64_t prev_number = 0;
	uint64_t number = 1;
	uint64_t last_added = 0;
	uint16_t num_divisor;
	uint16_t target_divisors = 500;

	for(uint64_t i = 0; i != -1; i++){
		last_added++;
		number = prev_number + last_added;
		prev_number = number;
		
		// add one because every number is divizable by one and itself
		// excludding one because it is itself a one
		num_divisor = 0;

		uint32_t num_sqrt = sqrt(number) + 1;

		for(uint32_t i = 1; i != num_sqrt; i++)
			if(!(number % i))
				num_divisor++;
		
		num_divisor *= 2;
		num_divisor -= (num_sqrt * num_sqrt == number);

		if(num_divisor >= target_divisors)
			break;
	}

	printf("the value of the first triangle number to have over %u divisors is %zu\n", target_divisors, number);

	return EXIT_SUCCESS;
}

