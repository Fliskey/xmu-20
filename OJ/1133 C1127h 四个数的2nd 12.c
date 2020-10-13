#include <stdio.h>

int main(){
	int a[4];
	while(scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3]) != EOF){
		int max1 = 0, max2 = 0;
		for(int i = 0; i < 4; i++){
			if(a[i] > max1){
				max1 = a[i];
			}
		}
		for(int i = 0; i < 4; i++){
			if(a[i] > max2 && a[i] < max1){
				max2 = a[i];
			}
		}
		if(max2 == 0){
			printf("%d\n",max1);
		}
		else{
			printf("%d\n",max2);
		}
	}
	return 0;
} 
