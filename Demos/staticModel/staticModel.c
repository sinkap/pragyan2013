#include <stdio.h>
#include "distribution.h"
#define FILENAME "./network.log"
#define LENGTH 1000
#include "grapher.h"

/* To generate the exponentially dsitributed data we read the raw data generated in 
 * previous exercise (parseLog)
 * 
 * We calculate the rate parameter of the exponential distribution as
 * 
 * We also plot the histogam of the raw data to affirm that we have an exponential distribution.
 * 
 *
 *              --
 *    lambda =  \   a(n)
 *  	        /_
 *	       ----------
 *		    n
 * 
 * or simply the average of your data. 
 *
 * 
 *
 *  We then use this lambda parameter to generate a exponential distribution similar to our traffic log.
 *
 *  We then also plot the distibution we generated and compare it with the actual data.
 * 
 */




int main(void) {



	char _readBuf[100];
	FILE* fp;
	fp = fopen(FILENAME, "r");
	int count = 0;
	int i;

	//Arrays to store raw and generated data
	float rawData[LENGTH];
	float genData[LENGTH];

	float total = 0.0; 
	float max = 0.0; 
	float lambda;


	//Reading the raw data and storing it an array.
	
	while(!feof(fp)){

		fgets(_readBuf,100, fp); 
		rawData[count] = atof(_readBuf) / (float) 1024.0;
		total += rawData[count];
		++count; 
	}
	
	graph_init(); 
	graph_new(HIST, rawData, count, "ylabel=probability,xlabel=Request Size(KB), title=Raw Data Distribution"); 
	graph_show(); 	

	//Plot the actual distibution of the raw data

	lambda = total / (float) count; 


	//Generate the exponential distribution based on the data
	for (i = 0; i < count; ++i)
		genData[i] = rexp(1.0 / lambda);
	

	graph_new(HIST, rawData, count, "ylabel=probability,xlabel=Request Size(KB), title=Raw Data Distribution"); 
	graph_new(HIST, genData, count, "ylabel=probability,xlabel=Request Size(KB), title=Raw Data Distribution"); 
	graph_show();
	graph_new(LINE, genData, count, "ylabel=probability,xlabel=Request Size(KB), title=Raw Data Distribution"); 
	graph_new(LINE, rawData, count, "ylabel=probability,xlabel=Request Size(KB), title=Raw Data Distribution"); 
	graph_show();
}
