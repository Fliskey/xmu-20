#include <stdio.h>
//#define swap(a,b) (a = a^b , b = a^b , a = a^b)
#define max3(a,b,c) { double max = a; if(b > max) max = b; if(c > max) max = c; printf("%.3f",max); }

double max33(double a,double b,double c){
	double max = a;
	if(b > max){
		max = b;
	}
	if(c > max){
		max = c;
	}
	return max;
}

int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	max3(a,b,c);
	printf("\n");
	printf("%.3f",max33(a,b,c));
	return 0;
}
