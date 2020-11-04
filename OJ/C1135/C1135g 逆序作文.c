#include <stdio.h>

int main(){
	
	char c;
	int bgin = 0;
	int stk[1000];//stack
	int sl = 0;
	
	
	while(scanf("%c",&c) != EOF){
		if(bgin){
			if(c != '#'){
				if(c==' ' || c=='\n' || c=='\t'){//pop stack
					sl--;
					while(sl >= 0){
						printf("%c",stk[sl]);
						sl--;
					}
					sl = 0;
					printf("%c",c);
				}
				else if(c == '\n'){
					printf("\n");
					sl = 0;
				}
				else{//push stack
					stk[sl] = c;
					sl++;
				}
			}
			else{
				bgin = 0;
			}
		}
		else{
			if(c == '#'){
				scanf("%c",&c);
				bgin = 1;
			}
		}
	}
	return 0;
}