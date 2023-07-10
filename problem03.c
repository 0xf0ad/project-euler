#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(uint64_t n){
        if(n < 4)
                return n > 1;
        if(!((n % 2) && (n % 3)))
                return false;

        uint64_t sealling = sqrt(n);
        for(uint32_t i = 5; i <= sealling; i += 6)
                if(!( n % (i) && n % (i+2) ))
                        return false;
        return true;
}


int main(void){
	uint64_t number = 600851475143;

	// I speed up the execution b 1342000% just by adding this line
	// from 89min 28sec to 0.004 second UNREEAAAAAAL
	uint32_t numsqrt = sqrt(number) + 1;
	
	// subtract 1 if the number was even
	uint64_t i = numsqrt - !(numsqrt & 1);
	for(; i > 1; i -= 2)
		if(!(number % i))
			if(isPrime(i))
				break;

	printf("the largest prime factor of the number %zu is %zu\n", number, i);
	return EXIT_SUCCESS;
}
