#include <stdio.h>
#include <math.h>
#define PI 3.1415926536


int main(){
	double x,y,z;
	double r,h,t;
	while(scanf("%lf %lf %lf",&r,&h,&t) != EOF){
		x = r * sin(h*PI/180) * cos(t*PI/180);
		y = r * sin(h*PI/180) * sin(t*PI/180);
		z = r * cos(h*PI/180);
		printf("x = %.10f y = %.10f z = %.10f\n",x,y,z);
	}
	
	return 0;
}
