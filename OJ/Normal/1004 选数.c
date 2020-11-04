#include <stdio.h>
#include <math.h>

int a[30];
int b[30];

int n,k;

int ss(int x){
	if(x == 0 || x == 1){
		return 1;
	}
	int q = (int) sqrt(x);
	for(int i=2;i<=q;i++){
		if(x%i == 0){
			return 0;
		}
	}
	return 1;
}

int suma = 0;
int sumb = 0;

int mj(int nw,int ni){
	if(nw == k){
		if(sumb % 2 == 1){
			if(ss(suma) == 1)
				return 1;
			else
				return 0;
		}
		if(suma == 2){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		int sumk = 0;
		for(int i=ni+1; i<=n-k+1+nw; i++){
			sumb += b[i];
			suma += a[i];
			sumk += mj(nw+1,i);
			sumb -= b[i];
			suma -= a[i];
		}
		return sumk;
	}
}

int main(){
	scanf("%d %d",&n,&k);

	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i] = a[i] % 2;
	}
	printf("%d",mj(0,0)); 
	
	return 0;
}
