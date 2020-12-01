#include <stdio.h>
#include <math.h>

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        while(n>=0){
            for(int i=2;i<=floor(sqrt(n));i++){
                if(n % i == 0){
                    printf("%d ",i);
                    n /= i;
                    goto ctn;
                }
            }
            printf("%d",n);
            break;
            ctn: continue;
        }
        printf("\n");
    }
    return 0;
}