//多少个平方数 
#include <stdio.h>
#include <math.h>

int pfs(int x){
	double q = sqrt(x);
	double qf = floor(q);
	return (q == qf);
}

int bx[32790];
int bl = 0;

int main(){
	for(int i=1;i<=32770;i++){
		bx[bl] = i*i;
		bl++;
	}
	int n;
	while(scanf("%d",&n) != EOF){
		int sum = 0;
		
		for(int i=0;i<bl && sum == 0;i++){
			if(n < bx[i]){
				sum = i;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
