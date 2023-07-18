#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

uint64_t d(uint64_t n){
	uint32_t nsqrt = sqrt(n) + 1;
	uint64_t sum = 1;

	for(uint32_t i = 2; i != nsqrt; i++){
		if(!(n % i)){
			sum += i;
			if( i*i != n)
				sum += n / i;
		}
	}

	return sum;
}

int main(void){
	uint64_t maxn = 10000;
	uint64_t sum = 0;

	for(uint64_t i = 1; i != maxn; i++){
		uint64_t res = d(i);
		if(i == d(res) && res != i)
			sum += i;
	}

	printf("sum : %zu\n", sum);
	return EXIT_SUCCESS;
}

