#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

uint32_t get_num_names(FILE* file){
	size_t counter = 1;

	while(!feof(file))
		if(fgetc(file) == ',')
			counter++;

	// clear the EOF reacheed by the prev loop
	clearerr(file);
	rewind(file);
	return counter;
}

typedef struct{
	const char* name;
	uint32_t lenght;
	uint32_t order;
	uint32_t score;
} data;

void swap(data* a, data* b){
	data tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort(data* arr, uint32_t len){
	uint32_t i, pvt = 0;

	if (len <= 1)
	return;

	swap(arr+((uint32_t)rand() % len), arr+len-1);

	for (i = 0; i != len-1; i++)
		if (strcmp(arr[i].name, arr[len-1].name) < 0)
			swap(arr+i, arr+pvt++);

	swap(arr+pvt, arr+len-1);

	sort(arr, pvt++);
	sort(arr + pvt, len - pvt);
}

int main(int argc, char** argv){

	uint32_t listlen;
	if(argc < 2){
		printf("please supply the filename of the list of names as an argumant\n");
		return EXIT_FAILURE;
	}
	const char* filename = argv[1];
	FILE* file = fopen(filename, "r");

	if(!file){
		fprintf(stderr, "could not file %s, does it existe ? do you ? it may existe as free electrons stored on your drive but what about you ?\n", filename);
		return EXIT_FAILURE;
	}
	fseek(file, 0, SEEK_END);
	listlen = ftell (file);
	fseek(file, 0, SEEK_SET);
	char list[listlen];
	fread(list, 1, listlen, file);
	rewind(file);

	uint32_t numnames = get_num_names(file);
	data names[numnames+1];
	uint32_t offset = 0;

	for(uint32_t i = 0; i != numnames+1; i++){
		uint32_t j = offset;
		uint32_t beginstring = 0;
		while(j < listlen){
			if(list[j] == '\"'){
				if(list[j+1] != ',' && list[j+1] != '\0'){
					beginstring = ++j;
				} else {
					offset = j+1;
					break;
				}
			}
			j++;
		}

		names[i].lenght = j - beginstring;
		names[i].name = strndup(&list[beginstring], names[i].lenght);
		// this will be unset for now
		names[i].order = 0;
		names[i].score = 0;
		for(uint32_t k = 0; k != names[i].lenght; k++)
			// '@' is 'A'-1 because we should subtract 'A' and add one
			names[i].score += (names[i].name[k] - '@');
	}

	sort(names, numnames+1);
	uint64_t sum = 0;

	for(uint32_t i = 0; i != numnames+1; i++){
		names[i].order = i;
		names[i].score *= i;
		sum += names[i].score;
	}

	printf("the total of all the name scores in the file is %zu\n", sum);

	return EXIT_SUCCESS;
}
