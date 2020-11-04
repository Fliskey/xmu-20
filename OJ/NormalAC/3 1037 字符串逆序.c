#include <stdio.h>
int main(){
	char a[23333];
	gets(a);
	int l;
	for(int i=0; a[i] != '\0'; i++){
		l = i;
	}
	for(int i = l;i>=0;i--){
		printf("%c",a[i]);
	}
	return 0;
}
