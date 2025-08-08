#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

// adds two digits arrays
// both digits arrays have to be with the same length
void add(uint8_t* addedto, uint8_t* addedby, size_t len){
	uint8_t carry = 0, result;
	for(size_t i = len - 1; i != ~0; i--){
		result = addedto[i] + addedby[i] + carry;
		carry  = result / 10;
		addedto[i] = result % 10;
	}
}

// fill the buf with the result of x^p as long as buf allows it
void pwr(uint16_t x, uint16_t p, uint8_t* buf, size_t len){
	for(uint16_t i = 0; i != p; i++){
		uint32_t carry = 0, result;
		for(size_t j = len - 1; j != ~0; j--){
			result = (buf[j] * x) + carry;
			carry  = result / 10;
			buf[j] = result % 10;
		}
	}
}

#define BUFSIZE 10

int main(void){

	uint8_t tmp[BUFSIZE];
	uint8_t sum[BUFSIZE] = {'\0'};
	sum[BUFSIZE-1] = 1;

	uint16_t target = 1001;

	for(uint16_t i = 2; i != target; i++){
		memset(tmp, 0, BUFSIZE);
		tmp[BUFSIZE-1] = 1;
		pwr(i, i, tmp, BUFSIZE);
		add(sum, tmp, BUFSIZE);
	}

	for(size_t i = 0; i != BUFSIZE; i++)
		sum[i] += '0';

	printf("the first %u digits of the series up to but not including %u are %s\n", BUFSIZE, target, sum);


	return EXIT_SUCCESS;
}

