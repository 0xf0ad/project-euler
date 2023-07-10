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
	uint32_t i, j;
	
	for(i = 3, j = 1; j != 10001; i += 2)
		if(isPrime(i))
			j++;

	// the variable i get incremented before checking
	// for j so we should subtract 1 to get the original number
	printf("the %uth prime number is %u\n", j, (i-2));
	return EXIT_SUCCESS;
}
