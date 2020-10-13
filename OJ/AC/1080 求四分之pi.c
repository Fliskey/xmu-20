#include <stdio.h>

int main(){
	int a = 1;
	double sum = 0;
	while(a < 1000000){
	//	printf("!");
		if( (a+1)/2 %2 == 1){
			sum += 1/(double)a;
		}
		else{
			sum -= 1/(double)a;
		}
		a += 2;
	}
	printf("%.6f",sum);
	return 0;
}
