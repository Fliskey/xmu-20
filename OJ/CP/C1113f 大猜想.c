#include <stdio.h>
//C1113f ´ó²ÂÏë
 
int main(){
	unsigned long long x;
	while(scanf("%lld",&x) != EOF){
		printf("%lld\n",x);
		unsigned long long times = 0;
		while(x != 1){
			if(x % 2){
				x *= 3;
				x++;
				times++;
			}
			else{
				x/=2;
				times++;
			}
		}
		printf("%lld\n",times);
	}
	return 0;
}
