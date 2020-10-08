#include <stdio.h>
#define ull unsigned long long 
int main(){
	ull sum = 0;
	ull p = 1;
	int n;
	scanf("%d",&n);
	for(int i=1 ; i<=n ; i++){
		p *= i;
		sum += p;
	}
	printf("%lld",sum);
	return 0;
}
