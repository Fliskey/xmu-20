#include <stdio.h>

short int fbnq[10004];
int xh[10004][10004] ;

int main(){
	memset(xh,0,sizeof(xh));
	int a,b,c;
	a = 0;
	b = 1;
	
	for(int i=2;i<=1000000000;i++){
		c = a+b;
		c %= 10000;
		printf("%d:%d\n",i,c); 
		a = b;
		b = c;
		if(xh[a][b]){
			printf("循环!\n",i,xh[b][c]);
			break;
		}
		else{
			xh[a][b] = i;
		}
	}
	
	printf("%d",c);
	return 0;
}