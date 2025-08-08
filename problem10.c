#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(uint32_t n){
	if(n < 4)
		return n > 1;
	if(!((n % 2) && (n % 3)))
		return false;

	uint32_t sealling = sqrt(n);

	for(uint32_t i = 5; i <= sealling; i += 6)
		if(!( n % (i) && n % (i+2) ))
			return false;

	return true;
}

int main(void){
	uint32_t number = 2000000;
	uint64_t sum = 2;

	for(uint32_t i = 3; i < number; i += 2)
		if(isPrime(i))
			sum += i;

	printf("the sum of all the primes below %u is %zu\n", number, sum);
	return EXIT_SUCCESS;
}

