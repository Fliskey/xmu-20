#include <stdio.h>
#define BL 0.9765625

int main(){
	int x;
	char c;
	while(scanf("%d %c",&x,&c) != EOF){
		double xf = x * BL*BL*BL;
		if(c == 'G'){
			printf("%.1f %c\n",xf,c);
		}
		else{
			xf = xf * BL;
			printf("%.1f %c\n",xf,c);
		}
	}
	return 0;
}
