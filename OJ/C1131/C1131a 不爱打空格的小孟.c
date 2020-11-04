//C1113a 不爱打空格的小孟 

#include <stdio.h>

char c[20];

int main(){
//	freopen("in.txt","r",stdin);
	while(scanf("%s",&c) != EOF){
		for(int i=0;i<=2;i++){
			printf("%c",c[i]);
		}
		
		printf(" ");
		
		for(int i=3;i<=4;i++){
			printf("%c",c[i]);
		}
		
		printf(" ");
		
		for(int i=5;i<=9;i++){
			printf("%c",c[i]);
		}
		
		printf("\n");
	}
	return 0;
} 
