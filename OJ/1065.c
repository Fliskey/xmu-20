#include <stdio.h>
#include <math.h>

int main(){
	int n;
	scanf("%d",&n);
	int map[8][8];
	int mi,mj;
	int max = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int x;
			scanf("%d",&x);
			map[i][j] = x;
			x = abs(x);
			if(x>max){
				max = x;
				mi = i+1;
				mj = j+1;
			}
		}
	}
	printf("%d %d %d",max,mi,mj);
	return 0;
}
