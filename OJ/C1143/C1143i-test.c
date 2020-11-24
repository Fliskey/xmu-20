#include <stdio.h>

int main(){
	freopen("in.txt","w",stdout);
	
	for(int n=1;n<=20;n++){
		for(int k=1;k<=9;k++){
			printf("%d %d\n",n,k);
		}
	}
	return 0;
}
