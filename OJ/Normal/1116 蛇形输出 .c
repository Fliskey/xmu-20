#include <stdio.h>
//1116 ÉßÐÎÊä³ö 

int main(){
	int map[104][104];
	int n;
	
	while(scanf("%d",&n) != EOF){
		
		memset(map,999,sizeof(map));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				map[i][j] = 0;
			}
		}
		
		int i=1,j=1,k=1;
		map[1][1] = 1;
		
		while(map[i][j+1] == 0){
			while(map[i][j+1] == 0){
				j++;
				k++;
				map[i][j] = k;
			}
			while(map[i+1][j] == 0){
				i++;
				k++;
				map[i][j] = k;
			}
			while(map[i][j-1] == 0){
				j--;
				k++;
				map[i][j] = k;
			}
			while(map[i-1][j] == 0){
				i--;
				k++;
				map[i][j] = k;
			}
		}
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				printf("%6d",map[i][j]);
			}
			printf("\n");
		}
	}
	
	
	return 0;
}
