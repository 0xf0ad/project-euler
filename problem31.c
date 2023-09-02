#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

uint16_t calc(uint8_t* indicies, uint8_t* currencies, uint8_t size){
	uint16_t sum= 0;
	for(uint8_t i = 0; i != size; i++)
		sum += indicies[i] * currencies[i];
	return sum;
}


int main(void){
	// brute force is probably fiiiiiiiiine
	
	uint16_t target = 200;
	// account for the obveous pattern of all pennies
	uint32_t total = 1;

	uint8_t currencies[8] = { 200, 100, 50, 20, 10, 5, 2, 1 };
	uint8_t indicies[8]   = {0};
	uint8_t maxes[8]      = { 2, 3, 5, 11, 21, 41, 101, 201 };

	// because we wants to strat from 2p instead of 1p
	uint8_t i = sizeof(currencies) - 2;
	// 45829
	bool done = false;
	bool shouldchange = false;
	while(!done){
		if(i != 0){
			if(indicies[i] == maxes[i]){
				indicies[i] = 0;
				i--;
				shouldchange = true;
				//printf("max %u, tar %u, cal %u, cur %u, new %d\n", maxes[i], target, calc(indicies, currencies, sizeof(currencies)), currencies[i], ((target - calc(indicies, currencies, sizeof(currencies))) / currencies[i]) + 1);
				//maxes[i] = ((target - calc(indicies, currencies, sizeof(currencies))) / currencies[i]) + 1;
				continue;
			} else {
				if(shouldchange || i == sizeof(currencies) - 2){
					indicies[i]++;
					i = sizeof(currencies) - 2;
					shouldchange = false;
				}
			}
		} else {
			if(indicies[0] == maxes[0])
				done = true;
			else {
				indicies[0]++;
				i++;
			}
		}
		uint16_t res = calc(indicies, currencies, sizeof(currencies));
		if(res <= target){
			//printf("2£: %u\t1£: %u\t50p: %u\t20p: %u\t10p: %u\t5p: %u\t2p: %u\t1p: %u\n", indicies[0], indicies[1], indicies[2], indicies[3], indicies[4], indicies[5], indicies[6], target - res);
			total++;
		}
	}

	printf("exist %u different ways can £%.2f be made using any number of coins\n", total, target / 100.0f);

	return EXIT_SUCCESS;
}

