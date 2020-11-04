#include <stdio.h>

void swap(int *a,int *b){
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

int main(){
	int a,b,c,d;
	while(scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF){
		if(b>a){
			swap(&a,&b);
		}
		if(c>b){
			swap(&b,&c);
		}
		if(d>c){
			swap(&c,&d);
		}
		
		
		if(b>a){
			swap(&a,&b);
		}
		if(c>b){
			swap(&b,&c);
		}
		
		
		if(b>a){
			swap(&a,&b);
		}
		
		printf("%d %d %d %d\n",a,b,c,d);
		
	}
	
	return 0;
}
