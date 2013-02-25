#include <stdio.h>
#include "distribution.h"
#include "grapher.h"
#define POINTS 10000

int main(void) {

   float data[POINTS];
   int i;
   for (i = 0; i < POINTS; ++i) {

       //Generate a normal random variate with 
       //mean = 0 and standard deviation = 1
 
       data[i] = normal(0.0, 1.0);

   }

   graph_init();
   graph_new(HIST, data, POINTS, "xlabel=value,ylabel=prbability,title=Normal Distribution"); 
   graph_show();

}
