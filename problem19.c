#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

uint8_t days_on_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void){
	uint8_t first_day = 366 % 7;
	uint8_t crnt_day = first_day;
	uint16_t num_mounths = 100 * 12;
	uint16_t sundays_on_fell_month = 0;

	for(uint16_t i = 0; i != num_mounths + 1; i++){
		crnt_day = (crnt_day + days_on_month[i % 12]) % 7;

		if((i % 12) == 1)
			if(!(i / 12) % 4)
				crnt_day++;

		if(crnt_day == 6)
			sundays_on_fell_month++;
	}

	printf("%u sunday accure on the 20th centry\n", sundays_on_fell_month);

	return EXIT_SUCCESS;
}
