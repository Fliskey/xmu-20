#include <stdio.h>

int main(){
	int a[10];
	for(int i=0;i<=9;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=10;i++){
		int min = 2100000000;
		int l = 0;
		for(int j=i;j<=10;j++){
			if(a[j-1] < min){
				min = a[j-1];
				l = j-1;
			}
		}
		int c = a[i-1];
		a[i-1] = a[l];
		a[l] = c;
	}
	for(int i=0;i<=9;i++){
		printf("%d\n",a[i]);
	}
	return 0;
}
