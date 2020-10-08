#include <stdio.h>

int main(){
	char c[20];
	gets(c);
	for(int i=0;c[i] != '\0'; i++){
		printf("%c",c[i]+4);
	}
	return 0;
}
