#include <stdio.h>
#include <math.h>
int pd(int x){
	int a,b,c;
	a = x/100;
	b = x/10%10;
	c = x%10;
	int s = 0;
	s += a*a*a;
	s += b*b*b;
	s += c*c*c;
	if(s == x){
		return 1;
	}
	return 0;
}
int main(){
	int m = 100,n = 999;
//	while(scanf("%d %d",&m,&n) != EOF){
		int cz = 0;
		for(int i=m; i<=n; i++){
			if(pd(i)){
			//	if(cz == 0){
				//	cz = 1;
					printf("%d\n",i);
			//	}
			//	else{
				//	printf(" %d",i); 
			//	}
			}
		}
		if(cz == 0){
			printf("no");
		}
		printf("\n");
//	}
	return 0;
}
