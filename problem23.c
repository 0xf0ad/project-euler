#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isabundant(uint32_t num){
	if(num < 12)
		return false;
	uint32_t sqrtnum = ceil(sqrt(num));
	uint32_t divsum = 1;
	for(uint32_t i = 2; i != sqrtnum; i++)
		if(!(num % i))
			divsum += i + num/i;

	if(sqrtnum * sqrtnum == num)
		divsum += sqrtnum;

	return (divsum > num);
}

int main(void){

	bool canbewrittenassumoftwoabundant = false;
	uint64_t sum = 276;
	for(uint32_t i = 25; i != 28124; i++){
		for(uint32_t j = 12; j != (i-12); j++)
			if(isabundant(j))
				if(isabundant(i-j)){
					canbewrittenassumoftwoabundant = true;
					break;
				}
		if(canbewrittenassumoftwoabundant)
			canbewrittenassumoftwoabundant = false;
		else
			sum += i;
	}

	printf("sum = %zu\n", sum);
	return EXIT_SUCCESS;
}
