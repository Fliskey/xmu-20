#include <stdio.h>
int main(){
	double a = 2,b = 1;
	int n;
	scanf("%d",&n);
	double sum = 0;
	for(int i=1;i<=n;i++){
		sum += a/b;
		int c = a;
		a += b;
		b = c; 
	}
	printf("%.2f",sum);
	return 0;
}
