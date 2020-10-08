#include <stdio.h>
int main(){
	char a[23333];
	char b[23333];
	gets(a);
	gets(b);
	printf("%s%s",a,b);
	return 0;
}
