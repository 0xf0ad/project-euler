#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int main(){
	uint16_t max = 1000;
	uint64_t sum = 0;
	for(unsigned int i = 0; i != max; i++){
		if(( (i%3) == 0 || (i%5) == 0))
			sum += i;
	}

	printf("their sum is %zu\n", sum);
	return EXIT_SUCCESS;
}
