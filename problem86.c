#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

uint32_t hh(uint32_t M){
	uint32_t result = 0;
	for(uint32_t i = 1; i <= M; i++){
		for(uint32_t j = i; j <= M; j++){
			double p = sqrt(((i+j)*(i+j)) + (M*M));
			if(p == (int)p) result++;
		}
	}
	return result;
}

int main(void){

	uint32_t sum = 0, M = 2;
	while(sum < 1000000)
		sum += hh(M++);

	printf("m = %u:\t%u\n", M-1, sum);

	return EXIT_SUCCESS;
}
