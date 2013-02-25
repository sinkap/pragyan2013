#include <stdio.h>
#include "distribution.h"
#include "grapher.h"
#define POINTS 10000



int main(void) {

   float data[POINTS];
   int i;
   for (i = 0; i < POINTS; ++i) {

       //Generate a lognormal random variate with underlying normal parameters as
       //mean = 0 and standard deviation = 1
 
       data[i] = lognormal(1.0, 0.5);
       

   }

   graph_init();
   graph_new(HIST, data, POINTS, "xlabel=value,ylabel=prbability,title=Lognormal Distribution"); 
   graph_show();


}
