#ifndef GRAPHER_H
#define GRAPHER_H
#include <fcntl.h>
#include <stdio.h>
#define SCATTER 'S'
#define HIST 'H'
#define LINE 'L'
#define LINE_LOG_X 'X'
#define PLOT_CMD "../include/graph.py /tmp/graph.current" 


FILE* fp = NULL;
char path[] = "/tmp/graph.current";





void graph_init() {

	fp = fopen(path, "w+");

	if (fp == NULL) {
		printf("File Cretion error\n"); 
		exit(1); 
	}

	chmod(path, S_IRWXU); 
}

void graph_new(char type, float* buffer, int length, char* keyvals) {

	if (fp == NULL) 
		graph_init(); 	
	int i ; 

	switch(type) {

		case LINE:

			fprintf(fp, "line:"); 
			for (i = 0 ; i < length ; i++) {
				if (i == (length - 1)) 
					fprintf(fp, "%f", buffer[i]); 	
				else 
					fprintf(fp, "%f, ", buffer[i]); 	
					
			}

                        fprintf(fp, ":%s\n", keyvals);
			return;
		
		case LINE_LOG_X:
			fprintf(fp, "logx:"); 
			for (i = 0 ; i < length ; i++) {
				if (i == (length - 1)) 
					fprintf(fp, "%f", buffer[i]); 	
				else 
					fprintf(fp, "%f, ", buffer[i]); 	
					
			}

                        fprintf(fp, ":%s\n", keyvals);
			return;
		

		case HIST:

                        fprintf(fp, "hist:");
                        for (i = 0 ; i < length ; i++) {
                                if (i == (length - 1))
                                        fprintf(fp, "%f", buffer[i]);
                                else
                                        fprintf(fp, "%f, ", buffer[i]);

                        }
                        fprintf(fp, ":%s\n", keyvals);
                        return;


		default:
			printf("Invalid Graph type"); 
			exit(1); 


	}

}



void graph_xy(char type, float* buffer_x, float* buffer_y, int length, char* keyvals) {

	if (fp == NULL) 
		graph_init(); 	
	int i ; 

	switch(type) {

		case SCATTER:
			fprintf(fp, "scatter:"); 
			for (i = 0 ; i < length ; i++) {
				if (i == (length - 1)) 
					fprintf(fp, "%f", buffer_x[i]); 	
				else 
					fprintf(fp, "%f, ", buffer_x[i]); 
			}
			fprintf(fp,":");
			for (i = 0 ; i < length ; i++) {
				if (i == (length - 1)) 
					fprintf(fp, "%f", buffer_y[i]); 	
				else 
					fprintf(fp, "%f, ", buffer_y[i]); 
			}

                        fprintf(fp, ":%s\n", keyvals);

			return;


		default:
			printf("Invalid Graph type"); 
			exit(1); 


	}
}

void graph_show() {

	fclose(fp);
	system(PLOT_CMD); 
	fp = NULL;


}

#endif 


