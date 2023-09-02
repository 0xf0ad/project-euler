#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

bool isPandigital(uint32_t num){
	bool digits[10] = { false };
	while(num){
		uint8_t digit = num % 10;
		// if a digit is previously read or if the digit is a 0 return false
		if(digits[digit] || !digit)
			return false;
		// else set the array element and continue
		digits[digit] = true;
		num /= 10;	
	}
	return true;
}

// function expects two numbers and return 1 if the two numbers and their product is 
bool prodIsPandigital(uint32_t a, uint32_t b){

	// a * b = c
	uint32_t c = a * b;
	bool digits[10] = { false };
	
	for(uint32_t i = 0; i != 3; i++){
		uint32_t num;
		switch(i){
			case 0:
				num = a;
				break;
			case 1:
				num = b;
				break;
			case 2:
				num = c;
				break;
		}
		while(num){
			uint8_t digit = num % 10;
			// if a digit is previously read or if the digit is a 0 return false
			if(digits[digit] || !digit)
				return false;
			// else set the array element and continue
			digits[digit] = true;
			num /= 10;	
		}
	}
	
	for(uint8_t i = 1; i != sizeof(digits); i++)
		if(!digits[i])
			return false;
	return true;
}

void insertifnotthere(uint32_t val, uint32_t* arr, size_t size){
	for(uint32_t i = 0; i != size; i++){
		if(arr[i] == val)
			return;
		if(!arr[i]){
			printf("sf l9itha %u\n", i);
			arr[i] = val;
			return;
		}
	}
}

uint32_t arrsum(uint32_t* arr, uint32_t size){
	uint32_t sum = 0;
	for(uint32_t i = 0; i != size; i++)
		sum += arr[i];
	return sum;
}

int main(void){

	uint32_t i, j;
	bool done = false;
	uint32_t results[16] = {0};
	i = 1;
	while(i){
		if(isPandigital(i)){
			j = 1;
			while(j < (10000000 / i)){
				if(prodIsPandigital(i, j)){
					if(i > j)
						done = true;
					else
						insertifnotthere(i * j, results, sizeof(results) / sizeof(results[0]));
				}
				j++;
			}
			if(done)
				break;
		}
		i++;
	}

	uint32_t sum = arrsum(results, sizeof(results) / sizeof(results[0]));
	printf("the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital is %u\n", sum);

	return EXIT_SUCCESS;
}

