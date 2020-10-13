#include <stdio.h>

int main(){
	char c;
	while(scanf("%c",&c) != EOF){
		if(c != 10){
			int a = (int) c;
			int b = -1;
			int bk = 0;
			
			if( 65<=a && a<=90){
				c += 32;
				bk = 1;
			}
			if( 97<=a && a<=122){
				c -= 32;
				bk = 1;
			}
			
			if( 48<=a && a<=57){
				b = a-48+1;
				if(b == 10){
					b = 0;
				}
				bk = 1;
			}
			
			if(bk == 1){
				if(b != -1){
					printf("%d\n",b);
				}
				else{
					printf("%c\n",c);
				}
			}
			else{
				printf("%d\n",c);
			}	
		}
	}
	
	return 0;
} 
