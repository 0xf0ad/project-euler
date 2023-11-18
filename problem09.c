#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int main(void){
	int64_t a, b, c;
	const uint32_t sum = 1000;

	for(a = 1; a != sum; a++){
		uint64_t a_squared = a*a;
		for(b = 1; b != sum - a; b++){
			c = sum - a - b;
			if(a_squared + b*b == c*c)
				goto getout;
		}
	}

	getout:

	printf("a = %ld\tb = %ld\tc = %ld\ntheir product : %ld\n", a, b, c, a * b * c);
	return EXIT_SUCCESS;
}
