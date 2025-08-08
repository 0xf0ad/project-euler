#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
	uint32_t n = 0;
	uint32_t max_n = 1000000;
	uint32_t max_chain_len = 0;

	for(uint32_t m = n; m != max_n; m++){
		uint64_t i = m;
		uint64_t crnt_chain = 0;

		while(i > 1){
			if(i % 2)
				i = 3 * i + 1;
			else
				i /= 2;
			crnt_chain++;
		}

		if(crnt_chain > max_chain_len){
			max_chain_len = crnt_chain;
			n = m;
		}
	}

	printf("starting number %u, under %u, produces the longest chain containing %u elements\n", n, max_n, max_chain_len+1);

	return EXIT_SUCCESS;
}

