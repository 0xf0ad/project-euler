#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main(void){
	uint32_t max = 4000000;

	uint64_t res = 2;
	uint64_t opp[2] = {1};
	uint64_t sum = 0;

	bool whattochange = 0;

	while(res <= max){

		res = opp[0] + opp[1];
		opp[whattochange] = res;
		whattochange = !whattochange;

		if(!(res & 1))
			sum += res;
	}

	printf("their sum is %zu\n", sum);
	return EXIT_SUCCESS;
}
