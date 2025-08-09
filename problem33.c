#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// I hade a bug that correctly finds the non-trivial fractions that are > 1
// lmao i am putting a bandage over it and reverting the sequence of displaying digits

int main(void){

	uint8_t a, b;
	uint64_t p = 1, q = 1;

	for(a = 0 ; a < 10; a++){
		for(b = 1; b < 10; b++){
			if(a == b)
				continue;

			if (b < a){
				// hmm this first for loop doesnt seem to find anything...
				for(uint8_t c = 1; c < 10; c++)
					if(a != c)
						if((double)((a*10)+b)/((b*10)+c) == (double)a/c)
							q *= (a*10 + b), p *= (a*10 + c);
							//printf("%u%u/%u%u = %u/%u\n", b, c, a, b, a, c);
				for(uint8_t c = 1; c <= a; c++)
					if((double)((a*10)+b)/((c*10)+a) == (double)b/c)
						q *= (a*10 + b), p *= (c*10 + a);
						//printf("%u%u/%u%u = %u/%u\n", c, a, a, b, c, b);
			}
		}
	}

	for(uint64_t gcd = p > q ? q : p; gcd > 0; gcd--){
		if(p % gcd == 0 && q % gcd == 0){
			printf("%lu\n", q / gcd);
			break;
		}
	}

	return EXIT_SUCCESS;
}