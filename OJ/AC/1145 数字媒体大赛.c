#include <stdio.h>

int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		double a[104] = {0};
		
		double max = 0, min = 200000000;
		int maxl = 0, minl = 0;
		
		for(int i=1; i<=n; i++){
			scanf("%lf",&a[i]);
			if(a[i] > max){
				max = a[i];
				maxl = i;
			}
			if(a[i] < min){
				min = a[i];
				minl = i;
			}
		}
		double sum = 0;
		for(int i=1;i<=n;i++){
			if(i != maxl && i != minl){
				sum += a[i];
			}
		}
		sum /= (n-2);
		printf("%.2f\n",sum);
	}
	return 0;
} 
