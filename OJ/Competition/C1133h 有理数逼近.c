#include <stdio.h>
#include <math.h>
//1133h

int gcd(int x,int y){
	if(y == 0){
		return x;
	}
	else{
		return gcd(y,x%y);
	}
}

int main(){
	int p,n;
	int count = 0;
	while(scanf("%d %d",&p,&n) != EOF){
		double l=0, r=90000;
		int l1,l2,r1,r2;
		
		double sp = sqrt(p);
		int spl = floor(sp);
		int spr = ceil(sp);
	//	printf("%d %d\n",spl,spr);
		
		for(double i=1 ; i<=n ; i++){
			int jl = floor((i-1)/spl) +1;
			int jr = floor(i/spr);
			for(double j=jr ; j<=jl ; j++){
				if(j == 0){
					continue;
				}
				double value = i/j;
			//	printf("%.0f %.0f %.2f %.2f\n",i,j,sp,value);
				if(value > sp){
				//	printf("v:%.2f r:%.2f\n",value,r);
					if(value <= r){
						r = value;
						r1 = i;
						r2 = j;
					}
				}
				if(value < sp){
				//	printf("v:%.2f l:%.2f\n",value,l);
					if(value >= l){
						l = value;
						l1 = i;
						l2 = j;
					}
				}
			}
		}
		//consider the yuefen problem: 
		int gl = gcd(l1,l2);
		l1 /= gl;
		l2 /= gl;
		int gr = gcd(r1,r2);
		r1 /= gr;
		r2 /= gr;
		
		printf("%d/%d %d/%d\n",l1,l2,r1,r2);
	}
	return 0;
} 
