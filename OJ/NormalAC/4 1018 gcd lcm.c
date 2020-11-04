//gcd lcm最小公倍数，最大公约数 
#include <stdio.h>

int gcd(int x,int y){
	if(x % y == 0){
		return y;
	} 
	else{
		return gcd(y,x%y);
	}
}

int lcm(int x,int y){
	return x*y/gcd(x,y);
}

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d %d",gcd(a,b),lcm(a,b));
	return 0;
}
