#include <stdio.h>
//1230 小政学递归

int n;

long long dp(int x){
	if(x == 0){
		return 1;
	}
	else{
		//前半层 
		for(int i=n;i>=x+2;i--){
			printf("%d*(",i);
		}
		if(x+1 <= n){
			printf("%d*fun(%d)",x+1,x);
		}
		else{
			printf("fun(%d)",x);
		}
		for(int i=2;i<=n-x;i++){
			printf(")");
		}
		printf("\n");
		
		
		unsigned long long a = dp(x-1);
		
		//后半层 
		for(int i=n;i>=x+2;i--){
			printf("%d*(",i);
		}
		if(x+1 <= n){
			printf("%d*%llu",x+1,a*x);
		}
		else{
			return x*a;
		}
		for(int i=2;i<=n-x;i++){
			printf(")");
		}
		printf("\n");
		return x*a;
	}
}

int main(){
	while(scanf("%d",&n) != EOF){
		if(n == 0){
			printf("fun(0)\n1\n");
			continue;
		}
		printf("%llu\n",dp(n));
	}
	return 0;
}
