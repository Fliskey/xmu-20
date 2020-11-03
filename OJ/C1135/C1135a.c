#include <stdio.h>

int main(){
	char c;
	
	int bg = 0;
	int count = 0;
	int ccount = 0;
	
	while(scanf("%c",&c) != EOF){
		if(c == '#'){
			if(bg){
				printf("%d\n",count);
				bg = 0;
			}
			else{
				bg = 1;
				count = 0;
			}
		}
		else if(c!='\n' && c!=' ' && c!='\t'){
			ccount++;
		}
		else if(c == '\n'){
			if(ccount){
				count++;
				ccount = 0;
			}
		}
	}
	return 0;
} 
