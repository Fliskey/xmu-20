#include <stdio.h>
#include <math.h>
int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		int q = sqrt(n);
		if(q * q == n){
			printf("y\n");
		}
		else{
			printf("n\n");
		}
	}
	return 0;
}
