#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define FILENAME "./apache.log"
#define INTERVAL 120

#define FORMAT "%d:%H:%M:%S"


/* The main steps to parse the file are.
 * 
 * Open the file (Hint: man fopen)
 * 
 * Step 1:
 * 	
 *	 Read the file line by line (Think how?)
 * 
 * Step 2:
 *	 Use strtok to split the line read from the file (Hint: man strtok)
 * 
 * Step 3:
 * 	 Get the date and the number of bytes
 * 
 * Step 4: 
 *	Calculate the number of bytes received in a two minute window
 * 
 * (Have a look at the manpage for strptime)
 */

int main(void) {


	FILE* fp; 

	fp = fopen(FILENAME, "r"); 
	
	if (!fp) {
		printf("File: %s could no be opened\n", FILENAME); 
		return -1;
	}


	struct tm t;
	
	//Add the logic for parsing the file here.


}
	

