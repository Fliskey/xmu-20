#include <stdio.h>
//C1133a µ¹Èý½ÇÐÎ 

int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		int k = n;
		while(k != 0){
			for(int i=1;i<=n-k;i++){
				printf(" ");
			}
			for(int i=1;i<=k;i++){
				printf("*");
			}
			for(int i=1;i<=k-1;i++){
				printf("*");
			}
			printf("\n");
			k--;
		}
	}
	return 0;
}
