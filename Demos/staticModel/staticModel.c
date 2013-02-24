#include <stdio.h>
#include "distribution.h"



int main(void) {



	char buf[100];
	FILE* fp;
	fp = fopen("./foo", "r");
	int count = 0;
	int i;
	float data[5000];
	float total = 0.0; 
	float max = 0.0; 
	float lambda;
	
	while(!feof(fp)){

		fgets(buf,100, fp); 
		data[count] = atof(buf) / (float) 1024.0;
		total += data[count];
		++count; 
	}
	

	
	lambda = total / (float) count; 

	for (i = 0; i < count; ++i)
		printf("%f\n",rexp(1.0 / lambda)); 
	

}
