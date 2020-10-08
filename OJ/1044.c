#include <stdio.h>
#define S(a,b,c) (a+b+c)/2
#define area(a,b,c) { double ss = S(a,b,c) ; double r = sqrt(ss*(ss-a)*(ss-b)*(ss-c)) ; printf("%.3f",r) ; }

int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	area(a,b,c);
	return 0;
}
