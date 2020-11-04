#include <stdio.h>
#define swap(a,b) (a = a^b , b = a^b , a = a^b)
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a>b)	swap(a,b);
	if(b>c)	swap(b,c);
	if(a>b)	swap(a,b);
	printf("%d %d %d ",a,b,c);
	return 0;
}
