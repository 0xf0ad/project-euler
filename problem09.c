#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void){
	int64_t a, b, c;
	const uint32_t sum = 1000;
	bool found = false;

	for(a = 1; !(a == sum || found); a++){
		uint64_t a_squared = a*a;
		for(b = 1; b != sum - a; b++){
			c = sum - a - b;
			if(a_squared + b*b == c*c){
				found = true;
				break;
			}
		}
	}

	// a is incremented befaure exiting the loop so we sould decrement it to obtain its original state
	a--;

	printf("a = %ld\tb = %ld\tc = %ld\ntheir product : %ld\n", a, b, c, a * b * c);
	return EXIT_SUCCESS;
}
