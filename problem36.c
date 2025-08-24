#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

uint32_t msb(uint32_t n){
	return (sizeof(typeof(n)) << 3) - __builtin_clz(n | 1);
}

uint32_t ispalindrom2(uint32_t n){
	uint32_t p = msb(n), q = p - 1;
	uint32_t m = 0;
	while(p--)
		m |= ((n >> p) & 1) << (q - p);
	return n == m;
}

bool increment(uint8_t* digits, uint8_t size){
	for(uint8_t i = size; i > 0; i--){
		if(digits[i-1] == 9)
			digits[i-1] = 0;
		else {
			digits[i-1]++;
			return false;
		}
	}
	return true;
}

uint32_t construct_num(uint8_t* dig, uint32_t size, uint8_t odd){
	uint32_t mm = 0, num = 0, ten = 1;
	while(mm < size){
		num += dig[mm++] * ten;
		ten *= 10;
	}
	mm -= odd;
	while(mm--){
		num += dig[mm] * ten;
		ten *= 10;
	}
	return num;
}

uint32_t count_palindrom_of_n_digits(uint32_t n){
	uint32_t m = (n >> 1) + (n & 1);
	uint8_t* dig = malloc(sizeof(uint8_t) * m);
	memset(dig, 0, m * sizeof(uint8_t));
	dig[0] = 1;

	uint8_t over = 0;
	uint32_t sum = 0;
	while(!over){
		uint32_t num = construct_num(dig, m, n&1);
		if(ispalindrom2(num))
			sum += num;
		over = increment(dig, m);
	}

	free(dig);
	return sum;
}

int main(void){

	// a million is 6 digits long
	uint32_t sum = 0;
	for(uint32_t i = 1; i < 7; i++)
		sum += count_palindrom_of_n_digits(i);
	printf("%u\n", sum);

	return EXIT_SUCCESS;
}