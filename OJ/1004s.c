#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ss(int x){
	int q = (int) sqrt(x);
	for(int i=2;i<=q;i++){
		if(x%i == 0){
			return 0;
		}
	}
	return 1;
}

int count = 0;
int n,k;
int a[];
int sum = 0;

int tsum(int nw,int l){ //nw为当前已选个数，l为当前位置 
	if(nw == k){
		if(ss(sum)){
			count++;
		}
		return 0;
	}
	else{
		for(int i = l+1; i<n-k+nw+1; i++){
			sum += a[i];
			tsum(nw+1,i);
			sum -= a[i];
		}
	}
}

int main(){
	scanf("%d %d",&n,&k);
	int* a = malloc (n*sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	tsum(0,-1);
	printf("%d",count);
	return 0;
}
