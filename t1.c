#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct Point {
double x;
double y;
}point;

int fSize(FILE *f1);
void fRead(struct Point *p, FILE *f1);
int minX(struct Point *pts);
int orientation(struct Point *pts, int p, int q, int r);
void convexHull(struct Point *pts);
void printResult(struct Point *pts);

int size;	//stores the total no. of points in the input file
int ans[4743433];
int index = 0;

void main() {
	FILE *f1;
	int i;
	f1 = fopen("test.txt","r");
	size = fSize(f1);
	size/=3;
	printf("%d\n",size);
	rewind(f1);
	struct Point *pts = (struct Point*) malloc(sizeof(struct Point)*size);
	fRead(pts, f1);
	convexHull(pts);
	printResult(pts);

}

//scans the file to find the total no. of points
int fSize(FILE *f1) {
	char str[30];	
	while(fscanf(f1, "%s", str) != EOF) {
		size++;
	}
	return size;
}

//reads from sample.txt and stores points in pts array
void fRead(struct Point *pts, FILE *f1) {
	int i;
	double z;
	for(i=0;i<size;i++) {
		fscanf(f1, "%lf %lf %lf", &pts[i].x, &pts[i].y, &z);
	}
}

//finds the min. value of X coordinate
int minX(struct Point *pts) {
	int i, min = 0;
	for(i=1;i<size;i++) {
		if(pts[i].x<pts[min].x) {
			min = i;
		}
	}
return min;
}

int orientation(struct Point *pts, int p, int q, int r) {
	 int val = (pts[q].y - pts[p].y) * (pts[r].x - pts[q].x) - (pts[q].x - pts[p].x) * (pts[r].y - pts[q].y);
 
    	if (val==0) return 0;  // colinear
	else if(val>1) return 1; //clockwise
	else return 2;		//counter clockwise
}

void convexHull(struct Point *pts) {
	int min = minX(pts);
	int i, p = min, q;
	do {
		q = (p+1)%size;
		for(i=0;i<size; i++) {
			if(orientation(pts,p,i,q)==2) {
				q = i;
			}
		}
	ans[index] = q;
	index++;	
        p = q; // Set p as q for next iteration
	} while(p!=min);
}

void printResult(struct Point *pts) {
	int i;
	printf("Solution:\n");
	for(i=0;i<index;i++) {
		printf("%lf %lf\n", pts[ans[i]].x, pts[ans[i]].y);
	}
	printf("%d\n", index);
}




