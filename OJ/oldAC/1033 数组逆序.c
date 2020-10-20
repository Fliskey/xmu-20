#include <stdio.h>

int main(){
	int a[10];
	for(int i=0;i<=9;i++){
		scanf("%d",&a[i]);
	}
	for(int i=9;i>=0;i--){
		printf("%d",a[i]);
		if(i != 0){
			printf(" ");
		}
	}
	return 0;
}
