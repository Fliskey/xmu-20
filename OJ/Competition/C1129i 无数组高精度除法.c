#include <stdio.h>
#define ULL unsigned long long

int main(){
	ULL a,b,zs;
	int c;
	while(scanf("%ld %ld %d",&a,&b,&c) != EOF){
		//输出整数部分 
		zs = a/b;
		a %= b;
		printf("%ld",zs);
		
		//若小数位为0则直接跳到下一组数据 
		if(c == 0)
		{
			printf("\n");
			continue;
		}
		printf(".");
		
		//输出小数位 
		while(c != 0){
			a *= 10;
			zs = a/b;
			
			printf("%ld",zs);
			
			a %= b;
			c--;
		}
		
		printf("\n");
	}
	return 0;
}
