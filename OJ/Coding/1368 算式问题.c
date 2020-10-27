#include <stdio.h>
//1368 ËãÊ½ÎÊÌâ

int main(){
	const int ans = 809;
	int i = 12;
	int x = i*809+1;
	if(x>=1000 && x<=9999){
		if(i*8 < 100){
			int p = i*8;
			int q = x/100;
			q -= p;
			if(q < 10){
				q *= 100;
				q += x%100;
				printf("%d\n%d\n%d\n%d\n%d",i,x,p,q,q-1);
			}
		}
	}
	return 0;
} 
