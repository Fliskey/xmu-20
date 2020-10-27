#include <stdio.h>

int main(){
	int n;
	int is_first = 1;
	while(scanf("%d",&n)!=EOF){
		if(n == 0){
			break;
		}
		double q;
		int fs = 0;
		int zr = 0;
		int zs = 0;
		for(int i=1;i<=n;i++){
			scanf("%lf",&q);
			if(q > 0){
				zs++;
			}
			else if(q == 0){
				zr++;
			}
			else if(q < 0){
				fs++;
			}
		}
		if(is_first){
			printf("%d %d %d",fs,zr,zs);
			is_first = 0;
		}
		else{
			printf("\n%d %d %d",fs,zr,zs);
		}
	}
	return 0;
}


