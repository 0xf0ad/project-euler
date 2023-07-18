#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

uint64_t factorial(uint64_t n){
	uint64_t result = 1;
	for(; n > 1; n--)
		result *= n;
	return result;
}

int main(void){
	uint32_t maxiters = 1000000;
	uint8_t numnumbers = 10;
	uint8_t numbers[numnumbers];
	char result[numnumbers+1];

	for(uint8_t i = 0; i != numnumbers; i++)
		numbers[i] = i;

	uint64_t prev_remainder = maxiters-1;
	for(uint32_t n = numnumbers-1; n != -1; n--){
		uint64_t nfact = factorial(n);
		uint64_t divresult = prev_remainder / nfact;
		prev_remainder = prev_remainder % nfact;
		result[numnumbers-n-1] = numbers[divresult] + '0';
		for(uint32_t i = divresult; i != n; i++)
			numbers[i] = numbers[i+1];
	}

	printf("the %uth lexicographic permutation of the digits is %s\n", maxiters, result);
	return EXIT_SUCCESS;
}

