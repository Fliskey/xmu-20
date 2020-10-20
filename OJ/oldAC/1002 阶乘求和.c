#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	if(n<=0){
		printf("0");
		return 0;
	}
	int sum = 0;
	for(int i=1;i<=n;i++){
		int ct = 1;
		for(int j=2;j<=i;j++){
			ct *= j;
		}
		sum += ct;
	}
	printf("%d",sum);
	return 0;
}
