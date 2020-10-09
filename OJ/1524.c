#include <stdio.h>
#include <math.h>

int main(){
	int x;
	scanf("%d",&x);
	double qx = sqrt(x);
	double qf = floor(qx);
	if(qx == qf){
		printf("y");
	}
	else{
		printf("n");
	}
	return 0;
} 
