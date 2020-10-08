#include <stdio.h>
int main(){
	int x,y;
	scanf("%d %d",&x,&y);
	int m,h;
	m = y%100 - x%100;
	h = y/100 - x/100;
	if(m < 0){
		m += 60;
		h--;
	}
	printf("The train journey time is %d hours %d minutes.",h,m);
	return 0;
} 
