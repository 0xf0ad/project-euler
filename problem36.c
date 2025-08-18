#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// log_2(10^6) = 20 => max number of mirrored bits is 10

uint32_t palindrom2(uint32_t n, bool odd){
	
}

bool isPalindrome10(uint32_t num){
	uint8_t digits[5];
	uint8_t digitNumber = 0;

	while(num){
		digits[digitNumber++] = num % 10;
		num /= 10;
	}

	if(digitNumber == 1)     return true;

	uint8_t numIters = digitNumber >> 1;
	digitNumber--;

	for(uint8_t i = 0; i != numIters; i++)
		if(digits[i] != digits[digitNumber-i])
			return false;

	return true;
}

int main(void){



	return EXIT_SUCCESS;
}