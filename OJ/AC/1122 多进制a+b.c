#include <stdio.h>
#include <math.h>

int n2d(int n,int x){
	int ans = 0;
	int i = 0;
	while(x != 0){
		ans += x%10 * pow(n,i);
		x/=10;
		i++;
	}
	return ans;
}

int xt5(int x){
	int ans = 0;
	int i = 0;
	int y = x;
	while(y != 0){
		ans += y%5 * pow(10,i);
		i++;
		y/=5;
	}
	return ans;
}

int main(){
	int a,b;
	while(scanf("%d %d",&a,&b) != EOF){
		int ax = n2d(2,a);
		int bx = n2d(7,b);
		int sum = ax + bx;
		printf("%d\n",xt5(sum));
	}
	return 0;
}
