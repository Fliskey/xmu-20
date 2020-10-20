#include <stdio.h>
#include <math.h>

int main(){
	int n;
	scanf("%d",&n);
	int p=0;
	double sum = 0;
	double m=1;
	for(int i=1;i<=n;i++){
		m *= i;
		while(m > 100000){
			m /= 10;
			sum /= 10;
			p++;
		}
		sum += m;
	//	if(sum > 100000){
	//		sum /= 10;
	//		p++;
	//	}
	}
//	while(sum > 100000){
//		sum /= 10;
//		p++;
//	}
	double ans = sum;
	while(ans > 10){
		ans /= 10;
		p++;
	}
	printf("%.3f x 10^(+%03d)",ans,p);
	return 0;
} 
