#include <stdio.h>
#include "distribution.h"
#include "grapher.h"
#define POINTS 10000

int main(void) {

   float data[POINTS];
   int i;
   for (i = 0; i < POINTS; ++i) {

       //Generate a exponential random variate with lambda as the rate parameter
 
       data[i] = rexp(0.5);
       

   }
   graph_init();
   graph_new(HIST, data, POINTS, "xlabel=value,ylabel=prbability,title=Exponential Distribution"); 
   graph_show();
}
