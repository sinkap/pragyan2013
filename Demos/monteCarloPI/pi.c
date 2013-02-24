#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "grapher.h"
#define NUM_THROWS 3000

/*

	Step1:
		Choose two random numbers between 0 and 1. 
		Remeber they are not discrete
		(HINT: The maximum random number is RAND_MAX)
		
	Step2:
		Calculate the distance from (0,0)


	Step3: 

		Calculate the ratio


		(pointsInside) / (totalPoints)


		4 times the ratio is PI.


	

*/

//get a random number bewteen 0 and 1 
float getRandom(void) {

	float val = (float) rand() / (float) RAND_MAX; 
	return val;
}

//get the distance from the origin
float getDistance(float x,float y) {

	return sqrtf(x*x + y*y); 

}


int main(void) {


	float result[NUM_THROWS]; 
	int throw=0, numInside = 0; 	

	float x,y;

	for (throw = 0; throw < NUM_THROWS; ++throw) {

		x = getRandom();
		y = getRandom(); 

		if (getDistance(x,y) <= 1.0) 
			numInside += 1; 
		
		result[throw] = ((float) 4 * (float) numInside)/ (float) (throw + 1);

	}


	printf("The value of PI computed is %f\n", result[NUM_THROWS - 1]); 


	graph_new(LINE_LOG_X, result, NUM_THROWS, "title=Monte Carlo (PI), xlabel=Num of iterations, ylabel=PI"); 

	graph_show(); 


}
	





