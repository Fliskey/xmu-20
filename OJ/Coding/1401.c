#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int card[5] = {0};
int board[400];
int f[41][41][41][41] = {0};
int n,m;

#define FF f[s1][s2][s3][s4]

int max(int a,int b){
    return a>b?a:b;
}

int main(){
    memset(f,0,sizeof(f));
    memset(card,0,sizeof(card));
    memset(board,0,sizeof(board));
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&board[i]);
    }
    for(int i=1;i<=m;i++){
        int no;
        scanf("%d",&no);
        card[no]++;
    }
    f[0][0][0][0] = board[1];
    for(int s1=0 ; s1<=card[1] ; s1++){
        for(int s2=0 ; s2<=card[2] ; s2++){
            for(int s3=0 ; s3<=card[3] ; s3++){
                for(int s4=0 ; s4<=card[4] ; s4++){
                    int now = s1*1 + s2*2 + s3*3 + s4*4 + 1;
                    now = now>n ? 0 : now;
                    if(s1)  FF = max(FF,f[s1-1][s2][s3][s4]+board[now]);
                    if(s2)  FF = max(FF,f[s1][s2-1][s3][s4]+board[now]);
                    if(s3)  FF = max(FF,f[s1][s2][s3-1][s4]+board[now]);
                    if(s4)  FF = max(FF,f[s1][s2][s3][s4-1]+board[now]);
                }
            }
        }
    }
    int ans = f[card[1]][card[2]][card[3]][card[4]];
    printf("%d",ans);
    return 0;
}