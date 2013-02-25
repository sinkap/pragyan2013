#include <math.h>
#include <stdlib.h>
#include <time.h>


int is_init = 0; 
int iset = 0; 
float gset = 0; 

void re_init() {

	is_init = 0; 
	iset = 0; 
	gset = 0; 
}




__inline__ void __init() {


	if (is_init == 0) {
		srand(10); 
		is_init = 1; 
	}
}


float __nrand() {

	return (float)(rand()) / (float) RAND_MAX;

}


float rexp(float __lambda) {


	
	return -((float)(1.0) / __lambda) * log(__nrand());


}

float normal(float mu, float sigma) {

	
	float u,v,rsq, fac; 

	if (iset == 0) {
		do {
			u = (2.0 * ((float) rand() / (float) RAND_MAX)) - 1.0;
			v = (2.0 * ((float) rand() / (float) RAND_MAX)) - 1.0;
			rsq = u*u + v*v; 
		}
		
		while (rsq >= 1.0 || rsq == 0.0); 

//Box Muller Transform..We have found the number in the unit cricle;

		fac = sqrtf(-2.0 * logf(rsq) / rsq); 
		gset = mu + (sigma * (u * fac)); 
		iset = 1 ; 
		return mu + (sigma * (v * fac)); 

	}
	
	else {
	
		iset = 0; 
		return gset; 
	}

}

float lognormal(float mu, float sigma) {
		
	return expf(normal(mu, sigma)); 

}

	



