#include <stdio.h>
#include <math.h>
//C1133e µÈ²îÊıÁĞ 

int ss(int x){
//	if(x == 0 || x == 1){
//		return 0; 
//	} 
	for(int i=2;i<=(int)sqrt(x);i++){
		if(x % i == 0){
			return 0;
		}
	}
	return 1;
}

int sss(int x,int y,int z){
	int a = x;
	int d = y;
	int n = z;
	int count = 1; 
	while(count < n){
		a += d;
		if(ss(a)){
			count++;
		}
	}
	printf("%d\n",a);
}
		
int main(){
	int a,d,n;
	while(scanf("%d %d %d",&a,&d,&n) != EOF){
		if(n == 0){
			continue;
		}
		sss(a,d,n);
	}
	return 0;
}
