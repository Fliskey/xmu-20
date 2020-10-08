#include <stdio.h>

int charcp(char *a,char *b){
	int bl = 0;
	for(int i=0; a[i] != '\0'; i++){
		if(!bl){
			if(a[i] > b[i]){
				return 1;
			}
			else{
				if(a[i] < b[i]){
					return 0;
				}
			}
			if(b[i] == '\0'){
				bl = 1;
			}
		}
		else{
			return 0;
		}
	}
}//a´®>b´®·µ»Ø1 

int main(){
	char a[2333],b[2333];
	while(gets(a)){
		gets(b);
		printf("%d\n",charcp(a,b));
	}
}
