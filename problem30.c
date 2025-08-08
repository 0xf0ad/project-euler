#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#define FIFTHPOWER(x) ( (x) * (x) * (x) * (x) * (x))

int main(void){

	uint32_t totalsum = 0;

	for(uint32_t i = 2; i != 200000; i++){
		uint8_t numdigits = ceilf(log10f(i));
		uint32_t crntdigit;
		uint32_t sum = 0;
		uint32_t _i = i;
		bool overflowed = false;
		for(uint8_t j = 0; j != numdigits; j++){
			crntdigit = _i % 10;
			sum += FIFTHPOWER(crntdigit);
			_i /= 10;
			if(sum > i){
				overflowed = true;
				break;
			}
		}
		if(!overflowed)
			if(sum == i)
				//printf("lmao I fonund %u\n", i);
				totalsum += sum;
	}

	printf("sum of all the numbers that can be written as the sum of fifth powers of their digits is %u\n", totalsum);
	
	return EXIT_SUCCESS;
}
