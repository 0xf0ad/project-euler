#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define adjnumdigits 4

const char* number = "0802229738150040007504050778521250779108"
                     "4949994017811857608717409843694804566200"
                     "8149317355791429937140675388300349133665"
                     "5270952304601142692468560132567137023691"
                     "2231167151676389419236542240402866331380"
                     "2447326099034502447533537836842035171250"
                     "3298812864236710263840675954706618386470"
                     "6726206802621220956394396308409166499421"
                     "2455580566739926971778789683148834896372"
                     "2136230975007644204535140061339734313395"
                     "7817532822753167159403800462161409535692"
                     "1639054296353147555888240017542436298557"
                     "8656004835718907054444374460215851541758"
                     "1980816805944769287392138652177704895540"
                     "0452088397359916079757321626267933279866"
                     "8836688757622072034633674655123263935369"
                     "0442167338253911249472180846293240627636"
                     "2069364172302388346299698267598574043616"
                     "2073352978319001743149714886811623570554"
                     "0170547183515469169233486143520189196748";

enum direction{
	right,
	down,
	forward_diagonal,
};

int main(void){
        const char* adjnum;
		// devide by 2 to get how many 2-digit numbers an the number
        uint16_t numnumbers= strlen(number) >> 1;
		uint16_t row_size = 20;
		uint16_t colum_size = numnumbers / row_size;
        uint64_t maxprod = 0, maxindex  = 0;
        uint64_t prod;

        for(uint16_t i = 0; i < numnumbers - adjnumdigits; i += 2){
                adjnum = number + i;

				for(enum direction dir = right; dir < forward_diagonal; dir++, prod = 1){
						if(dir == right && i <= row_size - adjnumdigits * 2)
								for(uint32_t j = 0; j != adjnumdigits * 2; j += 2){
										prod *= ((adjnum[j] - '0') * 10 + (adjnum[j + 1] - '0'));
										printf("%zu on %8s\n", prod, &adjnum[j]);
								}
						else if(dir == down && i <= colum_size - adjnumdigits)
								for(uint32_t j = 0; j != adjnumdigits * 2; j += row_size * 2)
										prod *= ((adjnum[j] - '0') * 10 + (adjnum[j + 1] - '0'));
						else if(dir == forward_diagonal && row_size - adjnumdigits * 2 && colum_size - adjnumdigits)
								for(uint32_t j = 0; j != (adjnumdigits+1) * 2; j += (row_size+1) * 2)
										prod *= ((adjnum[j] - '0') * 10 + (adjnum[j + 1] - '0'));
						if(prod > maxprod){
								maxprod = prod;
								maxindex = i;
						}
				}
        }

        const char* temp = strndup((number + maxindex), adjnumdigits);

        printf("their product is %zu on starts with %2s\n", maxprod, number + maxindex);

        free((void*) temp);

        return EXIT_SUCCESS;
}

