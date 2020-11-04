#include <stdio.h>
#define swap(a,b) (a = a^b, b = a^b, a = a^b)

int main(){
	int x,y;
	scanf("%d %d",&x,&y);
	swap(x,y);
	printf("%d %d",x,y);
	return 0;
}
