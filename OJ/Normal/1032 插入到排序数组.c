#include <stdio.h>
int main(){
	int a[9];
	for(int i=0;i<=8;i++){
		scanf("%d",&a[i]);
	}
	int n;
	scanf("%d",&n);
	int k = 0;
	if(n < a[0]){
		printf("%d\n",n);
		k = 1;
	}
	for(int i=0;i<=8;i++){
		printf("%d\n",a[i]);
		if(a[i+1]>n){
			if(k == 0){
				printf("%d\n",n);
				k = 1;
			}
		}
	}
	if(k == 0){
		printf("%d\n",n);
	}
	return 0;
}
