#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	int if_printed = 0;
	for(int i=n;i>=0;i--){
		int xs;
		scanf("%d",&xs);
		if(xs != 0){
			if(!if_printed){
				if_printed = 1;
				if(i == 1){
					if(xs != 1)
						printf("%dx",xs);
					else if(xs == -1)
						printf("-x");
					else
						printf("x");
				}
				else if(i == 0){
					printf("%d",xs);
				}
				else{
					if(xs == -1)
						printf("-x^%d",i);
					else if(xs != 1)
						printf("%dx^%d",xs,i);
					else
						printf("x^%d",i);
				}
			}
			else{
				if_printed = 1;
				if(i == 1){
					if(xs>0){
						if(xs != 1)
							printf("+%dx",xs);
						else
							printf("+x");
					}
					else{
						if(xs != -1) 
							printf("%dx",xs);
						else
							printf("-x");
					}
				}
				else if(i == 0){
					if(xs>0){
						printf("+%d",xs);
					}
					else{
						printf("%d",xs);
					}
				}
				else{
					if(xs>0){
						if(xs != 1)
							printf("+%dx^%d",xs,i);
						else
							printf("+x^%d",i);
					}
					else{
						if(xs != -1) 
							printf("%dx^%d",xs,i);
						else
							printf("-x^%d",i);
					}
				}
			}
		}
	}
	if(!if_printed){
		printf("0");
	}
	return 0;
}