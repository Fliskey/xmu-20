#include <stdio.h>
#include <math.h>
int main(){
	int n;
//	while(scanf("%d",&n) != EOF){
	int sum = 0;
	for(int n=1;n<=1073741824;n++){
		int q = sqrt(n);
		if(q * q == n){
			sum++;
		//	printf("%d\n",n);
		}
	//	else{
		//	printf("n\n");
	//	}
	}
	printf("%d",sum);
		
//	}
	return 0;
}
