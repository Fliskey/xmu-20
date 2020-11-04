#include <stdio.h>
#include <math.h>

int pdpl(int n){
	int pfg = sqrt(n);
	double lfg = pow(n,1.0/3);
	lfg += 0.00001;
	lfg = (int)lfg;
	if(pfg * pfg == n){
		if(pow(lfg,3) == n){
			return 1;
		}
	}
	return 0;
}

int main(){
	int n;
	int t;
	scanf("%d",&t);
	for(int j = 1; j <= t; j++){
		scanf("%d",&n);
		for(int i=2;i<=n;i++){
			if(pdpl(i)){
				printf("%d ",i);
			}
		}
		printf("-1\n");
	}
	return 0;
}
