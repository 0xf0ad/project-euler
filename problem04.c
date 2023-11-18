#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

bool isPalindrome(uint32_t num){
	if(num == 0)            return true;

	uint8_t digits[10];
	uint32_t tmpNum = num;
	uint8_t digitNumber = 0;

	while(tmpNum){
		digits[digitNumber] = tmpNum % 10;
		tmpNum /= 10;
		digitNumber++;
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
	// this is the largest polidrome number which can be a product of two 3-digit numbers
	uint32_t number = 997799;
	uint32_t i, j;

	while(number > 9999){
		if(isPalindrome(number)){
			for(i = 999; i != 99; i--){
				if(!(number % i)){
					j = number / i;
					if((j > 99) && (j < 1000)){
						goto getout;
					}
				}
			}
		}
		number--;
	}

	getout:

	printf("the number is %u = %u x %u\n", number, i, j);
	return EXIT_SUCCESS;
}
