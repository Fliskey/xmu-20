#include <stdio.h>

int main(){
	freopen("in.txt","w",stdout);
	srand(time(0));
	int n = 20;
	for(int i=1;i<=n;i++){
		int len = 7;
		for(int j=1;j<=len;j++){
			printf("%c",rand()%94+32);
		}
		printf("\n");
	}
	return 0;
}
