#include <stdio.h>

int main(){
	int k[23]={0,1,2,2,2,2,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5};
	
	int n;
	scanf("%d",&n);
	
	int ans;
	
	if(n <= 3){
		if(n == 1)	ans = 0;
		if(n == 2)	ans = 1;
		if(n == 3)	ans = 1;
		printf("%d",ans);
		return 0;
	}
	
	n -= 4;
	int t = n/21;
	int base = 6*(t)+2;
	
	int m = n%21;
	
	ans = k[m] + base;
	printf("%d",ans);
	
	return 0;
}
