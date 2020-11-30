#include <stdio.h>
#define p 32768

int main(){
	freopen("eout.txt","w",stdout); 
	for(int seed=0;seed<=10;seed++){
		for(int a=1;a<10;a++){
			for(int b=0;b<=100;b++){
				int seedcp = seed;
				printf("%d %d %d: ",seedcp,a,b);
				for(int k=1;k<=2;k++){
					int cp = seedcp;
					seedcp = (seedcp*a+b)%p;
					if(cp == seedcp){
						printf("!");
						break;
					}
				}
				printf("\n");
			}
		}
	}
	return 0;
}
