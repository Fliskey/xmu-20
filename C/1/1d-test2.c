#include <stdio.h>
#include <time.h>
#define p 32768

int main(){
	freopen("eout.txt","w",stdout); 
	srand((int)time(NULL));
	
	for(int q = 1;q<=100;q++){
		int seed = rand()%p;
		int a = rand()%p;
		int b = rand()%p;
		printf("%d %d %d: ",seed,a,b);
		for(int k=1;k<=100;k++){
			int cp = seed;
			seed = (seed*a+b)%p;
			if(cp == seed){
				printf("!!!!");
				break;
			}
			printf("%d(%d) ",seed,cp-seed);
		}
		printf("\n");
	}
	
	return 0;
}
