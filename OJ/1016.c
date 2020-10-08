#include <stdio.h>

int main(){
	char n[6];
	gets(n);
	int l = 0;
	for(int i=0;n[i] != '\0';i++){
		l++;
	}
	printf("%d\n",l);
	printf("%c",n[0]);
	for(int i=1;i<=l-1;i++){
		printf(" %c",n[i]);
	}
	printf("\n");
	for(int i=l-1;i>=0;i--){
		printf("%c",n[i]);
	}
	return 0;
}
