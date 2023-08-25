#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>

#define NUMDIGITS 4

uint32_t isPrime(uint32_t n){
	if(n < 4)
		return (n > 1);

	if(!((n % 2) && (n % 3)))
		return 0;

	uint64_t sealling = sqrt(n);
	for(uint32_t i = 5; i <= sealling; i += 6)
		if(!( n % (i) && n % (i+2) ))
			return 0;

	return 1;
}

#define log10_e 0.4342944819032518

u_int8_t* factorial(uint32_t n, uint32_t p, uint8_t* res){

	uint32_t resdigitnum = (n + 0.5f) * log10f(n) - (p + 0.5f) * log10f(p) - ((n + p) * log10_e);

	for(uint32_t i = 0; i != resdigitnum; i++)
		res[i] = 0;
	res[resdigitnum] = 1;

	for(uint32_t i = n; i != p; i--){
		uint32_t carry = 0;
		for(uint32_t j = resdigitnum; j != ~0; j--){
			res[j] = (res[j] * i) + carry;
			if(res[j] > 9){
				carry = res[j] / 10;
				res[j] = res[j] % 10;
			} else {
				carry = 0;
			}
		}
		uint32_t k = resdigitnum;
		while (carry){
			res[k-1] += carry % 10;
			carry /= 10;
			k--;
		}
	}

}

bool perm(uint32_t n, uint32_t p){

	// the function expectes 4-digits numbers
	uint8_t narr[4], parr[4];

	for(uint8_t i = 0; i != 4; i++){
		narr[i] = n % 10;
		parr[i] = p % 10;
		n /= 10;
		p /= 10;
	}



}

int main(void){

	uint32_t firstterm = 1001;

	uint32_t firstseallling = (10000 / 3) + 1;
	uint32_t secondsealling;
	for(uint32_t i = 0; i != firstseallling; i += 2){
		secondsealling = (10000 - i) / 3;
		for(uint32_t j = 0; j != secondsealling; j++){

			if(isPrime(firstterm + i))
				if(isPrime(firstterm + i + j))
					if(isPrime(firstterm + i + j + j))
						printf("lmaaaaao %u %u %u\n", firstterm + i, firstterm + i + j, firstterm + i + j + j);

		}
	}


}

