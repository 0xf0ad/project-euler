#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void increment(uint8_t* digits, uint8_t size){
	for(uint8_t i = size; i > 0; i--){
		if(digits[i-1] == 9)
			digits[i-1] = 0;
		else {
			digits[i-1]++;
			return;
		}
	}
}

uint64_t numirical(uint8_t* digits, uint8_t size){
	uint64_t ten = 1;
	uint64_t res = 0;
	for(uint8_t i = size; i > 0; i--){
		res += digits[i-1] * ten;
		ten *= 10;
	}
	return res;
}

uint64_t factorial(uint8_t* digits, uint8_t size){
	uint64_t factorial[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
	uint64_t sum = 0;
	uint8_t begin = 0;
	for(uint8_t i = 0; i < size; i++){
		if(digits[i] != 0)
			begin = 1;
		if(begin)
			sum += factorial[digits[i]];
	}
	return sum;
}

// it can be proven that theise numbers dont exede 10^6
// by solving for 9! * a < 10^(a+1) ; a is a little more than 6

int main(void){

	uint64_t sum  = 0;

	#define SIZE 7
	uint64_t treshhold = 1000000;

	uint8_t digits[SIZE] = {0};
	digits[SIZE-1] = 3;
	

	while(1){
		uint64_t watermelon = numirical(digits, SIZE);
		uint64_t mhayya = factorial(digits, SIZE);

		if(watermelon == mhayya){
			sum += watermelon;
		}else if(watermelon < mhayya){
			digits[SIZE-1] = 9;
		}
		
		if (watermelon > treshhold)
			break;

		increment(digits, SIZE);
	}

	printf("solution is %lu\n", sum);

	return EXIT_SUCCESS;
}