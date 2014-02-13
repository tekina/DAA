/*
 * @author:Aniket Garg
 *
 */

#include<stdio.h>
#include<stdlib.h>

#define SIZE 500 

struct point {
double x;
double y;
};

void disp(struct point test[SIZE]) {
    	double z, minX;
	FILE *fi;
    	fi = fopen("sample.txt","r");
    	int i;
	minX = test[0].x;
    	for(i=0;i<SIZE;i++) {
        	fscanf(fi,"%lf %lf %lf", &test[i].x, &test[i].y, &z);
		if(test[i].x<minX) minX = test[i].x;
    	}
       	printf("Minimum X oordinate: %f\n",minX);
}

void main() { 
    	struct point test[SIZE];
    	//test[10] = (struct point*) malloc(sizeof(struct point));
    	printf("working1\n");
    	disp(test);
    	printf("working2\n");
}
