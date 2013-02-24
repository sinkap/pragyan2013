#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "grapher.h"

/*


	The drunk is on a 2-D Cartesian plane whose coodinates are described using the "point" struct.

	Step 1:
		Generate a Random Number
	
	Step 2:
		Use the generated to select one of the four directions [ 'N', 'S', 'W', 'E' ]
	
	Step 3:
		Move the Drunkard in that direction.

	Step 4:
		Store the distances in an array and plot them



	How do I plot?
		
	graph_new(LINE, array, length_of_array, "legend=Drunk Walk, xlabel=Step Num, ylabel=Distance, title=Random Walk");
	graph_show(); 


	The next part of the exercise is to run the simulation 300 times and take the average value at each step.

	Some functions have been defined to help you, Although you may change the structure of the code, if you may deem necessary.


*/




struct point {

	float x; 
	float y; 
}; 




int getRandom() {
//This function should give you a random value between 0 to 3
//Hint: Use rand()

	return (rand() % 4) ;

}


void stepPoint(struct point* pt, char direction) {
//This function takes the point structure and changes the cartesian coordinates 
//according to the direction 


}

	


float getDistance(struct point pt) {
//Returns the caretsian distance
	
}




//A Trial means Each Walk of 500 steps.
//Return the distance in the floating poin array
struct point runTrial(int numSteps, float* distances) {


}

//This functions is to run the Walk and average it over a number of simulations 
//For example simualte(300, 500): Each walk will be of 500 steps, repeated 300 times.
//The average distance of each step has to be plotted
void simulate(int numSims, int numSteps) {


}





int main(void) {


	//Seed the Random number generator
	srand((unsigned)time(0)); 


	
	return 0; 

}
		

