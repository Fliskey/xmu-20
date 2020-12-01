#include <stdio.h>

int main(){
	
	int n;
	scanf("%d",&n);
	char c;
	int wait = -1;
	while(scanf("%c",&c) != EOF){
		if(n == 0){
			break;
		}
		if(c == '\n' || c=='\r'){
			if(wait >= 0){
				if(wait %2 == 0){
					printf("even\n");
				}
				else{
					printf("odd\n");
				}
				wait = -1;
				n--;
			}
		}
		if(c >= '0' && c <= '9')
			wait = c-'0';
	}
	if(n != 0){
		if(wait >= 0){
			if(wait %2 == 0){
				printf("even\n");
			}
			else{
				printf("odd\n");
			}
			wait = -1;
			n--;
		}
	}
	return 0;
} 
