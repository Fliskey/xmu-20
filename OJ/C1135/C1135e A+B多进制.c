#include <stdio.h>
#include <string.h>
#include <math.h>


int nto10(int x,int n){
	int count = 0;
	int copyx = x;
	int ans = 0;
	while(copyx != 0){
		int q = copyx%10;
		ans += q * pow(n,count);
		
		count++;
		copyx /= 10;
	}
	return ans;
}

int ten2n(int x,int n){
	int copyx = x;
	int ans[40];
	int al = 0;
	
	while(copyx != 0){
		int q = copyx % n;
		copyx /= n;
		ans[al] = q;
		al++;
	}
	al--;
	for(int i=al ; i>=0 ; i--){
		printf("%d",ans[i]);
	}
	printf("\n");
}

int main(){
	
	int n;
	scanf("%d",&n);
	for(int i=1 ; i<=n ; i++){
		int a,b;
		int ax,bx,cx;
		scanf("%d %d %d %d %d",&a,&ax,&b,&bx,&cx);
		
		a = nto10(a,ax);
		b = nto10(b,bx);
		int c = a+b;
		
		ten2n(c,cx);
		
	}
	
	return 0;
}