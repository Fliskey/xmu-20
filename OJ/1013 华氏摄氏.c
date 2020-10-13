#include <stdio.h>

int main(){
	double f;
	scanf("%lf",&f);
	double c = f - 32;
	c *= 5;
	c /= 9;
	printf("c=%.2f",c);
	return 0;
}
