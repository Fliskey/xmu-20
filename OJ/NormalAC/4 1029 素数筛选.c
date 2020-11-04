#include <stdio.h>

int ss(int x){
	int q = (int) sqrt(x);
	for(int i=2;i<=q;i++){
		if(x%i == 0){
			return 0;
		}
	}
	return 1;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 2; i <= n; i++){
		if(ss(i)){
			printf("%d\n",i);
		}
	}
	return 0;
}
