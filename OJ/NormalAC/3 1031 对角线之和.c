#include <stdio.h>

int main(){
	int a[3][3];
	for(int i = 0; i<=2; i++){
		for(int j = 0; j<=2; j++){
			scanf("%d",&a[i][j]);
		}
	}
	int z,f;
	z = a[0][0] + a[1][1] + a[2][2];
	f = a[0][2] + a[1][1] + a[2][0];
	printf("%d %d",z,f);
	return 0;
}
