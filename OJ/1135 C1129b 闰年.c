#include <stdio.h>

int main(){
	int n;
	while(scanf("%d",&n) == 1){
		int b = 0;
		if(n % 100 == 0){
			if(n % 400 == 0)
				b = 1;
			else
				b = 0;
		}
		else{
			if(n % 4 == 0)
				b = 1;
			else
				b = 0;
		}
		if(b == 1){
			printf("Leap year\n");
		}
		else{
			printf("Not leap year\n");
		}
	}
	return 0;
}
