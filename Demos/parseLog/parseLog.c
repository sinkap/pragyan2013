#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define FILENAME "./apache.log"
#define ARR_LEN 1000
#define INTERVAL 120

#define FORMAT "%d:%H:%M:%S"

int main(void) {


	FILE* fp; 

	fp = fopen(FILENAME, "r"); 
	
	if (!fp) {
		printf("File: %s could no be opened\n", FILENAME); 
		return -1;
	}


	char buf[5000]; 
	float byteArray[ARR_LEN]; 
	int numIntervals = 0; 
	int bytes = 0; 
	int flag = 0; 
	unsigned long curr_offset = 0;
	unsigned long prev_offset = 0;
	struct tm t;
	

	char *token, *prev_token; 
	char delim[] = "[]";

	while(!feof(fp)){
		if(fgets(buf, 5000, fp) == NULL)
			break;

		token = strtok(buf, delim);
		token = strtok(NULL, delim);

		if (token == NULL)
			break; 

		strptime(token, FORMAT, &t);
		curr_offset = 3600 * t.tm_hour + 60 * t.tm_min + t.tm_sec;

		token = strtok(NULL, delim);
		token = strtok(token, " ");
		

		if((curr_offset - prev_offset) > INTERVAL) {
			flag = 1;
		}
				
		while(token != NULL) {
			prev_token = token;
			token = strtok(NULL, " ");
		} 				
		

		if(strcmp(prev_token, "-") != 0)
			bytes += atoi(prev_token);



		if(flag == 1) {

			printf("%d\n", bytes);
			byteArray[numIntervals] = bytes;
			bytes = 0;
			flag = 0;
			prev_offset = curr_offset;
			numIntervals += 1;
		}
	}


}
	

