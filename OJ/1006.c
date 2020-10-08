#include <stdio.h>
int main(){
	int a,b,n1,n2;
	scanf("%d %d",&a,&b);
	scanf("%d %d",&n1,&n2);
	int x = 0;
	for(int i = a; i <= b; i++){
		if(i % n1 == 0 || i % n2 == 0){
			if(!x){
				printf("Answer:");
				x = 1;
			}
			printf(" %d",i);
		}
	}
	if(x){
		printf(".");
	}
	else{
		printf("NO SOLUTION.");
	}
	return 0;
}
