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
	if(ss(n)){
		printf("prime");
	}
	else{
		printf("not prime");
	}
	return 0;
}
