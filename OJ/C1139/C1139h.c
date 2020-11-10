#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int num[100004];
    while(scanf("%d",&n) != EOF){
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
        }
        
    }
    return 0;
}