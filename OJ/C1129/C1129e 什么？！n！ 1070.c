#include <stdio.h>

int countx(int x){
	int n=1;
	if(x>=25){
		printf("000000\n");
	}
	else{
		for(int i=1;i<=x;i++){
			n = (n%1000000) * i;
		}
		n %= 1000000;
		printf("%06d\n",n);
	}
}

int main(){
	int x;
	while(scanf("%d",&x)!=EOF){
		countx(x);
	}
	return 0;
} 
