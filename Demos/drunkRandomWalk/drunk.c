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


void stepPoint(struct point* pt, char direction, char opt) {
//This function takes the point structure and changes the cartesian coordinates 
//according to the direction 


	switch(direction) {
		
		case 'N':
			if(opt == 'B')
				pt->y += 2; 
			else
				pt->y += 1; 
			return; 

		case 'S':
			pt->y -= 1; 
			return ;
		case 'E':
			pt->x += 1; 
			return; 
		case 'W':
			pt->x -= 1; 
			return; 
		default:
			printf("error\n");
			exit(1); 
	}

}

	


float getDistance(struct point pt) {
//Returns the caretsian distance
	
	return sqrtf(pt.x * pt.x + pt.y * pt.y); 

}





struct point runTrial(int numSteps, float* distances, char opt) {

	int step; 
	struct point xy;

	xy.x = 0.0;
	xy.y = 0.0; 
	
	char directions[] = { 'N' , 'S' , 'W' , 'E' }; 
	char direction ;
	for (step = 0; step < numSteps; step++) {

		if(opt == 'L'){
			direction = 'N';
			while (((direction == 'N') || (direction == 'S')))
				direction = directions[getRandom()];
		}
		else
			direction = directions[getRandom()];


		stepPoint(&xy, direction, opt);

		distances[step] += getDistance(xy); 

		
	}
	

	return xy;

}


void simulate(int numSims, int numSteps) {

	int sim; 
	float lastPointX[numSims]; 
	float lastPointY[numSims];
	float average[numSteps];
	memset(average,0,numSteps * sizeof(float));
	int step;


	for (sim = 0; sim < numSims; sim++) {
			
		struct point final_xy; 
		final_xy = runTrial(numSteps, average, 'U'); 

		//Add to the average array
		
		lastPointX[sim] = final_xy.x;
		lastPointY[sim] = final_xy.y;
	

	}
	
	for (step=0; step < numSteps; step++) 
		average[step] = average[step] / (float) numSims;
	graph_new(LINE, average, numSteps, "legend=Unbiased Walk,title=Repititive Simulations,xlabel=Step Number,ylabel=Distance(averaged)");
	graph_xy(SCATTER,lastPointX,lastPointY, numSims, "legend=End Points(Unbiased Walk), title=Last Point in each Trial, xlabel=x-coordinate, ylabel=y-coordinate");


	printf("Final Distance UnBiased:%f\n", average[numSteps - 1] );

}


void simulateBiased(int numSims, int numSteps) {

        int sim;
        float lastPointX[numSims];
        float lastPointY[numSims];
        float average[numSteps];
        memset(average,0,numSteps * sizeof(float));
        int step;


        for (sim = 0; sim < numSims; sim++) {

                struct point final_xy;
                final_xy = runTrial(numSteps, average, 'B');

                //Add to the average array

                lastPointX[sim] = final_xy.x;
                lastPointY[sim] = final_xy.y;


        }

        for (step=0; step < numSteps; step++)
                average[step] = average[step] / (float) numSims;
        graph_new(LINE, average, numSteps, "legend=Biased Walk,title=Repititive Simulations,xlabel=Step Number,ylabel=Distance(averaged)");
        graph_xy(SCATTER,lastPointX,lastPointY, numSims, "legend=End Points(Biased Walk), title=Last Point in each Trial, xlabel=x-coordinate, ylabel=y-coordinate");

	printf("Final Distance Biased:%f\n", average[numSteps - 1] );
}

void simulateEW(int numSims, int numSteps) {

        int sim;
        float lastPointX[numSims];
        float lastPointY[numSims];
        float average[numSteps];
        memset(average,0,numSteps * sizeof(float));
        int step;


        for (sim = 0; sim < numSims; sim++) {

                struct point final_xy;
                final_xy = runTrial(numSteps, average, 'L');

                //Add to the average array

                lastPointX[sim] = final_xy.x;
                lastPointY[sim] = final_xy.y;


        }

        for (step=0; step < numSteps; step++)
                average[step] = average[step] / (float) numSims;
        graph_new(LINE, average, numSteps, "legend=EW Walk,title=Repititive Simulations,xlabel=Step Number,ylabel=Distance(averaged)");
        graph_xy(SCATTER,lastPointX,lastPointY, numSims, "legend=End Points(EW Walk), title=Last Point in each Trial, xlabel=x-coordinate, ylabel=y-coordinate");
	printf("Final Distance EW:%f\n", average[numSteps - 1] );

}


int main(void) {


	//Seed the Random number generator
	srand((unsigned)time(0)); 
	int i,j ; 
	struct point pt; 
	float distances1[500] = {0}; 
	float distances2[500] = {0};
	//Two Random Walks

	runTrial(500, distances1, 'U'); 
	graph_new(LINE, distances1, 500, "legend=1st Walk, xlabel=Step Number, ylabel=Distance from the origin"); 
	
	runTrial(500, distances2, 'U'); 
	graph_new(LINE, distances2, 500, "legend=2nd Walk, xlabel=Step Number, ylabel=Distance from the origin, title=2 Random Walks");
	graph_show(); 
	

	//Simulate 300 Random Walks with 500 steps each
	simulate(300,500); 
	simulateEW(300,500);
	simulateBiased(300,500);
	graph_show();



	
	return 0; 

}
		

