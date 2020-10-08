#include <stdio.h>
#include <math.h>
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	double sum = 0;
	for(int i=1;i<=a;i++){
		sum += i;
	}
	for(int i=1;i<=b;i++){
		sum += pow(i,2);
	}
	for(int i=1;i<=c;i++){
		sum += pow(i,-1);
	}
	printf("%.2f",sum);
	return 0;
}
