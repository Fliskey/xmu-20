#include <stdio.h>
#include <math.h>

int main(){
	int x;
	while(scanf("%d",&x)!=EOF){
		if(x<=100){
			int y = -100 + 2*x;
			printf("%d\n",y);
		}
		else{
			if(x<=500){
				printf("200\n");
			}
			else{
				double y = 1.5 * x - 650;
				y = floor(y);
				printf("%.0f\n",y);
			}
		}
			
	}
	return 0;
}
