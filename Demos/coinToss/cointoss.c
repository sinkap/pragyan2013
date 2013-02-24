#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "grapher.h"


/*

	Step 1:
		Generate a random number to choose from head and tail

	Step 2:
		Each trial consists of tossing three such coins

	Step 3:
		Repeate/Simulate these trials a large number of times 
		to get deterministic results

	Step 4:
		Plot the results. You may use:
		graph_new(HIST, array, length_of_array, "xlabel=x, ylabel=y, title=chart, legend=value")


*/


int getRandom() {

	return (rand() % 2);

}
//This is the trial function
int tossCoins(int numCoins) {

	int iter, numHeads = 0, numTails = 0;
	
	for(iter = 0; iter < numCoins ; iter ++) {
		if (getRandom()) 
			numHeads += 1;
		else 
			numTails += 1;
	}

	return abs(numHeads - numTails); 
}


//We simulate the coin tosses a large number of times
void simulate(int numCoins, int numSims) {

	float result[numSims]; 
	int sim;

	for (sim = 0; sim < numSims; sim++) 
		result[sim] = (float) tossCoins(numCoins);


	graph_new(HIST, result, numSims, "xlabel=heads - tails, ylabel=value, title=Coin Toss Experiment"); 

	graph_show();

}
	
int main(void) {


	srand((unsigned)time(0));

	simulate(3, 4000);



}
