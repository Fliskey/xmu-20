#include <stdio.h>

int main(){
	int x;
	scanf("%d",&x);
	int y;
	if(x<1){
		y = x;
	}
	if(1<=x && x<10){
		y = 2*x - 1;
	}
	if(10<=x){
		y = 3*x - 11;
	}
	printf("%d",y);
	return 0;
}
