#include <stdio.h>
#define ys(x,y) x%y

int main(){
	int x,y;
	scanf("%d %d",&x,&y);
	int yy = ys(x,y);
	printf("%d",yy);
	return 0;
}
