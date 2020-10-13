#include <stdio.h>

int swap(int *x,int *y){
	int i;
	i = *x;
	*x = *y;
	*y = i;
	return 1;
}

int main(){
	int a,b;
	while(scanf("%d %d",&a,&b) != EOF){
		swap(&a,&b);
		printf("%d %d\n",a,b);
	}
	
	return 0;
}
