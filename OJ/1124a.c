#include <stdio.h>
#include <math.h>

char map[1460][1460] = {0};
int n;

int mapr[3][3]={{1,1,1},{1,0,1},{1,1,1}};
int mapc[3][3]={{0,0,0},{0,1,0},{0,0,0}};

int pt(int now,int lv,int x,int y){
	if(lv == n){
		if(now == 1){
			map[x-1][y-1] = 'R';
		}	
		else{
			map[x-1][y-1] = 'C';
		}
		return 1;
	}
	for(int i=0;i<=2;i++){
		for(int j=0;j<=2;j++){
			if(now == 1){
				pt(mapr[i][j],lv+1,(x-1)*3+i+1,(y-1)*3+j+1); //1R 
			}
			else{
				pt(mapc[i][j],lv+1,(x-1)*3+i+1,(y-1)*3+j+1); //0C 
			}			
		}
	}
}

int main(){
	
	scanf("%d",&n);
	pt(1,1,1,1);
	int c = pow(3,n-1);
	for(int i=1;i<=c;i++){
		for(int j=1;j<=c;j++){
			printf("%c",map[i-1][j-1]);
		}
		printf("\n");
	}
	
	return 0;
}
