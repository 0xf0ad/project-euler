#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define log10_2piover2 0.3990899341790575
#define log10_e        0.4342944819032518

const char* factorial(uint64_t n){
	// aproximation for the log10(n!)
	uint32_t strlen = (n + 0.5f) * log10f(n) - n * log10_e + log10_2piover2;
	uint32_t result[strlen + 1];

	result[strlen] = 1;
	for(uint32_t i = strlen-1; i != -1; i--)
		result[i] = 0;

	for(uint32_t i = n; i != 1; i--){
		uint32_t carry = 0;
		for(uint32_t j = strlen; j != -1; j--){
			result[j] = result[j] * i + carry;
			if(result[j] > 9){
				carry = result[j] / 10;
				result[j] = result[j] % 10;
			} else {
				carry = 0;
			}
		}
		uint32_t k = strlen;
		while (carry){
			result[k-1] += carry % 10;
			carry /= 10;
			k--;
		}
	}

	char* strres = (char*) malloc(strlen+1);
	for(uint32_t i = 0; i != strlen + 1; i++)
		strres[i] = result[i] + '0';
	strres[strlen+1] = '\0';

	return strres;
}

int main(void){
	uint32_t num = 100;
	const char* res = factorial(num);
	uint32_t reslen = strlen(res) + 1;
	uint64_t sum = 0;

	for(uint32_t i = 0; i != reslen; i++)
		sum += res[i];

	sum -= '0' * (reslen-1);

	printf("the sum of figits of %u! is %zu\n", num, sum);

	free((void*) res);

	return EXIT_SUCCESS;
}
