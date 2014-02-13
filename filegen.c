#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    srand((unsigned int)time(NULL));

    double a = 500.0;
    FILE *fo = fopen("test.txt", "w");
    int i;
    for (i=0;i<1000;i++)
    	fprintf(fo,"%lf ", ((double)rand()/(double)(RAND_MAX)) * a);
	fprintf(fo,"%lf ", ((double)rand()/(double)(RAND_MAX)) * a);
	fprintf(fo,"%lf", ((double)rand()/(double)(RAND_MAX)) * a);
	fprintf(fo,"\n");
    fclose(fo);
    return 0;
}
