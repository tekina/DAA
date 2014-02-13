#include<stdio.h>
#include<stdlib.h>

typedef struct Point {
double x;
double y;
}point;

int fSize(FILE *f1);
void fRead(struct Point *p, FILE *f1, int size);

void main() {
	FILE *f1;
	int i, size;
	f1 = fopen("sample.txt","r");
	size = fSize(f1);
	size/=3;
	printf("%d\n",size);
	rewind(f1);
//	size  = 10;
	struct Point *pts = (struct Point*) malloc(sizeof(struct Point)*size);
	fRead(pts, f1, size);
}

int fSize(FILE *f1) {
	int size = 0;
	char str[30];	
	while(fscanf(f1, "%s", str) != EOF) {
		size++;
	}
	return size;
}

void fRead(struct Point *pts, FILE *f1, int size) {
	int i;
	double z;
	for(i=0;i<size;i++) {
		fscanf(f1, "%lf %lf %lf", &pts[i].x, &pts[i].y, &z);
	}
	for(i=0;i<size;i++) {
		printf("%lf %lf\n", pts[i].x, pts[i].y);
	}
}
