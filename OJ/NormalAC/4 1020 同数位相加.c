#include <stdio.h>
#include <math.h>
int main(){
	int sum = 0;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x = 2*pow(10,i-1);
		x *= (n-i+1);
		sum += x;
	}
	printf("%d",sum);
	return 0;
}
