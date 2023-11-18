#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int main(void){
	uint32_t max_digits = 1000;
	char results[2][max_digits+1];
	for(uint32_t i = 0; i != max_digits; i++)
		results[0][i] = results[1][i] = '0';
	results[0][max_digits-1] = results[1][max_digits-1] = '1';
	results[0][max_digits] = results[1][max_digits] = '\0';
	bool chosen = false;

	uint32_t index = 2;
	while(results[0][0] == '0' && results[1][0] == '0'){
		uint32_t j = max_digits-1;
		bool carry = 0;

		while(j != -1){
			uint32_t tmp = ((carry + results[0][j] + results[1][j] - (2 * '0')) % 10) + '0';
			carry = (carry + results[0][j] + results[1][j] - (2 * '0')) / 10;
			results[chosen][j] = tmp;
			j--;
		}

		chosen = !chosen;
		index++;
	}

	printf("the index of the first term in the Fibonacci sequence to contain %u digits is : %u\n", max_digits, index);
	return EXIT_SUCCESS;
}
