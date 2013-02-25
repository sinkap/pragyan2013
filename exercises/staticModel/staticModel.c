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



	//Plot the raw data histogram 



	//Calculate the lambda or the rate parameter

	//generate exponential random numbers


	//Plot a comparison of the raw and generated distibution 
	//Plot a comparison of the raw and generated data





}
