#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>


int main(void){
	uint32_t target = 20;
	uint32_t i = 2;
	bool found = true;

	for(;; i++){
		for(uint32_t j = target; j != 1; j--)
			if(i % j){
				found = false;
				break;
			}

		if(found)
			break;
		found = true;
	}
	printf("the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 is %u\n", i);
	return EXIT_SUCCESS;
}

