#include <stdio.h>
#include <math.h>

int main(){
	double x;
	scanf("%lf",&x);
	double dt = 9999;
	double xn = x / 2;
	double w;
	while(dt > 0.00001){
		w = xn;
		xn = 0.5 * (xn + x / xn);
		dt = xn - w;
		if(dt < 0){
			dt = -dt;
		}
	}
	printf("%.3f",xn);
	return 0;
}
