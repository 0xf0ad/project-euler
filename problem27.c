#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

uint32_t isPrime(int64_t n){
	if(n < 4)
		return (n > 1);

	if(!((n % 2) && (n % 3)))
		return 0;

	uint64_t sealling = sqrt(n);
	for(uint32_t i = 5; i <= sealling; i += 6)
		if(!( n % (i) && n % (i+2) ))
			return 0;

	return 1;
}

int main(void){
	int16_t a , b;

	uint16_t hiestsofar;
	int16_t ithinkifounda, ithinkifoundb;
	hiestsofar = ithinkifounda = ithinkifoundb = 0;

	for(a = -999; a < 1000; a += 2){
		for(b = -999; b < 1000; b += 2){
			uint16_t n = 0;

			while(isPrime((n * (n + a)) + b))
				n++;

			if(n > hiestsofar){
				hiestsofar    = n;
				ithinkifounda = a;
				ithinkifoundb = b;
			}
		}
	}

	printf("Find the product of the coefficients, a and b, for the quadratic expression ");
	printf("that produces the maximum number of primes for consecutive values of n is %d\n", (ithinkifounda * ithinkifoundb));

	return EXIT_SUCCESS;
}
