#include <stdio.h>

int main(){
	
	int fbnq[15004];
	fbnq[0] = 0;
	fbnq[1] = 1;
	
	for(int i=2;i<=15000;i++){
		fbnq[i] = fbnq[i-1] + fbnq[i-2] ;
		fbnq[i] %= 10000;
	}
	
	int n;
	
	while(scanf("%d",&n) && n!=-1){
		n %= 15000;
		printf("%d\n",fbnq[n]);
	}
	
	return 0;
}