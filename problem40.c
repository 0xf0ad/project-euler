#include <stdio.h>
#include <stdint.h>

// I addmit I used python and it run on 2s
// this was frustrating

int main(void){

	uint64_t prod = 1;
	uint64_t pwrten = 1;
	uint64_t offset = 1;
	uint64_t targets[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
	uint8_t j = 0;
	for(uint8_t i = 1; j < sizeof(targets)/sizeof(targets[0]); i++){
		uint64_t n_pwrten = pwrten * 10;
		uint64_t n_offset = offset + (i * (n_pwrten - pwrten));

		for( ;j < (sizeof(targets)/sizeof(targets[0])) && targets[j] < n_offset; j++){
			double a = offset + ((double)(targets[j] - offset) / (double)i);
			uint64_t num = (uint64_t) a;
			uint8_t b = i - ((a - num) * i);

			for(uint8_t k = 1; k < b; k++)
				num /= 10;
			num = num % 10;

			prod *= num;
		}
		pwrten = n_pwrten;
		offset = n_offset;
	}
	printf("prod = %lu\n", prod);

	return 0;
}