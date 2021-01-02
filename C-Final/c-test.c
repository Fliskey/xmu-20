#include <stdio.h>

int main(){
	freopen("in.txt","w",stdout);
	srand(time(0));
	int t = 100;
	for(int q=1;q<=t;q++){
		int n = rand()%3+1;
		for(int i=1;i<=n;i++){
			int s = rand()%3+1;
			printf("0%d",s);
			int m = rand()%100;
			printf("%02d",m);
			printf(" ");
		}
		printf("\n"); 
	}
		
	return 0;
}
