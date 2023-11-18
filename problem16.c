#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void poweroftwo(char* number, uint32_t strlen, uint32_t power){
	for(uint32_t i = 0; i != power; i++){

		uint32_t carry = 0;
		for(uint32_t j = strlen - 1; j != -1; j--){
			number[j] = (number[j] << 1) + carry - '0';

			if(number[j] > '9'){
				carry = (number[j] - '0') / 10;
				number[j] = ((number[j] - '0') % 10) + '0';
			} else {
				carry = 0;
			}
		}
	}
}

int main(void){
	uint16_t powerof = 1000;
	uint16_t numdigits = powerof * log10(2) + 1;
	char number[numdigits + 1];
	number[numdigits - 1] = '1';
	for(uint16_t i = 0; i != numdigits - 1; i++)
		number[i] = '0';
	number[numdigits] = '\0';

	poweroftwo(number, numdigits, powerof);

	uint32_t sum = 0;
	for(uint32_t i = 0; i != numdigits; i++)
		sum += number[i] - '0';

	printf("%u\n", sum);

	return EXIT_SUCCESS;
}
