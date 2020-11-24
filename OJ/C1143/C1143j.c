#include <stdio.h>
#include <string.h>

int used[10] = {0};
int chosed[10] = {0};
int c_point = 0;

int QPL(int n,int got){
    if(got == n){
        printf("(");
        int is_first = 1;
        for(int i=0;i<c_point;i++){
            if(is_first == 0){
                printf(", ");
            }
            else{
                is_first = 0;
            }
            printf("%d",chosed[i]);
        }
        printf(")");
        return 0;
    }
    else{
        for(int i=1;i<=n;i++){
            if(used[i] == 0){
                used[i] = 1;
                chosed[c_point++] = i;
                QPL(n,got+1);
                c_point--;
                used[i] = 0;
            }
        }
        return 0;
    }
}

int main(){
    int n;
    int is_first = 1;
    while(scanf("%d",&n) != EOF){
        if(is_first == 0){
            printf("\n");
        }
        memset(used,0,sizeof(used));
        QPL(n,0);
        if(is_first){
            is_first = 0;
        }
    }
    return 0;
}