#include <stdio.h>

int main(){
	int a,b,c;
	while(scanf("%d %d %d",&a,&b,&c) == 3){
		double sum = 0;
		sum = a+b+c;
		sum /= 3;
		sum += 0.0000001;
		printf("%.3f\n",sum);
	}
	return 0;
}
