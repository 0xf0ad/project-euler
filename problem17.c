#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>


const char digits[][10]      = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char over_ten[][10]    = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char prefix_tens[][10] = {"zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const char* hundred           = "hundred";
const char* thousand          = "thousand";

uint32_t num_len_in_lettres(const char* number){
	uint8_t ones      = number[4] - '0';
	uint8_t tens      = number[3] - '0';
	uint8_t hundreds  = number[2] - '0';
	uint8_t thousands = number[1] - '0';
	uint32_t len = 0;

	if(ones)
		len += strlen(digits[ones]);

	if(tens == 1)
		len = strlen(over_ten[ones]);
	else if(tens > 1)
		len += strlen(prefix_tens[tens]);
	if(hundreds && len == 0)
		len += strlen(digits[hundreds]) + strlen(hundred);
	else if(hundreds && len != 0)
		len += strlen(digits[hundreds]) + strlen(hundred) + strlen("and");
	if(thousands)
		len += strlen(digits[thousands]) + strlen(thousand);

	if(!len)
		len = strlen(digits[0]);

	return len;
}

int main(void){
	char number[5];
	uint32_t sum = 0;

	for(uint8_t i = 0; i != 5; i++)
		number[i] = '0';

	for(uint32_t i = 0; i != 1000; i++){
		uint32_t j = 4;
		if(number[j] == '9'){
			uint32_t k = j;
			while(number[k] == '9'){
				number[k] = '0';
				k--;
			}
			number[k]++;
		} else {
			number[j]++;
		}
		sum += num_len_in_lettres(number);
	}

	printf("number of letter excludding spaces and hyphens for 1 to 1000 is %u\n", sum);

	return EXIT_SUCCESS;
}

