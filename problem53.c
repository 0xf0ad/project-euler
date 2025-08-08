#include <stdio.h>
#include <stdint.h>

#define n 100
#define onemillion 1000000

int main(void){
	// al-khayam triangle

	uint64_t p[n+1][n] = {0};
	uint64_t counter = 0;

	for(uint8_t i = 0; i <= n; i++){
		p[i][0] = 1;	p[i][i] = 1;
		for(uint8_t j = 1; j < i; j++){
			p[i][j] = p[i-1][j-1] + p[i-1][j];
			counter += p[i][j] > onemillion;
		}
	}
	printf("%zu numbers on alkhayam triangle exede %d\n", counter, onemillion);
}