#include <stdio.h>

int solve[100][10];
int ip = 1;
int temp[10];
int map[10][10];

int num = 8;

int printboard(){
    for(int i=1;i<=num;i++){
        for(int j=1;j<=num;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}

int judge(int x,int y){
    for(int i=1;i<=num;i++){
        if(i == y)  continue;
        if(map[x][i] == 1){
            return 0;
        }
    }
    for(int i=1;i<=num;i++){
        if(i == x)  continue;
        if(map[i][y] == 1){
            return 0;
        }
    }
    for(int i=1-num;i<=num-1;i++){
        if(x+i >= 1 && x+i <= num){
            if(y+i >= 1 && y+i <= num){
                if(map[x+i][y+i] == 1){
                    return 0;
                }
            }
            if(y-i >= 1 && y-i <= num){
                if(map[x+i][y-i] == 1){
                    return 0;
                }
            }
        }
    }
    return 1;
}

int queen(int n){
    if(n == num+1){
        for(int i=1;i<=nmu;i++){
            solve[ip][i] = temp[i];
        }
        ip++;
        return 1;
    }
    else{
        for(int i=1;i<=num;i++){
            if(judge(n,i)){
                map[n][i] = 1;
                temp[n] = i;
                queen(n+1);
                temp[n] = 0;
                map[n][i] = 0;
            }
        }
        return 1;
    }
}

int main(){
    int n;
    queen(1);
    while(scanf("%d",&n) != EOF){
        printf("%d: ",n);
        for(int i=1;i<=num;i++){
            printf("%d",solve[n][i]);
        }
        printf("\n");
    }
    return 0;
}