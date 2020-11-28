#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
	double n;
	/*
	scanf("%lf",&n);
	printf("%.0f",n);
	*/
	double index[10004];
	memset(index,0,sizeof(index));
	
	for(double i=2;i<=10000;i+=1){
		double temp = pow(i,3);
		
		double temp1 = temp+2;
		double qr1 = sqrt(temp1)+0.00000001;
		double fl1 = floor(qr1);
		if(qr1 - fl1 < 0.000001){
			printf("%.0f\n",temp+1);
		}
		
		double temp2 = temp-2;
		double qr2 = sqrt(temp2)+0.00000001;
		double fl2 = floor(qr2);
		if(qr2 - fl2 < 0.000001){
			printf("%.0f\n",temp-1);
		}
	}
	return 0;
}
