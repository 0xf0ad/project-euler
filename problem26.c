#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BUFSIZE 2048
#define MAXNUM 1000

// elementary school devition (forget it)
/*
uint32_t divmod10(uint32_t num, char* str, size_t size){
	uint32_t remainder = 1;
	uint32_t prevrmdr = 10;
	size_t i = 0;
	for( ; i != size; i++){
		remainder = prevrmdr % num;
		if(!remainder){
			if(!prevrmdr){
				str[i] = ((prevrmdr) / num) + '0';
				break;
			}
		}
		str[i] = ((prevrmdr - remainder) / num) + '0';
		//printf("rem: %u, prev: %d, res: %c\n", remainder, prevrmdr, str[i]);
		prevrmdr = remainder * 10;
	}
	str[i] = '\0';
	return i;
}
*/

int main(void){
	// dont worry abiut this
	/*
	char buf[BUFSIZE];

	bool found = false;
	uint32_t longuestsofar = 0;
	uint32_t owneroflonguest;
	for(uint32_t i = 2; i != MAXNUM; i++){
		uint32_t len = divmod10(i, buf, BUFSIZE);
		printf("1/%d = 0.%s\n", i, buf);
		for(uint32_t j = len-1; j != 0xffffffff; j--){
			printf("\tj = %u\n", j);
			for(uint32_t k = j+1; k != len; k++){
				printf("\t\tk = %u\n", k);
				if(buf[j] == buf[k]){
					printf("buf[j] = buf[k] = %c = %c\n", buf[j], buf[k]);
					found = true;
					uint32_t l;
					uint16_t fnddigits = 0;
					for(l = 0; l != MIN((len - k), (k - j)) - 1; l++){
						printf("\t\t\tl = %u\n", l);
						if(buf[j+l] != buf[k+l]){
							printf("(buf[j+l] = %c) != (buf[k+l] = %c)\n", buf[j+l], buf[k+l]);
							found = false;
							break;
						}
					}
					if(found){
						if(longuestsofar < (k - j)){
							longuestsofar = k - j;
							owneroflonguest = i;
							printf("found that %d has the longuest with streak of %d\n", owneroflonguest, longuestsofar);
							break;
						}
					}
					break;
				}
			}
		}
	}
	*/

	uint32_t value, counter;
	uint32_t strike = 0;
	uint32_t strikeowner;
	for (uint32_t i = 7; i != MAXNUM; i++){
		counter = 0;
		value = 10 % i;
		uint32_t j = MAXNUM;
		while (value != 1 && j != 0){
			value *= 10;
			value = value % i;
			counter++;
			j--;
		}
		if (counter > strike && j > 1){
			strike = counter;
			strikeowner = i;
		}
	}
	
	printf("biggest strike of %u by the number %u\n", strike, strikeowner);
	return EXIT_SUCCESS;
}
