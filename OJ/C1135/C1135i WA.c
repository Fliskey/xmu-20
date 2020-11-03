#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	for(int i=n;i>=0;i--){
		int xs;
		scanf("%d",&xs);
		if(xs != 0){
			if(i == n){
				if(i == 1){
					if(xs != 1)
						printf("%dx",xs);
					else
						printf("x");
				}
				else{
					if(xs != 1)
						printf("%dx^%d",xs,i);
					else
						printf("x^%d",i);
				}
			}
			else{
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
	return 0;
}