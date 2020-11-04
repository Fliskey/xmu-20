#include <stdio.h>
int main(){
	char s[256] = {0};
	gets(s);
	int n;
	for(int i=255;i>=0;i--){
		if(s[i]){
			n = i;
			break;
		}
	}
	for(int i=0;i<=n;i++){
		if(s[i]<'0'||s[i]>'9')
			if(s[i] != ' ')
				printf("%c",s[i]);
	}
	return 0;
} 
