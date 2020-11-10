#include <stdio.h>
#include <stdlib.h>
#define swap(x,y) (x=x^y,y=x^y,x=x^y)

int main(){
    int map[14][14];
    memset(map,0,sizeof(map));
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
    	memset(map,0,sizeof(map));
        if(n<m){
            swap(n,m);
        }
        for(int x=1;x<=n;x++){
            map[x][1] = 1;
        }
        for(int y=1;y<=m;y++){
            map[1][y] = 1;
        }
        for(int i=2;i<=n;i++){
            for(int j=i;j<=n;j++){
                map[i][j] = map[i-1][j] + map[i][j-1];
                map[j][i] = map[j-1][i] + map[j][i-1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
            //	printf("%8d",map[i][j]);
            }
        //	printf("\n");
        }
        printf("%d\n",map[n][m]);
    }
    return 0;
}
