#include <stdio.h>
//C1113d ÄÔ¶´´ó¿ªÊý

int main(){
	int n;
	char num[204];
	
	while(scanf("%d %s",&n,&num) != EOF){
		int i = 0;
		num[i]++;
		while(num[i] > '9' && i != n){
			num[i] -= 10;
			i++;
			num[i] ++;
		}
		for(int j=0 ; j<n ; j++){
			printf("%c",num[j]);
		}
		if(i == n){
			printf("1");
		}
		printf("\n");
	}
	
	return 0;
} 
